#include<stdio.h>

int soma(int a, int b);

int main()
{
	int x = 0, y = 0;
	int resposta = 0;
	printf("escolha dois numeros inteiros para somar\n");
	scanf("%d %d", &x, &y);
	resposta = soma(x,y);
	printf("o valor da soma e:%d\n", resposta);
	
	return(0);
}

int soma(int a, int b)
{
	return(a+b);
}