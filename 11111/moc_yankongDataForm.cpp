/****************************************************************************
** Meta object code from reading C++ file 'yankongDataForm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../serialWorkTool/yankongDataForm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'yankongDataForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_yankongDataForm_t {
    QByteArrayData data[16];
    char stringdata0[281];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_yankongDataForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_yankongDataForm_t qt_meta_stringdata_yankongDataForm = {
    {
QT_MOC_LITERAL(0, 0, 15), // "yankongDataForm"
QT_MOC_LITERAL(1, 16, 12), // "slotRecvData"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 4), // "UINT"
QT_MOC_LITERAL(4, 35, 2), // "id"
QT_MOC_LITERAL(5, 38, 5), // "BYTE*"
QT_MOC_LITERAL(6, 44, 4), // "data"
QT_MOC_LITERAL(7, 49, 32), // "on_pushButton_zhengzhuan_clicked"
QT_MOC_LITERAL(8, 82, 30), // "on_pushButton_fanzhuan_clicked"
QT_MOC_LITERAL(9, 113, 26), // "on_pushButton_stop_clicked"
QT_MOC_LITERAL(10, 140, 27), // "on_pushButton_start_clicked"
QT_MOC_LITERAL(11, 168, 28), // "on_pushButton_stop_2_clicked"
QT_MOC_LITERAL(12, 197, 31), // "on_horizontalSlider_sliderMoved"
QT_MOC_LITERAL(13, 229, 8), // "position"
QT_MOC_LITERAL(14, 238, 35), // "on_horizontalSlider_actionTri..."
QT_MOC_LITERAL(15, 274, 6) // "action"

    },
    "yankongDataForm\0slotRecvData\0\0UINT\0"
    "id\0BYTE*\0data\0on_pushButton_zhengzhuan_clicked\0"
    "on_pushButton_fanzhuan_clicked\0"
    "on_pushButton_stop_clicked\0"
    "on_pushButton_start_clicked\0"
    "on_pushButton_stop_2_clicked\0"
    "on_horizontalSlider_sliderMoved\0"
    "position\0on_horizontalSlider_actionTriggered\0"
    "action"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_yankongDataForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,
      10,    0,   62,    2, 0x08 /* Private */,
      11,    0,   63,    2, 0x08 /* Private */,
      12,    1,   64,    2, 0x08 /* Private */,
      14,    1,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   15,

       0        // eod
};

void yankongDataForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<yankongDataForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotRecvData((*reinterpret_cast< UINT(*)>(_a[1])),(*reinterpret_cast< BYTE*(*)>(_a[2]))); break;
        case 1: _t->on_pushButton_zhengzhuan_clicked(); break;
        case 2: _t->on_pushButton_fanzhuan_clicked(); break;
        case 3: _t->on_pushButton_stop_clicked(); break;
        case 4: _t->on_pushButton_start_clicked(); break;
        case 5: _t->on_pushButton_stop_2_clicked(); break;
        case 6: _t->on_horizontalSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_horizontalSlider_actionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject yankongDataForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_yankongDataForm.data,
    qt_meta_data_yankongDataForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *yankongDataForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *yankongDataForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_yankongDataForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int yankongDataForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
