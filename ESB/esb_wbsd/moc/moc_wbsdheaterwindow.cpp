/****************************************************************************
** Meta object code from reading C++ file 'wbsdheaterwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../wbsdheaterwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wbsdheaterwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WBSDHeaterWindow_t {
    QByteArrayData data[16];
    char stringdata[218];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_WBSDHeaterWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_WBSDHeaterWindow_t qt_meta_stringdata_WBSDHeaterWindow = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 6),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 10),
QT_MOC_LITERAL(4, 36, 7),
QT_MOC_LITERAL(5, 44, 4),
QT_MOC_LITERAL(6, 49, 23),
QT_MOC_LITERAL(7, 73, 7),
QT_MOC_LITERAL(8, 81, 13),
QT_MOC_LITERAL(9, 95, 4),
QT_MOC_LITERAL(10, 100, 10),
QT_MOC_LITERAL(11, 111, 22),
QT_MOC_LITERAL(12, 134, 23),
QT_MOC_LITERAL(13, 158, 17),
QT_MOC_LITERAL(14, 176, 18),
QT_MOC_LITERAL(15, 195, 21)
    },
    "WBSDHeaterWindow\0iclose\0\0gotMessage\0"
    "Message\0aMsg\0connectionStatusChanged\0"
    "aStatus\0StringMessage\0aMSG\0updateData\0"
    "on_heaterRelay_pressed\0on_heaterRelay_released\0"
    "on_cooler_pressed\0on_cooler_released\0"
    "on_menuBack_triggered\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WBSDHeaterWindow[] = {

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
       3,    1,   60,    2, 0x0a,
       6,    2,   63,    2, 0x0a,
      10,    0,   68,    2, 0x0a,
      11,    0,   69,    2, 0x08,
      12,    0,   70,    2, 0x08,
      13,    0,   71,    2, 0x08,
      14,    0,   72,    2, 0x08,
      15,    0,   73,    2, 0x08,

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

       0        // eod
};

void WBSDHeaterWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WBSDHeaterWindow *_t = static_cast<WBSDHeaterWindow *>(_o);
        switch (_id) {
        case 0: _t->iclose(); break;
        case 1: _t->gotMessage((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 2: _t->connectionStatusChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< StringMessage(*)>(_a[2]))); break;
        case 3: _t->updateData(); break;
        case 4: _t->on_heaterRelay_pressed(); break;
        case 5: _t->on_heaterRelay_released(); break;
        case 6: _t->on_cooler_pressed(); break;
        case 7: _t->on_cooler_released(); break;
        case 8: _t->on_menuBack_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WBSDHeaterWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WBSDHeaterWindow::iclose)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject WBSDHeaterWindow::staticMetaObject = {
    { &WBSDChildWindow::staticMetaObject, qt_meta_stringdata_WBSDHeaterWindow.data,
      qt_meta_data_WBSDHeaterWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *WBSDHeaterWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WBSDHeaterWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WBSDHeaterWindow.stringdata))
        return static_cast<void*>(const_cast< WBSDHeaterWindow*>(this));
    return WBSDChildWindow::qt_metacast(_clname);
}

int WBSDHeaterWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void WBSDHeaterWindow::iclose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
