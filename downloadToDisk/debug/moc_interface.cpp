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
    QByteArrayData data[3];
    char stringdata0[29];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_wui__QWidgetRegion_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_wui__QWidgetRegion_t qt_meta_stringdata_wui__QWidgetRegion = {
    {
QT_MOC_LITERAL(0, 0, 18), // "wui::QWidgetRegion"
QT_MOC_LITERAL(1, 19, 8), // "addCheck"
QT_MOC_LITERAL(2, 28, 0) // ""

    },
    "wui::QWidgetRegion\0addCheck\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_wui__QWidgetRegion[] = {

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
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void wui::QWidgetRegion::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QWidgetRegion *_t = static_cast<QWidgetRegion *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addCheck((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject wui::QWidgetRegion::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_wui__QWidgetRegion.data,
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
    return QWidget::qt_metacast(_clname);
}

int wui::QWidgetRegion::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_wui__WUI_t {
    QByteArrayData data[3];
    char stringdata0[19];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_wui__WUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_wui__WUI_t qt_meta_stringdata_wui__WUI = {
    {
QT_MOC_LITERAL(0, 0, 8), // "wui::WUI"
QT_MOC_LITERAL(1, 9, 8), // "btnStart"
QT_MOC_LITERAL(2, 18, 0) // ""

    },
    "wui::WUI\0btnStart\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_wui__WUI[] = {

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
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void wui::WUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WUI *_t = static_cast<WUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->btnStart(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
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
QT_END_MOC_NAMESPACE