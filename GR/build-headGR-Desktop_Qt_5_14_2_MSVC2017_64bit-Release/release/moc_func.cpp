/****************************************************************************
** Meta object code from reading C++ file 'func.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../headGR/func.h"
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
    QByteArrayData data[12];
    char stringdata0[132];
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
QT_MOC_LITERAL(3, 19, 9), // "signalBmq"
QT_MOC_LITERAL(4, 29, 7), // "int32_t"
QT_MOC_LITERAL(5, 37, 10), // "signalData"
QT_MOC_LITERAL(6, 48, 4), // "data"
QT_MOC_LITERAL(7, 53, 13), // "slotWriteData"
QT_MOC_LITERAL(8, 67, 15), // "slotDataArrived"
QT_MOC_LITERAL(9, 83, 13), // "slotUpdateBmq"
QT_MOC_LITERAL(10, 97, 19), // "slot_new_connection"
QT_MOC_LITERAL(11, 117, 14) // "slot_recv_data"

    },
    "func\0signalStatus\0\0signalBmq\0int32_t\0"
    "signalData\0data\0slotWriteData\0"
    "slotDataArrived\0slotUpdateBmq\0"
    "slot_new_connection\0slot_recv_data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_func[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       3,    3,   57,    2, 0x06 /* Public */,
       5,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   67,    2, 0x08 /* Private */,
       8,    0,   68,    2, 0x08 /* Private */,
       9,    0,   69,    2, 0x08 /* Private */,
      10,    0,   70,    2, 0x08 /* Private */,
      11,    0,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4, 0x80000000 | 4,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void func::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<func *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->signalBmq((*reinterpret_cast< int32_t(*)>(_a[1])),(*reinterpret_cast< int32_t(*)>(_a[2])),(*reinterpret_cast< int32_t(*)>(_a[3]))); break;
        case 2: _t->signalData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->slotWriteData(); break;
        case 4: _t->slotDataArrived(); break;
        case 5: _t->slotUpdateBmq(); break;
        case 6: _t->slot_new_connection(); break;
        case 7: _t->slot_recv_data(); break;
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
        {
            using _t = void (func::*)(int32_t , int32_t , int32_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&func::signalBmq)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (func::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&func::signalData)) {
                *result = 2;
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
void func::signalStatus(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void func::signalBmq(int32_t _t1, int32_t _t2, int32_t _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void func::signalData(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
