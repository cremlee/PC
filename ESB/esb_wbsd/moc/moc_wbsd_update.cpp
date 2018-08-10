/****************************************************************************
** Meta object code from reading C++ file 'wbsd_update.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../wbsd_update.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wbsd_update.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_wbsd_update_t {
    QByteArrayData data[15];
    char stringdata[189];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_wbsd_update_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_wbsd_update_t qt_meta_stringdata_wbsd_update = {
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
QT_MOC_LITERAL(10, 95, 21),
QT_MOC_LITERAL(11, 117, 21),
QT_MOC_LITERAL(12, 139, 20),
QT_MOC_LITERAL(13, 160, 5),
QT_MOC_LITERAL(14, 166, 21)
    },
    "wbsd_update\0iclose\0\0gotMessage\0Message\0"
    "aMsg\0connectionStatusChanged\0aStatus\0"
    "StringMessage\0aMSG\0on_menuBack_triggered\0"
    "on_btn_select_clicked\0on_cb_type_activated\0"
    "index\0on_btn_update_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_wbsd_update[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    1,   50,    2, 0x0a,
       6,    2,   53,    2, 0x0a,
      10,    0,   58,    2, 0x08,
      11,    0,   59,    2, 0x08,
      12,    1,   60,    2, 0x08,
      14,    0,   63,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 8,    7,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,

       0        // eod
};

void wbsd_update::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        wbsd_update *_t = static_cast<wbsd_update *>(_o);
        switch (_id) {
        case 0: _t->iclose(); break;
        case 1: _t->gotMessage((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 2: _t->connectionStatusChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< StringMessage(*)>(_a[2]))); break;
        case 3: _t->on_menuBack_triggered(); break;
        case 4: _t->on_btn_select_clicked(); break;
        case 5: _t->on_cb_type_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_btn_update_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (wbsd_update::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&wbsd_update::iclose)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject wbsd_update::staticMetaObject = {
    { &WBSDChildWindow::staticMetaObject, qt_meta_stringdata_wbsd_update.data,
      qt_meta_data_wbsd_update,  qt_static_metacall, 0, 0}
};


const QMetaObject *wbsd_update::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *wbsd_update::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_wbsd_update.stringdata))
        return static_cast<void*>(const_cast< wbsd_update*>(this));
    return WBSDChildWindow::qt_metacast(_clname);
}

int wbsd_update::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WBSDChildWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void wbsd_update::iclose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
