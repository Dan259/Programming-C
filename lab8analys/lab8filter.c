#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 11

const int k5[] = {-3, 12, 17, 12, -3};
const int SUM5 = 35;

const int k7[] = {-2, 3, 6, 7, 6, 3, -2};
const int SUM7 = 21;

const int k9[] = {-21, 14, 39, 54, 59, 54, 39, 14, -21};
const int SUM9 = 231;

const int k11[] = {-36, 9, 44, 69, 84, 89, 84, 69, 44, 9, -36};
const int SUM11 = 429;

int main(int argc, char *argv[]) {
    setvbuf(stdout, NULL, _IONBF, 0);

    int N = 5;
    const int *k = k5;
    int SUM = SUM5;

    if (argc > 1) {
        N = atoi(argv[1]);
    }

    switch (N) {
        case 5:  k = k5;  SUM = SUM5;  break;
        case 7:  k = k7;  SUM = SUM7;  break;
        case 9:  k = k9;  SUM = SUM9;  break;
        case 11: k = k11; SUM = SUM11; break;
    }

    double buf[MAX_N] = {0.0};
    int count = 0;
    double val;

    while (scanf("%lf", &val) == 1) {
        for (int i = 0; i < N - 1; i++) {
            buf[i] = buf[i + 1];
        }
        
        buf[N - 1] = val;
        count++;

        if (count >= N) {
            double res = 0;
            for (int i = 0; i < N; i++) {
                res += buf[i] * k[i];
            }
            res /= SUM; 
            
            printf("%lf\n", res);
        } 
		else {
            printf("%lf\n", val);
        }
    }

    return 0;
}
