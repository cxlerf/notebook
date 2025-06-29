; 确保脚本以管理员权限运行，以避免权限问题
#SingleInstance Force
#NoEnv
SetWorkingDir %A_ScriptDir%
; 设置更高的优先级来处理全屏应用
Process, Priority,, High

; Alt + S 截图功能 - 直接使用 PrintScreen 键
!s::
Send, {PrintScreen}  ; 发送 PrintScreen，调用截图选择界面
return

; Alt + V 切换到 Visual Studio Code - 增强版本，专门处理全屏应用
!v::
; 检查 PotPlayer 是否全屏
WinGet, ActiveProcess, ProcessName, A
if (ActiveProcess = "PotPlayerMini.exe")
{
    ; 如果当前是 PotPlayer，先发送 ESC 退出全屏，然后切换
    Send, {Escape}
    Sleep, 200  ; 给一点时间让窗口模式生效
}

IfWinExist, ahk_exe Code.exe
{
    WinActivate
    ; 确保窗口真正激活
    WinWaitActive, ahk_exe Code.exe, , 2
}
else
{
    Run, "D:\Microsoft VS Code\Code.exe"  ; 替换为您的 VS Code 实际路径
}
return

; 备选方案：使用更强制的方式切换到 VS Code
; 如果上面的方法仍然不行，可以尝试这个版本
^!v::  ; Ctrl + Alt + V 作为备选快捷键
; 强制方式：直接最小化当前全屏窗口
WinGet, ActiveProcess, ProcessName, A
if (ActiveProcess = "PotPlayerMini.exe")
{
    WinMinimize, A  ; 最小化当前窗口
    Sleep, 300
}

IfWinExist, ahk_exe Code.exe
{
    WinActivate
    WinRestore  ; 确保窗口不是最小化状态
    WinShow     ; 确保窗口可见
}
else
{
    Run, "D:\Microsoft VS Code\Code.exe"
}
return

; Alt + N 智能切换当前程序的多个窗口 - 改进版本
!n::
; 获取当前活动窗口的进程名
WinGet, ActiveProcess, ProcessName, A

; 如果是 PotPlayer 全屏，先处理全屏状态
if (ActiveProcess = "PotPlayerMini.exe")
{
    ; 检查是否全屏，如果是则先退出全屏
    WinGet, Style, Style, A
    if (Style & 0x20000000)  ; 检查是否有边框（全屏时无边框）
    {
        Send, {Escape}
        Sleep, 200
    }
}

; 根据当前活动的程序来切换对应的多个窗口
if (ActiveProcess = "Code.exe")
{
    WinActivateBottom, ahk_exe Code.exe
}
else if (ActiveProcess = "chrome.exe")
{
    WinActivateBottom, ahk_exe chrome.exe
}
else if (ActiveProcess = "wpspdf.exe")
{
    WinActivateBottom, ahk_exe wpspdf.exe
}
else if (ActiveProcess = "PotPlayerMini.exe")
{
    WinActivateBottom, ahk_exe PotPlayerMini.exe
}
else if (ActiveProcess = "YoudaoDict.exe")
{
    WinActivateBottom, ahk_exe YoudaoDict.exe
}
else
{
    ; 如果当前程序不在支持列表中，尝试切换同进程的窗口
    WinActivateBottom, ahk_exe %ActiveProcess%
}
return

; 另一种方法：使用窗口组来更精确地控制切换
; 首先创建一个窗口组
GroupAdd, VSCodeGroup, ahk_exe Code.exe

; Alt + M 使用窗口组方式切换 VS Code 窗口
!m::
IfWinExist, ahk_group VSCodeGroup
{
    ; 激活组中的下一个窗口
    GroupActivate, VSCodeGroup, r
}
else
{
    Run, "C:\Program Files\Microsoft VS Code\Code.exe"
}
return

; Alt + P 切换到 PotPlayer - 改进版本
!p::
IfWinExist, ahk_exe PotPlayerMini.exe
{
    WinActivate
    ; 如果需要，可以自动进入全屏
    ; Sleep, 500
    ; Send, {Enter}  ; PotPlayer 中 Enter 键通常是全屏切换
}
else
{
    Run, "D:\PotPlayer\PotPlayerMini.exe"  ; 替换为您的 PotPlayer 实际路径
}
return

; Alt + C 切换到 Chrome - 保持原有功能
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

; Chrome 多窗口切换示例
GroupAdd, ChromeGroup, ahk_exe chrome.exe
!z::
IfWinExist, ahk_group ChromeGroup
{
    GroupActivate, ChromeGroup, r
}
else
{
    Run, "C:\Program Files\Google\Chrome\Application\chrome.exe"
}
return

; Alt + W 切换到 WPS PDF - 保持原有功能
!w::
IfWinExist, ahk_exe wpspdf.exe
{
    WinActivate
}
else
{
    Run, "D:\WPS Office\12.1.0.21541\office6\wpspdf.exe"
}
return

; Alt + D 切换到网易有道翻译 - 保持原有功能
!d::
IfWinExist, ahk_exe YoudaoDict.exe
{
    WinActivate
}
else
{
    Run, "D:\Dict\YoudaoDict.exe"
}
return

; 通用的多窗口切换函数 - 改进版本，处理全屏应用
SwitchBetweenWindows(exeName, programPath := "")
{
    ; 检查当前是否是全屏应用
    WinGet, ActiveProcess, ProcessName, A
    if (ActiveProcess = "PotPlayerMini.exe")
    {
        Send, {Escape}  ; 退出全屏
        Sleep, 200
    }
    
    IfWinExist, ahk_exe %exeName%
    {
        WinActivateBottom, ahk_exe %exeName%
    }
    else if (programPath != "")
    {
        Run, %programPath%
    }
    return
}

; 使用通用函数的示例
; Alt + Shift + V 切换 VS Code 窗口（使用通用函数）
!+v::
SwitchBetweenWindows("Code.exe", "C:\Program Files\Microsoft VS Code\Code.exe")
return

; 添加一个专门的全屏检测和处理函数
HandleFullscreenApp()
{
    WinGet, ActiveProcess, ProcessName, A
    if (ActiveProcess = "PotPlayerMini.exe")
    {
        ; 检查窗口状态
        WinGet, MinMax, MinMax, A
        if (MinMax = 1)  ; 1 表示最大化状态
        {
            Send, {Escape}
            Sleep, 300
            return true
        }
    }
    return false
}

; 添加一个更强制的 VS Code 切换方式
^+v::  ; Ctrl + Shift + V
; 先处理全屏应用
HandleFullscreenApp()

; 强制激活 VS Code
IfWinExist, ahk_exe Code.exe
{
    WinGet, VSCodeID, ID, ahk_exe Code.exe
    WinActivate, ahk_id %VSCodeID%
    WinShow, ahk_id %VSCodeID%
    WinRestore, ahk_id %VSCodeID%
    ; 确保窗口置于最前
    WinSet, AlwaysOnTop, On, ahk_id %VSCodeID%
    Sleep, 100
    WinSet, AlwaysOnTop, Off, ahk_id %VSCodeID%
}
else
{
    Run, "D:\Microsoft VS Code\Code.exe"
}
return