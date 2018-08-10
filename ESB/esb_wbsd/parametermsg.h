#ifndef PARAMETERMSG_H
#define PARAMETERMSG_H

#include "message.h"
#include "qstring.h"

class ParameterMsg : public Message
{
public:
	ParameterMsg(Message::board aBoard, Message::dbtype aType,char index);
    ParameterMsg(Message::board aBoard, Message::dbtype aType,char index, qtype id);
	~ParameterMsg();
	QString setBit(int index, int value);
	QString setNibble(int index,int value);
	QString setChar(int index,int value);
	QString setWord(int value);
	QString setWord(int hvalue,int lvalue);
	QString setFloat(float value);
	QString getBit(int index);
	QString getWord();
	QString getChar(int index);
	QString getNibble(int index);
	QString getFloat();
	QString toConsoleFormat();

private:
	
};

#endif // PARAMETERMSG_H
