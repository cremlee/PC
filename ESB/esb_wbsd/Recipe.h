#ifndef RECIPE_H
#define RECIPE_H

#include <qstring.h>
#include "rcpstruct.h"
/**
enum STRENGTH{DEFAULT_STRENGTH, MILD_MIX, NORMAL_MIX, STRONG_MIX};
enum CUPSIZE{DEFAULT_SIZE, SMALL_CUP, MEDIUM_CUP, LARGE_CUP};
enum CON_TYPE{NO_CON, LIQ_COFFEE, LIQ_DECAF, LIQ_MILK, LIQ_TEA, LIQ_CHOCO, INS_MILK, INS_TEA, INS_CHOCO, INS_SUGAR, INS_COFFEE, INS_DECAF};
enum PROD_TYPE{LEFT_BIB, RIGHT_BIB, CANISTER};
**/


class Recipe
{
public:
	Recipe(void);
	~Recipe(void);

	Recipe(QString RLine);
//	Recipe(QString name,QString RLine);

    bool isValidRecipe;


     int id;
	 int large_cup;
     int medium_cup;
     int small_cup;
     int seq1;
     int seq2;
     int seq3;
     int seq4;
     int dispense_type;
     int default_cup_size;
     int left_bib_type;
     int  left_bib_pressure_time;
     int left_bib_percent;
    float left_bib_mild_ratio;
    float left_bib_norm_ratio;
    float left_bib_strong_ratio;
     int left_bib_default_ratio;
    float left_bib_water_flow;
     long left_bib_ingredient_start;
     long left_bib_ingredient_stop;
    float left_bib_airvalve;
     long left_bib_airpump_start;
     long left_bib_airpump_stop;
     int left_bib_airpump_speed;
     int left_bib_after_flush_vol;
     int right_bib_type;
     int  right_bib_pressure_time;
     int right_bib_percent;
    float right_bib_mild_ratio;
    float right_bib_norm_ratio;
    float right_bib_strong_ratio;
    short right_bib_default_ratio;
    float right_bib_water_flow;
     long right_bib_ingredient_start;
     long right_bib_ingredient_stop;
    float right_bib_airvalve;
     long right_bib_airpump_start;
     long right_bib_airpump_stop;
     int right_bib_airpump_speed;
     int right_bib_after_flush_vol;
     int instant_type;
     int  instant_pressure_time;
     int instant_percent;
     int instant_default_pwm;
    float instant_water_flow;
    float instant_ingredient_gram_strong;
    float instant_ingredient_gram_norm;
    float instant_ingredient_gram_mild;
    short instant_ingredient_mild_pwm;
    short instant_ingredient_norm_pwm;
    int instant_ingredient_strong_pwm;
     int instant_ingredient_rtd_standard;
     int instant_ingredient_speed;            
     long instant_mixer_start_delay;
     long instant_mixer_stop_delay;
     int instant_mixer_speed;            
     int instant_after_flush_vol;
     /*Add for fmu*/
     int fmu_id;
     int fmu_percentage;

     /*recipe boundary*/
    int rtd_max;
    int rtd_min;
    float left_bib_ratio_max;
    float left_bib_ratio_min;
    float right_bib_ratio_max;
    float right_bib_ratio_min;
    float instant_gram_max;
    float instant_gram_min;
	int left_bib_percent_min;
    int left_bib_percent_max;

	int de_airtime;
	float ingr_ml_per_gram;

QString toRLine(bool with_boundarys=false);

int getId(){return id;}
int getLarge_cup(){return large_cup;}
int getMedium_cup(){return medium_cup;}
int getSmall_cup(){return small_cup;}
int getSeq1(){return seq1;}
int getSeq2(){return seq2;}
int getSeq3(){return seq3;}
int getSeq4(){return seq4;}
int getDispense_type(){return dispense_type;}
int getDefault_cup_size(){return default_cup_size;}
int getLeft_bib_type(){return left_bib_type;}
int  getLeft_bib_pressure_time(){return left_bib_pressure_time;}
int getLeft_bib_percent(){return left_bib_percent;}
float getLeft_bib_mild_ratio(){return left_bib_mild_ratio;}
float getLeft_bib_norm_ratio(){return left_bib_norm_ratio;}
float getLeft_bib_strong_ratio(){return left_bib_strong_ratio;}
int getLeft_bib_default_ratio(){return left_bib_default_ratio;}
float getLeft_bib_water_flow(){return left_bib_water_flow;}
long getLeft_bib_ingredient_start(){return left_bib_ingredient_start;}
long getLeft_bib_ingredient_stop(){return left_bib_ingredient_stop;}
float getLeft_bib_airvalve(){return left_bib_airvalve;}
long getLeft_bib_airpump_start(){return left_bib_airpump_start;}
long getLeft_bib_airpump_stop(){return left_bib_airpump_stop;}
int getLeft_bib_airpump_speed(){return left_bib_airpump_speed;}
int getLeft_bib_after_flush_vol(){return left_bib_after_flush_vol;}
int getRight_bib_type(){return right_bib_type;}
int  getRight_bib_pressure_time(){return right_bib_pressure_time;}
int getRight_bib_percent(){return right_bib_percent;}
float getRight_bib_mild_ratio(){return right_bib_mild_ratio;}
float getRight_bib_norm_ratio(){return right_bib_norm_ratio;}
float getRight_bib_strong_ratio(){return right_bib_strong_ratio;}
short getRight_bib_default_ratio(){return right_bib_default_ratio;}
float getRight_bib_water_flow(){return right_bib_water_flow;}
long getRight_bib_ingredient_start(){return right_bib_ingredient_start;}
long getRight_bib_ingredient_stop(){return right_bib_ingredient_stop;}
float getRight_bib_airvalve(){return right_bib_airvalve;}
long getRight_bib_airpump_start(){return right_bib_airpump_start;}
long getRight_bib_airpump_stop(){return right_bib_airpump_stop;}
int getRight_bib_airpump_speed(){return right_bib_airpump_speed;}
int getRight_bib_after_flush_vol(){return right_bib_after_flush_vol;}
int getInstant_type(){return instant_type;}
int  getInstant_pressure_time(){return instant_pressure_time;}
int getInstant_percent(){return instant_percent;}
int getInstant_default_pwm(){return instant_default_pwm;}
float getInstant_water_flow(){return instant_water_flow;}
float getInstant_ingredient_gram_strong(){return instant_ingredient_gram_strong;}
float getInstant_ingredient_gram_norm(){return instant_ingredient_gram_norm;}
float getInstant_ingredient_gram_mild(){return instant_ingredient_gram_mild;}
short getInstant_ingredient_mild_pwm(){return instant_ingredient_mild_pwm;}
short getInstant_ingredient_norm_pwm(){return instant_ingredient_norm_pwm;}
short getInstant_ingredient_strong_pwm(){return instant_ingredient_strong_pwm;}
long getInstant_ingredient_rtd_standard(){return instant_ingredient_rtd_standard;}
int getInstant_ingredient_speed(){return instant_ingredient_speed; }
long getInstant_mixer_start_delay(){return instant_mixer_start_delay;}
long getInstant_mixer_stop_delay(){return instant_mixer_stop_delay;}
int getInstant_mixer_speed(){return instant_mixer_speed; }
int getInstant_after_flush_vol(){return instant_after_flush_vol;}
int getRtd_max(){return rtd_max;}
int getRtd_min(){return rtd_min;}
float getLeft_bib_ratio_max(){return left_bib_ratio_max;}
float getLeft_bib_ratio_min(){return left_bib_ratio_min;}
float getRight_bib_ratio_max(){return right_bib_ratio_max;}
float getRight_bib_ratio_min(){return right_bib_ratio_min;}
float getInstant_gram_max(){return instant_gram_max;}
float getInstant_gram_min(){return instant_gram_min;}
int getLeft_bib_percent_min(){return left_bib_percent_min;}
int getLeft_bib_percent_max(){return left_bib_percent_max;}


float  getIngrPerPulse(enum PROD_TYPE aType);
float calcWaterContainer(enum PROD_TYPE aType,enum STRENGTH strength=NORMAL_MIX,enum CUPSIZE size=MEDIUM_CUP);
float  calcIngrTimeContainer(enum PROD_TYPE aType,enum STRENGTH strength=NORMAL_MIX,enum CUPSIZE size=MEDIUM_CUP);
float  calcIngrAmount(enum PROD_TYPE aType,enum STRENGTH=NORMAL_MIX,enum CUPSIZE size=MEDIUM_CUP);
float calcWaterTimeContainer(enum PROD_TYPE aType,enum STRENGTH strength=NORMAL_MIX,enum CUPSIZE size=MEDIUM_CUP);

int calcB2Frek(enum PROD_TYPE aType,enum STRENGTH=NORMAL_MIX,enum CUPSIZE size=MEDIUM_CUP);
int	   calcPulses(enum PROD_TYPE aType,enum STRENGTH=NORMAL_MIX,enum CUPSIZE size=MEDIUM_CUP);

float getStrength(enum PROD_TYPE aType,enum STRENGTH strength=NORMAL_MIX);
int getTotVol(enum CUPSIZE size=MEDIUM_CUP);

	//void print();
	bool saveToDb();
	bool loadFromDB( int id);
	void print();
	bool check();

};

#endif //RECIPE_H
