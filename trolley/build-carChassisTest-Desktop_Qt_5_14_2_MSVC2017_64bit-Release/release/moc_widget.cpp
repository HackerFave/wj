/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../carChassisTest/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[16];
    char stringdata0[281];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 12), // "slotRecvData"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 4), // "UINT"
QT_MOC_LITERAL(4, 26, 2), // "id"
QT_MOC_LITERAL(5, 29, 5), // "BYTE*"
QT_MOC_LITERAL(6, 35, 4), // "data"
QT_MOC_LITERAL(7, 40, 32), // "on_pushButton_zhengzhuan_clicked"
QT_MOC_LITERAL(8, 73, 30), // "on_pushButton_fanzhuan_clicked"
QT_MOC_LITERAL(9, 104, 26), // "on_pushButton_stop_clicked"
QT_MOC_LITERAL(10, 131, 31), // "on_horizontalSlider_sliderMoved"
QT_MOC_LITERAL(11, 163, 8), // "position"
QT_MOC_LITERAL(12, 172, 25), // "on_radioButton_up_clicked"
QT_MOC_LITERAL(13, 198, 27), // "on_radioButton_back_clicked"
QT_MOC_LITERAL(14, 226, 26), // "on_pushButton_back_clicked"
QT_MOC_LITERAL(15, 253, 27) // "on_pushButton_front_clicked"

    },
    "Widget\0slotRecvData\0\0UINT\0id\0BYTE*\0"
    "data\0on_pushButton_zhengzhuan_clicked\0"
    "on_pushButton_fanzhuan_clicked\0"
    "on_pushButton_stop_clicked\0"
    "on_horizontalSlider_sliderMoved\0"
    "position\0on_radioButton_up_clicked\0"
    "on_radioButton_back_clicked\0"
    "on_pushButton_back_clicked\0"
    "on_pushButton_front_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    1,   67,    2, 0x08 /* Private */,
      12,    0,   70,    2, 0x08 /* Private */,
      13,    0,   71,    2, 0x08 /* Private */,
      14,    0,   72,    2, 0x08 /* Private */,
      15,    0,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotRecvData((*reinterpret_cast< UINT(*)>(_a[1])),(*reinterpret_cast< BYTE*(*)>(_a[2]))); break;
        case 1: _t->on_pushButton_zhengzhuan_clicked(); break;
        case 2: _t->on_pushButton_fanzhuan_clicked(); break;
        case 3: _t->on_pushButton_stop_clicked(); break;
        case 4: _t->on_horizontalSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_radioButton_up_clicked(); break;
        case 6: _t->on_radioButton_back_clicked(); break;
        case 7: _t->on_pushButton_back_clicked(); break;
        case 8: _t->on_pushButton_front_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Widget.data,
    qt_meta_data_Widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE