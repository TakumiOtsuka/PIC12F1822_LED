/*
 * File:   main.c
 * Author: Takumi
 *
 * Created on 2018/12/18, 21:24
 */


#include <xc.h>

#define _XTAL_FREQ 4000000

// コンフィギュレーション1の設定
#pragma config FOSC = INTOSC  // 内部クロックを使用
#pragma config WDTE = OFF  // ウォッチドッグ・タイマなし
#pragma config PWRTE = ON  // 電源ONから64ms後にプログラムを開始する
#pragma config MCLRE = OFF  // 外部リセット信号は使用せずにデジタル入力(RA3)ピンとする
#pragma config CP = OFF  // プログラムメモリを保護しない
#pragma config CPD = OFF  // データメモリを保護しない
#pragma config BOREN = ON  // 電源電圧降下常時監視機能ON
#pragma config CLKOUTEN = OFF  // CLKOUTピンをRA4ピンで使用する
#pragma config IESO = OFF  // 外部・内部クロックの切り替えでの起動はなし
#pragma config FCMEN = OFF  // 外部クロック監視しない

// コンフィギュレーション2の設定
#pragma config WRT = OFF  // Flashメモリを保護しない
#pragma config PLLEN = OFF  // 動作クロックを32MHzでは動作させない
#pragma config STVREN = ON  // スタックがオーバフローやアンダーフローしたらリセットする
#pragma config BORV = HI  // 電源電圧降下常時監視電圧(2.5V)設定(HI)
#pragma config LVP = OFF  // 低電圧プログラミング機能を使用しない

// 指定した時間(num x 10ms)ウェイトする関数
void Wait(unsigned int num)
{
    int i;
    for (i = 0; i < num; i++) {
        __delay_ms(10);
    }
}

void main(void)
{
    OSCCON = 0b01101010;  // 内部クロックは4MHzとする
    ANSELA = 0b00000000;  // アナログは使用しない
    TRISA = 0b00001000;  // ピンはすべて出力に割り当てる(RA3は入力)
    PORTA = 0b00000000;  // 出力ピンの初期化(LOW)
    
    while (1) {
        RA2 = 1;  // 5番ピン(RA2)にHIGH(5V)を出力(LED ON)
        Wait(100);
        RA2 = 0;  // 5番ピン(RA2)にLOWを出力(LED OFF)
        Wait(100);
    }
    return;
}
