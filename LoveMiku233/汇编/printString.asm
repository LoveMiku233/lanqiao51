section code align=16 vstart=0x7c00 ;section分段 code 名字 align=16 16/32字节对齐 
;vstart=0x7c00 在真机运行情况下段寄存器都会被初始化为0x0000，但程序起始位置却是0x7c00，这样就会导致程序中标号不正确。
;解决方法：
;   第一种：可以把段寄存器初始化为0x7c00
;   第二种: 使用vstart=0x7c00,汇编地址会在计算的时候自动加上0x7c00。0x7c00+偏移地址

;and al,0x10 只保存000 ->1 0000 这个位的值
;or al,0x10 设置al 000->1 0000 这个位的值为1。可以通过or ah,0x00 通过ZF判断是否为0
;not al 反转操作数中的每一位
;xor al,bl 异或 可以通过ZF判断al与bl是否相等
mov si,sayHello ;把sayHello送入DS段寄存器
xor di,di ;异或，清空ES段寄存器
call PrintString ;call 标号/寄存器/内存地址
mov si,sayByeBye ;把sayByeBye送入DS段寄存器
call PrintString ;调用PrintString函数
jmp End  ;跳转到结束标号

PrintString: ;标号:PrintString 标号本质上是内存地址偏移
    .setup: ;开始标号
    mov ax,0xb800 ;把显存地址送入ax寄存器
    mov es,ax ;通过ax寄存器把显存地址送入ES段寄存器

    mov bh,0x07 ;属性:0x07黑底白字
    mov cx,0xffff ;循环次数

    .printChar: ;循环打印
    mov bl,[ds:si]
    inc si ;si++
    mov [es:di],bl ;传入字符
    inc di  ;di++
    mov [es:di],bh ;传入字符属性
    inc di ;di++
    or bl,0x00 ;判断bl是否为0x00
    jz .return ;等于0则跳转到return标号退出函数
    loop .printChar ;不等于0则继续循环
    .return: 
    ret  ;结束函数


;db 表示字节数据
sayHello db 'hi Dos!'
         db 0x00 ;0x00结尾
sayByeBye db 'bye windows!'
        db 0x00


;程序结束标号
End: jmp End ;死循环,补0
times 510-($-$$) db 0 
                db 0x55,0xaa
                