#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct humen
{
	char *name;
	char *surname;
	int age;
};

FILE *data = fopen("persons.txt","r");
struct humen mas1[4], mas2[4];
char *dat, file_data[100];
int j = 0;

int main(){

	while(fgets(file_data,100,data) != NULL){
		dat = strtok(file_data," ");
		int i = 0;
		
		
		while(dat != NULL){
			switch(i){
				case 0: mas1[j].name = dat; break;
				case 1: mas1[j].surname = dat; break;
				case 2: mas1[j].age = atoi(dat); break;
			}
			//printf("%s %s", dat, mas1[0].name);
			dat = strtok(NULL," ");
			i++;
		}
		j++;
	}
	int n = sizeof(mas1) / sizeof(mas1[0]);
	
	for(struct humen *p=mas1; p < mas1+n; p++)
    {
        printf("Name:%s Surname:%s Age: %d \n", p->name, p->surname, p->age);
    }
}
