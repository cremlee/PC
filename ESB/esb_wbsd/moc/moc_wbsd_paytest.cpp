/****************************************************************************
** Meta object code from reading C++ file 'wbsd_paytest.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../wbsd_paytest.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wbsd_paytest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WBSDpaytest_t {
    QByteArrayData data[14];
    char stringdata[157];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_WBSDpaytest_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_WBSDpaytest_t qt_meta_stringdata_WBSDpaytest = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 6),
QT_MOC_LITERAL(2, 19, 0),
QT_MOC_LITERAL(3, 20, 10),
QT_MOC_LITERAL(4, 31, 7),
QT_MOC_LITERAL(5, 39, 4),
QT_MOC_LITERAL(6, 44, 23),
QT_MOC_LITERAL(7, 68, 7),
QT_MOC_LITERAL(8, 76, 13),
QT_MOC_LITERAL(9, 90, 4),
QT_MOC_LITERAL(10, 95, 19),
QT_MOC_LITERAL(11, 115, 16),
QT_MOC_LITERAL(12, 132, 1),
QT_MOC_LITERAL(13, 134, 21)
    },
    "WBSDpaytest\0iclose\0\0gotMessage\0Message\0"
    "aMsg\0connectionStatusChanged\0aStatus\0"
    "StringMessage\0aMSG\0on_btn_test_clicked\0"
    "updatetestresult\0a\0on_menuBack_triggered\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WBSDpaytest[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    1,   45,    2, 0x0a,
       6,    2,   48,    2, 0x0a,
      10,    0,   53,    2, 0x0a,
      11,    1,   54,    2, 0x0a,
      13,    0,   57,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 8,    7,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,

       0        // eod
};

void WBSDpaytest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WBSDpaytest *_t = static_cast<WBSDpaytest *>(_o);
        switch (_id) {
        case 0: _t->iclose(); break;
        case 1: _t->gotMessage((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 2: _t->connectionStatusChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< StringMessage(*)>(_a[2]))); break;
        case 3: _t->on_btn_test_clicked(); break;
        case 4: _t->updatetestresult((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->on_menuBack_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WBSDpaytest::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WBSDpaytest::iclose)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject WBSDpaytest::staticMetaObject = {
    { &WBSDChildWindow::staticMetaObject, qt_meta_stringdata_WBSDpaytest.data,
      qt_meta_data_WBSDpaytest,  qt_static_metacall, 0, 0}
};


const QMetaObject *WBSDpaytest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WBSDpaytest::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WBSDpaytest.stringdata))
        return static_cast<void*>(const_cast< WBSDpaytest*>(this));
    return WBSDChildWindow::qt_metacast(_clname);
}

int WBSDpaytest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WBSDChildWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void WBSDpaytest::iclose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
