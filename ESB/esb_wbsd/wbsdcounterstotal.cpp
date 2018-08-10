#include "wbsdcounterstotal.h"
#include "ui_wbsdcounterstotal.h"
#include "wbsdchildwindow.h"
#include "application.h"
#include "parametermsg.h"

WBSDCountersTotal::WBSDCountersTotal(WBSDBaseWindow *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::WBSDCountersTotal)
{

    static const char* back[] = {
        QT_TRANSLATE_NOOP("back_counterstotal", "Back")
    };

    ui->setupUi(this);

    menuBack = new QAction(Application::translate("back_counterstotal",back[0]), this);
		menuBack->setEnabled(true);

    ui->menubar->addAction(menuBack);
    connect( menuBack, SIGNAL(triggered()), this, SLOT(on_menuBack_triggered()));

    updateData();
    ui->centralwidget->setLayout(ui->gridLayout_2);
    if(itsBaseWindow->getUnitTmp() == 0)
    {
        //Litres
       ui->lblUnit0->setText(QObject::tr("Litres"));
       ui->lblUnit1->setText(QObject::tr("Litres"));
       ui->lblUnit6->setText(QObject::tr("Kilogram"));//
       ui->lblUnit3->setText(QObject::tr("Kilogram"));//
       ui->lblUnit4->setText(QObject::tr("Litres"));
       ui->lblUnit5->setText(QObject::tr("Litres"));
       ui->label_16->setText(QObject::tr("Litres"));
       ui->label_18->setText(QObject::tr("Litres"));
    }
    else
    {
        //Gallons
        ui->lblUnit0->setText(QObject::tr("Ounces"));
        ui->lblUnit1->setText(QObject::tr("Ounces"));
        ui->lblUnit6->setText(QObject::tr("Kilogram"));//
        ui->lblUnit3->setText(QObject::tr("Kilogram"));//
        ui->lblUnit4->setText(QObject::tr("Ounces"));
        ui->lblUnit5->setText(QObject::tr("Ounces"));
        ui->label_16->setText(QObject::tr("Ounces"));
        ui->label_18->setText(QObject::tr("Ounces"));
    }
}

WBSDCountersTotal::~WBSDCountersTotal()
{
    delete ui;
}

void WBSDCountersTotal::on_menuBack_triggered()
{
    this->close();
}

void WBSDCountersTotal::connectionStatusChanged(int aStatus,StringMessage aMSG)
{
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        this->close();
        this->deleteLater();
    }
}

void WBSDCountersTotal::updateTotalDrinks(float volCount)
{
    ui->totalDrinks->setText(QString::number(volCount));
}

void WBSDCountersTotal::updateTotalSmall(float volCount)
{
    ui->totalSmall->setText(QString::number(volCount));
}

void WBSDCountersTotal::updateTotalMedium(float volCount)
{
    ui->totalMedium->setText(QString::number(volCount));
}

void WBSDCountersTotal::updateTotalLarge(float volCount)
{
    ui->totalLarge->setText(QString::number(volCount));
}

void WBSDCountersTotal::updateTotalDrinksNoRe(float volCount)
{
    ui->totalDrinksNoRe->setText(QString::number(volCount));
}

void WBSDCountersTotal::updateTotalSmallNoRe(float volCount)
{
    ui->totalSmallNoRe->setText(QString::number(volCount));
}

void WBSDCountersTotal::updateTotalMediumNoRe(float volCount)
{
    ui->totalMediumNoRe->setText(QString::number(volCount));
}

void WBSDCountersTotal::updateTotalLargeNoRe(float volCount)
{
    ui->totalLargeNoRe->setText(QString::number(volCount));
}

void WBSDCountersTotal::updateLeftBIB(float volCount)
{
    ui->leftBIB->setText(QString::number(volCount));
}

void WBSDCountersTotal::updateRightBIB(float volCount)
{
    ui->rightBIB->setText(QString::number(volCount));
}
static double changsmall(double a)
{
    if(a-0<0.0001 && a-0>-0.0001)
    {
        return 0;
    }
    else
    {
        return a;
    }
}
void WBSDCountersTotal::updateInstantVol(float volCount)
{
    ui->instantVol->setText(QString::number(changsmall(volCount*1000)));
}

void WBSDCountersTotal::updateLeftBIBNoRe(float volCount)
{
    ui->leftBIBNoRe->setText(QString::number(volCount));
}

void WBSDCountersTotal::updateRightBIBNoRe(float volCount)
{
    ui->rightBIBNoRe->setText(QString::number(volCount));
}



void WBSDCountersTotal::updateInstantVolNoRe(float volCount)
{
    ui->instantVolNoRe->setText(QString::number(changsmall(volCount*1000)));
}

void WBSDCountersTotal::updateData()
{
    ParameterMsg msg0(Message::MCB,Message::AP, 184);
    ParameterMsg msg1(Message::MCB,Message::AP, 185);
    ParameterMsg msg2(Message::MCB,Message::AP, 186);
    ParameterMsg msg3(Message::MCB,Message::AP, 187);
    ParameterMsg msg4(Message::MCB,Message::AP, 188);
    ParameterMsg msg5(Message::MCB,Message::AP, 189);
    ParameterMsg msg6(Message::MCB,Message::AP, 190);
    ParameterMsg msg7(Message::MCB,Message::AP, 191);
    ParameterMsg msg8(Message::MCB,Message::AP, 12);
    ParameterMsg msg9(Message::MCB,Message::AP, 13);
    ParameterMsg msg10(Message::MCB,Message::AP, 14);
    ParameterMsg msg11(Message::MCB,Message::AP, 15);
    ParameterMsg msg12(Message::MCB,Message::AP, 16);
    ParameterMsg msg13(Message::MCB,Message::AP, 17);
    msg0.getFloat();
    msg1.getFloat();
    msg2.getFloat();
    msg3.getFloat();
    msg4.getFloat();
    msg5.getFloat();
    msg6.getFloat();
    msg7.getFloat();
    msg8.getFloat();
    msg9.getFloat();
    msg10.getFloat();
    msg11.getFloat();
    msg12.getFloat();
    msg13.getFloat();
    itsBaseWindow->addMessageToQue(msg0);
    itsBaseWindow->addMessageToQue(msg1);
    itsBaseWindow->addMessageToQue(msg2);
    itsBaseWindow->addMessageToQue(msg3);
    itsBaseWindow->addMessageToQue(msg4);
    itsBaseWindow->addMessageToQue(msg5);
    itsBaseWindow->addMessageToQue(msg6);
    itsBaseWindow->addMessageToQue(msg7);
    itsBaseWindow->addMessageToQue(msg8);
    itsBaseWindow->addMessageToQue(msg9);
    itsBaseWindow->addMessageToQue(msg10);
    itsBaseWindow->addMessageToQue(msg11);
    itsBaseWindow->addMessageToQue(msg12);
    itsBaseWindow->addMessageToQue(msg13);
    gettotalcountcmd();
    gettotalcountnrcmd();
}

void WBSDCountersTotal::closeEvent(QCloseEvent *)
{
    emit iclose();
}

void WBSDCountersTotal::gettotalcountcmd()
{
    ParameterMsg msg0(Message::MCB,Message::AP,40);
    ParameterMsg msg1(Message::MCB,Message::AP,66);
    ParameterMsg msg2(Message::MCB,Message::AP,92);
    ParameterMsg msg3(Message::MCB,Message::AP,118);
    ParameterMsg msg4(Message::MCB,Message::AP,144);
    ParameterMsg msg5(Message::MCB,Message::AP,170);
    ParameterMsg msg6(Message::MCB,Message::AP,195);
    msg0.getFloat();
    msg1.getFloat();
    msg2.getFloat();
    msg3.getFloat();
    msg4.getFloat();
    msg5.getFloat();
    msg6.getFloat();
    itsBaseWindow->addMessageToQue(msg0);
    itsBaseWindow->addMessageToQue(msg1);
    itsBaseWindow->addMessageToQue(msg2);
    itsBaseWindow->addMessageToQue(msg3);
    itsBaseWindow->addMessageToQue(msg4);
    itsBaseWindow->addMessageToQue(msg5);
    itsBaseWindow->addMessageToQue(msg6);

}

void WBSDCountersTotal::gettotalcountnrcmd()
{
    ParameterMsg msg0(Message::MCB,Message::AP,53);
    ParameterMsg msg1(Message::MCB,Message::AP,79);
    ParameterMsg msg2(Message::MCB,Message::AP,105);
    ParameterMsg msg3(Message::MCB,Message::AP,131);
    ParameterMsg msg4(Message::MCB,Message::AP,157);
    ParameterMsg msg5(Message::MCB,Message::AP,183);
    ParameterMsg msg6(Message::MCB,Message::AP,198);
    msg0.getFloat();
    msg1.getFloat();
    msg2.getFloat();
    msg3.getFloat();
    msg4.getFloat();
    msg5.getFloat();
    msg6.getFloat();
    itsBaseWindow->addMessageToQue(msg0);
    itsBaseWindow->addMessageToQue(msg1);
    itsBaseWindow->addMessageToQue(msg2);
    itsBaseWindow->addMessageToQue(msg3);
    itsBaseWindow->addMessageToQue(msg4);
    itsBaseWindow->addMessageToQue(msg5);
    itsBaseWindow->addMessageToQue(msg6);
}

void WBSDCountersTotal::updatetotalroll(qreal a, int b)
{

//    66
//    92
//    118
//    144
//    170
    if(b == 40 ){totalconut.btn1vol = a;totalconut.Isbtn1get=true;}
    if(b == 66 ){totalconut.btn2vol = a;totalconut.Isbtn2get=true;}
    if(b == 92 ){totalconut.btn3vol = a;totalconut.Isbtn3get=true;}
    if(b == 118 ){totalconut.btn4vol = a;totalconut.Isbtn4get=true;}
    if(b == 144 ){totalconut.btn5vol = a;totalconut.Isbtn5get=true;}
    if(b == 170 ){totalconut.btn6vol = a;totalconut.Isbtn6get=true;}
    if(b == 195 ){totalconut.btn7vol = 0;totalconut.Isbtn7get=true;}
    if(totalconut.isready())
    {
        ui->label_17->setText(QString::number(totalconut.getall()));
    }else
    {
        ui->label_17->setText("data inquiring...");
    }


    if(b == 53 ){totalconutnr.btn1vol = a;totalconutnr.Isbtn1get=true;}
    if(b == 79 ){totalconutnr.btn2vol = a;totalconutnr.Isbtn2get=true;}
    if(b == 105 ){totalconutnr.btn3vol = a;totalconutnr.Isbtn3get=true;}
    if(b == 131 ){totalconutnr.btn4vol = a;totalconutnr.Isbtn4get=true;}
    if(b == 157 ){totalconutnr.btn5vol = a;totalconutnr.Isbtn5get=true;}
    if(b == 183 ){totalconutnr.btn6vol = a;totalconutnr.Isbtn6get=true;}
    if(b == 198 ){totalconutnr.btn7vol = 0;totalconutnr.Isbtn7get=true;}
    if(totalconutnr.isready())
    {
        ui->label_19->setText(QString::number(totalconutnr.getall()));
    }else
    {
        ui->label_19->setText("data inquiring...");
    }


}

void WBSDCountersTotal::gotMessage(Message aMsg)
{
    if ((aMsg.getType()==Message::REPLY_DB) && ((unsigned char)aMsg.getBoard()==Message::MCB) && (aMsg.getDataBaseType()==Message::AP)){
        unsigned char index=aMsg.getParameters().at(3);
        qDebug() << "WBSDCountersTotal::gotMessage " << index;
        switch(index){
            case 184:
                updateTotalDrinks(aMsg.getDataFloat());
                break;
            case 185:
                updateTotalSmall(aMsg.getDataFloat());
                break;
            case 186:
                updateTotalMedium(aMsg.getDataFloat());
                break;
            case 187:
                updateTotalLarge(aMsg.getDataFloat());
                break;
            case 188:
                updateTotalDrinksNoRe(aMsg.getDataFloat());
                break;
            case 189:
                updateTotalSmallNoRe(aMsg.getDataFloat());
                break;
            case 190:
                updateTotalMediumNoRe(aMsg.getDataFloat());
                break;
            case 191:
                updateTotalLargeNoRe(aMsg.getDataFloat());
                break;
            case 12:
                updateLeftBIB(aMsg.getDataFloat());
                break;
            case 13:
                updateRightBIB(aMsg.getDataFloat());
                break;
            case 14:
                updateInstantVol(aMsg.getDataFloat());
                break;
            case 15:
                updateLeftBIBNoRe(aMsg.getDataFloat());
                break;
            case 16:
                updateRightBIBNoRe(aMsg.getDataFloat());
                break;
            case 17:
                updateInstantVolNoRe(aMsg.getDataFloat());
                break;
        case 40:
        case 66:
        case 92:
        case 118:
        case 144:
        case 170:
        case 53:
        case 79:
        case 105:
        case 131:
        case 157:
        case 183:
        case 195:
        case 198:
            updatetotalroll(aMsg.getDataFloat(),index);
            break;
            default:
                break;
        }
    }

}
