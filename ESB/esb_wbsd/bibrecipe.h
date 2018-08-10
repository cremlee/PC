#ifndef BIBRECIPE_H
#define BIBRECIPE_H

#include <QGroupBox>

namespace Ui {
class BIBRecipe;
}

class BIBRecipe : public QGroupBox
{
    Q_OBJECT
    
public:
    explicit BIBRecipe(QWidget *parent = 0);
    ~BIBRecipe();
    
private:
    Ui::BIBRecipe *ui;
};

#endif // BIBRECIPE_H
