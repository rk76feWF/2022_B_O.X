#include <xc.h>
#include "config.h"
#define FCY 16000000UL
#include <libpic30.h>

#define LED1 _LATE3
#define LED2 _LATE2
#define LED3 _LATE1
#define BTN _RF3

void setup(void);

int main(void)
{
    setup();

    while (BTN)
        ;

    while (1)
    {
        LED1 = ~LED1;
        __delay_ms(1000);
        LED2 = ~LED2;
        __delay_ms(1000);
        LED3 = ~LED3;
        __delay_ms(1000);
    }

    return 0;
}

void setup(void)
{
    OSCCON = 0x0000;
    _COSC = 0b001; // FRCPLL
    _NOSC = 0b001; // FRCPLL
    CLKDIV = 0x0000;

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

    return;
}