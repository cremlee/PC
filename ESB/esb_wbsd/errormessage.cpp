#include "errormessage.h"
#include "message.h"
#include "qstring.h"
#include "qdebug.h"
#include "qdatetime.h"
ErrorMessage::ErrorMessage(ErrorMessage::errortype aType,char index) : Message (ERROR,"    ")
{
	msg[4]=0x00;
	msg[5]=0x00;
	msg[6]=aType;
	msg[7]=index;
	qDebug() << "Making errorquey:" << QString().sprintf("%d",index);
}

ErrorMessage::ErrorMessage(Message aMsg) : Message (aMsg.msg)
{
}


ErrorMessage::~ErrorMessage()
{

}

QString ErrorMessage::getDesc() {
    int s=getNumber().toInt();
    QString ret;
    switch (s){
    case ALM_OUTLET_LEAK_SMALL:
        ret=QObject::tr("ALM_OUTLET_LEAK_SMALL");
        break;
    case ALM_OUTLET_LEAK_BIG:
        ret=QObject::tr("ALM_OUTLET_LEAK_BIG");
        break;
    case ALM_FILL_TOO_LONG:
        ret=QObject::tr("ALM_FILL_TOO_LONG");
        break;
    case ALM_HEAT_TOO_LONG:
        ret=QObject::tr("ALM_HEAT_TOO_LONG");
        break;
    case ALM_WATER_SENSOR:
        ret=QObject::tr("ALM_WATER_SENSOR");
        break;
	case ALM_DRIPTRAY_FULL:
        ret=QObject::tr("ALM_DRIPTRAY_FULL");
		break;
    case ALM_REF_HI:
        ret=QObject::tr("ALM_REF_HI");
        break;
    case ALM_REF_LO:
        ret=QObject::tr("ALM_REF_LO");
        break;
    case ALM_REF_SENSOR:
        ret=QObject::tr("ALM_REF_SENSOR");
        break;
    case ALM_WJM_REMOVED:
        ret=QObject::tr("ALM_WJM_REMOVED");
        break;
    case ALM_FLUSHING_OVERDUE:
        ret=QObject::tr("FLUSHING OVERDUE");
        break;
    case ALM_CLEANING_OVERDUE:
        ret=QObject::tr("CLEANING OVERDUE");
        break;
    case ALM_RTC_STOPPED:
        ret=QObject::tr("ALM_RTC_STOPPED");
        break;
    case ALM_RECIPE_NA:
        ret=QObject::tr("ALM_RECIPE_NA");
        break;
    case ALM_RESTART:
        ret=QObject::tr("ALM_RESTART");
        break;
    case ALM_OUT_HEATER:
        ret=QObject::tr("ALM_OUT_HEATER");
        break;
    case ALM_OUT_AIRBR_VALVE:
        ret=QObject::tr("ALM_OUT_AIRBR_VALVE");
        break;
    case ALM_OUT_INST_VALVE:
        ret=QObject::tr("ALM_OUT_INST_VALVE");
        break;
    case ALM_OUT_INST_FAN:
        ret=QObject::tr("ALM_OUT_INST_FAN");
        break;
    case ALM_OUT_SPARE1:
        ret=QObject::tr("ALM_OUT_SPARE1");
        break;
    case ALM_OUT_SPARE2:
        ret=QObject::tr("ALM_OUT_SPARE2");
        break;
    case ALM_OUT_SPARE_VALVE:
        ret=QObject::tr("ALM_OUT_SPARE_VALVE");
        break;
    case ALM_OUT_LBIB_VALVE:
        ret=QObject::tr("ALM_OUT_LBIB_VALVE");
        break;
    case ALM_OUT_RBIB_VALVE:
        ret=QObject::tr("ALM_OUT_RBIB_VALVE");
        break;
    case ALM_OUT_LAIR_VALVE:
        ret=QObject::tr("ALM_OUT_LAIR_VALVE");
        break;
    case ALM_OUT_RAIR_VALVE:
        ret=QObject::tr("ALM_OUT_RAIR_VALVE");
        break;
    case ALM_OUT_LAIR_PUMP:
        ret=QObject::tr("ALM_OUT_LAIR_PUMP");
        break;
    case ALM_OUT_RAIR_PUMP:
        ret=QObject::tr("ALM_OUT_RAIR_PUMP");
        break;
    case ALM_OUT_HWTR_VALVE:
        ret=QObject::tr("ALM_OUT_HWTR_VALVE");
        break;
    case ALM_OUT_RFG_FAN:
        ret=QObject::tr("ALM_OUT_RFG_FAN");
        break;
    case ALM_OUT_COOLER:
        ret=QObject::tr("ALM_OUT_COOLER");
        break;
    case ALM_OUT_INLET:
        ret=QObject::tr("ALM_OUT_INLET");
        break;
    case ALM_OUT_CONC:
        ret=QObject::tr("ALM_OUT_CONC");
        break;
    case ALM_OUT_GP:
        ret=QObject::tr("ALM_OUT_GP");
        break;
    case ALM_OUT_MIXER:
        ret=QObject::tr("ALM_OUT_MIXER");
        break;
    case ALM_CONFIG_MM:
        ret=QObject::tr("CONFIGURATION MISMATCH");
        break;
    case ALM_OVERTEMP:
        ret=QObject::tr("OVERTEMPERATURE");
        break;
    case ALM_CONFIG_CL_FL_SCH:
        ret=QObject::tr("CLEANING FLASHING CONFIGURATION ERROR");
        break;
    case ALM_TOPTRAY_REMOVED:
        ret=QObject::tr("ALM_TOPTRAY_REMOVED");
        break;
    case ALM_PUMP_BLOCKED:
        ret=QObject::tr("ALM_PUMP_BLOCKED");
        break;
    case ALM_BUTTON_STUCKED:
        ret=QObject::tr("ALM_BUTTON_STUCKED");
        break;
    case ALM_BOIL_LEVEL_ERROR:
        ret=QObject::tr("ALM_BOIL_LEVEL_ERROR");
        break;
    case ALM_FMU_STATE_ERROR:
        ret=QObject::tr("FMU ERROR");
        break;
    case ALM_FMU_COM_ERROR:
        ret=QObject::tr("FMU Disconnect");
        break;
    default:
        ret=QObject::tr("UNDEFINED");
        break;
    }


    return ret;
}

QString ErrorMessage::toString() {
  if (getType()==REPLY_ERR_HIST)
    return QString("[%3]\t[%4]\t[%1:%2]").arg(getNumber()).arg(getDesc()).arg(getFromTime()).arg(getTomTime());
  else
      return QString("[%3]\t[%1:%2]").arg(getNumber()).arg(getDesc()).arg(getFromTime());
}

QString ErrorMessage::getNumber() {
    return QString("%1").arg((unsigned char)getData().at(0)+0);
}


QString ErrorMessage::getFromTime(){
	QByteArray ba=getData().mid(1,7);
	int year=((unsigned char) ba[0]*256 + (unsigned char)ba[1]);
    unsigned char month=ba[2];
    unsigned char day=ba[3];
    unsigned char hour=ba[4];
    unsigned char minute=ba[5];
    unsigned char sec=ba[6];
	QDateTime dt(QDate(year,month,day),QTime(hour,minute,sec));
	return QString("%1").arg(dt.toString());
}

QString ErrorMessage::getTomTime(){
	if (getType()==REPLY_ERR_HIST){
		QByteArray ba=getData().mid(8,7);
		int year=((unsigned char) ba[0]*256 + (unsigned char)ba[1]);
        unsigned char month=ba[2];
        unsigned char day=ba[3];
        unsigned char hour=ba[4];
        unsigned char minute=ba[5];
        unsigned char sec=ba[6];
		QDateTime dt(QDate(year,month,day),QTime(hour,minute,sec));
		return QString("%1").arg(dt.toString());
	} else
		return QString("%1").arg("NA");
}
