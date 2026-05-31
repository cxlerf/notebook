; === 脚本开始 ===

; XButton1 对应 Button 4 (通常是靠后的侧键) -> 设置为 粘贴 (Ctrl + V)
XButton1::Send, ^v

; XButton2 对应 Button 5 (通常是靠前的侧键) -> 单击复制，双击复制并发送到 iPad
XButton2::
    if (A_PriorHotkey <> "XButton2" or A_TimeSincePriorHotkey > 400) {
        ; 单击：只执行普通电脑复制
        Send, ^c
        return
    }
    
    ; 双击：执行复制并发送网络请求
    Send, ^c
    Sleep, 100 ; 等待剪贴板写入数据
    clipText := Clipboard
    
    if (clipText = "") {
        return
    }
    
    ; 对文本进行 URL 编码
    encodedText := UriEncode(clipText)
    
    ; 【核心修改】：严格匹配 Bark 要求的参数格式
    ; 增加 automaticallyCopy=1 和明确的 copy 参数
    barkUrl := "https://api.day.app/eo5s7rAfkjJA44SFABzTpV/" . encodedText . "?automaticallyCopy=1&copy=" . encodedText . "&isArchive=1"
    
    ; 静默发送网络请求
    try {
        whr := ComObjCreate("WinHttp.WinHttpRequest.5.1")
        whr.Open("GET", barkUrl, true)
        whr.Send()
        
        ToolTip, 已发送至 iPad
        SetTimer, RemoveToolTip, -1500
    }
return

RemoveToolTip:
    ToolTip
return

; URL 编码函数 (兼容 AHK v1)
UriEncode(Uri) {
    VarSetCapacity(Var, StrPut(Uri, "UTF-8"), 0)
    StrPut(Uri, &Var, "UTF-8")
    Res := ""
    Loop
    {
        Code := NumGet(Var, A_Index - 1, "UChar")
        if (!Code)
            break
        if (Code >= 0x30 && Code <= 0x39 ; 0-9
            || Code >= 0x41 && Code <= 0x5A ; A-Z
            || Code >= 0x61 && Code <= 0x7A ; a-z
            || Code == 0x2D || Code == 0x2E || Code == 0x5F || Code == 0x7E) ; - . _ ~
            Res .= Chr(Code)
        else
            Res .= Format("%{:02X}", Code)
    }
    return Res
}

; === 脚本结束 ===