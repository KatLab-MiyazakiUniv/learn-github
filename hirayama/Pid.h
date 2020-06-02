#ifndef PID_H
#define PID_HP
#include "PidGain.h"

class Pid 
{
    private:
        //メンバ変数
        PidGain gain;
    public:
        //コンストラクタ
        Pid(double Kp_, double Ki_, double Kd_);
        double error(double target, double output);
        double controll(double target, double output);
        double pid_sum(double target, double output);
        double pid_dt(double target, double output);
};

#endif