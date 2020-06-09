#ifndef PID_H
#define PID_H
#include "PidGain.h"

class PidGain
{
private:
    PidGain gain;

public:
    Pid(double Kp_, double Ki_, double Kd_);
    double error(double target, double output);
    double controll(double target, double output, double task);
    double Differential(double target, double output, double task); 
    double controll(double target, double output); 


};

#endif