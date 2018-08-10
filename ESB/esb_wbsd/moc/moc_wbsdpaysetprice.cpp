/****************************************************************************
** Meta object code from reading C++ file 'wbsdpaysetprice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../wbsdpaysetprice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wbsdpaysetprice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WBSDPaySetPrice_t {
    QByteArrayData data[16];
    char stringdata[201];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_WBSDPaySetPrice_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_WBSDPaySetPrice_t qt_meta_stringdata_WBSDPaySetPrice = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 6),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 16),
QT_MOC_LITERAL(4, 41, 20),
QT_MOC_LITERAL(5, 62, 27),
QT_MOC_LITERAL(6, 90, 10),
QT_MOC_LITERAL(7, 101, 7),
QT_MOC_LITERAL(8, 109, 4),
QT_MOC_LITERAL(9, 114, 23),
QT_MOC_LITERAL(10, 138, 7),
QT_MOC_LITERAL(11, 146, 13),
QT_MOC_LITERAL(12, 160, 4),
QT_MOC_LITERAL(13, 165, 10),
QT_MOC_LITERAL(14, 176, 10),
QT_MOC_LITERAL(15, 187, 12)
    },
    "WBSDPaySetPrice\0iclose\0\0on_btnOK_clicked\0"
    "on_btnCancel_clicked\0on_dblPrice_editingFinished\0"
    "gotMessage\0Message\0aMsg\0connectionStatusChanged\0"
    "aStatus\0StringMessage\0aMSG\0updateData\0"
    "closeEvent\0QCloseEvent*\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WBSDPaySetPrice[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    0,   55,    2, 0x08,
       4,    0,   56,    2, 0x08,
       5,    0,   57,    2, 0x08,
       6,    1,   58,    2, 0x0a,
       9,    2,   61,    2, 0x0a,
      13,    0,   66,    2, 0x0a,
      14,    1,   67,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 11,   10,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,    2,

       0        // eod
};

void WBSDPaySetPrice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WBSDPaySetPrice *_t = static_cast<WBSDPaySetPrice *>(_o);
        switch (_id) {
        case 0: _t->iclose(); break;
        case 1: _t->on_btnOK_clicked(); break;
        case 2: _t->on_btnCancel_clicked(); break;
        case 3: _t->on_dblPrice_editingFinished(); break;
        case 4: _t->gotMessage((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 5: _t->connectionStatusChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< StringMessage(*)>(_a[2]))); break;
        case 6: _t->updateData(); break;
        case 7: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WBSDPaySetPrice::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WBSDPaySetPrice::iclose)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject WBSDPaySetPrice::staticMetaObject = {
    { &WBSDChildWindow::staticMetaObject, qt_meta_stringdata_WBSDPaySetPrice.data,
      qt_meta_data_WBSDPaySetPrice,  qt_static_metacall, 0, 0}
};


const QMetaObject *WBSDPaySetPrice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WBSDPaySetPrice::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WBSDPaySetPrice.stringdata))
        return static_cast<void*>(const_cast< WBSDPaySetPrice*>(this));
    return WBSDChildWindow::qt_metacast(_clname);
}

int WBSDPaySetPrice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WBSDChildWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void WBSDPaySetPrice::iclose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
