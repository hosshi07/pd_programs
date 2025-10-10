# pd_programs
PD実践におけるコード　by Hosshi
## 各コードについて
対応するフォルダをクリックすると下に説明が書いてある．

## 環境構築ができないあなたへ
**spikeへの書き込みができねぇ**というあなたへ届け  
おそらくこのようなエラーが出ていることでしょう
```python
user@DESKTOP-QFQHCLT:~$ ./write.sh test Traceback (most recent call last): File "C:\Users\koenu\AppData\Local\Programs\Python\Python39\Lib\site-packages\cx_Freeze\initscripts\__startup__.py",    
line 138, in run File "C:\Users\koenu\AppData\Local\Programs\Python\Python39\Lib\site-packages\cx_Freeze\initscripts\console.py", line 16, in run File "SpikeDfuWriter.py", line 632, in <module> tsize    = tprefix["size"] File "SpikeDfuWriter.py",   
 line 600, in main def consume(fmt, data, names): File "SpikeDfuWriter.py", line 113, in init if not devices: File "SpikeDfuWriter.py", line 443,   
  in get_dfu_devices File "C:\Users\koenu\AppData\Local\Programs\Python\Python39\lib\site-packages\usb\core.py", line 1309, in    
  find usb.core.NoBackendError: No backend available   
```