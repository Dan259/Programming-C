#include "func.h"
#include <stdarg.h>
#include <stdio.h>

#define MAX(arr,cnt) do { \
	int max = arr[0]; \
	for(int j = 0; j < cnt;j++){ \
		if(arr[j] > max) \
			max = arr[j]; \
	} \
	printf("%d\n",max); \
} while(0)

#define MIN(arr,cnt) do { \
	int min = arr[0]; \
	for(int j = 0; j < cnt;j++){ \
		if(arr[j] < min) \
			min = arr[j]; \
	} \
	printf("%d\n",min); \
} while(0)

int math(int cnt, ...){
	int nums[cnt], sum = 0;
	double sr_arif;
	
	va_list num;
	va_start(num, cnt);
	
	for(int i = 0; i < cnt; i++){
		nums[i] = va_arg(num, int);
		sum += num[i];
	}
	
	sr_arif = sum / cnt;
	printf("Sum = %d\nArithmetic mean = %lf\nMax = ",sum,sr_arif);
	MAX(nums, cnt);
	printf("Min = ");
	MIN(nums, cnt);
	
		
	va_end(num);
	
	
}
