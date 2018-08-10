#ifndef MESSAGE_H
#define MESSAGE_H
#include <qbytearray.h>
#include <qstring.h>
#include "rcpstruct.h"
class Message
{
public:
	static const char STX=0x02;
	enum  qtype {
			PARAMETER=0xA110,
			SET_PARAMETER=0xA111,
            ANSWER_SET_PARAMETER=0xA112,
			RECIPE_P0=0xA120,
			RECIPE_P1=0xA122,
			RECIPE_P2=0xA124,
			RECIPE_P3=0xA126,
			ANSWER_RECIPE_P0=0xA121,
			ANSWER_RECIPE_P1=0xA123,
			ANSWER_RECIPE_P2=0xA125,
			ANSWER_RECIPE_P3=0xA127,
			SET_RCP=0xA128,
			ANSWER_SET_RCP=0xA129,
			SET_LANGUAGE=0xA131,
			ANSWER_LANGUAGE=0xA132,
			ERROR=0xA140,
			REPLY_DB=0xA112,
			REPLY_ERR=0xA142,
			REPLY_ERR_COUNT_ACT=0xA143,
			REPLY_ERR_COUNT_HIST=0xA144,
			REPLY_ERR_ACT=0xA145,
			REPLY_ERR_HIST=0xA146,
			REPLY_REC=0xA122,
			REPLY_LNG=0xA132,
			SET_ID_QUERY=0xA151,
			GET_ID_QUERY=0xA150,
			ID_ANSWER=0xA152,
			SET_ID_ANSWER=0xA154,
			GET_ID_ANSWER=0xA153,
			METADATA_QUERY=0xA160,
			METADATA_ANSWER=0xA162,
            UPDATE_INIT =0xA171,
            UPDATE_INIT_ANSWER =0xA172,
            UPDATE_UIB =0xA181,
            UPDATE_UIB_ANSWER =0xA182,
            UPDATE_MCB =0xA191,
            UPDATE_MCB_ANSWER =0xA192,
            UPDATE_FMU =0xA193,
            UPDATE_FMU_ANSWER =0xA194,
            ERROR_PACKET=0xFFFF


	} ;
    enum  errortype { ERR_ACTIVE=0xF0, ERR_HISTORIC=0xF1, ERR_NUMBER_ACTIVE=0xFA,ERR_TOTAL_ERRORS_IN_LOG=0xFB} ;
    enum  board { UIB=0x82,MCB=0x81,MAB=0x83,FMU=0x84} ;
    enum  dbtype { DV=0, DP=1, AV=2, AP=3,RV=30,PV=31,TV=32} ;
	enum  format { BIT=0, NIBBLE= 2, BYTE=3, WORD=4} ;

	struct struct_error{
		long a;
		long b;
		long c;
		long d;
	};
	struct struct_rec{
		long a;
		long b;
		long c;
		long d;
	};

	bool initialized;
	bool isErrorMessage(Message aMsg){return false;}
	QByteArray msg;
	int itsDataLen;
	unsigned int gotchkSum;
	bool haveChkkSum;
	int itsPID;
	int lastPID;
	Message(qtype id,char data[]);
    Message(QByteArray barr);
	Message();
	~Message();
	QByteArray getMsg();

    QByteArray getProtocoll();
    QByteArray getHeader();
	qtype getType();
    QByteArray getParameters();
    QByteArray getData();
    unsigned int calcChkSum();
    float getDataFloat(int aPos=0,bool reversed=true,int bytes=4);
    uint getDataUInt(int aPos=0,bool reversed=true,int bytes=4);
    int getDataInt(int aPos=0,bool reversed=true,int bytes=4);
	int setDataLen(qtype a);

	format getDataType(){return (format) msg.at(9);}
	dbtype getDataBaseType(){return (dbtype) msg.at(4);}
	board getBoard(){return (board) msg.at(5);}
	QString toConsoleFormat(){return "";}



    signed int  append(QByteArray data);
	void  clear();
private:

};

#endif // MESSAGE_H
