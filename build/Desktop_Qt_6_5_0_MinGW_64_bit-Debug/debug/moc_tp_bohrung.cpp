/****************************************************************************
** Meta object code from reading C++ file 'tp_bohrung.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../TouchProbe/tp_bohrung.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tp_bohrung.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSTP_BohrungENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSTP_BohrungENDCLASS = QtMocHelpers::stringData(
    "TP_Bohrung",
    "slot_setTextFromCilpBoard",
    ""
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSTP_BohrungENDCLASS_t {
    uint offsetsAndSizes[6];
    char stringdata0[11];
    char stringdata1[26];
    char stringdata2[1];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSTP_BohrungENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSTP_BohrungENDCLASS_t qt_meta_stringdata_CLASSTP_BohrungENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "TP_Bohrung"
        QT_MOC_LITERAL(11, 25),  // "slot_setTextFromCilpBoard"
        QT_MOC_LITERAL(37, 0)   // ""
    },
    "TP_Bohrung",
    "slot_setTextFromCilpBoard",
    ""
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTP_BohrungENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x0a,    1 /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject TP_Bohrung::staticMetaObject = { {
    QMetaObject::SuperData::link<TP_Base::staticMetaObject>(),
    qt_meta_stringdata_CLASSTP_BohrungENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTP_BohrungENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTP_BohrungENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TP_Bohrung, std::true_type>,
        // method 'slot_setTextFromCilpBoard'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void TP_Bohrung::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TP_Bohrung *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->slot_setTextFromCilpBoard(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *TP_Bohrung::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TP_Bohrung::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTP_BohrungENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return TP_Base::qt_metacast(_clname);
}

int TP_Bohrung::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TP_Base::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
