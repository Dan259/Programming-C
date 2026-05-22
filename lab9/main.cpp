#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char exam[100];
	printf("Enter your example:");
	scanf(" %[^\n]", &exam);
	
	char *token = strtok(exam," ");
	int c = 0, d = 0; 
	double num[50];
	char znak[50];
	
	while(token != NULL){
		if(c % 2 == 0){
			if(strchr(token, '.') != NULL)
				num[c / 2] = atof(token);
			else
				num[c / 2] = atoi(token);
		}
			
		else{
			znak[d] = *token;
			d++;
		}
		
		c++;
		token = strtok(NULL, " ");
	}
	
	for(int i = 0;i < ; i++){
		if(znak[i] == '+')
			res 
		printf("%lf", num[i]);
	}
	
	
	
}
