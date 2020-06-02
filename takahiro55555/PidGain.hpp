#ifndef ET_ROBOT_PID_GAIN_H
#define ET_ROBOT_PID_GAIN_H

class PidGain
{
public:
    double Kp, Ki, Kd;
    PidGain(double Kp_, double Ki_, double Kd_);
    void setPidGain(double Kp_, double Ki_, double Kd_);
};

#endif