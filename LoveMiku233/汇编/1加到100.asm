;1+2+3+...100  �������

code segment
start:
    ;����ѭ������ cx
    mov cx,100
    ;��ʼ��ax
    mov ax,0x0000
    ;sum���, sum�����Ǵ�100��ʼ��1
    ;add ax,cx ��ax����cx���������ax
sum:add ax,cx
    loop sum
    ;cx��Ϊ0����ÿ���Զ���1

ends
end start