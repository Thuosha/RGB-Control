; Coding by AwesomeCrackpotThuosha // @Thuosha
#NoEnv
#SingleInstance, force
#Persistent
#InstallKeybdHook
#UseHook
#KeyHistory, 0
#HotkeyInterval, 1
#MaxHotkeysPerInterval, 127

; Purple Color in-Game
TrigColor := 0xA145A3
; 0xA5A528 - Yellow
; 0xB8AC29 - Red

TriggerTrue := false

; Stuff for RGB-Control pixel searching (Search pixel/fov)
ImgStabilizerX := A_ScreenHeight // 160
ImgStabilizerY := A_ScreenHeight // 128

zx := A_ScreenWidth // 2
zy := A_ScreenHeight // 2
FovX := A_ScreenWidth // 40
FovY := A_ScreenHeight // 64

ScanA := zx - ImgStabilizerX
ScanB := zy
ScanC := zx + ImgStabilizerX
ScanD := zy + ImgStabilizerY

NearObjA := zx - ImgStabilizerX
NearObjB := zy - ImgStabilizerY
NearObjC := zx + ImgStabilizerX
NearObjD := zy + ImgStabilizerY

XButton1:: ; Here edit Activation-Key
   SoundBeep, 750, 300
   TriggerTrue := !TriggerTrue
   SetKeyDelay, -1, 1
   SetControlDelay, -1
   SetMouseDelay, -1
   SendMode, InputThenPlay
   SetBatchLines, -1
   SetWinDelay, -1
   ListLines, Off
   CoordMode, Pixel, Screen, RGB
   CoordMode, Mouse, Screen
   PID := DllCall("GetCurrentProcessId")
   Process, Priority, %PID%, High

Loop {
    While TriggerTrue {
        PixelSearch, Px, Py, ScanA, ScanB, ScanС, ScanD, TrigColor, 50, Fast RGB

        if (ErrorLevel=0) {
            Click, %Px%, %Py%, 1
        }
        Sleep, 25
    }
}
return

Up::
    SoundBeep, 300, 200
    settimer, loop, off

Down:: ; Here edit Diconnection-Key
    SoundBeep, 600, 250
    ExitApp
