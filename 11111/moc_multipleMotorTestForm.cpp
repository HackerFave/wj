/****************************************************************************
** Meta object code from reading C++ file 'multipleMotorTestForm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../serialWorkTool/multipleMotorTestForm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'multipleMotorTestForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_multipleMotorTestForm_t {
    QByteArrayData data[11];
    char stringdata0[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_multipleMotorTestForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_multipleMotorTestForm_t qt_meta_stringdata_multipleMotorTestForm = {
    {
QT_MOC_LITERAL(0, 0, 21), // "multipleMotorTestForm"
QT_MOC_LITERAL(1, 22, 14), // "signalValue_A2"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 7), // "int32_t"
QT_MOC_LITERAL(4, 46, 12), // "duoquanvalue"
QT_MOC_LITERAL(5, 59, 12), // "danquanvalue"
QT_MOC_LITERAL(6, 72, 14), // "signalValue_A3"
QT_MOC_LITERAL(7, 87, 14), // "signalValue_A4"
QT_MOC_LITERAL(8, 102, 14), // "signalValue_A8"
QT_MOC_LITERAL(9, 117, 37), // "on_pushButton_writeConfig_max..."
QT_MOC_LITERAL(10, 155, 37) // "on_pushButton_writeConfig_min..."

    },
    "multipleMotorTestForm\0signalValue_A2\0"
    "\0int32_t\0duoquanvalue\0danquanvalue\0"
    "signalValue_A3\0signalValue_A4\0"
    "signalValue_A8\0on_pushButton_writeConfig_max_clicked\0"
    "on_pushButton_writeConfig_min_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_multipleMotorTestForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       6,    2,   49,    2, 0x06 /* Public */,
       7,    2,   54,    2, 0x06 /* Public */,
       8,    2,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   64,    2, 0x08 /* Private */,
      10,    0,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void multipleMotorTestForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<multipleMotorTestForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalValue_A2((*reinterpret_cast< int32_t(*)>(_a[1])),(*reinterpret_cast< int32_t(*)>(_a[2]))); break;
        case 1: _t->signalValue_A3((*reinterpret_cast< int32_t(*)>(_a[1])),(*reinterpret_cast< int32_t(*)>(_a[2]))); break;
        case 2: _t->signalValue_A4((*reinterpret_cast< int32_t(*)>(_a[1])),(*reinterpret_cast< int32_t(*)>(_a[2]))); break;
        case 3: _t->signalValue_A8((*reinterpret_cast< int32_t(*)>(_a[1])),(*reinterpret_cast< int32_t(*)>(_a[2]))); break;
        case 4: _t->on_pushButton_writeConfig_max_clicked(); break;
        case 5: _t->on_pushButton_writeConfig_min_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (multipleMotorTestForm::*)(int32_t , int32_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&multipleMotorTestForm::signalValue_A2)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (multipleMotorTestForm::*)(int32_t , int32_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&multipleMotorTestForm::signalValue_A3)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (multipleMotorTestForm::*)(int32_t , int32_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&multipleMotorTestForm::signalValue_A4)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (multipleMotorTestForm::*)(int32_t , int32_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&multipleMotorTestForm::signalValue_A8)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject multipleMotorTestForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_multipleMotorTestForm.data,
    qt_meta_data_multipleMotorTestForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *multipleMotorTestForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *multipleMotorTestForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_multipleMotorTestForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int multipleMotorTestForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void multipleMotorTestForm::signalValue_A2(int32_t _t1, int32_t _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void multipleMotorTestForm::signalValue_A3(int32_t _t1, int32_t _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void multipleMotorTestForm::signalValue_A4(int32_t _t1, int32_t _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void multipleMotorTestForm::signalValue_A8(int32_t _t1, int32_t _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
