#include "wbsddoserwindow.h"
#include "ui_wbsddoserwindow.h"
#include "wbsdchildwindow.h"
#include "qstring.h"
#include "qdebug.h"
#include "application.h"

WBSDDoserWindow::WBSDDoserWindow(WBSDBaseWindow *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::WBSDDoserWindow)
{
    static const char* back[] = {
        QT_TRANSLATE_NOOP("back_doser", "Back")
    };

    ui->setupUi(this);

    menuBack = new QAction(Application::translate("back_doser",back[0]), this);
		menuBack->setEnabled(true);

    ui->menubar->addAction(menuBack);
    connect( menuBack, SIGNAL(triggered()), this, SLOT(on_menuBack_triggered()));
    ui->leftSlowLab->hide();
    ui->rightSlowLab->hide();
    ui->leftB2SlowTest->hide();
    ui->rightB2SlowTest->hide();
    /*modify by Lee.li
     */
    ui->centralwidget->setLayout(ui->verticalLayout);
}

WBSDDoserWindow::~WBSDDoserWindow()
{
    delete ui;
}

void WBSDDoserWindow::closeEvent(QCloseEvent *)
{
    emit iclose();
}

void WBSDDoserWindow::on_menuBack_triggered()
{
    this->close();
    this->deleteLater();
}

void WBSDDoserWindow::connectionStatusChanged(int aStatus,StringMessage aMSG)
{
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        this->close();
        this->deleteLater();
    }
}

void WBSDDoserWindow::on_leftB2Test_clicked()
{
    ParameterMsg message1(Message::MCB,Message::DV,2);
    ParameterMsg message2(Message::MCB,Message::DV,16);
    message1.setBit(10,1);
    message2.setBit(13,1);
    itsBaseWindow->addMessageToQue(message1);
    itsBaseWindow->addMessageToQue(message2);
}

void WBSDDoserWindow::on_leftB2Test_released()
{
    ParameterMsg message1(Message::MCB,Message::DV,2);
    ParameterMsg message2(Message::MCB,Message::DV,16);
    message1.setBit(10,0);
    message2.setBit(13,0);
    itsBaseWindow->addMessageToQue(message2);
    itsBaseWindow->addMessageToQue(message1);
}

void WBSDDoserWindow::on_rightB2Test_clicked()
{
    ParameterMsg message1(Message::MCB,Message::DV,2);
    ParameterMsg message2(Message::MCB,Message::DV,16);
    message1.setBit(10,1);
    message2.setBit(12,1);
    itsBaseWindow->addMessageToQue(message1);
    itsBaseWindow->addMessageToQue(message2);
}

void WBSDDoserWindow::on_rightB2Test_released()
{
    ParameterMsg message1(Message::MCB,Message::DV,2);
    ParameterMsg message2(Message::MCB,Message::DV,16);
    message1.setBit(10,0);
    message2.setBit(12,0);
    itsBaseWindow->addMessageToQue(message2);
    itsBaseWindow->addMessageToQue(message1);
}

void WBSDDoserWindow::on_leftB2SlowTest_clicked()
{
    ParameterMsg message1(Message::MCB,Message::DV,2);
    ParameterMsg message2(Message::MCB,Message::DV,16);
    message1.setBit(10,1);
    message2.setBit(5,1);
    itsBaseWindow->addMessageToQue(message1);
    itsBaseWindow->addMessageToQue(message2);
}

void WBSDDoserWindow::on_leftB2SlowTest_released()
{
    ParameterMsg message1(Message::MCB,Message::DV,2);
    ParameterMsg message2(Message::MCB,Message::DV,16);
    message1.setBit(10,0);
    message2.setBit(5,0);
    itsBaseWindow->addMessageToQue(message2);
    itsBaseWindow->addMessageToQue(message1);
}

void WBSDDoserWindow::on_rightB2SlowTest_clicked()
{
    ParameterMsg message1(Message::MCB,Message::DV,2);
    ParameterMsg message2(Message::MCB,Message::DV,16);
    message1.setBit(10,1);
    message2.setBit(4,1);
    itsBaseWindow->addMessageToQue(message1);
    itsBaseWindow->addMessageToQue(message2);
}

void WBSDDoserWindow::on_rightB2SlowTest_released()
{
    ParameterMsg message1(Message::MCB,Message::DV,2);
    ParameterMsg message2(Message::MCB,Message::DV,16);
    message1.setBit(10,0);
    message2.setBit(4,0);
    itsBaseWindow->addMessageToQue(message2);
    itsBaseWindow->addMessageToQue(message1);
}

void WBSDDoserWindow::updateData()
{
}

void WBSDDoserWindow::gotMessage(Message aMsg)
{
}
