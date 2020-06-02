/**
*   @file  PidGain.h
**/

#ifndef PID_GAIN_H
#define PID_GAIN_H

class PidGain {
    public:
        double Kp;
        double Ki;
        double Kd; 
        double integral;
        double pre_error;
    PidGain(double Kp_, double Ki_, double Kd_, double integral_, double pre_error_);
    void setPidGain(double Kp_, double Ki_, double Kd_, double integral_, double pre_error_);
};

#endif