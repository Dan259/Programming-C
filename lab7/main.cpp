#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x,y) x < y ? 1 : 0

struct humen
{
	char name[50];
	char surname[50];
	int age;
};
char file_data[100],cmd_data[100], *dat;
int i = 0, lines_count;

humen *file_input(){
	FILE *data = fopen("input.txt","r");
	lines_count = 0;
	int i = 0;
    while (! feof(data))
    {
        if (fgetc(data) == '\n')
            lines_count++;
    }
    lines_count++;
    struct humen *mas;
    mas = (humen*)malloc(lines_count*sizeof(humen));
    fclose(data);
    
    data = fopen("input.txt","r");
    while(i < lines_count){
    	fscanf(data, "%s %s %d", &mas[i].name, &mas[i].surname, &mas[i].age);
    	i++;
	}
	fclose(data);
	return mas;
}

humen *cmd_input(){
	printf("Enter number of people: ");
	scanf("%d", &lines_count);
	struct humen *mas;
	mas = (humen*)malloc(lines_count*sizeof(humen));
	
	for(int i = 0; i < lines_count; i++){
		printf("Enter %d person: ",(i+1));
		scanf(" %s %s %d", &mas[i].name, &mas[i].surname, &mas[i].age);
	}
	
	return mas;
}




int main(){
	struct humen *mas, *mas_sort;
	int min = 0, min_last = 99999, min_num;
	mas = file_input();
	mas_sort = (humen*)malloc(lines_count*sizeof(humen));
	
	for(int i = 0; i < lines_count; i++){
		min_last = 99999;
		for(min_num = 0; min_num < (lines_count+1); min_num++){
			if(mas[min_num].age != NULL){
				if(MIN(mas[min_num].age,min_last)){
				min_last = mas[min_num].age;
				min = min_num;
				}
			}
			
		}
		strcpy(mas_sort[i].name, mas[min].name);
		strcpy(mas_sort[i].surname, mas[min].surname);
		mas_sort[i].age = mas[min].age;
		mas[min].age = NULL;
	}
	
	
	for(int i = 0;i < lines_count;i++){
		printf("Name: %s Surname: %s Birth year: %d\n",mas_sort[i].name,mas_sort[i].surname,mas_sort[i].age);
	}
	free(mas);
}
