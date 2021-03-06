#ifndef PID_GAIN_H
#define PID_GAIN_H

class PidGain
{
public:
    double Kp;
    double Ki;
    double Kd;
    PidGain(double Kp_, double Ki_, double Kd_);
    void setPidGain(double Kp_, double Ki_, double Kd_);
};

#endif