#ifndef FMU_PARAMETER_H
#define FMU_PARAMETER_H

#include <QMainWindow>
#include<QHash>
#include"wbsdchildwindow.h"
namespace Ui {
class FMU_PARAMETER;
}

class FMU_PARAMETER : public WBSDChildWindow
{
    Q_OBJECT

public:
    explicit FMU_PARAMETER(WBSDBaseWindow *parent = 0,int fromrcp=-1);
    ~FMU_PARAMETER();
    void closeEvent(QCloseEvent* evt);
public slots:
    void getrecipeinfo(int id);
    void updateData();
    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);
//    recipe part
    void on_cb_recipe_actived();
    void on_spinBox_1_editingFinished();
    void on_spinBox_2_editingFinished();
    void on_spinBox_3_editingFinished();
    void on_spinBox_4_editingFinished();
    void on_spinBox_5_editingFinished();
    void on_spinBox_6_editingFinished();
    void on_spinBox_7_editingFinished();
    void on_spinBox_8_editingFinished();
    void on_spinBox_9_editingFinished();
    void on_spinBox_10_editingFinished();
    void on_spinBox_11_editingFinished();
    void on_spinBox_12_editingFinished();
    void on_spinBox_13_editingFinished();
    void SetRecipeInfo(char index ,int value);
    void updaterecipeinfo(int index,int value);
    void updatesysteminfo(int index,int value);
//    system part
    void on_sp_value_editingFinished();
    QString getSysParInfo(int index);
    void initmap();

    void HideRcpPart();
signals:
    void iclose();
    void rcpidchange(int i);
private slots:
    void treeitemclicked ( const QModelIndex & index );
    void on_pushButton_clicked();

    void on_tab_parameter_currentChanged(int index);

    void on_cb_recipe_activated(int index);

    void on_btn_load_clicked();
    void enablebtn();
void on_menuBack_triggered();
private:
    Ui::FMU_PARAMETER *ui;
    quint8 m_recipeid;
    int m_systemid;
    QAction *menuBack;
    QHash<int, QString> parainfo;
};

#endif // FMU_PARAMETER_H
