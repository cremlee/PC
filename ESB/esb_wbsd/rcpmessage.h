#pragma once
#include "qlist.h"
#include "message.h"
#include "qbytearray.h"
#include "recipe.h"
class RcpMessage:public Message
{
QString itsRecipe;
public:
	RcpMessage(int aRcp,int aSubQurey=0);

	RcpMessage(Message aMsg);
	RcpMessage(Recipe aMsg);
	~RcpMessage(void);
	Recipe getRecipe();
};

