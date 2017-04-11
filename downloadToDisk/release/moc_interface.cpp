/****************************************************************************
** Meta object code from reading C++ file 'interface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../interface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'interface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
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
    QByteArrayData data[12];
    char stringdata0[154];
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
QT_MOC_LITERAL(6, 75, 19), // "set44fzRegionsContr"
QT_MOC_LITERAL(7, 95, 14), // "exec223fzNotif"
QT_MOC_LITERAL(8, 110, 15), // "exec223fzDishon"
QT_MOC_LITERAL(9, 126, 13), // "exec44fzContr"
QT_MOC_LITERAL(10, 140, 10), // "allWasLoad"
QT_MOC_LITERAL(11, 151, 2) // "id"

    },
    "wui::WUI\0createInterf\0\0btnStart\0"
    "set223fzRegionsNotif\0set223fzRegionsDishon\0"
    "set44fzRegionsContr\0exec223fzNotif\0"
    "exec223fzDishon\0exec44fzContr\0allWasLoad\0"
    "id"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_wui__WUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    1,   61,    2, 0x0a /* Public */,
       5,    1,   64,    2, 0x0a /* Public */,
       6,    1,   67,    2, 0x0a /* Public */,
       7,    0,   70,    2, 0x0a /* Public */,
       8,    0,   71,    2, 0x0a /* Public */,
       9,    0,   72,    2, 0x0a /* Public */,
      10,    1,   73,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,

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
        case 4: _t->set44fzRegionsContr((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 5: _t->exec223fzNotif(); break;
        case 6: _t->exec223fzDishon(); break;
        case 7: _t->exec44fzContr(); break;
        case 8: _t->allWasLoad((*reinterpret_cast< int(*)>(_a[1]))); break;
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
QT_END_MOC_NAMESPACE
