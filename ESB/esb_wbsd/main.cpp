#include "mainwindow.h"
#include "wbsdmainwindow.h"
#include <QApplication>
#include "errormessage.h"
#include "parametermsg.h"
#include "wbsd_serial_port.h"
#include <iostream>
#include <QByteArray>
#include <QTranslator>
#include "application.h"
#include "recipe.h"
#include "databasehelper.h"
#include "rcpmessage.h"
#include<QDir>
#include "frmlogin.h"
#include"wbsd_run.h"
/*modify by Lee
add USA MODE
adjust the UI
2015-02-11 modify genneral setting.
2015-02-11 modify the info for recipe clone.
*/
int main(int argc, char *argv[])
{
    Application a(argc, argv);
	QCoreApplication::addLibraryPath(".\\plugins");

	    //Resource files
    Q_INIT_RESOURCE(tutpics);
    Q_INIT_RESOURCE(lang);
    a.loadTranslations(".\\lang");
    QDir tmp;
    tmp.mkdir(".\\clone");
	if (argc==2){
		QString recipeLine(argv[1]);
		if (recipeLine.toUpper()=="-C"){
			DataBaseHelper::getInstance()->deleteAllRecipes();
		} else {
			Recipe r(recipeLine);
			if (r.check()){
				r.print();
				r.saveToDb();
				RcpMessage aRMsg(r);
			}  else {
				QTextStream(stdout) << "No valid recipe!!" << endl;
			}
		}
        a.exit(0);
	} else	
	if (argc==3){
		QString recipeLine(argv[1]);
		QString recipeName=QString("%L1").arg(argv[2]);
		Recipe r(recipeLine);
		if (r.check()){
			QTextStream(stdout) << recipeName << " saved " << r.toRLine() << " full line " << r.toRLine(true) <<endl;
			r.print();
			r.saveToDb();
			DataBaseHelper::getInstance()->saveRecipeName(r.getId(),recipeName);
		}  else {
			QTextStream(stdout) << "No valid recipe!!" << endl;
		}
        a.exit(0);
        a.deleteLater();
	} else {

        QString lang = DataBaseHelper::getInstance()->getSetting("langStr","zh_CN");
        a.setLanguage(lang);
//        wbsd_SERIAL_PORT::instance();
//        WBSDMainWindow w;
//        w.show();
//        return a.exec();
        if(DataBaseHelper::getInstance()->getswitch()==0)
        {
           wbsd_SERIAL_PORT::instance();
           WBSDMainWindow w;
           w.show();
           return a.exec();
        }else
        {
            wbsd_SERIAL_PORT::instance();
            frmLogin w;
            w.show();
            return a.exec();
        }



	}
}
