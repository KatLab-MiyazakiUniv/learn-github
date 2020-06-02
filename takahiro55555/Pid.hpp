#ifndef ET_ROBOT_PID_H
#define ET_ROBOT_PID_H

#include "PidGain.hpp"

class Pid
{
private:
    const double INTERVAL_SEC;
    
    PidGain gain;
    double integral = 0.0;  // 誤差の累積値
    double beforeErrorValue = 0.0;  // 前回の誤差

public:
    Pid(double Kp_, double Ki_ = 0.0, double Kd_ = 0.0, double INTERVAL_SEC_ = 0.02);
    double error(double target, double output);
    double controll(double target, double output);
};

#endif