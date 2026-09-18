#include <stdio.h>
 
int main()
{
	int C;
	char T;
	float matriz[12][12];
	float soma = 0;
	
	scanf("%d", &C);
	scanf(" %c", &T);
	
	for(int i = 0; i < 12; i++)
	{
		for(int j = 0; j < 12; j++)
		{
			scanf("%f", &matriz[i][j]);
		}
	}
	
	for(int j = 0; j < 12; j++)
	{
		soma += matriz[j][C];
	}
	
	if(T == 'S')
	{
		printf("%.1f\n", soma);
	}else if(T == 'M')
	{
		printf("%.1f\n", soma / 12);
	}
	
    return 0;
}