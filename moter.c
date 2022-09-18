#include <xc.h>
#include "user.h"
#include "function.h"
#include <stdlib.h>
#include <math.h>

void moter(int num, double power)
{
    int pwm = (int)(fabs(power) * F_CYCLE / 100.0);
    int S1 = 0;
    int S2 = 0;
    if (power > 0)
    {
        S1 = F_CYCLE;
        S2 = F_CYCLE - abs(pwm);
    }
    else if (power == 0)
    {
        S1 = F_CYCLE;
        S2 = F_CYCLE;
    }
    else
    {
        S1 = F_CYCLE - abs(pwm);
        S2 = F_CYCLE;
    }

    switch (num)
    {
    case 1:
        OC1R = S1;
        OC2R = S2;
        break;
    case 2:
        OC3R = S1;
        OC4R = S2;
        break;
    case 3:
        OC5R = S1;
        OC6R = S2;
        break;
    }
    return;
}