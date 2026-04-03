#include <stdio.h>
#include <stdlib.h>
#include "func.h"

double **mat1, **mat2, **res;
int n;

double ent_mat(double **mat)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("Enter mat[%d][%d]: ", i, j);
			scanf("%lf",&mat[i][j]);
		}
	}
}

double print_mat(double **mat)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("[%lf]", mat[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	printf("Enter matrix size: ");
	scanf("%d",&n);
	
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
	
	
	
	ent_mat(mat1);
	print_mat(mat1);
	ent_mat(mat2);
	print_mat(mat2);
	
	res = oper(mat1,mat2);
	print_mat(res);
	
}
