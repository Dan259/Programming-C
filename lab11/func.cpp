#include "func.h"
#include <stdarg.h>
#include <stdio.h>

#define MAX(arr,cnt) \
	int max = arr[0]; \
	for(int j = 0; j < cnt;j++){ \
		if(arr[j] > max) \
			max = arr[j]; \
	} \
	printf("%d\n",max);

#define MIN(arr,cnt) \
	int min = arr[0]; \
	for(int j = 0; j < cnt;j++){ \
		if(arr[j] < min) \
			min = arr[j]; \
	} \
	printf("%d\n",min); 

int max(int cnt, ...){
	int nums[cnt], sum = 0;
	double sr_arif;
	
	va_list num;
	va_start(num, cnt);
	
	for(int i = 0; i < cnt; i++){
		nums[i] = va_arg(num, int);
		sum += nums[i];
	}
	
	printf("MAX = ");
	MAX(nums,cnt);
		
	va_end(num);	
}

int min(int cnt, ...){
	int nums[cnt], sum = 0;
	double sr_arif;
	
	va_list num;
	va_start(num, cnt);
	
	for(int i = 0; i < cnt; i++){
		nums[i] = va_arg(num, int);
		sum += nums[i];
	}
	
	printf("MIN = ");
	MIN(nums,cnt);
		
	va_end(num);	
}

int arif(int cnt, ...){
	int nums[cnt], sum = 0;
	double sr_arif;
	
	va_list num;
	va_start(num, cnt);
	
	for(int i = 0; i < cnt; i++){
		nums[i] = va_arg(num, int);
		sum += nums[i];
	}
	
	sr_arif = sum / cnt;
	
	printf("Arif = %lf\n",sr_arif);
		
	va_end(num);	
}

int summa(int cnt, ...){
	int nums[cnt], sum = 0;
	double sr_arif;
	
	va_list num;
	va_start(num, cnt);
	
	for(int i = 0; i < cnt; i++){
		nums[i] = va_arg(num, int);
		sum += nums[i];
	}
	
	printf("Sum = %d",sum);
		
	va_end(num);	
}
