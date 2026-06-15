#include<stdio.h>

int main()
{
	int A = 0;
	int B = 0;
	int C = 0;
	int D = 0;
	int diferenca = 0;
	
	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);
	scanf("%d", &D);
	
	diferenca = (A*B)-(C*D);
	
	printf("DIFERENCA = %d\n", diferenca);
	
	return(0);
}