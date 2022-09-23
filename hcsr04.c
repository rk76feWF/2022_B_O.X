#include <xc.h>
#include "user.h"
#include "function.h"
#include <libpic30.h>

unsigned int HCSR04_CNT = 0;
static unsigned int first = 0;
static unsigned int second = 0;

void setHCSR04(void)
{
    // Timer2
    // 60msごとにタイマ割り込みで10usのパルスを生成。
    T2CON = 0x0000;
    T2CONbits.TCKPS = 0b11;
    PR2 = 3750;
    _T2IP = 1;
    _T2IF = 0;
    _T2IE = 1;
    T2CONbits.TON = 1;

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

void __attribute__((interrupt, no_auto_psv)) _T2Interrupt(void)
{
    // 10usのパルス生成
    hcsr04_trig = 1;
    __delay_us(10);
    hcsr04_trig = 0;

    _T2IF = 0;
}
