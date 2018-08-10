#pragma once
#include "qlist.h"
#include "message.h"
#include "qbytearray.h"
class StringMessage:Message
{
public:
	StringMessage(Message aMsg);
	StringMessage(QString aMsg);
	~StringMessage(void);
	QList <QString>getList();
};

