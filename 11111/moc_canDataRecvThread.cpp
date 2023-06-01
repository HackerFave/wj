/****************************************************************************
** Meta object code from reading C++ file 'canDataRecvThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../serialWorkTool/canDataRecvThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'canDataRecvThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_canDataRecvThread_t {
    QByteArrayData data[20];
    char stringdata0[227];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_canDataRecvThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_canDataRecvThread_t qt_meta_stringdata_canDataRecvThread = {
    {
QT_MOC_LITERAL(0, 0, 17), // "canDataRecvThread"
QT_MOC_LITERAL(1, 18, 18), // "signalSendRecvData"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 12), // "VCI_CAN_OBJ*"
QT_MOC_LITERAL(4, 51, 4), // "data"
QT_MOC_LITERAL(5, 56, 5), // "DWORD"
QT_MOC_LITERAL(6, 62, 3), // "len"
QT_MOC_LITERAL(7, 66, 3), // "can"
QT_MOC_LITERAL(8, 70, 15), // "signalSendError"
QT_MOC_LITERAL(9, 86, 16), // "signalRecvStatus"
QT_MOC_LITERAL(10, 103, 8), // "slotWork"
QT_MOC_LITERAL(11, 112, 14), // "slotRecvStatus"
QT_MOC_LITERAL(12, 127, 12), // "slotPostWork"
QT_MOC_LITERAL(13, 140, 18), // "slotPostAppendData"
QT_MOC_LITERAL(14, 159, 11), // "const void*"
QT_MOC_LITERAL(15, 171, 6), // "size_t"
QT_MOC_LITERAL(16, 178, 20), // "slotSubAckAppendData"
QT_MOC_LITERAL(17, 199, 8), // "uint32_t"
QT_MOC_LITERAL(18, 208, 9), // "startWork"
QT_MOC_LITERAL(19, 218, 8) // "stopWork"

    },
    "canDataRecvThread\0signalSendRecvData\0"
    "\0VCI_CAN_OBJ*\0data\0DWORD\0len\0can\0"
    "signalSendError\0signalRecvStatus\0"
    "slotWork\0slotRecvStatus\0slotPostWork\0"
    "slotPostAppendData\0const void*\0size_t\0"
    "slotSubAckAppendData\0uint32_t\0startWork\0"
    "stopWork"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_canDataRecvThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   64,    2, 0x06 /* Public */,
       8,    1,   71,    2, 0x06 /* Public */,
       9,    1,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   77,    2, 0x0a /* Public */,
      11,    1,   78,    2, 0x0a /* Public */,
      12,    0,   81,    2, 0x0a /* Public */,
      13,    3,   82,    2, 0x0a /* Public */,
      16,    3,   89,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      18,    0,   96,    2, 0x02 /* Public */,
      19,    0,   97,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, QMetaType::Short,    4,    6,    7,
    QMetaType::Void, QMetaType::Short,    2,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14, 0x80000000 | 15, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 14, QMetaType::Int, 0x80000000 | 17,    2,    2,    2,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void canDataRecvThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<canDataRecvThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalSendRecvData((*reinterpret_cast< VCI_CAN_OBJ*(*)>(_a[1])),(*reinterpret_cast< DWORD(*)>(_a[2])),(*reinterpret_cast< short(*)>(_a[3]))); break;
        case 1: _t->signalSendError((*reinterpret_cast< short(*)>(_a[1]))); break;
        case 2: _t->signalRecvStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->slotWork(); break;
        case 4: _t->slotRecvStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->slotPostWork(); break;
        case 6: _t->slotPostAppendData((*reinterpret_cast< const void*(*)>(_a[1])),(*reinterpret_cast< size_t(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 7: _t->slotSubAckAppendData((*reinterpret_cast< const void*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const uint32_t(*)>(_a[3]))); break;
        case 8: _t->startWork(); break;
        case 9: _t->stopWork(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (canDataRecvThread::*)(VCI_CAN_OBJ * , DWORD , short );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&canDataRecvThread::signalSendRecvData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (canDataRecvThread::*)(short );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&canDataRecvThread::signalSendError)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (canDataRecvThread::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&canDataRecvThread::signalRecvStatus)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject canDataRecvThread::staticMetaObject = { {
    QMetaObject::SuperData::link<baseThread::staticMetaObject>(),
    qt_meta_stringdata_canDataRecvThread.data,
    qt_meta_data_canDataRecvThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *canDataRecvThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *canDataRecvThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_canDataRecvThread.stringdata0))
        return static_cast<void*>(this);
    return baseThread::qt_metacast(_clname);
}

int canDataRecvThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = baseThread::qt_metacall(_c, _id, _a);
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
void canDataRecvThread::signalSendRecvData(VCI_CAN_OBJ * _t1, DWORD _t2, short _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void canDataRecvThread::signalSendError(short _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void canDataRecvThread::signalRecvStatus(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
