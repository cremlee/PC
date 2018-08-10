#ifndef GENERALRECIPE_H
#define GENERALRECIPE_H

#include <QGroupBox>

namespace Ui {
class GeneralRecipe;
}

class GeneralRecipe : public QGroupBox
{
    Q_OBJECT
    
public:
    explicit GeneralRecipe(QWidget *parent = 0);
    ~GeneralRecipe();
    
private:
    Ui::GeneralRecipe *ui;
};

#endif // GENERALRECIPE_H
