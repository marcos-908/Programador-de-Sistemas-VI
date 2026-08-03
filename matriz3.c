#include<stdio.h>

int main()
{
	int i, j;
	int matriz[5][5];
	int menor, maior;
	int linhamaior, colunamaior;
	int linhamenor, colunamenor;
	
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			scanf("%d", &matriz[i][j]);
			if(i == 0 && j == 0)
			{
				maior=menor=matriz[i][j];
				linhamaior=colunamenor=j;
			}
			
			if(matriz[i][j] > maior)
			{
				maior=matriz[i][j];
				linhamaior=i;
				colunamaior=j;
			}
			
			if(matriz[i][j] <menor)
			{
				menor=matriz[i][j];
				linhamenor=i;
				colunamenor=j;
			}
		}
	}
	
	printf("O maior numero e: %d\n", maior);
	printf("Posicao: %d %d\n", linhamaior, colunamaior);
	printf("O menor numero e: %d\n", menor);
	printf("Posicao: %d %d\n", linhamenor, colunamenor);
	
	return(0);
}