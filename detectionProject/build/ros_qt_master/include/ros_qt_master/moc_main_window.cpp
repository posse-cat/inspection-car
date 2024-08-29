/****************************************************************************
** Meta object code from reading C++ file 'main_window.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/ros_qt_master/include/ros_qt_master/main_window.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_class1_ros_qt_demo__MainWindow_t {
    QByteArrayData data[16];
    char stringdata0[337];
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
QT_MOC_LITERAL(4, 79, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(5, 104, 25), // "on_button_connect_clicked"
QT_MOC_LITERAL(6, 130, 5), // "check"
QT_MOC_LITERAL(7, 136, 33), // "on_action_img_streaming_trigg..."
QT_MOC_LITERAL(8, 170, 28), // "on_action_img_save_triggered"
QT_MOC_LITERAL(9, 199, 28), // "on_action_img_stop_triggered"
QT_MOC_LITERAL(10, 228, 31), // "on_action_para_config_triggered"
QT_MOC_LITERAL(11, 260, 17), // "updateLoggingView"
QT_MOC_LITERAL(12, 278, 20), // "updateImgWidget_main"
QT_MOC_LITERAL(13, 299, 24), // "sentRequestChangeCamPara"
QT_MOC_LITERAL(14, 324, 5), // "uint*"
QT_MOC_LITERAL(15, 330, 6) // "float*"

    },
    "class1_ros_qt_demo::MainWindow\0"
    "on_checkbox_use_environment_stateChanged\0"
    "\0state\0on_actionAbout_triggered\0"
    "on_button_connect_clicked\0check\0"
    "on_action_img_streaming_triggered\0"
    "on_action_img_save_triggered\0"
    "on_action_img_stop_triggered\0"
    "on_action_para_config_triggered\0"
    "updateLoggingView\0updateImgWidget_main\0"
    "sentRequestChangeCamPara\0uint*\0float*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_class1_ros_qt_demo__MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x0a /* Public */,
       4,    0,   67,    2, 0x0a /* Public */,
       5,    1,   68,    2, 0x0a /* Public */,
       7,    0,   71,    2, 0x0a /* Public */,
       8,    0,   72,    2, 0x0a /* Public */,
       9,    0,   73,    2, 0x0a /* Public */,
      10,    0,   74,    2, 0x0a /* Public */,
      11,    0,   75,    2, 0x0a /* Public */,
      12,    0,   76,    2, 0x0a /* Public */,
      13,    3,   77,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14, 0x80000000 | 15, 0x80000000 | 15,    2,    2,    2,

       0        // eod
};

void class1_ros_qt_demo::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_checkbox_use_environment_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_actionAbout_triggered(); break;
        case 2: _t->on_button_connect_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_action_img_streaming_triggered(); break;
        case 4: _t->on_action_img_save_triggered(); break;
        case 5: _t->on_action_img_stop_triggered(); break;
        case 6: _t->on_action_para_config_triggered(); break;
        case 7: _t->updateLoggingView(); break;
        case 8: _t->updateImgWidget_main(); break;
        case 9: _t->sentRequestChangeCamPara((*reinterpret_cast< uint*(*)>(_a[1])),(*reinterpret_cast< float*(*)>(_a[2])),(*reinterpret_cast< float*(*)>(_a[3]))); break;
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
