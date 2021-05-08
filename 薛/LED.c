#include <STC15F2K60S2.H>

void main(void)
{
	while(1)
	{
		P2 |=(1<<7);
		P2 &= ~((1<<6)|(1<<5));

		P0=0xAA; // 1010 1010
	}
}