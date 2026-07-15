#include<stdio.h>

void menu();
double soma(double a, double b);
double subtracao(double a, double b);
double multiplicacao(double a, double b);
double divisao(double a, double b);
double potenciacao(double a, int b);
double raiz(double a);
int fatorial_simples(int a);
int farotial_duplo_par(int a);
int farotial_duplo_impar(int a);
int mdc(int a, int b);
int mmc(int a, int b);
void segundo_grau(double a, double b, double c);

int main()
{
	double resultado = 0.0;
	int operacao = 0;
	double x = 0.0;
	double y = 0.0;
	double p = 0.0;
	double r = 0.0;
	double R1 = 0.0;
	double R2 = 0.0;
	int resposta = 1;
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
			if (y==0)
			{
			printf("impossivel dividir por zero\n");
			}
			else{
			resultado = divisao(x,y);
			printf("a divisao fica: %lf\n", resultado);
			}
			break;
			
			case 5:
			printf("escolha uma base e depois o expoente\n");
			scanf("%lf", &x);
	        scanf("%lf", &y);
			if(y != 0)
			{
			resultado = potenciacao(x,y);
			printf("o potenciacao fica: %lf\n", resultado);
			}else
			{
				printf("todo numero elevato a 0 e: 1!\n");
			}
			break;
			
			case 6:
			printf("escolha um numero para descobrir a raiz quadrada\n");
			scanf("%lf", &r);
			if(r >! 0)
			{
			resultado = raiz(r);
			printf("o valor da raiz e: %lf\n", resultado);
			}else
			{
				printf("nao existe raizes para numeros de 0 ou numeros negativos\n");
			}
			break;
			
			case 7:
			printf("escolha um numero para saber o fatorial simples\n");
			scanf("%d", &m);
			resposta = fatorial_simples(m);
			if(m >! 0)
			{
			printf("o valor e: %d\n", resposta);
			}else
			{
				printf("nao existe fatorial de 0 ou numeros negativos!\n");
			}
			break;
			
			case 8:
			printf("escolha um numero para saber o fatorial duplo\n");
			scanf("%d", &m);
			if(m>0)
			{
			if(m%2 == 0)
			{
				resposta = farotial_duplo_par(m);
				printf("o valor e: %d\n", resposta);
			}else
			{
				resposta = farotial_duplo_impar(m);
				printf("o valor e: %d\n", resposta);
			}
			}else
			{
				printf("nao tem fatorial negativo\n");
			}
			break;
			
			case 9:
			printf("escolha dois valores para saber o maximo divisor commum\n");
			scanf("%d", &m);
			scanf("%d", &n);
			resposta = mdc(m,n);
			printf("o maximo divisor commum e: %d\n", resposta);
			break;
			
			case 10:
			printf("escolha dois valores para saber o minimo multiplo comum\n");
			scanf("%d", &m);
			scanf("%d", &n);
			resposta = mmc(m,n);
			printf("o minimo multiplicador commum e: %d\n", resposta);
			break;
			
			case 11:
			printf("escolha o a, depois o b, e depois o c\n");
			scanf("%lf", &x);
			scanf("%lf", &y);
			scanf("%lf", &p);
			if(x != 0)
			{
			segundo_grau(x,y,p);

			}
			else{
				printf("nao existe nos conjunto dos numeros reais\n");
			}
			break;
			
			case 12:
			printf("saindo do programa...\n");
			break;
			
			case 67:
			printf("SIX SEVEN!!!!!!!!!!!\n");
			break;
			
			default:
			printf("opcao inedisponivel\n");
			break;
		}
	}while(operacao != 12);
	
	return 0;
}

void menu()
{
	printf("BEM-VINDO A CALCULADORA!\n");
	printf("ESCOLHA UMA OPERACAO\n");
	printf("(1) somar\n");
	printf("(2) subtrair\n");
	printf("(3) multiplicar\n");
	printf("(4) dividir\n");
	printf("(5) potencia\n");
	printf("(6) raiz_quadrada\n");
	printf("(7) fatorial simples\n");
	printf("(8) fatorial dublo\n");
	printf("(9) Maximo Divisor Comum\n");
	printf("(10) Minimo Multiplo Comum\n");
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
	return (a*b);
}
	
double divisao(double a, double b)
{
	return (a/b);
}

double potenciacao(double a, int b)
{
	double resultado = 1.0;
	for(int i = 0; i < b; i++)
	{
		resultado = resultado*a;
	}
	
	return resultado;
}

double raiz(double a)
{
	double raiz, rk = 0.0;
	rk = a;
	
	for(int i = 0; i<100; i++)
	{
		raiz = 0.5*(rk+(a/rk));
		rk = raiz;
	}
	
	return raiz;
}

int fatorial_simples(int a)
{
	int resposta = 1;
	for(int i = a; i > 0; i--)
	{
		resposta = resposta*i;
	}
	
	return resposta;
}

int farotial_duplo_par(int a)
{
	int resposta = 1;
	for(int i = a; i > 0; i-=2)
	{
		resposta = resposta*i;
	}
	
	return resposta;
}

int farotial_duplo_impar(int a)
{
	int resposta = 1;
	for(int i = a; i > 0; i-=2)
	{
		resposta = resposta*i;
	}
	
	return resposta;
}

int mdc(int a, int b)
{
	int resto = 0;
		while(b != 0)
	{
		resto = a%b;
		a = b;
		b = resto;
	}
	
	return a;
}

int mmc(int a, int b)

{	
	return(a*b)/mdc(a,b);
}

void segundo_grau(double a, double b, double c)
{
	double delta = 0.0;
	double R1 = 0.0;
	double R2 = 0.0;
	double rk = 0.0;
	
	delta = (b*b) - (4*a*c);
	
	if(delta > 0 && a !=0)
	{
		R1 = (-b+raiz(delta))/(2*a);
		R2 = (-b-raiz(delta))/(2*a);
		
		printf("X1: %lf\n", R1);
        printf("X2: %lf\n", R2);
		
	}else
	{
		printf("nao existe raizes de 0 ou numeros negativo\n");
	}
}