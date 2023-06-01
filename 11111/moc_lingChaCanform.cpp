/****************************************************************************
** Meta object code from reading C++ file 'lingChaCanform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../serialWorkTool/lingChaCanform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lingChaCanform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_lingChaCanform_t {
    QByteArrayData data[16];
    char stringdata0[296];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_lingChaCanform_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_lingChaCanform_t qt_meta_stringdata_lingChaCanform = {
    {
QT_MOC_LITERAL(0, 0, 14), // "lingChaCanform"
QT_MOC_LITERAL(1, 15, 19), // "slotRecvLingChaData"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 4), // "UINT"
QT_MOC_LITERAL(4, 41, 2), // "id"
QT_MOC_LITERAL(5, 44, 5), // "BYTE*"
QT_MOC_LITERAL(6, 50, 4), // "data"
QT_MOC_LITERAL(7, 55, 27), // "on_pushButton_start_clicked"
QT_MOC_LITERAL(8, 83, 26), // "on_pushButton_stop_clicked"
QT_MOC_LITERAL(9, 110, 31), // "on_pushButton_disenable_clicked"
QT_MOC_LITERAL(10, 142, 26), // "on_pushButton_sudu_clicked"
QT_MOC_LITERAL(11, 169, 30), // "on_pushButton_xiangdui_clicked"
QT_MOC_LITERAL(12, 200, 28), // "on_pushButton_juedui_clicked"
QT_MOC_LITERAL(13, 229, 28), // "on_pushButton_lianxu_clicked"
QT_MOC_LITERAL(14, 258, 9), // "slotTimer"
QT_MOC_LITERAL(15, 268, 27) // "on_pushButton_ceshi_clicked"

    },
    "lingChaCanform\0slotRecvLingChaData\0\0"
    "UINT\0id\0BYTE*\0data\0on_pushButton_start_clicked\0"
    "on_pushButton_stop_clicked\0"
    "on_pushButton_disenable_clicked\0"
    "on_pushButton_sudu_clicked\0"
    "on_pushButton_xiangdui_clicked\0"
    "on_pushButton_juedui_clicked\0"
    "on_pushButton_lianxu_clicked\0slotTimer\0"
    "on_pushButton_ceshi_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_lingChaCanform[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x0a /* Public */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,
      12,    0,   74,    2, 0x08 /* Private */,
      13,    0,   75,    2, 0x08 /* Private */,
      14,    0,   76,    2, 0x08 /* Private */,
      15,    0,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void lingChaCanform::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<lingChaCanform *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotRecvLingChaData((*reinterpret_cast< UINT(*)>(_a[1])),(*reinterpret_cast< BYTE*(*)>(_a[2]))); break;
        case 1: _t->on_pushButton_start_clicked(); break;
        case 2: _t->on_pushButton_stop_clicked(); break;
        case 3: _t->on_pushButton_disenable_clicked(); break;
        case 4: _t->on_pushButton_sudu_clicked(); break;
        case 5: _t->on_pushButton_xiangdui_clicked(); break;
        case 6: _t->on_pushButton_juedui_clicked(); break;
        case 7: _t->on_pushButton_lianxu_clicked(); break;
        case 8: _t->slotTimer(); break;
        case 9: _t->on_pushButton_ceshi_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject lingChaCanform::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_lingChaCanform.data,
    qt_meta_data_lingChaCanform,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *lingChaCanform::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *lingChaCanform::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_lingChaCanform.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int lingChaCanform::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
