/****************************************************************************
** Meta object code from reading C++ file 'testingcsvreader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "test/testingcsvreader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testingcsvreader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TestingCSVReader_t {
    QByteArrayData data[10];
    char stringdata0[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestingCSVReader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestingCSVReader_t qt_meta_stringdata_TestingCSVReader = {
    {
QT_MOC_LITERAL(0, 0, 16), // "TestingCSVReader"
QT_MOC_LITERAL(1, 17, 20), // "LoadEmptyCSVFileType"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 19), // "LoadTeachingCSVFile"
QT_MOC_LITERAL(4, 59, 22), // "LoadPublicationCSVFile"
QT_MOC_LITERAL(5, 82, 23), // "LoadPresentationCSVFile"
QT_MOC_LITERAL(6, 106, 17), // "LoadGrantsCSVFile"
QT_MOC_LITERAL(7, 124, 29), // "TestParseDateString_intString"
QT_MOC_LITERAL(8, 154, 30), // "TestParseDateString_charString"
QT_MOC_LITERAL(9, 185, 20) // "TestGetNumberHeaders"

    },
    "TestingCSVReader\0LoadEmptyCSVFileType\0"
    "\0LoadTeachingCSVFile\0LoadPublicationCSVFile\0"
    "LoadPresentationCSVFile\0LoadGrantsCSVFile\0"
    "TestParseDateString_intString\0"
    "TestParseDateString_charString\0"
    "TestGetNumberHeaders"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestingCSVReader[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TestingCSVReader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TestingCSVReader *_t = static_cast<TestingCSVReader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->LoadEmptyCSVFileType(); break;
        case 1: _t->LoadTeachingCSVFile(); break;
        case 2: _t->LoadPublicationCSVFile(); break;
        case 3: _t->LoadPresentationCSVFile(); break;
        case 4: _t->LoadGrantsCSVFile(); break;
        case 5: _t->TestParseDateString_intString(); break;
        case 6: _t->TestParseDateString_charString(); break;
        case 7: _t->TestGetNumberHeaders(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject TestingCSVReader::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TestingCSVReader.data,
      qt_meta_data_TestingCSVReader,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TestingCSVReader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestingCSVReader::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TestingCSVReader.stringdata0))
        return static_cast<void*>(const_cast< TestingCSVReader*>(this));
    return QObject::qt_metacast(_clname);
}

int TestingCSVReader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
