#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(arr,cnt) \
	int max = 0; \
	for(int j = 0; j < cnt;j++){ \
		if(arr[j] > max) \
			max = arr[j]; \
	} \
	printf("%d",max); 
	
#define Arif(arr, cnt) \
	int sum = 0; \
	double arif = 0; \
	for(int j = 0; j < cnt;j++){ \
		sum += arr[j]; \
	} \
	arif = sum / cnt; \
	printf("%lf",arif);



int main(){
	char row1[100];
	int row[10];
	printf("Enter numbers row:");
	scanf("%[^\n]",&row1);
	
	char *token = strtok(row1," ");
	int i = 0;
	
	while(token != NULL){
		row[i] = atoi(token);
		token = strtok(NULL," ");
		i++;
	}
	
	Arif(row,i);
}
