/**
 * @file /include/class1_ros_qt_demo/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef ros_qt_demo_QNODE_HPP_
#define ros_qt_demo_QNODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

// To workaround boost/qt4 problems that won't be bugfixed. Refer to
//    https://bugreports.qt.io/browse/QTBUG-22829
#ifndef Q_MOC_RUN
#include <ros/ros.h>
#endif
#include <QThread>

// include for image wireless transportation
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/highgui/highgui.hpp>

#include <QThread>
#include <QStringListModel>
#include <QImage>
#include <QPixmap>

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace class1_ros_qt_demo {

/*****************************************************************************
** Class
*****************************************************************************/

class QNode : public QThread {
    Q_OBJECT
public:
	QNode(int argc, char** argv, const std::string,const std::string);
	virtual ~QNode();
    //bool rosPublisher();
    //bool rosPublisher(const std::string &master_url, const std::string &host_url);
	void run();
    //add test function
    bool rosConncTest();
    bool rosConncTest(const std::string &master_url, const std::string &host_url);
    //recieve the image from ROS master
    bool rosImageReception();
    bool rosImageReception(const std::string &master_url, const std::string &host_url);
    //read frame rate from topic ""
    //reiever's callback function;
    void imgCallbackFunction1(const sensor_msgs::ImageConstPtr &msg);
    void imgCallbackFunction2(const sensor_msgs::ImageConstPtr &msg);
    // convertion
    QImage cvMatToQImage(const cv::Mat& mat);
	/*********************
	** Logging
	**********************/
	enum LogLevel {
	         Debug,
	         Info,
	         Warn,
	         Error,
             Fatal,
             Image
	 };

	QStringListModel* loggingModel() { return &logging_model; }
	void log( const LogLevel &level, const std::string &msg);

    QImage* qImg1() { return &q_img1; }
    QImage* qImg2(){ return &q_img2; }

Q_SIGNALS:
    void imageUpdate();
	void loggingUpdated();
    void rosShutdown();

private:
	int init_argc;
	char** init_argv;
    // image topic name
    //std::string topic_name="/pylon_camera_node/image_raw";
    std::string basler_cam,IR_cam;
    //std::string topic_name="testNode/houseBoy";
    ros::Publisher chatter_publisher;
    // https://blog.csdn.net/qq_35412059/article/details/126068079
    // <user-manual> for class %QStringListModel%
    QStringListModel logging_model;

    // <opencv> type imgaes
    // note: cv_Mat img  <==> cv_ptr->imgae
    cv_bridge::CvImagePtr cv_ptr1;
    cv_bridge::CvImagePtr cv_ptr2;
    // <QT> type images
    QImage q_img1;
    QImage q_img2;
    //QPixmap q_show_img;

};

}  // namespace class1_ros_qt_demo

#endif /* class1_ros_qt_demo_QNODE_HPP_ */
