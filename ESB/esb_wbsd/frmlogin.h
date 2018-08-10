#ifndef FRMLOGIN_H
#define FRMLOGIN_H

#include <QDialog>
#include<databasehelper.h>
namespace Ui {
class frmLogin;
}

class frmLogin : public QDialog
{
    Q_OBJECT

public:
    explicit frmLogin(QWidget *parent = 0);
    ~frmLogin();


private slots:
    void on_btnLogin_clicked(); //用户按下登录按钮
    void on_btnClose_clicked(); //关闭界面

private:
    Ui::frmLogin *ui;
    void InitForm();            //初始化界面
};

#endif // FRMLOGIN_H
