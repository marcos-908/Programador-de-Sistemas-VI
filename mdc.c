#include<stdio.h>

int main()
{
	int a = 0;
	int b = 0;
	int resto = 0;
	
	scanf("%d", &a);
	scanf("%d", &b);
	
	while(b != 0)
	{
		resto = a%b;
		a = b;
		b = resto;
	}
	
	printf("%d\n", a);
	
	return(0);
}