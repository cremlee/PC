/****************************************************************************
** Meta object code from reading C++ file 'wbsd_clone.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../wbsd_clone.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wbsd_clone.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_wbsdclone_t {
    QByteArrayData data[29];
    char stringdata[370];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_wbsdclone_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_wbsdclone_t qt_meta_stringdata_wbsdclone = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 6),
QT_MOC_LITERAL(2, 17, 0),
QT_MOC_LITERAL(3, 18, 10),
QT_MOC_LITERAL(4, 29, 7),
QT_MOC_LITERAL(5, 37, 4),
QT_MOC_LITERAL(6, 42, 23),
QT_MOC_LITERAL(7, 66, 7),
QT_MOC_LITERAL(8, 74, 13),
QT_MOC_LITERAL(9, 88, 4),
QT_MOC_LITERAL(10, 93, 18),
QT_MOC_LITERAL(11, 112, 20),
QT_MOC_LITERAL(12, 133, 15),
QT_MOC_LITERAL(13, 149, 15),
QT_MOC_LITERAL(14, 165, 20),
QT_MOC_LITERAL(15, 186, 21),
QT_MOC_LITERAL(16, 208, 22),
QT_MOC_LITERAL(17, 231, 5),
QT_MOC_LITERAL(18, 237, 3),
QT_MOC_LITERAL(19, 241, 10),
QT_MOC_LITERAL(20, 252, 6),
QT_MOC_LITERAL(21, 259, 5),
QT_MOC_LITERAL(22, 265, 8),
QT_MOC_LITERAL(23, 274, 8),
QT_MOC_LITERAL(24, 283, 8),
QT_MOC_LITERAL(25, 292, 21),
QT_MOC_LITERAL(26, 314, 21),
QT_MOC_LITERAL(27, 336, 21),
QT_MOC_LITERAL(28, 358, 10)
    },
    "wbsdclone\0iclose\0\0gotMessage\0Message\0"
    "aMsg\0connectionStatusChanged\0aStatus\0"
    "StringMessage\0aMSG\0on_btnlang_clicked\0"
    "on_btnlang_2_clicked\0on_btnd_clicked\0"
    "on_btnr_clicked\0on_btn_clear_clicked\0"
    "on_btn_backup_clicked\0on_btn_restore_clicked\0"
    "dbsup\0cnt\0setversion\0getrpc\0rcpId\0"
    "clonedbs\0filename\0clonercp\0"
    "getcrtfirewareVersion\0on_menuBack_triggered\0"
    "on_pushButton_clicked\0destroywin\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_wbsdclone[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    1,  110,    2, 0x0a,
       6,    2,  113,    2, 0x0a,
      10,    0,  118,    2, 0x0a,
      11,    0,  119,    2, 0x0a,
      12,    0,  120,    2, 0x0a,
      13,    0,  121,    2, 0x0a,
      14,    0,  122,    2, 0x0a,
      15,    0,  123,    2, 0x0a,
      16,    0,  124,    2, 0x0a,
      17,    1,  125,    2, 0x0a,
      19,    0,  128,    2, 0x0a,
      20,    1,  129,    2, 0x0a,
      22,    1,  132,    2, 0x0a,
      24,    1,  135,    2, 0x0a,
      25,    0,  138,    2, 0x0a,
      26,    0,  139,    2, 0x08,
      27,    0,  140,    2, 0x08,
      28,    0,  141,    2, 0x08,

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
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void wbsdclone::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        wbsdclone *_t = static_cast<wbsdclone *>(_o);
        switch (_id) {
        case 0: _t->iclose(); break;
        case 1: _t->gotMessage((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 2: _t->connectionStatusChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< StringMessage(*)>(_a[2]))); break;
        case 3: _t->on_btnlang_clicked(); break;
        case 4: _t->on_btnlang_2_clicked(); break;
        case 5: _t->on_btnd_clicked(); break;
        case 6: _t->on_btnr_clicked(); break;
        case 7: _t->on_btn_clear_clicked(); break;
        case 8: _t->on_btn_backup_clicked(); break;
        case 9: _t->on_btn_restore_clicked(); break;
        case 10: _t->dbsup((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: { bool _r = _t->setversion();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: _t->getrpc((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->clonedbs((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->clonercp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: { QString _r = _t->getcrtfirewareVersion();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 16: _t->on_menuBack_triggered(); break;
        case 17: _t->on_pushButton_clicked(); break;
        case 18: _t->destroywin(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (wbsdclone::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&wbsdclone::iclose)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject wbsdclone::staticMetaObject = {
    { &WBSDChildWindow::staticMetaObject, qt_meta_stringdata_wbsdclone.data,
      qt_meta_data_wbsdclone,  qt_static_metacall, 0, 0}
};


const QMetaObject *wbsdclone::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *wbsdclone::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_wbsdclone.stringdata))
        return static_cast<void*>(const_cast< wbsdclone*>(this));
    return WBSDChildWindow::qt_metacast(_clname);
}

int wbsdclone::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WBSDChildWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void wbsdclone::iclose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
