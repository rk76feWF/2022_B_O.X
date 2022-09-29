#include <xc.h>
#include "config.h"
#include "user.h"
#include "function.h"
#include <libpic30.h> // delay

extern queue_t uart1;
extern int ENCODER_CNT;
extern unsigned int HCSR04_CNT;

int main(void)
{
    setup();

    __delay_UART(0x88); // 0x88が送られてくるまで待機

    while (1)
    {
        LED3 = 1;
        moter(1, -50);
        __delay_ms(100);

        while (HCSR04_CNT > 100)
            ;

        moter(1, -100);
        __delay_ms(1000);

        while (HCSR04_CNT < 100)
            ;

        __delay_ms(1000);
        LED3 = 0;
        moter(1, 0);

        __delay_ms(1000);
        solenoid2 = 1;
        __delay_ms(500);
        solenoid1 = 1;
        __delay_ms(500);
        solenoid2 = 0;

        controller();

        solenoid1 = 0;
        __delay_ms(100);
        solenoid2 = 1;
        __delay_ms(1500);
        solenoid2 = 0;
        __delay_ms(1500);
    }
    return 0;
}

void controller(void)
{
    data_t tmp = 0x00;
    while (dequeue(&uart1, &tmp) == 0)
        ;
    tmp = 0x00;
    while (1)
    {
        dequeue(&uart1, &tmp);
        switch (tmp)
        {
        case 0x66:
            // 展開機構左回転
            break;
        case 0x77:
            // 展開機構右回転
            break;
        case 0x88:
            // 射出シーケンスへ
            return;
            break;
        default:
            // 射出機構回転停止
            break;
        }
    }
}
