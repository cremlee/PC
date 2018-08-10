/****************************************************************************
** Meta object code from reading C++ file 'wbsdcounterswindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../wbsdcounterswindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wbsdcounterswindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WBSDCountersWindow_t {
    QByteArrayData data[23];
    char stringdata[351];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_WBSDCountersWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_WBSDCountersWindow_t qt_meta_stringdata_WBSDCountersWindow = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 19),
QT_MOC_LITERAL(2, 39, 0),
QT_MOC_LITERAL(3, 40, 21),
QT_MOC_LITERAL(4, 62, 22),
QT_MOC_LITERAL(5, 85, 24),
QT_MOC_LITERAL(6, 110, 10),
QT_MOC_LITERAL(7, 121, 1),
QT_MOC_LITERAL(8, 123, 18),
QT_MOC_LITERAL(9, 142, 18),
QT_MOC_LITERAL(10, 161, 18),
QT_MOC_LITERAL(11, 180, 18),
QT_MOC_LITERAL(12, 199, 18),
QT_MOC_LITERAL(13, 218, 18),
QT_MOC_LITERAL(14, 237, 18),
QT_MOC_LITERAL(15, 256, 18),
QT_MOC_LITERAL(16, 275, 10),
QT_MOC_LITERAL(17, 286, 7),
QT_MOC_LITERAL(18, 294, 4),
QT_MOC_LITERAL(19, 299, 23),
QT_MOC_LITERAL(20, 323, 7),
QT_MOC_LITERAL(21, 331, 13),
QT_MOC_LITERAL(22, 345, 4)
    },
    "WBSDCountersWindow\0set_CountersButton1\0"
    "\0on_menuBack_triggered\0on_buttonTotal_clicked\0"
    "on_ResetCounters_clicked\0destroywin\0"
    "i\0on_button1_clicked\0on_button2_clicked\0"
    "on_button3_clicked\0on_button4_clicked\0"
    "on_button5_clicked\0on_button6_clicked\0"
    "on_button7_clicked\0on_button8_clicked\0"
    "gotMessage\0Message\0aMsg\0connectionStatusChanged\0"
    "aStatus\0StringMessage\0aMSG\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WBSDCountersWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    0,   90,    2, 0x08,
       4,    0,   91,    2, 0x08,
       5,    0,   92,    2, 0x08,
       6,    1,   93,    2, 0x08,
       8,    0,   96,    2, 0x0a,
       9,    0,   97,    2, 0x0a,
      10,    0,   98,    2, 0x0a,
      11,    0,   99,    2, 0x0a,
      12,    0,  100,    2, 0x0a,
      13,    0,  101,    2, 0x0a,
      14,    0,  102,    2, 0x0a,
      15,    0,  103,    2, 0x0a,
      16,    1,  104,    2, 0x0a,
      19,    2,  107,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 21,   20,   22,

       0        // eod
};

void WBSDCountersWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WBSDCountersWindow *_t = static_cast<WBSDCountersWindow *>(_o);
        switch (_id) {
        case 0: _t->set_CountersButton1(); break;
        case 1: _t->on_menuBack_triggered(); break;
        case 2: _t->on_buttonTotal_clicked(); break;
        case 3: _t->on_ResetCounters_clicked(); break;
        case 4: _t->destroywin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_button1_clicked(); break;
        case 6: _t->on_button2_clicked(); break;
        case 7: _t->on_button3_clicked(); break;
        case 8: _t->on_button4_clicked(); break;
        case 9: _t->on_button5_clicked(); break;
        case 10: _t->on_button6_clicked(); break;
        case 11: _t->on_button7_clicked(); break;
        case 12: _t->on_button8_clicked(); break;
        case 13: _t->gotMessage((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 14: _t->connectionStatusChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< StringMessage(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WBSDCountersWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WBSDCountersWindow::set_CountersButton1)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject WBSDCountersWindow::staticMetaObject = {
    { &WBSDChildWindow::staticMetaObject, qt_meta_stringdata_WBSDCountersWindow.data,
      qt_meta_data_WBSDCountersWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *WBSDCountersWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WBSDCountersWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WBSDCountersWindow.stringdata))
        return static_cast<void*>(const_cast< WBSDCountersWindow*>(this));
    return WBSDChildWindow::qt_metacast(_clname);
}

int WBSDCountersWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WBSDChildWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void WBSDCountersWindow::set_CountersButton1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
