#include <xc.h>
#include "user.h"
#include "function.h"

queue_t testtest;

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

    // U2のピンの設定
    // _TRISF5 = 1; // RX
    // _TRISF4 = 0; // TX
    // _U2RXR = 17; // RX
    // _RP10R = 5;  // TX

    // U2モジュールの設定
    // U2MODE = 0x0000;
    // U2STA = 0x0000;
    // U2MODEbits.BRGH = 1;   // 高速ボーレートモード
    // U2BRG = 103;           // ボーレート設定
    // _U2RXIE = 1;           // 割り込みを有効化
    // _U2RXIF = 0;           // 割り込みのフラグを下げる
    // _U2RXIP = 7;           // 割り込み優先度の設定
    // U2MODEbits.UARTEN = 1; // UART有効化
    // U2STAbits.UTXEN = 1;   // 送信有効化

    return;
}

void __attribute__((interrupt, no_auto_psv)) _U1RXInterrupt(void)
{
    enqueue(&testtest, U1RXREG);
    _U1RXIF = 0;
}

void __attribute__((interrupt, no_auto_psv)) _U2RXInterrupt(void)
{
    //    U2TXREG = U2RXREG;
    _U2RXIF = 0;
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
