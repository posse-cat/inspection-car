/****************************************************************************
** Meta object code from reading C++ file 'camera_configure_window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/ros_qt_master/include/ros_qt_master/camera_configure_window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'camera_configure_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_camera_configure_window_t {
    QByteArrayData data[9];
    char stringdata0[138];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_camera_configure_window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_camera_configure_window_t qt_meta_stringdata_camera_configure_window = {
    {
QT_MOC_LITERAL(0, 0, 23), // "camera_configure_window"
QT_MOC_LITERAL(1, 24, 11), // "camera_conf"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 5), // "uint*"
QT_MOC_LITERAL(4, 43, 6), // "float*"
QT_MOC_LITERAL(5, 50, 14), // "slider2spinBox"
QT_MOC_LITERAL(6, 65, 14), // "spinBox2slider"
QT_MOC_LITERAL(7, 80, 32), // "on_pushButton_returnMain_pressed"
QT_MOC_LITERAL(8, 113, 24) // "on_pushButton_OK_pressed"

    },
    "camera_configure_window\0camera_conf\0"
    "\0uint*\0float*\0slider2spinBox\0"
    "spinBox2slider\0on_pushButton_returnMain_pressed\0"
    "on_pushButton_OK_pressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_camera_configure_window[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   39,    2, 0x06 /* Public */,
       5,    1,   46,    2, 0x06 /* Public */,
       6,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   52,    2, 0x0a /* Public */,
       8,    0,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4, 0x80000000 | 4,    2,    2,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void camera_configure_window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<camera_configure_window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->camera_conf((*reinterpret_cast< uint*(*)>(_a[1])),(*reinterpret_cast< float*(*)>(_a[2])),(*reinterpret_cast< float*(*)>(_a[3]))); break;
        case 1: _t->slider2spinBox((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->spinBox2slider((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_returnMain_pressed(); break;
        case 4: _t->on_pushButton_OK_pressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (camera_configure_window::*)(unsigned int * , float * , float * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&camera_configure_window::camera_conf)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (camera_configure_window::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&camera_configure_window::slider2spinBox)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (camera_configure_window::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&camera_configure_window::spinBox2slider)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject camera_configure_window::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_camera_configure_window.data,
    qt_meta_data_camera_configure_window,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *camera_configure_window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *camera_configure_window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_camera_configure_window.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int camera_configure_window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void camera_configure_window::camera_conf(unsigned int * _t1, float * _t2, float * _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void camera_configure_window::slider2spinBox(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void camera_configure_window::spinBox2slider(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
