#include<stdio.h>

int main()
{
	int A = 0;
	int B = 0;
	int C = 0;
	int *ptr;
	int *ptr_2;
	int *ptr_3;
	
	scanf("%d %d %d", &A, &B, &C);
	
	ptr = &A;
	ptr_2 = &B;
	ptr_3 = &C;
	
	printf("varialvel A = %d\n", *ptr);
	printf("endereco A = %x\n", ptr);
	printf("varialvel B = %d\n", *ptr_2);
	printf("endereco B = %x\n", ptr_2);
	printf("variavel C = %d\n", *ptr_3);
	printf("endereco C = %x\n", ptr_3);
	
	return(0);
}