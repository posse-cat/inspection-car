/**
 * @file /src/qnode.cpp  rename: node_img_receive.cpp
 *
 * @brief Ros communication central!
 *
 * @date Decemble 2023 by yunfengPeng
 **/

/** routine illustration:
  * this routine recieve data from images published by remote ROS host in car,
  * then display video on QT-gui.
  * IMAGE FROM : Industrial cameras , Infra-red cameras ,
**/

/*****************************************************************************
** Includes
*****************************************************************************/
// include for basic QT-ROS programe
#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include <sstream>
#include <opencv2/opencv.hpp>

//head file
#include "ros_qt_master/node_img_receive.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/
//namespace class2_ros_qt_demo {
//    ros::init()
//    ros::NodeHandle nh;
//    image_transport::ImageTransport it(nh);
//}

namespace class1_ros_qt_demo {

/*****************************************************************************
** Implementation
*****************************************************************************/

QNode::QNode(int argc, char** argv, const std::string tpc1, const std::string tpc2) :
	init_argc(argc),
	init_argv(argv)
	{
        this->basler_cam=tpc1;
        this->IR_cam=tpc2;
    }

QNode::~QNode() {
    if(ros::isStarted()) {
      ros::shutdown(); // explicitly needed since we use ros::start();
      ros::waitForShutdown();
    }
    wait();

    this->cv_ptr1=nullptr;
    this->cv_ptr2=nullptr;
}

bool QNode::rosConncTest(){
    
    ros::init(init_argc,init_argv,"class1_ros_qt_demo");
    if(!ros::master::check()){
        return false;
    }
    ros::start(); // explicitly needed since our nodehandle is going out of scope.
    ros::NodeHandle n;
    log(Info,std::string("Ready to get image:Conncetion to Master!!"));
    return true;
} // function <rosConncTest>

bool QNode::rosConncTest(const std::string &master_url, const std::string &host_url){
    std::map<std::string,std::string> remappings;
    remappings["__master"] = master_url;
    remappings["__hostname"] = host_url;
    //ros::init(remappings,"class1_ros_qt_demo");
    if ( ! ros::master::check() ) {
        return false;
    }
    ros::start(); // explicitly needed since our nodehandle is going out of scope.
    ros::NodeHandle n;
    log(Info,std::string("Ready to get image:Conncetion to Master!!"));
    return true;
} // function <rosConncTest>

/*
bool QNode::rosPublisher() {
    ros::init(init_argc,init_argv,"class1_ros_qt_demo");
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;
	// Add your ros communications here.
	chatter_publisher = n.advertise<std_msgs::String>("chatter", 100);
	start();
	return true;
} // function <rosPublisher>

bool QNode::rosPublisher(const std::string &master_url, const std::string &host_url) {
	std::map<std::string,std::string> remappings;
	remappings["__master"] = master_url;
	remappings["__hostname"] = host_url;
	ros::init(remappings,"class1_ros_qt_demo");
	if ( ! ros::master::check() ) {
		return false;
    }
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;
	// Add your ros communications here.
	chatter_publisher = n.advertise<std_msgs::String>("chatter", 1000);
	start();
	return true;
} // function <rosPublisher>
*/

bool QNode::rosImageReception(){
    ros::init(init_argc,init_argv,"class1_ros_qt_demo");
    if(!ros::master::check()){
        return false;
    }
    ros::start(); // explicitly needed since our nodehandle is going out of scope.
    // Go to QThread
    start();
    return true;
} // function <rosImageReception>

/*QT多线程：QThread类子类的run函数重写 ->
* https://blog.csdn.net/m0_57665952/article/details/129747728
*/

void QNode::run(){
    ros::NodeHandle nh;
    image_transport::ImageTransport it(nh);

    // subscriber for image topic
    image_transport::TransportHints transport_name1("compressed");
    image_transport::TransportHints transport_name2("compressed");
    /*
        ==========>>>>
        2024.8.21反馈：
        ==========>>>>
        image_transport 后台会自动注册一些服务来方便用户控制图像传输过程。
        然而，下面代码中两个订阅者都使用了同一个 “compressed” 方式变量，
        一旦订阅对象执行回调就会根据 命名空间+传输方式+set_parameter 自动注册一个服务，
        导致后台重复注册了一个名为 “/class1_ros_qt_demo/compressed/set_parameters” 的服务。

        **这样一种命名，可能跟ros开发者不主张ros体系内多线程编程方式有关，不考虑有多个图像订阅的情形.      
    */  
    /*-----------------------<recieve basler-camera topic>-------------------------------*/
    image_transport::Subscriber sub1=it.subscribe(this->basler_cam,30,
                                                 &QNode::imgCallbackFunction1,this,
                                                 transport_name1);
    // subscribe without compressed technology
    //image_transport::Subscriber sub1=it.subscribe(this->basler_cam,30,
    //                                             &QNode::imgCallbackFunction,this
    //                                                           );

    /*-------------------------<recieve IR-camera topic>---------------------------------*/
    image_transport::Subscriber sub2=it.subscribe(this->IR_cam,30,
                                                 &QNode::imgCallbackFunction2,this,
                                                 transport_name2);                
    /*-----------------------------execute recurrence------------------------------------*/

    //ros::spin();   ---- is "SingleThreadedSpinner" 

    //multi-thread processor
    //ros::MultiThreadedSpinner spinner(2);
    //spinner.spin();

    ros::AsyncSpinner spinner(2); // Use 2 threads
    spinner.start();
    ros::waitForShutdown();
    
    std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
    Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
} // function <run>
/*void QNode::run() {
	ros::Rate loop_rate(1);
	int count = 0;
	while ( ros::ok() ) {

		std_msgs::String msg;
		std::stringstream ss;
		ss << "hello world " << count;
		msg.data = ss.str();
		chatter_publisher.publish(msg);
		log(Info,std::string("I sent: ")+msg.data);
		ros::spinOnce();
		loop_rate.sleep();
		++count;
	}
	std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
	Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}*/

void QNode::log( const LogLevel &level, const std::string &msg) {
	logging_model.insertRows(logging_model.rowCount(),1);
	std::stringstream logging_model_msg;
	switch ( level ) {
		case(Debug) : {
				ROS_DEBUG_STREAM(msg);
				logging_model_msg << "[DEBUG] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Info) : {
				ROS_INFO_STREAM(msg);
				logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Warn) : {
				ROS_WARN_STREAM(msg);
				logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Error) : {
				ROS_ERROR_STREAM(msg);
				logging_model_msg << "[ERROR] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Fatal) : {
				ROS_FATAL_STREAM(msg);
				logging_model_msg << "[FATAL] [" << ros::Time::now() << "]: " << msg;
				break;
		}
        case(Image):{
                logging_model_msg<<"[IMAGE]  [" << ros::Time::now() << "]: " << msg;
                break;
        }
	}
	QVariant new_row(QString(logging_model_msg.str().c_str()));
	logging_model.setData(logging_model.index(logging_model.rowCount()-1),new_row);
	Q_EMIT loggingUpdated(); // used to readjust the scrollbar
} // function <log>

QImage QNode::cvMatToQImage(const cv::Mat& mat)
{
    switch (mat.type()) {
    case CV_8UC1:{
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);

        image.setColorCount(256);
        for(int i = 0; i < 256; i++){
            image.setColor(i, qRgb(i, i, i));
        }

        uchar *pSrc = mat.data;
        for(int row = 0; row < mat.rows; row ++){
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }

        return image;
    }
        break;
    case CV_8UC3:{
        const uchar *pSrc = (const uchar*)mat.data;
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);

        return image.rgbSwapped();
    }
        break;
    case CV_8UC4:{
        const uchar *pSrc = (const uchar*)mat.data;
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);

        return image.copy();
    }
        break;
    default:
        break;
    }

    return QImage();
}

void QNode::imgCallbackFunction1(const sensor_msgs::ImageConstPtr &msg){
    //cv_bridge::CvImagePtr cv_ptr;
    try
    {
        // another type see:
        // https://blog.csdn.net/sinat_16643223/article/details/121489129
        this->cv_ptr1=cv_bridge::toCvCopy(msg,"mono8");
        // send information to loggingView box
        ros::Time nowtime=ros::Time::now();
        int time=int(nowtime.toSec());
        // set infomation to logging-box
        if ((time%10)==0){
            log(Image,std::string("Get streaming >>"));
        }
        // convert image type
        this->q_img1=this->cvMatToQImage(this->cv_ptr1->image);
        // add the image pre-processing algorithm


        //this->q_show_img=QPixmap::fromImage(this->q_img);
        Q_EMIT imageUpdate();
    }
    catch(cv_bridge::Exception &e)
    {
        ROS_ERROR("cv_bridge exception: %s",e.what());
    }
    return;
} // function <imgCallbackFunction1>

void QNode::imgCallbackFunction2(const sensor_msgs::ImageConstPtr &msg){
    //cv_bridge::CvImagePtr cv_ptr;
    try
    {
        // another type see:
        // https://blog.csdn.net/sinat_16643223/article/details/121489129
        this->cv_ptr2=cv_bridge::toCvCopy(msg,"mono8");
        
        //vertical and horizontal flip
        cv::flip(cv_ptr2->image,cv_ptr2->image,0); //vertical
        cv::flip(cv_ptr2->image,cv_ptr2->image,1); //horizontal

        // convert image type
        this->q_img2=this->cvMatToQImage(this->cv_ptr2->image);
        // add the image pre-processing algorithm


        //this->q_show_img=QPixmap::fromImage(this->q_img);
        Q_EMIT imageUpdate();
    }
    catch(cv_bridge::Exception &e)
    {
        ROS_ERROR("cv_bridge exception: %s",e.what());
    }
    return;
} // function <imgCallbackFunction1>

}  // namespace class1_ros_qt_demo
