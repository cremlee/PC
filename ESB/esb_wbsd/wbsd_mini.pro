#-------------------------------------------------
#
# Project created by QtCreator 2013-03-19T10:13:38
#
#-------------------------------------------------
include(qextserialport.pri)

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Compact_PC_Tool
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
        message.cpp\
        parametermsg.cpp\
        errormessage.cpp\
	wbsd_serial_port.cpp \
    bibrecipe.cpp \
    instrecipe.cpp \
    generalrecipe.cpp \
    stringmessage.cpp \
    wbsdmainwindow.cpp \
    wbsdstartpage.cpp \
    wbsderrorwindow.cpp \
    wbsdcounterswindow.cpp \
    wbsdwaterwindow.cpp \
    wbsdtestingwindow.cpp \
    wbsdoutletwindow.cpp \
    wbsdboilerwindow.cpp \
    wbsdcoolingwindow.cpp \
    wbsdmixerswindow.cpp \
    wbsddoserwindow.cpp \
    wbsddisplaywindow.cpp \
    wbsdversionwindow.cpp \
    wbsdgeneralwindow.cpp \
    wbsddrinkwindow.cpp \
    wbsddrink_window.cpp \
    wbsddisplayoptwindow.cpp \
    wbsdtimewindow.cpp \
    wbsdcleaningwindow.cpp \
    wbsdecowindow.cpp \
    wbsdbasewindow.cpp \
    wbsdchildwindow.cpp \
    wbsdwidget.cpp \
    wbsdbuttoncounters.cpp \
    application.cpp \
    wbsdpumpwindow.cpp \
    wbsdheaterwindow.cpp \
    wbsdinstantwindow.cpp \
    wbsdbuttontestwindow.cpp \
    databasehelper.cpp \
    Recipe.cpp \
    rcpmessage.cpp \
    lngmessage.cpp \
    wbsdcounterstotal.cpp \
    wbsdcalibratecanisterwindow.cpp \
    wbsdpaywindow.cpp \
    wbsdpaysetprice.cpp \
    wbsdpaysetcoinchannel.cpp \
    wbsd_clone.cpp \
    wbsd_paytest.cpp \
    wbsdbtn78cnt.cpp \
    frmlogin.cpp \
    wbsd_happyhour.cpp \
    mywin.cpp \
    wbsd_update.cpp \
    updatemessage.cpp \
    wbsd_run.cpp \
    fmu_calibration.cpp \
    fmu_error.cpp \
    fmu_parameter.cpp \
    fmu_recipe.cpp \
    fmu_setting.cpp \
    fmu_test.cpp \
    fmu_update.cpp \
    wbsd_extern_tool.cpp \
    fmu_message.cpp \
    fmu_clone.cpp


HEADERS  += mainwindow.h\
        message.h \
        parametermsg.h \
        errormessage.h \
         wbsd_serial_port.h \
    bibrecipe.h \
    instrecipe.h \
    generalrecipe.h \
    stringmessage.h \
    wbsdmainwindow.h \
    wbsdstartpage.h \
    wbsderrorwindow.h \
    wbsdcounterswindow.h \
    wbsdwaterwindow.h \
    wbsdtestingwindow.h \
    wbsdoutletwindow.h \
    wbsdboilerwindow.h \
    wbsdcoolingwindow.h \
    wbsdmixerswindow.h \
    wbsddoserwindow.h \
    wbsddisplaywindow.h \
    wbsdversionwindow.h \
    wbsdgeneralwindow.h \
    wbsddrinkwindow.h \
    wbsddisplayoptwindow.h \
    wbsdtimewindow.h \
    wbsdcleaningwindow.h \
    wbsdecowindow.h \
    wbsdbasewindow.h \
    wbsdchildwindow.h \
    wbsdwidget.h \
    wbsdbuttoncounters.h \
    application.h \
    wbsdpumpwindow.h \
    wbsdheaterwindow.h \
    wbsdinstantwindow.h \
    wbsdbuttontestwindow.h \
    databasehelper.h \
    Recipe.h \
    rcpmessage.h \
    lngmessage.h \
    wbsdcounterstotal.h \
    wbsdcalibratecanisterwindow.h \
    wbsdpaywindow.h \
    wbsdpaysetprice.h \
    wbsdpaysetcoinchannel.h \
    wbsddrink_window.h \
    wbsd_clone.h \
    wbsd_paytest.h \
    wbsdbtn78cnt.h \
    frmlogin.h \
    wbsd_happyhour.h \
    mywin.h \
    wbsd_update.h \
    updatemessage.h \
    wbsd_run.h \
    fmu_calibration.h \
    fmu_error.h \
    fmu_parameter.h \
    fmu_recipe.h \
    fmu_setting.h \
    fmu_test.h \
    fmu_update.h \
    wbsd_extern_tool.h \
    fmu_message.h \
    fmu_clone.h

FORMS    += mainwindow.ui \
    noconnection.ui \
    valchanger.ui \
    recipe.ui \
    bibrecipe.ui \
    instrecipe.ui \
    generalrecipe.ui \
    wbsdmainwindow.ui \
    wbsdstartpage.ui \
    wbsderrorwindow.ui \
    wbsdcounterswindow.ui \
    wbsdwaterwindow.ui \
    wbsdtestingwindow.ui \
    wbsdoutletwindow.ui \
    wbsdboilerwindow.ui \
    wbsdcoolingwindow.ui \
    wbsdmixerswindow.ui \
    wbsddoserwindow.ui \
    wbsddisplaywindow.ui \
    wbsdversionwindow.ui \
    wbsdgeneralwindow.ui \
    wbsddrinkwindow.ui \
    wbsddisplayoptwindow.ui \
    wbsdtimewindow.ui \
    wbsdcleaningwindow.ui \
    wbsdecowindow.ui \
    wbsdbuttoncounters.ui \
    wbsdpumpwindow.ui \
    wbsdheaterwindow.ui \
    wbsdinstantwindow.ui \
    wbsdbuttontestwindow.ui \
    wbsdcounterstotal.ui \
    wbsdcalibratecanisterwindow.ui \
    wbsdpaywindow.ui \
    wbsdpaysetprice.ui \
    wbsdpaysetcoinchannel.ui \
    wbsddrink_window.ui \
    wbsd_clone.ui \
    wbsd_paytest.ui \
    wbsdbtn78cnt.ui \
    frmlogin.ui \
    wbsd_happyhour.ui \
    wbsd_update.ui \
    wbsd_run.ui \
    fmu_calibration.ui \
    fmu_error.ui \
    fmu_parameter.ui \
    fmu_setting.ui \
    fmu_test.ui \
    fmu_update.ui \
    wbsd_extern_tool.ui \
    fmu_clone.ui

RESOURCES += tutpics.qrc \
    lang.qrc


TRANSLATIONS += lang/EN_GB.ts lang/ZH_CN.ts


OTHER_FILES += \
    wbsd_esb.pro.user \
    myapp.rc \
    1.jpg

DESTDIR = ./debug
MOC_DIR += ./moc
OBJECTS_DIR += ./obj
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles

#RC_FILE = myapp.rc
