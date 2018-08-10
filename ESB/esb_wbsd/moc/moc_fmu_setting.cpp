/****************************************************************************
** Meta object code from reading C++ file 'fmu_setting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../fmu_setting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fmu_setting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FMU_SETTING_t {
    QByteArrayData data[26];
    char stringdata[383];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_FMU_SETTING_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_FMU_SETTING_t qt_meta_stringdata_FMU_SETTING = {
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
QT_MOC_LITERAL(10, 95, 20),
QT_MOC_LITERAL(11, 116, 19),
QT_MOC_LITERAL(12, 136, 20),
QT_MOC_LITERAL(13, 157, 18),
QT_MOC_LITERAL(14, 176, 17),
QT_MOC_LITERAL(15, 194, 10),
QT_MOC_LITERAL(16, 205, 30),
QT_MOC_LITERAL(17, 236, 5),
QT_MOC_LITERAL(18, 242, 24),
QT_MOC_LITERAL(19, 267, 4),
QT_MOC_LITERAL(20, 272, 14),
QT_MOC_LITERAL(21, 287, 5),
QT_MOC_LITERAL(22, 293, 20),
QT_MOC_LITERAL(23, 314, 21),
QT_MOC_LITERAL(24, 336, 20),
QT_MOC_LITERAL(25, 357, 24)
    },
    "FMU_SETTING\0iclose\0\0gotMessage\0Message\0"
    "aMsg\0connectionStatusChanged\0aStatus\0"
    "StringMessage\0aMSG\0on_btn_param_clicked\0"
    "on_btn_test_clicked\0on_btn_error_clicked\0"
    "on_btn_cal_clicked\0on_btn_up_clicked\0"
    "destroywin\0on_cb_element_switch_activated\0"
    "index\0update_cb_element_switch\0conf\0"
    "updateHardness\0value\0on_btn_clone_clicked\0"
    "on_menuBack_triggered\0on_pbtn_rest_clicked\0"
    "on_cb_hardness_activated\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FMU_SETTING[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    1,   95,    2, 0x0a,
       6,    2,   98,    2, 0x0a,
      10,    0,  103,    2, 0x08,
      11,    0,  104,    2, 0x08,
      12,    0,  105,    2, 0x08,
      13,    0,  106,    2, 0x08,
      14,    0,  107,    2, 0x08,
      15,    0,  108,    2, 0x08,
      16,    1,  109,    2, 0x08,
      18,    1,  112,    2, 0x08,
      20,    1,  115,    2, 0x08,
      22,    0,  118,    2, 0x08,
      23,    0,  119,    2, 0x08,
      24,    0,  120,    2, 0x08,
      25,    1,  121,    2, 0x08,

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
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,

       0        // eod
};

void FMU_SETTING::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FMU_SETTING *_t = static_cast<FMU_SETTING *>(_o);
        switch (_id) {
        case 0: _t->iclose(); break;
        case 1: _t->gotMessage((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 2: _t->connectionStatusChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< StringMessage(*)>(_a[2]))); break;
        case 3: _t->on_btn_param_clicked(); break;
        case 4: _t->on_btn_test_clicked(); break;
        case 5: _t->on_btn_error_clicked(); break;
        case 6: _t->on_btn_cal_clicked(); break;
        case 7: _t->on_btn_up_clicked(); break;
        case 8: _t->destroywin(); break;
        case 9: _t->on_cb_element_switch_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->update_cb_element_switch((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->updateHardness((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_btn_clone_clicked(); break;
        case 13: _t->on_menuBack_triggered(); break;
        case 14: _t->on_pbtn_rest_clicked(); break;
        case 15: _t->on_cb_hardness_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FMU_SETTING::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FMU_SETTING::iclose)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject FMU_SETTING::staticMetaObject = {
    { &WBSDChildWindow::staticMetaObject, qt_meta_stringdata_FMU_SETTING.data,
      qt_meta_data_FMU_SETTING,  qt_static_metacall, 0, 0}
};


const QMetaObject *FMU_SETTING::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FMU_SETTING::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FMU_SETTING.stringdata))
        return static_cast<void*>(const_cast< FMU_SETTING*>(this));
    return WBSDChildWindow::qt_metacast(_clname);
}

int FMU_SETTING::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WBSDChildWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void FMU_SETTING::iclose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
