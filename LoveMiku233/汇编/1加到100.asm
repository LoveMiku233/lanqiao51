;1+2+3+...100  程序设计

code segment
start:
    ;设置循环次数 cx
    mov cx,100
    ;初始化ax
    mov ax,0x0000
    ;sum标号, sum正好是从100开始减1
    ;add ax,cx 把ax加上cx，结果存入ax
sum:add ax,cx
    loop sum
    ;cx不为0，则每次自动减1

ends
end start