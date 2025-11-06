#include <kernel.h>
#include <t_syslog.h>
#include "kernel_cfg.h"
#include "report9-2.h"

#include <stdlib.h>              // exit() を使うため
#include "spike/hub/display.h"   // Hub表示
#include "spike/hub/speaker.h"   // スピーカ（環境により header 名が異なる場合あり）
#include "spike/pup/motor.h"     // モータを使うためのヘッダ

#define TEMPO   18          /* 基本の音長(相対) */
#define VOLUME  50          /* 音量 (0～100 程度) */

//pup_motor_t *motorA;
//pup_motor_t *motorE;

// 周期ハンドラ: 1秒ごとにカウントを表示
void test_spike_cychdr(intptr_t exinf)
{
    static int count = 0;
    
    hub_display_number(++count);   // 数字だけを表示（テキストが無ければ数字でOK）
}

void move_robot(intptr_t exinf)
{
    pup_motor_t *motorA = pup_motor_init(PBIO_PORT_ID_A, PUP_DIRECTION_COUNTERCLOCKWISE);
    pup_motor_t *motorE = pup_motor_init(PBIO_PORT_ID_E, PUP_DIRECTION_CLOCKWISE);

    // 1秒待ってからスタート
    // モータA・Bを同時に500度/秒で回転
    pup_motor_set_speed(motorA, 500);
    pup_motor_set_speed(motorE, 500);
    dly_tsk(1600000);  // 1秒間回転

    // モータA・Bを停止
    pup_motor_stop(motorA);
    pup_motor_stop(motorE);
    dly_tsk(500000);  // 0.85秒待機

    // モータAだけ再び回転
    pup_motor_set_speed(motorA, 500);
    pup_motor_set_speed(motorE, -500);
    dly_tsk(220000);  // 1秒間回転
    // すべてのモータを停止して終了
    pup_motor_stop(motorA);
    pup_motor_stop(motorE);

    exit(0);
}

void Main(intptr_t exinf)
{   

    const int32_t quarter = 250;
    const int32_t half    = 500;
    const int32_t full    = 1000;
    // 周期ハンドラ開始（app.cfg で TEST_SPIKE_CYC1 を定義）
    sta_cyc(TEST_SPIKE_CYC1);
    sta_cyc(MOVE);

    hub_speaker_set_volume(VOLUME);

    while (1) {
        // 音階を順番に鳴らす（依頼いただいた並び）
        hub_speaker_play_tone(NOTE_C4, full);        // ド
        hub_speaker_play_tone(NOTE_G4, full);        // ソ
        hub_speaker_play_tone(NOTE_F4, quarter);     // ファ
        hub_speaker_play_tone(NOTE_E4, quarter);     // ミ
        hub_speaker_play_tone(NOTE_D4, quarter);     // レ
        hub_speaker_play_tone(NOTE_C5, full);        // 高いド
        hub_speaker_play_tone(NOTE_G4, half);        // ソ
        hub_speaker_play_tone(NOTE_F4, quarter);     // ファ
        hub_speaker_play_tone(NOTE_E4, quarter);     // ミ
        hub_speaker_play_tone(NOTE_D4, quarter);     // レ
        hub_speaker_play_tone(NOTE_C5, full);        // 高いド
        hub_speaker_play_tone(NOTE_G4, half);        // ソ
        hub_speaker_play_tone(NOTE_F4, quarter);     // ファ
        hub_speaker_play_tone(NOTE_E4, quarter);     // ミ
        hub_speaker_play_tone(NOTE_F4, quarter);     // ファ
        hub_speaker_play_tone(NOTE_D4, full);        // レ

        // 小休止（ループ間の区切り）
        dly_tsk(300000); // 300ms
    }

    // 到達しないが、書式上の終了
    ext_tsk();
}
