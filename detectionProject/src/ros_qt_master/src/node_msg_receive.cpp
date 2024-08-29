/**
 * @file /src/node_msg_receive.cpp
 *
 * @brief Ros communication central!
 *
 * @date Decemble 2023 by yunfengPeng
 **/

/** routine illustration:
  * this routine recieve IMU data which be collected by rasparryPi in car,
  * then subscribe the particular topic and calculate car position.
**/

#include "ros_qt_master/car_tracking.hpp"
#include "std_msgs/String.h"

//head file
#include "ros_qt_master/node_msg_receive.hpp"

namespace class1_ros_qt_demo{

SpNode::SpNode(int argc, char **argv) :
	init_argc(argc),
	init_argv(argv)
{
    pt_ptr = new PointTrack();
    result_arr=new double[6];
}

SpNode::~SpNode()
{
    if(ros::isStarted()) {
      ros::shutdown(); // explicitly needed since we use ros::start();
      ros::waitForShutdown();
    }
    wait();

    if (pt_ptr!=nullptr)
    {
        delete pt_ptr;
    }

    if (result_arr!=nullptr)
    {
        delete result_arr;
    }
}

void SpNode::run()
{
    ros::NodeHandle n;

    std::string topic_name = "IMU_data";

    ros::Subscriber data_sub =n.subscribe
    (topic_name, 10, &class1_ros_qt_demo::SpNode::subscriberCallback,this);
    ros::spin();
}

bool SpNode::rosIMUReception()
{
    ros::init(init_argc,init_argv,"class1_ros_qt_demo");
    if ( ! ros::master::check() ) {
        return false;
    }
    ros::start(); // explicitly needed since our nodehandle is going out of scope.

    start();

    return true;
}

bool SpNode::rosIMUReception(const std::string &master_url, const std::string &host_url)
{
    std::map<std::string,std::string> remappings;
    remappings["__master"] = master_url;
    remappings["__hostname"] = host_url;
    ros::init(remappings,"class1_ros_qt_demo");
    if ( ! ros::master::check() ) {
        return false;
    }
    ros::start(); // explicitly needed since our nodehandle is going out of scope.

    start();

    return true;
}

void SpNode::subscriberCallback(const serial_pkg::KinematicData::ConstPtr &msg_ptr)
{
    // 2024-06-11 目前考虑在回调函数中完成 当前坐标 结算
    double motion_state[4];
    motion_state[0]=msg_ptr->line_velocity;
    motion_state[1]=msg_ptr->roll;
    motion_state[2]=msg_ptr->pitch;
    motion_state[3]=msg_ptr->yaw;

    //调用 PointTrack 类中的方法 计算当前位置坐标
    pt_ptr->coordinateUpdate(motion_state);

    //给结果赋值
    *(result_arr)= motion_state[1];   //roll
    *(result_arr+1)= motion_state[2]; //pitch
    *(result_arr+2)= motion_state[3]; //yaw

    pt_ptr->getCoordinate(result_arr+3); // x y z

    Q_EMIT trackUpdate(result_arr);
}

}// namespace class1_ros_qt_demo

