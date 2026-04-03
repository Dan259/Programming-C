#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct humen
{
	char *name;
	char *surname;
	int age;
};

FILE *data = fopen("persons.txt","r");
struct humen mas1[4], mas2[4];
char file_data[100], *dat;
int i = 0;

int main(){
	while(fgets(file_data,100,data) != NULL){
		dat = strtok(file_data," ");
		
		if(dat != NULL){
			mas1[i].name = (char*)malloc(strlen(dat) * sizeof(char));
			strcpy(mas1[i].name, dat);
		}
		
		dat = strtok(NULL, " ");
		if(dat != NULL){
			mas1[i].surname = (char*)malloc(strlen(dat) * sizeof(char));
			strcpy(mas1[i].surname, dat);
		}
		
		dat = strtok(NULL, " ");
		if(dat != NULL){
			mas1[i].age = atoi(dat);
		}
		
		printf("%s %s %s %d",mas1[0].name ,mas1[1].name ,mas1[2].surname ,mas1[3].age);
		i++;
	}
}
