/****************************************************************************
** Meta object code from reading C++ file 'datashowform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../serialWorkTool/datashowform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datashowform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_dataShowForm_t {
    QByteArrayData data[13];
    char stringdata0[232];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dataShowForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dataShowForm_t qt_meta_stringdata_dataShowForm = {
    {
QT_MOC_LITERAL(0, 0, 12), // "dataShowForm"
QT_MOC_LITERAL(1, 13, 12), // "signalStatus"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 29), // "on_pushButton_connect_clicked"
QT_MOC_LITERAL(4, 57, 9), // "slotState"
QT_MOC_LITERAL(5, 67, 3), // "err"
QT_MOC_LITERAL(6, 71, 26), // "on_pushButton_send_clicked"
QT_MOC_LITERAL(7, 98, 11), // "slotNewData"
QT_MOC_LITERAL(8, 110, 4), // "data"
QT_MOC_LITERAL(9, 115, 32), // "on_pushButton_disconnect_clicked"
QT_MOC_LITERAL(10, 148, 25), // "on_pushButton_sum_clicked"
QT_MOC_LITERAL(11, 174, 27), // "on_pushButton_sum_2_clicked"
QT_MOC_LITERAL(12, 202, 29) // "on_pushButton_sum_asc_clicked"

    },
    "dataShowForm\0signalStatus\0\0"
    "on_pushButton_connect_clicked\0slotState\0"
    "err\0on_pushButton_send_clicked\0"
    "slotNewData\0data\0on_pushButton_disconnect_clicked\0"
    "on_pushButton_sum_clicked\0"
    "on_pushButton_sum_2_clicked\0"
    "on_pushButton_sum_asc_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dataShowForm[] = {

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
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   62,    2, 0x08 /* Private */,
       4,    1,   63,    2, 0x08 /* Private */,
       6,    0,   66,    2, 0x08 /* Private */,
       7,    1,   67,    2, 0x08 /* Private */,
       9,    0,   70,    2, 0x08 /* Private */,
      10,    0,   71,    2, 0x08 /* Private */,
      11,    0,   72,    2, 0x08 /* Private */,
      12,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void dataShowForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<dataShowForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_connect_clicked(); break;
        case 2: _t->slotState((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_send_clicked(); break;
        case 4: _t->slotNewData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: _t->on_pushButton_disconnect_clicked(); break;
        case 6: _t->on_pushButton_sum_clicked(); break;
        case 7: _t->on_pushButton_sum_2_clicked(); break;
        case 8: _t->on_pushButton_sum_asc_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (dataShowForm::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&dataShowForm::signalStatus)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject dataShowForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_dataShowForm.data,
    qt_meta_data_dataShowForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *dataShowForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dataShowForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dataShowForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int dataShowForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void dataShowForm::signalStatus(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
