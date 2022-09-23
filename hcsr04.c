#include <xc.h>
#include "user.h"
#include "function.h"

unsigned int HCSR04_CNT = 0;
static unsigned int first = 0;
static unsigned int second = 0;

void setHCSR04(void)
{
    // Timer2
    T2CON = 0x0000;
    T2CONbits.TCKPS = 0b10; // 1:64
    PR2 = 15000;            // 60ms
    T2CONbits.TON = 1;

    OC7CON1 = 0x0000;
    OC7CON2 = 0x0000;
    OC7CON1bits.OCM = 0b110;
    OC7CON1bits.OCTSEL = 0;        // Timer2
    OC7CON2bits.SYNCSEL = 0b01100; // Timer2
    OC7R = 3;                      // 12us秒のパルスを生成
    _RP10R = 24;

    // Timer3
    // HC-SR04のEchoピンの監視に使っているInput Capture 2用のクロック元
    T3CON = 0x0000;
    T3CONbits.TCKPS = 0b10; // 1:64
    T3CONbits.TON = 1;

    // Input Capture 2
    IC2CON1 = 0x0000;
    IC2CON1bits.ICM = 0b001;    // キャプチャモードを立ち上がり、立ち下がりエッジごと
    IC2CON1bits.ICTSEL = 0b000; // Timer3
    _IC2R = 17;                 // PPSでRP17ピンとIC2モジュールを接続
    _IC2IE = 1;                 // 割り込みを有効化
    _IC2IF = 0;                 // 割り込みのフラグを下げる
    _IC2IP = 1;                 // 割り込み優先度の設定
    return;
}

void __attribute__((interrupt, no_auto_psv)) _IC2Interrupt(void)
{
    if (hcsr04_echo == 1)
        first = IC2BUF;

    if (hcsr04_echo == 0)
    {
        second = IC2BUF;
        if (second > first && second - first > 10)
            HCSR04_CNT = second - first;
    }
    LED2 = ~LED2;

    _IC2IF = 0;
}
