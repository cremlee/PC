/****************************************************************************
** Meta object code from reading C++ file 'wbsd_run.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../wbsd_run.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wbsd_run.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_wbsd_run_t {
    QByteArrayData data[14];
    char stringdata[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_wbsd_run_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_wbsd_run_t qt_meta_stringdata_wbsd_run = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 16),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 12),
QT_MOC_LITERAL(4, 40, 4),
QT_MOC_LITERAL(5, 45, 13),
QT_MOC_LITERAL(6, 59, 22),
QT_MOC_LITERAL(7, 82, 13),
QT_MOC_LITERAL(8, 96, 10),
QT_MOC_LITERAL(9, 107, 7),
QT_MOC_LITERAL(10, 115, 4),
QT_MOC_LITERAL(11, 120, 23),
QT_MOC_LITERAL(12, 144, 7),
QT_MOC_LITERAL(13, 152, 4)
    },
    "wbsd_run\0deviceDiscovered\0\0QextPortInfo\0"
    "info\0deviceRemoved\0updateConnectionStatus\0"
    "StringMessage\0gotMessage\0Message\0aMsg\0"
    "connectionStatusChanged\0aStatus\0aMSG\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_wbsd_run[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08,
       5,    1,   42,    2, 0x08,
       6,    2,   45,    2, 0x08,
       8,    1,   50,    2, 0x0a,
      11,    2,   53,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 7,    2,    2,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 7,   12,   13,

       0        // eod
};

void wbsd_run::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        wbsd_run *_t = static_cast<wbsd_run *>(_o);
        switch (_id) {
        case 0: _t->deviceDiscovered((*reinterpret_cast< const QextPortInfo(*)>(_a[1]))); break;
        case 1: _t->deviceRemoved((*reinterpret_cast< const QextPortInfo(*)>(_a[1]))); break;
        case 2: _t->updateConnectionStatus((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< StringMessage(*)>(_a[2]))); break;
        case 3: _t->gotMessage((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 4: _t->connectionStatusChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< StringMessage(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QextPortInfo >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QextPortInfo >(); break;
            }
            break;
        }
    }
}

const QMetaObject wbsd_run::staticMetaObject = {
    { &WBSDChildWindow::staticMetaObject, qt_meta_stringdata_wbsd_run.data,
      qt_meta_data_wbsd_run,  qt_static_metacall, 0, 0}
};


const QMetaObject *wbsd_run::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *wbsd_run::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_wbsd_run.stringdata))
        return static_cast<void*>(const_cast< wbsd_run*>(this));
    return WBSDChildWindow::qt_metacast(_clname);
}

int wbsd_run::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WBSDChildWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
