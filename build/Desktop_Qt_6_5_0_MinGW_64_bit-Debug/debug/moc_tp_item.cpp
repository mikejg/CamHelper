/****************************************************************************
** Meta object code from reading C++ file 'tp_item.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../TouchProbe/tp_item.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tp_item.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSTP_ItemENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSTP_ItemENDCLASS = QtMocHelpers::stringData(
    "TP_Item",
    "sig_NewPixmap",
    "",
    "sig_NewItem",
    "sig_DeleteItem",
    "TP_Item*",
    "sig_Err",
    "sig_Log",
    "sig_HighLightLineNumber",
    "sig_Create",
    "slot_Fold_In",
    "slot_Fold_Out",
    "slot_Fold_Toggle",
    "slot_Show_TP_Kante",
    "slot_Show_TP_Ausrichten",
    "slot_Show_TP_Steg",
    "slot_Show_TP_Ebenheit",
    "slot_Show_TP_Nut",
    "slot_Delet_Item",
    "slot_Show_TP_Bohrung",
    "slot_ReCreate",
    "slot_NewHeaderLine"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSTP_ItemENDCLASS_t {
    uint offsetsAndSizes[44];
    char stringdata0[8];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[15];
    char stringdata5[9];
    char stringdata6[8];
    char stringdata7[8];
    char stringdata8[24];
    char stringdata9[11];
    char stringdata10[13];
    char stringdata11[14];
    char stringdata12[17];
    char stringdata13[19];
    char stringdata14[24];
    char stringdata15[18];
    char stringdata16[22];
    char stringdata17[17];
    char stringdata18[16];
    char stringdata19[21];
    char stringdata20[14];
    char stringdata21[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSTP_ItemENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSTP_ItemENDCLASS_t qt_meta_stringdata_CLASSTP_ItemENDCLASS = {
    {
        QT_MOC_LITERAL(0, 7),  // "TP_Item"
        QT_MOC_LITERAL(8, 13),  // "sig_NewPixmap"
        QT_MOC_LITERAL(22, 0),  // ""
        QT_MOC_LITERAL(23, 11),  // "sig_NewItem"
        QT_MOC_LITERAL(35, 14),  // "sig_DeleteItem"
        QT_MOC_LITERAL(50, 8),  // "TP_Item*"
        QT_MOC_LITERAL(59, 7),  // "sig_Err"
        QT_MOC_LITERAL(67, 7),  // "sig_Log"
        QT_MOC_LITERAL(75, 23),  // "sig_HighLightLineNumber"
        QT_MOC_LITERAL(99, 10),  // "sig_Create"
        QT_MOC_LITERAL(110, 12),  // "slot_Fold_In"
        QT_MOC_LITERAL(123, 13),  // "slot_Fold_Out"
        QT_MOC_LITERAL(137, 16),  // "slot_Fold_Toggle"
        QT_MOC_LITERAL(154, 18),  // "slot_Show_TP_Kante"
        QT_MOC_LITERAL(173, 23),  // "slot_Show_TP_Ausrichten"
        QT_MOC_LITERAL(197, 17),  // "slot_Show_TP_Steg"
        QT_MOC_LITERAL(215, 21),  // "slot_Show_TP_Ebenheit"
        QT_MOC_LITERAL(237, 16),  // "slot_Show_TP_Nut"
        QT_MOC_LITERAL(254, 15),  // "slot_Delet_Item"
        QT_MOC_LITERAL(270, 20),  // "slot_Show_TP_Bohrung"
        QT_MOC_LITERAL(291, 13),  // "slot_ReCreate"
        QT_MOC_LITERAL(305, 18)   // "slot_NewHeaderLine"
    },
    "TP_Item",
    "sig_NewPixmap",
    "",
    "sig_NewItem",
    "sig_DeleteItem",
    "TP_Item*",
    "sig_Err",
    "sig_Log",
    "sig_HighLightLineNumber",
    "sig_Create",
    "slot_Fold_In",
    "slot_Fold_Out",
    "slot_Fold_Toggle",
    "slot_Show_TP_Kante",
    "slot_Show_TP_Ausrichten",
    "slot_Show_TP_Steg",
    "slot_Show_TP_Ebenheit",
    "slot_Show_TP_Nut",
    "slot_Delet_Item",
    "slot_Show_TP_Bohrung",
    "slot_ReCreate",
    "slot_NewHeaderLine"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTP_ItemENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  128,    2, 0x06,    1 /* Public */,
       3,    0,  131,    2, 0x06,    3 /* Public */,
       4,    1,  132,    2, 0x06,    4 /* Public */,
       6,    1,  135,    2, 0x06,    6 /* Public */,
       7,    1,  138,    2, 0x06,    8 /* Public */,
       8,    1,  141,    2, 0x06,   10 /* Public */,
       9,    0,  144,    2, 0x06,   12 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    0,  145,    2, 0x0a,   13 /* Public */,
      11,    0,  146,    2, 0x0a,   14 /* Public */,
      12,    0,  147,    2, 0x0a,   15 /* Public */,
      13,    0,  148,    2, 0x0a,   16 /* Public */,
      14,    0,  149,    2, 0x0a,   17 /* Public */,
      15,    0,  150,    2, 0x0a,   18 /* Public */,
      16,    0,  151,    2, 0x0a,   19 /* Public */,
      17,    0,  152,    2, 0x0a,   20 /* Public */,
      18,    0,  153,    2, 0x0a,   21 /* Public */,
      19,    0,  154,    2, 0x0a,   22 /* Public */,
      20,    0,  155,    2, 0x0a,   23 /* Public */,
      21,    1,  156,    2, 0x0a,   24 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPixmap,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject TP_Item::staticMetaObject = { {
    QMetaObject::SuperData::link<QFrame::staticMetaObject>(),
    qt_meta_stringdata_CLASSTP_ItemENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTP_ItemENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTP_ItemENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TP_Item, std::true_type>,
        // method 'sig_NewPixmap'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPixmap, std::false_type>,
        // method 'sig_NewItem'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sig_DeleteItem'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<TP_Item *, std::false_type>,
        // method 'sig_Err'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'sig_Log'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'sig_HighLightLineNumber'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'sig_Create'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_Fold_In'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_Fold_Out'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_Fold_Toggle'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_Show_TP_Kante'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_Show_TP_Ausrichten'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_Show_TP_Steg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_Show_TP_Ebenheit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_Show_TP_Nut'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_Delet_Item'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_Show_TP_Bohrung'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_ReCreate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_NewHeaderLine'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void TP_Item::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TP_Item *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sig_NewPixmap((*reinterpret_cast< std::add_pointer_t<QPixmap>>(_a[1]))); break;
        case 1: _t->sig_NewItem(); break;
        case 2: _t->sig_DeleteItem((*reinterpret_cast< std::add_pointer_t<TP_Item*>>(_a[1]))); break;
        case 3: _t->sig_Err((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->sig_Log((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->sig_HighLightLineNumber((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 6: _t->sig_Create(); break;
        case 7: _t->slot_Fold_In(); break;
        case 8: _t->slot_Fold_Out(); break;
        case 9: _t->slot_Fold_Toggle(); break;
        case 10: _t->slot_Show_TP_Kante(); break;
        case 11: _t->slot_Show_TP_Ausrichten(); break;
        case 12: _t->slot_Show_TP_Steg(); break;
        case 13: _t->slot_Show_TP_Ebenheit(); break;
        case 14: _t->slot_Show_TP_Nut(); break;
        case 15: _t->slot_Delet_Item(); break;
        case 16: _t->slot_Show_TP_Bohrung(); break;
        case 17: _t->slot_ReCreate(); break;
        case 18: _t->slot_NewHeaderLine((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< TP_Item* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TP_Item::*)(QPixmap );
            if (_t _q_method = &TP_Item::sig_NewPixmap; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TP_Item::*)();
            if (_t _q_method = &TP_Item::sig_NewItem; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TP_Item::*)(TP_Item * );
            if (_t _q_method = &TP_Item::sig_DeleteItem; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TP_Item::*)(QString );
            if (_t _q_method = &TP_Item::sig_Err; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TP_Item::*)(QString );
            if (_t _q_method = &TP_Item::sig_Log; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (TP_Item::*)(QStringList );
            if (_t _q_method = &TP_Item::sig_HighLightLineNumber; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (TP_Item::*)();
            if (_t _q_method = &TP_Item::sig_Create; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject *TP_Item::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TP_Item::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTP_ItemENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int TP_Item::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void TP_Item::sig_NewPixmap(QPixmap _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TP_Item::sig_NewItem()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TP_Item::sig_DeleteItem(TP_Item * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TP_Item::sig_Err(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TP_Item::sig_Log(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TP_Item::sig_HighLightLineNumber(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void TP_Item::sig_Create()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
