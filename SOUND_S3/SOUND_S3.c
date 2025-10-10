#include <kernel.h>              // RTOSの基本機能
#include <stdlib.h>              // exit() を使うため
#include <t_syslog.h>            // シリアルモニタにメッセージを出す
#include <SOUND_S3.h>
#include "spike/hub/display.h"   // 画面表示
#include "spike/hub/speaker.h"   // スピーカー制御
#include "spike/hub/battery.h"   // バッテリー情報




void play_sound() {
    int32_t e = 200;  // 8分音符
    int32_t q = 400;  // 4分音符
    int32_t h = 800;  // 2分音符
    int32_t f = 1200; // 全音符

    // テンポ：ゆったりとしたBPM（おおよそ80〜90）

    hub_speaker_play_tone(NOTE_G4, q);    // ソ
    hub_speaker_play_tone(NOTE_A4, q);    // ラ
    hub_speaker_play_tone(NOTE_B4, q);    // シ
    hub_speaker_play_tone(NOTE_C5, q);    // ド
    hub_speaker_play_tone(NOTE_B4, h);    // シー
    hub_speaker_play_tone(NOTE_A4, q);    // ラ
    hub_speaker_play_tone(NOTE_G4, q);    // ソ
    hub_speaker_play_tone(NOTE_E4, h);    // ミー

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
    // 起動時のメッセージをシリアルモニタに送信
    syslog(LOG_NOTICE, "Program started.");

    // スピーカーの音量を100%に設定
    hub_speaker_set_volume(100);

    // バッテリー電圧を取得してハブの画面に表示
    uint16_t battery = hub_battery_get_voltage();
    hub_display_number(battery);

    // メロディを再生
    play_sound();

    // 3秒待機（単位：マイクロ秒）
    dly_tsk(3000000);

    // プログラムを終了
    exit(0);
}


