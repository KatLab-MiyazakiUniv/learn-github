#include "Pid.h"

Pid::Pid(double Kp_, double Ki_, double Kd_, double integral_, double pre_error_) : gain(Kp_, Ki_, Kd_, integral_, pre_error_) {}

// 誤差
double Pid::error(double target, double output)
{
    return target - output;
}

// 誤差の累積値
double Pid::i_error(double target, double output, double period)
{
    gain.integral += error(target, output) * period;
    return gain.integral;
}

// 今回の誤差 - 前回の誤差
double Pid::d_error(double target, double output, double period)
{
    double d_error = (error(target, output) - gain.pre_error) / period; 
    gain.pre_error = error(target, output); 
    return  d_error;
}

// P制御
double Pid::p_controll(double target, double output)
{
    return gain.Kp * error(target, output);
}

// I制御
double Pid::i_controll(double target, double output, double period)
{
    return gain.Ki * i_error(target, output, period);
}

// D制御
double Pid::d_controll(double target, double output, double period)
{
    return gain.Kd * d_error(target, output, period);
}
