#include "PidGain.h"

PidGain::PidGain(double Kp_, double Ki_, double Kd_)
	:Kp(Kp_), Ki(Ki_), Kd(Kd_), integral_temp(0), pre_error(0)
{
}

void PidGain::setPidGain(double Kp_, double Ki_, double Kd_){
	Kp = Kp_;
	Ki = Ki_;
	Kd = Kd_;
	return;
}
