#include<stdio.h>

int main()
{
	int m = 0;
	int n = 0;
	int copia_m = 0;
	int copia_n = 0;
	int resto = 0;
	int resposta = 0;
	
	scanf("%d", &m);
	scanf("%d", &n);
	
	copia_m = m;
	copia_n = n;
	
	while(n != 0)
	{
		resto = m%n;
		m = n;
		n = resto;
	}
	
	resposta = (copia_m*copia_n)/m;
	
	printf("%d", resposta);
	
	return(0);
}