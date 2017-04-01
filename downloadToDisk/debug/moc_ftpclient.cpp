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
    QByteArrayData data[19];
    char stringdata0[189];
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
QT_MOC_LITERAL(5, 35, 12), // "allDownloads"
QT_MOC_LITERAL(6, 48, 9), // "errorEmit"
QT_MOC_LITERAL(7, 58, 13), // "finishRequest"
QT_MOC_LITERAL(8, 72, 14), // "QNetworkReply*"
QT_MOC_LITERAL(9, 87, 2), // "in"
QT_MOC_LITERAL(10, 90, 6), // "errors"
QT_MOC_LITERAL(11, 97, 27), // "QNetworkReply::NetworkError"
QT_MOC_LITERAL(12, 125, 16), // "downloadProgress"
QT_MOC_LITERAL(13, 142, 4), // "recv"
QT_MOC_LITERAL(14, 147, 5), // "total"
QT_MOC_LITERAL(15, 153, 8), // "finished"
QT_MOC_LITERAL(16, 162, 5), // "reply"
QT_MOC_LITERAL(17, 168, 10), // "functTimer"
QT_MOC_LITERAL(18, 179, 9) // "startNext"

    },
    "WNetworkFtp\0emit10Obj\0\0err\0listGet\0"
    "allDownloads\0errorEmit\0finishRequest\0"
    "QNetworkReply*\0in\0errors\0"
    "QNetworkReply::NetworkError\0"
    "downloadProgress\0recv\0total\0finished\0"
    "reply\0functTimer\0startNext"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WNetworkFtp[] = {

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
       5,    0,   64,    2, 0x06 /* Public */,
       6,    0,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   66,    2, 0x0a /* Public */,
      10,    1,   69,    2, 0x0a /* Public */,
      12,    2,   72,    2, 0x0a /* Public */,
      15,    1,   77,    2, 0x0a /* Public */,
      17,    0,   80,    2, 0x0a /* Public */,
      18,    0,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QStringList,    3,    4,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,   13,   14,
    QMetaType::Void, 0x80000000 | 8,   16,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WNetworkFtp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WNetworkFtp *_t = static_cast<WNetworkFtp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->emit10Obj((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 1: _t->allDownloads(); break;
        case 2: _t->errorEmit(); break;
        case 3: _t->finishRequest((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 4: _t->errors((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 5: _t->downloadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 6: _t->finished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 7: _t->functTimer(); break;
        case 8: _t->startNext(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
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
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WNetworkFtp::allDownloads)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (WNetworkFtp::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WNetworkFtp::errorEmit)) {
                *result = 2;
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
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
void WNetworkFtp::allDownloads()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void WNetworkFtp::errorEmit()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
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
    QByteArrayData data[18];
    char stringdata0[174];
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
QT_MOC_LITERAL(5, 45, 11), // "endDownload"
QT_MOC_LITERAL(6, 57, 5), // "start"
QT_MOC_LITERAL(7, 63, 11), // "getListFrom"
QT_MOC_LITERAL(8, 75, 3), // "err"
QT_MOC_LITERAL(9, 79, 12), // "downloadStop"
QT_MOC_LITERAL(10, 92, 4), // "list"
QT_MOC_LITERAL(11, 97, 11), // "downloadTen"
QT_MOC_LITERAL(12, 109, 9), // "startLoad"
QT_MOC_LITERAL(13, 119, 8), // "getError"
QT_MOC_LITERAL(14, 128, 5), // "error"
QT_MOC_LITERAL(15, 134, 9), // "errorText"
QT_MOC_LITERAL(16, 144, 16), // "downloadProgress"
QT_MOC_LITERAL(17, 161, 12) // "endDownloads"

    },
    "WNetFtpClient\0downStop\0\0downlTen\0"
    "endFormList\0endDownload\0start\0getListFrom\0"
    "err\0downloadStop\0list\0downloadTen\0"
    "startLoad\0getError\0error\0errorText\0"
    "downloadProgress\0endDownloads"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WNetFtpClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x06 /* Public */,
       3,    2,   79,    2, 0x06 /* Public */,
       4,    0,   84,    2, 0x06 /* Public */,
       5,    0,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   86,    2, 0x0a /* Public */,
       7,    2,   89,    2, 0x0a /* Public */,
       9,    2,   94,    2, 0x0a /* Public */,
      11,    2,   99,    2, 0x0a /* Public */,
      12,    0,  104,    2, 0x0a /* Public */,
      13,    2,  105,    2, 0x0a /* Public */,
      16,    3,  110,    2, 0x0a /* Public */,
      17,    0,  117,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QStringList,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QStringList,    2,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QStringList,    8,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QStringList,    8,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::QStringList,    8,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   14,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::LongLong, QMetaType::LongLong,    2,    2,    2,
    QMetaType::Void,

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
        case 3: _t->endDownload(); break;
        case 4: _t->start((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 5: _t->getListFrom((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 6: _t->downloadStop((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 7: _t->downloadTen((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 8: _t->startLoad(); break;
        case 9: _t->getError((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 10: _t->downloadProgress((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3]))); break;
        case 11: _t->endDownloads(); break;
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
        {
            typedef void (WNetFtpClient::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WNetFtpClient::endDownload)) {
                *result = 3;
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
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

// SIGNAL 3
void WNetFtpClient::endDownload()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
