/****************************************************************************
** Meta object code from reading C++ file 'touchprobe.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../TouchProbe/touchprobe.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'touchprobe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSTouchProbeENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSTouchProbeENDCLASS = QtMocHelpers::stringData(
    "TouchProbe",
    "slot_NewPixmap",
    "",
    "slot_Create",
    "slot_ShowPix",
    "slot_Export",
    "slot_ExportTouchprobe"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSTouchProbeENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[11];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[13];
    char stringdata5[12];
    char stringdata6[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSTouchProbeENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSTouchProbeENDCLASS_t qt_meta_stringdata_CLASSTouchProbeENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "TouchProbe"
        QT_MOC_LITERAL(11, 14),  // "slot_NewPixmap"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 11),  // "slot_Create"
        QT_MOC_LITERAL(39, 12),  // "slot_ShowPix"
        QT_MOC_LITERAL(52, 11),  // "slot_Export"
        QT_MOC_LITERAL(64, 21)   // "slot_ExportTouchprobe"
    },
    "TouchProbe",
    "slot_NewPixmap",
    "",
    "slot_Create",
    "slot_ShowPix",
    "slot_Export",
    "slot_ExportTouchprobe"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTouchProbeENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x0a,    1 /* Public */,
       3,    0,   47,    2, 0x0a,    3 /* Public */,
       4,    0,   48,    2, 0x0a,    4 /* Public */,
       5,    0,   49,    2, 0x0a,    5 /* Public */,
       6,    0,   50,    2, 0x0a,    6 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QPixmap,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject TouchProbe::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSTouchProbeENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTouchProbeENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTouchProbeENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TouchProbe, std::true_type>,
        // method 'slot_NewPixmap'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPixmap, std::false_type>,
        // method 'slot_Create'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_ShowPix'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_Export'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_ExportTouchprobe'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void TouchProbe::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TouchProbe *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->slot_NewPixmap((*reinterpret_cast< std::add_pointer_t<QPixmap>>(_a[1]))); break;
        case 1: _t->slot_Create(); break;
        case 2: _t->slot_ShowPix(); break;
        case 3: _t->slot_Export(); break;
        case 4: _t->slot_ExportTouchprobe(); break;
        default: ;
        }
    }
}

const QMetaObject *TouchProbe::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TouchProbe::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTouchProbeENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TouchProbe::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
