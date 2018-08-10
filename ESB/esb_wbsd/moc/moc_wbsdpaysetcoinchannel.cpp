/****************************************************************************
** Meta object code from reading C++ file 'wbsdpaysetcoinchannel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../wbsdpaysetcoinchannel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wbsdpaysetcoinchannel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WBSDPaySetCoinChannel_t {
    QByteArrayData data[19];
    char stringdata[266];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_WBSDPaySetCoinChannel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_WBSDPaySetCoinChannel_t qt_meta_stringdata_WBSDPaySetCoinChannel = {
    {
QT_MOC_LITERAL(0, 0, 21),
QT_MOC_LITERAL(1, 22, 6),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 21),
QT_MOC_LITERAL(4, 52, 34),
QT_MOC_LITERAL(5, 87, 21),
QT_MOC_LITERAL(6, 109, 7),
QT_MOC_LITERAL(7, 117, 10),
QT_MOC_LITERAL(8, 128, 12),
QT_MOC_LITERAL(9, 141, 10),
QT_MOC_LITERAL(10, 152, 7),
QT_MOC_LITERAL(11, 160, 4),
QT_MOC_LITERAL(12, 165, 23),
QT_MOC_LITERAL(13, 189, 7),
QT_MOC_LITERAL(14, 197, 13),
QT_MOC_LITERAL(15, 211, 4),
QT_MOC_LITERAL(16, 216, 10),
QT_MOC_LITERAL(17, 227, 16),
QT_MOC_LITERAL(18, 244, 20)
    },
    "WBSDPaySetCoinChannel\0iclose\0\0"
    "on_pushButton_clicked\0"
    "on_dblChannelValue_editingFinished\0"
    "on_chkFVToken_toggled\0checked\0closeEvent\0"
    "QCloseEvent*\0gotMessage\0Message\0aMsg\0"
    "connectionStatusChanged\0aStatus\0"
    "StringMessage\0aMSG\0updateData\0"
    "on_btnOK_clicked\0on_btnCancel_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WBSDPaySetCoinChannel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    0,   65,    2, 0x08,
       4,    0,   66,    2, 0x08,
       5,    1,   67,    2, 0x08,
       7,    1,   70,    2, 0x08,
       9,    1,   73,    2, 0x0a,
      12,    2,   76,    2, 0x0a,
      16,    0,   81,    2, 0x0a,
      17,    0,   82,    2, 0x0a,
      18,    0,   83,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 14,   13,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WBSDPaySetCoinChannel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WBSDPaySetCoinChannel *_t = static_cast<WBSDPaySetCoinChannel *>(_o);
        switch (_id) {
        case 0: _t->iclose(); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_dblChannelValue_editingFinished(); break;
        case 3: _t->on_chkFVToken_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 5: _t->gotMessage((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 6: _t->connectionStatusChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< StringMessage(*)>(_a[2]))); break;
        case 7: _t->updateData(); break;
        case 8: _t->on_btnOK_clicked(); break;
        case 9: _t->on_btnCancel_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WBSDPaySetCoinChannel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WBSDPaySetCoinChannel::iclose)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject WBSDPaySetCoinChannel::staticMetaObject = {
    { &WBSDChildWindow::staticMetaObject, qt_meta_stringdata_WBSDPaySetCoinChannel.data,
      qt_meta_data_WBSDPaySetCoinChannel,  qt_static_metacall, 0, 0}
};


const QMetaObject *WBSDPaySetCoinChannel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WBSDPaySetCoinChannel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WBSDPaySetCoinChannel.stringdata))
        return static_cast<void*>(const_cast< WBSDPaySetCoinChannel*>(this));
    return WBSDChildWindow::qt_metacast(_clname);
}

int WBSDPaySetCoinChannel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WBSDChildWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void WBSDPaySetCoinChannel::iclose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
