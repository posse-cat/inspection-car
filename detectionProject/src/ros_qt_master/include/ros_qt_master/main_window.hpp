/**
 * @file /include/class1_ros_qt_demo/main_window.hpp
 *
 * @brief Qt based gui for class1_ros_qt_demo.
 *
 * @date November 2010
 **/
#ifndef class1_ros_qt_demo_MAIN_WINDOW_H
#define class1_ros_qt_demo_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/
/*QT5*/
#include <QtWidgets/QMainWindow>
#include <QPointer>
//#include "ui_main_window.h"
#include "ui_main_window_new.h"
#include "node_img_receive.hpp"

/*****************************************************************************
** forward declaration
*****************************************************************************/
class camera_configure_window;

enum poptype {
	NOMASTER,
	NOSERVICE
};

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace class1_ros_qt_demo {
	class CtrlNode; //前置声明在这个命名空间下其他的类

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow {
Q_OBJECT

public:
	MainWindow(int argc, char** argv, QWidget *parent = 0);
	~MainWindow();

	void ReadSettings(); // Load up qt program settings at startup
	void WriteSettings(); // Save qt program settings when closing

	void closeEvent(QCloseEvent *event); // Overloaded function
	void MessagePopup(poptype);

public Q_SLOTS:
	/******************************************
	** Auto-connections (connectSlotsByName())
	*******************************************/
    // THe rule of Auto-connection: on_<object-name>_<signal-name>
    // https://blog.csdn.net/qq_54169998/article/details/125982843
	
	void on_checkbox_use_environment_stateChanged(int state);

	//we delete this three pushbutton in ui ,2024-6-17
    //void on_pushButton_start_pressed();
    //void on_pushButton_save_pressed();
    //void on_pushButton_stop_pressed();

	//we delete this two pushbutton in ui ,2024-6-13
	void on_actionAbout_triggered(); 
    void on_button_connect_clicked(bool check);

	void on_action_img_streaming_triggered();
	void on_action_img_save_triggered();
	void on_action_img_stop_triggered();
    void on_action_para_config_triggered();
 
    /******************************************
    ** Manual connections
    *******************************************/
    void updateLoggingView(); // no idea why this can't connect automatically
    //                         & because you not follow the nomenclature
    void updateImgWidget_main();
	//void updateImgWidget_front();

    void sentRequestChangeCamPara(unsigned int *,float*,float*);

private:
	Ui::MainWindowDesign ui;

	//image topic name from ros-master
	std::string basler_cam_name = "/pylon_camera_node/image_raw";
	/* note!!!!! (in rasbarryPi) */
	//std::string IR_cam_name = "/usb_cam_infrared/image_raw";
	std::string IR_cam_name = "/usb_cam1/image_raw";


	//node for recieving image
	QNode qnode;
	
    camera_configure_window * camconf_window;
    QPointer<camera_configure_window> camconf_ui_ptr;
    CtrlNode *ctlnode_ptr;

};

}  // namespace class1_ros_qt_demo

#endif // class1_ros_qt_demo_MAIN_WINDOW_H
