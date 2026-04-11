#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct humen
{
	char name[50];
	char surname[50];
	int age;
	char gender[6];
	double height;
};

int lines_count;

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
    	fscanf(data, "%s %s %d %s %lf", &mas[i].name, &mas[i].surname, &mas[i].age, &mas[i].gender, &mas[i].height);
    	i++;
	}
	fclose(data);
	return mas;
}

humen *sort(struct humen *mas){
	struct humen *mas_sort;
	char chosen_oper[10];
	mas_sort = (humen*)malloc(lines_count*sizeof(humen));
	printf("Will you use multiply sorting?(+/-) ");
	scanf("%s", &chosen_oper);
	if(strcmp("+",chosen_oper) == 0){
		printf("1");
	}
	else{
		printf("Choose parameter to sort(Name/Surname/Byear/Gender/Height): ");
		scanf("%s", &chosen_oper);
		
	}
}

int main(){
	struct humen *mas;
	mas = file_input();
	sort(mas);
//	printf("%s %s %d %s %lf", mas[0].name, mas[0].surname, mas[0].age, mas[0].gender, mas[0].height);
	
	return 0;
}
