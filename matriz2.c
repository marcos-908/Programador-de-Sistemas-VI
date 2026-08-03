#include<stdio.h>

int main()
{
	int soma = 0;
	int i, j;
	int matriz[4][4];
	
	for(int i = 0; i < 4; i++)
	{
		printf("\n");
		
		for(int j = 0; j < 4; j++)
		{
			scanf("%d", &matriz[i][j]);
			soma += matriz[i][j];
		}
	}
	
	if(soma == 67)
	{
		printf("SIX SEVEN!!!!!!\n");
	}else
	{
		printf("total = %d\n", soma);
	}
	
	return(0);
}