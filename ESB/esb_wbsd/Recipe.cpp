#include "Recipe.h"
#include "qstring.h"
#include "qstringlist.h"
#include "qdebug.h"
#include "databasehelper.h"
#include "qtextstream.h"
#include "rcpstruct.h"
#define FMU_ON
Recipe::Recipe(QString RLine)
{
	int index=0;
	RLine=RLine.replace(",",".");
	QStringList sl=RLine.split(":");
	seq4=8;
	isValidRecipe=false;

	index=0;
    if ((sl.size()!=53) && (sl.size()!=61) && (sl.size()!=63) && (sl.size()!=55)) {
        QTextStream(stdout) << QString().sprintf("RecipeID: %d [%s] No valid recipe!! Wrong number of arguments is: %d should be 53 or 61 or 55",sl[index].mid(1).toInt(),RLine.toLatin1().data(),sl.size()) << endl;
		return;
	}
// Real lines;
	id=(int) sl[index++].mid(1).toInt();
	large_cup=(int)sl[index++].toInt();
    medium_cup=(int)sl[index++].toInt();
    small_cup=(int)sl[index++].toInt();
	seq1=(int)sl[index++].toInt();
    seq2=(int)sl[index++].toInt();
    seq3=(int)sl[index++].toInt();
    dispense_type=(int)sl[index++].toInt();
    default_cup_size=(int)sl[index++].toInt();
    left_bib_type=(int)sl[index++].toInt();
    left_bib_percent=(int)sl[index++].toInt();
    left_bib_pressure_time=(int)sl[index++].toInt();
	left_bib_mild_ratio=sl[index++].toFloat();
    left_bib_norm_ratio=sl[index++].toFloat();
    left_bib_strong_ratio=sl[index++].toFloat();
    left_bib_default_ratio=(int)sl[index++].toInt();
    left_bib_water_flow=sl[index++].toFloat();
	left_bib_ingredient_start=( long)sl[index++].toLong();
    left_bib_airvalve=sl[index++].toFloat();
	left_bib_airpump_start=( long)sl[index++].toLong();
	left_bib_airpump_stop=( long)sl[index++].toLong();
    left_bib_airpump_speed=(int)sl[index++].toInt();
    left_bib_after_flush_vol=(int)sl[index++].toInt();

    right_bib_type=(int)sl[index++].toInt();
    right_bib_percent=(int)sl[index++].toInt();
    right_bib_pressure_time=(int)sl[index++].toInt();
    right_bib_mild_ratio=sl[index++].toFloat();
    right_bib_norm_ratio=sl[index++].toFloat();
    right_bib_strong_ratio=sl[index++].toFloat();
    right_bib_default_ratio=(int)sl[index++].toInt();
    right_bib_water_flow=sl[index++].toFloat();
	right_bib_ingredient_start=( long)sl[index++].toLong();
    right_bib_airvalve=sl[index++].toFloat();
	right_bib_airpump_start=( long)sl[index++].toLong();
	right_bib_airpump_stop=( long)sl[index++].toLong();
    right_bib_airpump_speed=(int)sl[index++].toInt();
    right_bib_after_flush_vol=(int)sl[index++].toInt();

    instant_type=(int)sl[index++].toInt();
    instant_percent=(int)sl[index++].toInt();
    instant_pressure_time=(int)sl[index++].toInt();
    instant_ingredient_mild_pwm=(int)sl[index++].toInt();
    instant_ingredient_norm_pwm=(int)sl[index++].toInt();
    instant_ingredient_strong_pwm=(int)sl[index++].toInt();
    instant_default_pwm=(int)sl[index++].toInt();
    instant_water_flow=sl[index++].toFloat();
    instant_ingredient_gram_mild=sl[index++].toFloat();
    instant_ingredient_gram_norm=sl[index++].toFloat();
    instant_ingredient_gram_strong=sl[index++].toFloat();
    instant_ingredient_rtd_standard=sl[index++].toLong();
    instant_mixer_start_delay=( long)sl[index++].toLong();
    instant_mixer_stop_delay=( long)sl[index++].toLong();
    instant_mixer_speed=(int)sl[index++].toInt();            
    instant_after_flush_vol=(int)sl[index++].toInt();

    if(sl.size()==55)
    {
        fmu_id = (int)sl[index++].toInt();
        fmu_percentage = (int)sl[index++].toInt();
    }
	if (sl.size()==61){
		rtd_max=(int)sl[index++].toInt();
		rtd_min=(int)sl[index++].toInt();
		left_bib_ratio_max=sl[index++].toFloat();
		left_bib_ratio_min=sl[index++].toFloat();
		right_bib_ratio_max=sl[index++].toFloat();
		right_bib_ratio_min=sl[index++].toFloat();
		instant_gram_max=sl[index++].toFloat();
		instant_gram_min=sl[index++].toFloat();
		left_bib_percent_max=left_bib_percent;
		left_bib_percent_min=left_bib_percent;

	} else 	if (sl.size()==63){
		rtd_max=(int)sl[index++].toInt();
		rtd_min=(int)sl[index++].toInt();
		left_bib_ratio_max=sl[index++].toFloat();
		left_bib_ratio_min=sl[index++].toFloat();
		right_bib_ratio_max=sl[index++].toFloat();
		right_bib_ratio_min=sl[index++].toFloat();
		instant_gram_max=sl[index++].toFloat();
		instant_gram_min=sl[index++].toFloat();
		left_bib_percent_max=sl[index++].toInt();
		left_bib_percent_min=sl[index++].toInt();

    } else{
		rtd_max=(int)large_cup;
		rtd_min=(int)small_cup;
		left_bib_ratio_max=(float)left_bib_mild_ratio;
		left_bib_ratio_min=(float)left_bib_strong_ratio;
		right_bib_ratio_max=(float)right_bib_mild_ratio;
		right_bib_ratio_min=(float)right_bib_strong_ratio;
		instant_gram_max=(float)instant_ingredient_gram_strong;
		instant_gram_min=(float)instant_ingredient_gram_mild;
		left_bib_percent_max=left_bib_percent;
		left_bib_percent_min=left_bib_percent;
	}
	//print();
	isValidRecipe=true;
}

Recipe::~Recipe(void){
}

Recipe::Recipe(void){
}

QString Recipe::toRLine(bool with_boundarys){
#ifdef FMU_ON
        QString ret=QString().sprintf("R%d:%d:%d:%d:%d:%d:%d:%d:%d:%d:%d:%d:%2.1f:%2.1f:%2.1f:%d:%2.1f:%d:%2.1f:%d:%d:%d:%d:%d:%d:%d:%2.1f:%2.1f:%2.1f:%d:%2.1f:%d:%2.1f:%d:%d:%d:%d:%d:%d:%d:%d:%d:%d:%d:%2.1f:%2.1f:%2.1f:%2.1f:%d:%d:%d:%d:%d:%d:%d",
   	    id,
		large_cup,
		medium_cup,
		small_cup,
		seq1,
		seq2,
		seq3,
		dispense_type,
		default_cup_size,
		left_bib_type,
		left_bib_percent,
		left_bib_pressure_time,
		left_bib_mild_ratio,
		left_bib_norm_ratio,
		left_bib_strong_ratio,
		left_bib_default_ratio,
		left_bib_water_flow,
		left_bib_ingredient_start,
		left_bib_airvalve,
		left_bib_airpump_start,
		left_bib_airpump_stop,
		left_bib_airpump_speed,
		left_bib_after_flush_vol,
		right_bib_type,
		right_bib_percent,
		right_bib_pressure_time,
		right_bib_mild_ratio,
		right_bib_norm_ratio,
		right_bib_strong_ratio,
		right_bib_default_ratio,
		right_bib_water_flow,
		right_bib_ingredient_start,
		right_bib_airvalve,
		right_bib_airpump_start,
		right_bib_airpump_stop,
		right_bib_airpump_speed,
		right_bib_after_flush_vol,
		instant_type,
		instant_percent,
		instant_pressure_time,
		instant_ingredient_mild_pwm,
		instant_ingredient_norm_pwm,
		instant_ingredient_strong_pwm,
		instant_default_pwm,
		instant_water_flow,
		instant_ingredient_gram_mild,
		instant_ingredient_gram_norm,
		instant_ingredient_gram_strong,
		instant_ingredient_rtd_standard,
		instant_mixer_start_delay,
		instant_mixer_stop_delay,
		instant_mixer_speed,
        instant_after_flush_vol,
        //modify by lee add fmu part
        fmu_id,
        fmu_percentage);
#endif
#ifndef FMU_ON
        QString ret=QString().sprintf("R%d:%d:%d:%d:%d:%d:%d:%d:%d:%d:%d:%d:%2.1f:%2.1f:%2.1f:%d:%2.1f:%d:%2.1f:%d:%d:%d:%d:%d:%d:%d:%2.1f:%2.1f:%2.1f:%d:%2.1f:%d:%2.1f:%d:%d:%d:%d:%d:%d:%d:%d:%d:%d:%d:%2.1f:%2.1f:%2.1f:%2.1f:%d:%d:%d:%d:%d",
        id,
        large_cup,
        medium_cup,
        small_cup,
        seq1,
        seq2,
        seq3,
        dispense_type,
        default_cup_size,
        left_bib_type,
        left_bib_percent,
        left_bib_pressure_time,
        left_bib_mild_ratio,
        left_bib_norm_ratio,
        left_bib_strong_ratio,
        left_bib_default_ratio,
        left_bib_water_flow,
        left_bib_ingredient_start,
        left_bib_airvalve,
        left_bib_airpump_start,
        left_bib_airpump_stop,
        left_bib_airpump_speed,
        left_bib_after_flush_vol,
        right_bib_type,
        right_bib_percent,
        right_bib_pressure_time,
        right_bib_mild_ratio,
        right_bib_norm_ratio,
        right_bib_strong_ratio,
        right_bib_default_ratio,
        right_bib_water_flow,
        right_bib_ingredient_start,
        right_bib_airvalve,
        right_bib_airpump_start,
        right_bib_airpump_stop,
        right_bib_airpump_speed,
        right_bib_after_flush_vol,
        instant_type,
        instant_percent,
        instant_pressure_time,
        instant_ingredient_mild_pwm,
        instant_ingredient_norm_pwm,
        instant_ingredient_strong_pwm,
        instant_default_pwm,
        instant_water_flow,
        instant_ingredient_gram_mild,
        instant_ingredient_gram_norm,
        instant_ingredient_gram_strong,
        instant_ingredient_rtd_standard,
        instant_mixer_start_delay,
        instant_mixer_stop_delay,
        instant_mixer_speed,
        instant_after_flush_vol);
#endif
	if (with_boundarys){
		ret.append(QString().sprintf("%d:%d:%2.1f:%2.1f:%2.1f:%2.1f:%2.1f:%2.1f:%d:%d",
							rtd_max,
							rtd_min,
							left_bib_ratio_max,
							left_bib_ratio_min,	
							right_bib_ratio_max,
							right_bib_ratio_min,
							instant_gram_max,
							instant_gram_min,
							left_bib_percent_max,
							left_bib_percent_min));
                        }
  return ret;
}
bool Recipe::saveToDb(){
	return DataBaseHelper::getInstance()->saveRecipe(this);
}
bool Recipe::check(){
     if (rtd_max<large_cup) 
			return false;
     if (rtd_max<medium_cup) 
			return false;
     if (rtd_max<small_cup) 
			return false;
     if (rtd_min>large_cup) 
			return false;
     if (rtd_min>medium_cup) 
			return false;
     if (rtd_min>small_cup) 
			return false;
	 if (left_bib_mild_ratio-left_bib_ratio_max>0.09)
			return false;
	 if (left_bib_norm_ratio-left_bib_ratio_max>0.09)
			return false;
	 if (left_bib_strong_ratio-left_bib_ratio_max>0.09)
			return false;
	 if (left_bib_ratio_min-left_bib_mild_ratio>0.09)
			return false;
	 if (left_bib_ratio_min-left_bib_norm_ratio>0.09)
			return false;
	 if (left_bib_ratio_min-left_bib_strong_ratio>0.09)
			return false;
	 if (left_bib_percent-left_bib_percent_max>0.09)
			return false;
	 if (left_bib_percent_min-left_bib_percent>0.09)
			return false;
	 if (right_bib_mild_ratio-right_bib_ratio_max>0.09)
			return false;
	 if (right_bib_norm_ratio-right_bib_ratio_max>0.09)
			return false;
	 if (right_bib_strong_ratio-right_bib_ratio_max>0.09)
			return false;
	 if (right_bib_ratio_min-right_bib_mild_ratio>0.09)
			return false;
	 if (right_bib_ratio_min-right_bib_norm_ratio>0.09)
			return false;
	 if (right_bib_ratio_min-right_bib_strong_ratio>0.09)
			return false;
	 if (instant_ingredient_gram_mild-instant_gram_max>0.09)
			return false;
	 if (instant_ingredient_gram_norm-instant_gram_max>0.09)
			return false;
	 if (instant_ingredient_gram_strong-instant_gram_max>0.09)
			return false;

	 if (instant_gram_min-instant_ingredient_gram_mild>0.09)
			return false;
	 if (instant_gram_min-instant_ingredient_gram_norm>0.09)
			return false;
	 if (instant_gram_min-instant_ingredient_gram_strong>0.09)
			return false;
 	 return isValidRecipe;
}


bool Recipe::loadFromDB(int aId){
	if (aId==0){
			id=0;
			large_cup =0;
			medium_cup=0;
			small_cup=0;
			seq1=8;
			seq2=8;
			seq3=8;
			dispense_type=0;
			default_cup_size=0;
			left_bib_type=0;
			left_bib_pressure_time=0;
			left_bib_percent=0;
			left_bib_mild_ratio=0;
			left_bib_norm_ratio=0;
			left_bib_strong_ratio=0;
			left_bib_default_ratio=0;
			left_bib_water_flow=0;
			left_bib_ingredient_start=0;
			left_bib_airvalve=0;
			left_bib_airpump_start=0;
			left_bib_airpump_stop=0;
			left_bib_airpump_speed=0;
			left_bib_after_flush_vol=0;
			right_bib_type=0;
			right_bib_pressure_time=0;
			right_bib_percent=0;
			right_bib_mild_ratio=0;
			right_bib_norm_ratio=0;
			right_bib_strong_ratio=0;
			right_bib_default_ratio=0;
			right_bib_water_flow=0;
			right_bib_ingredient_start=0;
			right_bib_airvalve=0;
			right_bib_airpump_start=0;
			right_bib_airpump_stop=0;
			right_bib_airpump_speed=0;
			right_bib_after_flush_vol=0;
			instant_type=0;
			instant_pressure_time=0;
			instant_percent=0;
			instant_default_pwm=0;
			instant_water_flow=0;
			instant_ingredient_gram_strong=0;
			instant_ingredient_gram_norm=0;
			instant_ingredient_gram_mild=0;
			instant_ingredient_mild_pwm=0;
			instant_ingredient_norm_pwm=0;
			instant_ingredient_strong_pwm=0;
			instant_ingredient_rtd_standard=0;
			instant_mixer_start_delay=0;
			instant_mixer_stop_delay=0;
			instant_mixer_speed=0;            
			instant_after_flush_vol=0;

			rtd_max=0;
			rtd_min=0;
			left_bib_ratio_max=0;
			left_bib_ratio_min=0;
			right_bib_ratio_max=0;
			right_bib_ratio_min=0;
			instant_gram_max=0;
			instant_gram_min=0;

			left_bib_percent_max=0;
			left_bib_percent_min=0;

	} else {
		DataBaseHelper::getInstance()->loadRecipe(this,aId);
	}
	isValidRecipe=true;
	return check();
}
void  Recipe::print(){
	QTextStream cout(stdout);
		cout << "Recipe" << endl;;
		cout << "=========================================================" << endl;;
		cout << "id:" << id << endl;;
        cout <<	"large_cup:" << large_cup << endl;;
		cout << "medium_cup:" << medium_cup<< endl;
		cout << "small_cup:" << small_cup<< endl;
		cout << "seq1:" << seq1<< endl;
		cout << "seq2:" << seq2<< endl;
		cout << "seq3:" << seq3<< endl;
		cout << "dispense_type:" << dispense_type<< endl;
		cout << "default_cup_size:" << default_cup_size<< endl;
		cout << "left_bib_type:" << left_bib_type<< endl;
		cout << "left_bib_pressure_time:" << left_bib_pressure_time<< endl;
		cout << "left_bib_percent:" << left_bib_percent<< endl;
		cout << "left_bib_mild_ratio:" << left_bib_mild_ratio<< endl;
		cout << "left_bib_norm_ratio:" << left_bib_norm_ratio<< endl;
		cout << "left_bib_strong_ratio:" << left_bib_strong_ratio<< endl;
		cout << "left_bib_default_ratio:" << left_bib_default_ratio<< endl;
		cout << "left_bib_water_flow:" << left_bib_water_flow<< endl;
		cout << "left_bib_ingredient_start:" << left_bib_ingredient_start<< endl;
		cout << "left_bib_airvalve:" << left_bib_airvalve<< endl;
		cout << "left_bib_airpump_start:" << left_bib_airpump_start<< endl;
		cout << "left_bib_airpump_stop:" << left_bib_airpump_stop<< endl;
		cout << "left_bib_airpump_speed:" << left_bib_airpump_speed<< endl;
		cout << "left_bib_after_flush_vol:" << left_bib_after_flush_vol<< endl;
		cout << "right_bib_type:" << right_bib_type<< endl;
		cout << "right_bib_pressure_time:" << right_bib_pressure_time<< endl;
		cout << "right_bib_percent:" << right_bib_percent<< endl;
		cout << "right_bib_mild_ratio:" << right_bib_mild_ratio<< endl;
		cout << "right_bib_norm_ratio:" << right_bib_norm_ratio<< endl;
		cout << "right_bib_strong_ratio:" << right_bib_strong_ratio<< endl;
		cout << "right_bib_default_ratio:" << right_bib_default_ratio<< endl;
		cout << "right_bib_water_flow:" << right_bib_water_flow<< endl;
		cout << "right_bib_ingredient_start:" << right_bib_ingredient_start<< endl;
		cout << "right_bib_airvalve:" << right_bib_airvalve<< endl;
		cout << "right_bib_airpump_start:" << right_bib_airpump_start<< endl;
		cout << "right_bib_airpump_stop:" << right_bib_airpump_stop<< endl;
		cout << "right_bib_airpump_speed:" << right_bib_airpump_speed<< endl;
		cout << "right_bib_after_flush_vol:" << right_bib_after_flush_vol<< endl;
		cout << "instant_type:" << instant_type<< endl;
		cout << "instant_pressure_time:" << instant_pressure_time<< endl;
		cout << "instant_percent:" << instant_percent<< endl;
		cout << "instant_default_pwm:" << instant_default_pwm<< endl;
		cout << "instant_water_flow:" << instant_water_flow<< endl;
		cout << "instant_ingredient_gram_strong:" << instant_ingredient_gram_strong<< endl;
		cout << "instant_ingredient_gram_norm:" << instant_ingredient_gram_norm<< endl;
		cout << "instant_ingredient_gram_mild:" << instant_ingredient_gram_mild<< endl;
		cout << "instant_ingredient_mild_pwm:" << instant_ingredient_mild_pwm<< endl;
		cout << "instant_ingredient_norm_pwm:" << instant_ingredient_norm_pwm<< endl;
		cout << "instant_ingredient_strong_pwm:" << instant_ingredient_strong_pwm<< endl;
		cout << "instant_ingredient_rtd_standard:" << instant_ingredient_rtd_standard<< endl;
		cout << "instant_mixer_start_delay:" << instant_mixer_start_delay<< endl;
		cout << "instant_mixer_stop_delay:" << instant_mixer_stop_delay<< endl;
		cout << "instant_mixer_speed:" << instant_mixer_speed<< endl;            
		cout << "instant_after_flush_vol:" << instant_after_flush_vol<< endl;
		cout << "rtd_max:" << rtd_max<< endl;
		cout << "rtd_min:" << rtd_min<< endl;
		cout << "left_bib_ratio_max:" << left_bib_ratio_max<< endl;
		cout << "left_bib_ratio_min:" << left_bib_ratio_min<< endl;
		cout << "right_bib_ratio_max:" << right_bib_ratio_max<< endl;
		cout << "right_bib_ratio_min:" << right_bib_ratio_min<< endl;
		cout << "instant_gram_max:" << instant_gram_max<< endl;
		cout << "instant_gram_min:" << instant_gram_min<< endl;
		cout << "left_bib_percent_max:" << left_bib_percent_max<< endl;
		cout << "left_bib_percent_min:" << left_bib_percent_min<< endl;
		cout << "RLine:" << toRLine(true) << endl;
		cout << endl;;
        qDebug() << "Recipe" ;
		qDebug() << "=========================================================" ;;
        qDebug() << "id:" << id ;
        qDebug() <<	"large_cup:" << large_cup;
		qDebug() << "medium_cup:" << medium_cup;
		qDebug() << "small_cup:" << small_cup;
		qDebug() << "seq1:" << seq1;
		qDebug() << "seq2:" << seq2;
		qDebug() << "seq3:" << seq3;
		qDebug() << "dispense_type:" << dispense_type;
		qDebug() << "default_cup_size:" << default_cup_size;
		qDebug() << "left_bib_type:" << left_bib_type;
		qDebug() << "left_bib_pressure_time:" << left_bib_pressure_time;
		qDebug() << "left_bib_percent:" << left_bib_percent;
		qDebug() << "left_bib_mild_ratio:" << left_bib_mild_ratio;
		qDebug() << "left_bib_norm_ratio:" << left_bib_norm_ratio;
		qDebug() << "left_bib_strong_ratio:" << left_bib_strong_ratio;
		qDebug() << "left_bib_default_ratio:" << left_bib_default_ratio;
		qDebug() << "left_bib_water_flow:" << left_bib_water_flow;
		qDebug() << "left_bib_ingredient_start:" << left_bib_ingredient_start;
		qDebug() << "left_bib_airvalve:" << left_bib_airvalve;
		qDebug() << "left_bib_airpump_start:" << left_bib_airpump_start;
		qDebug() << "left_bib_airpump_stop:" << left_bib_airpump_stop;
		qDebug() << "left_bib_airpump_speed:" << left_bib_airpump_speed;
		qDebug() << "left_bib_after_flush_vol:" << left_bib_after_flush_vol;
		qDebug() << "right_bib_type:" << right_bib_type;
		qDebug() << "right_bib_pressure_time:" << right_bib_pressure_time;
		qDebug() << "right_bib_percent:" << right_bib_percent;
		qDebug() << "right_bib_mild_ratio:" << right_bib_mild_ratio;
		qDebug() << "right_bib_norm_ratio:" << right_bib_norm_ratio;
		qDebug() << "right_bib_strong_ratio:" << right_bib_strong_ratio;
		qDebug() << "right_bib_default_ratio:" << right_bib_default_ratio;
		qDebug() << "right_bib_water_flow:" << right_bib_water_flow;
		qDebug() << "right_bib_ingredient_start:" << right_bib_ingredient_start;
		qDebug() << "right_bib_airvalve:" << right_bib_airvalve;
		qDebug() << "right_bib_airpump_start:" << right_bib_airpump_start;
		qDebug() << "right_bib_airpump_stop:" << right_bib_airpump_stop;
		qDebug() << "right_bib_airpump_speed:" << right_bib_airpump_speed;
		qDebug() << "right_bib_after_flush_vol:" << right_bib_after_flush_vol;
		qDebug() << "instant_type:" << instant_type;
		qDebug() << "instant_pressure_time:" << instant_pressure_time;
		qDebug() << "instant_percent:" << instant_percent;
		qDebug() << "instant_default_pwm:" << instant_default_pwm;
		qDebug() << "instant_water_flow:" << instant_water_flow;
		qDebug() << "instant_ingredient_gram_strong:" << instant_ingredient_gram_strong;
		qDebug() << "instant_ingredient_gram_norm:" << instant_ingredient_gram_norm;
		qDebug() << "instant_ingredient_gram_mild:" << instant_ingredient_gram_mild;
		qDebug() << "instant_ingredient_mild_pwm:" << instant_ingredient_mild_pwm;
		qDebug() << "instant_ingredient_norm_pwm:" << instant_ingredient_norm_pwm;
		qDebug() << "instant_ingredient_strong_pwm:" << instant_ingredient_strong_pwm;
		qDebug() << "instant_ingredient_rtd_standard:" << instant_ingredient_rtd_standard;
		qDebug() << "instant_mixer_start_delay:" << instant_mixer_start_delay;
		qDebug() << "instant_mixer_stop_delay:" << instant_mixer_stop_delay;
		qDebug() << "instant_mixer_speed:" << instant_mixer_speed;            
		qDebug() << "instant_after_flush_vol:" << instant_after_flush_vol;
		qDebug() << "rtd_max:" << rtd_max;
		qDebug() << "rtd_min:" << rtd_min;
		qDebug() << "left_bib_ratio_max:" << left_bib_ratio_max;
		qDebug() << "left_bib_ratio_min:" << left_bib_ratio_min;
		qDebug() << "right_bib_ratio_max:" << right_bib_ratio_max;
		qDebug() << "right_bib_ratio_min:" << right_bib_ratio_min;
		qDebug() << "instant_gram_max:" << instant_gram_max;
		qDebug() << "instant_gram_min:" << instant_gram_min;
		qDebug() << "left_bib_percent_max:" << left_bib_percent_max;
		qDebug() << "left_bib_percent_min:" << left_bib_percent_min;
		qDebug() << "RLine:" << toRLine(true) << endl;		
}

float Recipe::getIngrPerPulse(enum PROD_TYPE aType)
{
	enum CON_TYPE c;
	switch (aType){
	case LEFT_BIB:
		c=(enum CON_TYPE)left_bib_type;
		break;
	case RIGHT_BIB:
		c=(enum CON_TYPE)right_bib_type;
		break;
	case CANISTER:
		c=(enum CON_TYPE)instant_type;
		break;
	}
	switch (c){
	case LIQ_COFFEE:
	case LIQ_DECAF:
		return 0.105;
		break;
	case LIQ_MILK:
	case LIQ_CHOCO:
		return 0.096;
		break;
	default:
		return 0.096;
	}
}

float Recipe::calcWaterContainer(enum PROD_TYPE aType,enum STRENGTH strength,enum CUPSIZE size){
	float canvol;
	float ratio=getStrength(aType,strength);
	switch (aType){
	case LEFT_BIB:
		canvol=getTotVol(size)*left_bib_percent;
		return ratio*canvol/(ratio+1);
		break;
	case RIGHT_BIB:
		canvol=getTotVol(size)*right_bib_percent;
		return ratio*canvol/(ratio+1);
		break;
	case CANISTER:
		return getTotVol(size)*instant_percent-ingr_ml_per_gram*ratio*(getTotVol(size)*instant_ingredient_rtd_standard);
		break;
	}
	return 0;
}

float Recipe::getStrength(enum PROD_TYPE aType,enum STRENGTH strength){
	enum CON_TYPE c;
	switch (aType){
	case LEFT_BIB:
			switch (strength){
			case STRONG_MIX:
				return left_bib_strong_ratio;
				break;
			case NORMAL_MIX:
				return left_bib_norm_ratio;
				break;
			case MILD_MIX:
					return left_bib_mild_ratio;
				break;
			}
		break;
	case RIGHT_BIB:
			switch (strength){
			case STRONG_MIX:
				return right_bib_strong_ratio;
				break;
			case NORMAL_MIX:
				return right_bib_norm_ratio;
				break;
			case MILD_MIX:
					return right_bib_mild_ratio;
				break;
			}
		break;
	case CANISTER:
			switch (strength){
			case STRONG_MIX:
				return instant_ingredient_gram_strong;
				break;
			case NORMAL_MIX:
				return instant_ingredient_gram_norm;
				break;
			case MILD_MIX:
				return instant_ingredient_gram_mild;
				break;
			}
		break;
	}
	return 0;
}

int Recipe::getTotVol(enum CUPSIZE size){
	switch(size){
	case LARGE_CUP:
		return  large_cup;
		break;
	case MEDIUM_CUP:
		return  medium_cup;
		break;
	case SMALL_CUP:
		return  small_cup;
		break;
	}
}


float  Recipe::calcIngrTimeContainer(enum PROD_TYPE aType,enum STRENGTH strength,enum CUPSIZE size){
	float wtr=calcWaterContainer(aType,strength,size);
	int start_time;
	int end_time;
	float flow;
	switch (aType){
		case LEFT_BIB:
			end_time=de_airtime+left_bib_pressure_time+calcWaterTimeContainer(aType,strength,size)-1000*left_bib_after_flush_vol/left_bib_water_flow;
			flow=left_bib_water_flow;
			left_bib_ingredient_stop=end_time;
			break;
		case RIGHT_BIB:
			end_time=de_airtime+right_bib_pressure_time+calcWaterTimeContainer(aType,strength,size)-1000*right_bib_after_flush_vol/right_bib_water_flow;
			flow=right_bib_water_flow;
			right_bib_ingredient_stop=end_time;
			break;
	case CANISTER:
			return 0;
		break;
	}

	return 0;
}

int	Recipe::calcPulses(enum PROD_TYPE aType,enum STRENGTH strength,enum CUPSIZE size){
   return (int)calcIngrAmount(aType,strength,size)/getIngrPerPulse(aType);
}


float  Recipe::calcIngrAmount(enum PROD_TYPE aType,enum STRENGTH strength,enum CUPSIZE size){

	switch (aType){
	case LEFT_BIB:
		return getTotVol(size)*left_bib_percent-calcWaterContainer(aType,strength,size);
		break;
	case RIGHT_BIB:
		return getTotVol(size)*right_bib_percent-calcWaterContainer(aType,strength,size);
		break;
	case CANISTER:
		return getTotVol(size)*instant_percent-calcWaterContainer(aType,strength,size);
		break;
	}
   return 0;
}


int Recipe::calcB2Frek(enum PROD_TYPE aType,enum STRENGTH strength,enum CUPSIZE size){
   return calcPulses(aType,strength,size)/(calcIngrTimeContainer(aType,strength,size)/1000);
}

float Recipe::calcWaterTimeContainer(enum PROD_TYPE aType,enum STRENGTH strength,enum CUPSIZE size){
   return 0;
}
