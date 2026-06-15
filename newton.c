#include<stdio.h>

int main()
{
	double raiz = 0.0;
	double x = 0.0;
	double xk = 0.0;
	
	printf("informe um numero para descobrir a raiz quadrada\n");
	scanf("%lf", &x);
	
	xk = x;
	
	for(int i=0; i < 1000; i++)
	{
		raiz = 0.5*(xk + (x/xk));
		xk = raiz;
	}
	
	printf("o valor da raiz e: %lf\n", raiz);
	
	return(0);
}