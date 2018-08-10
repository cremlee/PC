#ifndef WBSDERRORWINDOW_H
#define WBSDERRORWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QStandardItemModel>
#include "wbsdchildwindow.h"
#include "errormessage.h"

namespace Ui {
class WBSDErrorWindow;
}

class WBSDErrorWindow : public WBSDChildWindow
{
    Q_OBJECT
    
public:
    explicit WBSDErrorWindow(WBSDBaseWindow *parent = 0);
    ~WBSDErrorWindow();
    //QListWidget *listErrors;
    //QListWidget *listErrHistory;

public slots:
    void updateActiveErrors(QString err);
    void clearActiveErrors();
    void updateHistoryErrors(QString err);
    void clearHistoryErrors();
    void on_loadErrorButton_clicked();
	void on_btnSaveErrors_clicked();
	void gotMessage(Message aMsg);
	void gotErrorCountMsg(ErrorMessage aMsg);
	void gotErrorMsg(ErrorMessage aMsg);
	void connectionStatusChanged(int aStatus,StringMessage aMSG);
	void updateData();

private slots:
    void on_menuBack_triggered();

signals:
    void send_loadErrorButton_clicked();
    
private:
    Ui::WBSDErrorWindow *ui;
    QAction *menuBack;
    int err_act;
    int err_total;
    short err_query_type;
    short err_query_number;
    QList <ErrorMessage> err_messages_act;
    QList <ErrorMessage> err_messages_hist;

};

#endif // WBSDERRORWINDOW_H
