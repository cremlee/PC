/****************************************************************************
** Meta object code from reading C++ file 'wbsddisplaywindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../wbsddisplaywindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wbsddisplaywindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WBSDDisplayWindow_t {
    QByteArrayData data[22];
    char stringdata[292];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_WBSDDisplayWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_WBSDDisplayWindow_t qt_meta_stringdata_WBSDDisplayWindow = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 6),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 10),
QT_MOC_LITERAL(4, 37, 7),
QT_MOC_LITERAL(5, 45, 4),
QT_MOC_LITERAL(6, 50, 23),
QT_MOC_LITERAL(7, 74, 7),
QT_MOC_LITERAL(8, 82, 13),
QT_MOC_LITERAL(9, 96, 4),
QT_MOC_LITERAL(10, 101, 10),
QT_MOC_LITERAL(11, 112, 10),
QT_MOC_LITERAL(12, 123, 13),
QT_MOC_LITERAL(13, 137, 1),
QT_MOC_LITERAL(14, 139, 21),
QT_MOC_LITERAL(15, 161, 21),
QT_MOC_LITERAL(16, 183, 21),
QT_MOC_LITERAL(17, 205, 22),
QT_MOC_LITERAL(18, 228, 5),
QT_MOC_LITERAL(19, 234, 16),
QT_MOC_LITERAL(20, 251, 19),
QT_MOC_LITERAL(21, 271, 19)
    },
    "WBSDDisplayWindow\0iclose\0\0gotMessage\0"
    "Message\0aMsg\0connectionStatusChanged\0"
    "aStatus\0StringMessage\0aMSG\0updateData\0"
    "testwclose\0UpdateLCDInfo\0a\0"
    "on_lcdSegment_clicked\0on_buttonTest_clicked\0"
    "on_menuBack_triggered\0on_soundTest_activated\0"
    "index\0on_pbrst_clicked\0on_cb_LCD_activated\0"
    "on_cb_Ani_activated\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WBSDDisplayWindow[] = {

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
      10,    0,   88,    2, 0x0a,
      11,    0,   89,    2, 0x0a,
      12,    1,   90,    2, 0x0a,
      14,    0,   93,    2, 0x08,
      15,    0,   94,    2, 0x08,
      16,    0,   95,    2, 0x08,
      17,    1,   96,    2, 0x08,
      19,    0,   99,    2, 0x08,
      20,    1,  100,    2, 0x08,
      21,    1,  103,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 8,    7,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,

       0        // eod
};

void WBSDDisplayWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WBSDDisplayWindow *_t = static_cast<WBSDDisplayWindow *>(_o);
        switch (_id) {
        case 0: _t->iclose(); break;
        case 1: _t->gotMessage((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 2: _t->connectionStatusChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< StringMessage(*)>(_a[2]))); break;
        case 3: _t->updateData(); break;
        case 4: _t->testwclose(); break;
        case 5: _t->UpdateLCDInfo((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 6: _t->on_lcdSegment_clicked(); break;
        case 7: _t->on_buttonTest_clicked(); break;
        case 8: _t->on_menuBack_triggered(); break;
        case 9: _t->on_soundTest_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_pbrst_clicked(); break;
        case 11: _t->on_cb_LCD_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_cb_Ani_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WBSDDisplayWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WBSDDisplayWindow::iclose)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject WBSDDisplayWindow::staticMetaObject = {
    { &WBSDChildWindow::staticMetaObject, qt_meta_stringdata_WBSDDisplayWindow.data,
      qt_meta_data_WBSDDisplayWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *WBSDDisplayWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WBSDDisplayWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WBSDDisplayWindow.stringdata))
        return static_cast<void*>(const_cast< WBSDDisplayWindow*>(this));
    return WBSDChildWindow::qt_metacast(_clname);
}

int WBSDDisplayWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void WBSDDisplayWindow::iclose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
