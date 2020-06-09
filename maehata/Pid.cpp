#include "Pid.h"

Pid::pid(double Kp_, double Ki_, double Kd_)
    gain(Kp_, Ki_, Kd_)
{
}

double Pid::error(double tardet, double output)
{
    return target - output;
}

double Pid::controll(double tardet, double output, double task)
{
    // 操作量 ＝ Kp × 誤差
    return gain.Kp * error(target, output);

}
double Pid::integral(double tardet, double output, double task)
{
    gain.integral += error(target, output) * task;
    return gain.Ki * gain.integral;

}
double Pid::defferent(double tardet, double output, double task)
{
    double tmp = (error(target, putput) - gain.pre_error) / task;
    gain.pre_error = tmp;

    return tmp;
}
