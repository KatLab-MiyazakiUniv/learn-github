#include<stdio.h>
#include "Pid.h"

int main(void)
{
    double Kp = 0.6;
    double Ki = 0.08;
    double Kd = 0.04; 
    double integral = 0.0; // 誤差の累積値を格納する変数
    double pre_error = 0.0; // 前回の誤差を格納する変数
    Pid pid(Kp, Ki, Kd, integral, pre_error);
    double target = 200.0; //目標値
    double output = 100; //現在地
    double period = 0.004; //周期

    double controllvalue = pid.p_controll(target, output) + pid.i_controll(target, output, period) + pid.d_controll(target, output, period);
    
    printf("%lf\n", controllvalue);
    return 0;
}