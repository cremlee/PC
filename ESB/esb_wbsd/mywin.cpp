#include "mywin.h"
#include <QPainter>
#include<QPen>
#include<QDebug>
mywin::mywin(QWidget *parent) :
    QWidget(parent)
{
    //MyHeight = (height()-50)/7*7;
    //MyWidth = width()-130)/1440*1440;
    //_ecolist = new QList<EcoInfo_T>();
}

void mywin::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    //paint the zuobiao
    QPen pen;  // creates a default pen

    pen.setStyle(Qt::SolidLine);
    pen.setWidth(2);

    pen.setBrush(Qt::black);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    paint.setPen(pen);

    paint.drawLine(80,0,80,height()-50);
    paint.drawLine(80,height()-50,width()-150,height()-50);

    pen.setWidth(1);
    pen.setBrush(Qt::blue);
    paint.setPen(pen);
    qreal tmp = (qreal)(width()-150-80)/7;
    paint.drawText(80+10,height()-20,"Sunday");
    paint.drawLine(80+tmp*(0),height()-55,80+tmp*(0),height()-50);
    paint.drawText(80+tmp+10,height()-20,"Monday");
    paint.drawLine(80+tmp*(1),height()-45,80+tmp*(1),height()-50);
    paint.drawText(80+tmp*2+10,height()-20,"Tuesday");
    paint.drawLine(80+tmp*(2),height()-45,80+tmp*(2),height()-50);
    paint.drawText(80+tmp*3+5,height()-20,"Wednesday");
    paint.drawLine(80+tmp*(3),height()-45,80+tmp*(3),height()-50);
    paint.drawText(80+tmp*4+10,height()-20,"Thursday");
    paint.drawLine(80+tmp*(4),height()-45,80+tmp*(4),height()-50);
    paint.drawText(80+tmp*5+15,height()-20,"Friday");
    paint.drawLine(80+tmp*(5),height()-45,80+tmp*(5),height()-50);
    paint.drawText(80+tmp*6+10,height()-20,"Saturday");
    paint.drawLine(80+tmp*(6),height()-45,80+tmp*(6),height()-50);
    paint.drawLine(80+tmp*(7),height()-45,80+tmp*(7),height()-50);
    pen.setWidth(1);
    pen.setBrush(Qt::black);
    paint.setPen(pen);
    tmp = (height()-50)/6;
    for(int i=0;i<6;i++)
    {
        paint.drawLine(75,tmp*i,80,tmp*i);
        paint.drawText(50,tmp*(i)+8,QString("%1").arg((6-i)*4));
    }
   paint.fillRect(width()-100,0,30,20,Qt::green);
   paint.drawText(width()-65,13,"Work Time");
   paint.fillRect(width()-100,40,30,20,Qt::red);
   paint.drawText(width()-65,53,"ECO  Time");

    foreach (EcoInfo_T a, _ecolist) {
       Drawmyview(a,&paint);
    }
    paint.end();
}

void mywin::setPaintlist(QList<EcoInfo_T> ecolist)
{
    _ecolist.clear();
    foreach (EcoInfo_T a, ecolist) {
       _ecolist.append(a);
    }
    update();
}



void mywin::Drawmyview(EcoInfo_T mydemo, QPainter *pat)
{
    QPen pen;  // creates a default pen
    pen.setStyle(Qt::SolidLine);
    pen.setBrush(Qt::black);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    pat->setPen(pen);
    int tmp = (height()-50)/7;
    qreal tmp1 = (width()-80-150)/7;
    mydemo.height=(height()-50)*(mydemo.stop-mydemo.start)/(60*24);
    mydemo.width = 20; //(width()-150-80)*(mydemo.stop-mydemo.start)/(60*24);
    mydemo.X =80+((tmp1-20)/2)+mydemo.index*(tmp1);
    mydemo.Y = 0;
    pat->fillRect(mydemo.X,mydemo.Y,mydemo.width,height()-50-2,Qt::red);
    pat->fillRect(mydemo.X,(height()-50)*(60*24-mydemo.stop)/(60*24),mydemo.width,mydemo.height,Qt::green);
}


