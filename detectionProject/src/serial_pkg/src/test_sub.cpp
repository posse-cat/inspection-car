#include <ros/ros.h>
#include <iostream>
#include "serial_pkg/KinematicData.h"

void subCallBack(const serial_pkg::KinematicData::ConstPtr &msg)
{
    //ROS_INFO("KinematicData: %s,%d,%.2f",person->name.c_str(),person->age,person->height);
    ROS_INFO("KinematicData: %d ",msg->roll);
}

int main(int argc ,char **argv){

    ros::init(argc,argv,"demo01");
    std::string topic_name = "data_topic";  
    ros::NodeHandle nh;

    ros::Subscriber IMU_sub = nh.subscribe(topic_name,10,&subCallBack);

    ros::spin();

    return 0;
} //
