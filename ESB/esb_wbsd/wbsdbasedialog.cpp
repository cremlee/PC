#include <QObject>
#include "wbsdbasedialog.h"
#include "wbsd_serial_port.h"
#include "qdebug.h"
#include "stringmessage.h"

WBSDBaseDialog::WBSDBaseDialog(WBSDBaseWindow *parent)
    : QMainWindow(parent)
{
    itsBaseWindow=parent;
    parent->connectToMessages(this);
}

WBSDBaseDialog::~WBSDBaseDialog()
{
    itsBaseWindow->disconnectToMessages(this);
    this->deleteLater();
}
