/**
 * @file /src/node_cam_control.cpp
 *
 * @brief Ros communication central!
 *
 * @date june 2024 by yunfengPeng
 **/

/** routine illustration:  
  * this routine construct client-mode and send request to server( from pylon-camera pkg),
  * then user can adjust camera parameters to see image clearly.
  * concretly: 
   https://github.com/basler/pylon-ros-camera/blob/master/camera_control_msgs/README.rst
*/



/*****************************************************************************
** Includes
*****************************************************************************/
#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include <sstream>
// include for image wireless transportation
#include <image_transport/image_transport.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/highgui/highgui.hpp>

//include head file for customize type of service
#include "camera_control_msgs/SetROI.h"
#include "camera_control_msgs/SetExposure.h"
#include "camera_control_msgs/SetGain.h"

// head file
#include "node_cam_control.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/
namespace class1_ros_qt_demo {

CtrlNode::CtrlNode(int argc, char **argv):
	  init_argc(argc),
	  init_argv(argv)
{
    // defaut member setting
    this->exposure_time=5000.;
    this->gain_factor=0.0;

    // original image size: 4096*3000
    this->roi_region.offset_x=0;
    this->roi_region.offset_y=0;
    this->roi_region.width=4096;
    this->roi_region.height=3000;
}

CtrlNode::~CtrlNode()
{
    if(ros::isStarted()) {
        ros::shutdown(); // explicitly needed since we use ros::start();
        ros::waitForShutdown();
    }
    //wait();
}

void CtrlNode::modifyCameraParameter(const unsigned int *roi, const float &eptime, const float &gain)
{
    this->roi_region.offset_x=*(roi)  -(*(roi)  %4);
    this->roi_region.offset_y=*(roi+1)-(*(roi+1)%2);
    this->roi_region.width   =*(roi+2)-(*(roi+2)%4);
    this->roi_region.height  =*(roi+3)-(*(roi+3)%2);

    this->exposure_time=eptime;
    this->gain_factor=gain;
}

/* 实现不同模式下的服务请求发送：
 * 首先，配置相机参数的窗口中修改了一些参数之后发出相关的信号；
 * 然后，我们根据这个信号绑定一个槽函数来修改所有相机配置参数（该类的成员变量）；
 * 最后，统一发送相关的请求
 */

bool CtrlNode::sendModification()
{
    ros::init(init_argc,init_argv,"class1_ros_qt_demo");
    if(!ros::master::check()){
        return false;
    }
    ros::start(); // explicitly needed since our nodehandle is going out of scope.

    ros::NodeHandle nh;

    //------------------------------------------------------------------------------------------
    //                                       part one
    //------------------------------------------------------------------------------------------
    /* waitForService : 等待服务端运行 */
    ros::service::waitForService(srv_roi_name,ros::Duration(1)); //等待1秒
    if (serviceExistence(srv_roi_name))
    {
        ros::ServiceClient roi_client = nh.serviceClient<camera_control_msgs::SetROI>(srv_roi_name);
        camera_control_msgs::SetROI roi_srv;
        roi_srv.request.target_roi.x_offset=this->roi_region.offset_x;
        roi_srv.request.target_roi.y_offset=this->roi_region.offset_y;
        roi_srv.request.target_roi.width=this->roi_region.width;
        roi_srv.request.target_roi.height=this->roi_region.height;
        roi_srv.request.target_roi.do_rectify=false;

        roi_client.call(roi_srv);
        ROS_INFO("ROI set: %s !",roi_srv.response.success ? "successfull":"failure");
    }
    else
    {
        ROS_INFO("<ROI> parameter service not exist!!");
        return false;
    }  
    //------------------------------------------------------------------------------------------
    //                                       part two
    //------------------------------------------------------------------------------------------
    //ros::service::waitForService(srv_eptime_name,ros::Duration(1));
    if (serviceExistence(srv_eptime_name))
    {
        ros::ServiceClient eptime_client = nh.serviceClient<camera_control_msgs::SetExposure>(srv_eptime_name);
        camera_control_msgs::SetExposure eptime_srv;
        eptime_srv.request.target_exposure=this->exposure_time;

        eptime_client.call(eptime_srv);
        ROS_INFO("Exposure set: %s !",eptime_srv.response.success ? "successfull":"failure");
    }
    else
    {
        ROS_INFO("<Exposure time> parameter service not exist!!");
        return false;
    }
    //------------------------------------------------------------------------------------------
    //                                       part three
    //------------------------------------------------------------------------------------------
    ros::service::waitForService(srv_gain_name,ros::Duration(1));
    if (serviceExistence(srv_gain_name))
    {
        ros::ServiceClient gain_client = nh.serviceClient<camera_control_msgs::SetGain>(srv_gain_name);
        camera_control_msgs::SetGain gain_srv;
        gain_srv.request.target_gain=this->gain_factor;

        gain_client.call(gain_srv);       
        ROS_INFO("Gain set: %s !",gain_srv.response.success ? "successfull":"failure");
    }
    else
    {
        ROS_INFO("<Gain factor> parameter service not exist!!");
        return false;
    }
    
    return true;
}

bool CtrlNode::serviceExistence(const std::string& service_name)
{
    return true;
}

void CtrlNode::testprintfuntion()
{
    //ROS_INFO("ROI : %d",this->roi_region.offset_x);
    //ROS_INFO("can i change roi? => %s",this->serviceExistence(srv_roi_name) ? "yes":"no");
    //ROS_INFO("can i change ept? => %s",this->serviceExistence(srv_eptime_name) ? "yes":"no");
    //ROS_INFO("can i change gain? => %s",this->serviceExistence(srv_gain_name) ? "yes":"no");

    ROS_INFO("ROI : %d",this->roi_region.offset_x);
    ROS_INFO("exposure time: %f us",this->exposure_time);
    ROS_INFO("gain factor: %f us",this->gain_factor);

    ROS_INFO("============================================");
}

}
