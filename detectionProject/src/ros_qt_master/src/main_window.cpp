/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date December 2023 by pengyunfeng
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include "main_window.hpp"
#include "camera_configure_window.h"
#include "node_cam_control.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace class1_ros_qt_demo {

using namespace Qt;

/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
	: QMainWindow(parent)
	, qnode(argc,argv,basler_cam_name,IR_cam_name)
{
	ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.
    //QObject::connect(ui.actionAbout_Qt, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt())); // qApp is a global variable for the application
    this->setWindowTitle("碳纤维臂架内腔检测程序");

    ReadSettings();//setting information for <right-side-Tools> in UI
    setWindowIcon(QIcon(":/images/icon.png"));
    //ui.tab_manager->setCurrentIndex(0); // ensure the first tab is showing - qt-designer should have this already hardwired, but often loses it (settings?).
    QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));

	/*********************
    ** Logging-windows
	**********************/
    // %QListView% user manual ->
    //
	ui.view_logging->setModel(qnode.loggingModel());
    QObject::connect(&qnode, SIGNAL(loggingUpdated()), this, SLOT(updateLoggingView()));

    /*********************
    ** Auto Start
    **********************/
    // ischeck() to check the state of box. -> return %bool%
    if ( ui.checkbox_remember_settings->isChecked() ) {
        on_button_connect_clicked(true);
    }

    /*************************************
    ** Image display Box（%QLabel% class）
    **************************************/
    // Refference: https://qt.0voice.com/?id=6057
    //ui.Image_show->setStyleSheet("border: 1px dashed green;");

    /*************************************
    ** Image display Box（%QWidget% son-class）
    **************************************/
    QObject::connect(&qnode,SIGNAL(imageUpdate()),this,SLOT(updateImgWidget_main()));

    /*************************************
    *** transform the camera parameter
    **************************************/   
    ctlnode_ptr = new CtrlNode(argc,argv);

    /*************************************
    *** sub_window close when main_window close
    **************************************/
   this->setAttribute(Qt::WA_QuitOnClose,true); 

}

MainWindow::~MainWindow() {

    if (camconf_window != nullptr)
    {
        delete camconf_window;
    }


}

/*****************************************************************************
** Implementation [Slots]
*****************************************************************************/

//void MainWindow::showNoMasterMessage() {
//    // %QMessageBox% user manual ->
//    // https://blog.csdn.net/kenfan1647/article/details/122922588//
//	  QMessageBox msgBox;//
// 	  msgBox.setText("Couldn't find the ros master.");
//    msgBox.setStandardButtons(QMessageBox::Close | QMessageBox::Ok);
//    int rec = msgBox.exec();
//    switch(rec)
//    {
//        case QMessageBox::Ok:
//            break;
//        case QMessageBox::Close:
//            // quit Main-Window interface
//            close();
//    }
//    return;
//}
void MainWindow::MessagePopup(poptype mode)
{
    QMessageBox msgBox;
    
    /***************************************************
     * * * show rubric according to "mode"
     ***************************************************/
    switch (mode) {
        case (NOMASTER):{
            msgBox.setText("Couldn't find the ros master.");
        }
        case (NOSERVICE):{
            msgBox.setText("Couldn't find the server about cam parameter.");
        }
    }

    /***************************************************
     * * *  configure the content of box-window
     ***************************************************/
    msgBox.setStandardButtons(QMessageBox::Close | QMessageBox::Ok);
    int rec = msgBox.exec();
    switch(rec)
    {
        case QMessageBox::Ok:
            break;
        case QMessageBox::Close:
            // quit Main-Window interface
            close();
    }
    return;
}

/*
 * These triggers whenever the button is clicked, regardless of whether it
 * is already checked or not.
 */
void MainWindow::on_button_connect_clicked(bool check){
    if ( ui.checkbox_use_environment->isChecked() ) {
        if ( !qnode.rosConncTest() ) {
            MessagePopup(NOMASTER);
        } else {
            // %QPushButton% user manual  ->
            //https://blog.csdn.net/Littlehero_121/article/details/128798040
            ui.button_connect->setEnabled(false);
        }
    } else {

        if ( ! qnode.rosConncTest(ui.line_edit_master->text().toStdString(),
                   ui.line_edit_host->text().toStdString()) ) {
            MessagePopup(NOMASTER);

        } else {
            ui.button_connect->setEnabled(false);
            ui.line_edit_master->setReadOnly(true);
            //ui.line_edit_host->setReadOnly(true);
            //ui.line_edit_topic->setReadOnly(true);
        }
    }
}

/*void MainWindow::on_button_connect_clicked(bool check ) {
	if ( ui.checkbox_use_environment->isChecked() ) {
        if ( !qnode.init() ) {
			showNoMasterMessage();
        } else {
            // %QPushButton% user manual  ->
            //https://blog.csdn.net/Littlehero_121/article/details/128798040
			ui.button_connect->setEnabled(false);
		}
	} else {

		if ( ! qnode.init(ui.line_edit_master->text().toStdString(),
				   ui.line_edit_host->text().toStdString()) ) {
			showNoMasterMessage();

		} else {
			ui.button_connect->setEnabled(false);
			ui.line_edit_master->setReadOnly(true);
			ui.line_edit_host->setReadOnly(true);
            //ui.line_edit_topic->setReadOnly(true);
		}
	}
}*/

void MainWindow::on_action_img_streaming_triggered()
{
    if(!qnode.rosImageReception()){
        MessagePopup(NOMASTER);
    }else{
        ui.action_img_streaming->setEnabled(false);
    }
}

void MainWindow::on_action_img_save_triggered()
{
    QImage* img_ptr=qnode.qImg1();
    QString date=QDateTime::currentDateTime().toString();
    QString fileName="./image-"+date+".png";
    img_ptr->save(fileName,"PNG");
    return;
}

void MainWindow::on_action_img_stop_triggered()
{
    //Q_EMIT qnode.rosShutdown();  //close the "main_window" directly
    //stop QThread : https://blog.csdn.net/qq_44365088/article/details/119087454
    this->qnode.terminate();
    this->qnode.wait();
    //delete &this->qnode;
    ui.action_img_streaming->setEnabled(true);
}

void MainWindow::on_action_para_config_triggered()
{
    if(camconf_ui_ptr==nullptr)
    {
        camconf_window=new camera_configure_window();
        QObject::connect(camconf_window,&camera_configure_window::camera_conf,this,&MainWindow::sentRequestChangeCamPara);
        camconf_ui_ptr=camconf_window;
        
        //https://blog.csdn.net/heqiunong/article/details/129613509
        camconf_window->setAttribute(Qt::WA_DeleteOnClose); //当子窗口被关闭时，widget将会被释放

        //配置子窗口的名称和显示位置
        camconf_window->setWindowTitle("配置工业相机参数");
        // 假设 parentWidget 是父窗口的指针，childWidget 是子窗口的指针
        QRect parentRect = this->rect(); // 获取父窗口的矩形区域
        int centerX = parentRect.center().x(); // 计算父窗口的X中心点
        int centerY = parentRect.center().y(); // 计算父窗口的Y中心点
        camconf_window->move(centerX, centerY); // 将子窗口移动到父窗口的中心点
        camconf_window->show();
    }
    else
    {
        camconf_window=camconf_ui_ptr.data();
        camconf_window->hide();
        camconf_window->showNormal();
    }
}

void MainWindow::on_checkbox_use_environment_stateChanged(int state) {
	bool enabled;
    // once the state of box changed, execute this action
	if ( state == 0 ) {
		enabled = true;
	} else {
		enabled = false;
	}
	ui.line_edit_master->setEnabled(enabled);
	ui.line_edit_host->setEnabled(enabled);
    //ui.line_edit_topic->setEnabled(enabled);
}

/* 
    ====>> 不使用按钮的方式触发命令了

void MainWindow::on_pushButton_start_pressed(){
    if(!qnode.rosImageReception()){
        MessagePopup(NOMASTER);
    }else{
        ui.pushButton_start->setEnabled(false);
    }
}

void MainWindow::on_pushButton_save_pressed(){
    QImage* img_ptr=qnode.qImg();
    QString date=QDateTime::currentDateTime().toString();
    QString fileName="/home/pp/imgResult/image-"+date+".png";
    img_ptr->save(fileName,"PNG");
    return;
}

void MainWindow::on_pushButton_stop_pressed(){
    //Q_EMIT qnode.rosShutdown();  //close the "main_window" directly
    //stop QThread : https://blog.csdn.net/qq_44365088/article/details/119087454
    this->qnode.terminate();
    this->qnode.wait();
    //delete &this->qnode;
    ui.pushButton_start->setEnabled(true);
}
*/

/*****************************************************************************
** Implemenation [Slots][manually connected]
*****************************************************************************/

/**
 * This function is signalled by the underlying model. When the model changes,
 * this will drop the cursor down to the last line in the QListview to ensure
 * the user can always see the latest log message.
 */
void MainWindow::updateLoggingView() {
        ui.view_logging->scrollToBottom();
}

void MainWindow::updateImgWidget_main(){
    /*--------- part 1: basler camera ----------*/
    QImage* img_ptr1=qnode.qImg1();
    ui.image_widget->setImage(*img_ptr1);

    /*--------- part 2: IR camera --------------*/
    QImage* img_ptr2=qnode.qImg2();
    ui.front_view->setImage(*img_ptr2);
}


void MainWindow::sentRequestChangeCamPara(unsigned int * roi_ptr, float *eptime_ptr, float *gain_ptr)
{
    ctlnode_ptr->modifyCameraParameter(roi_ptr,*eptime_ptr,*gain_ptr);
    if (!ctlnode_ptr->sendModification())
    {
        MessagePopup(NOSERVICE);
    }
    //ctlnode_ptr->testprintfuntion();
}
/*****************************************************************************
** Implementation [Menu]
*****************************************************************************/

void MainWindow::on_actionAbout_triggered() {
    QMessageBox::about(this, tr("About ..."),tr("<h2>PACKAGE_NAME Test Program 0.10</h2><p>Copyright Yujin Robot</p><p>This package needs an about description.</p>"));
}

/*****************************************************************************
** Implementation [Configuration]
*****************************************************************************/

// set communication's information and display these by string value
void MainWindow::ReadSettings() {
    //QSettings settings("Qt-Ros Package", "class1_ros_qt_demo");
    QSettings settings("config.ini", QSettings::IniFormat);
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());
    QString master_url = settings.value("master_url",QString("http://192.168.1.1:11311/")).toString();
    QString host_url = settings.value("host_url", QString("192.168.1.2")).toString();
    //QString topic_name = settings.value("topic_name", QString("/chatter")).toString();
    ui.line_edit_master->setText(master_url);
    ui.line_edit_host->setText(host_url);
    //ui.line_edit_topic->setText(topic_name);
    bool remember = settings.value("remember_settings", false).toBool();
    ui.checkbox_remember_settings->setChecked(remember);
    bool checked = settings.value("use_environment_variables", false).toBool();
    ui.checkbox_use_environment->setChecked(checked);
    if ( checked ) {
    	ui.line_edit_master->setEnabled(false);
    	ui.line_edit_host->setEnabled(false);
    	//ui.line_edit_topic->setEnabled(false);
    }
}

// remmember settings before MainWindow closed
void MainWindow::WriteSettings() {
    //QSettings settings("Qt-Ros Package", "class1_ros_qt_demo");
    QSettings settings("config.ini", QSettings::IniFormat);
    settings.setValue("master_url",ui.line_edit_master->text());
    settings.setValue("host_url",ui.line_edit_host->text());
    //settings.setValue("topic_name",ui.line_edit_topic->text());
    settings.setValue("use_environment_variables",QVariant(ui.checkbox_use_environment->isChecked()));
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    settings.setValue("remember_settings",QVariant(ui.checkbox_remember_settings->isChecked()));
    /*
     *
    //settings for camera_configure_window UI
    if (camconf_window != nullptr)
    {
        settings.setValue("image_scale_factor",camconf_window->getImageScaleFactor());
        settings.setValue("camera_exposure_time",camconf_window->getExposureTime());
        settings.setValue("camera_gain_factor",camconf_window->getGainFactor());
    }
    else
    {
        //初次打开时的默认值
        settings.setValue("image_scale_factor",1.);
        settings.setValue("camera_exposure_time",5000.);
        settings.setValue("camera_gain_factor",1.);
    }
    */

}

void MainWindow::closeEvent(QCloseEvent *event)
{
	WriteSettings();
	QMainWindow::closeEvent(event);
}

}  // namespace class1_ros_qt_demo

