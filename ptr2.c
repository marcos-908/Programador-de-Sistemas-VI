#include<stdio.h>

int main()
{
	int idade = 20;
	int *p;
	
	p = &idade;
	
	printf("valor inicial %d\n", *p);
	*p = idade+5;
	printf("valor final %d\n", *p);
	
	return(0);
}