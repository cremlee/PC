/****************************************************************************
** Meta object code from reading C++ file 'wbsdbuttontestwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../wbsdbuttontestwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wbsdbuttontestwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WBSDButtonTestWindow_t {
    QByteArrayData data[18];
    char stringdata[255];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_WBSDButtonTestWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_WBSDButtonTestWindow_t qt_meta_stringdata_WBSDButtonTestWindow = {
    {
QT_MOC_LITERAL(0, 0, 20),
QT_MOC_LITERAL(1, 21, 6),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 10),
QT_MOC_LITERAL(4, 40, 7),
QT_MOC_LITERAL(5, 48, 4),
QT_MOC_LITERAL(6, 53, 23),
QT_MOC_LITERAL(7, 77, 7),
QT_MOC_LITERAL(8, 85, 13),
QT_MOC_LITERAL(9, 99, 4),
QT_MOC_LITERAL(10, 104, 10),
QT_MOC_LITERAL(11, 115, 18),
QT_MOC_LITERAL(12, 134, 19),
QT_MOC_LITERAL(13, 154, 18),
QT_MOC_LITERAL(14, 173, 19),
QT_MOC_LITERAL(15, 193, 18),
QT_MOC_LITERAL(16, 212, 19),
QT_MOC_LITERAL(17, 232, 21)
    },
    "WBSDButtonTestWindow\0iclose\0\0gotMessage\0"
    "Message\0aMsg\0connectionStatusChanged\0"
    "aStatus\0StringMessage\0aMSG\0updateData\0"
    "on_button1_pressed\0on_button1_released\0"
    "on_button2_pressed\0on_button2_released\0"
    "on_button3_pressed\0on_button3_released\0"
    "on_menuBack_triggered\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WBSDButtonTestWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    1,   70,    2, 0x0a,
       6,    2,   73,    2, 0x0a,
      10,    0,   78,    2, 0x0a,
      11,    0,   79,    2, 0x08,
      12,    0,   80,    2, 0x08,
      13,    0,   81,    2, 0x08,
      14,    0,   82,    2, 0x08,
      15,    0,   83,    2, 0x08,
      16,    0,   84,    2, 0x08,
      17,    0,   85,    2, 0x08,

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
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WBSDButtonTestWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WBSDButtonTestWindow *_t = static_cast<WBSDButtonTestWindow *>(_o);
        switch (_id) {
        case 0: _t->iclose(); break;
        case 1: _t->gotMessage((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 2: _t->connectionStatusChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< StringMessage(*)>(_a[2]))); break;
        case 3: _t->updateData(); break;
        case 4: _t->on_button1_pressed(); break;
        case 5: _t->on_button1_released(); break;
        case 6: _t->on_button2_pressed(); break;
        case 7: _t->on_button2_released(); break;
        case 8: _t->on_button3_pressed(); break;
        case 9: _t->on_button3_released(); break;
        case 10: _t->on_menuBack_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WBSDButtonTestWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WBSDButtonTestWindow::iclose)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject WBSDButtonTestWindow::staticMetaObject = {
    { &WBSDChildWindow::staticMetaObject, qt_meta_stringdata_WBSDButtonTestWindow.data,
      qt_meta_data_WBSDButtonTestWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *WBSDButtonTestWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WBSDButtonTestWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WBSDButtonTestWindow.stringdata))
        return static_cast<void*>(const_cast< WBSDButtonTestWindow*>(this));
    return WBSDChildWindow::qt_metacast(_clname);
}

int WBSDButtonTestWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WBSDChildWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void WBSDButtonTestWindow::iclose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
