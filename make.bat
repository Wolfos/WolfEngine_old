cd /d %~dp0
color A
call ndk-build
timeout /t 300
call ant debug
call adb uninstall nl.rvanee.wolfengine
call adb install Android/Bin/wolfengine-debug.apk
adb shell am start -n nl.rvanee.wolfengine/nl.rvanee.wolfengine.WolfEngine
pause