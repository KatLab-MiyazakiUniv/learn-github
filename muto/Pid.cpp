#include "Pid.h"

Pid::Pid(double Kp_, double Ki_, double Kd_)
	:gain(Kp_, Ki_, Kd_)
{
}

double Pid::error(double target, double output){
	return target - output;
}

double Pid::integral(double target, double output, double period){
	gain.integral_temp += error(target, output) * period;
	return gain.Ki * gain.integral_temp;
}

double Pid::differential(double target, double output, double period){
	double temp = (error(target, output) - gain.pre_error) / period;
	gain.pre_error = temp;
	return temp;
}

double Pid::controll(double target, double output){
	return gain.Kp * error(target, output);
}
