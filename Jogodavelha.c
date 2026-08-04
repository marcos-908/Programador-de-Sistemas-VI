#include<stdio.h>
#include<stdlib.h>

char matrix[3][3];

char check();
void init_matrix();
void get_player_move();
void get_computer_move();
void disp_matrix();

int main()
{
	char done;
	printf("Este e o jogo-da-velha.\n");
	printf("Voce Estara jogando contra o computador.\n");
	
	done = ' ';
	init_matrix();
	do
	{
		disp_matrix();
		get_player_move();
		done = check();
		if(done != ' ')
		{
			break;
		}
		get_computer_move();
		done = check();
	}while(done == ' ');
	if(done == 'X')
	{
		printf("Voce Ganhou!\n");
	}
	else
	{
		printf("Supremacia das maquinas\n");
	}
	disp_matrix();
	return(0);
}

void init_matrix()
{
	int i = 0;
	int j = 0;
	for(int i = 0; i < 3; i++)
	{
		for(j=0; j < 3; j++)
		{
			matrix[i][j] = ' ';
		}
	}
}

void get_player_move()
{
	int x = 0;
	int y = 0;
	printf("Digite as coordenadas para o X:");
	scanf("%d %d",&x,&y);
	if(matrix[x][y] != ' ')
	{
		printf("Posicao invalida, tente novamente\n");
		get_player_move();
	}
	else
	{
		matrix[x][y] = 'X';
	}
}

void get_computer_move()
{
	int i, j;
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			if(matrix[i][j] == ' ')
			{
				break;
			}
		}
		if(matrix[i][j] == ' ')
		{
			break;
		}
	}
	
	if(i*j == 9)
	{
		printf("empate\n");
		exit(0);
	}
	else
	{
		matrix[i][j] = 'O';
	}
}

void disp_matrix()
{
	int t;
	
	for(t = 0; t < 3; t++)
	{
		printf(" %c | %c | %c ", matrix[t][0],matrix[t][1],matrix[t][2]);
		if(t != 2)
		{
			printf("\n---|---|---\n");
		}
	}
	printf("\n");
}

char check()
{
	int i;
	
	for(int i = 0; i < 3; i++ )
	{
		if(matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2])
		{
			return(matrix[i][0]);
		}
	}
	
	for(int i = 0; i < 3; i++)
	{
		if(matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i])
		{
			return(matrix[0][i]);
		}
	}
	
	if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
	{
		return(matrix[0][0]);
	}
	if(matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
	{
		return(matrix[0][2]);
	}
	
	return ' ';
}
