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

void setMoter(void)
{
    OC1CON1 = 0b0001110000000110;
    OC1CON2 = 0b0000000000011111;
    _RP11R = 18;
    OC1R = F_CYCLE;
    OC1RS = F_CYCLE;

    OC2CON1 = 0b0001110000000110;
    OC2CON2 = 0b0000000000011111;
    _RP24R = 19;
    OC2R = F_CYCLE;
    OC2RS = F_CYCLE;

    OC3CON1 = 0b0001110000000110;
    OC3CON2 = 0b0000000000011111;
    _RP23R = 20;
    OC3R = F_CYCLE;
    OC3RS = F_CYCLE;

    OC4CON1 = 0b0001110000000110;
    OC4CON2 = 0b0000000000011111;
    _RP22R = 21;
    OC4R = F_CYCLE;
    OC4RS = F_CYCLE;

    OC5CON1 = 0b0001110000000110;
    OC5CON2 = 0b0000000000011111;
    _RP25R = 22;
    OC5R = F_CYCLE;
    OC5RS = F_CYCLE;

    OC6CON1 = 0b0001110000000110;
    OC6CON2 = 0b0000000000011111;
    _RP20R = 23;
    OC6R = F_CYCLE;
    OC6RS = F_CYCLE;

    return;
}
