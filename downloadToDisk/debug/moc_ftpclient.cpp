/****************************************************************************
** Meta object code from reading C++ file 'ftpclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ftpclient.h"
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
struct qt_meta_stringdata_WFtpClient_t {
    QByteArrayData data[14];
    char stringdata0[130];
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
QT_MOC_LITERAL(3, 22, 13), // "endOperations"
QT_MOC_LITERAL(4, 36, 8), // "finished"
QT_MOC_LITERAL(5, 45, 12), // "finishedList"
QT_MOC_LITERAL(6, 58, 11), // "doneURLInfo"
QT_MOC_LITERAL(7, 70, 8), // "QUrlInfo"
QT_MOC_LITERAL(8, 79, 7), // "urlInfo"
QT_MOC_LITERAL(9, 87, 12), // "ftpConnected"
QT_MOC_LITERAL(10, 100, 8), // "hasError"
QT_MOC_LITERAL(11, 109, 10), // "commFinish"
QT_MOC_LITERAL(12, 120, 2), // "id"
QT_MOC_LITERAL(13, 123, 6) // "hasBed"

    },
    "WFtpClient\0sendError\0\0endOperations\0"
    "finished\0finishedList\0doneURLInfo\0"
    "QUrlInfo\0urlInfo\0ftpConnected\0hasError\0"
    "commFinish\0id\0hasBed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WFtpClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       3,    1,   52,    2, 0x06 /* Public */,
       4,    1,   55,    2, 0x06 /* Public */,
       5,    2,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   63,    2, 0x0a /* Public */,
       9,    1,   66,    2, 0x0a /* Public */,
      11,    2,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   12,   13,

       0        // eod
};

void WFtpClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WFtpClient *_t = static_cast<WFtpClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->endOperations((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: _t->finished((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 3: _t->finishedList((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 4: _t->doneURLInfo((*reinterpret_cast< QUrlInfo(*)>(_a[1]))); break;
        case 5: _t->ftpConnected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->commFinish((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
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
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WFtpClient::endOperations)) {
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
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
void WFtpClient::endOperations(QStringList _t1)
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
QT_END_MOC_NAMESPACE
