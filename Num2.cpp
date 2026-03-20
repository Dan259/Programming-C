#include <stdio.h>
int matf[2][2],m,s,sqrt_matf[2][2],b;

int main(void)
{
	printf("Enter size: ");
	scanf("%d",&b);
	double mat[b][b];
	for(int i = 0; i < b; i++)
	{
		for(int j = 0; j < b; j++)
		{
			printf("Enter mat[%d][%d]: ", i, j);
			scanf("%lf",&mat[i][j]);
		}
	}
	
	for(int i = 0; i < b; i++)
	{
		m = m + mat[i][i];
	}
	for(int i = 0, j = (b-1); i < b, j > -1; i++, j--)
	{
		
		s = s + mat[j][i];
	}
	
	for(int i = 0; i < b; i++)
	{
		for(int j = 0; j < b; j++)
		{
			printf("[%lf]", mat[i][j]);
		}
		printf("\n");
	}
	printf("main = %d, sub = %d\n",m,s);
	
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			printf("Enter matf[%d][%d]: ",i,j);
			scanf("%d",&matf[i][j]);
		}
	}
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			printf("[%d]", matf[i][j]);
		}
		printf("\n");
	}
	
	sqrt_matf[0][0] = matf[0][0] * matf[0][0] + matf[0][1] * matf[1][0];
	sqrt_matf[0][1] = matf[0][0] * matf[1][0] + matf[0][1] * matf[1][1];
	sqrt_matf[1][0] = matf[1][0] * matf[0][0] + matf[1][1] * matf[1][0];
	sqrt_matf[1][1] = matf[1][0] * matf[1][0] + matf[1][1] * matf[1][1];
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			printf("[%d]", sqrt_matf[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
