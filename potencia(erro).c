#include<stdio.h>

int main()
{
	double resultado = 0.0;
	double a = 0.0;
	double b = 0.0;
	
	scanf("%lf", &a);
	scanf("%lf", &b);
	
	resultado = a;
	
	for(int i = 0; i=b; i++)
	{
		resultado = resultado*a;
	}
	
	printf("resultado: %lf\n", resultado);
	
	return(0);
}