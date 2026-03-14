#include <stdio.h>
#include <math.h>

int main(void)
{
	double a,b,c,D,x1,x2;
	char d;
	
	while(1)
	{

		printf("Enter a:");
		scanf("%lf",&a);
		
		printf("Enter b:");
		scanf("%lf",&b);
		
		printf("Enter c:");
		scanf("%lf",&c);
		
		D = pow(b,2.) - 4*a*c;
		printf("D - %f\n",D);
		
		if(D > 0)
		{
			x1 = (-b + pow(D,0.5)) / (2*a);
			x2 = (-b - pow(D,0.5)) / (2*a);
		
			printf("x1 - %f x2 - %f\n",x1,x2);	
		}
		else if(D == 0)
		{
			x1 = -b / (2*a);
			printf("x1 - %f\n",x1);
		}
		
		else
		{
			printf("No solution");
		}
		
		printf("Proceed? y/n:");
		scanf(" %c",&d);
		if(d == 'n') 
		{
			break;
		}
		
	}
	
}
