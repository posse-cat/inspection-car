#ifndef ros_qt_demo_two_QNODE_HPP_
#define ros_qt_demo_two_QNODE_HPP_
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
#include <cv_bridge/cv_bridge.h>
/*****************************************************************************
**   Foward Declaration
******************************************************************************

/*****************************************************************************
** Class/Struct
*****************************************************************************/
namespace class1_ros_qt_demo{

//define data struct to set parameter
typedef struct 
{
    /* data */
    unsigned int offset_x;
    unsigned int offset_y;
    unsigned int width;
    unsigned int height;
}RoiPara;
  
class CtrlNode : public QObject
{
    Q_OBJECT
public:
    CtrlNode(int argc, char** argv );
    virtual ~CtrlNode();

    void modifyCameraParameter(const unsigned int *,const float&,const float&);

    bool sendModification();
    bool serviceExistence(const std::string&);


    void testprintfuntion();
    
private:
	int init_argc;
	char** init_argv;

    //service name
    std::string srv_roi_name="/pylon_camera_node/set_roi";
    std::string srv_eptime_name="/pylon_camera_node/set_exposure";
    std::string srv_gain_name="/pylon_camera_node/set_gain";

    //SetMode srv_type;
    RoiPara roi_region;
    float exposure_time;  //因camera_control_msgs功能包中定义的服务数据是float类型的值
    float gain_factor;
};

}
#endif /*class1_ros_qt_demo_two_QNODE_HPP_*/
