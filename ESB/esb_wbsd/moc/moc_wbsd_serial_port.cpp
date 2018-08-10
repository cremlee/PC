/****************************************************************************
** Meta object code from reading C++ file 'wbsd_serial_port.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../wbsd_serial_port.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wbsd_serial_port.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_wbsd_SERIAL_PORT_t {
    QByteArrayData data[16];
    char stringdata[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_wbsd_SERIAL_PORT_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_wbsd_SERIAL_PORT_t qt_meta_stringdata_wbsd_SERIAL_PORT = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 10),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 7),
QT_MOC_LITERAL(4, 37, 3),
QT_MOC_LITERAL(5, 41, 3),
QT_MOC_LITERAL(6, 45, 23),
QT_MOC_LITERAL(7, 69, 7),
QT_MOC_LITERAL(8, 77, 13),
QT_MOC_LITERAL(9, 91, 4),
QT_MOC_LITERAL(10, 96, 8),
QT_MOC_LITERAL(11, 105, 4),
QT_MOC_LITERAL(12, 110, 15),
QT_MOC_LITERAL(13, 126, 11),
QT_MOC_LITERAL(14, 138, 16),
QT_MOC_LITERAL(15, 155, 6)
    },
    "wbsd_SERIAL_PORT\0gotMessage\0\0Message\0"
    "msg\0log\0connectionStatusChanged\0aStatus\0"
    "StringMessage\0aMSG\0sendNext\0send\0"
    "onDataAvailable\0pingTimeout\0"
    "pingTimeoutError\0resend\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_wbsd_SERIAL_PORT[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06,
       5,    1,   62,    2, 0x06,
       6,    2,   65,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      10,    0,   70,    2, 0x0a,
      11,    1,   71,    2, 0x0a,
      12,    0,   74,    2, 0x0a,
      13,    0,   75,    2, 0x0a,
      14,    0,   76,    2, 0x0a,
      15,    0,   77,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 8,    7,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void wbsd_SERIAL_PORT::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        wbsd_SERIAL_PORT *_t = static_cast<wbsd_SERIAL_PORT *>(_o);
        switch (_id) {
        case 0: _t->gotMessage((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 1: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->connectionStatusChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< StringMessage(*)>(_a[2]))); break;
        case 3: _t->sendNext(); break;
        case 4: _t->send((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 5: _t->onDataAvailable(); break;
        case 6: _t->pingTimeout(); break;
        case 7: _t->pingTimeoutError(); break;
        case 8: _t->resend(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (wbsd_SERIAL_PORT::*_t)(Message );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&wbsd_SERIAL_PORT::gotMessage)) {
                *result = 0;
            }
        }
        {
            typedef void (wbsd_SERIAL_PORT::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&wbsd_SERIAL_PORT::log)) {
                *result = 1;
            }
        }
        {
            typedef void (wbsd_SERIAL_PORT::*_t)(int , StringMessage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&wbsd_SERIAL_PORT::connectionStatusChanged)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject wbsd_SERIAL_PORT::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_wbsd_SERIAL_PORT.data,
      qt_meta_data_wbsd_SERIAL_PORT,  qt_static_metacall, 0, 0}
};


const QMetaObject *wbsd_SERIAL_PORT::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *wbsd_SERIAL_PORT::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_wbsd_SERIAL_PORT.stringdata))
        return static_cast<void*>(const_cast< wbsd_SERIAL_PORT*>(this));
    return QObject::qt_metacast(_clname);
}

int wbsd_SERIAL_PORT::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void wbsd_SERIAL_PORT::gotMessage(Message _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void wbsd_SERIAL_PORT::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void wbsd_SERIAL_PORT::connectionStatusChanged(int _t1, StringMessage _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
