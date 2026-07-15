#include<stdio.h>

int main()
{
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	double delta = 0.0;
	double raiz = 0.0;
	double xk = 0.0;
	double R1 = 0.0;
	double R2 = 0.0;
	
	scanf("%lf", &a);
	scanf("%lf", &b);
	scanf("%lf", &c);
	
	delta = (b*b) - (4*a*c);
	if(delta>0 && a !=0)
	{
	xk = delta;
	
	for(int i=0; i < 1000; i++)
	{
		raiz = 0.5*(xk+(delta/xk));
		xk = raiz;
	}
	
	R1 = (-b+raiz)/(2*a);
	R2 = (-b-raiz)/(2*a);
	
	printf("R1 = %.5lf\n", R1);
	printf("R2 = %.5lf\n", R2);
	
	}else
	{
		printf("Impossivel calcular\n");
	}
	
	return(0);
}