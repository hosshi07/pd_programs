/*
 * Copyright (c) 2023 Afrel Co., Ltd. 
 * All rights reserved
 */
#include <stdlib.h>
#include <kernel.h>

#include <spike/hub/system.h>

#include <main.h>

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
pup_motor_t *motorE;
pup_device_t *ColorSensor1;       //カラーセンサーを使う変数
pup_device_t *ColorSensor2;
pup_device_t *ForceSensor;       //フォースセンサーを使う変数
pup_device_t *UltraSonicSensor;  //距離センサーを使う変数


void Main(intptr_t exinf)
{
  int32_t start_angleA;
  int32_t start_angleE;
  hub_button_t pressed = 0;
  //int32_t start_angle;
  int n;
  hub_display_text("Hello", 100, 2000);
  dly_tsk(1000000);
  hub_display_text("RUN", 200, 1000);

  motorA = pup_motor_init(PBIO_PORT_ID_A, PUP_DIRECTION_COUNTERCLOCKWISE);
  motorE = pup_motor_init(PBIO_PORT_ID_E, PUP_DIRECTION_CLOCKWISE);
  
  start_angleA = pup_motor_get_count(motorA);
  start_angleE = pup_motor_get_count(motorE);

  pup_motor_set_speed(motorA, 300);
  pup_motor_set_speed(motorE, 300);
  
  while(!(pressed&HUB_BUTTON_CENTER)){
    
    hub_button_is_pressed(&pressed);
  }

  
  // n = 2
  // //1回転は360度;
  // while(pup_motor_get_count(motorA) - start_angle < (360 * n));
  
  dly_tsk(3000000);
  pup_motor_stop(motorA);
  pup_motor_stop(motorB);
  //プログラムを終了します
  exit(0);
}
