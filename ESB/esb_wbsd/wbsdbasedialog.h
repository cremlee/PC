#ifndef WBSDBASEDIALOG_H
#define WBSDBASEDIALOG_H

#include <QDialog>
#include "message.h"
#include "stringmessage.h"
#include "ui_mainwindow.h"
#include "wbsdbasewindow.h"

class WBSDBaseDialog : public QDialog
{
    Q_OBJECT

public:
    WBSDBaseDialog (WBSDBaseWindow *parent);
    ~WBSDChildWindow();

public slots:
    virtual void gotMessage(Message aMsg)=0;
    virtual void connectionStatusChanged(int aStatus,StringMessage aMSG)=0;

protected:
    WBSDBaseWindow *itsBaseWindow;
    QTimer *myTimer;
};

#endif // WBSDBASEDIALOG_H
