/****************************************************************************
** Meta object code from reading C++ file 'wbsdpumpwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../wbsdpumpwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wbsdpumpwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WBSDPumpWindow_t {
    QByteArrayData data[19];
    char stringdata[280];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_WBSDPumpWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_WBSDPumpWindow_t qt_meta_stringdata_WBSDPumpWindow = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 6),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 10),
QT_MOC_LITERAL(4, 34, 7),
QT_MOC_LITERAL(5, 42, 4),
QT_MOC_LITERAL(6, 47, 23),
QT_MOC_LITERAL(7, 71, 7),
QT_MOC_LITERAL(8, 79, 13),
QT_MOC_LITERAL(9, 93, 4),
QT_MOC_LITERAL(10, 98, 10),
QT_MOC_LITERAL(11, 109, 20),
QT_MOC_LITERAL(12, 130, 21),
QT_MOC_LITERAL(13, 152, 19),
QT_MOC_LITERAL(14, 172, 20),
QT_MOC_LITERAL(15, 193, 19),
QT_MOC_LITERAL(16, 213, 20),
QT_MOC_LITERAL(17, 234, 21),
QT_MOC_LITERAL(18, 256, 22)
    },
    "WBSDPumpWindow\0iclose\0\0gotMessage\0"
    "Message\0aMsg\0connectionStatusChanged\0"
    "aStatus\0StringMessage\0aMSG\0updateData\0"
    "on_waterPump_pressed\0on_waterPump_released\0"
    "on_rbibPump_pressed\0on_rbibPump_released\0"
    "on_lbibPump_pressed\0on_lbibPump_released\0"
    "on_menuBack_triggered\0on_btn_setpump_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WBSDPumpWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    1,   75,    2, 0x0a,
       6,    2,   78,    2, 0x0a,
      10,    0,   83,    2, 0x0a,
      11,    0,   84,    2, 0x08,
      12,    0,   85,    2, 0x08,
      13,    0,   86,    2, 0x08,
      14,    0,   87,    2, 0x08,
      15,    0,   88,    2, 0x08,
      16,    0,   89,    2, 0x08,
      17,    0,   90,    2, 0x08,
      18,    0,   91,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 8,    7,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WBSDPumpWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WBSDPumpWindow *_t = static_cast<WBSDPumpWindow *>(_o);
        switch (_id) {
        case 0: _t->iclose(); break;
        case 1: _t->gotMessage((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 2: _t->connectionStatusChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< StringMessage(*)>(_a[2]))); break;
        case 3: _t->updateData(); break;
        case 4: _t->on_waterPump_pressed(); break;
        case 5: _t->on_waterPump_released(); break;
        case 6: _t->on_rbibPump_pressed(); break;
        case 7: _t->on_rbibPump_released(); break;
        case 8: _t->on_lbibPump_pressed(); break;
        case 9: _t->on_lbibPump_released(); break;
        case 10: _t->on_menuBack_triggered(); break;
        case 11: _t->on_btn_setpump_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WBSDPumpWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WBSDPumpWindow::iclose)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject WBSDPumpWindow::staticMetaObject = {
    { &WBSDChildWindow::staticMetaObject, qt_meta_stringdata_WBSDPumpWindow.data,
      qt_meta_data_WBSDPumpWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *WBSDPumpWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WBSDPumpWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WBSDPumpWindow.stringdata))
        return static_cast<void*>(const_cast< WBSDPumpWindow*>(this));
    return WBSDChildWindow::qt_metacast(_clname);
}

int WBSDPumpWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WBSDChildWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void WBSDPumpWindow::iclose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
