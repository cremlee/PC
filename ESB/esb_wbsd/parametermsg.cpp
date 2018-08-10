#include "parametermsg.h"
#include "message.h"
#include "QString.h"

ParameterMsg::ParameterMsg(Message::board aBoard, Message::dbtype aType,char index)
     : Message (PARAMETER,"    ")
{
//ver 1
	msg[4]=aType;
	msg[5]=aBoard;
	msg[6]=0x00;
	msg[7]=index;
//ver 2
/*
	msg[6]=aType;
	msg[4]=aBoard;
	msg[5]=0x00;
	msg[6]=aType;
	msg[7]=index;
*/
}

ParameterMsg::ParameterMsg(Message::board aBoard, Message::dbtype aType, char index, enum qtype id)
     : Message (id,"    ")
{
//ver 1
    msg[4]=aType;
    msg[5]=aBoard;
    msg[6]=0x00;
    msg[7]=index;
//ver 2
/*
    msg[6]=aType;
    msg[4]=aBoard;
    msg[5]=0x00;
    msg[6]=aType;
    msg[7]=index;
*/
}

	QString ParameterMsg::setBit(int index, int value){
		msg[3]=0x11;
		msg[8]=(unsigned char)index & 0xff;
		msg[9]=Message::BIT;
		msg[10]=0;
		msg[11]=0;
		msg[12]=0;
		if (value==0)
			msg[13]=0;
		else
			msg[13]=1;
		return msg.toHex();
	}
	QString ParameterMsg::setNibble(int index,int value){
		msg[3]=0x11;
		msg[8]=(unsigned char)index & 0xff;
		msg[9]=Message::NIBBLE;
		msg[10]=0;
		msg[11]=0;
		msg[12]=0;
		msg[13]=(unsigned char)value & 0x0F;
		return msg.toHex();
	}
	QString ParameterMsg::setChar(int index,int value){
		msg[3]=0x11;
		msg[8]=(unsigned char)index & 0xff;
		msg[9]=Message::BYTE;
		msg[10]=0;
		msg[11]=0;
		msg[12]=0;
		msg[13]=(unsigned char)value & 0xFF;
		return msg.toHex();
	}
	QString ParameterMsg::setWord(int value){
		msg[3]=0x11;
		msg[8]=0;
		msg[9]=Message::WORD;
		msg[10]=0;
		msg[11]=0;
		msg[12]=(unsigned char)(value >> 8);
		msg[13]=(unsigned char)value & 0xFF;
		return msg.toHex();
	}
	QString ParameterMsg::setWord(int hvalue,int lvalue){
		msg[3]=0x11;
		msg[8]=0;
		msg[9]=Message::WORD;
		msg[10]=0;
		msg[11]=0;
		msg[12]=(unsigned char)hvalue & 0xFF;
		msg[13]=(unsigned char)lvalue & 0xFF;
		return msg.toHex();
	}
	QString ParameterMsg::setFloat(float value){
		msg[3]=0x11;
		msg[8]=0;
		msg[9]=Message::WORD;
		long* b;
		b=(long*)&value;
		msg[10]=(unsigned char)(*b >> 24) & 0xFF;
		msg[11]=(unsigned char)(*b >> 16) & 0xFF;
		msg[12]=(unsigned char)(*b >> 8) & 0xFF;
		msg[13]=(unsigned char)*b & 0xFF;
		return msg.toHex();
	}

QString ParameterMsg::getWord(){
		msg[3]=0x10;
		msg[8]=0;
		msg[9]=Message::WORD;
		return msg.toHex();
	}
	QString ParameterMsg::getChar(int index){
		msg[3]=0x10;
		msg[8]=(unsigned char)index & 0xff;
		msg[9]=Message::BYTE;
		return msg.toHex();
	}
	QString ParameterMsg::getNibble(int index){
		msg[3]=0x10;
		msg[8]=(unsigned char)index & 0xff;
		msg[9]=Message::NIBBLE;
		return msg.toHex();
	}
	QString ParameterMsg::getBit(int index){
		msg[3]=0x10;
		msg[8]=(unsigned char)index & 0xff;
		msg[9]=Message::BIT;
		return msg.toHex();
	}
	QString ParameterMsg::getFloat(){
		msg[3]=0x10;
		msg[8]=0;
		msg[9]=Message::WORD;
		return msg.toHex();
	}

QString ParameterMsg::toConsoleFormat(){
	return "";
//	QString
//	if (getType()==PARAMETER)

}


ParameterMsg::~ParameterMsg()
{

}
