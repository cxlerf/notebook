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
return

; Alt + W 切换到 WPS PDF
!w::
; 先尝试激活现有的WPS PDF窗口
IfWinExist, ahk_exe wpspdf.exe
{
    WinActivate
    ; 调试信息
    ToolTip, 找到并激活了WPS PDF窗口
    SetTimer, RemoveToolTip, 2000
}
else
{
    ; 如果没有找到窗口，启动WPS PDF
    Run, "D:\WPS Office\12.1.0.21541\office6\wpspdf.exe"
    ; 调试信息
    ToolTip, 启动WPS PDF程序
    SetTimer, RemoveToolTip, 2000
}
return

; 移除提示的定时器
RemoveToolTip:
ToolTip
SetTimer, RemoveToolTip, Off
return

; 调试热键 - 按F2查看当前所有WPS相关窗口
F2::
WinGet, windows, List
Loop, %windows%
{
    id := windows%A_Index%
    WinGetTitle, title, ahk_id %id%
    WinGet, process, ProcessName, ahk_id %id%
    if (InStr(process, "wps") > 0 || InStr(title, "WPS") > 0 || InStr(title, "PDF") > 0)
        MsgBox, 窗口标题: %title%`n进程名: %process%`n窗口ID: %id%
}
return