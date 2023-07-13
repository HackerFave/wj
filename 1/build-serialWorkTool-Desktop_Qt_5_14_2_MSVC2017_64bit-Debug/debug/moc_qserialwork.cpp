/****************************************************************************
** Meta object code from reading C++ file 'qserialwork.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../serialWorkTool/methord/qserialwork.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qserialwork.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QSerialWork_t {
    QByteArrayData data[18];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSerialWork_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSerialWork_t qt_meta_stringdata_QSerialWork = {
    {
QT_MOC_LITERAL(0, 0, 11), // "QSerialWork"
QT_MOC_LITERAL(1, 12, 7), // "NewData"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 4), // "data"
QT_MOC_LITERAL(4, 26, 5), // "State"
QT_MOC_LITERAL(5, 32, 3), // "err"
QT_MOC_LITERAL(6, 36, 8), // "OpenPort"
QT_MOC_LITERAL(7, 45, 8), // "portName"
QT_MOC_LITERAL(8, 54, 21), // "QSerialPort::BaudRate"
QT_MOC_LITERAL(9, 76, 4), // "flag"
QT_MOC_LITERAL(10, 81, 21), // "QSerialPort::DataBits"
QT_MOC_LITERAL(11, 103, 3), // "bit"
QT_MOC_LITERAL(12, 107, 9), // "ClosePort"
QT_MOC_LITERAL(13, 117, 9), // "WriteData"
QT_MOC_LITERAL(14, 127, 3), // "buf"
QT_MOC_LITERAL(15, 131, 3), // "len"
QT_MOC_LITERAL(16, 135, 10), // "timeUpdate"
QT_MOC_LITERAL(17, 146, 11) // "DataArrived"

    },
    "QSerialWork\0NewData\0\0data\0State\0err\0"
    "OpenPort\0portName\0QSerialPort::BaudRate\0"
    "flag\0QSerialPort::DataBits\0bit\0ClosePort\0"
    "WriteData\0buf\0len\0timeUpdate\0DataArrived"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSerialWork[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    3,   55,    2, 0x0a /* Public */,
      12,    0,   62,    2, 0x0a /* Public */,
      13,    2,   63,    2, 0x0a /* Public */,
      16,    0,   68,    2, 0x0a /* Public */,
      17,    0,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 8, 0x80000000 | 10,    7,    9,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::LongLong,   14,   15,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QSerialWork::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QSerialWork *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->NewData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->State((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->OpenPort((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QSerialPort::BaudRate(*)>(_a[2])),(*reinterpret_cast< QSerialPort::DataBits(*)>(_a[3]))); break;
        case 3: _t->ClosePort(); break;
        case 4: _t->WriteData((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 5: _t->timeUpdate(); break;
        case 6: _t->DataArrived(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QSerialWork::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QSerialWork::NewData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QSerialWork::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QSerialWork::State)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QSerialWork::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_QSerialWork.data,
    qt_meta_data_QSerialWork,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QSerialWork::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSerialWork::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSerialWork.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QSerialWork::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QSerialWork::NewData(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QSerialWork::State(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
