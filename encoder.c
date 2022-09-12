#include <xc.h>
#include "user.h"
#include "function.h"

extern int ENCODER_CNT;

void setIC(void)
{
    // Input Capture 1
    IC1CON1 = 0x0000;
    IC1CON1bits.ICM = 0b011; // キャプチャモードを毎回の立ち上がりエッジごとに設定
    _IC1R = 13;              // PPSでRP13ピンとIC1モジュールを接続
    _IC1IE = 1;              // 割り込みを有効化
    _IC1IF = 0;              // 割り込みのフラグを下げる
    _IC1IP = 1;              // 割り込み優先度の設定

    return;
}

void __attribute__((interrupt, no_auto_psv)) _IC1Interrupt(void)
{
    if (_RB4)
        ENCODER_CNT++;
    else if (~_RB4)
        ENCODER_CNT--;

    _IC1IF = 0;
}
