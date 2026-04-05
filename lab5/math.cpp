#include <stdio.h>
#include <stdlib.h>
#include "func.h"

double **oper(double **mat1, double **mat2)
{
	char ch;
	printf("Choose operation(+,-,*): ");
	scanf("%s", &ch);
	
	extern int n;
	double **res;
	res = (double**)malloc(n*sizeof(double*));
	
	for(int i = 0; i < n; i++)
	{
		res[i] = (double*)malloc(n*sizeof(double));
	}
	if(ch == '+')
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				res[i][j] = mat1[i][j] + mat2[i][j];
			}
		}
	}
	
	if(ch == '-')
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				res[i][j] = mat1[i][j] - mat2[i][j];
			}
		}
	}
	
	if(ch == '*')
	{
		for (int i = 0; i < n; i++) {
	        for (int j = 0; j < n; j++) {
	        	res[i][j] = 0;
	            for (int k = 0; k < n; k++) {
	                res[i][j] += mat1[i][k] * mat2[k][j];
	            }
	        }
    	}
	}
	return res;
}
