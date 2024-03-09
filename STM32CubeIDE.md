# Increase size of icons
1. ### Right click the shortcut and copy the target path and paste into file system
2. ### Open the `.ini` file and insert the below at the bottom of the file
```
-Dswt.enable.autoScale=true
-Dswt.autoScale=150
-Dswt.autoScale.method=nearest
```
3. ### Save the file and open STM32CubeIDE