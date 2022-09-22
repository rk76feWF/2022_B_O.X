#include <xc.h>
#include "config.h"
#include "user.h"
#include "function.h"
#include <libpic30.h>

int ENCODER_CNT = 0;
extern queue_t testtest;

int main(void)
{
    setup();
    data_t c = 0x00;

    while (c != 'a')
        dequeue(&testtest, &c);
    c = 0;

    while (1)
    {
        hcsr04_a = 1;
        __delay_us(10);
        hcsr04_a = 0;

        while (hcsr04_b != 1)
            ;

        LED2 = ~LED2;

        __delay_ms(60);
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

    // HC-SR04
    _TRISF4 = 0; // Output
    _TRISF5 = 1; // Input

    return;
}