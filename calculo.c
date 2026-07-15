#include<stdio.h>

int main()
{
	int c1 = 0;
	int n1 = 0;
	double v1 = 0.0;
	int c2 = 0;
	int n2 = 0;
	double v2 = 0.0;
	double total = 0.0;
	
	scanf("%d", &c1);
	scanf("%d", &n1);
	scanf("%lf", &v1);
	scanf("%d", &c2);
	scanf("%d", &n2);
	scanf("%lf", &v2);
	
	total = (v1*n1) + (v2*n2);
	
	printf("VALOR A PAGAR: R$ %.2lf\n", total);
	
	return(0);
}