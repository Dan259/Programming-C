#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct humen
{
	char *name;
	char *surname;
	int age;
};
char file_data[100],cmd_data[100], *dat;
int i = 0;

humen *file_input(){
	FILE *data = fopen("input.txt","r");
	int lines_count = 0;
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
	while(fgets(file_data,100,data) != NULL){
		dat = strtok(file_data," ");
		if(dat != NULL){
			mas[i].name = (char*)malloc(strlen(dat) * sizeof(char));
			strcpy(mas[i].name, dat);
		}
		
		dat = strtok(NULL, " ");
		if(dat != NULL){
			mas[i].surname = (char*)malloc(strlen(dat) * sizeof(char));
			strcpy(mas[i].surname, dat);
		}
		
		dat = strtok(NULL, " ");
		if(dat != NULL){
			mas[i].age = atoi(dat);
		}
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
		printf("Enter %d human: ", (i+1));
		scanf("%s", cmd_data);
		
		for(int j = 0; j < 3; j++)
			dat = strtok(file_data," ");
			if(dat != NULL){
				mas[i].name = (char*)malloc(strlen(dat) * sizeof(char));
				strcpy(mas[i].name, dat);
				printf("%s", mas[i].name);
			}
			
			dat = strtok(NULL, " ");
			if(dat != NULL){
				mas[i].surname = (char*)malloc(strlen(dat) * sizeof(char));
				strcpy(mas[i].surname, dat);
			}
			
			dat = strtok(NULL, " ");
			if(dat != NULL){
				mas[i].age = atoi(dat);
			}
	}
	return mas;
}




int main(){
	struct humen *mas, *mas_sort;
	mas = cmd_input();
	mas_sort = mas;
	printf("%s", mas[0].surname);
	
	
	free(mas); free(mas_sort);
}
