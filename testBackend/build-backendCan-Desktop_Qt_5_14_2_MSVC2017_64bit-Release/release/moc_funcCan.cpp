/****************************************************************************
** Meta object code from reading C++ file 'funcCan.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../sdk/methord/funcCan.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'funcCan.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_funcCan_t {
    QByteArrayData data[11];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_funcCan_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_funcCan_t qt_meta_stringdata_funcCan = {
    {
QT_MOC_LITERAL(0, 0, 7), // "funcCan"
QT_MOC_LITERAL(1, 8, 18), // "slotRecvCanMessage"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 4), // "data"
QT_MOC_LITERAL(4, 33, 5), // "DWORD"
QT_MOC_LITERAL(5, 39, 3), // "len"
QT_MOC_LITERAL(6, 43, 3), // "can"
QT_MOC_LITERAL(7, 47, 12), // "slotResetCan"
QT_MOC_LITERAL(8, 60, 19), // "slot_new_connection"
QT_MOC_LITERAL(9, 80, 14), // "slot_recv_data"
QT_MOC_LITERAL(10, 95, 13) // "slotUpdateBmq"

    },
    "funcCan\0slotRecvCanMessage\0\0data\0DWORD\0"
    "len\0can\0slotResetCan\0slot_new_connection\0"
    "slot_recv_data\0slotUpdateBmq"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_funcCan[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   39,    2, 0x0a /* Public */,
       7,    0,   46,    2, 0x0a /* Public */,
       8,    0,   47,    2, 0x0a /* Public */,
       9,    0,   48,    2, 0x0a /* Public */,
      10,    0,   49,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::VoidStar, 0x80000000 | 4, QMetaType::Short,    3,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void funcCan::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<funcCan *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotRecvCanMessage((*reinterpret_cast< void*(*)>(_a[1])),(*reinterpret_cast< DWORD(*)>(_a[2])),(*reinterpret_cast< short(*)>(_a[3]))); break;
        case 1: _t->slotResetCan(); break;
        case 2: _t->slot_new_connection(); break;
        case 3: _t->slot_recv_data(); break;
        case 4: _t->slotUpdateBmq(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject funcCan::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_funcCan.data,
    qt_meta_data_funcCan,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *funcCan::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *funcCan::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_funcCan.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int funcCan::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
