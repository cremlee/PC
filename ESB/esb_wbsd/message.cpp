#include "message.h"
#include "qdebug.h"
#include "qlist.h"
Message::Message(qtype id,char data[])
{
	msg[0]=STX;
	msg[1] = 0xB7;
	msg[2]=(char)(id >> 8);
	msg[3]=(char)(id & 0x00FF);
	for (int i=0;i<sizeof data;i++){
		msg[i+4]=data[i];
	}
	initialized=false;
	itsDataLen=0;
	if (msg.length()<5)
	  return;
	if (itsDataLen==0)
		setDataLen(getType());
}


Message::Message(QByteArray barr)
{
	itsDataLen=0;
	msg=QByteArray();
	haveChkkSum=true;
	msg.append(barr);
	if (msg.length()>4)
		setDataLen(getType());
    initialized=true;
}

Message::Message()
{
	msg=QByteArray();
    initialized=true;
	lastPID=0x0f0f;
	itsDataLen=0;
}


Message::~Message()
{

}

Message::qtype Message::getType(){
	char c[4];
	c[2]=0;
	c[3]=0;
	c[0]=msg[3];
	c[1]=msg[2];
	return *(qtype*)&c;
}


QByteArray Message::getProtocoll(){
    QByteArray r;
    r[0]=msg[1];
    return r;
}
QByteArray Message::getHeader(){
    QByteArray r;
    r[0]=msg[2];
    r[1]=msg[3];
    return r;
}
//1262

QByteArray Message::getParameters(){
    QByteArray r;
	r[0]=msg[4]; // type [DV=0,DP=1,AV=2,AP=3]
	r[1]=msg[5]; // group 
	r[2]=msg[6]; // unit [MCB=81, UIB=82]
	r[3]=msg[7]; // block 
	switch (getType()){
	case REPLY_DB:
		r[4]=msg[8]; // index
		r[5]=msg[9]; 
        /*qDebug() << "type " << r.mid(0,1).toHex() << " [DV=0,DP=1,AV=2,AP=3]";
		qDebug() << "group " << r.mid(1,1).toHex() << " [MCB=81, UIB=82]";
		qDebug() << "unit " << r.mid(2,1).toHex() << " ";
		qDebug() << "block " << r.mid(3,1).toHex() << " ";
		qDebug() << "index " << r.mid(4,1).toHex() << " ";
		qDebug() << "format " << r.mid(5,1).toHex() << " [BIT=0,NIBBLE=2,BYTE=3,WORD=4]";
*/
		break;

	case REPLY_ERR:
	case REPLY_ERR_COUNT_ACT:
	case REPLY_ERR_COUNT_HIST:
	case REPLY_ERR_ACT:
    case REPLY_ERR_HIST:
	default:
		break;
	}
    return r;
}
QByteArray Message::getData(){
	int datastartpos=0;
	switch (getType()){
	case REPLY_DB:
		datastartpos=10;
		break;
	case ANSWER_RECIPE_P0:
	case ANSWER_RECIPE_P1:
	case ANSWER_RECIPE_P2:
	case ANSWER_RECIPE_P3:
		datastartpos=4;
		break;
	case PARAMETER:
	case ERROR:
	case REPLY_ERR:
	case REPLY_ERR_COUNT_ACT:
	case REPLY_ERR_COUNT_HIST:
	case REPLY_REC:
	case ANSWER_LANGUAGE:
	default:
		datastartpos=8;
	}
	return msg.mid(datastartpos);
}

float Message::getDataFloat(int pos,bool reversed,int bytes){
    QByteArray r;
	QByteArray m=getData().mid(bytes*pos,bytes);
	while (m.length()<4)
		m.insert(0,(char)0);

    r[0]=m[3];
	r[1]=m[2];
    r[2]=m[1];
    r[3]=m[0];
    float *f; 
	if (reversed) {
	    f=(float*)r.constData();
	} else {
		f=(float*)m.constData();
	}
    return *f;
}

uint Message::getDataUInt(int pos,bool reversed,int bytes){
    QByteArray r;
	QByteArray m=getData().mid(bytes*pos,bytes);
	while (m.length()<4){
		m.append((char)0);
	}
    r[0]=m[3];
    r[1]=m[2];
    r[2]=m[1];
    r[3]=m[0];
    unsigned int *i;
	if (reversed) {
		i=(unsigned int*)r.constData();
	} else {
		i=(unsigned int*)m.constData();
	}
//	qDebug() << m.toHex()<< " " << r.toHex() << " " << *i ;
    return *i;
}

int Message::getDataInt(int pos,bool reversed,int bytes){
    QByteArray r;
	QByteArray m=getData().mid(bytes*pos,bytes);
//	qDebug() << getData().toHex(); 
//	qDebug() << m.toHex(); 
	while (m.length()<4){
		m.append((char)0);
	}
    r[0]=m[3];
    r[1]=m[2];
    r[2]=m[1];
    r[3]=m[0];
    int *i;
	if (reversed) {
		i=(int*)r.constData();
	} else {
		i=(int*)m.constData();
	}
//	qDebug() << m.toHex()<< " " << r.toHex() << " " << *i ;
    return *i;
}

QByteArray Message::getMsg()
{
	//qDebug() << msg.toHex();
	return msg;
}


unsigned int Message::calcChkSum(){
unsigned int sum1 = 0;
unsigned int sum2 = 0;
unsigned int i;
if ((msg.length()<itsDataLen) || (itsDataLen==0))
	return -1;
for( i = 4; i < msg.length()-2; i++ ){
		unsigned char uc=msg.at(i);
        sum1 = (sum1 + uc) % 255;
        sum2 = (sum2 + sum1) % 255;  
    }    
    return (0x0000FFFF) & ((sum2 << 8) | sum1); 
}



int Message::setDataLen(qtype a){
	if (msg.length()==0){
		itsDataLen=8;
		return itsDataLen;
		if ((msg.at(4)==0xff) && (msg.at(5)==0xff) && (msg.at(6)==0xff) && (msg.at(7)==0xff)){
				itsDataLen=8;
				return itsDataLen;
		}

	}
	if (msg.length()<7){
		return 8;
	}
	unsigned char j=msg.at(6);
	char n;

	switch ((qtype)a) {
	case ID_ANSWER: //00xa152 + 51
		j=msg.at(5);
		switch (j){
			case 0x50:
				n=0x53;
				msg.replace(3,1,&n,1);
				itsDataLen=28;
				break;
			case 0x51:
				n=0x54;
				msg.replace(3,1,&n,1);
				itsDataLen=8;
				break;
			case 0xff:
				itsDataLen=8;
				break;
			default:
				break;
			}
		break;
	case SET_ID_QUERY: //00xa152 + 51
		itsDataLen=28;
		break;
	case SET_ID_ANSWER:
		itsDataLen=8;
		break;
	case GET_ID_QUERY:
		itsDataLen=8;
		break;
	case GET_ID_ANSWER:  //00xa152 + 50
		itsDataLen=28;
		break;
	case METADATA_QUERY:
		itsDataLen=8;
		break;
	case METADATA_ANSWER:
		itsDataLen=0x6ff;
		break;
	case SET_PARAMETER:
			itsDataLen=0x0e;
		break;
	case PARAMETER:
			itsDataLen=0x0a;
		break; 
	case ANSWER_RECIPE_P0:
			itsDataLen=0x0a;
		break; 
	case ANSWER_RECIPE_P1:
	case ANSWER_RECIPE_P2:
	case ANSWER_RECIPE_P3:
			itsDataLen=0x10;
		break; 
	case ANSWER_LANGUAGE:
			itsDataLen=0x1+2+1+8;
		break; 
	case ERROR:
			itsDataLen=0x8;
		break; 
	case REPLY_DB:
			itsDataLen=1+2+1+6+sizeof(long);  //STX(1)+TYE(2)+PROT(1)+PARAM(6)+SIZEOF_DATA
		break; 
	case REPLY_ERR:
			itsDataLen=1+2+1+4+8;
			switch (j){
			case 0xfa:
				n=0x43;
				msg.replace(3,1,&n,1);
				itsDataLen=9;
				break;
			case 0xfb:
				n=0x44;
				msg.replace(3,1,&n,1);
				itsDataLen=9;
				break;
			case 0xf0:
				n=0x45;
				msg.replace(3,1,&n,1);
				itsDataLen=16;
				break;
			case 0xf1:
				n=0x46;
				msg.replace(3,1,&n,1);
				itsDataLen=24;
				break;
			default:
				break;
			}
		break; 
    case REPLY_ERR_HIST:
			itsDataLen=1+2+1+4+1+7+7;
		break; 
	case REPLY_ERR_ACT:
			itsDataLen=1+2+1+4+1+7;
		break; 
	case REPLY_ERR_COUNT_ACT:
	case REPLY_ERR_COUNT_HIST:
			itsDataLen=1+2+1+4+1;
		break; 
	case REPLY_REC:
			itsDataLen=1+2+1+4+106;//sizeof(struct_rec);
		break; 
    case UPDATE_INIT:
            itsDataLen =12;
               break;
		default:
		break; 
	}
	return itsDataLen;
}

signed int  Message::append(QByteArray data){
	//qDebug() << "Msg bef:" << msg.toHex();
	//qDebug() << "   Data:" << data.toHex();
	if (msg.length()==0){
		haveChkkSum=false;
		itsDataLen=0;
	}
	msg.append(data);
	if (msg.length()<8)
		return 0;
	if (msg.at(0)!=STX)
		return 0;
	unsigned int sum1;
	unsigned int sum2;
	if (!haveChkkSum){
		sum1=msg.at(3) & (0X000000FF);
		sum2=msg.at(2)& (0X000000FF);

		gotchkSum=(0x0000FFFF) & ((sum2<< 8) | sum1);
		msg.remove(2,2);
		haveChkkSum=true;

		sum1=msg.at(2) & (0X000000FF);
		sum2=msg.at(3)& (0X000000FF);
		itsDataLen=sum1 * 256 + sum2+6;
		msg.remove(2,2);
		sum1=msg.at(2) & (0X000000FF);
		sum2=msg.at(3)& (0X000000FF);
		itsPID=sum1 * 256 + sum2+6;
		msg.remove(2,2);
	}

	if (itsDataLen>0xff){
		int rows=itsDataLen >> 8;
		QByteArray data=msg.mid(8);
		QList <QByteArray> alist=data.split (0xa);
		qDebug() << "data:" << data;
		qDebug() << "rader:" << alist.size();
		qDebug() << "sist:" << alist.last().length();
		return ((alist.size()>=rows+1) && (alist.last().length()==0));
	}
	if (msg.length()>=itsDataLen){
        //qDebug() << msg.toHex();
        //qDebug() << msg.length();
		bool retVal=(gotchkSum == calcChkSum());
		haveChkkSum=false;
		if (retVal){
			sum1=msg.at(msg.length()-1) & (0X000000FF);
			sum2=msg.at(msg.length()-2)& (0X000000FF);
				if ((sum1==0x55) && ( sum2==0xaa)){
					msg.remove(msg.length(),2);
					msg.truncate(itsDataLen-2);
					if (itsPID==lastPID){
		  				    qDebug() << "PID: DOUBLE !!!!!!!!!!!!!!!!!!!!!!" << lastPID;
							clear();
							return -2;
					} else {
						lastPID=itsPID;
//						qDebug() << "PID:" << lastPID;
						return 1;
					}
				} else {
 				    qDebug() << "PID: NO_EOF !!!!!!!!!!!!!!!!!!!!!!" << lastPID;
					return -1;
				}
		}
		else {
			clear();
 		    qDebug() << "PID: CHECKSUM !!!!!!!!!!!!!!!!!!!!!!" << lastPID;
			return -1;
		}
	}
	else{
		return 0;
	}
};

void  Message::clear(){
//	qDebug() << "Entering Message::clear:" << msg.toHex();
	haveChkkSum=false;

	if (itsDataLen==0){
		msg.clear();

//		qDebug() << "Leaving Message::clear:" << msg.toHex();
		return;
	} 
	if (msg.length()>itsDataLen){
		msg.remove(0,itsDataLen);
		if (msg.length()<5){
			itsDataLen=0;
//			qDebug() << "Leaving Message::clear:" << msg.toHex();
			return;
		}
		setDataLen(getType());
	}
	else {

		itsDataLen=0; 
		msg.clear();
	}
//	qDebug() << "Leaving Message::clear:" << msg.toHex();
};

