#include <stdio.h>

double potenciacao(double a, int b);

int main()
{
    double base;
    int expo;
	double resultado;
   scanf("%lf %d", &base, &expo);
   resultado = potenciacao(base,expo);
   printf("%.5lf\n", resultado);

    return 0;
}


double potenciacao(double a, int b)
{
	double resultado = 1.0;
	for(int i = 0; i < b; i++)
	{
		resultado = resultado*a;
	}
	
	return(resultado);
}