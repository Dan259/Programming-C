#include <stdio.h>
#include <stdlib.h>

#define N 5
const int k[N] = {-3, 12, 17, 12, -3};
const int SUM = 35;

/* 
#define N 7
const int k[N] = {-2, 3, 6, 7, 6, 3, -2};
const int SUM = 21;
*/


int main() {
    double buf[N];
    int count = 0;
    double val;

    for (int i = 0; i < N; i++) {
        buf[i] = 0.0;
    }

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
        } else {
            printf("%lf\n", val);
        }
    }

    return 0;
}
