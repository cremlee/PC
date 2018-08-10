/****************************************************************************
** Meta object code from reading C++ file 'wbsdbasewindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../wbsdbasewindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wbsdbasewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WBSDBaseWindow_t {
    QByteArrayData data[19];
    char stringdata[217];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_WBSDBaseWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_WBSDBaseWindow_t qt_meta_stringdata_WBSDBaseWindow = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 15),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 7),
QT_MOC_LITERAL(4, 40, 19),
QT_MOC_LITERAL(5, 60, 13),
QT_MOC_LITERAL(6, 74, 16),
QT_MOC_LITERAL(7, 91, 10),
QT_MOC_LITERAL(8, 102, 4),
QT_MOC_LITERAL(9, 107, 23),
QT_MOC_LITERAL(10, 131, 7),
QT_MOC_LITERAL(11, 139, 4),
QT_MOC_LITERAL(12, 144, 11),
QT_MOC_LITERAL(13, 156, 1),
QT_MOC_LITERAL(14, 158, 5),
QT_MOC_LITERAL(15, 164, 9),
QT_MOC_LITERAL(16, 174, 14),
QT_MOC_LITERAL(17, 189, 11),
QT_MOC_LITERAL(18, 201, 14)
    },
    "WBSDBaseWindow\0transferMessage\0\0Message\0"
    "newConnectionStatus\0StringMessage\0"
    "disconnect_close\0gotMessage\0aMsg\0"
    "connectionStatusChanged\0aStatus\0aMSG\0"
    "setwincheck\0a\0setOt\0sendclose\0"
    "setMachineUnit\0MachineUnit\0getMachineUnit\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WBSDBaseWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06,
       4,    2,   67,    2, 0x06,
       6,    0,   72,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       7,    1,   73,    2, 0x0a,
       9,    2,   76,    2, 0x0a,
      12,    1,   81,    2, 0x0a,
      14,    1,   84,    2, 0x0a,
      15,    0,   87,    2, 0x0a,
      16,    1,   88,    2, 0x0a,
      18,    0,   91,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 5,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    8,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 5,   10,   11,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   13,
    QMetaType::Void,

       0        // eod
};

void WBSDBaseWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WBSDBaseWindow *_t = static_cast<WBSDBaseWindow *>(_o);
        switch (_id) {
        case 0: _t->transferMessage((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 1: _t->newConnectionStatus((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< StringMessage(*)>(_a[2]))); break;
        case 2: _t->disconnect_close(); break;
        case 3: _t->gotMessage((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 4: _t->connectionStatusChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< StringMessage(*)>(_a[2]))); break;
        case 5: _t->setwincheck((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->setOt((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->sendclose(); break;
        case 8: _t->setMachineUnit((*reinterpret_cast< MachineUnit(*)>(_a[1]))); break;
        case 9: _t->getMachineUnit(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WBSDBaseWindow::*_t)(Message );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WBSDBaseWindow::transferMessage)) {
                *result = 0;
            }
        }
        {
            typedef void (WBSDBaseWindow::*_t)(int , StringMessage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WBSDBaseWindow::newConnectionStatus)) {
                *result = 1;
            }
        }
        {
            typedef void (WBSDBaseWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WBSDBaseWindow::disconnect_close)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject WBSDBaseWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_WBSDBaseWindow.data,
      qt_meta_data_WBSDBaseWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *WBSDBaseWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WBSDBaseWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WBSDBaseWindow.stringdata))
        return static_cast<void*>(const_cast< WBSDBaseWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int WBSDBaseWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
void WBSDBaseWindow::transferMessage(Message _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WBSDBaseWindow::newConnectionStatus(int _t1, StringMessage _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WBSDBaseWindow::disconnect_close()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
