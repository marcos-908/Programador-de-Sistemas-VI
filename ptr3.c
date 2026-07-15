#include<stdio.h>

int main()
{
	int num = 0;
	int *ptr;
	
	printf("escolha um numero\n");
	scanf("%d", &num);
	
	ptr = &num;
	
	printf("numero = %d\n", *ptr);
	*ptr = num*2;
	printf("dobro = %d\n", *ptr);
	
	return(0);
}