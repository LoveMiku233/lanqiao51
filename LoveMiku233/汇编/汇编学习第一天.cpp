#include <iostream>
using namespace std;
void test(int a) {
	cout << a << endl;
}
int main() {
//	test(1);
	__asm { //rex 64bit eax 32bit ax 16bit 
		mov eax, 10H
		//call ������ַ
		//push eax //eaxѹ��ջ
		// lea dest,[��ֵַ] ֱ�Ӹ��Ƶ�ַ
		//lea ebx, [1000H] ebx=1000H
		//call ������ַ
		//add op1,op2 -> op1=op1+op2 
		//sub op1,op2 -> op1=op1-op2
		//inc op1 -> op1=op1+1
		//dec op1 -> op1=op1-1
		//jmp �ڴ��ַ   ��ת���ڴ��ִַ��
	}
	return 0;
}