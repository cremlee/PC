#ifndef UPDATEMESSAGE_H
#define UPDATEMESSAGE_H
#pragma once
#include "qlist.h"
#include "message.h"
#include "qbytearray.h"
class UpdateMessage : public Message
{
public:
    UpdateMessage();
    UpdateMessage(QByteArray aLng,int type);
    void updateInit();
    void refreshupdatebuf(QByteArray updatebuf);
    ~UpdateMessage(void);
    void GetCurrentMsg(int index);
    void Settype(int type);
    short GetcheckSum(QByteArray buf);
private:
    QList <QByteArray> queryQue;
public:
    QByteArray updatebuf;
    int Type;
    int pkgCnt;
};

#endif // UPDATEMESSAGE_H
