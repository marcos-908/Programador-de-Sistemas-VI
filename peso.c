#include<stdio.h>

int main()
{
	double nota_1 = 0.0;
	double peso_1 = 2.0;
	double nota_2 = 0.0;
	double peso_2 = 3.0;
	double nota_3 = 0.0;
	double peso_3 = 5.0;
	double media = 0.0;
	
	scanf("%lf", &nota_1);
	scanf("%lf", &nota_2);
	scanf("%lf", &nota_3);
	
	media = ((nota_1*peso_1)+(nota_2*peso_2)+(nota_3*peso_3))/(peso_1+peso_2+peso_3);
	
	printf("MEDIA = %.1lf\n",media );
	
	return(0);
}