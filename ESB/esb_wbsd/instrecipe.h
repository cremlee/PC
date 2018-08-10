#ifndef INSTRECIPE_H
#define INSTRECIPE_H

#include <QGroupBox>

namespace Ui {
class InstRecipe;
}

class InstRecipe : public QGroupBox
{
    Q_OBJECT
    
public:
    explicit InstRecipe(QWidget *parent = 0);
    ~InstRecipe();
    
private:
    Ui::InstRecipe *ui;
};

#endif // INSTRECIPE_H
