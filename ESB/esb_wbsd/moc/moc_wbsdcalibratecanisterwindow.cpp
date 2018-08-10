/****************************************************************************
** Meta object code from reading C++ file 'wbsdcalibratecanisterwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../wbsdcalibratecanisterwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wbsdcalibratecanisterwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WBSDCalibrateCanisterwindow_t {
    QByteArrayData data[18];
    char stringdata[233];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_WBSDCalibrateCanisterwindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_WBSDCalibrateCanisterwindow_t qt_meta_stringdata_WBSDCalibrateCanisterwindow = {
    {
QT_MOC_LITERAL(0, 0, 27),
QT_MOC_LITERAL(1, 28, 6),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 21),
QT_MOC_LITERAL(4, 58, 32),
QT_MOC_LITERAL(5, 91, 7),
QT_MOC_LITERAL(6, 99, 1),
QT_MOC_LITERAL(7, 101, 20),
QT_MOC_LITERAL(8, 122, 10),
QT_MOC_LITERAL(9, 133, 7),
QT_MOC_LITERAL(10, 141, 4),
QT_MOC_LITERAL(11, 146, 23),
QT_MOC_LITERAL(12, 170, 7),
QT_MOC_LITERAL(13, 178, 13),
QT_MOC_LITERAL(14, 192, 4),
QT_MOC_LITERAL(15, 197, 10),
QT_MOC_LITERAL(16, 208, 10),
QT_MOC_LITERAL(17, 219, 12)
    },
    "WBSDCalibrateCanisterwindow\0iclose\0\0"
    "on_pushButton_clicked\0"
    "on_doubleSpinBox_editingFinished\0"
    "myvalue\0a\0on_btn_close_clicked\0"
    "gotMessage\0Message\0aMsg\0connectionStatusChanged\0"
    "aStatus\0StringMessage\0aMSG\0updateData\0"
    "closeEvent\0QCloseEvent*\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WBSDCalibrateCanisterwindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    0,   60,    2, 0x08,
       4,    0,   61,    2, 0x08,
       5,    1,   62,    2, 0x08,
       7,    0,   65,    2, 0x08,
       8,    1,   66,    2, 0x0a,
      11,    2,   69,    2, 0x0a,
      15,    0,   74,    2, 0x0a,
      16,    1,   75,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 13,   12,   14,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,    2,

       0        // eod
};

void WBSDCalibrateCanisterwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WBSDCalibrateCanisterwindow *_t = static_cast<WBSDCalibrateCanisterwindow *>(_o);
        switch (_id) {
        case 0: _t->iclose(); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_doubleSpinBox_editingFinished(); break;
        case 3: _t->myvalue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->on_btn_close_clicked(); break;
        case 5: _t->gotMessage((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 6: _t->connectionStatusChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< StringMessage(*)>(_a[2]))); break;
        case 7: _t->updateData(); break;
        case 8: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WBSDCalibrateCanisterwindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WBSDCalibrateCanisterwindow::iclose)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject WBSDCalibrateCanisterwindow::staticMetaObject = {
    { &WBSDChildWindow::staticMetaObject, qt_meta_stringdata_WBSDCalibrateCanisterwindow.data,
      qt_meta_data_WBSDCalibrateCanisterwindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *WBSDCalibrateCanisterwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WBSDCalibrateCanisterwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WBSDCalibrateCanisterwindow.stringdata))
        return static_cast<void*>(const_cast< WBSDCalibrateCanisterwindow*>(this));
    return WBSDChildWindow::qt_metacast(_clname);
}

int WBSDCalibrateCanisterwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WBSDChildWindow::qt_metacall(_c, _id, _a);
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
void WBSDCalibrateCanisterwindow::iclose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
