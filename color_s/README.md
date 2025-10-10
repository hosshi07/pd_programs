# color_sについて
このコードは、**LEGO SPIKE Prime** のカラーセンサーを用いて、  
**2つのセンサーの反射光（明るさ）をリアルタイムに取得・表示** するプログラムです。  

##  概要
- **対象デバイス**：SPIKE Prime / MINDSTORMS ハブ  
- **使用センサー**：カラーセンサー × 2（例：ポートBとEに接続）  
- **動作**：  
  - センサーの反射光（0〜100）を周期的に読み取る  
  - ハブのディスプレイに数値を表示（例：「B : 45 F : 60」）  
  - 中央ボタンを押すと終了  

##  コードのポイント
```c
ColorSensor1 = pup_color_sensor_get_device(PBIO_PORT_ID_B);
ColorSensor2 = pup_color_sensor_get_device(PBIO_PORT_ID_E);
```

動かんかった。おそらくスペック不足だろう．ならばリアルタイム処理から一定間隔ごとでの処理に切り替える
信号処理でいうとサンプリングを粗くする感じになるか．