/****************************************************************************
** Meta object code from reading C++ file 'dialog_open.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Dialoge/dialog_open.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_open.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSDialog_OpenENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSDialog_OpenENDCLASS = QtMocHelpers::stringData(
    "Dialog_Open",
    "sig_LoadProject",
    "",
    "slot_ShowDialog",
    "slot_accepted",
    "slot_TextChanged",
    "slot_Clicked",
    "QModelIndex",
    "slot_TagsClicked",
    "slot_NewProjectList",
    "slot_NoTagsSelected"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSDialog_OpenENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[12];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[14];
    char stringdata5[17];
    char stringdata6[13];
    char stringdata7[12];
    char stringdata8[17];
    char stringdata9[20];
    char stringdata10[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSDialog_OpenENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSDialog_OpenENDCLASS_t qt_meta_stringdata_CLASSDialog_OpenENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "Dialog_Open"
        QT_MOC_LITERAL(12, 15),  // "sig_LoadProject"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 15),  // "slot_ShowDialog"
        QT_MOC_LITERAL(45, 13),  // "slot_accepted"
        QT_MOC_LITERAL(59, 16),  // "slot_TextChanged"
        QT_MOC_LITERAL(76, 12),  // "slot_Clicked"
        QT_MOC_LITERAL(89, 11),  // "QModelIndex"
        QT_MOC_LITERAL(101, 16),  // "slot_TagsClicked"
        QT_MOC_LITERAL(118, 19),  // "slot_NewProjectList"
        QT_MOC_LITERAL(138, 19)   // "slot_NoTagsSelected"
    },
    "Dialog_Open",
    "sig_LoadProject",
    "",
    "slot_ShowDialog",
    "slot_accepted",
    "slot_TextChanged",
    "slot_Clicked",
    "QModelIndex",
    "slot_TagsClicked",
    "slot_NewProjectList",
    "slot_NoTagsSelected"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDialog_OpenENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   62,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   67,    2, 0x0a,    4 /* Public */,
       4,    0,   68,    2, 0x0a,    5 /* Public */,
       5,    1,   69,    2, 0x0a,    6 /* Public */,
       6,    1,   72,    2, 0x0a,    8 /* Public */,
       8,    0,   75,    2, 0x0a,   10 /* Public */,
       9,    1,   76,    2, 0x0a,   11 /* Public */,
      10,    0,   79,    2, 0x0a,   13 /* Public */,

 // signals: parameters
    QMetaType::Int, QMetaType::QString, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Dialog_Open::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSDialog_OpenENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDialog_OpenENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDialog_OpenENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Dialog_Open, std::true_type>,
        // method 'sig_LoadProject'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'slot_ShowDialog'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_accepted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_TextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'slot_Clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QModelIndex, std::false_type>,
        // method 'slot_TagsClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_NewProjectList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'slot_NoTagsSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Dialog_Open::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Dialog_Open *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { int _r = _t->sig_LoadProject((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->slot_ShowDialog(); break;
        case 2: _t->slot_accepted(); break;
        case 3: _t->slot_TextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->slot_Clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 5: _t->slot_TagsClicked(); break;
        case 6: _t->slot_NewProjectList((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 7: _t->slot_NoTagsSelected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = int (Dialog_Open::*)(QString , QString );
            if (_t _q_method = &Dialog_Open::sig_LoadProject; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *Dialog_Open::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog_Open::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDialog_OpenENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Dialog_Open::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
int Dialog_Open::sig_LoadProject(QString _t1, QString _t2)
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}
QT_WARNING_POP
