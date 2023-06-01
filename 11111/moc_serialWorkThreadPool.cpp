/****************************************************************************
** Meta object code from reading C++ file 'serialWorkThreadPool.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../serialWorkTool/serialWorkThreadPool.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialWorkThreadPool.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_serialWorkThreadPool_MT_141_t {
    QByteArrayData data[9];
    char stringdata0[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_serialWorkThreadPool_MT_141_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_serialWorkThreadPool_MT_141_t qt_meta_stringdata_serialWorkThreadPool_MT_141 = {
    {
QT_MOC_LITERAL(0, 0, 27), // "serialWorkThreadPool_MT_141"
QT_MOC_LITERAL(1, 28, 8), // "slotWork"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 12), // "slotWorkData"
QT_MOC_LITERAL(4, 51, 4), // "data"
QT_MOC_LITERAL(5, 56, 9), // "startWork"
QT_MOC_LITERAL(6, 66, 8), // "stopWork"
QT_MOC_LITERAL(7, 75, 3), // "run"
QT_MOC_LITERAL(8, 79, 7) // "isStart"

    },
    "serialWorkThreadPool_MT_141\0slotWork\0"
    "\0slotWorkData\0data\0startWork\0stopWork\0"
    "run\0isStart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_serialWorkThreadPool_MT_141[] = {

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

void serialWorkThreadPool_MT_141::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<serialWorkThreadPool_MT_141 *>(_o);
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

QT_INIT_METAOBJECT const QMetaObject serialWorkThreadPool_MT_141::staticMetaObject = { {
    QMetaObject::SuperData::link<baseThreadPool::staticMetaObject>(),
    qt_meta_stringdata_serialWorkThreadPool_MT_141.data,
    qt_meta_data_serialWorkThreadPool_MT_141,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *serialWorkThreadPool_MT_141::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serialWorkThreadPool_MT_141::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_serialWorkThreadPool_MT_141.stringdata0))
        return static_cast<void*>(this);
    return baseThreadPool::qt_metacast(_clname);
}

int serialWorkThreadPool_MT_141::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_stringdata_serialWorkThreadPool_MT_142_t {
    QByteArrayData data[9];
    char stringdata0[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_serialWorkThreadPool_MT_142_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_serialWorkThreadPool_MT_142_t qt_meta_stringdata_serialWorkThreadPool_MT_142 = {
    {
QT_MOC_LITERAL(0, 0, 27), // "serialWorkThreadPool_MT_142"
QT_MOC_LITERAL(1, 28, 8), // "slotWork"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 12), // "slotWorkData"
QT_MOC_LITERAL(4, 51, 4), // "data"
QT_MOC_LITERAL(5, 56, 9), // "startWork"
QT_MOC_LITERAL(6, 66, 8), // "stopWork"
QT_MOC_LITERAL(7, 75, 3), // "run"
QT_MOC_LITERAL(8, 79, 7) // "isStart"

    },
    "serialWorkThreadPool_MT_142\0slotWork\0"
    "\0slotWorkData\0data\0startWork\0stopWork\0"
    "run\0isStart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_serialWorkThreadPool_MT_142[] = {

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

void serialWorkThreadPool_MT_142::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<serialWorkThreadPool_MT_142 *>(_o);
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

QT_INIT_METAOBJECT const QMetaObject serialWorkThreadPool_MT_142::staticMetaObject = { {
    QMetaObject::SuperData::link<baseThreadPool::staticMetaObject>(),
    qt_meta_stringdata_serialWorkThreadPool_MT_142.data,
    qt_meta_data_serialWorkThreadPool_MT_142,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *serialWorkThreadPool_MT_142::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serialWorkThreadPool_MT_142::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_serialWorkThreadPool_MT_142.stringdata0))
        return static_cast<void*>(this);
    return baseThreadPool::qt_metacast(_clname);
}

int serialWorkThreadPool_MT_142::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_stringdata_serialWorkThreadPool_MT_143_t {
    QByteArrayData data[9];
    char stringdata0[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_serialWorkThreadPool_MT_143_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_serialWorkThreadPool_MT_143_t qt_meta_stringdata_serialWorkThreadPool_MT_143 = {
    {
QT_MOC_LITERAL(0, 0, 27), // "serialWorkThreadPool_MT_143"
QT_MOC_LITERAL(1, 28, 8), // "slotWork"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 12), // "slotWorkData"
QT_MOC_LITERAL(4, 51, 4), // "data"
QT_MOC_LITERAL(5, 56, 9), // "startWork"
QT_MOC_LITERAL(6, 66, 8), // "stopWork"
QT_MOC_LITERAL(7, 75, 3), // "run"
QT_MOC_LITERAL(8, 79, 7) // "isStart"

    },
    "serialWorkThreadPool_MT_143\0slotWork\0"
    "\0slotWorkData\0data\0startWork\0stopWork\0"
    "run\0isStart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_serialWorkThreadPool_MT_143[] = {

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

void serialWorkThreadPool_MT_143::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<serialWorkThreadPool_MT_143 *>(_o);
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

QT_INIT_METAOBJECT const QMetaObject serialWorkThreadPool_MT_143::staticMetaObject = { {
    QMetaObject::SuperData::link<baseThreadPool::staticMetaObject>(),
    qt_meta_stringdata_serialWorkThreadPool_MT_143.data,
    qt_meta_data_serialWorkThreadPool_MT_143,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *serialWorkThreadPool_MT_143::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serialWorkThreadPool_MT_143::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_serialWorkThreadPool_MT_143.stringdata0))
        return static_cast<void*>(this);
    return baseThreadPool::qt_metacast(_clname);
}

int serialWorkThreadPool_MT_143::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_stringdata_serialWorkThreadPool_MT_145_t {
    QByteArrayData data[9];
    char stringdata0[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_serialWorkThreadPool_MT_145_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_serialWorkThreadPool_MT_145_t qt_meta_stringdata_serialWorkThreadPool_MT_145 = {
    {
QT_MOC_LITERAL(0, 0, 27), // "serialWorkThreadPool_MT_145"
QT_MOC_LITERAL(1, 28, 8), // "slotWork"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 12), // "slotWorkData"
QT_MOC_LITERAL(4, 51, 4), // "data"
QT_MOC_LITERAL(5, 56, 9), // "startWork"
QT_MOC_LITERAL(6, 66, 8), // "stopWork"
QT_MOC_LITERAL(7, 75, 3), // "run"
QT_MOC_LITERAL(8, 79, 7) // "isStart"

    },
    "serialWorkThreadPool_MT_145\0slotWork\0"
    "\0slotWorkData\0data\0startWork\0stopWork\0"
    "run\0isStart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_serialWorkThreadPool_MT_145[] = {

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

void serialWorkThreadPool_MT_145::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<serialWorkThreadPool_MT_145 *>(_o);
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

QT_INIT_METAOBJECT const QMetaObject serialWorkThreadPool_MT_145::staticMetaObject = { {
    QMetaObject::SuperData::link<baseThreadPool::staticMetaObject>(),
    qt_meta_stringdata_serialWorkThreadPool_MT_145.data,
    qt_meta_data_serialWorkThreadPool_MT_145,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *serialWorkThreadPool_MT_145::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serialWorkThreadPool_MT_145::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_serialWorkThreadPool_MT_145.stringdata0))
        return static_cast<void*>(this);
    return baseThreadPool::qt_metacast(_clname);
}

int serialWorkThreadPool_MT_145::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_stringdata_serialWorkThreadPool_TT_601_t {
    QByteArrayData data[9];
    char stringdata0[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_serialWorkThreadPool_TT_601_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_serialWorkThreadPool_TT_601_t qt_meta_stringdata_serialWorkThreadPool_TT_601 = {
    {
QT_MOC_LITERAL(0, 0, 27), // "serialWorkThreadPool_TT_601"
QT_MOC_LITERAL(1, 28, 8), // "slotWork"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 12), // "slotWorkData"
QT_MOC_LITERAL(4, 51, 4), // "data"
QT_MOC_LITERAL(5, 56, 9), // "startWork"
QT_MOC_LITERAL(6, 66, 8), // "stopWork"
QT_MOC_LITERAL(7, 75, 3), // "run"
QT_MOC_LITERAL(8, 79, 7) // "isStart"

    },
    "serialWorkThreadPool_TT_601\0slotWork\0"
    "\0slotWorkData\0data\0startWork\0stopWork\0"
    "run\0isStart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_serialWorkThreadPool_TT_601[] = {

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

void serialWorkThreadPool_TT_601::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<serialWorkThreadPool_TT_601 *>(_o);
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

QT_INIT_METAOBJECT const QMetaObject serialWorkThreadPool_TT_601::staticMetaObject = { {
    QMetaObject::SuperData::link<baseThreadPool::staticMetaObject>(),
    qt_meta_stringdata_serialWorkThreadPool_TT_601.data,
    qt_meta_data_serialWorkThreadPool_TT_601,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *serialWorkThreadPool_TT_601::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serialWorkThreadPool_TT_601::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_serialWorkThreadPool_TT_601.stringdata0))
        return static_cast<void*>(this);
    return baseThreadPool::qt_metacast(_clname);
}

int serialWorkThreadPool_TT_601::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_stringdata_serialWorkThreadPool_LX_603_t {
    QByteArrayData data[9];
    char stringdata0[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_serialWorkThreadPool_LX_603_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_serialWorkThreadPool_LX_603_t qt_meta_stringdata_serialWorkThreadPool_LX_603 = {
    {
QT_MOC_LITERAL(0, 0, 27), // "serialWorkThreadPool_LX_603"
QT_MOC_LITERAL(1, 28, 8), // "slotWork"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 12), // "slotWorkData"
QT_MOC_LITERAL(4, 51, 4), // "data"
QT_MOC_LITERAL(5, 56, 9), // "startWork"
QT_MOC_LITERAL(6, 66, 8), // "stopWork"
QT_MOC_LITERAL(7, 75, 3), // "run"
QT_MOC_LITERAL(8, 79, 7) // "isStart"

    },
    "serialWorkThreadPool_LX_603\0slotWork\0"
    "\0slotWorkData\0data\0startWork\0stopWork\0"
    "run\0isStart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_serialWorkThreadPool_LX_603[] = {

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

void serialWorkThreadPool_LX_603::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<serialWorkThreadPool_LX_603 *>(_o);
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

QT_INIT_METAOBJECT const QMetaObject serialWorkThreadPool_LX_603::staticMetaObject = { {
    QMetaObject::SuperData::link<baseThreadPool::staticMetaObject>(),
    qt_meta_stringdata_serialWorkThreadPool_LX_603.data,
    qt_meta_data_serialWorkThreadPool_LX_603,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *serialWorkThreadPool_LX_603::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serialWorkThreadPool_LX_603::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_serialWorkThreadPool_LX_603.stringdata0))
        return static_cast<void*>(this);
    return baseThreadPool::qt_metacast(_clname);
}

int serialWorkThreadPool_LX_603::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_stringdata_serialWorkThreadPool_YK_602_t {
    QByteArrayData data[9];
    char stringdata0[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_serialWorkThreadPool_YK_602_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_serialWorkThreadPool_YK_602_t qt_meta_stringdata_serialWorkThreadPool_YK_602 = {
    {
QT_MOC_LITERAL(0, 0, 27), // "serialWorkThreadPool_YK_602"
QT_MOC_LITERAL(1, 28, 8), // "slotWork"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 12), // "slotWorkData"
QT_MOC_LITERAL(4, 51, 4), // "data"
QT_MOC_LITERAL(5, 56, 9), // "startWork"
QT_MOC_LITERAL(6, 66, 8), // "stopWork"
QT_MOC_LITERAL(7, 75, 3), // "run"
QT_MOC_LITERAL(8, 79, 7) // "isStart"

    },
    "serialWorkThreadPool_YK_602\0slotWork\0"
    "\0slotWorkData\0data\0startWork\0stopWork\0"
    "run\0isStart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_serialWorkThreadPool_YK_602[] = {

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

void serialWorkThreadPool_YK_602::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<serialWorkThreadPool_YK_602 *>(_o);
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

QT_INIT_METAOBJECT const QMetaObject serialWorkThreadPool_YK_602::staticMetaObject = { {
    QMetaObject::SuperData::link<baseThreadPool::staticMetaObject>(),
    qt_meta_stringdata_serialWorkThreadPool_YK_602.data,
    qt_meta_data_serialWorkThreadPool_YK_602,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *serialWorkThreadPool_YK_602::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serialWorkThreadPool_YK_602::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_serialWorkThreadPool_YK_602.stringdata0))
        return static_cast<void*>(this);
    return baseThreadPool::qt_metacast(_clname);
}

int serialWorkThreadPool_YK_602::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_stringdata_serialWorkThreadPool_XT_01_t {
    QByteArrayData data[9];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_serialWorkThreadPool_XT_01_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_serialWorkThreadPool_XT_01_t qt_meta_stringdata_serialWorkThreadPool_XT_01 = {
    {
QT_MOC_LITERAL(0, 0, 26), // "serialWorkThreadPool_XT_01"
QT_MOC_LITERAL(1, 27, 8), // "slotWork"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 12), // "slotWorkData"
QT_MOC_LITERAL(4, 50, 4), // "data"
QT_MOC_LITERAL(5, 55, 9), // "startWork"
QT_MOC_LITERAL(6, 65, 8), // "stopWork"
QT_MOC_LITERAL(7, 74, 3), // "run"
QT_MOC_LITERAL(8, 78, 7) // "isStart"

    },
    "serialWorkThreadPool_XT_01\0slotWork\0"
    "\0slotWorkData\0data\0startWork\0stopWork\0"
    "run\0isStart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_serialWorkThreadPool_XT_01[] = {

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

void serialWorkThreadPool_XT_01::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<serialWorkThreadPool_XT_01 *>(_o);
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

QT_INIT_METAOBJECT const QMetaObject serialWorkThreadPool_XT_01::staticMetaObject = { {
    QMetaObject::SuperData::link<baseThreadPool::staticMetaObject>(),
    qt_meta_stringdata_serialWorkThreadPool_XT_01.data,
    qt_meta_data_serialWorkThreadPool_XT_01,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *serialWorkThreadPool_XT_01::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serialWorkThreadPool_XT_01::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_serialWorkThreadPool_XT_01.stringdata0))
        return static_cast<void*>(this);
    return baseThreadPool::qt_metacast(_clname);
}

int serialWorkThreadPool_XT_01::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_stringdata_serialWorkThreadPool_XT_02_t {
    QByteArrayData data[9];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_serialWorkThreadPool_XT_02_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_serialWorkThreadPool_XT_02_t qt_meta_stringdata_serialWorkThreadPool_XT_02 = {
    {
QT_MOC_LITERAL(0, 0, 26), // "serialWorkThreadPool_XT_02"
QT_MOC_LITERAL(1, 27, 8), // "slotWork"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 12), // "slotWorkData"
QT_MOC_LITERAL(4, 50, 4), // "data"
QT_MOC_LITERAL(5, 55, 9), // "startWork"
QT_MOC_LITERAL(6, 65, 8), // "stopWork"
QT_MOC_LITERAL(7, 74, 3), // "run"
QT_MOC_LITERAL(8, 78, 7) // "isStart"

    },
    "serialWorkThreadPool_XT_02\0slotWork\0"
    "\0slotWorkData\0data\0startWork\0stopWork\0"
    "run\0isStart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_serialWorkThreadPool_XT_02[] = {

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

void serialWorkThreadPool_XT_02::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<serialWorkThreadPool_XT_02 *>(_o);
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

QT_INIT_METAOBJECT const QMetaObject serialWorkThreadPool_XT_02::staticMetaObject = { {
    QMetaObject::SuperData::link<baseThreadPool::staticMetaObject>(),
    qt_meta_stringdata_serialWorkThreadPool_XT_02.data,
    qt_meta_data_serialWorkThreadPool_XT_02,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *serialWorkThreadPool_XT_02::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serialWorkThreadPool_XT_02::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_serialWorkThreadPool_XT_02.stringdata0))
        return static_cast<void*>(this);
    return baseThreadPool::qt_metacast(_clname);
}

int serialWorkThreadPool_XT_02::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_stringdata_serialWorkThreadPool_BMQ_t {
    QByteArrayData data[13];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_serialWorkThreadPool_BMQ_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_serialWorkThreadPool_BMQ_t qt_meta_stringdata_serialWorkThreadPool_BMQ = {
    {
QT_MOC_LITERAL(0, 0, 24), // "serialWorkThreadPool_BMQ"
QT_MOC_LITERAL(1, 25, 13), // "signalComData"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 4), // "data"
QT_MOC_LITERAL(4, 45, 3), // "com"
QT_MOC_LITERAL(5, 49, 8), // "slotWork"
QT_MOC_LITERAL(6, 58, 12), // "slotWorkData"
QT_MOC_LITERAL(7, 71, 11), // "DataArrived"
QT_MOC_LITERAL(8, 83, 19), // "slotReadShareMemory"
QT_MOC_LITERAL(9, 103, 9), // "startWork"
QT_MOC_LITERAL(10, 113, 8), // "stopWork"
QT_MOC_LITERAL(11, 122, 3), // "run"
QT_MOC_LITERAL(12, 126, 7) // "isStart"

    },
    "serialWorkThreadPool_BMQ\0signalComData\0"
    "\0data\0com\0slotWork\0slotWorkData\0"
    "DataArrived\0slotReadShareMemory\0"
    "startWork\0stopWork\0run\0isStart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_serialWorkThreadPool_BMQ[] = {

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
       1,    2,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   64,    2, 0x0a /* Public */,
       6,    1,   65,    2, 0x0a /* Public */,
       7,    0,   68,    2, 0x0a /* Public */,
       8,    0,   69,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       9,    0,   70,    2, 0x02 /* Public */,
      10,    0,   71,    2, 0x02 /* Public */,
      11,    0,   72,    2, 0x02 /* Public */,
      12,    0,   73,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,

       0        // eod
};

void serialWorkThreadPool_BMQ::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<serialWorkThreadPool_BMQ *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalComData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->slotWork(); break;
        case 2: _t->slotWorkData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->DataArrived(); break;
        case 4: _t->slotReadShareMemory(); break;
        case 5: _t->startWork(); break;
        case 6: _t->stopWork(); break;
        case 7: _t->run(); break;
        case 8: { bool _r = _t->isStart();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (serialWorkThreadPool_BMQ::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&serialWorkThreadPool_BMQ::signalComData)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject serialWorkThreadPool_BMQ::staticMetaObject = { {
    QMetaObject::SuperData::link<baseThreadPool::staticMetaObject>(),
    qt_meta_stringdata_serialWorkThreadPool_BMQ.data,
    qt_meta_data_serialWorkThreadPool_BMQ,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *serialWorkThreadPool_BMQ::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serialWorkThreadPool_BMQ::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_serialWorkThreadPool_BMQ.stringdata0))
        return static_cast<void*>(this);
    return baseThreadPool::qt_metacast(_clname);
}

int serialWorkThreadPool_BMQ::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = baseThreadPool::qt_metacall(_c, _id, _a);
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
void serialWorkThreadPool_BMQ::signalComData(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_serialWorkThreadPool_BMQ_A2_t {
    QByteArrayData data[15];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_serialWorkThreadPool_BMQ_A2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_serialWorkThreadPool_BMQ_A2_t qt_meta_stringdata_serialWorkThreadPool_BMQ_A2 = {
    {
QT_MOC_LITERAL(0, 0, 27), // "serialWorkThreadPool_BMQ_A2"
QT_MOC_LITERAL(1, 28, 8), // "slotWork"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 12), // "slotWorkData"
QT_MOC_LITERAL(4, 51, 3), // "COM"
QT_MOC_LITERAL(5, 55, 7), // "int32_t"
QT_MOC_LITERAL(6, 63, 3), // "duo"
QT_MOC_LITERAL(7, 67, 3), // "dan"
QT_MOC_LITERAL(8, 71, 15), // "slotMachineData"
QT_MOC_LITERAL(9, 87, 8), // "int32_t&"
QT_MOC_LITERAL(10, 96, 4), // "data"
QT_MOC_LITERAL(11, 101, 9), // "startWork"
QT_MOC_LITERAL(12, 111, 8), // "stopWork"
QT_MOC_LITERAL(13, 120, 3), // "run"
QT_MOC_LITERAL(14, 124, 7) // "isStart"

    },
    "serialWorkThreadPool_BMQ_A2\0slotWork\0"
    "\0slotWorkData\0COM\0int32_t\0duo\0dan\0"
    "slotMachineData\0int32_t&\0data\0startWork\0"
    "stopWork\0run\0isStart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_serialWorkThreadPool_BMQ_A2[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    3,   50,    2, 0x0a /* Public */,
       8,    1,   57,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      11,    0,   60,    2, 0x02 /* Public */,
      12,    0,   61,    2, 0x02 /* Public */,
      13,    0,   62,    2, 0x02 /* Public */,
      14,    0,   63,    2, 0x02 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 5, 0x80000000 | 5,    4,    6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,

       0        // eod
};

void serialWorkThreadPool_BMQ_A2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<serialWorkThreadPool_BMQ_A2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotWork(); break;
        case 1: _t->slotWorkData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int32_t(*)>(_a[2])),(*reinterpret_cast< int32_t(*)>(_a[3]))); break;
        case 2: _t->slotMachineData((*reinterpret_cast< int32_t(*)>(_a[1]))); break;
        case 3: _t->startWork(); break;
        case 4: _t->stopWork(); break;
        case 5: _t->run(); break;
        case 6: { bool _r = _t->isStart();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject serialWorkThreadPool_BMQ_A2::staticMetaObject = { {
    QMetaObject::SuperData::link<baseThreadPool::staticMetaObject>(),
    qt_meta_stringdata_serialWorkThreadPool_BMQ_A2.data,
    qt_meta_data_serialWorkThreadPool_BMQ_A2,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *serialWorkThreadPool_BMQ_A2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serialWorkThreadPool_BMQ_A2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_serialWorkThreadPool_BMQ_A2.stringdata0))
        return static_cast<void*>(this);
    return baseThreadPool::qt_metacast(_clname);
}

int serialWorkThreadPool_BMQ_A2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = baseThreadPool::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_serialWorkThreadPool_BMQ_A3_t {
    QByteArrayData data[15];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_serialWorkThreadPool_BMQ_A3_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_serialWorkThreadPool_BMQ_A3_t qt_meta_stringdata_serialWorkThreadPool_BMQ_A3 = {
    {
QT_MOC_LITERAL(0, 0, 27), // "serialWorkThreadPool_BMQ_A3"
QT_MOC_LITERAL(1, 28, 8), // "slotWork"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 12), // "slotWorkData"
QT_MOC_LITERAL(4, 51, 3), // "COM"
QT_MOC_LITERAL(5, 55, 7), // "int32_t"
QT_MOC_LITERAL(6, 63, 3), // "duo"
QT_MOC_LITERAL(7, 67, 3), // "dan"
QT_MOC_LITERAL(8, 71, 15), // "slotMachineData"
QT_MOC_LITERAL(9, 87, 8), // "int32_t&"
QT_MOC_LITERAL(10, 96, 4), // "data"
QT_MOC_LITERAL(11, 101, 9), // "startWork"
QT_MOC_LITERAL(12, 111, 8), // "stopWork"
QT_MOC_LITERAL(13, 120, 3), // "run"
QT_MOC_LITERAL(14, 124, 7) // "isStart"

    },
    "serialWorkThreadPool_BMQ_A3\0slotWork\0"
    "\0slotWorkData\0COM\0int32_t\0duo\0dan\0"
    "slotMachineData\0int32_t&\0data\0startWork\0"
    "stopWork\0run\0isStart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_serialWorkThreadPool_BMQ_A3[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    3,   50,    2, 0x0a /* Public */,
       8,    1,   57,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      11,    0,   60,    2, 0x02 /* Public */,
      12,    0,   61,    2, 0x02 /* Public */,
      13,    0,   62,    2, 0x02 /* Public */,
      14,    0,   63,    2, 0x02 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 5, 0x80000000 | 5,    4,    6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,

       0        // eod
};

void serialWorkThreadPool_BMQ_A3::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<serialWorkThreadPool_BMQ_A3 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotWork(); break;
        case 1: _t->slotWorkData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int32_t(*)>(_a[2])),(*reinterpret_cast< int32_t(*)>(_a[3]))); break;
        case 2: _t->slotMachineData((*reinterpret_cast< int32_t(*)>(_a[1]))); break;
        case 3: _t->startWork(); break;
        case 4: _t->stopWork(); break;
        case 5: _t->run(); break;
        case 6: { bool _r = _t->isStart();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject serialWorkThreadPool_BMQ_A3::staticMetaObject = { {
    QMetaObject::SuperData::link<baseThreadPool::staticMetaObject>(),
    qt_meta_stringdata_serialWorkThreadPool_BMQ_A3.data,
    qt_meta_data_serialWorkThreadPool_BMQ_A3,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *serialWorkThreadPool_BMQ_A3::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serialWorkThreadPool_BMQ_A3::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_serialWorkThreadPool_BMQ_A3.stringdata0))
        return static_cast<void*>(this);
    return baseThreadPool::qt_metacast(_clname);
}

int serialWorkThreadPool_BMQ_A3::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = baseThreadPool::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_serialWorkThreadPool_BMQ_A4_t {
    QByteArrayData data[15];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_serialWorkThreadPool_BMQ_A4_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_serialWorkThreadPool_BMQ_A4_t qt_meta_stringdata_serialWorkThreadPool_BMQ_A4 = {
    {
QT_MOC_LITERAL(0, 0, 27), // "serialWorkThreadPool_BMQ_A4"
QT_MOC_LITERAL(1, 28, 8), // "slotWork"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 12), // "slotWorkData"
QT_MOC_LITERAL(4, 51, 3), // "COM"
QT_MOC_LITERAL(5, 55, 7), // "int32_t"
QT_MOC_LITERAL(6, 63, 3), // "duo"
QT_MOC_LITERAL(7, 67, 3), // "dan"
QT_MOC_LITERAL(8, 71, 15), // "slotMachineData"
QT_MOC_LITERAL(9, 87, 8), // "int32_t&"
QT_MOC_LITERAL(10, 96, 4), // "data"
QT_MOC_LITERAL(11, 101, 9), // "startWork"
QT_MOC_LITERAL(12, 111, 8), // "stopWork"
QT_MOC_LITERAL(13, 120, 3), // "run"
QT_MOC_LITERAL(14, 124, 7) // "isStart"

    },
    "serialWorkThreadPool_BMQ_A4\0slotWork\0"
    "\0slotWorkData\0COM\0int32_t\0duo\0dan\0"
    "slotMachineData\0int32_t&\0data\0startWork\0"
    "stopWork\0run\0isStart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_serialWorkThreadPool_BMQ_A4[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    3,   50,    2, 0x0a /* Public */,
       8,    1,   57,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      11,    0,   60,    2, 0x02 /* Public */,
      12,    0,   61,    2, 0x02 /* Public */,
      13,    0,   62,    2, 0x02 /* Public */,
      14,    0,   63,    2, 0x02 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 5, 0x80000000 | 5,    4,    6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,

       0        // eod
};

void serialWorkThreadPool_BMQ_A4::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<serialWorkThreadPool_BMQ_A4 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotWork(); break;
        case 1: _t->slotWorkData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int32_t(*)>(_a[2])),(*reinterpret_cast< int32_t(*)>(_a[3]))); break;
        case 2: _t->slotMachineData((*reinterpret_cast< int32_t(*)>(_a[1]))); break;
        case 3: _t->startWork(); break;
        case 4: _t->stopWork(); break;
        case 5: _t->run(); break;
        case 6: { bool _r = _t->isStart();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject serialWorkThreadPool_BMQ_A4::staticMetaObject = { {
    QMetaObject::SuperData::link<baseThreadPool::staticMetaObject>(),
    qt_meta_stringdata_serialWorkThreadPool_BMQ_A4.data,
    qt_meta_data_serialWorkThreadPool_BMQ_A4,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *serialWorkThreadPool_BMQ_A4::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serialWorkThreadPool_BMQ_A4::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_serialWorkThreadPool_BMQ_A4.stringdata0))
        return static_cast<void*>(this);
    return baseThreadPool::qt_metacast(_clname);
}

int serialWorkThreadPool_BMQ_A4::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = baseThreadPool::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_serialWorkThreadPool_BMQ_A8_t {
    QByteArrayData data[15];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_serialWorkThreadPool_BMQ_A8_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_serialWorkThreadPool_BMQ_A8_t qt_meta_stringdata_serialWorkThreadPool_BMQ_A8 = {
    {
QT_MOC_LITERAL(0, 0, 27), // "serialWorkThreadPool_BMQ_A8"
QT_MOC_LITERAL(1, 28, 8), // "slotWork"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 12), // "slotWorkData"
QT_MOC_LITERAL(4, 51, 3), // "COM"
QT_MOC_LITERAL(5, 55, 7), // "int32_t"
QT_MOC_LITERAL(6, 63, 3), // "duo"
QT_MOC_LITERAL(7, 67, 3), // "dan"
QT_MOC_LITERAL(8, 71, 15), // "slotMachineData"
QT_MOC_LITERAL(9, 87, 8), // "int32_t&"
QT_MOC_LITERAL(10, 96, 4), // "data"
QT_MOC_LITERAL(11, 101, 9), // "startWork"
QT_MOC_LITERAL(12, 111, 8), // "stopWork"
QT_MOC_LITERAL(13, 120, 3), // "run"
QT_MOC_LITERAL(14, 124, 7) // "isStart"

    },
    "serialWorkThreadPool_BMQ_A8\0slotWork\0"
    "\0slotWorkData\0COM\0int32_t\0duo\0dan\0"
    "slotMachineData\0int32_t&\0data\0startWork\0"
    "stopWork\0run\0isStart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_serialWorkThreadPool_BMQ_A8[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    3,   50,    2, 0x0a /* Public */,
       8,    1,   57,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      11,    0,   60,    2, 0x02 /* Public */,
      12,    0,   61,    2, 0x02 /* Public */,
      13,    0,   62,    2, 0x02 /* Public */,
      14,    0,   63,    2, 0x02 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 5, 0x80000000 | 5,    4,    6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,

       0        // eod
};

void serialWorkThreadPool_BMQ_A8::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<serialWorkThreadPool_BMQ_A8 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotWork(); break;
        case 1: _t->slotWorkData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int32_t(*)>(_a[2])),(*reinterpret_cast< int32_t(*)>(_a[3]))); break;
        case 2: _t->slotMachineData((*reinterpret_cast< int32_t(*)>(_a[1]))); break;
        case 3: _t->startWork(); break;
        case 4: _t->stopWork(); break;
        case 5: _t->run(); break;
        case 6: { bool _r = _t->isStart();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject serialWorkThreadPool_BMQ_A8::staticMetaObject = { {
    QMetaObject::SuperData::link<baseThreadPool::staticMetaObject>(),
    qt_meta_stringdata_serialWorkThreadPool_BMQ_A8.data,
    qt_meta_data_serialWorkThreadPool_BMQ_A8,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *serialWorkThreadPool_BMQ_A8::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serialWorkThreadPool_BMQ_A8::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_serialWorkThreadPool_BMQ_A8.stringdata0))
        return static_cast<void*>(this);
    return baseThreadPool::qt_metacast(_clname);
}

int serialWorkThreadPool_BMQ_A8::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = baseThreadPool::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_serialWorkThreadPool_BMQ_A1_t {
    QByteArrayData data[15];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_serialWorkThreadPool_BMQ_A1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_serialWorkThreadPool_BMQ_A1_t qt_meta_stringdata_serialWorkThreadPool_BMQ_A1 = {
    {
QT_MOC_LITERAL(0, 0, 27), // "serialWorkThreadPool_BMQ_A1"
QT_MOC_LITERAL(1, 28, 8), // "slotWork"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 12), // "slotWorkData"
QT_MOC_LITERAL(4, 51, 3), // "COM"
QT_MOC_LITERAL(5, 55, 7), // "int32_t"
QT_MOC_LITERAL(6, 63, 3), // "duo"
QT_MOC_LITERAL(7, 67, 3), // "dan"
QT_MOC_LITERAL(8, 71, 15), // "slotMachineData"
QT_MOC_LITERAL(9, 87, 8), // "int32_t&"
QT_MOC_LITERAL(10, 96, 4), // "data"
QT_MOC_LITERAL(11, 101, 9), // "startWork"
QT_MOC_LITERAL(12, 111, 8), // "stopWork"
QT_MOC_LITERAL(13, 120, 3), // "run"
QT_MOC_LITERAL(14, 124, 7) // "isStart"

    },
    "serialWorkThreadPool_BMQ_A1\0slotWork\0"
    "\0slotWorkData\0COM\0int32_t\0duo\0dan\0"
    "slotMachineData\0int32_t&\0data\0startWork\0"
    "stopWork\0run\0isStart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_serialWorkThreadPool_BMQ_A1[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    3,   50,    2, 0x0a /* Public */,
       8,    1,   57,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      11,    0,   60,    2, 0x02 /* Public */,
      12,    0,   61,    2, 0x02 /* Public */,
      13,    0,   62,    2, 0x02 /* Public */,
      14,    0,   63,    2, 0x02 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 5, 0x80000000 | 5,    4,    6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,

       0        // eod
};

void serialWorkThreadPool_BMQ_A1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<serialWorkThreadPool_BMQ_A1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotWork(); break;
        case 1: _t->slotWorkData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int32_t(*)>(_a[2])),(*reinterpret_cast< int32_t(*)>(_a[3]))); break;
        case 2: _t->slotMachineData((*reinterpret_cast< int32_t(*)>(_a[1]))); break;
        case 3: _t->startWork(); break;
        case 4: _t->stopWork(); break;
        case 5: _t->run(); break;
        case 6: { bool _r = _t->isStart();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject serialWorkThreadPool_BMQ_A1::staticMetaObject = { {
    QMetaObject::SuperData::link<baseThreadPool::staticMetaObject>(),
    qt_meta_stringdata_serialWorkThreadPool_BMQ_A1.data,
    qt_meta_data_serialWorkThreadPool_BMQ_A1,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *serialWorkThreadPool_BMQ_A1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serialWorkThreadPool_BMQ_A1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_serialWorkThreadPool_BMQ_A1.stringdata0))
        return static_cast<void*>(this);
    return baseThreadPool::qt_metacast(_clname);
}

int serialWorkThreadPool_BMQ_A1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = baseThreadPool::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_serialWorkThreadPool_BMQ_XT_1_t {
    QByteArrayData data[15];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_serialWorkThreadPool_BMQ_XT_1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_serialWorkThreadPool_BMQ_XT_1_t qt_meta_stringdata_serialWorkThreadPool_BMQ_XT_1 = {
    {
QT_MOC_LITERAL(0, 0, 29), // "serialWorkThreadPool_BMQ_XT_1"
QT_MOC_LITERAL(1, 30, 8), // "slotWork"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 12), // "slotWorkData"
QT_MOC_LITERAL(4, 53, 3), // "COM"
QT_MOC_LITERAL(5, 57, 7), // "int32_t"
QT_MOC_LITERAL(6, 65, 3), // "duo"
QT_MOC_LITERAL(7, 69, 3), // "dan"
QT_MOC_LITERAL(8, 73, 15), // "slotMachineData"
QT_MOC_LITERAL(9, 89, 8), // "int32_t&"
QT_MOC_LITERAL(10, 98, 4), // "data"
QT_MOC_LITERAL(11, 103, 9), // "startWork"
QT_MOC_LITERAL(12, 113, 8), // "stopWork"
QT_MOC_LITERAL(13, 122, 3), // "run"
QT_MOC_LITERAL(14, 126, 7) // "isStart"

    },
    "serialWorkThreadPool_BMQ_XT_1\0slotWork\0"
    "\0slotWorkData\0COM\0int32_t\0duo\0dan\0"
    "slotMachineData\0int32_t&\0data\0startWork\0"
    "stopWork\0run\0isStart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_serialWorkThreadPool_BMQ_XT_1[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    3,   50,    2, 0x0a /* Public */,
       8,    1,   57,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      11,    0,   60,    2, 0x02 /* Public */,
      12,    0,   61,    2, 0x02 /* Public */,
      13,    0,   62,    2, 0x02 /* Public */,
      14,    0,   63,    2, 0x02 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 5, 0x80000000 | 5,    4,    6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,

       0        // eod
};

void serialWorkThreadPool_BMQ_XT_1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<serialWorkThreadPool_BMQ_XT_1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotWork(); break;
        case 1: _t->slotWorkData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int32_t(*)>(_a[2])),(*reinterpret_cast< int32_t(*)>(_a[3]))); break;
        case 2: _t->slotMachineData((*reinterpret_cast< int32_t(*)>(_a[1]))); break;
        case 3: _t->startWork(); break;
        case 4: _t->stopWork(); break;
        case 5: _t->run(); break;
        case 6: { bool _r = _t->isStart();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject serialWorkThreadPool_BMQ_XT_1::staticMetaObject = { {
    QMetaObject::SuperData::link<baseThreadPool::staticMetaObject>(),
    qt_meta_stringdata_serialWorkThreadPool_BMQ_XT_1.data,
    qt_meta_data_serialWorkThreadPool_BMQ_XT_1,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *serialWorkThreadPool_BMQ_XT_1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serialWorkThreadPool_BMQ_XT_1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_serialWorkThreadPool_BMQ_XT_1.stringdata0))
        return static_cast<void*>(this);
    return baseThreadPool::qt_metacast(_clname);
}

int serialWorkThreadPool_BMQ_XT_1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = baseThreadPool::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_serialWorkThreadPool_BMQ_XT_2_t {
    QByteArrayData data[15];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_serialWorkThreadPool_BMQ_XT_2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_serialWorkThreadPool_BMQ_XT_2_t qt_meta_stringdata_serialWorkThreadPool_BMQ_XT_2 = {
    {
QT_MOC_LITERAL(0, 0, 29), // "serialWorkThreadPool_BMQ_XT_2"
QT_MOC_LITERAL(1, 30, 8), // "slotWork"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 12), // "slotWorkData"
QT_MOC_LITERAL(4, 53, 3), // "COM"
QT_MOC_LITERAL(5, 57, 7), // "int32_t"
QT_MOC_LITERAL(6, 65, 3), // "duo"
QT_MOC_LITERAL(7, 69, 3), // "dan"
QT_MOC_LITERAL(8, 73, 15), // "slotMachineData"
QT_MOC_LITERAL(9, 89, 8), // "int32_t&"
QT_MOC_LITERAL(10, 98, 4), // "data"
QT_MOC_LITERAL(11, 103, 9), // "startWork"
QT_MOC_LITERAL(12, 113, 8), // "stopWork"
QT_MOC_LITERAL(13, 122, 3), // "run"
QT_MOC_LITERAL(14, 126, 7) // "isStart"

    },
    "serialWorkThreadPool_BMQ_XT_2\0slotWork\0"
    "\0slotWorkData\0COM\0int32_t\0duo\0dan\0"
    "slotMachineData\0int32_t&\0data\0startWork\0"
    "stopWork\0run\0isStart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_serialWorkThreadPool_BMQ_XT_2[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    3,   50,    2, 0x0a /* Public */,
       8,    1,   57,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      11,    0,   60,    2, 0x02 /* Public */,
      12,    0,   61,    2, 0x02 /* Public */,
      13,    0,   62,    2, 0x02 /* Public */,
      14,    0,   63,    2, 0x02 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 5, 0x80000000 | 5,    4,    6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,

       0        // eod
};

void serialWorkThreadPool_BMQ_XT_2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<serialWorkThreadPool_BMQ_XT_2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotWork(); break;
        case 1: _t->slotWorkData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int32_t(*)>(_a[2])),(*reinterpret_cast< int32_t(*)>(_a[3]))); break;
        case 2: _t->slotMachineData((*reinterpret_cast< int32_t(*)>(_a[1]))); break;
        case 3: _t->startWork(); break;
        case 4: _t->stopWork(); break;
        case 5: _t->run(); break;
        case 6: { bool _r = _t->isStart();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject serialWorkThreadPool_BMQ_XT_2::staticMetaObject = { {
    QMetaObject::SuperData::link<baseThreadPool::staticMetaObject>(),
    qt_meta_stringdata_serialWorkThreadPool_BMQ_XT_2.data,
    qt_meta_data_serialWorkThreadPool_BMQ_XT_2,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *serialWorkThreadPool_BMQ_XT_2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serialWorkThreadPool_BMQ_XT_2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_serialWorkThreadPool_BMQ_XT_2.stringdata0))
        return static_cast<void*>(this);
    return baseThreadPool::qt_metacast(_clname);
}

int serialWorkThreadPool_BMQ_XT_2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = baseThreadPool::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
