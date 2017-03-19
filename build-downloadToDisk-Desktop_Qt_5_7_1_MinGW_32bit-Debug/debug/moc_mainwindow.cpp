/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../downloadToDisk/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WMainInterf_t {
    QByteArrayData data[11];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WMainInterf_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WMainInterf_t qt_meta_stringdata_WMainInterf = {
    {
QT_MOC_LITERAL(0, 0, 11), // "WMainInterf"
QT_MOC_LITERAL(1, 12, 7), // "setPath"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 4), // "path"
QT_MOC_LITERAL(4, 26, 10), // "setDateBeg"
QT_MOC_LITERAL(5, 37, 10), // "setDateEnd"
QT_MOC_LITERAL(6, 48, 7), // "getPath"
QT_MOC_LITERAL(7, 56, 10), // "getDateBeg"
QT_MOC_LITERAL(8, 67, 10), // "getDateEnd"
QT_MOC_LITERAL(9, 78, 12), // "closeDateBeg"
QT_MOC_LITERAL(10, 91, 12) // "closeDateEnd"

    },
    "WMainInterf\0setPath\0\0path\0setDateBeg\0"
    "setDateEnd\0getPath\0getDateBeg\0getDateEnd\0"
    "closeDateBeg\0closeDateEnd"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WMainInterf[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       5,    1,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   63,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x0a /* Public */,
       9,    1,   66,    2, 0x0a /* Public */,
      10,    1,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QDate,    2,
    QMetaType::Void, QMetaType::QDate,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,    2,
    QMetaType::Void, QMetaType::QDate,    2,

       0        // eod
};

void WMainInterf::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WMainInterf *_t = static_cast<WMainInterf *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setPath((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->setDateBeg((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 2: _t->setDateEnd((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 3: _t->getPath(); break;
        case 4: _t->getDateBeg(); break;
        case 5: _t->getDateEnd(); break;
        case 6: _t->closeDateBeg((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 7: _t->closeDateEnd((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WMainInterf::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WMainInterf::setPath)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WMainInterf::*_t)(QDate );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WMainInterf::setDateBeg)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (WMainInterf::*_t)(QDate );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WMainInterf::setDateEnd)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject WMainInterf::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WMainInterf.data,
      qt_meta_data_WMainInterf,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WMainInterf::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WMainInterf::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WMainInterf.stringdata0))
        return static_cast<void*>(const_cast< WMainInterf*>(this));
    return QObject::qt_metacast(_clname);
}

int WMainInterf::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void WMainInterf::setPath(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WMainInterf::setDateBeg(QDate _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WMainInterf::setDateEnd(QDate _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[1];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10) // "MainWindow"

    },
    "MainWindow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

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

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
