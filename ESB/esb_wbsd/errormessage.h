#ifndef ERRORMESSAGE_H
#define ERRORMESSAGE_H

#include "message.h"
#include "qstring.h"

#define ALM_OUTLET_LEAK_SMALL        17// small leak at outlet valve
#define ALM_OUTLET_LEAK_BIG          18// big leak at outlet valve
#define ALM_FILL_TOO_LONG            19// refill takes too long
#define ALM_HEAT_TOO_LONG            21// Heating takes too long
#define ALM_WATER_SENSOR             25// Boiler temp sensor out of range
#define ALM_DRIPTRAY_FULL            27
#define ALM_REF_HI                   30// Cooling box temperature too high too long
#define ALM_REF_LO                   31// Cooling box temperature too low too long
#define ALM_REF_SENSOR               32// Refrigerator temp sensor out of range
#define ALM_WJM_REMOVED              60
#define ALM_FLUSHING_OVERDUE         71
#define ALM_CLEANING_OVERDUE         73
#define ALM_RTC_STOPPED              95

#define ALM_RECIPE_NA               102

// Internal alarms
#define ALM_RESTART					200
#define ALM_OUT_HEATER              201
#define ALM_OUT_AIRBR_VALVE         202
#define ALM_OUT_INST_VALVE          203
#define ALM_OUT_INST_FAN            204
#define ALM_OUT_SPARE1              205
#define ALM_OUT_SPARE2              206
#define ALM_OUT_SPARE_VALVE         207
#define ALM_OUT_LBIB_VALVE          208
#define ALM_OUT_RBIB_VALVE          209
#define ALM_OUT_LAIR_VALVE          210
#define ALM_OUT_RAIR_VALVE          211
#define ALM_OUT_LAIR_PUMP           212 // PWM
#define ALM_OUT_RAIR_PUMP           213 // PWM
#define ALM_OUT_HWTR_VALVE          214
#define ALM_OUT_RFG_FAN             215
#define ALM_OUT_COOLER              216
#define ALM_OUT_INLET               217
#define ALM_OUT_CONC                218 // PWM
#define ALM_OUT_GP                  219 // PWM
#define ALM_OUT_MIXER               220 // PWM
#define ALM_CONFIG_MM               240 // Configuration mismatch
#define ALM_OVERTEMP                241
#define ALM_CONFIG_CL_FL_SCH        242
#define ALM_TOPTRAY_REMOVED         243
#define ALM_PUMP_BLOCKED			244
#define ALM_BUTTON_STUCKED			245
#define ALM_BOIL_LEVEL_ERROR		246

#define ALM_FMU_STATE_ERROR		247
#define ALM_FMU_COM_ERROR		248

class ErrorMessage : public Message
{
public:
	ErrorMessage(errortype aType,char index=0);
	ErrorMessage(Message aMsg);
	~ErrorMessage();
    QString toString();
    QString getNumber();
	QString getDesc();
	QString getFromTime();
	QString getTomTime();


private:
	
};

#endif // ERRORMESSAGE_H
