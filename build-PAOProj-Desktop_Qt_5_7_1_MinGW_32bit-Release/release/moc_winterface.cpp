/****************************************************************************
** Meta object code from reading C++ file 'winterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../downloadToDisk/winterface.h"
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
    QByteArrayData data[16];
    char stringdata0[200];
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
QT_MOC_LITERAL(4, 43, 16), // "refreshTableComm"
QT_MOC_LITERAL(5, 60, 4), // "comm"
QT_MOC_LITERAL(6, 65, 19), // "getDishonContrTable"
QT_MOC_LITERAL(7, 85, 15), // "createBigReport"
QT_MOC_LITERAL(8, 101, 16), // "createDataReport"
QT_MOC_LITERAL(9, 118, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(10, 136, 4), // "item"
QT_MOC_LITERAL(11, 141, 18), // "createDishonReport"
QT_MOC_LITERAL(12, 160, 18), // "refreshTableByList"
QT_MOC_LITERAL(13, 179, 9), // "sortTable"
QT_MOC_LITERAL(14, 189, 3), // "ind"
QT_MOC_LITERAL(15, 193, 6) // "addInn"

    },
    "WInterface\0createTableReport\0\0"
    "refreshTable\0refreshTableComm\0comm\0"
    "getDishonContrTable\0createBigReport\0"
    "createDataReport\0QTableWidgetItem*\0"
    "item\0createDishonReport\0refreshTableByList\0"
    "sortTable\0ind\0addInn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a /* Public */,
       3,    0,   65,    2, 0x0a /* Public */,
       4,    1,   66,    2, 0x0a /* Public */,
       6,    0,   69,    2, 0x0a /* Public */,
       7,    0,   70,    2, 0x0a /* Public */,
       8,    1,   71,    2, 0x0a /* Public */,
      11,    1,   74,    2, 0x0a /* Public */,
      12,    0,   77,    2, 0x0a /* Public */,
      13,    1,   78,    2, 0x0a /* Public */,
      15,    1,   81,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, 0x80000000 | 9,   10,

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
        case 2: _t->refreshTableComm((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->getDishonContrTable(); break;
        case 4: _t->createBigReport(); break;
        case 5: _t->createDataReport((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 6: _t->createDishonReport((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 7: _t->refreshTableByList(); break;
        case 8: _t->sortTable((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->addInn((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
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
QT_END_MOC_NAMESPACE
