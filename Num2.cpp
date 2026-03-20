#include <stdio.h>
double mat[3][3];
int matf[2][2],m,s,sqrt_matf[2][2],i;

double print_mat()
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			printf(" [%lf]",mat[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	
	m = mat[0][0] + mat[1][1] + mat[2][2];
	s = mat[2][0] + mat[1][1] + mat[0][2];
	
	print_mat(mat);
	printf("main = %d, sub = %d",m,s);
	
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			printf("Enter matf[%d][%d]:",i,j);
			scanf(" %lf",&matf[i][j]);
		}
	}
	b = 2;
	print_mat(matf);
	
	sqrt_matf[0][0] = matf[0][0] * matf[0][0] + matf[0][1] * matf[1][0];
	sqrt_matf[0][1] = matf[0][0] * matf[1][0] + matf[0][1] * matf[1][1];
	sqrt_matf[1][0] = matf[1][0] * matf[0][0] + matf[1][1] * matf[1][0];
	sqrt_matf[1][1] = matf[1][0] * matf[1][0] + matf[1][1] * matf[1][1];
	print_mat(2, sqrt_matf);
	
	return 0;
}
