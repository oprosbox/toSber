/****************************************************************************
** Meta object code from reading C++ file 'winterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../winterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'winterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WInterface_t {
    QByteArrayData data[9];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WInterface_t qt_meta_stringdata_WInterface = {
    {
QT_MOC_LITERAL(0, 0, 10), // "WInterface"
QT_MOC_LITERAL(1, 11, 17), // "createTableReport"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 12), // "refreshTable"
QT_MOC_LITERAL(4, 43, 15), // "createBigReport"
QT_MOC_LITERAL(5, 59, 16), // "createDataReport"
QT_MOC_LITERAL(6, 76, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(7, 94, 4), // "item"
QT_MOC_LITERAL(8, 99, 18) // "createDishonReport"

    },
    "WInterface\0createTableReport\0\0"
    "refreshTable\0createBigReport\0"
    "createDataReport\0QTableWidgetItem*\0"
    "item\0createDishonReport"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WInterface[] = {

 // content:
       7,       // revision
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
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    1,   42,    2, 0x0a /* Public */,
       8,    1,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void WInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WInterface *_t = static_cast<WInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->createTableReport(); break;
        case 1: _t->refreshTable(); break;
        case 2: _t->createBigReport(); break;
        case 3: _t->createDataReport((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->createDishonReport((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject WInterface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WInterface.data,
      qt_meta_data_WInterface,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WInterface.stringdata0))
        return static_cast<void*>(const_cast< WInterface*>(this));
    return QObject::qt_metacast(_clname);
}

int WInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
