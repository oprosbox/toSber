/****************************************************************************
** Meta object code from reading C++ file 'findindom.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../findindom.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'findindom.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ndom__WFindThr_t {
    QByteArrayData data[6];
    char stringdata0[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ndom__WFindThr_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ndom__WFindThr_t qt_meta_stringdata_ndom__WFindThr = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ndom::WFindThr"
QT_MOC_LITERAL(1, 15, 10), // "threadStop"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 9), // "sAllFiles"
QT_MOC_LITERAL(4, 37, 9), // "findFiles"
QT_MOC_LITERAL(5, 47, 9) // "stopedThr"

    },
    "ndom::WFindThr\0threadStop\0\0sAllFiles\0"
    "findFiles\0stopedThr"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ndom__WFindThr[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       3,    1,   37,    2, 0x06 /* Public */,
       4,    1,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QStringList,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void ndom::WFindThr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WFindThr *_t = static_cast<WFindThr *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->threadStop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sAllFiles((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: _t->findFiles((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 3: _t->stopedThr(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WFindThr::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WFindThr::threadStop)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WFindThr::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WFindThr::sAllFiles)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (WFindThr::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WFindThr::findFiles)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject ndom::WFindThr::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ndom__WFindThr.data,
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
    return QThread::qt_metacast(_clname);
}

int ndom::WFindThr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ndom::WFindThr::threadStop(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ndom::WFindThr::sAllFiles(QStringList _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ndom::WFindThr::findFiles(QStringList _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_ndom__WFindThrExp_t {
    QByteArrayData data[4];
    char stringdata0[40];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ndom__WFindThrExp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ndom__WFindThrExp_t qt_meta_stringdata_ndom__WFindThrExp = {
    {
QT_MOC_LITERAL(0, 0, 17), // "ndom::WFindThrExp"
QT_MOC_LITERAL(1, 18, 10), // "threadStop"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 9) // "stopedThr"

    },
    "ndom::WFindThrExp\0threadStop\0\0stopedThr"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ndom__WFindThrExp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void ndom::WFindThrExp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WFindThrExp *_t = static_cast<WFindThrExp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->threadStop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->stopedThr(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WFindThrExp::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WFindThrExp::threadStop)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ndom::WFindThrExp::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ndom__WFindThrExp.data,
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
    return QThread::qt_metacast(_clname);
}

int ndom::WFindThrExp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ndom::WFindThrExp::threadStop(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_ndom__WFind_t {
    QByteArrayData data[7];
    char stringdata0[83];
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
QT_MOC_LITERAL(4, 44, 13), // "getSignalStop"
QT_MOC_LITERAL(5, 58, 19), // "allThreadsFormLists"
QT_MOC_LITERAL(6, 78, 4) // "list"

    },
    "ndom::WFind\0allThreadsStop\0\0allThreadsLists\0"
    "getSignalStop\0allThreadsFormLists\0"
    "list"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ndom__WFind[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       3,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   40,    2, 0x0a /* Public */,
       5,    1,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QStringList,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QStringList,    6,

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
        case 2: _t->getSignalStop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->allThreadsFormLists((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
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
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
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
