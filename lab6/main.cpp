#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *data1 = fopen("IN.txt","r");
FILE *data2 = fopen("OUT.txt","w");
char str[100];
int byear[4], byear1;

int main(){
	while(fgets(str,100,data1) != NULL){
		printf("%s",str);
		for(int i = (strlen(str) - 5),j = 0; j < 4; i++, j++){
			byear[j] = str[i] - '0';
			printf("\n%d %c\n",byear[j],str[i]);
		}
		//printf("\n%d%d%d%d",byear[0],byear[1],byear[2],byear[3]);
		byear1 = byear[0] * 1000 + byear[1] * 100 + byear[2] * 10 + byear[3];
		printf("\n%d",byear1);
	}
	
}
