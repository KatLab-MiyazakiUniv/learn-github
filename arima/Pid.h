#ifndef PID_H
#define PID_H

#include "PidGain.h"

class Pid
{
private:
    PidGain gain;
    double integral;
    double preError;

public:
    Pid(double Kp_, double Ki_, double Kd_);
    double error(double target, double current);
    double controll(double target, double current);
};

#endif