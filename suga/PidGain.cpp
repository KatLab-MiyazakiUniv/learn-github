#include "PidGain.h"

PidGain::PidGain(double Kp_, double Ki_, double Kd_, double integral_, double pre_error_) : Kp(Kp_), Ki(Ki_), Kd(Kd_), integral(integral_), pre_error(pre_error_) {}

void PidGain::setPidGain(double Kp_, double Ki_, double Kd_, double integral_, double pre_error_) 
{
    Kp = Kp_;
    Ki = Ki_;
    Kd = Kd_;
    integral = integral_;
    pre_error = pre_error_;

    return;
}