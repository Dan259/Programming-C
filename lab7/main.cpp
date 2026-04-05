#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x,y) x < y ? x : y

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
	return mas;
}

humen *cmd_input(){
	int lines_count;
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
	int min = 0;
	mas = file_input();
	mas_sort = (humen*)malloc(lines_count*sizeof(humen));
	for(int i = 0;i < (lines_count-1); i++){
		for(int j = 0;j < lines_count;j++){
			if(mas[i].age != NULL){
				min = MIN(mas[j].age, mas[(j+1)].age);
			}
		}
		
	}
	
	free(mas);
}
