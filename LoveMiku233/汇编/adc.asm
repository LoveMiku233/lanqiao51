code segment
start:
    ;���� 0x00020003 + 0x00030002    
    ;ax:bx
    mov ax,0x0002
    mov bx,0x0003
    
    ;cx:dx
    mov cx,0x0003
    mov dx,0x0002
    ;��λ+��λ �����λ����CF=1
    add bx,dx
    ;��λ+��λ+CF
    adc ax,cx
    ;���= 0x00050005   
ends
end start