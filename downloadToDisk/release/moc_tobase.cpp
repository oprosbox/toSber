/****************************************************************************
** Meta object code from reading C++ file 'tobase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tobase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tobase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WBaseWR_t {
    QByteArrayData data[7];
    char stringdata0[63];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WBaseWR_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WBaseWR_t qt_meta_stringdata_WBaseWR = {
    {
QT_MOC_LITERAL(0, 0, 7), // "WBaseWR"
QT_MOC_LITERAL(1, 8, 8), // "getError"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 5), // "error"
QT_MOC_LITERAL(4, 24, 12), // "writeToNotif"
QT_MOC_LITERAL(5, 37, 11), // "findObjects"
QT_MOC_LITERAL(6, 49, 13) // "writeToDishon"

    },
    "WBaseWR\0getError\0\0error\0writeToNotif\0"
    "findObjects\0writeToDishon"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WBaseWR[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   32,    2, 0x0a /* Public */,
       6,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Bool, QMetaType::QStringList,    5,
    QMetaType::Bool, QMetaType::QStringList,    5,

       0        // eod
};

void WBaseWR::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WBaseWR *_t = static_cast<WBaseWR *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: { bool _r = _t->writeToNotif((*reinterpret_cast< QStringList(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { bool _r = _t->writeToDishon((*reinterpret_cast< QStringList(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WBaseWR::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WBaseWR::getError)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject WBaseWR::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WBaseWR.data,
      qt_meta_data_WBaseWR,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WBaseWR::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WBaseWR::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WBaseWR.stringdata0))
        return static_cast<void*>(const_cast< WBaseWR*>(this));
    if (!strcmp(_clname, "WToBASE"))
        return static_cast< WToBASE*>(const_cast< WBaseWR*>(this));
    return QObject::qt_metacast(_clname);
}

int WBaseWR::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void WBaseWR::getError(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
