#include <kernel.h>                // RTOS（リアルタイムOS）の基本機能
#include <stdlib.h>                // exit() を使うため
#include <t_syslog.h>              // シリアルモニタにメッセージを出す
#include <report4.h>
#include "spike/pup/colorsensor.h" // カラーセンサーを使う
#include "spike/hub/speaker.h"   // スピーカー制御
#include "spike/hub/battery.h"   // バッテリー情報


void play_sound() {
    int32_t e = 200;  // 8分音符
    int32_t q = 400;  // 4分音符
    int32_t h = 800;  // 2分音符
    int32_t f = 1200; // 全音符

    // テンポ：ゆったりとしたBPM（おおよそ80〜90）

    // ♪ 愛してるの響きだけで〜
    hub_speaker_play_tone(NOTE_G4, q);    // ソ
    hub_speaker_play_tone(NOTE_A4, q);    // ラ
    hub_speaker_play_tone(NOTE_B4, q);    // シ
    hub_speaker_play_tone(NOTE_C5, q);    // ド
    hub_speaker_play_tone(NOTE_B4, h);    // シー
    hub_speaker_play_tone(NOTE_A4, q);    // ラ
    hub_speaker_play_tone(NOTE_G4, q);    // ソ
    hub_speaker_play_tone(NOTE_E4, h);    // ミー

    // ♪ 強くなれる気がしたよ〜
    hub_speaker_play_tone(NOTE_E4, q);    // ミ
    hub_speaker_play_tone(NOTE_F4, q);    // ファ
    hub_speaker_play_tone(NOTE_G4, q);    // ソ
    hub_speaker_play_tone(NOTE_A4, h);    // ラー
    hub_speaker_play_tone(NOTE_G4, q);    // ソ
    hub_speaker_play_tone(NOTE_F4, q);    // ファ
    hub_speaker_play_tone(NOTE_E4, f);    // ミー（伸ばす）

    // 終了の余韻
    dly_tsk(500000);
}

// ──────────────────────────────
// Main関数（RTOSが最初に実行する関数）
// ──────────────────────────────
void Main(intptr_t exinf)
{
    // 起動メッセージをシリアルモニタに表示
    syslog(LOG_NOTICE, "Program started.");
    // スピーカーの音量を100%に設定
    hub_speaker_set_volume(100);

    // Dポートに接続されたカラーセンサーを取得
    // pup_device_t* はセンサーを操作するための変数
    pup_device_t *ColorSensor = pup_color_sensor_get_device(PBIO_PORT_ID_D);

    // ──────────────────────────────
    // 反射光の強さ（明るさ）を読み取って表示するループ
    // ──────────────────────────────
    while (1)
    {
        // 反射光の強さを取得（0〜100 の範囲）
        int32_t reflection = pup_color_sensor_reflection(ColorSensor);

        // シリアルモニタに表示
        syslog(LOG_NOTICE, "Reflection: %ld", reflection);
        if (reflection == 0){
          play_sound();
        }
        // 0.5秒待つ（マイクロ秒単位）
        dly_tsk(500000);
    }

    // 実際にはここには到達しない（無限ループのため）
    exit(0);
}
