#include "Pid.h"

Pid::Pid(double Kp_, double Ki_, double Kd_)
    : gain(Kp_, Ki_, Kd_), integral(0.0), preError(0.0)
{
}

double Pid::error(double target, double current)
{
    return target - current;
}

double Pid::controll(double target, double current)
{
    double currentError = error(target, current);
    integral += (target - current) * 0.004;
    double diff = (currentError - preError) * 0.004;
    preError = currentError;

    double ctrlValue = gain.Kp * currentError + gain.Ki * integral + gain.Kd * diff;

    return ctrlValue;
}