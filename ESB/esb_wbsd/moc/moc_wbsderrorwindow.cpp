/****************************************************************************
** Meta object code from reading C++ file 'wbsderrorwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../wbsderrorwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wbsderrorwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WBSDErrorWindow_t {
    QByteArrayData data[22];
    char stringdata[329];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_WBSDErrorWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_WBSDErrorWindow_t qt_meta_stringdata_WBSDErrorWindow = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 28),
QT_MOC_LITERAL(2, 45, 0),
QT_MOC_LITERAL(3, 46, 18),
QT_MOC_LITERAL(4, 65, 3),
QT_MOC_LITERAL(5, 69, 17),
QT_MOC_LITERAL(6, 87, 19),
QT_MOC_LITERAL(7, 107, 18),
QT_MOC_LITERAL(8, 126, 26),
QT_MOC_LITERAL(9, 153, 24),
QT_MOC_LITERAL(10, 178, 10),
QT_MOC_LITERAL(11, 189, 7),
QT_MOC_LITERAL(12, 197, 4),
QT_MOC_LITERAL(13, 202, 16),
QT_MOC_LITERAL(14, 219, 12),
QT_MOC_LITERAL(15, 232, 11),
QT_MOC_LITERAL(16, 244, 23),
QT_MOC_LITERAL(17, 268, 7),
QT_MOC_LITERAL(18, 276, 13),
QT_MOC_LITERAL(19, 290, 4),
QT_MOC_LITERAL(20, 295, 10),
QT_MOC_LITERAL(21, 306, 21)
    },
    "WBSDErrorWindow\0send_loadErrorButton_clicked\0"
    "\0updateActiveErrors\0err\0clearActiveErrors\0"
    "updateHistoryErrors\0clearHistoryErrors\0"
    "on_loadErrorButton_clicked\0"
    "on_btnSaveErrors_clicked\0gotMessage\0"
    "Message\0aMsg\0gotErrorCountMsg\0"
    "ErrorMessage\0gotErrorMsg\0"
    "connectionStatusChanged\0aStatus\0"
    "StringMessage\0aMSG\0updateData\0"
    "on_menuBack_triggered\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WBSDErrorWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    1,   80,    2, 0x0a,
       5,    0,   83,    2, 0x0a,
       6,    1,   84,    2, 0x0a,
       7,    0,   87,    2, 0x0a,
       8,    0,   88,    2, 0x0a,
       9,    0,   89,    2, 0x0a,
      10,    1,   90,    2, 0x0a,
      13,    1,   93,    2, 0x0a,
      15,    1,   96,    2, 0x0a,
      16,    2,   99,    2, 0x0a,
      20,    0,  104,    2, 0x0a,
      21,    0,  105,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 14,   12,
    QMetaType::Void, 0x80000000 | 14,   12,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 18,   17,   19,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WBSDErrorWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WBSDErrorWindow *_t = static_cast<WBSDErrorWindow *>(_o);
        switch (_id) {
        case 0: _t->send_loadErrorButton_clicked(); break;
        case 1: _t->updateActiveErrors((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->clearActiveErrors(); break;
        case 3: _t->updateHistoryErrors((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->clearHistoryErrors(); break;
        case 5: _t->on_loadErrorButton_clicked(); break;
        case 6: _t->on_btnSaveErrors_clicked(); break;
        case 7: _t->gotMessage((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 8: _t->gotErrorCountMsg((*reinterpret_cast< ErrorMessage(*)>(_a[1]))); break;
        case 9: _t->gotErrorMsg((*reinterpret_cast< ErrorMessage(*)>(_a[1]))); break;
        case 10: _t->connectionStatusChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< StringMessage(*)>(_a[2]))); break;
        case 11: _t->updateData(); break;
        case 12: _t->on_menuBack_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WBSDErrorWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WBSDErrorWindow::send_loadErrorButton_clicked)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject WBSDErrorWindow::staticMetaObject = {
    { &WBSDChildWindow::staticMetaObject, qt_meta_stringdata_WBSDErrorWindow.data,
      qt_meta_data_WBSDErrorWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *WBSDErrorWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WBSDErrorWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WBSDErrorWindow.stringdata))
        return static_cast<void*>(const_cast< WBSDErrorWindow*>(this));
    return WBSDChildWindow::qt_metacast(_clname);
}

int WBSDErrorWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WBSDChildWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void WBSDErrorWindow::send_loadErrorButton_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
