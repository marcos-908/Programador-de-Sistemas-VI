#include<stdio.h>

int main()
{
	int num = 0;
	int num_2 = 0;
	int *ptr;
	int *ptr_2;
	
	printf("escolha dois numeros para somar1\n");
	scanf("%d %d", &num, &num_2);
	
	ptr = &num;
	ptr_2 = &num_2;
	
	printf("numero 1: %d\n", *ptr);
	printf("numero 1: %d\n", *ptr_2);
	
	*ptr = *ptr+*ptr_2;
	
	printf("soma = %d\n", *ptr);
	
	return(0);
}