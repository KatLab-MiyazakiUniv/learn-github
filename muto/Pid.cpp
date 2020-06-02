#include "Pid.h"

Pid::Pid(double Kp_, double Ki_, double Kd_)
	:gain(Kp_, Ki_, Kd_)
{
}

double Pid::error(double target, double output){
	return target - output;
}

double Pid::Integral(double target, double output, double task){
	gain.integral += error(target, output) * task;
	return gain.Ki * gain.integral;
}

double Pid::Defferential(double target, double output, double task){
	(error(target, output) - gain.pre_error) / task;
	return (error(target, output) - gain.pre_error) / task;

double Pid::controll(double target, double output){
	return gain.Kp * error(target, output);
}
