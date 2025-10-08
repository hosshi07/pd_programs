/*
 * Copyright (c) 2023 Afrel Co., Ltd. 
 * All rights reserved
 */
#include <stdlib.h>
#include <kernel.h>

#include <spike/hub/system.h>

#include <color_s.h>

#include "spike/pup/motor.h"
#include "spike/pup/colorsensor.h"
#include "spike/pup/forcesensor.h"
#include "spike/pup/ultrasonicsensor.h"

#include "spike/hub/battery.h"
#include "spike/hub/button.h"
#include "spike/hub/display.h"
#include "spike/hub/imu.h"
#include "spike/hub/light.h"
#include "spike/hub/speaker.h"

#include <pbio/color.h>

pup_motor_t *motorA;             //モータAを使う変数
pup_motor_t *motorB;             //モータBを使う変数
pup_device_t *ColorSensor;       //カラーセンサーを使う変数
pup_device_t *ColorSensor1;
pup_device_t *ColorSensor2;
pup_device_t *ForceSensor;       //フォースセンサーを使う変数
pup_device_t *UltraSonicSensor;  //距離センサーを使う変数

void Main(intptr_t exinf)
{
  hub_button_t pressed = 0;
  // カラーセンサー初期化（ポートCとDに接続）
  ColorSensor1 = pup_color_sensor_get_device(PBIO_PORT_ID_B);
  ColorSensor1 = pup_color_sensor_get_device(PBIO_PORT_ID_E);

  while (!(pressed&HUB_BUTTON_CENTER))
  {
      hub_button_is_pressed(&pressed);
      // 反射光を取得（0～100）
      int reflected1 = pup_color_sensor_reflection(ColorSensor1);
      int reflected2 = pup_color_sensor_reflection(ColorSensor2);

      // ディスプレイに表示
      char buf[32];
      snprintf(buf, sizeof(buf), "B : %d F : %d", reflected1, reflected2);
      hub_display_text(buf, 200, 100); // 明るさ200、表示時間100ms

      // 少し待つ（CPU負荷軽減、100ms）
      dly_tsk(100000);
  }
}
