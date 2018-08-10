#include "LngMessage.h"
#include "qbytearray.h"
#include "message.h"
#include "qstring.h"
#include "qdebug.h"

LngMessage::LngMessage(QByteArray aLng)
{
    msg.clear();
	msg.append(STX);
	msg.append(0xB7);
	msg.append(0xa1);
	msg.append(0x31);
	qDebug() << aLng.size();
	int s=aLng.size();
	msg.append(((s >> 8) & 0x00FF));
	msg.append((char)(s  & 0x00FF));
	msg.append(aLng);
	qDebug() << msg.toHex();


}

LngMessage::LngMessage()
{

}
void LngMessage::getindex(int index)
{
        msg.clear();
        msg.append(STX);
        msg.append(0xB7);
        msg.append(0xa1);
        msg.append(0x30);
        msg.append(( char) (index<<24));
        msg.append(( char) (index<<16));
        msg.append(( char) (index<<8));
        msg.append(( char)index);
        qDebug() << msg.toHex();
}



LngMessage::~LngMessage(void)
{
}

void LngMessage::setVersion(QByteArray mdata)
{
    msg.clear();
    msg.append(STX);
    msg.append(0xB7);
    msg.append(0xa1);
    msg.append(0x61);
    msg.append((char)0x00);
    msg.append((char)0x00);
    msg.append((char)0x00);
    msg.append((char)0x00);
    msg.append(mdata);
    qDebug() << msg.toHex();
}

