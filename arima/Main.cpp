#include <stdio.h>
#include "Pid.h"

int main(void)
{
    double Kp = 0.6;
    double Ki = 0.08;
    double Kd = 0.04;
    Pid pid(Kp, Ki, Kd);

    double target = 200.0;
    double current = 100.0;
    double ctrlValue = 0.0;

    for (int i = 0; i < 20; i++)
    {
        printf("%lf\n", current);
        ctrlValue = pid.controll(target, current);
        current = current + ctrlValue;
    }
    return 0;
}