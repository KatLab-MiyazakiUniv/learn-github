#include "Pid.h"

Pid::pid(double Kp_, double Ki_, double Kd_)
    gain(Kp_, Ki_, Kd_)
{
}

double Pid::error(double tardet, double output)
{
    return target - output;
}

double Pid::controll(double tardet, double output)
{
    // 操作量 ＝ Kp × 誤差
    return gain.Kp * error(target, output);
}