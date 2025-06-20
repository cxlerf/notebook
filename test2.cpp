; 确保脚本以管理员权限运行，以避免权限问题
#SingleInstance Force
#NoEnv
SetWorkingDir %A_ScriptDir%
; Alt + V 切换到 Visual Studio Code
!v::
IfWinExist, ahk_exe Code.exe
{
    WinActivate
}
else
{
    Run, "C:\Program Files\Microsoft VS Code\Code.exe"  ; 替换为您的 VS Code 实际路径
}
return
; Alt + P 切换到 PotPlayer
!p::
IfWinExist, ahk_exe PotPlayerMini.exe  ; 根据您的 PotPlayer 版本，可能需要调整为 PotPlayerMini.exe 或其他
{
    WinActivate
}
else
{
    Run, "D:\PotPlayer\PotPlayerMini.exe"  ; 替换为您的 PotPlayer 实际路径
}
return
; Alt + C 切换到 Chrome
!c::
IfWinExist, ahk_exe chrome.exe
{
    WinActivate
}
else
{
    Run, "C:\Program Files\Google\Chrome\Application\chrome.exe"  ; 替换为您的 Chrome 实际路径
}
; Alt + W 切换到 WPS Office !w:: IfWinExist, ahk_exe wps.exe { WinActivate }
else 
{ 
Run, "D:\WPS Office\12.1.0.21541\office6\wpspdf.exe" ; 
}
return