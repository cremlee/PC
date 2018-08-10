/****************************************************************************
** Meta object code from reading C++ file 'wbsdcounterstotal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../wbsdcounterstotal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wbsdcounterstotal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WBSDCountersTotal_t {
    QByteArrayData data[11];
    char stringdata[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_WBSDCountersTotal_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_WBSDCountersTotal_t qt_meta_stringdata_WBSDCountersTotal = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 6),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 21),
QT_MOC_LITERAL(4, 48, 10),
QT_MOC_LITERAL(5, 59, 7),
QT_MOC_LITERAL(6, 67, 4),
QT_MOC_LITERAL(7, 72, 23),
QT_MOC_LITERAL(8, 96, 7),
QT_MOC_LITERAL(9, 104, 13),
QT_MOC_LITERAL(10, 118, 4)
    },
    "WBSDCountersTotal\0iclose\0\0"
    "on_menuBack_triggered\0gotMessage\0"
    "Message\0aMsg\0connectionStatusChanged\0"
    "aStatus\0StringMessage\0aMSG\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WBSDCountersTotal[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    0,   35,    2, 0x08,
       4,    1,   36,    2, 0x0a,
       7,    2,   39,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 9,    8,   10,

       0        // eod
};

void WBSDCountersTotal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WBSDCountersTotal *_t = static_cast<WBSDCountersTotal *>(_o);
        switch (_id) {
        case 0: _t->iclose(); break;
        case 1: _t->on_menuBack_triggered(); break;
        case 2: _t->gotMessage((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 3: _t->connectionStatusChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< StringMessage(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WBSDCountersTotal::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WBSDCountersTotal::iclose)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject WBSDCountersTotal::staticMetaObject = {
    { &WBSDChildWindow::staticMetaObject, qt_meta_stringdata_WBSDCountersTotal.data,
      qt_meta_data_WBSDCountersTotal,  qt_static_metacall, 0, 0}
};


const QMetaObject *WBSDCountersTotal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WBSDCountersTotal::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WBSDCountersTotal.stringdata))
        return static_cast<void*>(const_cast< WBSDCountersTotal*>(this));
    return WBSDChildWindow::qt_metacast(_clname);
}

int WBSDCountersTotal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WBSDChildWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void WBSDCountersTotal::iclose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
