/****************************************************************************
** Meta object code from reading C++ file 'canDataSendThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../sdk/thread/canDataSendThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'canDataSendThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_canDataSendThread_t {
    QByteArrayData data[16];
    char stringdata0[183];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_canDataSendThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_canDataSendThread_t qt_meta_stringdata_canDataSendThread = {
    {
QT_MOC_LITERAL(0, 0, 17), // "canDataSendThread"
QT_MOC_LITERAL(1, 18, 8), // "slotWork"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 14), // "slotRecvStatus"
QT_MOC_LITERAL(4, 43, 6), // "status"
QT_MOC_LITERAL(5, 50, 10), // "slotRecvId"
QT_MOC_LITERAL(6, 61, 14), // "slotSendCanBuf"
QT_MOC_LITERAL(7, 76, 6), // "length"
QT_MOC_LITERAL(8, 83, 12), // "slotPostWork"
QT_MOC_LITERAL(9, 96, 18), // "slotPostAppendData"
QT_MOC_LITERAL(10, 115, 11), // "const void*"
QT_MOC_LITERAL(11, 127, 6), // "size_t"
QT_MOC_LITERAL(12, 134, 20), // "slotSubAckAppendData"
QT_MOC_LITERAL(13, 155, 8), // "uint32_t"
QT_MOC_LITERAL(14, 164, 9), // "startWork"
QT_MOC_LITERAL(15, 174, 8) // "stopWork"

    },
    "canDataSendThread\0slotWork\0\0slotRecvStatus\0"
    "status\0slotRecvId\0slotSendCanBuf\0"
    "length\0slotPostWork\0slotPostAppendData\0"
    "const void*\0size_t\0slotSubAckAppendData\0"
    "uint32_t\0startWork\0stopWork"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_canDataSendThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    1,   60,    2, 0x0a /* Public */,
       5,    1,   63,    2, 0x0a /* Public */,
       6,    2,   66,    2, 0x0a /* Public */,
       8,    0,   71,    2, 0x0a /* Public */,
       9,    3,   72,    2, 0x0a /* Public */,
      12,    3,   79,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      14,    0,   86,    2, 0x02 /* Public */,
      15,    0,   87,    2, 0x02 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::VoidStar, QMetaType::Int,    2,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 11, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 10, QMetaType::Int, 0x80000000 | 13,    2,    2,    2,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void canDataSendThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<canDataSendThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotWork(); break;
        case 1: _t->slotRecvStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->slotRecvId((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->slotSendCanBuf((*reinterpret_cast< void*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->slotPostWork(); break;
        case 5: _t->slotPostAppendData((*reinterpret_cast< const void*(*)>(_a[1])),(*reinterpret_cast< size_t(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->slotSubAckAppendData((*reinterpret_cast< const void*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const uint32_t(*)>(_a[3]))); break;
        case 7: _t->startWork(); break;
        case 8: _t->stopWork(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject canDataSendThread::staticMetaObject = { {
    QMetaObject::SuperData::link<baseThread::staticMetaObject>(),
    qt_meta_stringdata_canDataSendThread.data,
    qt_meta_data_canDataSendThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *canDataSendThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *canDataSendThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_canDataSendThread.stringdata0))
        return static_cast<void*>(this);
    return baseThread::qt_metacast(_clname);
}

int canDataSendThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = baseThread::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
