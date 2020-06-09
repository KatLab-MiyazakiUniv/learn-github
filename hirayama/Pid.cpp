#include "Pid.h"

// タスク周期
const double TASK_TIME = 0.004;

// p制御
Pid::Pid(double Kp_, double Ki_, double Kd_)
    : gain(Kp_, Ki_, Kd_)
{    
}

double Pid::error(double target, double output)
{
    return target - output;
}

double Pid::controll(double target, double output)
{
    //操作量　= kp * 誤差（引数あり）
    //kp * 
    return 
    gain.Kp * error(target, output) + 
    gain.Ki * pid_sum(target, output) + 
    gain.Kd * pid_dt(target, output);
}

//　積分（i制御）誤差の累積地*タスク周期
double Pid::pid_sum(double target, double output)
{
    static double errorSum; // 誤差の累積値 
    errorSum += error(target, output) * TASK_TIME;
    return errorSum;
}

//　微分（d制御）= (前回の誤差‐今回の誤差)*タスク周期
double Pid::pid_dt(double target, double output)
{
    static double beforeError; // 前回の誤差
    double nowError = error(target, output); // 今回の誤差
    
    // 過去の更新
    beforeError = nowError;
    return (nowError - beforeError)/TASK_TIME;

}





