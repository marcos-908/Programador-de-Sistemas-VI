#include <stdio.h>
 
int main()
{
	int matriz[1][3];
	
	scanf("%d %d %d", &matriz[0][0], &matriz[0][1], &matriz[0][2]);
	
	for(int i=0; i<1; i++)
	{
		for(int j=0; j<3; j++)
		{
			printf("%d ", matriz[i][j]);
		}
	}
	
    return 0;
}