#include <xc.h>
#include "config.h"
#include "user.h"
#include "function.h"
#include <libpic30.h>

int ENCODER_CNT = 0;

int main(void)
{
    setup();

    while (BTN)
        ;

    OC1R = 50;
    OC2R = 100;
    OC3R = 150;
    OC4R = 200;
    OC5R = 250;
    OC6R = 300;

    while (1)
    {
        ENCODER_CNT = 0;
        while (ENCODER_CNT <= 100)
            ;
        LED1 = ~LED1;
        __delay_ms(1000);
        LED2 = ~LED2;
        __delay_ms(1000);
        LED3 = ~LED3;
        __delay_ms(1000);

        solenoid1 = ~solenoid1;
        __delay_ms(1000);
        solenoid1 = ~solenoid1;

        solenoid2 = ~solenoid2;
        __delay_ms(1000);
        solenoid2 = ~solenoid2;

        solenoid3 = ~solenoid3;
        __delay_ms(1000);
        solenoid3 = ~solenoid3;

        solenoid4 = ~solenoid4;
        __delay_ms(1000);
        solenoid4 = ~solenoid4;

        solenoid5 = ~solenoid5;
        __delay_ms(1000);
        solenoid5 = ~solenoid5;

        solenoid6 = ~solenoid6;
        __delay_ms(1000);
        solenoid6 = ~solenoid6;
    }

    return 0;
}

void setup(void)
{
    OSCCON = 0x0000;
    _COSC = 0b001; // FRCPLL
    _NOSC = 0b001; // FRCPLL
    CLKDIV = 0x0000;

    setIO();
    setUART();
    setIC();
    setPWM();

    return;
}

void setIO(void)
{
    // Analog or Digital
    ANSB = 0x0000;
    ANSC = 0x0000;
    ANSD = 0x0000;
    ANSE = 0x0000;
    ANSF = 0x0000;
    ANSG = 0x0000;

    // Input or Output
    TRISB = 0xffff;
    TRISC = 0xffff;
    TRISD = 0xffff;
    TRISE = 0xffff;
    TRISF = 0xffff;
    TRISG = 0xffff;

    _TRISE3 = 0; // LED1
    _TRISE2 = 0; // LED2
    _TRISE1 = 0; // LED3

    _TRISF3 = 1; // ボタン

    // solenoid
    _TRISB12 = 0;
    _TRISB13 = 0;
    _TRISB14 = 0;
    _TRISB15 = 0;
    _TRISB7 = 0;
    _TRISB6 = 0;

    return;
}