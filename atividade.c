#include<stdio.h>

void menu();
double soma(double a, double b);
double subtracao(double a, double b);
double multiplicacao(double a, double b);
double divisao(double a, double b);
double potenciacao(double a, int b);
double raiz(double a);
int fatorial_simples(int a);
int farotial_dublo(int a);
int mdc(int a, int b);
int mmc(int a, int b);
double equacao(double a, double b, double c);

int main()
{
	double resultado = 0.0;
	double operacao = 0;
	double x = 0.0;
	double y = 0.0;
	double p = 0.0;
	double raiz = 0.0;
	double r = 0.0;
	double rk = 0.0;
	int resposta = 0;
	int m = 0;
	int n = 0;
	
	do{
		menu();
		scanf("%d", &operacao);
		
		switch(operacao)
		{
			case 1:
			printf("qual numeros deseja somar com qual?\n");
			scanf("%lf", &x);
	        scanf("%lf", &y);
			resultado = soma(x,y);
			printf("a soma fica: %lf\n", resultado);
			break;
			
			case 2:
			printf("escolha numeros que deseja subtrair\n");
			scanf("%lf", &x);
	        scanf("%lf", &y);
			resultado = subtracao(x,y);
			printf("a subtracao fica: %lf\n", resultado);
			break;
			
			case 3:
			printf("escolha numeros que deseja multiplicar\n");
			scanf("%lf", &x);
	        scanf("%lf", &y);
			resultado = multiplicacao(x,y);
			printf("a multiplicacao fica: %lf\n", resultado);
			break;
			
			case 4:
			printf("escolha numeros que deseja dividir\n");
			scanf("%lf", &x);
	        scanf("%lf", &y);
			resultado = divisao(x,y);
			printf("a divisao fica: %lf\n", resultado);
			break;
			
			case 5:
			printf("escolha uma base e depois o expoente\n");
			scanf("%lf", &x);
	        scanf("%lf", &y);
			resultado = potenciacao(x,y);
			break;
			
		}
	while()
	
	return(0);
}

void menu()
{
	printf("BEM-VINDO A CALCULADORA!\n");
	printf("(1) soma\n");
	printf("(2) subtracao\n");
	printf("(3) multiplicacao\n");
	printf("(4) divisao\n");
	printf("(5) potenciacao\n");
	printf("(6) raiz quadrada\n");
	printf("(7) fatorial simples\n");
	printf("(8) fatorial dublo\n");
	printf("(9) MDC\n");
	printf("(10) MMC\n");
	printf("(11) equacao do segundo grau\n");
	printf("(12) sair\n");
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

double potenciacao(double a, int b)
{
	double resultado = 1.0;
	for(int i = 0; i < b; i++)
	{
		resultado = resultado*a;
	}
	
	return(resultado);
}

double raiz(double a)
{
	rk = r;
	
	for(int i = 0; i<1000; i++)
	{
		raiz = 0.5*(rk+(r/rk));
		rk = raiz
	}
	
	return(raiz);
}

int fatorial_simples(int a)
{
	
}

int farotial_dublo(int a)

int mdc(int a, int b)

int mmc(int a, int b)

double equacao(double a, double b, double c)