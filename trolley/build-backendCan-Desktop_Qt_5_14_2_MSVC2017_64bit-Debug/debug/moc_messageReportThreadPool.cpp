/****************************************************************************
** Meta object code from reading C++ file 'messageReportThreadPool.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../sdk/thread/messageReportThreadPool.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'messageReportThreadPool.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_messageReportThreadPool_MT_141_t {
    QByteArrayData data[9];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_messageReportThreadPool_MT_141_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_messageReportThreadPool_MT_141_t qt_meta_stringdata_messageReportThreadPool_MT_141 = {
    {
QT_MOC_LITERAL(0, 0, 30), // "messageReportThreadPool_MT_141"
QT_MOC_LITERAL(1, 31, 8), // "slotWork"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 12), // "slotWorkData"
QT_MOC_LITERAL(4, 54, 4), // "data"
QT_MOC_LITERAL(5, 59, 9), // "startWork"
QT_MOC_LITERAL(6, 69, 8), // "stopWork"
QT_MOC_LITERAL(7, 78, 3), // "run"
QT_MOC_LITERAL(8, 82, 7) // "isStart"

    },
    "messageReportThreadPool_MT_141\0slotWork\0"
    "\0slotWorkData\0data\0startWork\0stopWork\0"
    "run\0isStart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_messageReportThreadPool_MT_141[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    1,   45,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       5,    0,   48,    2, 0x02 /* Public */,
       6,    0,   49,    2, 0x02 /* Public */,
       7,    0,   50,    2, 0x02 /* Public */,
       8,    0,   51,    2, 0x02 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    4,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,

       0        // eod
};

void messageReportThreadPool_MT_141::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<messageReportThreadPool_MT_141 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotWork(); break;
        case 1: _t->slotWorkData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->startWork(); break;
        case 3: _t->stopWork(); break;
        case 4: _t->run(); break;
        case 5: { bool _r = _t->isStart();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject messageReportThreadPool_MT_141::staticMetaObject = { {
    QMetaObject::SuperData::link<baseThreadPool::staticMetaObject>(),
    qt_meta_stringdata_messageReportThreadPool_MT_141.data,
    qt_meta_data_messageReportThreadPool_MT_141,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *messageReportThreadPool_MT_141::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *messageReportThreadPool_MT_141::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_messageReportThreadPool_MT_141.stringdata0))
        return static_cast<void*>(this);
    return baseThreadPool::qt_metacast(_clname);
}

int messageReportThreadPool_MT_141::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = baseThreadPool::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
struct qt_meta_stringdata_messageReportThreadPool_MT_145_t {
    QByteArrayData data[9];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_messageReportThreadPool_MT_145_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_messageReportThreadPool_MT_145_t qt_meta_stringdata_messageReportThreadPool_MT_145 = {
    {
QT_MOC_LITERAL(0, 0, 30), // "messageReportThreadPool_MT_145"
QT_MOC_LITERAL(1, 31, 8), // "slotWork"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 12), // "slotWorkData"
QT_MOC_LITERAL(4, 54, 4), // "data"
QT_MOC_LITERAL(5, 59, 9), // "startWork"
QT_MOC_LITERAL(6, 69, 8), // "stopWork"
QT_MOC_LITERAL(7, 78, 3), // "run"
QT_MOC_LITERAL(8, 82, 7) // "isStart"

    },
    "messageReportThreadPool_MT_145\0slotWork\0"
    "\0slotWorkData\0data\0startWork\0stopWork\0"
    "run\0isStart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_messageReportThreadPool_MT_145[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    1,   45,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       5,    0,   48,    2, 0x02 /* Public */,
       6,    0,   49,    2, 0x02 /* Public */,
       7,    0,   50,    2, 0x02 /* Public */,
       8,    0,   51,    2, 0x02 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    4,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,

       0        // eod
};

void messageReportThreadPool_MT_145::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<messageReportThreadPool_MT_145 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotWork(); break;
        case 1: _t->slotWorkData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->startWork(); break;
        case 3: _t->stopWork(); break;
        case 4: _t->run(); break;
        case 5: { bool _r = _t->isStart();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject messageReportThreadPool_MT_145::staticMetaObject = { {
    QMetaObject::SuperData::link<baseThreadPool::staticMetaObject>(),
    qt_meta_stringdata_messageReportThreadPool_MT_145.data,
    qt_meta_data_messageReportThreadPool_MT_145,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *messageReportThreadPool_MT_145::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *messageReportThreadPool_MT_145::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_messageReportThreadPool_MT_145.stringdata0))
        return static_cast<void*>(this);
    return baseThreadPool::qt_metacast(_clname);
}

int messageReportThreadPool_MT_145::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = baseThreadPool::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
struct qt_meta_stringdata_messageReportThreadPool_LX_603_t {
    QByteArrayData data[9];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_messageReportThreadPool_LX_603_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_messageReportThreadPool_LX_603_t qt_meta_stringdata_messageReportThreadPool_LX_603 = {
    {
QT_MOC_LITERAL(0, 0, 30), // "messageReportThreadPool_LX_603"
QT_MOC_LITERAL(1, 31, 8), // "slotWork"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 12), // "slotWorkData"
QT_MOC_LITERAL(4, 54, 4), // "data"
QT_MOC_LITERAL(5, 59, 9), // "startWork"
QT_MOC_LITERAL(6, 69, 8), // "stopWork"
QT_MOC_LITERAL(7, 78, 3), // "run"
QT_MOC_LITERAL(8, 82, 7) // "isStart"

    },
    "messageReportThreadPool_LX_603\0slotWork\0"
    "\0slotWorkData\0data\0startWork\0stopWork\0"
    "run\0isStart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_messageReportThreadPool_LX_603[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    1,   45,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       5,    0,   48,    2, 0x02 /* Public */,
       6,    0,   49,    2, 0x02 /* Public */,
       7,    0,   50,    2, 0x02 /* Public */,
       8,    0,   51,    2, 0x02 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    4,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,

       0        // eod
};

void messageReportThreadPool_LX_603::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<messageReportThreadPool_LX_603 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotWork(); break;
        case 1: _t->slotWorkData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->startWork(); break;
        case 3: _t->stopWork(); break;
        case 4: _t->run(); break;
        case 5: { bool _r = _t->isStart();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject messageReportThreadPool_LX_603::staticMetaObject = { {
    QMetaObject::SuperData::link<baseThreadPool::staticMetaObject>(),
    qt_meta_stringdata_messageReportThreadPool_LX_603.data,
    qt_meta_data_messageReportThreadPool_LX_603,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *messageReportThreadPool_LX_603::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *messageReportThreadPool_LX_603::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_messageReportThreadPool_LX_603.stringdata0))
        return static_cast<void*>(this);
    return baseThreadPool::qt_metacast(_clname);
}

int messageReportThreadPool_LX_603::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = baseThreadPool::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
struct qt_meta_stringdata_messageReportThreadPool_TT_601_t {
    QByteArrayData data[9];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_messageReportThreadPool_TT_601_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_messageReportThreadPool_TT_601_t qt_meta_stringdata_messageReportThreadPool_TT_601 = {
    {
QT_MOC_LITERAL(0, 0, 30), // "messageReportThreadPool_TT_601"
QT_MOC_LITERAL(1, 31, 8), // "slotWork"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 12), // "slotWorkData"
QT_MOC_LITERAL(4, 54, 4), // "data"
QT_MOC_LITERAL(5, 59, 9), // "startWork"
QT_MOC_LITERAL(6, 69, 8), // "stopWork"
QT_MOC_LITERAL(7, 78, 3), // "run"
QT_MOC_LITERAL(8, 82, 7) // "isStart"

    },
    "messageReportThreadPool_TT_601\0slotWork\0"
    "\0slotWorkData\0data\0startWork\0stopWork\0"
    "run\0isStart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_messageReportThreadPool_TT_601[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    1,   45,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       5,    0,   48,    2, 0x02 /* Public */,
       6,    0,   49,    2, 0x02 /* Public */,
       7,    0,   50,    2, 0x02 /* Public */,
       8,    0,   51,    2, 0x02 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    4,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,

       0        // eod
};

void messageReportThreadPool_TT_601::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<messageReportThreadPool_TT_601 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotWork(); break;
        case 1: _t->slotWorkData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->startWork(); break;
        case 3: _t->stopWork(); break;
        case 4: _t->run(); break;
        case 5: { bool _r = _t->isStart();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject messageReportThreadPool_TT_601::staticMetaObject = { {
    QMetaObject::SuperData::link<baseThreadPool::staticMetaObject>(),
    qt_meta_stringdata_messageReportThreadPool_TT_601.data,
    qt_meta_data_messageReportThreadPool_TT_601,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *messageReportThreadPool_TT_601::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *messageReportThreadPool_TT_601::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_messageReportThreadPool_TT_601.stringdata0))
        return static_cast<void*>(this);
    return baseThreadPool::qt_metacast(_clname);
}

int messageReportThreadPool_TT_601::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = baseThreadPool::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
struct qt_meta_stringdata_messageReportThreadPool_YK_602_t {
    QByteArrayData data[9];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_messageReportThreadPool_YK_602_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_messageReportThreadPool_YK_602_t qt_meta_stringdata_messageReportThreadPool_YK_602 = {
    {
QT_MOC_LITERAL(0, 0, 30), // "messageReportThreadPool_YK_602"
QT_MOC_LITERAL(1, 31, 8), // "slotWork"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 12), // "slotWorkData"
QT_MOC_LITERAL(4, 54, 4), // "data"
QT_MOC_LITERAL(5, 59, 9), // "startWork"
QT_MOC_LITERAL(6, 69, 8), // "stopWork"
QT_MOC_LITERAL(7, 78, 3), // "run"
QT_MOC_LITERAL(8, 82, 7) // "isStart"

    },
    "messageReportThreadPool_YK_602\0slotWork\0"
    "\0slotWorkData\0data\0startWork\0stopWork\0"
    "run\0isStart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_messageReportThreadPool_YK_602[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    1,   45,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       5,    0,   48,    2, 0x02 /* Public */,
       6,    0,   49,    2, 0x02 /* Public */,
       7,    0,   50,    2, 0x02 /* Public */,
       8,    0,   51,    2, 0x02 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    4,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,

       0        // eod
};

void messageReportThreadPool_YK_602::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<messageReportThreadPool_YK_602 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotWork(); break;
        case 1: _t->slotWorkData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->startWork(); break;
        case 3: _t->stopWork(); break;
        case 4: _t->run(); break;
        case 5: { bool _r = _t->isStart();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject messageReportThreadPool_YK_602::staticMetaObject = { {
    QMetaObject::SuperData::link<baseThreadPool::staticMetaObject>(),
    qt_meta_stringdata_messageReportThreadPool_YK_602.data,
    qt_meta_data_messageReportThreadPool_YK_602,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *messageReportThreadPool_YK_602::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *messageReportThreadPool_YK_602::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_messageReportThreadPool_YK_602.stringdata0))
        return static_cast<void*>(this);
    return baseThreadPool::qt_metacast(_clname);
}

int messageReportThreadPool_YK_602::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = baseThreadPool::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
struct qt_meta_stringdata_MachineEnableThreadPool_t {
    QByteArrayData data[7];
    char stringdata0[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MachineEnableThreadPool_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MachineEnableThreadPool_t qt_meta_stringdata_MachineEnableThreadPool = {
    {
QT_MOC_LITERAL(0, 0, 23), // "MachineEnableThreadPool"
QT_MOC_LITERAL(1, 24, 8), // "slotWork"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 9), // "startWork"
QT_MOC_LITERAL(4, 44, 8), // "stopWork"
QT_MOC_LITERAL(5, 53, 3), // "run"
QT_MOC_LITERAL(6, 57, 7) // "isStart"

    },
    "MachineEnableThreadPool\0slotWork\0\0"
    "startWork\0stopWork\0run\0isStart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MachineEnableThreadPool[] = {

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
       1,    0,   39,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x02 /* Public */,
       4,    0,   41,    2, 0x02 /* Public */,
       5,    0,   42,    2, 0x02 /* Public */,
       6,    0,   43,    2, 0x02 /* Public */,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,

       0        // eod
};

void MachineEnableThreadPool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MachineEnableThreadPool *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotWork(); break;
        case 1: _t->startWork(); break;
        case 2: _t->stopWork(); break;
        case 3: _t->run(); break;
        case 4: { bool _r = _t->isStart();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MachineEnableThreadPool::staticMetaObject = { {
    QMetaObject::SuperData::link<baseThreadPool::staticMetaObject>(),
    qt_meta_stringdata_MachineEnableThreadPool.data,
    qt_meta_data_MachineEnableThreadPool,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MachineEnableThreadPool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MachineEnableThreadPool::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MachineEnableThreadPool.stringdata0))
        return static_cast<void*>(this);
    return baseThreadPool::qt_metacast(_clname);
}

int MachineEnableThreadPool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = baseThreadPool::qt_metacall(_c, _id, _a);
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
