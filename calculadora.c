#include<stdio.h>

void menu();
double soma(double a, double b);
double subtracao(double a, double b);
double multiplicacao(double a, double b);
double divisao(double a, double b);

int main()
{
	double x = 0.0;
	double y = 0.0;
	double resultado = 0.0;
	int operacao = 0;
	
	do{
	menu();
	scanf("%d", &operacao);
	
	switch(operacao)
	{
		case 1:
		printf("escolha um numero para somar\n");
		scanf("%lf", &x);
		printf("escolha outro numero para somar\n");
		scanf("%lf", &y);
		resultado = soma(x,y);
		printf("o resultado e: %lf\n", resultado);
		break;
		
		case 2:
		printf("escolha um numero para subtrair\n");
		scanf("%lf", &x);
		printf("escolha outro numero para subtrair\n");
		scanf("%lf", &y);
		resultado = subtracao(x,y);
		printf("o resultado e: %lf\n", resultado);
		break;
		
		case 3:
		printf("escolha um numero para multiplicar\n");
		scanf("%lf", &x);
		printf("escolha outro numero para multiplicar\n");
		scanf("%lf", &y);
		resultado = multiplicacao(x,y);
		printf("o resultado e: %lf\n", resultado);
		break;
		
		case 4:
		printf("escolha um numero para dividir\n");
		scanf("%lf", &x);
		printf("escolha outro numero para dividir\n");
		scanf("%lf", &y);
		if (y==0)
		{
			printf("impossivel dividir por zero\n");
		}
		else{
		resultado = divisao(x,y);
		printf("o resultado e: %lf\n", resultado);
		break;
		}
		
		default:
		printf("essa operacao nao existe! esccolhe uma valida!\n");
		break;
	}
	}while(operacao != 1 && operacao != 2 && operacao != 3 && operacao != 4);
		
	return(0);
}

double soma(double a, double b)
{
	return(a+b);
}

double subtracao(double a, double b)
{
	return(a-b);
}

double multiplicacao(double a, double b)
{
	return(a*b);
}

double divisao(double a, double b)
{
	return(a/b);
}

void menu()
{
	printf("aperte 1 para soma\n");
	printf("aperte 2 para subtracao\n");
	printf("aperte 3 para multiplicacao\n");
	printf("aperte 4 para divisao\n");
}