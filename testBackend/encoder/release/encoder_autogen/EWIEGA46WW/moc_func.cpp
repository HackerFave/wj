/****************************************************************************
** Meta object code from reading C++ file 'func.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../func.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'func.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_func_t {
    QByteArrayData data[15];
    char stringdata0[222];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_func_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_func_t qt_meta_stringdata_func = {
    {
QT_MOC_LITERAL(0, 0, 4), // "func"
QT_MOC_LITERAL(1, 5, 12), // "signalStatus"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 13), // "slotWriteData"
QT_MOC_LITERAL(4, 33, 15), // "slotDataArrived"
QT_MOC_LITERAL(5, 49, 20), // "slotWriteShareMemory"
QT_MOC_LITERAL(6, 70, 8), // "QString&"
QT_MOC_LITERAL(7, 79, 4), // "data"
QT_MOC_LITERAL(8, 84, 22), // "slotReconect_to_server"
QT_MOC_LITERAL(9, 107, 26), // "slotDisconnect_from_server"
QT_MOC_LITERAL(10, 134, 13), // "slot_rcv_data"
QT_MOC_LITERAL(11, 148, 20), // "slot_connect_success"
QT_MOC_LITERAL(12, 169, 15), // "slot_error_proc"
QT_MOC_LITERAL(13, 185, 30), // "QLocalSocket::LocalSocketError"
QT_MOC_LITERAL(14, 216, 5) // "state"

    },
    "func\0signalStatus\0\0slotWriteData\0"
    "slotDataArrived\0slotWriteShareMemory\0"
    "QString&\0data\0slotReconect_to_server\0"
    "slotDisconnect_from_server\0slot_rcv_data\0"
    "slot_connect_success\0slot_error_proc\0"
    "QLocalSocket::LocalSocketError\0state"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_func[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   62,    2, 0x08 /* Private */,
       4,    0,   63,    2, 0x08 /* Private */,
       5,    1,   64,    2, 0x08 /* Private */,
       8,    0,   67,    2, 0x08 /* Private */,
       9,    0,   68,    2, 0x08 /* Private */,
      10,    0,   69,    2, 0x08 /* Private */,
      11,    0,   70,    2, 0x08 /* Private */,
      12,    1,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,

       0        // eod
};

void func::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<func *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->slotWriteData(); break;
        case 2: _t->slotDataArrived(); break;
        case 3: _t->slotWriteShareMemory((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->slotReconect_to_server(); break;
        case 5: _t->slotDisconnect_from_server(); break;
        case 6: _t->slot_rcv_data(); break;
        case 7: _t->slot_connect_success(); break;
        case 8: _t->slot_error_proc((*reinterpret_cast< QLocalSocket::LocalSocketError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (func::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&func::signalStatus)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject func::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_func.data,
    qt_meta_data_func,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *func::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *func::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_func.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int func::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void func::signalStatus(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
