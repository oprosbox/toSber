/****************************************************************************
** Meta object code from reading C++ file 'findindom.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../findindom.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'findindom.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ndom__WFindThr_t {
    QByteArrayData data[3];
    char stringdata0[25];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ndom__WFindThr_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ndom__WFindThr_t qt_meta_stringdata_ndom__WFindThr = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ndom::WFindThr"
QT_MOC_LITERAL(1, 15, 8), // "finished"
QT_MOC_LITERAL(2, 24, 0) // ""

    },
    "ndom::WFindThr\0finished\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ndom__WFindThr[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void ndom::WFindThr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WFindThr *_t = static_cast<WFindThr *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WFindThr::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WFindThr::finished)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ndom::WFindThr::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ndom__WFindThr.data,
      qt_meta_data_ndom__WFindThr,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ndom::WFindThr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ndom::WFindThr::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ndom__WFindThr.stringdata0))
        return static_cast<void*>(const_cast< WFindThr*>(this));
    return QObject::qt_metacast(_clname);
}

int ndom::WFindThr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ndom::WFindThr::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_ndom__WFindThrExp_t {
    QByteArrayData data[3];
    char stringdata0[28];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ndom__WFindThrExp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ndom__WFindThrExp_t qt_meta_stringdata_ndom__WFindThrExp = {
    {
QT_MOC_LITERAL(0, 0, 17), // "ndom::WFindThrExp"
QT_MOC_LITERAL(1, 18, 8), // "finished"
QT_MOC_LITERAL(2, 27, 0) // ""

    },
    "ndom::WFindThrExp\0finished\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ndom__WFindThrExp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void ndom::WFindThrExp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WFindThrExp *_t = static_cast<WFindThrExp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WFindThrExp::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WFindThrExp::finished)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ndom::WFindThrExp::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ndom__WFindThrExp.data,
      qt_meta_data_ndom__WFindThrExp,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ndom::WFindThrExp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ndom::WFindThrExp::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ndom__WFindThrExp.stringdata0))
        return static_cast<void*>(const_cast< WFindThrExp*>(this));
    return QObject::qt_metacast(_clname);
}

int ndom::WFindThrExp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ndom::WFindThrExp::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_ndom__WFind_t {
    QByteArrayData data[5];
    char stringdata0[58];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ndom__WFind_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ndom__WFind_t qt_meta_stringdata_ndom__WFind = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ndom::WFind"
QT_MOC_LITERAL(1, 12, 14), // "allThreadsStop"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 15), // "allThreadsLists"
QT_MOC_LITERAL(4, 44, 13) // "getSignalStop"

    },
    "ndom::WFind\0allThreadsStop\0\0allThreadsLists\0"
    "getSignalStop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ndom__WFind[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       3,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QStringList,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void ndom::WFind::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WFind *_t = static_cast<WFind *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->allThreadsStop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->allThreadsLists((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: _t->getSignalStop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WFind::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WFind::allThreadsStop)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WFind::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WFind::allThreadsLists)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ndom::WFind::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ndom__WFind.data,
      qt_meta_data_ndom__WFind,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ndom::WFind::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ndom::WFind::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ndom__WFind.stringdata0))
        return static_cast<void*>(const_cast< WFind*>(this));
    return QObject::qt_metacast(_clname);
}

int ndom::WFind::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ndom::WFind::allThreadsStop(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ndom::WFind::allThreadsLists(QStringList _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
