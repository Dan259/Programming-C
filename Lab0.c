#include <stdio.h>
#include <stdlib.h>
#define GETBIT(j) ((b[(j)/8] & (0x80 >> ((j) % 8)))?1:0)
#define CLRBIT(j) ((b[(j)/8] &= (~(0x80 >> ((j) % 8)))))

unsigned char b[1000000000];
int a = 2;

int main(){
    unsigned long long *L;
    L = (unsigned long long *)b;
    for(int i = 0; i < (1000000000/8); i++)
        *L++ = 0xffffffffffffffff;
    
    CLRBIT(0); CLRBIT(1);
    long long n = 100000000; 

    int *P = (int *)malloc(n * sizeof(int));
    int count = 0;

    for (long long p = 2; p * p <= n; p++) {
        if (GETBIT(p)) {
            for (long long j = p * p; j <= n; j += p) {
                CLRBIT(j);
            }
        }
    }

    for (long long i = 2; i <= n; i++) {
        if (GETBIT(i)) {
            P[count++] = (int)i;
        }
    }

    printf("Found %d common numbers.\n", count, n);
    for (int i = 0; i < 10000000 && i < count; i++) {
        printf("%d ", P[i]);
    }

    free(P);
    return 0;
}
