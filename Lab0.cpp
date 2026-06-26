#include <stdio.h>
#define GETBIT(j) ((b[(j)/8] & (0x80 >> ((j) % 8)))?1:0)
#define CLRBIT(j) ((b[(j)/8] &= (~(0x80 >> ((j) % 8)))))
unsigned char b[1000000000];
int a = 2;
int main()
{
	unsigned long long *L;
	L = (unsigned long long *)b;
	for(int i = 0; i<(1000000000/8); i++)
		*L++ = 0xffffffffffffffff;
	
	CLRBIT(0); CLRBIT(1);
		
	return 0;
}
