code segment
start:
    ;处理 0x00020003 + 0x00030002    
    ;ax:bx
    mov ax,0x0002
    mov bx,0x0003
    
    ;cx:dx
    mov cx,0x0003
    mov dx,0x0002
    ;低位+低位 如果进位出则CF=1
    add bx,dx
    ;高位+高位+CF
    adc ax,cx
    ;结果= 0x00050005   
ends
end start