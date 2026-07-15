#include<stdio.h>

int main()
{
	int A = 0;
	int B = 0;
	int *ptr;
	int *ptr_2;
	
	scanf("%d %d", &A, &B);
	
	ptr = &A;
	ptr_2 = &B;
	
	printf(" numero 1 = %d\n", *ptr);
	printf(" numero 2 = %d\n", *ptr_2);
	printf("\n");
	*ptr = *ptr+*ptr_2;
	printf("Soma = %d\n", *ptr);
	*ptr = *ptr-(*ptr_2*2);
	printf("Subtracao = %d\n", *ptr);
	*ptr = *ptr * (*ptr_2*2);
	printf("Multiplicacao = %d\n", *ptr);
	*ptr = *ptr / (*ptr_2);
	
	return(0);
}