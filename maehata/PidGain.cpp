#include "PidGain.h"

PidGain::Pidgain(double Kp_, double Ki_, double Kd_)
    : Kp(Kp_), Ki(Ki_), Kd(Kd_)
{
}

void PidGain::setPidGain(double Kp_, double Ki_, double Kd_)
{
    Kp = Kp_;
    Ki = Ki_;
    Kd = Kd_;

    return;
}