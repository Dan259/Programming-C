#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

FILE *out = fopen("output.txt","w");
	
double create_mat(double **mat,int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			mat[i][j] = rand() % 10;
		}
	}
}

double print_mat(double **mat,int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("[%lf]", mat[i][j]);
			fprintf(out,"[%lf]",mat[i][j]);
		}
		printf("\n");
		fprintf(out,"\n");
	}
	fprintf(out,"\n");
}

double sum_elements(double **mat,int n){
	int res = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			res += mat[i][j];
		}
	}
	return res;
}

int main(){
	time_t start_time, end_time;
	
	start_time = time(NULL);
	
	srand(time(NULL));
	
	FILE *data = fopen("input.txt","r");
	
	int year, mon, day, n, cnt;
	
	fscanf(data, "%d.%d.%d", &day, &mon, &year);

	struct tm target_date = {0};
	target_date.tm_year = year - 1900;
	target_date.tm_mon = mon - 1;
	target_date.tm_mday = day;
	
	time_t target = mktime(&target_date);
	time_t now = time(NULL);
	if(target == -1){
		return -1;
	}
	
	double diff = difftime(target,now);
	int diff_day = ceil(diff / 86400);
	
	printf("To reach required time - %d days\n\n",diff_day);
	
	printf("Enter size of matrix:");
	scanf("%d",&n);
	
	double **mat1,**mat2;
	mat1 = (double**)malloc(n*sizeof(double*));
	for(int i = 0; i < n; i++)
	{
		mat1[i] = (double*)malloc(n*sizeof(double));
	}
	
	mat2 = (double**)malloc(n*sizeof(double*));
	for(int i = 0; i < n; i++)
	{
		mat2[i] = (double*)malloc(n*sizeof(double));
	}
	
	create_mat(mat1,n);
	create_mat(mat2,n);
	
	while(sum_elements(mat1,n) != sum_elements(mat2,n)){
		create_mat(mat2,n);
		cnt += 1;
	}
	int sum_mat1 = sum_elements(mat1,n);
	int sum_mat2 = sum_elements(mat2,n);
	printf("\n");
	print_mat(mat1,n);
	printf("Sum elements = %d\n\n",sum_mat1);
	print_mat(mat2,n);
	printf("Sum elements = %d\n",sum_mat2);
	printf("Count = %d\n", cnt);
 
    end_time = time(NULL);
 
    double elapsed_time = difftime(end_time, start_time);
 
    printf("\nProgramm time - %lf seconds", elapsed_time);
    
    fclose(out);
}
