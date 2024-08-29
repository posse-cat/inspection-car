/****************************************************************************
** Meta object code from reading C++ file 'main_window.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/ros_qt_master/main_window.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_class1_ros_qt_demo__MainWindow_t {
    QByteArrayData data[12];
    char stringdata0[252];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_class1_ros_qt_demo__MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_class1_ros_qt_demo__MainWindow_t qt_meta_stringdata_class1_ros_qt_demo__MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 30), // "class1_ros_qt_demo::MainWindow"
QT_MOC_LITERAL(1, 31, 40), // "on_checkbox_use_environment_s..."
QT_MOC_LITERAL(2, 72, 0), // ""
QT_MOC_LITERAL(3, 73, 5), // "state"
QT_MOC_LITERAL(4, 79, 27), // "on_pushButton_start_pressed"
QT_MOC_LITERAL(5, 107, 26), // "on_pushButton_save_pressed"
QT_MOC_LITERAL(6, 134, 26), // "on_pushButton_stop_pressed"
QT_MOC_LITERAL(7, 161, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(8, 186, 25), // "on_button_connect_clicked"
QT_MOC_LITERAL(9, 212, 5), // "check"
QT_MOC_LITERAL(10, 218, 17), // "updateLoggingView"
QT_MOC_LITERAL(11, 236, 15) // "updateImgWidget"

    },
    "class1_ros_qt_demo::MainWindow\0"
    "on_checkbox_use_environment_stateChanged\0"
    "\0state\0on_pushButton_start_pressed\0"
    "on_pushButton_save_pressed\0"
    "on_pushButton_stop_pressed\0"
    "on_actionAbout_triggered\0"
    "on_button_connect_clicked\0check\0"
    "updateLoggingView\0updateImgWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_class1_ros_qt_demo__MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a /* Public */,
       4,    0,   57,    2, 0x0a /* Public */,
       5,    0,   58,    2, 0x0a /* Public */,
       6,    0,   59,    2, 0x0a /* Public */,
       7,    0,   60,    2, 0x0a /* Public */,
       8,    1,   61,    2, 0x0a /* Public */,
      10,    0,   64,    2, 0x0a /* Public */,
      11,    0,   65,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void class1_ros_qt_demo::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_checkbox_use_environment_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_start_pressed(); break;
        case 2: _t->on_pushButton_save_pressed(); break;
        case 3: _t->on_pushButton_stop_pressed(); break;
        case 4: _t->on_actionAbout_triggered(); break;
        case 5: _t->on_button_connect_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->updateLoggingView(); break;
        case 7: _t->updateImgWidget(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject class1_ros_qt_demo::MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_class1_ros_qt_demo__MainWindow.data,
    qt_meta_data_class1_ros_qt_demo__MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *class1_ros_qt_demo::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *class1_ros_qt_demo::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_class1_ros_qt_demo__MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int class1_ros_qt_demo::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
