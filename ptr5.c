#include<stdio.h>

int main()
{
	int num = 0;
	int num_2 = 0;
	int *ptr;
	int *ptr_2;
	
	printf("escolha dois valores\n");
	scanf("%d %d", &num, &num_2);
	
	ptr = &num;
	ptr_2 = &num_2;
	
	printf("ANTES:\n");
	printf("A = %d\n", *ptr);
	printf("B = %d\n", *ptr_2);
	
	ptr = &num_2;
	ptr_2 = &num;
	
	printf("DEPOIS:\n");
	printf("A = %d\n", *ptr);
	printf("B = %d\n", *ptr_2);
	
	return(0);
}