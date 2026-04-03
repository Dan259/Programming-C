#include <math.h>
#include "PS.h"
#include <stdbool.h>

bool check_triangle(double a, double b, double c)
{
	bool res;
	if(a + b > c && a + c > b && b + c > a)
	{
		res = true;
	}
	else
	{
		res = false;
	}
	return res;
}

double perimeter(double a, double b, double c)
{
	double P = a + b + c;
	return P;
}
double square(double a, double b, double c)
{
	double p = (a + b + c) / 2;
	return pow((p * (p - a) * (p - b) * (p - c)), 0.5);
}
