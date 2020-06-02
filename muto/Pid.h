#ifndef PID_H
#define PID_H

#include "PidGain.h"

class Pid{
	private:
		PidGain gain;

	public:
		Pid(double Kp_, double Ki_, double Kd_);
		double error(double target, double output);
		double integral(double target, double output, double task, int t);
		double differential(double target, double output, double task);
		double controll(double target, double output);
};

#endif
