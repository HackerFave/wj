/****************************************************************************
** Meta object code from reading C++ file 'baseThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../sdk/thread/baseThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'baseThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_baseThread_t {
    QByteArrayData data[18];
    char stringdata0[209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_baseThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_baseThread_t qt_meta_stringdata_baseThread = {
    {
QT_MOC_LITERAL(0, 0, 10), // "baseThread"
QT_MOC_LITERAL(1, 11, 15), // "signalStartWork"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 16), // "signalRecvStatus"
QT_MOC_LITERAL(4, 45, 6), // "status"
QT_MOC_LITERAL(5, 52, 8), // "slotWork"
QT_MOC_LITERAL(6, 61, 14), // "slotRecvStatus"
QT_MOC_LITERAL(7, 76, 10), // "slotRecvId"
QT_MOC_LITERAL(8, 87, 14), // "slotSendCanBuf"
QT_MOC_LITERAL(9, 102, 6), // "length"
QT_MOC_LITERAL(10, 109, 12), // "slotPostWork"
QT_MOC_LITERAL(11, 122, 18), // "slotPostAppendData"
QT_MOC_LITERAL(12, 141, 11), // "const void*"
QT_MOC_LITERAL(13, 153, 6), // "size_t"
QT_MOC_LITERAL(14, 160, 20), // "slotSubAckAppendData"
QT_MOC_LITERAL(15, 181, 8), // "uint32_t"
QT_MOC_LITERAL(16, 190, 9), // "startWork"
QT_MOC_LITERAL(17, 200, 8) // "stopWork"

    },
    "baseThread\0signalStartWork\0\0"
    "signalRecvStatus\0status\0slotWork\0"
    "slotRecvStatus\0slotRecvId\0slotSendCanBuf\0"
    "length\0slotPostWork\0slotPostAppendData\0"
    "const void*\0size_t\0slotSubAckAppendData\0"
    "uint32_t\0startWork\0stopWork"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_baseThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    1,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   73,    2, 0x0a /* Public */,
       6,    1,   74,    2, 0x0a /* Public */,
       7,    1,   77,    2, 0x0a /* Public */,
       8,    2,   80,    2, 0x0a /* Public */,
      10,    0,   85,    2, 0x0a /* Public */,
      11,    3,   86,    2, 0x0a /* Public */,
      14,    3,   93,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      16,    0,  100,    2, 0x02 /* Public */,
      17,    0,  101,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::VoidStar, QMetaType::Int,    2,    9,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 13, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 12, QMetaType::Int, 0x80000000 | 15,    2,    2,    2,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void baseThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<baseThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalStartWork(); break;
        case 1: _t->signalRecvStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->slotWork(); break;
        case 3: _t->slotRecvStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->slotRecvId((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->slotSendCanBuf((*reinterpret_cast< void*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->slotPostWork(); break;
        case 7: _t->slotPostAppendData((*reinterpret_cast< const void*(*)>(_a[1])),(*reinterpret_cast< size_t(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 8: _t->slotSubAckAppendData((*reinterpret_cast< const void*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const uint32_t(*)>(_a[3]))); break;
        case 9: _t->startWork(); break;
        case 10: _t->stopWork(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (baseThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&baseThread::signalStartWork)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (baseThread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&baseThread::signalRecvStatus)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject baseThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_baseThread.data,
    qt_meta_data_baseThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *baseThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *baseThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_baseThread.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int baseThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void baseThread::signalStartWork()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void baseThread::signalRecvStatus(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
