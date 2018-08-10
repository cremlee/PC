#include "updatemessage.h"
#include<qdebug.h>
static ushort PKG_MAX_LEN =1024*7;
UpdateMessage::UpdateMessage()
{
    this->Type = 0x81;
}

UpdateMessage::UpdateMessage(QByteArray aLng, int type)
{


   // qDebug() << msg.toHex();
}

void UpdateMessage::updateInit()
{
    msg.clear();
    msg[0] = STX;
    msg[1] = 0xB7;
    msg[2] = 0xA1;
    msg[3] = 0x71;
    msg[4] = (unsigned char)(this->updatebuf.size()>>24) ;
    msg[5] = (unsigned char)(this->updatebuf.size()>>16);
    msg[6] = (unsigned char)(this->updatebuf.size()>>8);
    msg[7] = (unsigned char)(this->updatebuf.size());
    msg[8] = 0;
    msg[9] = 0;
    short sum = GetcheckSum(this->updatebuf);
    msg[10] = (unsigned char)((sum & 0xff00)>>8);//fitcrc
    msg[11] = (unsigned char)(sum & 0x00ff);//fitcrc

}

void UpdateMessage::refreshupdatebuf(QByteArray updatebuf)
{
    this->updatebuf.clear();
    this->updatebuf.append(updatebuf);
    queryQue.clear();
    int pkgcount;
    if(this->updatebuf.size()<=PKG_MAX_LEN)
    {
        pkgcount=1;
        queryQue.append(this->updatebuf);
    }
    else
    {
       pkgcount =  updatebuf.size()/PKG_MAX_LEN +1;
       qDebug()<<"pkgcount="<<pkgcount;
       for(int j=0;j<pkgcount;j++)
       {
           QByteArray tmpbuf;
           if(j==pkgcount-1)
           {
               tmpbuf.append(this->updatebuf.mid(j*PKG_MAX_LEN,updatebuf.size()-j*PKG_MAX_LEN));
           }
            else
           {
               tmpbuf.append(this->updatebuf.mid(j*PKG_MAX_LEN,PKG_MAX_LEN));
           }
           queryQue.append(tmpbuf);
       }
    }
   this->pkgCnt = pkgcount;

}

UpdateMessage::~UpdateMessage()
{

}

void UpdateMessage::GetCurrentMsg(int index)
{
    msg.clear();
    msg[0] = STX;
    msg[1] = 0xB7;
    msg[2] = 0xA1;
    msg[3] = this->Type;
    msg[4] = 0;//
    msg[5] = index;//
    msg[6] =(unsigned char)((this->queryQue.at(index).size() & 0x0000ff00)>>8);//BlocklengthMSB
    msg[7] =(unsigned char)(this->queryQue.at(index).size()& 0x000000ff);//
    msg.append(this->queryQue.at(index));
    short sum = GetcheckSum(msg.mid(4,msg.length()-4));

}

void UpdateMessage::Settype(int type)
{
    this->Type = type;
}

short UpdateMessage::GetcheckSum(QByteArray buf)
{
    unsigned int sum1 = 0;
    unsigned int sum2 = 0;
    unsigned int i;
    for( i = 0; i < buf.length(); i++ ){
            unsigned char uc=buf.at(i);
            sum1 = (sum1 + uc) % 255;
            sum2 = (sum2 + sum1) % 255;
        }
        return (0x0000FFFF) & ((sum2 << 8) | sum1);
}
