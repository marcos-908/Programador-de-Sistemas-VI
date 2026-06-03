#include<stdio.h>

int main()
{
	int num = 0;
	
	printf("informe um numero inteiro\n");
	scanf("%d",&num);
	
	if(num > 5)
	{
		printf("esse numero e maior que 5\n");
	}
	else
	{
		printf("esse numero e menor que 5\n");
	}
	
	return(0);
}