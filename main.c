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

    data_t c = 0x00;
    while (c != 'a')
        dequeue(&uart1, &c);
    c = 0;

    while (1)
    {
        __delay_ms(1);
    }

    return 0;
}
