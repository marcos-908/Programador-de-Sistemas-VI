#include<stdio.h>

int main()
{
	double R = 0.0;
	double pi = (3.14159);
	double total = 0.0;
	
	scanf("%lf", &R);
	
	total = (4.0/3.0)*pi*(R*R*R);
	
	printf("VOLUME = %.3lf\n", total);
	
	return(0);
}