#include<stdio.h>

int main()
{
	int numero = 50;
	int *ptr;
	
	ptr = &numero;
	
	printf("o valor da variavel = %d\n", numero);
	printf("o endedereco da memoria do numero = %x\n", &numero);
	printf("valor armazenado em ptr = %x\n", ptr);
	printf("conteudo apontado por ptr = %d\n", *ptr);
	
	return(0);
}