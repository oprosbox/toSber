/****************************************************************************
** Meta object code from reading C++ file 'interface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../interface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'interface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_wui__WMainInterf_t {
    QByteArrayData data[11];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_wui__WMainInterf_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_wui__WMainInterf_t qt_meta_stringdata_wui__WMainInterf = {
    {
QT_MOC_LITERAL(0, 0, 16), // "wui::WMainInterf"
QT_MOC_LITERAL(1, 17, 7), // "setPath"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "path"
QT_MOC_LITERAL(4, 31, 10), // "setDateBeg"
QT_MOC_LITERAL(5, 42, 10), // "setDateEnd"
QT_MOC_LITERAL(6, 53, 7), // "getPath"
QT_MOC_LITERAL(7, 61, 10), // "getDateBeg"
QT_MOC_LITERAL(8, 72, 10), // "getDateEnd"
QT_MOC_LITERAL(9, 83, 12), // "closeDateBeg"
QT_MOC_LITERAL(10, 96, 12) // "closeDateEnd"

    },
    "wui::WMainInterf\0setPath\0\0path\0"
    "setDateBeg\0setDateEnd\0getPath\0getDateBeg\0"
    "getDateEnd\0closeDateBeg\0closeDateEnd"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_wui__WMainInterf[] = {

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

void wui::WMainInterf::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
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

const QMetaObject wui::WMainInterf::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_wui__WMainInterf.data,
      qt_meta_data_wui__WMainInterf,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *wui::WMainInterf::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *wui::WMainInterf::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_wui__WMainInterf.stringdata0))
        return static_cast<void*>(const_cast< WMainInterf*>(this));
    return QObject::qt_metacast(_clname);
}

int wui::WMainInterf::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void wui::WMainInterf::setPath(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void wui::WMainInterf::setDateBeg(QDate _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void wui::WMainInterf::setDateEnd(QDate _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_wui__QWidgetRegion_t {
    QByteArrayData data[5];
    char stringdata0[49];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_wui__QWidgetRegion_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_wui__QWidgetRegion_t qt_meta_stringdata_wui__QWidgetRegion = {
    {
QT_MOC_LITERAL(0, 0, 18), // "wui::QWidgetRegion"
QT_MOC_LITERAL(1, 19, 11), // "emitListReg"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 8), // "addCheck"
QT_MOC_LITERAL(4, 41, 7) // "clickOk"

    },
    "wui::QWidgetRegion\0emitListReg\0\0"
    "addCheck\0clickOk"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_wui__QWidgetRegion[] = {

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
       3,    1,   32,    2, 0x0a /* Public */,
       4,    0,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

       0        // eod
};

void wui::QWidgetRegion::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QWidgetRegion *_t = static_cast<QWidgetRegion *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->emitListReg((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 1: _t->addCheck((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->clickOk(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QWidgetRegion::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QWidgetRegion::emitListReg)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject wui::QWidgetRegion::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_wui__QWidgetRegion.data,
      qt_meta_data_wui__QWidgetRegion,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *wui::QWidgetRegion::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *wui::QWidgetRegion::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_wui__QWidgetRegion.stringdata0))
        return static_cast<void*>(const_cast< QWidgetRegion*>(this));
    return QDialog::qt_metacast(_clname);
}

int wui::QWidgetRegion::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void wui::QWidgetRegion::emitListReg(QStringList _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_wui__WUI_t {
    QByteArrayData data[8];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_wui__WUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_wui__WUI_t qt_meta_stringdata_wui__WUI = {
    {
QT_MOC_LITERAL(0, 0, 8), // "wui::WUI"
QT_MOC_LITERAL(1, 9, 12), // "createInterf"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 8), // "btnStart"
QT_MOC_LITERAL(4, 32, 20), // "set223fzRegionsNotif"
QT_MOC_LITERAL(5, 53, 21), // "set223fzRegionsDishon"
QT_MOC_LITERAL(6, 75, 14), // "exec223fzNotif"
QT_MOC_LITERAL(7, 90, 15) // "exec223fzDishon"

    },
    "wui::WUI\0createInterf\0\0btnStart\0"
    "set223fzRegionsNotif\0set223fzRegionsDishon\0"
    "exec223fzNotif\0exec223fzDishon"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_wui__WUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    0,   45,    2, 0x0a /* Public */,
       4,    1,   46,    2, 0x0a /* Public */,
       5,    1,   49,    2, 0x0a /* Public */,
       6,    0,   52,    2, 0x0a /* Public */,
       7,    0,   53,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void wui::WUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WUI *_t = static_cast<WUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->createInterf(); break;
        case 1: _t->btnStart(); break;
        case 2: _t->set223fzRegionsNotif((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 3: _t->set223fzRegionsDishon((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 4: _t->exec223fzNotif(); break;
        case 5: _t->exec223fzDishon(); break;
        default: ;
        }
    }
}

const QMetaObject wui::WUI::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_wui__WUI.data,
      qt_meta_data_wui__WUI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *wui::WUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *wui::WUI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_wui__WUI.stringdata0))
        return static_cast<void*>(const_cast< WUI*>(this));
    return QObject::qt_metacast(_clname);
}

int wui::WUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
