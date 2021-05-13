#include <iostream>
using namespace std;
void test(int a) {
	cout << a << endl;
}
int main() {
//	test(1);
	__asm { //rex 64bit eax 32bit ax 16bit 
		mov eax, 10H
		//call 函数地址
		//push eax //eax压入栈
		// lea dest,[地址值] 直接复制地址
		//lea ebx, [1000H] ebx=1000H
		//call 函数地址
		//add op1,op2 -> op1=op1+op2 
		//sub op1,op2 -> op1=op1-op2
		//inc op1 -> op1=op1+1
		//dec op1 -> op1=op1-1
		//jmp 内存地址   跳转到内存地址执行
	}
	return 0;
}