# SOUND_S3

SPIKE-RT上で動作する    
**好きな音を奏でるプログラム**です。  

---

##  概要

このプログラムは好きな音楽を流します．  
これはレポート課題２に相当するものです．


---

## コード注目
これは**SOUND_S2**を改造して好きな曲にしたものです．  
Mainを処理する部分には**音楽を流す工程**があります．  
その中に独自の関数**play_sound**が存在し，これを改造して好きな曲をながします．  
play_sound内の**hub_speaker_play_tone関数**にはノード，音符の引数が必要なため，音符は新たな変数に格納している．  
この関数は上から順番に処理するため好きな曲の音程に合わせて関数を挿入することで完成する．  



```c
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
```