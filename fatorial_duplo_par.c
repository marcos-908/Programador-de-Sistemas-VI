#include<stdio.h>

int main()
{
	int resposta = 1;
	int a = 0;
	
	scanf("%d", &a);
	
	if(a%2 == 0)
	{
	for(int i = a; i > 0; i-=2)
	{
		resposta = resposta*i;
	}
	printf("%d\n", resposta);
	}else
	{
		printf("nao\n");
	}
	
	
	return(0);
}