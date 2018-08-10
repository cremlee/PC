#include "wbsdbuttontestwindow.h"
#include "ui_wbsdbuttontestwindow.h"
#include "wbsdchildwindow.h"
#include "wbsdchildwindow.h"
#include "qstring.h"
#include "qdebug.h"
#include "application.h"

WBSDButtonTestWindow::WBSDButtonTestWindow(WBSDBaseWindow *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::WBSDButtonTestWindow)
{
    static const char* back[] = {
        QT_TRANSLATE_NOOP("back_buttontest", "Back")
    };

    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose,true);
    menuBack = new QAction(Application::translate("back_buttontest",back[0]), this);
		menuBack->setEnabled(true);

    ui->menubar->addAction(menuBack);
    connect( menuBack, SIGNAL(triggered()), this, SLOT(on_menuBack_triggered()));

    myTimer = new QTimer(this);
    connect(myTimer,SIGNAL(timeout()),this,SLOT(updateData()));
    myTimer->start(500);
    updateButton();
    ui->centralwidget->setLayout(ui->gridLayout);
}

WBSDButtonTestWindow::~WBSDButtonTestWindow()
{
    myTimer->stop();
    myTimer->deleteLater();
    myTimer=0;
    delete ui;
    this->deleteLater();
}

void WBSDButtonTestWindow::closeEvent(QCloseEvent *)
{
    emit iclose();
}

void WBSDButtonTestWindow::on_menuBack_triggered()
{
    this->close();
}

void WBSDButtonTestWindow::connectionStatusChanged(int aStatus,StringMessage aMSG)
{
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        this->close();
        this->deleteLater();
    }
}

void WBSDButtonTestWindow::updateButtonStatus(unsigned int conf)
{
    QString qss=QString("RJDEBUG WBSDButtonTestWindow::updateButtonStatus data %1").arg(conf);
    qDebug () << qss;

    int button1 = (conf & 0x8000) >> 15;
    int button2 = (conf & 0x4000) >> 14;
    int button3 = (conf & 0x2000) >> 13;
    int button4 = (conf & 0x1000) >> 12;
    int button5 = (conf & 0x800) >> 11;
    int button6 = (conf & 0x400) >> 10;
    int button7 = (conf & 0x200) >> 9;
    int button8 = (conf & 0x100) >> 8;
    int button9 = (conf & 0x80) >> 7;
    int button10 = (conf & 0x40) >> 6;
    int button11 = (conf & 0x20) >> 5;
    int button12 = (conf & 0x10) >> 4;


    if (button1 == 1)
    {
        ui->button1->setAutoFillBackground(true);
        //ui->button1->setStyleSheet("background-color: rgb(255, 0, 0); color: rgb(255, 255, 255)");
        ui->button1->setStyleSheet("background-color: green");
    }
    else
    {
        ui->button1->setAutoFillBackground(true);
        ui->button1->setStyleSheet("background-color: red");
    }
    if (button2 == 1)
    {
        ui->button2->setAutoFillBackground(true);
        ui->button2->setStyleSheet("background-color: green");
    }
    else
    {
        ui->button2->setAutoFillBackground(true);
        ui->button2->setStyleSheet("background-color: red");
    }
    if (button3 == 1)
    {
        ui->button3->setAutoFillBackground(true);
        ui->button3->setStyleSheet("background-color: green");
    }
    else
    {
        ui->button3->setAutoFillBackground(true);
        ui->button3->setStyleSheet("background-color: red");
    }
    if (button4 == 1)
    {
        ui->button4->setAutoFillBackground(true);
        ui->button4->setStyleSheet("background-color: green");
    }
    else
    {
        ui->button4->setAutoFillBackground(true);
        ui->button4->setStyleSheet("background-color: red");
    }
    if (button5 == 1)
    {
        ui->button5->setAutoFillBackground(true);
        ui->button5->setStyleSheet("background-color: green");
    }
    else
    {
        ui->button5->setAutoFillBackground(true);
        ui->button5->setStyleSheet("background-color: red");
    }
    if (button6 == 1)
    {
        ui->button6->setAutoFillBackground(true);
        ui->button6->setStyleSheet("background-color: green");
    }
    else
    {
        ui->button6->setAutoFillBackground(true);
        ui->button6->setStyleSheet("background-color: red");
    }
    if (button7 == 1)
    {
        ui->button7->setAutoFillBackground(true);
        ui->button7->setStyleSheet("background-color: green");
    }
    else
    {
        ui->button7->setAutoFillBackground(true);
        ui->button7->setStyleSheet("background-color: red");
    }
    if (button8 == 1)
    {
        ui->button8->setAutoFillBackground(true);
        ui->button8->setStyleSheet("background-color: green");
    }
    else
    {
        ui->button8->setAutoFillBackground(true);
        ui->button8->setStyleSheet("background-color: red");
    }
    if (button9 == 1)
    {
        qDebug() << "button 9";
        ui->button9->setAutoFillBackground(true);
        ui->button9->setStyleSheet("background-color: green");
    }
    else
    {
        ui->button9->setAutoFillBackground(true);
        ui->button9->setStyleSheet("background-color: red");
    }
    if (button10 == 1)
    {
        qDebug() << "button 10";
        ui->button10->setAutoFillBackground(true);
        ui->button10->setStyleSheet("background-color: green");
    }
    else
    {
        ui->button10->setAutoFillBackground(true);
        ui->button10->setStyleSheet("background-color: red");
    }
    if (button11 == 1)
    {
        qDebug() << "button 11";
        ui->button11->setAutoFillBackground(true);
        ui->button11->setStyleSheet("background-color: green");
    }
    else
    {
        ui->button11->setAutoFillBackground(true);
        ui->button11->setStyleSheet("background-color: red");
    }
    if (button12 == 1)
    {
        ui->button12->setAutoFillBackground(true);
        ui->button12->setStyleSheet("background-color: green");
    }
    else
    {
        ui->button12->setAutoFillBackground(true);
        ui->button12->setStyleSheet("background-color: red");
    }
}

void WBSDButtonTestWindow::updateButton()
{
    static const char* buttonTest[] = {
        QT_TRANSLATE_NOOP("buttontest_txt", "Button 1"),
        QT_TRANSLATE_NOOP("buttontest_txt", "Button 2"),
        QT_TRANSLATE_NOOP("buttontest_txt", "Button 3"),
        QT_TRANSLATE_NOOP("buttontest_txt", "Button 4"),
        QT_TRANSLATE_NOOP("buttontest_txt", "Button 5"),
        QT_TRANSLATE_NOOP("buttontest_txt", "Button 6"),
        QT_TRANSLATE_NOOP("buttontest_txt", "Button 7"),
        QT_TRANSLATE_NOOP("buttontest_txt", "Button 8"),
        QT_TRANSLATE_NOOP("buttontest_txt", "Button 9"),
        QT_TRANSLATE_NOOP("buttontest_txt", "Button 10"),
        QT_TRANSLATE_NOOP("buttontest_txt", "Button 11"),
        QT_TRANSLATE_NOOP("buttontest_txt", "Button 12")
    };

    ui->button1->setText(Application::translate("buttontest_txt",buttonTest[0]));
    ui->button1->setStyleSheet("background-color: red");
    ui->button2->setText(Application::translate("buttontest_txt",buttonTest[1]));
    ui->button2->setStyleSheet("background-color: red");
    ui->button3->setText(Application::translate("buttontest_txt",buttonTest[2]));
    ui->button3->setStyleSheet("background-color: red");
    ui->button4->setText(Application::translate("buttontest_txt",buttonTest[3]));
    ui->button4->setStyleSheet("background-color: red");
    ui->button5->setText(Application::translate("buttontest_txt",buttonTest[4]));
    ui->button5->setStyleSheet("background-color: red");
    ui->button6->setText(Application::translate("buttontest_txt",buttonTest[5]));
    ui->button6->setStyleSheet("background-color: red");
    ui->button7->setText(Application::translate("buttontest_txt",buttonTest[6]));
    ui->button7->setStyleSheet("background-color: red");
    ui->button8->setText(Application::translate("buttontest_txt",buttonTest[7]));
    ui->button8->setStyleSheet("background-color: red");
    ui->button9->setText(Application::translate("buttontest_txt",buttonTest[8]));
    ui->button9->setStyleSheet("background-color: red");
    ui->button10->setText(Application::translate("buttontest_txt",buttonTest[9]));
    ui->button10->setStyleSheet("background-color: red");
    ui->button11->setText(Application::translate("buttontest_txt",buttonTest[10]));
    ui->button11->setStyleSheet("background-color: red");
    ui->button12->setText(Application::translate("buttontest_txt",buttonTest[11]));
    ui->button12->setStyleSheet("background-color: red");
}

void WBSDButtonTestWindow::on_button1_pressed()
{
    ui->button1->setAutoFillBackground(true);
    ui->button1->setStyleSheet("background-color: green");
    ParameterMsg message1(Message::UIB,Message::DV,1);
    message1.setWord(1<<15);
    itsBaseWindow->addMessageToQue(message1);

}

void WBSDButtonTestWindow::on_button1_released()
{
    ui->button1->setAutoFillBackground(true);
    ui->button1->setStyleSheet("background-color: red");
}

void WBSDButtonTestWindow::on_button2_pressed()
{
    ui->button2->setAutoFillBackground(true);
    ui->button2->setStyleSheet("background-color: green");
    ParameterMsg message1(Message::UIB,Message::DV,1);
    message1.setWord(1<<14);
    itsBaseWindow->addMessageToQue(message1);

}

void WBSDButtonTestWindow::on_button2_released()
{
    ui->button2->setAutoFillBackground(true);
    ui->button2->setStyleSheet("background-color: red");
}

void WBSDButtonTestWindow::on_button3_pressed()
{
    ui->button3->setAutoFillBackground(true);
    ui->button3->setStyleSheet("background-color: green");
    ParameterMsg message1(Message::UIB,Message::DV,1);
    message1.setWord(1<<13);
    itsBaseWindow->addMessageToQue(message1);

}

void WBSDButtonTestWindow::on_button3_released()
{
    ui->button3->setAutoFillBackground(true);
    ui->button3->setStyleSheet("background-color: red");
}

void WBSDButtonTestWindow::updateData()
{
    ParameterMsg msg1(Message::UIB,Message::DV,1);
    msg1.getWord();
    itsBaseWindow->addMessageToQue(msg1);
}

void WBSDButtonTestWindow::gotMessage(Message aMsg)
{
    unsigned int aVal;
    QByteArray data=aMsg.getData();
    QString hex=QString(data.toHex());
    aVal= 0xFFFF & aMsg.getDataUInt();
    Message::qtype atype=aMsg.getType();
    switch (atype){
        case (Message::REPLY_DB):
            switch ((unsigned char)aMsg.getBoard()){
                case (Message::MCB):
                    switch ((unsigned char)aMsg.getDataBaseType()){
                        case Message::DP:
                            switch(aMsg.getParameters().at(3)){
                                default:
                                    break;
                            }

                    }
                    break;
                case (Message::UIB):
                    switch ((unsigned char)aMsg.getDataBaseType()){
                        case Message::DV:
                            switch (aMsg.getParameters().at(3)){
                                case (1):
                                    updateButtonStatus(aVal);
                                    break;
                                default:
                                    break;
                            }
                    }
                    break;
                default:
                    break;
            }
    }
}
