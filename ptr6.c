#include<stdio.h>

int main()
{
	int A = 0;
	int B = 0;
	int *ptr;
	int *ptr_2;
	
	printf("escolha dois valores\n");
	scanf("%d %d", &A, &B);
	
	ptr = &A;
	ptr_2 = &B;
	
	printf("A = %d\n", *ptr);
	printf("B = %d\n", *ptr_2);
	
	if(*ptr > *ptr_2)
	{
		printf("Maior valor = %d\n", *ptr);
	}else
	{
		printf("Maior valor = %d\n", *ptr_2);
	}
	
	return(0);
}