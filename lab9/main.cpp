#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char exam[100], exam1[100];
	printf("Enter your example:");
	scanf(" %[^\n]", exam1);
	
	exam[0] = exam1[0];
	for(int i = 1, j = 1; i < strlen(exam1);i++){
		if(exam1[i] == '+' || exam1[i] == '-' || exam1[i] == '*'){
			exam[j] = ' ';
			exam[j+1] = exam1[i];
			exam[j+2] = ' ';
			j += 3;
		}
		else{
			exam[j] = exam1[i];
			j++;
		}
	}
	
	char *token = strtok(exam," ");
	int c = 0, d = 0; 
	double num[50], res = 0;
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
	
	res = num[0];
	
	for(int i = 0;i < (d+1); i++){
		if(znak[i] == '+'){
			res += num[i+1];
		}
		else if(znak[i] == '-')
			res -= num[i+1];
		else if(znak[i] == '*')
			res *= num[i+1];
	}
	printf("%lf", res);
	
	free(token);
}
