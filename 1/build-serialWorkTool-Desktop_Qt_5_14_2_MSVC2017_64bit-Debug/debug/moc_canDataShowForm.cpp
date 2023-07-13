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
    QByteArrayData data[16];
    char stringdata0[402];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_canDataShowForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_canDataShowForm_t qt_meta_stringdata_canDataShowForm = {
    {
QT_MOC_LITERAL(0, 0, 15), // "canDataShowForm"
QT_MOC_LITERAL(1, 16, 26), // "on_pushButton_open_clicked"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 26), // "on_pushButton_send_clicked"
QT_MOC_LITERAL(4, 71, 31), // "on_pushButton_cleanData_clicked"
QT_MOC_LITERAL(5, 103, 27), // "on_pushButton_close_clicked"
QT_MOC_LITERAL(6, 131, 28), // "on_checkBox_autoSend_clicked"
QT_MOC_LITERAL(7, 160, 7), // "checked"
QT_MOC_LITERAL(8, 168, 27), // "on_checkBox_canrecv_clicked"
QT_MOC_LITERAL(9, 196, 27), // "on_checkBox_cansave_clicked"
QT_MOC_LITERAL(10, 224, 26), // "on_pushButton_init_clicked"
QT_MOC_LITERAL(11, 251, 30), // "on_pushButton_foreward_clicked"
QT_MOC_LITERAL(12, 282, 30), // "on_pushButton_reversal_clicked"
QT_MOC_LITERAL(13, 313, 28), // "on_pushButton_enable_clicked"
QT_MOC_LITERAL(14, 342, 32), // "on_pushButton_stopEnable_clicked"
QT_MOC_LITERAL(15, 375, 26) // "on_pushButton_mode_clicked"

    },
    "canDataShowForm\0on_pushButton_open_clicked\0"
    "\0on_pushButton_send_clicked\0"
    "on_pushButton_cleanData_clicked\0"
    "on_pushButton_close_clicked\0"
    "on_checkBox_autoSend_clicked\0checked\0"
    "on_checkBox_canrecv_clicked\0"
    "on_checkBox_cansave_clicked\0"
    "on_pushButton_init_clicked\0"
    "on_pushButton_foreward_clicked\0"
    "on_pushButton_reversal_clicked\0"
    "on_pushButton_enable_clicked\0"
    "on_pushButton_stopEnable_clicked\0"
    "on_pushButton_mode_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_canDataShowForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    1,   83,    2, 0x08 /* Private */,
       8,    1,   86,    2, 0x08 /* Private */,
       9,    1,   89,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    0,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void canDataShowForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<canDataShowForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_open_clicked(); break;
        case 1: _t->on_pushButton_send_clicked(); break;
        case 2: _t->on_pushButton_cleanData_clicked(); break;
        case 3: _t->on_pushButton_close_clicked(); break;
        case 4: _t->on_checkBox_autoSend_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_checkBox_canrecv_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_checkBox_cansave_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_pushButton_init_clicked(); break;
        case 8: _t->on_pushButton_foreward_clicked(); break;
        case 9: _t->on_pushButton_reversal_clicked(); break;
        case 10: _t->on_pushButton_enable_clicked(); break;
        case 11: _t->on_pushButton_stopEnable_clicked(); break;
        case 12: _t->on_pushButton_mode_clicked(); break;
        default: ;
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
