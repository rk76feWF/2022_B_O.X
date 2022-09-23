#include <xc.h>
#include "user.h"
#include "function.h"

queue_t uart1;

void setUART(void)
{
    // U1のピンの設定
    _TRISD8 = 1; // RX
    _TRISD9 = 0; // TX
    _U1RXR = 2;  // RX
    _RP4R = 3;   // TX

    // U1モジュールの設定
    U1MODE = 0x0000;
    U1STA = 0x0000;
    U1MODEbits.BRGH = 1;   // 高速ボーレートモード
    U1BRG = 103;           // ボーレート設定
    _U1RXIE = 1;           // 割り込みを有効化
    _U1RXIF = 0;           // 割り込みのフラグを下げる
    _U1RXIP = 7;           // 割り込み優先度の設定
    U1MODEbits.UARTEN = 1; // UART有効化
    U1STAbits.UTXEN = 1;   // 送信有効化

    return;
}

void __attribute__((interrupt, no_auto_psv)) _U1RXInterrupt(void)
{
    enqueue(&uart1, U1RXREG);
    _U1RXIF = 0;
}

void prints(char *text)
{
    U1TXREG = 0x0a;
    U1TXREG = 0x0d;

    while (*text != '\0')
    {
        while (U1STAbits.TRMT == 0)
            ;
        U1TXREG = *text++;
    }

    return;
}
