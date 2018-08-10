#include "fmu_message.h"




/*0xaa 0x55*/

fmu_message::fmu_message()
{
}

void fmu_message::SetParam(int id, int value)
{
    msg.clear();
    msg[0]=STX;
    msg[1] = 0xB7;
    msg[2]=(char)(FMU_PARAM_SET >> 8);
    msg[3]=(char)(FMU_PARAM_SET & 0x00FF);
    //id
    msg[4]=(unsigned char)(id >> 24) & 0xFF;
    msg[5]=(unsigned char)(id >> 16) & 0xFF;
    msg[6]=(unsigned char)(id >> 8) & 0xFF;
    msg[7]=(unsigned char)id & 0xFF;
    //value
    msg[8]=(unsigned char)(value >> 24) & 0xFF;
    msg[9]=(unsigned char)(value >> 16) & 0xFF;
    msg[10]=(unsigned char)(value >> 8) & 0xFF;
    msg[11]=(unsigned char)value & 0xFF;
    //ETX
    msg[12]=0xaa;
    msg[13]=0x55;

}

void fmu_message::GetParam(int id)
{
    msg.clear();
    msg[0]=STX;
    msg[1] = 0xB7;
    msg[2]=(char)(FMU_PARAM_GET >> 8);
    msg[3]=(char)(FMU_PARAM_GET & 0x00FF);
    //id
    msg[4]=(unsigned char)(id >> 24) & 0xFF;
    msg[5]=(unsigned char)(id >> 16) & 0xFF;
    msg[6]=(unsigned char)(id >> 8) & 0xFF;
    msg[7]=(unsigned char)id & 0xFF;
    //ETX
    msg[8]=0xaa;
    msg[9]=0x55;
}

void fmu_message::TestFunc(unsigned char id)
{
    msg.clear();
    msg[0]=STX;
    msg[1] = 0xB7;
    msg[2]=(char)(FMU_TEST >> 8);
    msg[3]=(char)(FMU_TEST & 0x00FF);
    //id
    msg[4]=id;
    //ETX
    msg[5]=0xaa;
    msg[6]=0x55;
}

void fmu_message::CalibrationRun(int id, int speed)
{
    msg.clear();
    msg[0]=STX;
    msg[1] = 0xB7;
    msg[2]=(char)(FMU_CAL_RUN >> 8);
    msg[3]=(char)(FMU_CAL_RUN & 0x00FF);
    //id
    msg[4]=id;
    msg[5]=speed;
    //ETX
    msg[6]=0xaa;
    msg[7]=0x55;
}

void fmu_message::CalibrationSet(int id, int speed, int value)
{
    msg.clear();
    msg[0]=STX;
    msg[1] = 0xB7;
    msg[2]=(char)(FMU_CAL_SET >> 8);
    msg[3]=(char)(FMU_CAL_SET & 0x00FF);
    //id
    msg[4]=id;
    msg[5]=speed;
    msg[7]=(unsigned char)(value >> 8) & 0xFF;
    msg[6]=(unsigned char)(value ) & 0xFF;
    //ETX
    msg[8]=0xaa;
    msg[9]=0x55;
}

void fmu_message::GetVersion(int type)
{
    msg.clear();
    msg[0]=STX;
    msg[1] = 0xB7;
    msg[2]=(char)(FMU_GET_VERSION >> 8);
    msg[3]=(char)(FMU_GET_VERSION & 0x00FF);
    //id
    msg[4]=type;
    //ETX
    msg[5]=0xaa;
    msg[6]=0x55;
}

void fmu_message::LoadDefault()
{
    msg.clear();
    msg[0]=STX;
    msg[1] = 0xB7;
    msg[2]=(char)(FMU_RESET >> 8);
    msg[3]=(char)(FMU_RESET & 0x00FF);
    //id
    msg[4]=0;
    //ETX
    msg[5]=0xaa;
    msg[6]=0x55;
}

void fmu_message::ResetDescaleCounter()
{
    msg.clear();
    msg[0]=STX;
    msg[1] = 0xB7;
    msg[2]=(char)(FMU_RESET_DESCALE >> 8);
    msg[3]=(char)(FMU_RESET_DESCALE & 0x00FF);
    //ETX
    msg[4]=0xaa;
    msg[5]=0x55;
}




