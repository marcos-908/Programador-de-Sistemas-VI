#include<stdio.h>

int main()
{
	char nome[25];
	double sf = 0.0;
	double ve = 0.0;
	double total = 0.0;
	
	scanf("%s", &nome);
	scanf("%lf", &sf);
	scanf("%lf", &ve);
	
	total = sf + (0.15*(ve));
	
	printf("TOTAL = R$ %.2lf", total);
	
	return(0);
}