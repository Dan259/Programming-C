#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct humen
{
	char name[50];
	char surname[50];
	int byear;
	char gender[6];
	double height;
};

int lines_count;

void swap(struct humen *mas, int i, int j){
	struct humen temp;
	temp = mas[i];
	mas[i] = mas[j];
	mas[j] = temp;
}

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
    	fscanf(data, "%s %s %d %s %lf", &mas[i].name, &mas[i].surname, &mas[i].byear, &mas[i].gender, &mas[i].height);
    	i++;
	}
	fclose(data);
	return mas;
}

humen sort(struct humen *mas, char *chosen_oper){
	int should_swap = 0;
	for (int i = 0; i < lines_count - 1; i++){
        for (int j = 0; j < lines_count - i - 1; j++){
			if(strcmp(chosen_oper, "name") == 0)
				should_swap = strcmp(mas[j].name, mas[j+1].name) > 0;
			else if(strcmp(chosen_oper, "surname") == 0)
				should_swap = strcmp(mas[j].surname, mas[j+1].surname) > 0;
			else if(strcmp(chosen_oper, "byear") == 0)
				should_swap = mas[j].byear > mas[j+1].byear ? 1:0;
			else if(strcmp(chosen_oper, "gender") == 0)
				should_swap = strcmp(mas[j].gender, mas[j+1].gender) > 0;
			else if(strcmp(chosen_oper, "height") == 0)
				should_swap = mas[j].height > mas[j+1].height ? 1:0;
			
			if(should_swap == 1)
				swap(mas, j, j+1);
	    }
	}
}

humen *choose_sort(struct humen *mas){
	struct humen *mas_sort;
	char chosen_oper[10];
	printf("Will you use multisorting?(+/-) ");
	scanf("%s", &chosen_oper);
	if(strcmp("+",chosen_oper) == 0){
		char chosen_oper1[10];
		printf("Choose main parameter to sort(name/surname/byear/gender/height): ");
		scanf("%s", &chosen_oper);
		printf("Choose subparameter to sort(name/surname/byear/gender/height): ");
		scanf("%s", &chosen_oper1);
		sort(mas,chosen_oper1);
		sort(mas,chosen_oper);
	}
	else{
		printf("Choose parameter to sort(name/surname/byear/gender/height): ");
		scanf("%s", &chosen_oper);
		sort(mas,chosen_oper);
		
	}
}

int main(){
	struct humen *mas;
	mas = file_input();
	choose_sort(mas);
	for(int i = 0; i < lines_count; i++){
		printf("%s %s %d %s %lf\n", mas[i].name, mas[i].surname, mas[i].byear, mas[i].gender, mas[i].height);
	}
	free(mas);
	
	return 0;
}
