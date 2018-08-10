#ifndef FMU_MESSAGE_H
#define FMU_MESSAGE_H
#include <QByteArray>
#include "message.h"
class fmu_message:public Message
{
public:
    static const char STX=0x02;
    static const char UCB=0x0A;
    static const char FTHB=0x0B;
public:
    enum  qtype {
            FMU_PARAM_GET=0xB001,
            FMU_PARAM_SET=0xB002,
            FMU_TEST =0xB003,
            FMU_CAL_RUN=0xB004,
            FMU_CAL_SET=0xB005,
            FMU_GET_VERSION = 0xB006,
            FMU_RESET=0xB007,
            FMU_RESET_DESCALE=0xB008,
            FMU_RESET_FINISH=0xB017

    } ;
public:
    fmu_message();
    void SetParam(int id,int value);
    void GetParam(int id);
    void TestFunc(unsigned char id);
    void CalibrationRun(int id,int speed);
    void CalibrationSet(int id,int speed,int value);
    void GetVersion(int type);
    void LoadDefault();
    void ResetDescaleCounter();
    QByteArray getmsg();
};

#endif // FMU_MESSAGE_H
