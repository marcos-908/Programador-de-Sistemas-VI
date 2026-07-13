#include<stdio.h>

int main()
{
	int *ptr;
	int valor = 10;

	ptr = &valor;

	printf("endereco = %x\n", &valor);
	printf("endereco = %x\n", ptr);
	printf("valor = %d\n", *ptr);

	return(0);
}