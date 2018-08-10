/****************************************************************************
** Meta object code from reading C++ file 'wbsdmainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../wbsdmainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wbsdmainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WBSDMainWindow_t {
    QByteArrayData data[26];
    char stringdata[507];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_WBSDMainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_WBSDMainWindow_t qt_meta_stringdata_WBSDMainWindow = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 16),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 12),
QT_MOC_LITERAL(4, 46, 4),
QT_MOC_LITERAL(5, 51, 13),
QT_MOC_LITERAL(6, 65, 3),
QT_MOC_LITERAL(7, 69, 7),
QT_MOC_LITERAL(8, 77, 22),
QT_MOC_LITERAL(9, 100, 13),
QT_MOC_LITERAL(10, 114, 11),
QT_MOC_LITERAL(11, 126, 8),
QT_MOC_LITERAL(12, 135, 6),
QT_MOC_LITERAL(13, 142, 23),
QT_MOC_LITERAL(14, 166, 32),
QT_MOC_LITERAL(15, 199, 31),
QT_MOC_LITERAL(16, 231, 31),
QT_MOC_LITERAL(17, 263, 34),
QT_MOC_LITERAL(18, 298, 33),
QT_MOC_LITERAL(19, 332, 38),
QT_MOC_LITERAL(20, 371, 30),
QT_MOC_LITERAL(21, 402, 15),
QT_MOC_LITERAL(22, 418, 6),
QT_MOC_LITERAL(23, 425, 21),
QT_MOC_LITERAL(24, 447, 27),
QT_MOC_LITERAL(25, 475, 30)
    },
    "WBSDMainWindow\0deviceDiscovered\0\0"
    "QextPortInfo\0info\0deviceRemoved\0log\0"
    "aString\0updateConnectionStatus\0"
    "StringMessage\0setLanguage\0QAction*\0"
    "action\0on_actionQuit_triggered\0"
    "on_actionServiceNormal_triggered\0"
    "on_actionServiceNurse_triggered\0"
    "on_actionServiceClean_triggered\0"
    "on_actionServiceOperator_triggered\0"
    "on_actionServiceService_triggered\0"
    "on_actionServiceManufacturer_triggered\0"
    "on_actionServiceWBSD_triggered\0"
    "setServiceLevel\0aLevel\0on_menuQuit_triggered\0"
    "on_actionStateUsa_triggered\0"
    "on_actionStatechange_triggered\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WBSDMainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x08,
       5,    1,  102,    2, 0x08,
       6,    1,  105,    2, 0x08,
       8,    2,  108,    2, 0x08,
      10,    1,  113,    2, 0x08,
      13,    0,  116,    2, 0x0a,
      14,    0,  117,    2, 0x0a,
      15,    0,  118,    2, 0x0a,
      16,    0,  119,    2, 0x0a,
      17,    0,  120,    2, 0x0a,
      18,    0,  121,    2, 0x0a,
      19,    0,  122,    2, 0x0a,
      20,    0,  123,    2, 0x0a,
      21,    1,  124,    2, 0x0a,
      23,    0,  127,    2, 0x0a,
      24,    0,  128,    2, 0x0a,
      25,    0,  129,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 9,    2,    2,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WBSDMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WBSDMainWindow *_t = static_cast<WBSDMainWindow *>(_o);
        switch (_id) {
        case 0: _t->deviceDiscovered((*reinterpret_cast< const QextPortInfo(*)>(_a[1]))); break;
        case 1: _t->deviceRemoved((*reinterpret_cast< const QextPortInfo(*)>(_a[1]))); break;
        case 2: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->updateConnectionStatus((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< StringMessage(*)>(_a[2]))); break;
        case 4: _t->setLanguage((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 5: _t->on_actionQuit_triggered(); break;
        case 6: _t->on_actionServiceNormal_triggered(); break;
        case 7: _t->on_actionServiceNurse_triggered(); break;
        case 8: _t->on_actionServiceClean_triggered(); break;
        case 9: _t->on_actionServiceOperator_triggered(); break;
        case 10: _t->on_actionServiceService_triggered(); break;
        case 11: _t->on_actionServiceManufacturer_triggered(); break;
        case 12: _t->on_actionServiceWBSD_triggered(); break;
        case 13: _t->setServiceLevel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_menuQuit_triggered(); break;
        case 15: _t->on_actionStateUsa_triggered(); break;
        case 16: _t->on_actionStatechange_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QextPortInfo >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QextPortInfo >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    }
}

const QMetaObject WBSDMainWindow::staticMetaObject = {
    { &WBSDBaseWindow::staticMetaObject, qt_meta_stringdata_WBSDMainWindow.data,
      qt_meta_data_WBSDMainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *WBSDMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WBSDMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WBSDMainWindow.stringdata))
        return static_cast<void*>(const_cast< WBSDMainWindow*>(this));
    return WBSDBaseWindow::qt_metacast(_clname);
}

int WBSDMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WBSDBaseWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
