#include<stdio.h>

int main()
{
	char sinal;
	
	printf("informe a operacao que deseja\n");
	
	scanf("%", sinal);
	
	switch(sinal)
	{
		case '+':
		soma();
		break;
		
		case '-':
		subtracao();
		break;
		
		case '*'
		produto();
		break;
		
		case '/':
		divisao();
		break;
		
		default;
		printf("essa operacao nao existe\n");
	}
	
	return(0);
}