#include <stdio.h>
#include "Pid.h"

int main(void)
{
    double Kp = 0.6;
    double Ki = 0.08;
    double Kd = 0.04;
    Pid pid(Kp, Ki, Kd);

    double target = 200.0;
    double output = 100.0;
    double task = 0.004;

    double controllValue = Pid.controll(target, output);

    printf("%lf\n", controllValue);
    return 0;
}