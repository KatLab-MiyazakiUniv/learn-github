#ifndef PID_GAIN_H
#define PID_GAIN_H

class PidGain
{
public:
    double Kp;
    double Ki;
    double Kd;
    double integral;
    double pre_error;

    PidGain(double Kp_, double Ki_, double Kd_,)
    void setPidGain(double Kp_, double Ki_, doubleKd_);
};

#endif
