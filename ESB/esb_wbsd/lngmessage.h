#pragma once
#include "qlist.h"
#include "message.h"
#include "qbytearray.h"
class LngMessage:public Message
{
QByteArray itsLng;
public:
	LngMessage(QByteArray aLng);
    LngMessage();
    void getindex(int index);
	~LngMessage(void);
    void setVersion(QByteArray mdata);
};

