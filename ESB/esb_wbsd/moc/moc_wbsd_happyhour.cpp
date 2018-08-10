/****************************************************************************
** Meta object code from reading C++ file 'wbsd_happyhour.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../wbsd_happyhour.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wbsd_happyhour.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_wbsdHappyHour_t {
    QByteArrayData data[26];
    char stringdata[383];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_wbsdHappyHour_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_wbsdHappyHour_t qt_meta_stringdata_wbsdHappyHour = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 6),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 10),
QT_MOC_LITERAL(4, 33, 7),
QT_MOC_LITERAL(5, 41, 4),
QT_MOC_LITERAL(6, 46, 23),
QT_MOC_LITERAL(7, 70, 7),
QT_MOC_LITERAL(8, 78, 13),
QT_MOC_LITERAL(9, 92, 4),
QT_MOC_LITERAL(10, 97, 16),
QT_MOC_LITERAL(11, 114, 5),
QT_MOC_LITERAL(12, 120, 10),
QT_MOC_LITERAL(13, 131, 1),
QT_MOC_LITERAL(14, 133, 13),
QT_MOC_LITERAL(15, 147, 3),
QT_MOC_LITERAL(16, 151, 18),
QT_MOC_LITERAL(17, 170, 10),
QT_MOC_LITERAL(18, 181, 21),
QT_MOC_LITERAL(19, 203, 28),
QT_MOC_LITERAL(20, 232, 28),
QT_MOC_LITERAL(21, 261, 28),
QT_MOC_LITERAL(22, 290, 27),
QT_MOC_LITERAL(23, 318, 27),
QT_MOC_LITERAL(24, 346, 27),
QT_MOC_LITERAL(25, 374, 7)
    },
    "wbsdHappyHour\0iclose\0\0gotMessage\0"
    "Message\0aMsg\0connectionStatusChanged\0"
    "aStatus\0StringMessage\0aMSG\0SetDPHappyHourTm\0"
    "block\0QTimeEdit*\0a\0DPHappyHourUp\0val\0"
    "DPHappyHourSetFlag\0updateData\0"
    "on_menuBack_triggered\0"
    "on_mode1_tes_editingFinished\0"
    "on_mode1_tee_editingFinished\0"
    "on_mode2_tes_editingFinished\0"
    "on_mod2_tee_editingFinished\0"
    "on_mod3_tes_editingFinished\0"
    "on_mod3_tee_editingFinished\0upSetUi\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_wbsdHappyHour[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    1,   90,    2, 0x0a,
       6,    2,   93,    2, 0x0a,
      10,    2,   98,    2, 0x0a,
      14,    2,  103,    2, 0x0a,
      16,    1,  108,    2, 0x0a,
      17,    0,  111,    2, 0x0a,
      18,    0,  112,    2, 0x08,
      19,    0,  113,    2, 0x08,
      20,    0,  114,    2, 0x08,
      21,    0,  115,    2, 0x08,
      22,    0,  116,    2, 0x08,
      23,    0,  117,    2, 0x08,
      24,    0,  118,    2, 0x08,
      25,    0,  119,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 8,    7,    9,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 12,   11,   13,
    QMetaType::Void, 0x80000000 | 12, QMetaType::UShort,   13,   15,
    QMetaType::Void, QMetaType::UShort,   15,
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

void wbsdHappyHour::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        wbsdHappyHour *_t = static_cast<wbsdHappyHour *>(_o);
        switch (_id) {
        case 0: _t->iclose(); break;
        case 1: _t->gotMessage((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 2: _t->connectionStatusChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< StringMessage(*)>(_a[2]))); break;
        case 3: _t->SetDPHappyHourTm((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QTimeEdit*(*)>(_a[2]))); break;
        case 4: _t->DPHappyHourUp((*reinterpret_cast< QTimeEdit*(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 5: _t->DPHappyHourSetFlag((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 6: _t->updateData(); break;
        case 7: _t->on_menuBack_triggered(); break;
        case 8: _t->on_mode1_tes_editingFinished(); break;
        case 9: _t->on_mode1_tee_editingFinished(); break;
        case 10: _t->on_mode2_tes_editingFinished(); break;
        case 11: _t->on_mod2_tee_editingFinished(); break;
        case 12: _t->on_mod3_tes_editingFinished(); break;
        case 13: _t->on_mod3_tee_editingFinished(); break;
        case 14: _t->upSetUi(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTimeEdit* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTimeEdit* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (wbsdHappyHour::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&wbsdHappyHour::iclose)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject wbsdHappyHour::staticMetaObject = {
    { &WBSDChildWindow::staticMetaObject, qt_meta_stringdata_wbsdHappyHour.data,
      qt_meta_data_wbsdHappyHour,  qt_static_metacall, 0, 0}
};


const QMetaObject *wbsdHappyHour::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *wbsdHappyHour::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_wbsdHappyHour.stringdata))
        return static_cast<void*>(const_cast< wbsdHappyHour*>(this));
    return WBSDChildWindow::qt_metacast(_clname);
}

int wbsdHappyHour::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WBSDChildWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void wbsdHappyHour::iclose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
