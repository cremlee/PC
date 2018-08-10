/****************************************************************************
** Meta object code from reading C++ file 'fmu_calibration.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../fmu_calibration.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fmu_calibration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FMU_Calibration_t {
    QByteArrayData data[27];
    char stringdata[394];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_FMU_Calibration_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_FMU_Calibration_t qt_meta_stringdata_FMU_Calibration = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 6),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 10),
QT_MOC_LITERAL(4, 35, 7),
QT_MOC_LITERAL(5, 43, 4),
QT_MOC_LITERAL(6, 48, 23),
QT_MOC_LITERAL(7, 72, 7),
QT_MOC_LITERAL(8, 80, 13),
QT_MOC_LITERAL(9, 94, 4),
QT_MOC_LITERAL(10, 99, 17),
QT_MOC_LITERAL(11, 117, 15),
QT_MOC_LITERAL(12, 133, 2),
QT_MOC_LITERAL(13, 136, 5),
QT_MOC_LITERAL(14, 142, 24),
QT_MOC_LITERAL(15, 167, 24),
QT_MOC_LITERAL(16, 192, 24),
QT_MOC_LITERAL(17, 217, 21),
QT_MOC_LITERAL(18, 239, 21),
QT_MOC_LITERAL(19, 261, 21),
QT_MOC_LITERAL(20, 283, 9),
QT_MOC_LITERAL(21, 293, 22),
QT_MOC_LITERAL(22, 316, 24),
QT_MOC_LITERAL(23, 341, 9),
QT_MOC_LITERAL(24, 351, 9),
QT_MOC_LITERAL(25, 361, 9),
QT_MOC_LITERAL(26, 371, 21)
    },
    "FMU_Calibration\0iclose\0\0gotMessage\0"
    "Message\0aMsg\0connectionStatusChanged\0"
    "aStatus\0StringMessage\0aMSG\0updateCalSpdValue\0"
    "QDoubleSpinBox*\0lb\0value\0"
    "on_btn_cal_spd_1_clicked\0"
    "on_btn_cal_spd_2_clicked\0"
    "on_btn_cal_spd_3_clicked\0on_btn_cal_30_clicked\0"
    "on_btn_cal_50_clicked\0on_btn_cal_80_clicked\0"
    "finishcal\0on_btn_cal_100_clicked\0"
    "on_btn_cal_spd_4_clicked\0enablesp1\0"
    "enablesp2\0enablesp3\0on_menuBack_triggered\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FMU_Calibration[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    1,  100,    2, 0x0a,
       6,    2,  103,    2, 0x0a,
      10,    2,  108,    2, 0x0a,
      14,    0,  113,    2, 0x08,
      15,    0,  114,    2, 0x08,
      16,    0,  115,    2, 0x08,
      17,    0,  116,    2, 0x08,
      18,    0,  117,    2, 0x08,
      19,    0,  118,    2, 0x08,
      20,    0,  119,    2, 0x08,
      21,    0,  120,    2, 0x08,
      22,    0,  121,    2, 0x08,
      23,    0,  122,    2, 0x08,
      24,    0,  123,    2, 0x08,
      25,    0,  124,    2, 0x08,
      26,    0,  125,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 8,    7,    9,
    QMetaType::Void, 0x80000000 | 11, QMetaType::Int,   12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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

void FMU_Calibration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FMU_Calibration *_t = static_cast<FMU_Calibration *>(_o);
        switch (_id) {
        case 0: _t->iclose(); break;
        case 1: _t->gotMessage((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 2: _t->connectionStatusChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< StringMessage(*)>(_a[2]))); break;
        case 3: _t->updateCalSpdValue((*reinterpret_cast< QDoubleSpinBox*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->on_btn_cal_spd_1_clicked(); break;
        case 5: _t->on_btn_cal_spd_2_clicked(); break;
        case 6: _t->on_btn_cal_spd_3_clicked(); break;
        case 7: _t->on_btn_cal_30_clicked(); break;
        case 8: _t->on_btn_cal_50_clicked(); break;
        case 9: _t->on_btn_cal_80_clicked(); break;
        case 10: _t->finishcal(); break;
        case 11: _t->on_btn_cal_100_clicked(); break;
        case 12: _t->on_btn_cal_spd_4_clicked(); break;
        case 13: _t->enablesp1(); break;
        case 14: _t->enablesp2(); break;
        case 15: _t->enablesp3(); break;
        case 16: _t->on_menuBack_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDoubleSpinBox* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FMU_Calibration::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FMU_Calibration::iclose)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject FMU_Calibration::staticMetaObject = {
    { &WBSDChildWindow::staticMetaObject, qt_meta_stringdata_FMU_Calibration.data,
      qt_meta_data_FMU_Calibration,  qt_static_metacall, 0, 0}
};


const QMetaObject *FMU_Calibration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FMU_Calibration::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FMU_Calibration.stringdata))
        return static_cast<void*>(const_cast< FMU_Calibration*>(this));
    return WBSDChildWindow::qt_metacast(_clname);
}

int FMU_Calibration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WBSDChildWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void FMU_Calibration::iclose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
