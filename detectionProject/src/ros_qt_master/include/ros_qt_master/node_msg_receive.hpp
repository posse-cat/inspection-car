#ifndef ros_qt_demo_thr_QNODE_HPP_
#define ros_qt_demo_thr_QNODE_HPP_
/*****************************************************************************
** Includes
*****************************************************************************/
// To workaround boost/qt4 problems that won't be bugfixed. Refer to
//    https://bugreports.qt.io/browse/QTBUG-22829
#ifndef Q_MOC_RUN
#include <ros/ros.h>
#endif
#include <string>
#include <QThread>
#include "serial_pkg/KinematicData.h"

/*****************************************************************************
**   Foward Declaration
*****************************************************************************/
class PointTrack;

/*****************************************************************************
** Class
*****************************************************************************/
namespace class1_ros_qt_demo{
// To recieve the data from topic(IMU data in this project)
class SpNode : public QThread
{
    Q_OBJECT
public:
    SpNode(int argc, char** argv);
    virtual ~SpNode();
    void run();

    //recieve the IMU-data from ROS master
    bool rosIMUReception();
    bool rosIMUReception(const std::string &master_url, const std::string &host_url);

    void subscriberCallback(const serial_pkg::KinematicData::ConstPtr &msg);

Q_SIGNALS:
    void trackUpdate(double *);

private:
    int init_argc;
	char** init_argv;
    PointTrack *pt_ptr;
    double *result_arr; // roll pitch yaw x y z
};

}

#endif /*class1_ros_qt_demo_thr_QNODE_HPP_*/
