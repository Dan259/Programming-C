#include <stdio.h>
#include "PS.h"
#include <stdbool.h>

int main(void) 
{
	double a,b,c;
	
	printf("Enter a: ");
	scanf("%lf",&a);
	
	printf("Enter b: ");
	scanf("%lf",&b);
	
	printf("Enter c: ");
	scanf("%lf",&c);
	
	bool res = check_triangle(a, b, c);
	
	if(res)
	{
		double P = perimeter(a, b, c);
		double S = square(a, b, c);
		printf("P = %lf, S = %lf", P, S);
	}
	else
	{
		printf("Triangle don't exist");
	}
	return 0;
}
