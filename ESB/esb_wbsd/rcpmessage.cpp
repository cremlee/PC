#include "RcpMessage.h"
#include "qlist.h"
#include "qbytearray.h"
#include "message.h"
#include "qstring.h"
#include "recipe.h"
#include "qdebug.h"

RcpMessage::RcpMessage(int aRcp,int aSubQurey) : Message (QByteArray())
{
	msg[0]=STX;
	msg[1] = 0xB7;
	switch (aSubQurey){
	case 0:
		msg[2]=0xa1;
		msg[3]=0x20;
		break;
	case 1:
		msg[2]=0xa1;
		msg[3]=0x22;
		break;
	case 2:
		msg[2]=0xa1;
		msg[3]=0x24;
		break;
	case 3:
		msg[2]=0xa1;
		msg[3]=0x26;
		break;
	}
	msg[4]=(char)0xFF00&aRcp>>8;
	msg[5]=(char)0x00FF&aRcp;
}

RcpMessage::RcpMessage(Message aMsg) : Message (aMsg.msg)
{
}

RcpMessage::RcpMessage(Recipe aRcp): Message(QByteArray()){

    msg[0]=STX;
	msg[1] = 0xB7;
	qtype id=SET_RCP;
	msg[2]=0xa1;
	msg[3]=0x28;
	msg[4]=0x00;
	msg[5]=0x00;
	msg[6]=0x00;
	msg[7]=(char)0x00FF&aRcp.getId();
	msg.append(aRcp.toRLine());
    int l=aRcp.toRLine().length()+2;
	msg[4]=(char)0xFF00&l>>8;
	msg[5]=(char)0x00FF&l;
	msg.append((char)0);
    itsRecipe=aRcp.toRLine();
    qDebug() <<"aaaaaaaa="<<  itsRecipe;
}

RcpMessage::~RcpMessage(void)
{
}

Recipe RcpMessage::getRecipe(){
	return Recipe(itsRecipe);
}
