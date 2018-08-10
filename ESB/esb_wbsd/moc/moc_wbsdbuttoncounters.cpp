/****************************************************************************
** Meta object code from reading C++ file 'wbsdbuttoncounters.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../wbsdbuttoncounters.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wbsdbuttoncounters.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WBSDButtonCounters_t {
    QByteArrayData data[14];
    char stringdata[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_WBSDButtonCounters_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_WBSDButtonCounters_t qt_meta_stringdata_WBSDButtonCounters = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 6),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 9),
QT_MOC_LITERAL(4, 37, 10),
QT_MOC_LITERAL(5, 48, 7),
QT_MOC_LITERAL(6, 56, 4),
QT_MOC_LITERAL(7, 61, 23),
QT_MOC_LITERAL(8, 85, 7),
QT_MOC_LITERAL(9, 93, 13),
QT_MOC_LITERAL(10, 107, 4),
QT_MOC_LITERAL(11, 112, 10),
QT_MOC_LITERAL(12, 123, 12),
QT_MOC_LITERAL(13, 136, 21)
    },
    "WBSDButtonCounters\0iclose\0\0destroyed\0"
    "gotMessage\0Message\0aMsg\0connectionStatusChanged\0"
    "aStatus\0StringMessage\0aMSG\0closeEvent\0"
    "QCloseEvent*\0on_menuBack_triggered\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WBSDButtonCounters[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06,
       3,    1,   45,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    1,   48,    2, 0x0a,
       7,    2,   51,    2, 0x0a,
      11,    1,   56,    2, 0x0a,
      13,    0,   59,    2, 0x08,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 9,    8,   10,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void,

       0        // eod
};

void WBSDButtonCounters::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WBSDButtonCounters *_t = static_cast<WBSDButtonCounters *>(_o);
        switch (_id) {
        case 0: _t->iclose(); break;
        case 1: _t->destroyed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->gotMessage((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 3: _t->connectionStatusChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< StringMessage(*)>(_a[2]))); break;
        case 4: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 5: _t->on_menuBack_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WBSDButtonCounters::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WBSDButtonCounters::iclose)) {
                *result = 0;
            }
        }
        {
            typedef void (WBSDButtonCounters::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WBSDButtonCounters::destroyed)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject WBSDButtonCounters::staticMetaObject = {
    { &WBSDChildWindow::staticMetaObject, qt_meta_stringdata_WBSDButtonCounters.data,
      qt_meta_data_WBSDButtonCounters,  qt_static_metacall, 0, 0}
};


const QMetaObject *WBSDButtonCounters::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WBSDButtonCounters::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WBSDButtonCounters.stringdata))
        return static_cast<void*>(const_cast< WBSDButtonCounters*>(this));
    return WBSDChildWindow::qt_metacast(_clname);
}

int WBSDButtonCounters::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void WBSDButtonCounters::iclose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void WBSDButtonCounters::destroyed(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
