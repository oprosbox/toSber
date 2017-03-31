/****************************************************************************
** Meta object code from reading C++ file 'loadsave.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../loadsave.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loadsave.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ftpload__WLoadZip_t {
    QByteArrayData data[7];
    char stringdata0[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ftpload__WLoadZip_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ftpload__WLoadZip_t qt_meta_stringdata_ftpload__WLoadZip = {
    {
QT_MOC_LITERAL(0, 0, 17), // "ftpload::WLoadZip"
QT_MOC_LITERAL(1, 18, 14), // "allObjectsStop"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 12), // "signAddFiles"
QT_MOC_LITERAL(4, 47, 13), // "delObjThreads"
QT_MOC_LITERAL(5, 61, 2), // "id"
QT_MOC_LITERAL(6, 64, 13) // "formListFiles"

    },
    "ftpload::WLoadZip\0allObjectsStop\0\0"
    "signAddFiles\0delObjThreads\0id\0"
    "formListFiles"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ftpload__WLoadZip[] = {

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
       6,    1,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QStringList,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QStringList,    2,

       0        // eod
};

void ftpload::WLoadZip::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WLoadZip *_t = static_cast<WLoadZip *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->allObjectsStop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->signAddFiles((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: _t->delObjThreads((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->formListFiles((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WLoadZip::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WLoadZip::allObjectsStop)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WLoadZip::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WLoadZip::signAddFiles)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ftpload::WLoadZip::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ftpload__WLoadZip.data,
      qt_meta_data_ftpload__WLoadZip,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ftpload::WLoadZip::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ftpload::WLoadZip::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ftpload__WLoadZip.stringdata0))
        return static_cast<void*>(const_cast< WLoadZip*>(this));
    if (!strcmp(_clname, "WPackUnpack7z"))
        return static_cast< WPackUnpack7z*>(const_cast< WLoadZip*>(this));
    return QObject::qt_metacast(_clname);
}

int ftpload::WLoadZip::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ftpload::WLoadZip::allObjectsStop(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ftpload::WLoadZip::signAddFiles(QStringList _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_ftpload__WLoadZipThread_t {
    QByteArrayData data[1];
    char stringdata0[24];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ftpload__WLoadZipThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ftpload__WLoadZipThread_t qt_meta_stringdata_ftpload__WLoadZipThread = {
    {
QT_MOC_LITERAL(0, 0, 23) // "ftpload::WLoadZipThread"

    },
    "ftpload::WLoadZipThread"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ftpload__WLoadZipThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void ftpload::WLoadZipThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject ftpload::WLoadZipThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ftpload__WLoadZipThread.data,
      qt_meta_data_ftpload__WLoadZipThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ftpload::WLoadZipThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ftpload::WLoadZipThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ftpload__WLoadZipThread.stringdata0))
        return static_cast<void*>(const_cast< WLoadZipThread*>(this));
    return QThread::qt_metacast(_clname);
}

int ftpload::WLoadZipThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_ftpload__WLoadFtp_t {
    QByteArrayData data[15];
    char stringdata0[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ftpload__WLoadFtp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ftpload__WLoadFtp_t qt_meta_stringdata_ftpload__WLoadFtp = {
    {
QT_MOC_LITERAL(0, 0, 17), // "ftpload::WLoadFtp"
QT_MOC_LITERAL(1, 18, 9), // "sGetFiles"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 16), // "getDownloadFiles"
QT_MOC_LITERAL(4, 46, 3), // "err"
QT_MOC_LITERAL(5, 50, 5), // "files"
QT_MOC_LITERAL(6, 56, 16), // "allFilesDownload"
QT_MOC_LITERAL(7, 73, 15), // "allFilesProcess"
QT_MOC_LITERAL(8, 89, 8), // "download"
QT_MOC_LITERAL(9, 98, 7), // "endLoad"
QT_MOC_LITERAL(10, 106, 10), // "nextUnpack"
QT_MOC_LITERAL(11, 117, 15), // "getProcessFiles"
QT_MOC_LITERAL(12, 133, 9), // "procFiles"
QT_MOC_LITERAL(13, 143, 17), // "delObjectThatStop"
QT_MOC_LITERAL(14, 161, 2) // "id"

    },
    "ftpload::WLoadFtp\0sGetFiles\0\0"
    "getDownloadFiles\0err\0files\0allFilesDownload\0"
    "allFilesProcess\0download\0endLoad\0"
    "nextUnpack\0getProcessFiles\0procFiles\0"
    "delObjectThatStop\0id"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ftpload__WLoadFtp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    2,   62,    2, 0x06 /* Public */,
       6,    1,   67,    2, 0x06 /* Public */,
       7,    1,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   73,    2, 0x0a /* Public */,
       9,    0,   74,    2, 0x0a /* Public */,
      10,    2,   75,    2, 0x0a /* Public */,
      11,    1,   80,    2, 0x0a /* Public */,
      13,    1,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QStringList,    4,    5,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QStringList,    2,    5,
    QMetaType::Void, QMetaType::QStringList,   12,
    QMetaType::Void, QMetaType::Int,   14,

       0        // eod
};

void ftpload::WLoadFtp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WLoadFtp *_t = static_cast<WLoadFtp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sGetFiles((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 1: _t->getDownloadFiles((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 2: _t->allFilesDownload((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->allFilesProcess((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->download(); break;
        case 5: _t->endLoad(); break;
        case 6: _t->nextUnpack((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 7: _t->getProcessFiles((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 8: _t->delObjectThatStop((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WLoadFtp::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WLoadFtp::sGetFiles)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WLoadFtp::*_t)(int , QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WLoadFtp::getDownloadFiles)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (WLoadFtp::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WLoadFtp::allFilesDownload)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (WLoadFtp::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WLoadFtp::allFilesProcess)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject ftpload::WLoadFtp::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ftpload__WLoadFtp.data,
      qt_meta_data_ftpload__WLoadFtp,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ftpload::WLoadFtp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ftpload::WLoadFtp::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ftpload__WLoadFtp.stringdata0))
        return static_cast<void*>(const_cast< WLoadFtp*>(this));
    return QObject::qt_metacast(_clname);
}

int ftpload::WLoadFtp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void ftpload::WLoadFtp::sGetFiles(QStringList _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ftpload::WLoadFtp::getDownloadFiles(int _t1, QStringList _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ftpload::WLoadFtp::allFilesDownload(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ftpload::WLoadFtp::allFilesProcess(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
