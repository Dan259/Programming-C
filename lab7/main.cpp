#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void swap(struct humen *mas, int i, int j){
	char name_last[50], surname_last[50];
	strcpy(name_last,mas_sort[i].name);                     
	strcpy(surname_last,mas_sort[i].surname);
	int age_last = mas_sort[i].age;
	strcpy(mas_sort[i].name,mas_sort[j].name);
	strcpy(mas_sort[i].surname,mas_sort[j].surname);
	mas_sort[i].age = mas_sort[j].age;
	strcpy(mas_sort[j].name,name_last);
	strcpy(mas_sort[j].surname,surname_last);
	mas_sort[j].age = age_last;
	
}


int main(){
	struct humen *mas;
	mas = file_input();
	mas_sort = mas;
	
	for (int i = 0; i < lines_count - 1; i++)
    {
        for (int j = 0; j < lines_count - i - 1; j++)
        {
            if (mas_sort[j].age > mas_sort[j + 1].age)
                swap(mas_sort, j, j + 1);
        }
    }
	
	for(int i = 0;i < lines_count;i++){
		printf("Name: %s Surname: %s Birth year: %d\n",mas_sort[i].name,mas_sort[i].surname,mas_sort[i].age);
	}
	free(mas);
}
