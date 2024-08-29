#include "../include/ros_qt_master/car_tracking.hpp"

PointTrack::PointTrack()
{
    this->DrtX << 1. , 0. ,0.;

    //初始时刻状态: roll =pitch =yaw =0
    //            velocity =0
    roll_prv =0.;
    pitch_prv=0.;
    yaw_prv  =0.;
    velocity_prv =0.;

    //初始时刻位置：
    c_x=0.;
    c_y=0.;
    c_z=0.;

}

PointTrack::~PointTrack()
{

}

void PointTrack::setPreviousState(const double * state_arr) 
{
    /*
    state_arr[0] = previous line velocity   ----- m/s

    state_arr[1] = previous Roll            ----- 度
    state_arr[2] = previous Pitch           ----- 度
    state_arr[3] = previous Yaw             ----- 度
    */

    this->velocity_prv =*(state_arr+0);
    this->roll_prv     =*(state_arr+1) * PI_DOUBLE / 180.; //rad
    this->pitch_prv    =*(state_arr+2) * PI_DOUBLE / 180.;
    this->yaw_prv      =*(state_arr+3) * PI_DOUBLE / 180.;


}

void PointTrack::setCurrentState(const double * state_arr)
{
    /*
    state_arr[0] = current line velocity   ----- m/s

    state_arr[1] = current Roll            ----- 度
    state_arr[2] = current Pitch           ----- 度
    state_arr[3] = current Yaw             ----- 度
    */

    this->velocity_cur =*(state_arr+0);
    this->roll_cur    =*(state_arr+1) * PI_DOUBLE / 180.; //rad
    this->pitch_cur    =*(state_arr+2) * PI_DOUBLE / 180.;
    this->yaw_cur      =*(state_arr+3) * PI_DOUBLE / 180.;
}

void PointTrack::calculateIncrement()
{
    double l = (velocity_cur+velocity_prv)/double(sam_rate)/2.;

    //cout<< l <<endl;

    //----------------------------------------------------------
    this->Tx <<  1,            0,             0,
                 0,cos(roll_prv),-sin(roll_prv),
                 0,sin(roll_prv), cos(roll_prv);

    this->Ty <<  cos(pitch_prv), 0,sin(pitch_prv),
                 0,              1,             0,
                 -sin(pitch_prv),0,cos(pitch_prv);             

    this->Tz <<  cos(yaw_prv),-sin(yaw_prv),0,
                 sin(yaw_prv), cos(yaw_prv),0,
                 0,                       0,1;

    this->T=Tz*Ty*Tx;
    //----------------------------------------------------------
    this->Tx <<  1,            0,             0,
                 0,cos(roll_cur),-sin(roll_cur),
                 0,sin(roll_cur), cos(roll_cur);

    this->Ty <<  cos(pitch_cur), 0,sin(pitch_cur),
                 0,              1,             0,
                 -sin(pitch_cur),0,cos(pitch_cur);             

    this->Tz <<  cos(yaw_cur),-sin(yaw_cur),0,
                 sin(yaw_cur), cos(yaw_cur),0,
                 0,                       0,1;             

    this->T1=Tz*Ty*Tx;
    //----------------------------------------------------------
    Vector3d DrtX1 = T  * DrtX;
    Vector3d DrtX2 = T1 * DrtX;
    // Vector 默认按照列来存储，这一点与上面的 Matrix类型不同
    double LL = DrtX1.transpose() * DrtX2;

    //
    double oox;
    if (LL >1)
    {
        // 有时候因为计算机存储误差导致LL略微大于1
        oox=0.;        
    }
    else
    {
        oox = acos(LL);
    }
    
    //
    Vector3d displacement;
    double R;
    if (abs(oox)>1e-5)
    {
        R=l/(oox);
        displacement(0)= R*sin(oox);
        displacement(1)= R*(1.-cos(oox));
        displacement(2)= 0.;
    }
    else
    {
        displacement(0)= l*cos(oox);
        displacement(1)= l*sin(oox);
        displacement(2)= 0.;
    }

    displacement = T * displacement;

    //
    c_x+=displacement(0);
    c_y+=displacement(1);
    c_z+=displacement(2);

}

void PointTrack::coordinateUpdate(const double * current_state)
{
    this->setCurrentState(current_state);

    this->calculateIncrement();

    this->setPreviousState(current_state);
}

void PointTrack::getCoordinate(double * xyz_ptr)
{        
    *(xyz_ptr)=this->c_x;
    *(xyz_ptr+1)=this->c_y;
    *(xyz_ptr+2)=this->c_z;
}
