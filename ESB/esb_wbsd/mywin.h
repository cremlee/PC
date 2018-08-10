#ifndef MYWIN_H
#define MYWIN_H

#include <QWidget>
#include<QList>
struct EcoInfo_T
{
    int index;
    qreal X;
    qreal Y;
    qreal width;
    qreal height;
    int start;
    int stop;

};

class mywin : public QWidget
{
    Q_OBJECT
public:
    explicit mywin(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void setPaintlist( QList<EcoInfo_T> ecolist);
    void Drawmyview(EcoInfo_T mydemo,QPainter* pat);
signals:

public slots:
private:
    int count;
    int MyHeight;
    int MyWidth;
    QList<EcoInfo_T> _ecolist;

};

#endif // MYWIN_H
