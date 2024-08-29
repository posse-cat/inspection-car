# include <ros/ros.h>
# include "testboy/person.h"


int main(int argc,char **argv){
	
	ros::init(argc,argv,"test01");
	
	ros::NodeHandle n;
	
	ros::Publisher person_info_pub =n.advertise<testboy::person>("/person",10);
	
	ros::Rate loop_rate(1);
	
    //int count=0;
	
	while(ros::ok())
	{
		testboy::person person_message;
		person_message.name="pp";
		person_message.age=25;
		person_message.gender=testboy::person::male;
		
		person_info_pub.publish(person_message);
		
		ROS_INFO("name:%s  age:%d  gender:%d",
		          person_message.name.c_str(),person_message.age,person_message.gender);
		
		loop_rate.sleep();
	}
	
	return 0;
}
