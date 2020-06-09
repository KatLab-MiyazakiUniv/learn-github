#ifndef PID_H
#define PID_H
#include "PidGain.h"

class Pid{
    public:
        Pid(double Kp_, double Ki_, double Kd_, double integtal_, double pre_error_);
        double error(double target, double output);
        double i_error(double target, double output, double period);
        double d_error(double target, double output, double period);
        double p_controll(double target, double output);
        double i_controll(double target, double output, double period);
        double d_controll(double target, double output, double period);


    private:
        PidGain gain;
};
#endif