#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *data1 = fopen("IN.txt","r");
FILE *data2 = fopen("OUT.txt","w");
int byear;
char name[50], surname[50], otchestvo[50];

int main(){
	while (fscanf(data1, "%s %s %s %d", surname, name, otchestvo, &byear) == 4) {
		if(surname[0] == 'I'){
			fprintf(data2, "%s %s %s %d\n", surname, name, otchestvo, byear);
		}
    }
}
