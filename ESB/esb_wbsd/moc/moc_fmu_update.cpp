/****************************************************************************
** Meta object code from reading C++ file 'fmu_update.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../fmu_update.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fmu_update.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FMU_UPDATE_t {
    QByteArrayData data[13];
    char stringdata[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_FMU_UPDATE_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_FMU_UPDATE_t qt_meta_stringdata_FMU_UPDATE = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 6),
QT_MOC_LITERAL(2, 18, 0),
QT_MOC_LITERAL(3, 19, 10),
QT_MOC_LITERAL(4, 30, 7),
QT_MOC_LITERAL(5, 38, 4),
QT_MOC_LITERAL(6, 43, 23),
QT_MOC_LITERAL(7, 67, 7),
QT_MOC_LITERAL(8, 75, 13),
QT_MOC_LITERAL(9, 89, 4),
QT_MOC_LITERAL(10, 94, 23),
QT_MOC_LITERAL(11, 118, 17),
QT_MOC_LITERAL(12, 136, 10)
    },
    "FMU_UPDATE\0iclose\0\0gotMessage\0Message\0"
    "aMsg\0connectionStatusChanged\0aStatus\0"
    "StringMessage\0aMSG\0on_btn_openfile_clicked\0"
    "on_btn_ok_clicked\0getversion\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FMU_UPDATE[] = {

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
      10,    0,   53,    2, 0x08,
      11,    0,   54,    2, 0x08,
      12,    0,   55,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 8,    7,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FMU_UPDATE::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FMU_UPDATE *_t = static_cast<FMU_UPDATE *>(_o);
        switch (_id) {
        case 0: _t->iclose(); break;
        case 1: _t->gotMessage((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 2: _t->connectionStatusChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< StringMessage(*)>(_a[2]))); break;
        case 3: _t->on_btn_openfile_clicked(); break;
        case 4: _t->on_btn_ok_clicked(); break;
        case 5: _t->getversion(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FMU_UPDATE::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FMU_UPDATE::iclose)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject FMU_UPDATE::staticMetaObject = {
    { &WBSDChildWindow::staticMetaObject, qt_meta_stringdata_FMU_UPDATE.data,
      qt_meta_data_FMU_UPDATE,  qt_static_metacall, 0, 0}
};


const QMetaObject *FMU_UPDATE::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FMU_UPDATE::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FMU_UPDATE.stringdata))
        return static_cast<void*>(const_cast< FMU_UPDATE*>(this));
    return WBSDChildWindow::qt_metacast(_clname);
}

int FMU_UPDATE::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void FMU_UPDATE::iclose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
