#include<stdio.h>

int main()
{
	int num = 0;
	int ht = 0;
	double rh = 0;
	double salary = 0;
	
	scanf("%d", &num);
	scanf("%d", &ht);
	scanf("%lf", &rh);
	
	salary = ht*rh;
	
	printf("NUMBER = %d\n", num);
	printf("SALARY = U$ %.2lf\n", salary);
	
	return(0);
}