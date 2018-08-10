#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlRecord>
#include <QVariant>
#include <QDateTime>
#include <QDate>
#include <QSqlField>
#include  "databasehelper.h"
#include <QDebug>
#include "Recipe.h"
#include <QTextCodec>
#include<QDebug>
#include <QMessageBox>
#include<QApplication>
//#include "lang.hpp"





#include<QFile>
DataBaseHelper* DataBaseHelper::_instance = NULL;

DataBaseHelper::DataBaseHelper()
{
    _instance=this;
    itsMachineDB=QSqlDatabase::addDatabase("QSQLITE","machine");
    //区分美版 和其它的版本
    QFile file("conf.ini");
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream fileOut(&file);
        QString tmpstr=fileOut.readAll();
        QStringList lst = tmpstr.split(":");
        if(lst[0] =="state=1")
        {
            _DBname = OtherDbName;
            _stateMc=1;
        }else
        {
           _DBname = USADbName;
           _stateMc=0;
        }
        if(lst[1] =="switch=0")
        {
            _switch=0;
        }else
        {
            _switch=1;
        }
        if(lst[1] =="last=0")
        {
            _last =0;
        }else
        {
            _last =1;
        }
        file.close();
    }
    itsMachineDB.setDatabaseName(QApplication::applicationDirPath()+"/db/"+_DBname);
    codec=QTextCodec::codecForName( "UTF 8" );
    if (itsMachineDB.open()){
        int a=0;
        itsMachineDB.close();
    }else
    {
    qDebug()<<"opdb err =" << itsMachineDB.lastError();
    }

}


QString DataBaseHelper::getSetting(QString aSetting,QString defVal){
    QString retString;
    //itsMachineDB.setDatabaseName("C:\\Users\\A422518\\Documents\\crem\\_main project new base classes\\wbsd_mini\\esb.sqlite3");

//	QMessageBox::information(0, "Information", "start");


    if (itsMachineDB.open()){
//		QMessageBox::information(0, "Information", "1");
        QSqlQuery query1(itsMachineDB);
        query1.exec(QString("select value from settings where key='%1'").arg(aSetting));
        if (query1.next()) {
            QSqlRecord r=query1.record();
            retString=query1.value(0).toString().trimmed();
//			QMessageBox::information(0, "Information 1", retString);
        } else{
            retString=defVal;
//			QMessageBox::information(0, "Information 2", retString);
        }
        query1.finish();
    }
//	QMessageBox::information(0, "Information", "end");
    itsMachineDB.close();
//	QMessageBox::information(0, "Information", "slut");
    return retString;
}

/*Lang *DataBaseHelper::getTranslation(QString aLanguage,QString aKey){
    itsMachineDB.setDatabaseName("/media/config/addon.sqlite");
    Lang *ret=new Lang ();
    if (itsMachineDB.open()){
        QSqlQuery query1 (itsMachineDB);
        query1.exec(QString("select language,key,line1,line2,state from settings where language='%1' and key='%2'").arg(aLanguage).arg(aKey));
        if (query1.next()) {
            ret->itsLine1=query1.value(2).toString();
            ret->itsLine2=query1.value(3).toString();
            ret->itsKey=query1.value(1).toString();
            ret->itsState=query1.value(4).toInt();
        } else{
            ret=new Lang();
        }
        query1.finish();
    }
    itsMachineDB.close();
    return ret;
}*/




bool DataBaseHelper::setSetting(QString aSetting,QString defVal){
    //itsMachineDB.setDatabaseName("C:\\Users\\A422518\\Documents\\crem\\_main project new base classes\\wbsd_mini\\esb.sqlite3");
    QString sql1=QString("delete from settings where key='%1'").arg(aSetting);
    QString sql2=QString("insert into settings values ('%1','%2')").arg(aSetting).arg(defVal);
    if (itsMachineDB.open()){
        itsMachineDB.exec(sql1);
            //return false;
        itsMachineDB.exec(sql2);
//            itsMachineDB.rollback();
//            return false;
//        }
        itsMachineDB.commit();
    } else
        return false;
    itsMachineDB.close();
    return true;
}

void DataBaseHelper::populateComboFromTabKat(QString key,QComboBox* aCombo)
{
    QString retString;
   aCombo->clear();
    if (itsMachineDB.open()){
        QSqlQuery query1 (itsMachineDB);
        QString sql=QString("SELECT t . KEY , t . description ,t.sortorder FROM tabkat t , settings s WHERE s . KEY = 'lang' AND s . value = t . lang AND  t. var = '%1'  ORDER BY t.sortorder,t . KEY").arg(key);
        query1.exec(sql);
        if (query1.next()){
            aCombo->addItem(query1.value(1).toString().trimmed(),query1.value(0).toInt());
           // qDebug()<<"query1.value(1).toString().trimmed()"<<query1.value(1).toString().trimmed();
            //qDebug()<<"query1.value(0).toInt()"<<query1.value(0).toInt();
            while (query1.next()) {
                aCombo->addItem(query1.value(1).toString().trimmed(),query1.value(0).toString().trimmed());
                //qDebug()<<"w query1.value(1).toString().trimmed()"<<query1.value(1).toString().trimmed();
                //qDebug()<<"w query1.value(0).toString()"<<query1.value(0).toString();

        }
        } else {
            query1.finish();
            sql=QString("SELECT t . KEY , t . description ,t.sortorder FROM tabkat t,settings s WHERE  s . KEY = 'lang' AND s . value = t . lang AND  t. var = '%1' ORDER BY t.sortorder,t . KEY").arg(key);
            query1.exec(sql);
        while (query1.next()) {
            aCombo->addItem(query1.value(1).toString().trimmed(),query1.value(0).toString().trimmed());
        }
        }
        query1.finish();
    }
    itsMachineDB.close();
}

QString DataBaseHelper::getTabKatString(QString key,int value)
{
    QString retString;
    QByteArray ba;
    QVariant v;
    //itsMachineDB.setDatabaseName("C:\\Users\\A422518\\Documents\\crem\\_main project new base classes\\wbsd_mini\\esb.sqlite3");
    if (itsMachineDB.open()){
        QSqlQuery query1 (itsMachineDB);
        QString sql=QString("SELECT t.description FROM tabkat t , settings s WHERE s.KEY = 'lang' AND s.value = t.lang AND  t.var = '%1' and t.key='%2' ORDER BY t.description").arg(key).arg(value);
//		qDebug() << sql;
        query1.exec(sql);
        if (query1.next()){
            retString= query1.value(0).toString().trimmed();
        } else {
            query1.finish();
            sql=QString("SELECT t.KEY , t.description ,t.sortorder FROM tabkat t WHERE  t.lang='31' AND  t.var = '%1' t.key= '%2' ORDER BY t.KEY").arg(key).arg(value);
//			qDebug() << sql;
            query1.exec(sql);
            while (query1.next()) {
                retString= query1.value(0).toString().trimmed();
            }
        }
        query1.finish();
    }
    itsMachineDB.close();
    return retString;
}

void DataBaseHelper::deleteAllRecipes(){
    if (itsMachineDB.open()){
        itsMachineDB.exec("delete from recipe");
    }
}
QList<int> DataBaseHelper::GetCurrentValidRcp(QString key, int c_bibl, int c_bibr, int c_can, int fmuon)
{
    QList<int> mylist;
    QString txt=getTabKatString("100",0).trimmed();
    if (txt.length()==0)
          txt="No drink";
        qDebug()<<"GetCurrentValidRcp";
    //aCombo->addItem(txt,0);  //Populate embty button
    if (itsMachineDB.open()){
        QSqlQuery query1 (itsMachineDB);
        QString sql;
        if (c_bibl == 70) {
            sql=QString("SELECT t . KEY , t.description,t.sortorder FROM tabkat t , settings s, recipe r WHERE s.KEY = 'lang' AND s.value = t.lang AND  t.var = '100' and r.id=t.key and r.left_bib_type=0 and r.right_bib_type=0 and r.instant_type=0 and (r.seq1=3) and r.seq2=8 ORDER BY t.description");
        }
         if (c_bibl == 80) {
            sql=QString("SELECT t . KEY , t.description,t.sortorder FROM tabkat t , settings s, recipe r WHERE s.KEY = 'lang' AND s.value = t.lang AND  t.var = '100' and r.id=t.key and r.left_bib_type=0 and r.right_bib_type=0 and r.instant_type=0 and (r.seq1=4) and r.seq2=8 ORDER BY t.description");
        } else {
             if(fmuon==1)
             {
                sql=QString("SELECT t . KEY , t.description,t.sortorder FROM tabkat t , settings s, recipe r WHERE s.KEY = 'lang' AND s.value = t.lang AND  t.var = '100' and r.id=t.key and r.left_bib_type in (0,%1) and r.right_bib_type in (0,%2) and r.instant_type in (0,%3) and r.seq1<>3 and r.seq1<>4 and r.seq2<>3 and r.seq2<>4 and r.seq3<>3 and r.seq3<>4 ORDER BY t.sortorder").arg(c_bibl).arg(c_bibr).arg(c_can);

             }
             else
             {
                 sql=QString("SELECT t . KEY , t.description,t.sortorder FROM tabkat t , settings s, recipe r WHERE s.KEY = 'lang' AND s.value = t.lang AND  t.var = '100' and r.id=t.key and r.left_bib_type in (0,%1) and r.right_bib_type in (0,%2) and r.instant_type in (0,%3) and r.seq1<>16 and r.seq2<>16 and r.seq3<>16 and r.seq1<>3 and r.seq1<>4 and r.seq2<>3 and r.seq2<>4 and r.seq3<>3 and r.seq3<>4 ORDER BY t.sortorder").arg(c_bibl).arg(c_bibr).arg(c_can);
             }
        }
         qDebug()<<"GetCurrentValidRcp 0"<<sql;
        query1.exec(sql);
        if (query1.next()){

            mylist.append(query1.value(0).toInt());
            while (query1.next()) {
                mylist.append(query1.value(0).toInt()); }
        } else {
            query1.finish();
            if (c_bibl == 70) {
                sql=QString("SELECT t . KEY , t.description,t.sortorder FROM tabkat t ,  recipe r WHERE t.lang='31' AND  t.var = '100' and r.id=t.key and r.left_bib_type=0 and r.right_bib_type=0 and r.instant_type=0 and (r.seq1=3) and r.seq2=8 ORDER BY t.description");
            }
            else if (c_bibl == 80) {
                sql=QString("SELECT t . KEY , t.description,t.sortorder FROM tabkat t ,  recipe r WHERE t.lang='31' AND  t.var = '100' and r.id=t.key and r.left_bib_type=0 and r.right_bib_type=0 and r.instant_type=0 and (r.seq1=4) and r.seq2=8 ORDER BY t.description");
            } else {
                if(fmuon==1)
                   sql=QString("SELECT t . KEY , t.description,t.sortorder FROM tabkat t ,  recipe r WHERE t.lang='31' AND  t.var = '100' and r.id=t.key and r.left_bib_type in (0,%1) and r.right_bib_type in (0,%2) and r.instant_type in (0,%3) and r.seq1<>3 and r.seq1<>4 and r.seq2<>3 and r.seq2<>4 and r.seq3<>3 and r.seq3<>4 ORDER BY t.sortorder").arg(c_bibl).arg(c_bibr).arg(c_can);
                else
                   sql=QString("SELECT t . KEY , t.description,t.sortorder FROM tabkat t ,  recipe r WHERE t.lang='31' AND  t.var = '100' and r.id=t.key and r.left_bib_type in (0,%1) and r.right_bib_type in (0,%2) and r.instant_type in (0,%3) and r.seq1<>16 and r.seq2<>16 and r.seq3<>16 and r.seq1<>3 and r.seq1<>4 and r.seq2<>3 and r.seq2<>4 and r.seq3<>3 and r.seq3<>4 ORDER BY t.sortorder").arg(c_bibl).arg(c_bibr).arg(c_can);

                 }
            qDebug()<<"GetCurrentValidRcp 1"<<sql;
            query1.exec(sql);
            while (query1.next()) {
            mylist.append(query1.value(0).toInt());}
        }
        query1.finish();
    }
    qDebug()<<"GetCurrentValidRcp"<<mylist;
    itsMachineDB.close();
    return mylist;
}

QList<int> DataBaseHelper::GetCurrentValidRcp(QString key, int c_can)
{
    QList<int> mylist;
    QString txt=getTabKatString("100",0).trimmed();
    if (txt.length()==0)
          txt="No drink";
        qDebug()<<"GetCurrentValidRcp";
    //aCombo->addItem(txt,0);  //Populate embty button
    if (itsMachineDB.open()){
        QSqlQuery query1 (itsMachineDB);
        QString sql;
        sql=QString("SELECT t . KEY , t.description,t.sortorder FROM tabkat t , settings s, recipe r WHERE s.KEY = 'lang' AND s.value = t.lang AND  t.var = '100' and r.id=t.key and r.instant_type = %1 and r.seq1<>3 and r.seq1<>4 and r.seq2<>3 and r.seq2<>4 and r.seq3<>3 and r.seq3<>4 ORDER BY t.sortorder").arg(c_can);
        query1.exec(sql);
        if (query1.next()){
            mylist.append(query1.value(0).toInt());
            while (query1.next()) {
                mylist.append(query1.value(0).toInt()); }
        } else {
            query1.finish();
            sql=QString("SELECT t . KEY , t.description,t.sortorder FROM tabkat t ,  recipe r WHERE t.lang='31' AND  t.var = '100' and r.id=t.key and r.instant_type = %1 and r.seq1<>3 and r.seq1<>4 and r.seq2<>3 and r.seq2<>4 and r.seq3<>3 and r.seq3<>4 ORDER BY t.sortorder").arg(c_can);
            query1.exec(sql);
            while (query1.next()) {
            mylist.append(query1.value(0).toInt());}
        }
        query1.finish();
    }
    itsMachineDB.close();
    return mylist;
}

void DataBaseHelper::populateValidRecipes(QString key, QComboBox* aCombo, int c_bibl, int c_bibr, int c_can, int fmuon)
{
    QString retString="unknown";
    //itsMachineDB.setDatabaseName("C:\\Users\\A422518\\Documents\\crem\\_main project new base classes\\wbsd_mini\\esb.sqlite3");
    aCombo->clear();
    QString txt=getTabKatString("100",0).trimmed();
    if (txt.length()==0)
          txt="No drink";
    aCombo->addItem(txt,0);  //Populate embty button

    if (itsMachineDB.open()){
        QSqlQuery query1 (itsMachineDB);
        QString sql;
        if (c_bibl == 70) {
            sql=QString("SELECT t . KEY , t.description,t.sortorder FROM tabkat t , settings s, recipe r WHERE s.KEY = 'lang' AND s.value = t.lang AND  t.var = '100' and r.id=t.key and r.left_bib_type=0 and r.right_bib_type=0 and r.instant_type=0 and (r.seq1=3) and r.seq2=8 ORDER BY t.description");
        }
         if (c_bibl == 80) {
            sql=QString("SELECT t . KEY , t.description,t.sortorder FROM tabkat t , settings s, recipe r WHERE s.KEY = 'lang' AND s.value = t.lang AND  t.var = '100' and r.id=t.key and r.left_bib_type=0 and r.right_bib_type=0 and r.instant_type=0 and (r.seq1=4) and r.seq2=8 ORDER BY t.description");
        } else {
            if(fmuon==1)
                sql=QString("SELECT t . KEY , t.description,t.sortorder FROM tabkat t , settings s, recipe r WHERE s.KEY = 'lang' AND s.value = t.lang AND  t.var = '100' and r.id=t.key and r.left_bib_type in (0,%1) and r.right_bib_type in (0,%2) and r.instant_type in (0,%3) and r.seq1<>3 and r.seq1<>4 and r.seq2<>3 and r.seq2<>4 and r.seq3<>3 and r.seq3<>4 ORDER BY t.sortorder").arg(c_bibl).arg(c_bibr).arg(c_can);
            else
                sql=QString("SELECT t . KEY , t.description,t.sortorder FROM tabkat t , settings s, recipe r WHERE s.KEY = 'lang' AND s.value = t.lang AND  t.var = '100' and r.id=t.key and r.left_bib_type in (0,%1) and r.right_bib_type in (0,%2) and r.instant_type in (0,%3) and r.seq1<>16 and r.seq2<>16 and r.seq3<>16 and r.seq1<>3 and r.seq1<>4 and r.seq2<>3 and r.seq2<>4 and r.seq3<>3 and r.seq3<>4 ORDER BY t.sortorder").arg(c_bibl).arg(c_bibr).arg(c_can);

        }

        query1.exec(sql);
        if (query1.next()){
            aCombo->addItem(query1.value(1).toString().trimmed().toLocal8Bit(),query1.value(0).toInt());
            while (query1.next()) {
                aCombo->addItem(query1.value(1).toString().trimmed().toLocal8Bit(),query1.value(0).toString().trimmed());
        }
        } else {
            query1.finish();
            if (c_bibl == 70) {
                sql=QString("SELECT t . KEY , t.description,t.sortorder FROM tabkat t ,  recipe r WHERE t.lang='31' AND  t.var = '100' and r.id=t.key and r.left_bib_type=0 and r.right_bib_type=0 and r.instant_type=0 and (r.seq1=3) and r.seq2=8 ORDER BY t.description");
            }
            else if (c_bibl == 80) {
                sql=QString("SELECT t . KEY , t.description,t.sortorder FROM tabkat t ,  recipe r WHERE t.lang='31' AND  t.var = '100' and r.id=t.key and r.left_bib_type=0 and r.right_bib_type=0 and r.instant_type=0 and (r.seq1=4) and r.seq2=8 ORDER BY t.description");
            } else {
                 if(fmuon==1)
                    sql=QString("SELECT t . KEY , t.description,t.sortorder FROM tabkat t ,  recipe r WHERE t.lang='31' AND  t.var = '100' and r.id=t.key and r.left_bib_type in (0,%1) and r.right_bib_type in (0,%2) and r.instant_type in (0,%3) and r.seq1<>3 and r.seq1<>4 and r.seq2<>3 and r.seq2<>4 and r.seq3<>3 and r.seq3<>4 ORDER BY t.sortorder").arg(c_bibl).arg(c_bibr).arg(c_can);
                else
                    sql=QString("SELECT t . KEY , t.description,t.sortorder FROM tabkat t ,  recipe r WHERE t.lang='31' AND  t.var = '100' and r.id=t.key and r.left_bib_type in (0,%1) and r.right_bib_type in (0,%2) and r.instant_type in (0,%3) and r.seq1<>16 and r.seq2<>16 and r.seq3<>16 and r.seq1<>3 and r.seq1<>4 and r.seq2<>3 and r.seq2<>4 and r.seq3<>3 and r.seq3<>4 ORDER BY t.sortorder").arg(c_bibl).arg(c_bibr).arg(c_can);

            }
            query1.exec(sql);
            while (query1.next()) {
                aCombo->addItem(query1.value(1).toString().trimmed().toLocal8Bit(),query1.value(0).toString().trimmed());
            }
        }
        query1.finish();
    }
    itsMachineDB.close();
}



bool DataBaseHelper::loadRecipe(Recipe* aRecipe,int id){
    QString retString="unknown";
    bool ret=false;
    qDebug()<<"Recipe id = "<<id;
    if (itsMachineDB.open()){
        QSqlQuery query1 (itsMachineDB);
        QString sql=QString("SELECT * from recipe where id = %1").arg(id);
        query1.exec(sql);
        if (query1.next()){
            QSqlRecord rec=query1.record();
            aRecipe->id=( int)query1.value(rec.indexOf("id")).toInt();
            aRecipe->large_cup =(int)query1.value(rec.indexOf("large_cup")).toInt();
            aRecipe->medium_cup=(int)query1.value(rec.indexOf("medium_cup")).toInt();
            aRecipe->small_cup=(int)query1.value(rec.indexOf("small_cup")).toInt();
            aRecipe->seq1=( int)query1.value(rec.indexOf("seq1")).toInt();
            aRecipe->seq2=( int)query1.value(rec.indexOf("seq2")).toInt();
            aRecipe->seq3=( int)query1.value(rec.indexOf("seq3")).toInt();
            aRecipe->dispense_type=( int)query1.value(rec.indexOf("dispense_type")).toInt();
            aRecipe->default_cup_size=( int)query1.value(rec.indexOf("default_cup_size")).toInt();
            aRecipe->left_bib_type=( int)query1.value(rec.indexOf("left_bib_type")).toInt();
            aRecipe->left_bib_pressure_time=(int)query1.value(rec.indexOf("left_bib_pressure_time")).toInt();
            aRecipe->left_bib_percent=(int)query1.value(rec.indexOf("left_bib_percent")).toInt();
            aRecipe->left_bib_mild_ratio=(float)query1.value(rec.indexOf("left_bib_mild_ratio")).toFloat();
            aRecipe->left_bib_norm_ratio=(float)query1.value(rec.indexOf("left_bib_norm_ratio")).toFloat();
            aRecipe->left_bib_strong_ratio=(float)query1.value(rec.indexOf("left_bib_strong_ratio")).toFloat();
            aRecipe->left_bib_default_ratio=(int)query1.value(rec.indexOf("left_bib_default_ratio")).toInt();
            aRecipe->left_bib_water_flow=(float)query1.value(rec.indexOf("left_bib_water_flow")).toInt();
            aRecipe->left_bib_ingredient_start=(int)query1.value(rec.indexOf("left_bib_ingredient_start")).toInt();
            aRecipe->left_bib_airvalve=(float)query1.value(rec.indexOf("left_bib_airvalve")).toFloat();
            aRecipe->left_bib_airpump_start=(int)query1.value(rec.indexOf("left_bib_airpump_start")).toInt();
            aRecipe->left_bib_airpump_stop=(long )query1.value(rec.indexOf("left_bib_airpump_stop")).toInt();
            aRecipe->left_bib_airpump_speed=(int)query1.value(rec.indexOf("left_bib_airpump_speed")).toInt();
            aRecipe->left_bib_after_flush_vol=(int)query1.value(rec.indexOf("left_bib_after_flush_vol")).toInt();
            aRecipe->right_bib_type=(int)query1.value(rec.indexOf("right_bib_type")).toInt();
            aRecipe->right_bib_pressure_time=(int)query1.value(rec.indexOf("right_bib_pressure_time")).toInt();
            aRecipe->right_bib_percent=(int)query1.value(rec.indexOf("right_bib_percent")).toInt();
            aRecipe->right_bib_mild_ratio=(float)query1.value(rec.indexOf("right_bib_mild_ratio")).toFloat();
            aRecipe->right_bib_norm_ratio=(float)query1.value(rec.indexOf("right_bib_norm_ratio")).toFloat();
            aRecipe->right_bib_strong_ratio=(float)query1.value(rec.indexOf("right_bib_strong_ratio")).toFloat();
            aRecipe->right_bib_default_ratio=(int)query1.value(rec.indexOf("right_bib_default_ratio")).toInt();
            aRecipe->right_bib_water_flow=(float)query1.value(rec.indexOf("right_bib_water_flow")).toInt();
            aRecipe->right_bib_ingredient_start=(int)query1.value(rec.indexOf("right_bib_ingredient_start")).toInt();
            aRecipe->right_bib_airvalve=(float)query1.value(rec.indexOf("right_bib_airvalve")).toFloat();
            aRecipe->right_bib_airpump_start=(int)query1.value(rec.indexOf("right_bib_airpump_start")).toInt();
            aRecipe->right_bib_airpump_stop=(long )query1.value(rec.indexOf("right_bib_airpump_stop")).toInt();
            aRecipe->right_bib_airpump_speed=(int)query1.value(rec.indexOf("right_bib_airpump_speed")).toInt();
            aRecipe->right_bib_after_flush_vol=(int)query1.value(rec.indexOf("right_bib_after_flush_vol")).toInt();
            aRecipe->instant_type=(int)query1.value(rec.indexOf("instant_type")).toInt();
            aRecipe->instant_pressure_time=(int)query1.value(rec.indexOf("instant_pressure_time")).toInt();
            aRecipe->instant_percent=(int)query1.value(rec.indexOf("instant_percent")).toInt();
            aRecipe->instant_default_pwm=(int)query1.value(rec.indexOf("instant_default_pwm")).toInt();
            aRecipe->instant_water_flow=(float)query1.value(rec.indexOf("instant_water_flow")).toInt();
            aRecipe->instant_ingredient_gram_strong=(float)query1.value(rec.indexOf("instant_ingredient_gram_strong")).toFloat();
            aRecipe->instant_ingredient_gram_norm=(float)query1.value(rec.indexOf("instant_ingredient_gram_norm")).toFloat();
            aRecipe->instant_ingredient_gram_mild=(float)query1.value(rec.indexOf("instant_ingredient_gram_mild")).toFloat();
            aRecipe->instant_ingredient_mild_pwm=(int)query1.value(rec.indexOf("instant_ingredient_mild_pwm")).toInt();
            aRecipe->instant_ingredient_norm_pwm=(int)query1.value(rec.indexOf("instant_ingredient_norm_pwm")).toInt();
            aRecipe->instant_ingredient_strong_pwm=(int)query1.value(rec.indexOf("instant_ingredient_strong_pwm")).toInt();
            aRecipe->instant_ingredient_rtd_standard=(long )query1.value(rec.indexOf("instant_ingredient_rtd_standard")).toInt();
            aRecipe->instant_mixer_start_delay=(long )query1.value(rec.indexOf("instant_mixer_start_delay")).toInt();
            aRecipe->instant_mixer_stop_delay=(long )query1.value(rec.indexOf("instant_mixer_stop_delay")).toInt();
            aRecipe->instant_mixer_speed=(int)query1.value(rec.indexOf("instant_mixer_speed")).toInt();
            aRecipe->instant_after_flush_vol=(int)query1.value(rec.indexOf("instant_after_flush_vol")).toInt();

            aRecipe->rtd_max=(int)query1.value(rec.indexOf("rtd_max")).toInt();
            aRecipe->rtd_min=(int)query1.value(rec.indexOf("rtd_min")).toInt();
            aRecipe->left_bib_ratio_max=(float)query1.value(rec.indexOf("left_bib_ratio_max")).toFloat();
            aRecipe->left_bib_ratio_min=(float)query1.value(rec.indexOf("left_bib_ratio_min")).toFloat();
            aRecipe->right_bib_ratio_max=(float)query1.value(rec.indexOf("right_bib_ratio_max")).toFloat();
            aRecipe->right_bib_ratio_min=(float)query1.value(rec.indexOf("right_bib_ratio_min")).toFloat();
            aRecipe->instant_gram_max=(float)query1.value(rec.indexOf("instant_gram_max")).toFloat();
            aRecipe->instant_gram_min=(float)query1.value(rec.indexOf("instant_gram_min")).toFloat();

            aRecipe->left_bib_percent_max=(int)query1.value(rec.indexOf("left_bib_percent_max")).toInt();
            aRecipe->left_bib_percent_min=(int)query1.value(rec.indexOf("left_bib_percent_min")).toInt();


            query1.finish();
            ret=true;
    } else {
            query1.finish();
            ret=false;
    }
    itsMachineDB.close();
    } else {
        ret=false;
    }

    return ret;

}
/*modify by lee*/
bool DataBaseHelper::saveRecipeName(int id,QString recipeName){
    Recipe existrec;
    QString retString="unknown";
    bool ret=false;

    QString lng=getSetting("lang","31");
    if (itsMachineDB.open()){
        QString sql1=QString("delete from tabkat where var='100' and lang=%1 and key=%2").arg(lng.toInt()).arg(id);
        itsMachineDB.exec(sql1);
        sql1=QString("insert into tabkat values (100,%1,%2,'%3','000')").arg(lng.toInt()).arg(id).arg(recipeName);
        itsMachineDB.exec(sql1);
        itsMachineDB.close();
    }
    return true;
}

int DataBaseHelper::GetCurrentUnitTmp()
{
    int retint=0;
    if (itsMachineDB.open())
    {
        QSqlQuery query1 (itsMachineDB);
        QString sql=QString("SELECT t . KEY , t . description ,t.sortorder FROM tabkat t , settings s WHERE s . KEY = 'lang' AND s . value = t . lang AND  t. var = '%1'  ORDER BY t.sortorder,t . KEY").arg("012");
        query1.exec(sql);
        if (query1.next()){
            retint = query1.value(0).toInt();
            qDebug()<<"unit tmp = "<<query1.value(0).toString();
             }
        query1.finish();
        itsMachineDB.close();
    }

    return retint;
}

QByteArray DataBaseHelper::GetRcpItemID()
{
    QByteArray ret;
    if (itsMachineDB.open())
    {
        QSqlQuery query1 (itsMachineDB);
        QString sql=QString("select id from recipe  order by id");
        query1.exec(sql);
        while (query1.next()){
            ret.append(query1.value(0).toInt());
             }
        query1.finish();
        itsMachineDB.close();
    }
    qDebug()<<"rcp ID = "<<ret.toHex() << ret.count();
    return ret;
}

int DataBaseHelper::getMachineState()
{
    return _stateMc;
}

void DataBaseHelper::setMachineState(int a)
{
    _stateMc =a;
    QFile file("conf.ini");
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream fileOut(&file);
        fileOut <<"state="<<a<<":switch="<<_switch<<":last="<<_last;;
        file.close();
    }

}

void DataBaseHelper::setswitch(int a)
{
    _switch =a;
    QFile file("conf.ini");
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream fileOut(&file);
        fileOut <<"state="<<_stateMc<<":switch="<<a<<":last="<<_last;
        file.close();
    }
}

void DataBaseHelper::setlast(int a)
{
    _last =a;
    QFile file("conf.ini");
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream fileOut(&file);
        fileOut <<"state="<<_stateMc<<":switch="<<_switch<<":last="<<_last;;
        file.close();
    }
}

void DataBaseHelper::ChangeDbsName(bool USA)
{
    if(USA)
    {
        _DBname = USADbName;
    }else
    {
        _DBname = OtherDbName;
    }
    itsMachineDB.close();
    itsMachineDB.setDatabaseName(QApplication::applicationDirPath()+"/db/"+_DBname);
}



bool DataBaseHelper::saveRecipe(Recipe* aRecipe){
    Recipe existrec;
    QString retString="unknown";
    bool ret=false;
    bool existDB=loadRecipe(&existrec,aRecipe->id);
    if (itsMachineDB.open()){
        if (existDB){
                QString sql1=QString("delete from recipe where id=%1").arg(aRecipe->id);
                itsMachineDB.exec(sql1);
        }
        QString sql2=QString("insert into recipe (");
        sql2.append("id,large_cup,medium_cup,small_cup,seq1,seq2,seq3,dispense_type,default_cup_size,");
        sql2.append("left_bib_type,left_bib_pressure_time,left_bib_percent,left_bib_mild_ratio,left_bib_norm_ratio,left_bib_strong_ratio,left_bib_default_ratio,left_bib_water_flow,left_bib_ingredient_start,left_bib_airvalve,left_bib_airpump_start,left_bib_airpump_stop,left_bib_airpump_speed,left_bib_after_flush_vol,");
        sql2.append("right_bib_type,right_bib_pressure_time,right_bib_percent,right_bib_mild_ratio,right_bib_norm_ratio,right_bib_strong_ratio,right_bib_default_ratio,right_bib_water_flow,right_bib_ingredient_start,right_bib_airvalve,right_bib_airpump_start,right_bib_airpump_stop,right_bib_airpump_speed,right_bib_after_flush_vol,");
        sql2.append("instant_type,instant_pressure_time,instant_percent,instant_default_pwm,instant_water_flow,instant_ingredient_gram_strong,instant_ingredient_gram_norm,instant_ingredient_gram_mild,instant_ingredient_mild_pwm,instant_ingredient_norm_pwm,instant_ingredient_strong_pwm,instant_ingredient_rtd_standard,instant_mixer_start_delay,instant_mixer_stop_delay,instant_mixer_speed,instant_after_flush_vol,");
        sql2.append("rtd_max,rtd_min,left_bib_ratio_max,left_bib_ratio_min,right_bib_ratio_max,right_bib_ratio_min,instant_gram_max,instant_gram_min,left_bib_percent_max,left_bib_percent_min");
        sql2.append(") values (");
        sql2.append(QString().sprintf("%d",aRecipe->id));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->large_cup));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->medium_cup));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->small_cup));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->seq1));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->seq2));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->seq3));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->dispense_type));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->default_cup_size));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->left_bib_type));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->left_bib_pressure_time));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->left_bib_percent));
        sql2.append(", ");
        sql2.append(QString().sprintf("%2.1f",aRecipe->left_bib_mild_ratio));
        sql2.append(", ");
        sql2.append(QString().sprintf("%2.1f",aRecipe->left_bib_norm_ratio));
        sql2.append(", ");
        sql2.append(QString().sprintf("%2.1f",aRecipe->left_bib_strong_ratio));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->left_bib_default_ratio));
        sql2.append(", ");
        sql2.append(QString().sprintf("%2.1f",aRecipe->left_bib_water_flow));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->left_bib_ingredient_start));
        sql2.append(", ");
        sql2.append(QString().sprintf("%2.1f",aRecipe->left_bib_airvalve));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->left_bib_airpump_start));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->left_bib_airpump_stop));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->left_bib_airpump_speed));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->left_bib_after_flush_vol));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->right_bib_type));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->right_bib_pressure_time));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->right_bib_percent));
        sql2.append(", ");
        sql2.append(QString().sprintf("%2.1f",aRecipe->right_bib_mild_ratio));
        sql2.append(", ");
        sql2.append(QString().sprintf("%2.1f",aRecipe->right_bib_norm_ratio));
        sql2.append(", ");
        sql2.append(QString().sprintf("%2.1f",aRecipe->right_bib_strong_ratio));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->right_bib_default_ratio));
        sql2.append(", ");
        sql2.append(QString().sprintf("%2.1f",aRecipe->right_bib_water_flow));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->right_bib_ingredient_start));
        sql2.append(", ");
        sql2.append(QString().sprintf("%2.1f",aRecipe->right_bib_airvalve));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->right_bib_airpump_start));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->right_bib_airpump_stop));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->right_bib_airpump_speed));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->right_bib_after_flush_vol));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->instant_type));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->instant_pressure_time));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->instant_percent));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->instant_default_pwm));
        sql2.append(", ");
        sql2.append(QString().sprintf("%2.1f",aRecipe->instant_water_flow));
        sql2.append(", ");
        sql2.append(QString().sprintf("%2.1f",aRecipe->instant_ingredient_gram_strong));
        sql2.append(", ");
        sql2.append(QString().sprintf("%2.1f",aRecipe->instant_ingredient_gram_norm));
        sql2.append(", ");
        sql2.append(QString().sprintf("%2.1f",aRecipe->instant_ingredient_gram_mild));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->instant_ingredient_mild_pwm));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->instant_ingredient_norm_pwm));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->instant_ingredient_strong_pwm));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->instant_ingredient_rtd_standard));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->instant_mixer_start_delay));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->instant_mixer_stop_delay));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->instant_mixer_speed));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->instant_after_flush_vol));;
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->rtd_max));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->rtd_min));
        sql2.append(", ");
        sql2.append(QString().sprintf("%2.1f",aRecipe->left_bib_ratio_max));
        sql2.append(", ");
        sql2.append(QString().sprintf("%2.1f",aRecipe->left_bib_ratio_min));
        sql2.append(", ");
        sql2.append(QString().sprintf("%2.1f",aRecipe->right_bib_ratio_max));
        sql2.append(", ");
        sql2.append(QString().sprintf("%2.1f",aRecipe->right_bib_ratio_min));
        sql2.append(", ");
        sql2.append(QString().sprintf("%2.1f",aRecipe->instant_gram_max));
        sql2.append(", ");
        sql2.append(QString().sprintf("%2.1f",aRecipe->instant_gram_min));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->left_bib_percent_max));
        sql2.append(", ");
        sql2.append(QString().sprintf("%d",aRecipe->left_bib_percent_min));
        sql2.append(")");
        itsMachineDB.exec(sql2);
        itsMachineDB.close();
        return ret;
    }
}
