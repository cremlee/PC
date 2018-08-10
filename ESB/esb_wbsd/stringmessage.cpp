#include "stringmessage.h"
#include "qlist.h"
#include "qbytearray.h"
#include "message.h"
#include "qstring.h"

StringMessage::StringMessage(Message aMsg) : Message (aMsg.msg)
{
}

StringMessage::StringMessage(QString aMsg): Message(QByteArray()){
	msg[0]=0x02;
	msg[1]=0x00;
	msg[2]=0x00;
	msg[3]=0x00;
	msg[4]=0x00;
	msg[5]=0x00;
	msg[6]=0x00;
	msg[7]=0x00;
	msg.append(aMsg);
	//QList


}

StringMessage::~StringMessage(void)
{
}

QList <QString> StringMessage::getList(){
	QList <QString> tolist;
	QList <QByteArray> alist;
	setDataLen(getType());
	if (itsDataLen>0xff){
		int rows=itsDataLen >> 8;
		QByteArray data=msg.mid(8);
		alist=data.split (0xa);
		if ((alist.size()>=rows+1) && (alist.last().length()==0)){
			for (int i=0;i<alist.size();i++){
				QString tostr=alist.at(i);
				tostr.remove("\r");
                if(!tostr.contains("crc"))
                    tolist.append(tostr);
			}
		}
	}
	return tolist;
}
