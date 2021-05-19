code segment
start:
    ;乘法mul  8位乘数 : mul reg/mem8  = reg/mem8 * al = ah:al
    ;        16位乘数 : mul reg/mem16 = reg/mem16 * ax = dx:ax
    mov al,0x02
    mov ah,0x10
    mul ah
    ;结果 = 0x0020 
    mov ax,0xf040
    mov bx,0x0002
    mul bx
    ;结果= 0x0001E080
  
    ;除法div 8位除数 : div reg/mem8 = ax / reg/mem8 = al ... ah
    ;       16位除数 : div reg/mem16 = dx:ax / reg/mem16 = ax ... dx 
    mov ax,0x10
    mov bl,0x02
    div bl
    ;结果= 0x08
    mov bx,0x8000
    mov ax,0x0000
    mov cx,0x0250
    div cx
    ;结果= 0x01A0 ... 0x006E
ends
end start