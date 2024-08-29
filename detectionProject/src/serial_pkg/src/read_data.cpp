//serial_port.cpp
#include <ros/ros.h>
#include <serial/serial.h>
#include <std_msgs/Float32.h>
#include <iostream>
#include <fstream>
#include "serial_pkg/KinematicData.h"

double parseData_velocity(uint8_t h_byte,uint8_t l_byte)
{
    int total_byte=(h_byte<<8) + l_byte;

    if ((total_byte & 0x8000)==0)
    {
        //最高位0
        
        // mm/s -> m/s
        double result_v = double(total_byte)/1000;
        return result_v;
    }
    else
    {
        //最高位1
        total_byte= 0xffff +1 -total_byte;

        // mm/s -> m/s
        double result_v = (-1)*double(total_byte)/1000;
        return result_v;
    }
    
}

double parseData_accelerate(uint8_t h_byte,uint8_t l_byte)
{
    int total_byte=(h_byte<<8) + l_byte;

    if ((total_byte & 0x8000)==0)
    {
        //最高位0
        
        //  -> m/s2
        double result_v = double(total_byte)/1672;
        return result_v;
    }
    else
    {
        //最高位1
        total_byte= 0xffff +1 -total_byte;

        //  -> m/s2
        double result_v = (-1)*double(total_byte)/1672;
        return result_v;
    }
    
}

/*double pareData_gyroscope(uint8_t h_byte,uint8_t l_byte)
{
    int total_byte=(h_byte<<8) + l_byte;
    if ((total_byte & 0x8000)==0)
    {
        //最高位0
        
        //  -> rad/s
        double result_v = double(total_byte)/3755;
        return result_v;
    }
    else
    {
        //最高位1
        total_byte= 0xffff +1 -total_byte;

        //  -> rad/s
        double result_v = (-1)*double(total_byte)/3755;
        return result_v;
    }
}*/

double pareData_Eulerian(uint8_t h_byte,uint8_t l_byte)
{
    int total_byte=(h_byte<<8) + l_byte;
    if ((total_byte & 0x8000)==0)
    {
        //最高位0
        
        //  -> rad/s
        double result_v = double(total_byte)/100;
        return result_v;
    }
    else
    {
        //最高位1
        total_byte= 0xffff +1 -total_byte;

        //  -> rad/s
        double result_v = (-1)*double(total_byte)/100;
        return result_v;
    }
}


int main(int argc, char** argv)
{
    ros::init(argc, argv, "serial_port");
    //创建句柄（虽然后面没用到这个句柄，但如果不创建，运行时进程会出错）
    ros::NodeHandle n;

    // publish topic with IMU data (100Hz)
	ros::Publisher chatter_publisher = n.advertise<serial_pkg::KinematicData>("IMU_topic", 1000);
    // message
    serial_pkg::KinematicData IMU_msg;
    
    //创建一个serial类
    serial::Serial sp;
    //创建timeout
    serial::Timeout to = serial::Timeout::simpleTimeout(100);
    //设置要打开的串口名称
    sp.setPort("/dev/ttyACM0");
    //设置串口通信的波特率
    sp.setBaudrate(115200);
    //串口设置timeout
    sp.setTimeout(to);

    try
    {
        //打开串口
        sp.open();
    }
    catch(serial::IOException& e)
    {
        ROS_ERROR_STREAM("Unable to open port.");
        return -1;
    }
    
    //判断串口是否打开成功
    if(sp.isOpen())
    {
        ROS_INFO_STREAM("/dev/ttyACM0 is opened.");
    }
    else
    {
        return -1;
    }
    
    ros::Rate loop_rate(100);
    while(ros::ok())
    {
        //获取缓冲区内的字节数
        size_t n = sp.available();
        if(n!=0)
        {
            uint8_t buffer[24];
            //读出数据
            n = sp.read(buffer, n);

            //数据解析结果
            double para[9];
            //报文头
            //int isComplete;

            if (n==24)
            {                
                // x velocity
                para[0]=parseData_velocity(buffer[2],buffer[3]);
                // y velocity
                para[1]=parseData_velocity(buffer[4],buffer[5]);
                // z velocity
                para[2]=parseData_velocity(buffer[6],buffer[7]);


                // x acceleration
                para[3]=parseData_accelerate(buffer[8],buffer[9]);
                // y acceleration
                para[4]=parseData_accelerate(buffer[10],buffer[11]);
                // z acceleration
                para[5]=parseData_accelerate(buffer[12],buffer[13]);


                // roll
                para[6]=pareData_Eulerian(buffer[14],buffer[15]);
                // pitch
                para[7]=pareData_Eulerian(buffer[16],buffer[17]);
                // yaw
                para[8]=pareData_Eulerian(buffer[18],buffer[19]);

                // publish the data after process
                IMU_msg.line_velocity=para[0];
                IMU_msg.roll=para[6];
                IMU_msg.pitch=para[7];
                IMU_msg.yaw=para[8];
                //
                chatter_publisher.publish(IMU_msg);
            }
            else if (n==23)
            {
                // x velocity
                para[0]=parseData_velocity(buffer[1],buffer[2]);
                // y velocity
                para[1]=parseData_velocity(buffer[3],buffer[4]);
                // z velocity
                para[2]=parseData_velocity(buffer[5],buffer[6]);


                // x acceleration
                para[3]=parseData_accelerate(buffer[7],buffer[8]);
                // y acceleration
                para[4]=parseData_accelerate(buffer[9],buffer[10]);
                // z acceleration
                para[5]=parseData_accelerate(buffer[11],buffer[12]);


                // x angle velocity
                para[6]=pareData_Eulerian(buffer[13],buffer[14]);
                // y angle velocity
                para[7]=pareData_Eulerian(buffer[15],buffer[16]);
                // z angle velocity
                para[8]=pareData_Eulerian(buffer[17],buffer[18]);

                // publish the data after process
                IMU_msg.line_velocity=para[0];
                IMU_msg.roll=para[6];
                IMU_msg.pitch=para[7];
                IMU_msg.yaw=para[8];
                //
                chatter_publisher.publish(IMU_msg);
            }
            else 
            {
                std::cout<<"not available data.."<<std::endl;                
                continue;
            }
                        
            //把数据发送回去
            //sp.write(buffer, n);
        }
        loop_rate.sleep();
    }
    
    //关闭串口
    sp.close();
 
    return 0;
}
