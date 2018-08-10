#ifndef DATABASEHELPER_H
#define DATABASEHELPER_H
#include <QString>
#include <QSqlDatabase>
#include <qcombobox.h>
#include "Recipe.h"
#include <QTextCodec>

//#include "lang.hpp"
static QString OtherDbName ="esb.sqlite3";
static QString USADbName   ="esbusa.sqlite3";
class DataBaseHelper
{
private:
    DataBaseHelper();
public:
   QSqlDatabase itsMachineDB;
   static DataBaseHelper* getInstance(){
        if (_instance==0){
            _instance=new DataBaseHelper();
        }
        return _instance;
   }

   QString getSetting(QString aSetting,QString defVal="");
   bool setSetting(QString aSetting,QString defVal);
   void populateComboFromTabKat(QString key,QComboBox* aCombo);
   QString getTabKatString(QString key,int value);
   void populateValidRecipes(QString key,QComboBox* aCombo,int c_bibl,int c_bibr,int c_can,int fmuon=0);

  //  Lang *getTranslation(QString aLanguage,QString aKey);

	void deleteAllRecipes();
	bool loadRecipe(Recipe* aRecipe,int id);
	bool saveRecipe(Recipe* aRecipe);
	bool saveRecipeName(int id,QString recipeName);

    int GetCurrentUnitTmp();
    QByteArray GetRcpItemID();

    int getMachineState();
    void setMachineState(int a);

    int getswitch(){return _switch;}
    void setswitch(int a);


    int getlast(){return _last;}
    void setlast(int a);
    void ChangeDbsName(bool USA);
    QList<int> GetCurrentValidRcp(QString key,int c_bibl,int c_bibr,int c_can,int fmuon);
    QList<int> GetCurrentValidRcp(QString key,int c_can);
private:
    static DataBaseHelper* _instance;
	QTextCodec * codec;
    QString _DBname;
    int _stateMc;
    int _switch;
    int _last;

};

#endif // DATABASEHELPER_H
