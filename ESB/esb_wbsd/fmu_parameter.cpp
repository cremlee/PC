#include "fmu_parameter.h"
#include "ui_fmu_parameter.h"
#include "parametermsg.h"
#include<QMessageBox>
#include<QDebug>
#include"fmu_message.h"
#include<application.h>
static const char* back[] = {
        QT_TRANSLATE_NOOP("back_version", "Back")
    };
FMU_PARAMETER::FMU_PARAMETER(WBSDBaseWindow *parent, int fromrcp) :
    WBSDChildWindow(parent),
    ui(new Ui::FMU_PARAMETER)
{
    ui->setupUi(this);

    m_systemid =-1;
    //m_recipeid =fromrcp;
    qDebug()<<"fromrcp="<<fromrcp;
    menuBack = new QAction(Application::translate("back_doser",back[0]), this);
        menuBack->setEnabled(true);

    ui->menubar->addAction(menuBack);
    connect( menuBack, SIGNAL(triggered()), this, SLOT(on_menuBack_triggered()));
    updateData();
    initmap();
    ui->tab_parameter->removeTab(0);
    if(fromrcp!=-1)
    {
        m_recipeid =fromrcp;
        //getrecipeinfo(m_recipeid);
        for(int i=0;i<ui->cb_recipe->count();i++)
        {
            if(fromrcp == ui->cb_recipe->itemData(i).toInt())
            {
                this->ui->cb_recipe->setCurrentIndex(i);
                break;
            }
        }
        //ui->tab_sub_sys->setEnabled(false);
        //ui->tab_parameter->removeTab(0);
        getrecipeinfo(m_recipeid);

    }else
    {
        m_recipeid =1;
        getrecipeinfo(m_recipeid);
    }
    ui->centralwidget->setLayout(ui->verticalLayout);
    myTimer=new QTimer(this);
    myTimer->setSingleShot(true);
    this->setWindowTitle(QObject::tr("MMP parameter settings"));
    ui->treeWidget->expandAll();
    HideRcpPart();
}

FMU_PARAMETER::~FMU_PARAMETER()
{
    delete ui;
}

void FMU_PARAMETER::closeEvent(QCloseEvent *evt)
{
    itsBaseWindow->setwincheck(false);
    itsBaseWindow->setOt(5000);
    if(!isblockiclose)
     emit iclose();
}

void FMU_PARAMETER::getrecipeinfo(int id)
{
     int dataindex = ((id&0x0000ffff)<<16);

     fmu_message msg;
     msg.GetParam(dataindex);
     qDebug()<<"send message=="<<msg.getMsg().toHex();
     itsBaseWindow->addMessageToQue(msg);

     dataindex +=3;

     fmu_message msg1;
     msg1.GetParam(dataindex);
     qDebug()<<"send message=="<<msg.getMsg().toHex();
     itsBaseWindow->addMessageToQue(msg1);

//     for(int i=0;i<13;i++)
//     {
//         fmu_message msg;
//         msg.GetParam(dataindex++);
//         qDebug()<<"send message=="<<msg.getMsg().toHex();
//         itsBaseWindow->addMessageToQue(msg);
//     }
}


//CREM recipe nr	Recipe Name	FMU ID

//Cafe au lait	15
//Cafe au lait foam	35
//Cappuccino	13
//cappuccino 2	13
//Coffee milk	22
//Hot milk	2
//Hot milk foamed	33
//Latte	25
//Latte macchiato	17
//latte macchiato 2	17
//Latte macchiato fast	not in
//latte macchiato fast 2	not in
//Choco de luxe (instant choco)	36
//Wiener melange (instant choco)	37
//Cafe au lait sugar	15
//Cappuccino sugar	13
//Coffee Milk Sugar	22


void FMU_PARAMETER::updateData()
{
     ui->cb_recipe->addItem(tr("Cafe au lait/Cafe au lait sugar"),15);
     ui->cb_recipe->addItem(tr("Cafe au lait foam"),35);
     ui->cb_recipe->addItem(tr("Cappuccino/Cappuccino sugar"),13);
     ui->cb_recipe->addItem(tr("Coffee milk/Weiner Melange"),22);
     ui->cb_recipe->addItem(tr("Hot milk"),2);
     ui->cb_recipe->addItem(tr("Hot milk foamed"),33);
     ui->cb_recipe->addItem(tr("Latte"),25);
     ui->cb_recipe->addItem(tr("Latte macchiato"),17);
     ui->cb_recipe->addItem(tr("Choco de luxe (instant choco)"),36);
     ui->cb_recipe->addItem(tr("Wiener melange (instant choco)"),37);
     connect(ui->treeWidget, SIGNAL(clicked ( const QModelIndex &)), this, SLOT(treeitemclicked(const QModelIndex &)));
     for(int i=100;i<107;i++)
     {
         fmu_message msg;
         msg.GetParam(i);
         qDebug()<<"send message=="<<msg.getMsg().toHex();
         itsBaseWindow->addMessageToQue(msg);
     }
     for(int i=110;i<122;i++)
     {
         fmu_message msg;
         msg.GetParam(i);
         qDebug()<<"send message=="<<msg.getMsg().toHex();
         itsBaseWindow->addMessageToQue(msg);
     }
}

void FMU_PARAMETER::gotMessage(Message aMsg)
{
    Message::qtype atype=aMsg.getType();
    if(atype == fmu_message::FMU_PARAM_GET)
    {
       bool f;
       int flag = aMsg.getMsg().mid(4,4).toHex().toInt(&f,16);
       int value = aMsg.getMsg().mid(8,4).toHex().toInt(&f,16);
       if((flag &0xffff0000) == 0)
       {
            ui->sp_value->setValue(value);
            switch (flag) {
            case 100:
                ui->lb_id_100->setText(QString::number(value));
                break;
            case 101:
                ui->lb_id_101->setText(QString::number(value));
                break;
            case 102:
                ui->lb_id_102->setText(QString::number(value));
                break;
            case 103:
                ui->lb_id_103->setText(QString::number(value));
                break;
            case 104:
                ui->lb_id_104->setText(QString::number(value));
                break;
            case 105:
                ui->lb_id_105->setText(QString::number(value));
                break;
            case 106:
                ui->lb_id_106->setText(QString::number(value));
                break;
            case 110:
                ui->lb_id_110->setText(QString::number(value));
                break;
            case 111:
                ui->lb_id_111->setText(QString::number(value));
                break;
            case 112:
                ui->lb_id_112->setText(QString::number(value));
                break;
            case 113:
                ui->lb_id_113->setText(QString::number(value));
                break;
            case 114:
                ui->lb_id_114->setText(QString::number(value));
                break;
            case 115:
                ui->lb_id_115->setText(QString::number(value));
                break;
            case 116:
                ui->lb_id_116->setText(QString::number(value));
                break;
            case 117:
                ui->lb_id_117->setText(QString::number(value));
                break;
            case 118:
                ui->lb_id_118->setText(QString::number(value));
                break;
            case 119:
                ui->lb_id_119->setText(QString::number(value));
                break;
            case 120:
                ui->lb_id_120->setText(QString::number(value));
                break;
            case 121:
                ui->lb_id_121->setText(QString::number(value));
                break;
            default:
                break;
            }
       }
       else
       {
           int index = flag&0x0000ffff;
           updaterecipeinfo(index,value);
       }
    }
    else if(atype == fmu_message::FMU_PARAM_SET)
    {

    }
    else if(atype == fmu_message::FMU_RESET)
    {

    }
    else if(atype == fmu_message::FMU_RESET_FINISH)
    {
        if(myTimer->isActive())
            myTimer->stop();
        ui->btn_load->setEnabled(true);
        itsBaseWindow->setwincheck(false);
        itsBaseWindow->setOt(5000);
    }
    qDebug()<<"got message=="<<aMsg.getMsg().toHex();
}

void FMU_PARAMETER::connectionStatusChanged(int aStatus, StringMessage aMSG)
{
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        isblockiclose=true;
        this->close();
        this->deleteLater();
    }
}



void FMU_PARAMETER::on_cb_recipe_actived()
{
   m_recipeid =  ui->cb_recipe->itemData(ui->cb_recipe->currentIndex()).toInt();
   getrecipeinfo(m_recipeid);
}

void FMU_PARAMETER::on_spinBox_1_editingFinished()
{
    SetRecipeInfo(1,ui->spinBox_1->value());
}

void FMU_PARAMETER::on_spinBox_2_editingFinished()
{
    SetRecipeInfo(2,ui->spinBox_2->value());
}

void FMU_PARAMETER::on_spinBox_3_editingFinished()
{
     SetRecipeInfo(3,ui->spinBox_3->value());
}
void FMU_PARAMETER::on_spinBox_4_editingFinished()
{
     SetRecipeInfo(4,ui->spinBox_4->value());
}
void FMU_PARAMETER::on_spinBox_5_editingFinished()
{
     SetRecipeInfo(5,ui->spinBox_5->value());
}
void FMU_PARAMETER::on_spinBox_6_editingFinished()
{
     SetRecipeInfo(6,ui->spinBox_6->value());
}
void FMU_PARAMETER::on_spinBox_7_editingFinished()
{
     SetRecipeInfo(7,ui->spinBox_7->value());
}
void FMU_PARAMETER::on_spinBox_8_editingFinished()
{
     SetRecipeInfo(8,ui->spinBox_8->value());
}
void FMU_PARAMETER::on_spinBox_9_editingFinished()
{
     SetRecipeInfo(9,ui->spinBox_9->value());
}
void FMU_PARAMETER::on_spinBox_10_editingFinished()
{
     SetRecipeInfo(10,ui->spinBox_10->value());
}
void FMU_PARAMETER::on_spinBox_11_editingFinished()
{
     SetRecipeInfo(11,ui->spinBox_11->value());
}
void FMU_PARAMETER::on_spinBox_12_editingFinished()
{
    SetRecipeInfo(12,ui->spinBox_12->value());
}

void FMU_PARAMETER::on_spinBox_13_editingFinished()
{
    SetRecipeInfo(13,ui->spinBox_13->value());
}

void FMU_PARAMETER::SetRecipeInfo(char index, int value)
{
    int sendid = (m_recipeid<<16) +(index-1);
    fmu_message msg;
    msg.SetParam(sendid,value);
    qDebug()<<"send message=="<<msg.getMsg().toHex();
    itsBaseWindow->addMessageToQue(msg);

}

void FMU_PARAMETER::updaterecipeinfo(int index, int value)
{
    index = index%13;
    switch (index) {
    case 0:
        ui->spinBox_1->setValue(value);
        break;
    case 1:
        ui->spinBox_2->setValue(value);
        break;
    case 2:
        ui->spinBox_3->setValue(value);
        break;
    case 3:
        ui->spinBox_4->setValue(value);
        break;
    case 4:
        ui->spinBox_5->setValue(value);
        break;
    case 5:
        ui->spinBox_6->setValue(value);
        break;
    case 6:
        ui->spinBox_7->setValue(value);
        break;
    case 7:
        ui->spinBox_8->setValue(value);
        break;
    case 8:
        ui->spinBox_9->setValue(value);
        break;
    case 9:
        ui->spinBox_10->setValue(value);
        break;
    case 10:
        ui->spinBox_11->setValue(value);
        break;
    case 11:
        ui->spinBox_12->setValue(value);
        break;
    case 12:
        ui->spinBox_13->setValue(value);
        break;
    default:
        break;
    }
}

void FMU_PARAMETER::updatesysteminfo(int index, int value)
{
     ui->lbl_id->setText(QString::number(index));
     ui->sp_value->setValue(value);

}

void FMU_PARAMETER::on_sp_value_editingFinished()
{

   // QMessageBox::information(this,"提示",QString::number(m_systemid)+"="+QString::number(ui->sp_value->value()));
}

QString FMU_PARAMETER::getSysParInfo(int index)
{
    if(parainfo.contains(index))
        return parainfo.value(index);
    else
        return "Reserved for future";
}

void FMU_PARAMETER::initmap()
{
    parainfo.clear();
    parainfo.insert(100,tr("Clean shot time out,timeout for sending clean shot command without feedback"));
    parainfo.insert(101,tr("clean shot volume"));
    parainfo.insert(102,tr("clean shot temperature"));
    parainfo.insert(103,tr("Ratio for the pump for clean shot"));
    parainfo.insert(104,tr("clean shot after dispense time(including calibration)"));
    parainfo.insert(105,tr("free flow timeout"));
    parainfo.insert(106,tr("Clock sync timeout"));
    parainfo.insert(110,tr("Conductivity Threshold1,might be used in judge clean or dispense"));
    parainfo.insert(111,tr("Conductivity Threshold2,might be used in judge clean or dispense"));
    parainfo.insert(112,tr("capacitive sensor enable flag(0=disable the function)"));
    parainfo.insert(113,tr("milk check enable during predispense phase flag(0=disable the detect)"));
    parainfo.insert(114,tr("milk check enable during dispense flag(0=disable the detect)"));
    parainfo.insert(115,tr("If flow meter inside or not(0 = no flow meter and warning,1 = normal)"));
    parainfo.insert(116,tr("Guiccar use 2000,if old flowmeter 600"));
    parainfo.insert(117,tr("timeout for no pulse from flow meter, when inlet valve is opened"));
    parainfo.insert(118,tr("Timeout for inlet valve keep opened"));
    parainfo.insert(119,tr("enable or disable the FTH connection detection, check temperature during heating"));
    parainfo.insert(120,tr("pump software protection function"));
    parainfo.insert(121,tr("If reach the count without clean, machine block and cleaning overdue"));

//    117	flow meter no pulse timeout	2000				msec	timeout for no pulse from flow meter, when inlet valve is opened
//    118	inlet valve open timeout	90				sec	Timeout for inlet valve keep opened
//    119	FTH connection detect enable	0				NA	enable or disable the FTH connection detection, check temperature during heating
//    120	pump software protection	0				NA	pump software protection function
//    121	cup count for clean	300				cups	If reach the count without clean, machine block and cleaning overdue.


    parainfo.insert(200,tr("Empty tube time(clean cycle 101 )"));
    parainfo.insert(201,tr("Aditional pause time after empty tube(clean cycle 102 )"));
    parainfo.insert(202,tr("Fill reservior volume(clean cycle 104)"));
    parainfo.insert(203,tr("Fill reservior temperature(clean cycle 103/104)"));
    parainfo.insert(204,tr("Fill reservior pump speed(clean cycle 103/104)"));
    parainfo.insert(205,tr("Empty tube time(clean cycle 106 )"));
    parainfo.insert(206,tr("Aditional pause time after empty tube(clean cycle 107 )"));
    parainfo.insert(207,tr("Pause to second phase(clean cycle 113 )"));
    parainfo.insert(208,tr("Rinse line water volume(clean cycle 202)"));
    parainfo.insert(209,tr("Rinse line water temperature(clean cycle 201/202)"));
    parainfo.insert(210,tr("Rinse line pump speed(clean cycle 202)"));
    parainfo.insert(211,tr("Fill reservior volume(clean cycle 203)"));
    parainfo.insert(212,tr("Fill reservior temperature(clean cycle 203)"));
    parainfo.insert(213,tr("Fill reservior pump speed(clean cycle 203)"));
    parainfo.insert(214,tr("circulation  temperature(clean cycle 204/205)"));
    parainfo.insert(215,tr("circulation  pump speed(clean cycle 204/205)"));
    parainfo.insert(216,tr("circulation time(clean cycle 205)"));
    parainfo.insert(217,tr("Fill reservior volume(clean cycle 208)"));
    parainfo.insert(218,tr("Fill reservior temperature(clean cycle 207/208)"));
    parainfo.insert(219,tr("Fill reservior pump speed(clean cycle 208)"));
    parainfo.insert(220,tr("circulation temperature(clean cycle 209)"));
    parainfo.insert(221,tr("circulation  pump speed(clean cycle 209)"));
    parainfo.insert(222,tr("circulation time(clean cycle 209)"));
    parainfo.insert(223,tr("Sequese numbers(clean cycle 210)"));
    parainfo.insert(224,tr("circulation temperature(clean cycle 210)"));
    parainfo.insert(225,tr("circulation  pump speed(clean cycle 210)"));
    parainfo.insert(226,tr("circulation time(clean cycle 210)"));
    parainfo.insert(227,tr("Air valve open for blow(clean cycle 210)"));
    parainfo.insert(228,tr("Empty reservior time(clean cycle 211)"));
    parainfo.insert(229,tr("blow air inside to drain the tubes(clean cycle 212)"));
    parainfo.insert(230,tr("Empty reservior time(clean cycle 301)"));
    parainfo.insert(231,tr("Flush to reservior first time volume(clean cycle 302)"));
    parainfo.insert(232,tr("Flush to reservior temperature(clean cycle 302)"));
    parainfo.insert(233,tr("Flush to reservior second time volume(clean cycle 302)"));
    parainfo.insert(234,tr("Flush to reservior pmup speed"));
    parainfo.insert(235,tr("Flush to reservior third time volume(clean cycle 302)"));
    parainfo.insert(236,tr("Flush to reservior third time air vlave volume(clean cycle 302)"));
    parainfo.insert(237,tr("Empty reservior time(clean cycle 303)"));
    parainfo.insert(238,tr("blow air inside to drain the tubes(clean cycle 304)"));
}

void FMU_PARAMETER::HideRcpPart()
{
   QObjectList childrens =  this->children();


  QList<QLabel*> lablst= ui->tab_sub_rcp->findChildren<QLabel *>();
  qDebug()<<"lablst"<<lablst.size();
  foreach (QLabel *item, lablst) {
      item->hide();
  }
  QList<QSpinBox*> splst= ui->tab_sub_rcp->findChildren<QSpinBox *>();
  qDebug()<<"lablst"<<lablst.size();
  foreach (QSpinBox *item, splst) {
      item->hide();
  }
//   foreach (QObject *item, childrens) {
//       if(item->inherits("QLabel"))
//       {
//           QLabel *b = qobject_cast<QLabel*>(item);
//           b->hide();
//       }
//       else if(item->inherits("QSpinBox"))
//       {
//           QSpinBox *s = qobject_cast<QSpinBox*>(item);
//           s->hide();
//       }
//   }
   ui->label_2->show();
   ui->label_6->show();
   ui->label_7->show();
   ui->label_8->show();
   ui->label_9->show();


   ui->label_10->show();
   ui->label_23->show();
   ui->label_49->show();
   ui->spinBox_1->show();
   ui->label_36->show();


   ui->label_13->show();
   ui->label_26->show();
   ui->label_52->show();
   ui->spinBox_4->show();
   ui->label_39->show();

   ui->lbl->show();

}

void FMU_PARAMETER::treeitemclicked(const QModelIndex &index)
{
    m_systemid = 100+index.row();

    QTreeWidgetItem* item=ui->treeWidget->currentItem();
    QString lbname = item->text(index.column());
    QList <QString> al=lbname.split(":");
    if(al.size()>1)
    {
    QList <QString> a2=al[1].split(" ");
    QString name = al[1].mid(al[1].indexOf(" "));
    bool ok;
    int id = a2[0].toInt(&ok,10);
    ui->lbl_id->setText(a2[0]);
    ui->lbl_name->setText(name);
    if(ok)
    {
        ui->lbl_info->setText(getSysParInfo(id));
        m_systemid = id;
        fmu_message msg;
        msg.GetParam(m_systemid);
        qDebug()<<"send message=="<<msg.getMsg().toHex();
        itsBaseWindow->addMessageToQue(msg);
    }else
    {
        ui->lbl_info->setText("NA");
        m_systemid =-1;
    }
    }
    //QMessageBox::information(this,"提示",item->text(index.column()));
}

void FMU_PARAMETER::on_pushButton_clicked()
{
    if(m_systemid==-1)
        return;
    qDebug()<<"on_sp_value_editingFinished";
    fmu_message msg;
    msg.SetParam(m_systemid,ui->sp_value->value());
    qDebug()<<"send message=="<<msg.getMsg().toHex();
    itsBaseWindow->addMessageToQue(msg);
}

void FMU_PARAMETER::on_tab_parameter_currentChanged(int index)
{
    if(index == 1)
    {
        m_recipeid = ui->cb_recipe->itemData(ui->cb_recipe->currentIndex()).toInt();
        getrecipeinfo(m_recipeid);
    }
}

void FMU_PARAMETER::on_cb_recipe_activated(int index)
{
    m_recipeid = ui->cb_recipe->itemData(index).toInt();
    getrecipeinfo(m_recipeid);
    emit rcpidchange(m_recipeid);
}

void FMU_PARAMETER::on_btn_load_clicked()
{
    itsBaseWindow->setwincheck(true);
    QMessageBox::StandardButton reply = QMessageBox::question(this, QObject::tr("Load default Setting(recipes and system parameters)"), QObject::tr("Recipes and System parameters will be set to default, are you sure?"),QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
    itsBaseWindow->setOt(30000);
    fmu_message msg;
    msg.LoadDefault();
    itsBaseWindow->addMessageToQue(msg);
    ui->btn_load->setEnabled(false);
    if (myTimer!=0)
        myTimer->singleShot(30000,this,SLOT(enablebtn()));
        }

}

void FMU_PARAMETER::enablebtn()
{
    ui->btn_load->setEnabled(true);
    itsBaseWindow->setwincheck(false);
     itsBaseWindow->setOt(5000);
     ui->lbl_id->setText("");
     ui->lbl_name->setText("");
     for(int i=100;i<107;i++)
     {
         fmu_message msg;
         msg.GetParam(i);
         qDebug()<<"send message=="<<msg.getMsg().toHex();
         itsBaseWindow->addMessageToQue(msg);
     }
     for(int i=110;i<122;i++)
     {
         fmu_message msg;
         msg.GetParam(i);
         qDebug()<<"send message=="<<msg.getMsg().toHex();
         itsBaseWindow->addMessageToQue(msg);
     }
}

void FMU_PARAMETER::on_menuBack_triggered()
{
    this->close();
}
