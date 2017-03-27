/****************************************************************************
** Meta object code from reading C++ file 'ftpclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../downloadToDisk/ftpclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ftpclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WNetworkFtp_t {
    QByteArrayData data[11];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WNetworkFtp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WNetworkFtp_t qt_meta_stringdata_WNetworkFtp = {
    {
QT_MOC_LITERAL(0, 0, 11), // "WNetworkFtp"
QT_MOC_LITERAL(1, 12, 9), // "emit10Obj"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 3), // "err"
QT_MOC_LITERAL(4, 27, 7), // "listGet"
QT_MOC_LITERAL(5, 35, 9), // "errorEmit"
QT_MOC_LITERAL(6, 45, 13), // "finishRequest"
QT_MOC_LITERAL(7, 59, 14), // "QNetworkReply*"
QT_MOC_LITERAL(8, 74, 2), // "in"
QT_MOC_LITERAL(9, 77, 6), // "errors"
QT_MOC_LITERAL(10, 84, 27) // "QNetworkReply::NetworkError"

    },
    "WNetworkFtp\0emit10Obj\0\0err\0listGet\0"
    "errorEmit\0finishRequest\0QNetworkReply*\0"
    "in\0errors\0QNetworkReply::NetworkError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WNetworkFtp[] = {

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
       1,    2,   34,    2, 0x06 /* Public */,
       5,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   40,    2, 0x0a /* Public */,
       9,    1,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QStringList,    3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 10,    2,

       0        // eod
};

void WNetworkFtp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WNetworkFtp *_t = static_cast<WNetworkFtp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->emit10Obj((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 1: _t->errorEmit(); break;
        case 2: _t->finishRequest((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: _t->errors((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WNetworkFtp::*_t)(int , QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WNetworkFtp::emit10Obj)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WNetworkFtp::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WNetworkFtp::errorEmit)) {
                *result = 1;
                return;
            }
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
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void WNetworkFtp::emit10Obj(int _t1, QStringList _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WNetworkFtp::errorEmit()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
struct qt_meta_stringdata_WNetworkFtpThread_t {
    QByteArrayData data[5];
    char stringdata0[41];
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
QT_MOC_LITERAL(3, 29, 3), // "err"
QT_MOC_LITERAL(4, 33, 7) // "listGet"

    },
    "WNetworkFtpThread\0allStoped\0\0err\0"
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
       1,    2,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QStringList,    3,    4,

       0        // eod
};

void WNetworkFtpThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WNetworkFtpThread *_t = static_cast<WNetworkFtpThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->allStoped((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WNetworkFtpThread::*_t)(int , QStringList );
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
void WNetworkFtpThread::allStoped(int _t1, QStringList _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_WFtpClient_t {
    QByteArrayData data[17];
    char stringdata0[147];
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
QT_MOC_LITERAL(4, 29, 3), // "err"
QT_MOC_LITERAL(5, 33, 8), // "finished"
QT_MOC_LITERAL(6, 42, 12), // "finishedList"
QT_MOC_LITERAL(7, 55, 7), // "errorTo"
QT_MOC_LITERAL(8, 63, 11), // "reconToHost"
QT_MOC_LITERAL(9, 75, 11), // "doneURLInfo"
QT_MOC_LITERAL(10, 87, 8), // "QUrlInfo"
QT_MOC_LITERAL(11, 96, 7), // "urlInfo"
QT_MOC_LITERAL(12, 104, 12), // "ftpConnected"
QT_MOC_LITERAL(13, 117, 2), // "id"
QT_MOC_LITERAL(14, 120, 8), // "hasError"
QT_MOC_LITERAL(15, 129, 10), // "commFinish"
QT_MOC_LITERAL(16, 140, 6) // "hasBed"

    },
    "WFtpClient\0sendError\0\0sFiles\0err\0"
    "finished\0finishedList\0errorTo\0reconToHost\0"
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
       1,    2,   59,    2, 0x06 /* Public */,
       3,    2,   64,    2, 0x06 /* Public */,
       5,    1,   69,    2, 0x06 /* Public */,
       6,    2,   72,    2, 0x06 /* Public */,
       7,    0,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   78,    2, 0x0a /* Public */,
       9,    1,   79,    2, 0x0a /* Public */,
      12,    2,   82,    2, 0x0a /* Public */,
      15,    2,   87,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QStringList,    4,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   13,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   13,   16,

       0        // eod
};

void WFtpClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WFtpClient *_t = static_cast<WFtpClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendError((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->sFiles((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
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
            typedef void (WFtpClient::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WFtpClient::sendError)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WFtpClient::*_t)(int , QStringList );
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
void WFtpClient::sendError(int _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WFtpClient::sFiles(int _t1, QStringList _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
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
    QByteArrayData data[15];
    char stringdata0[132];
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
QT_MOC_LITERAL(3, 24, 8), // "downlTen"
QT_MOC_LITERAL(4, 33, 11), // "endFormList"
QT_MOC_LITERAL(5, 45, 5), // "start"
QT_MOC_LITERAL(6, 51, 11), // "getListFrom"
QT_MOC_LITERAL(7, 63, 3), // "err"
QT_MOC_LITERAL(8, 67, 12), // "downloadStop"
QT_MOC_LITERAL(9, 80, 4), // "list"
QT_MOC_LITERAL(10, 85, 11), // "downloadTen"
QT_MOC_LITERAL(11, 97, 9), // "startLoad"
QT_MOC_LITERAL(12, 107, 8), // "getError"
QT_MOC_LITERAL(13, 116, 5), // "error"
QT_MOC_LITERAL(14, 122, 9) // "errorText"

    },
    "WNetFtpClient\0downStop\0\0downlTen\0"
    "endFormList\0start\0getListFrom\0err\0"
    "downloadStop\0list\0downloadTen\0startLoad\0"
    "getError\0error\0errorText"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WNetFtpClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x06 /* Public */,
       3,    2,   64,    2, 0x06 /* Public */,
       4,    0,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   70,    2, 0x0a /* Public */,
       6,    2,   73,    2, 0x0a /* Public */,
       8,    2,   78,    2, 0x0a /* Public */,
      10,    2,   83,    2, 0x0a /* Public */,
      11,    0,   88,    2, 0x0a /* Public */,
      12,    2,   89,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QStringList,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QStringList,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QStringList,    7,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QStringList,    7,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::QStringList,    7,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   13,   14,

       0        // eod
};

void WNetFtpClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WNetFtpClient *_t = static_cast<WNetFtpClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->downStop((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 1: _t->downlTen((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 2: _t->endFormList(); break;
        case 3: _t->start((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 4: _t->getListFrom((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 5: _t->downloadStop((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 6: _t->downloadTen((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 7: _t->startLoad(); break;
        case 8: _t->getError((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WNetFtpClient::*_t)(int , QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WNetFtpClient::downStop)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WNetFtpClient::*_t)(int , QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WNetFtpClient::downlTen)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (WNetFtpClient::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WNetFtpClient::endFormList)) {
                *result = 2;
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
void WNetFtpClient::downStop(int _t1, QStringList _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WNetFtpClient::downlTen(int _t1, QStringList _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WNetFtpClient::endFormList()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
