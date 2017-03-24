/****************************************************************************
** Meta object code from reading C++ file 'ftpclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ftpclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ftpclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WNetworkFtp_t {
    QByteArrayData data[5];
    char stringdata0[45];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WNetworkFtp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WNetworkFtp_t qt_meta_stringdata_WNetworkFtp = {
    {
QT_MOC_LITERAL(0, 0, 11), // "WNetworkFtp"
QT_MOC_LITERAL(1, 12, 13), // "finishRequest"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 14), // "QNetworkReply*"
QT_MOC_LITERAL(4, 42, 2) // "in"

    },
    "WNetworkFtp\0finishRequest\0\0QNetworkReply*\0"
    "in"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WNetworkFtp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void WNetworkFtp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WNetworkFtp *_t = static_cast<WNetworkFtp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finishRequest((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

const QMetaObject WNetworkFtp::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WNetworkFtp.data,
      qt_meta_data_WNetworkFtp,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WNetworkFtp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WNetworkFtp::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WNetworkFtp.stringdata0))
        return static_cast<void*>(const_cast< WNetworkFtp*>(this));
    return QObject::qt_metacast(_clname);
}

int WNetworkFtp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_WNetworkFtpThread_t {
    QByteArrayData data[6];
    char stringdata0[44];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WNetworkFtpThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WNetworkFtpThread_t qt_meta_stringdata_WNetworkFtpThread = {
    {
QT_MOC_LITERAL(0, 0, 17), // "WNetworkFtpThread"
QT_MOC_LITERAL(1, 18, 9), // "allStoped"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 2), // "id"
QT_MOC_LITERAL(4, 32, 3), // "err"
QT_MOC_LITERAL(5, 36, 7) // "listGet"

    },
    "WNetworkFtpThread\0allStoped\0\0id\0err\0"
    "listGet"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WNetworkFtpThread[] = {

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
       1,    3,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QStringList,    3,    4,    5,

       0        // eod
};

void WNetworkFtpThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WNetworkFtpThread *_t = static_cast<WNetworkFtpThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->allStoped((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WNetworkFtpThread::*_t)(int , int , QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WNetworkFtpThread::allStoped)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject WNetworkFtpThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_WNetworkFtpThread.data,
      qt_meta_data_WNetworkFtpThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WNetworkFtpThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WNetworkFtpThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WNetworkFtpThread.stringdata0))
        return static_cast<void*>(const_cast< WNetworkFtpThread*>(this));
    return QThread::qt_metacast(_clname);
}

int WNetworkFtpThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void WNetworkFtpThread::allStoped(int _t1, int _t2, QStringList _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_WFtpClient_t {
    QByteArrayData data[16];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WFtpClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WFtpClient_t qt_meta_stringdata_WFtpClient = {
    {
QT_MOC_LITERAL(0, 0, 10), // "WFtpClient"
QT_MOC_LITERAL(1, 11, 9), // "sendError"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 6), // "sFiles"
QT_MOC_LITERAL(4, 29, 8), // "finished"
QT_MOC_LITERAL(5, 38, 12), // "finishedList"
QT_MOC_LITERAL(6, 51, 7), // "errorTo"
QT_MOC_LITERAL(7, 59, 11), // "reconToHost"
QT_MOC_LITERAL(8, 71, 11), // "doneURLInfo"
QT_MOC_LITERAL(9, 83, 8), // "QUrlInfo"
QT_MOC_LITERAL(10, 92, 7), // "urlInfo"
QT_MOC_LITERAL(11, 100, 12), // "ftpConnected"
QT_MOC_LITERAL(12, 113, 2), // "id"
QT_MOC_LITERAL(13, 116, 8), // "hasError"
QT_MOC_LITERAL(14, 125, 10), // "commFinish"
QT_MOC_LITERAL(15, 136, 6) // "hasBed"

    },
    "WFtpClient\0sendError\0\0sFiles\0finished\0"
    "finishedList\0errorTo\0reconToHost\0"
    "doneURLInfo\0QUrlInfo\0urlInfo\0ftpConnected\0"
    "id\0hasError\0commFinish\0hasBed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WFtpClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    1,   62,    2, 0x06 /* Public */,
       4,    1,   65,    2, 0x06 /* Public */,
       5,    2,   68,    2, 0x06 /* Public */,
       6,    0,   73,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   74,    2, 0x0a /* Public */,
       8,    1,   75,    2, 0x0a /* Public */,
      11,    2,   78,    2, 0x0a /* Public */,
      14,    2,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   12,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   12,   15,

       0        // eod
};

void WFtpClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WFtpClient *_t = static_cast<WFtpClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sFiles((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: _t->finished((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 3: _t->finishedList((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 4: _t->errorTo(); break;
        case 5: _t->reconToHost(); break;
        case 6: _t->doneURLInfo((*reinterpret_cast< QUrlInfo(*)>(_a[1]))); break;
        case 7: _t->ftpConnected((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 8: _t->commFinish((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WFtpClient::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WFtpClient::sendError)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WFtpClient::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WFtpClient::sFiles)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (WFtpClient::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WFtpClient::finished)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (WFtpClient::*_t)(QStringList , QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WFtpClient::finishedList)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (WFtpClient::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WFtpClient::errorTo)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject WFtpClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WFtpClient.data,
      qt_meta_data_WFtpClient,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WFtpClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WFtpClient::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WFtpClient.stringdata0))
        return static_cast<void*>(const_cast< WFtpClient*>(this));
    if (!strcmp(_clname, "WFtpFilter"))
        return static_cast< WFtpFilter*>(const_cast< WFtpClient*>(this));
    return QObject::qt_metacast(_clname);
}

int WFtpClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void WFtpClient::sendError(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WFtpClient::sFiles(QStringList _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WFtpClient::finished(QStringList _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void WFtpClient::finishedList(QStringList _t1, QStringList _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void WFtpClient::errorTo()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}
struct qt_meta_stringdata_WNetFtpClient_t {
    QByteArrayData data[8];
    char stringdata0[55];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WNetFtpClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WNetFtpClient_t qt_meta_stringdata_WNetFtpClient = {
    {
QT_MOC_LITERAL(0, 0, 13), // "WNetFtpClient"
QT_MOC_LITERAL(1, 14, 8), // "downStop"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 5), // "start"
QT_MOC_LITERAL(4, 30, 12), // "downloadStop"
QT_MOC_LITERAL(5, 43, 2), // "id"
QT_MOC_LITERAL(6, 46, 3), // "err"
QT_MOC_LITERAL(7, 50, 4) // "list"

    },
    "WNetFtpClient\0downStop\0\0start\0"
    "downloadStop\0id\0err\0list"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WNetFtpClient[] = {

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
       1,    3,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   36,    2, 0x0a /* Public */,
       4,    3,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QStringList,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QStringList,    5,    6,    7,

       0        // eod
};

void WNetFtpClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WNetFtpClient *_t = static_cast<WNetFtpClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->downStop((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 1: _t->start((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: _t->downloadStop((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WNetFtpClient::*_t)(int , int , QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WNetFtpClient::downStop)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject WNetFtpClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WNetFtpClient.data,
      qt_meta_data_WNetFtpClient,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WNetFtpClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WNetFtpClient::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WNetFtpClient.stringdata0))
        return static_cast<void*>(const_cast< WNetFtpClient*>(this));
    return QObject::qt_metacast(_clname);
}

int WNetFtpClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void WNetFtpClient::downStop(int _t1, int _t2, QStringList _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
