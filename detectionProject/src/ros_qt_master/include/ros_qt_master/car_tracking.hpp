#ifndef CAR_TRACKING_HPP_
#define CAR_TRACKING_HPP_
#include <math.h>
#include <Eigen/Dense>
#include <iostream>

using namespace std;
using namespace Eigen;

#define PI_DOUBLE 3.1415926535897931

class PointTrack {
public:
    PointTrack();
    ~PointTrack();

    //interface to execute co-ordinate update
    //----> according to "the current state of motion"
    void coordinateUpdate(const double*);
    //get current position
    void getCoordinate(double *);

protected:
    // use to iteration on the state of motion
    void setPreviousState(const double*);
    void setCurrentState(const double*);

    // achieve the co-ordinate resolving
    void calculateIncrement();

private:
    //线速度
    double velocity_prv,velocity_cur;
    //姿态角
    double roll_prv,pitch_prv,yaw_prv;
    double roll_cur,pitch_cur,yaw_cur;
    //采样率 50HZ
    int sam_rate=50;

    //计算矩阵
    Vector3d DrtX;
    Matrix3d Tx,Ty,Tz;    
    Matrix3d T,T1;

    //空间位置坐标
    double c_x,c_y,c_z;

};

#endif
