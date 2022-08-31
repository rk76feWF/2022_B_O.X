#include <xc.h>
#include "config.h"
#include "user.h"
#include "function.h"
#include <libpic30.h>
#include <stdio.h>

controller_t controller;

int main(void)
{
    setup();

    while (1)
    {
        char buf[128];
        sprintf(buf, "%3d %3d %3d %3d   %d %d %d %d | %d %d %d %d | %d %d %d %d",                           \
                controller.Lx_scalar, controller.Ly_scalar, controller.Rx_scalar, controller.Ry_scalar,     \
                controller.btn_UP, controller.btn_DOWN, controller.btn_RIGHT, controller.btn_LEFT,          \
                controller.btn_Triangle, controller.btn_Cross, controller.btn_Circle, controller.btn_Square,\
                controller.btn_L1, controller.btn_L2, controller.btn_R1, controller.btn_R2                  \
                );
        prints(buf);
    }

    return 0;
}

void setup(void)
{
    OSCCON = 0x0000;
    _COSC = 0b001;
    _NOSC = 0b001;
    CLKDIV = 0x0000;

    ANSB = 0x0000;
    ANSC = 0x0000;
    ANSD = 0x0000;
    ANSE = 0x0000;
    ANSF = 0x0000;
    ANSG = 0x0000;

    TRISB = 0xffff;
    TRISC = 0xffff;
    TRISD = 0xffff;
    TRISE = 0xffff;
    TRISF = 0xffff;
    TRISG = 0xffff;

    _TRISB13 = 0;
    _TRISB12 = 0;

    setUART();
    setPWM();
    setTimer();

    return;
}
