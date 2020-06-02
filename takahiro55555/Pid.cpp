#include "Pid.hpp"

Pid::Pid(double Kp_, double Ki_, double Kd_, double INTERVAL_SEC_)
    : gain(Kp_, Ki_, Kd_), INTERVAL_SEC(INTERVAL_SEC_)
{
}

double Pid::error(double target, double output)
{
    return target - output;
}

double Pid::controll(double target, double output)
{
    double errorValue = error(target, output);  // 誤差を算出
    integral += errorValue * INTERVAL_SEC;  // 誤差の累積値を更新
    
    double controllValue = gain.Kp * errorValue;  // P値
    controllValue += gain.Ki * integral;  // I値
    controllValue += gain.Kd * (errorValue - beforeErrorValue) / INTERVAL_SEC;  // D値
    
    beforeErrorValue = errorValue;  // 今回の誤差をメンバ変数に格納して保存

    return controllValue;
}