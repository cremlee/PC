#include "wbsdwidget.h"

WBSDWidget::WBSDWidget(WBSDBaseWindow *baseWindow,QWidget *parent)
	: QWidget(parent)
{
	itsBaseWindow=baseWindow;
}

WBSDWidget::~WBSDWidget()
{

}
