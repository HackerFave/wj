/****************************************************************************
** Meta object code from reading C++ file 'canDataShowForm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../serialWorkTool/canDataShowForm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'canDataShowForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_canDataShowForm_t {
    QByteArrayData data[22];
    char stringdata0[338];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_canDataShowForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_canDataShowForm_t qt_meta_stringdata_canDataShowForm = {
    {
QT_MOC_LITERAL(0, 0, 15), // "canDataShowForm"
QT_MOC_LITERAL(1, 16, 16), // "signalDataToView"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 4), // "UINT"
QT_MOC_LITERAL(4, 39, 2), // "id"
QT_MOC_LITERAL(5, 42, 5), // "BYTE*"
QT_MOC_LITERAL(6, 48, 4), // "data"
QT_MOC_LITERAL(7, 53, 16), // "signalDataToForm"
QT_MOC_LITERAL(8, 70, 26), // "on_pushButton_open_clicked"
QT_MOC_LITERAL(9, 97, 26), // "on_pushButton_send_clicked"
QT_MOC_LITERAL(10, 124, 31), // "on_pushButton_cleanData_clicked"
QT_MOC_LITERAL(11, 156, 27), // "on_pushButton_close_clicked"
QT_MOC_LITERAL(12, 184, 28), // "on_checkBox_autoSend_clicked"
QT_MOC_LITERAL(13, 213, 7), // "checked"
QT_MOC_LITERAL(14, 221, 27), // "on_checkBox_canrecv_clicked"
QT_MOC_LITERAL(15, 249, 27), // "on_checkBox_cansave_clicked"
QT_MOC_LITERAL(16, 277, 21), // "slotRealTimeUpdateMsg"
QT_MOC_LITERAL(17, 299, 12), // "VCI_CAN_OBJ*"
QT_MOC_LITERAL(18, 312, 5), // "DWORD"
QT_MOC_LITERAL(19, 318, 3), // "len"
QT_MOC_LITERAL(20, 322, 3), // "can"
QT_MOC_LITERAL(21, 326, 11) // "slotOpenCan"

    },
    "canDataShowForm\0signalDataToView\0\0"
    "UINT\0id\0BYTE*\0data\0signalDataToForm\0"
    "on_pushButton_open_clicked\0"
    "on_pushButton_send_clicked\0"
    "on_pushButton_cleanData_clicked\0"
    "on_pushButton_close_clicked\0"
    "on_checkBox_autoSend_clicked\0checked\0"
    "on_checkBox_canrecv_clicked\0"
    "on_checkBox_cansave_clicked\0"
    "slotRealTimeUpdateMsg\0VCI_CAN_OBJ*\0"
    "DWORD\0len\0can\0slotOpenCan"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_canDataShowForm[] = {

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
       1,    2,   69,    2, 0x06 /* Public */,
       7,    2,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   79,    2, 0x08 /* Private */,
       9,    0,   80,    2, 0x08 /* Private */,
      10,    0,   81,    2, 0x08 /* Private */,
      11,    0,   82,    2, 0x08 /* Private */,
      12,    1,   83,    2, 0x08 /* Private */,
      14,    1,   86,    2, 0x08 /* Private */,
      15,    1,   89,    2, 0x08 /* Private */,
      16,    3,   92,    2, 0x08 /* Private */,
      21,    1,   99,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, 0x80000000 | 17, 0x80000000 | 18, QMetaType::Short,    6,   19,   20,
    QMetaType::Void, QMetaType::Short,    2,

       0        // eod
};

void canDataShowForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<canDataShowForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalDataToView((*reinterpret_cast< UINT(*)>(_a[1])),(*reinterpret_cast< BYTE*(*)>(_a[2]))); break;
        case 1: _t->signalDataToForm((*reinterpret_cast< UINT(*)>(_a[1])),(*reinterpret_cast< BYTE*(*)>(_a[2]))); break;
        case 2: _t->on_pushButton_open_clicked(); break;
        case 3: _t->on_pushButton_send_clicked(); break;
        case 4: _t->on_pushButton_cleanData_clicked(); break;
        case 5: _t->on_pushButton_close_clicked(); break;
        case 6: _t->on_checkBox_autoSend_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_checkBox_canrecv_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_checkBox_cansave_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->slotRealTimeUpdateMsg((*reinterpret_cast< VCI_CAN_OBJ*(*)>(_a[1])),(*reinterpret_cast< DWORD(*)>(_a[2])),(*reinterpret_cast< short(*)>(_a[3]))); break;
        case 10: _t->slotOpenCan((*reinterpret_cast< short(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (canDataShowForm::*)(UINT , BYTE * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&canDataShowForm::signalDataToView)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (canDataShowForm::*)(UINT , BYTE * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&canDataShowForm::signalDataToForm)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject canDataShowForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_canDataShowForm.data,
    qt_meta_data_canDataShowForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *canDataShowForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *canDataShowForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_canDataShowForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int canDataShowForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void canDataShowForm::signalDataToView(UINT _t1, BYTE * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void canDataShowForm::signalDataToForm(UINT _t1, BYTE * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
