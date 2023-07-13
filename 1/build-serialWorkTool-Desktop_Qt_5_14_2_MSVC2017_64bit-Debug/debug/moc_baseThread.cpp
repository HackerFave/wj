/****************************************************************************
** Meta object code from reading C++ file 'baseThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../serialWorkTool/thread/baseThread.h"
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
    QByteArrayData data[12];
    char stringdata0[137];
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
QT_MOC_LITERAL(3, 28, 8), // "slotWork"
QT_MOC_LITERAL(4, 37, 12), // "slotPostWork"
QT_MOC_LITERAL(5, 50, 18), // "slotPostAppendData"
QT_MOC_LITERAL(6, 69, 11), // "const void*"
QT_MOC_LITERAL(7, 81, 6), // "size_t"
QT_MOC_LITERAL(8, 88, 20), // "slotSubAckAppendData"
QT_MOC_LITERAL(9, 109, 8), // "uint32_t"
QT_MOC_LITERAL(10, 118, 9), // "startWork"
QT_MOC_LITERAL(11, 128, 8) // "stopWork"

    },
    "baseThread\0signalStartWork\0\0slotWork\0"
    "slotPostWork\0slotPostAppendData\0"
    "const void*\0size_t\0slotSubAckAppendData\0"
    "uint32_t\0startWork\0stopWork"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_baseThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   50,    2, 0x0a /* Public */,
       4,    0,   51,    2, 0x0a /* Public */,
       5,    3,   52,    2, 0x0a /* Public */,
       8,    3,   59,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      10,    0,   66,    2, 0x02 /* Public */,
      11,    0,   67,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 7, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Int, 0x80000000 | 9,    2,    2,    2,

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
        case 1: _t->slotWork(); break;
        case 2: _t->slotPostWork(); break;
        case 3: _t->slotPostAppendData((*reinterpret_cast< const void*(*)>(_a[1])),(*reinterpret_cast< size_t(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->slotSubAckAppendData((*reinterpret_cast< const void*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const uint32_t(*)>(_a[3]))); break;
        case 5: _t->startWork(); break;
        case 6: _t->stopWork(); break;
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void baseThread::signalStartWork()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
