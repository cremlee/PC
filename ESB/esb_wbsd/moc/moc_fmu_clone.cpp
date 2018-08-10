/****************************************************************************
** Meta object code from reading C++ file 'fmu_clone.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../fmu_clone.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fmu_clone.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FMU_CLONE_t {
    QByteArrayData data[22];
    char stringdata[288];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_FMU_CLONE_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_FMU_CLONE_t qt_meta_stringdata_FMU_CLONE = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 6),
QT_MOC_LITERAL(2, 17, 0),
QT_MOC_LITERAL(3, 18, 10),
QT_MOC_LITERAL(4, 29, 7),
QT_MOC_LITERAL(5, 37, 4),
QT_MOC_LITERAL(6, 42, 23),
QT_MOC_LITERAL(7, 66, 7),
QT_MOC_LITERAL(8, 74, 13),
QT_MOC_LITERAL(9, 88, 4),
QT_MOC_LITERAL(10, 93, 20),
QT_MOC_LITERAL(11, 114, 24),
QT_MOC_LITERAL(12, 139, 24),
QT_MOC_LITERAL(13, 164, 8),
QT_MOC_LITERAL(14, 173, 8),
QT_MOC_LITERAL(15, 182, 8),
QT_MOC_LITERAL(16, 191, 7),
QT_MOC_LITERAL(17, 199, 5),
QT_MOC_LITERAL(18, 205, 7),
QT_MOC_LITERAL(19, 213, 25),
QT_MOC_LITERAL(20, 239, 25),
QT_MOC_LITERAL(21, 265, 21)
    },
    "FMU_CLONE\0iclose\0\0gotMessage\0Message\0"
    "aMsg\0connectionStatusChanged\0aStatus\0"
    "StringMessage\0aMSG\0on_btn_clear_clicked\0"
    "on_btn_clone_set_clicked\0"
    "on_btn_clone_rcp_clicked\0clonedbs\0"
    "filename\0clonercp\0uppbset\0value\0uppbrcp\0"
    "on_btn_upload_set_clicked\0"
    "on_btn_upload_rcp_clicked\0"
    "on_menuBack_triggered\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FMU_CLONE[] = {

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
       6,    2,   83,    2, 0x0a,
      10,    0,   88,    2, 0x08,
      11,    0,   89,    2, 0x08,
      12,    0,   90,    2, 0x08,
      13,    1,   91,    2, 0x08,
      15,    1,   94,    2, 0x08,
      16,    1,   97,    2, 0x08,
      18,    1,  100,    2, 0x08,
      19,    0,  103,    2, 0x08,
      20,    0,  104,    2, 0x08,
      21,    0,  105,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 8,    7,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FMU_CLONE::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FMU_CLONE *_t = static_cast<FMU_CLONE *>(_o);
        switch (_id) {
        case 0: _t->iclose(); break;
        case 1: _t->gotMessage((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 2: _t->connectionStatusChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< StringMessage(*)>(_a[2]))); break;
        case 3: _t->on_btn_clear_clicked(); break;
        case 4: _t->on_btn_clone_set_clicked(); break;
        case 5: _t->on_btn_clone_rcp_clicked(); break;
        case 6: _t->clonedbs((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->clonercp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->uppbset((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->uppbrcp((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_btn_upload_set_clicked(); break;
        case 11: _t->on_btn_upload_rcp_clicked(); break;
        case 12: _t->on_menuBack_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FMU_CLONE::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FMU_CLONE::iclose)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject FMU_CLONE::staticMetaObject = {
    { &WBSDChildWindow::staticMetaObject, qt_meta_stringdata_FMU_CLONE.data,
      qt_meta_data_FMU_CLONE,  qt_static_metacall, 0, 0}
};


const QMetaObject *FMU_CLONE::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FMU_CLONE::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FMU_CLONE.stringdata))
        return static_cast<void*>(const_cast< FMU_CLONE*>(this));
    return WBSDChildWindow::qt_metacast(_clname);
}

int FMU_CLONE::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void FMU_CLONE::iclose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
