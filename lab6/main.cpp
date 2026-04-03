#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *data1 = fopen("IN.txt","r");
FILE *data2 = fopen("OUT.txt","w");
char str[100];
int byear[4], byear1;

int main(){
	while(fgets(str,100,data1) != NULL){
		//printf("%s",str);
		for(int i = (strlen(str) - 5),j = 0; j < 5; i++, j++){
			byear[j] = str[i] - '0';
			byear[j] = byear[j] > 0 ? byear[j] : 0;
		}
		byear1 = byear[0] == 0 ? byear[1] * 1000 + byear[2] * 100 + byear[3] * 10 + byear[4] : byear[0] * 1000 + byear[1] * 100 + byear[2] * 10 + byear[3];
		if(byear1 > 1980){
			fputs(str,data2);
		}
		printf("%d\n", byear1);
	}
	
}
