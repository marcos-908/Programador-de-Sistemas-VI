#include<stdio.h>
#define TAM 8
#define NAVIOS 3

typedef struct
{
	char nome[50];
	int tentativas;
}Jogador;

void inicianizartabuleiro(char tabuleiro[TAM][TAM]);
void mostrartabuleiro(char tabuleiro[TAM][TAM]);
void posicionarnavios(char tabuleiro[TAM][TAM]);
void realizaataque(char tabuleiro[TAM][TAM], int *destruidos);
void salvarresultado(Jogador jogador);
void lerresultado();

int main()
{
	Jogador jogador;
	jogador.tentativas = 0;
	int destruidos = 0;
	char tabuleiro[TAM][TAM];
	
	printf("------------------------\n");
	printf("     Batalha Naval!\n");
	printf("------------------------\n");
	
	printf("Digita seu nome\n");
	scanf("%s", jogador.nome);
	
	inicianizartabuleiro(tabuleiro);
	posicionarnavios(tabuleiro);
	while(destruidos < 3)
	{
		mostrartabuleiro(tabuleiro);
		realizaataque(tabuleiro, &destruidos);
		jogador.tentativas += 1;
	}
	
	mostrartabuleiro(tabuleiro);
	salvarresultado(jogador);
	
	printf("\nPARABENS!\nTODOS NAVIOS FORAM DESTRUIDOS!!!!\n");
	printf("----------------------------------------\n");
	printf("Nome: %s\n", jogador.nome);
	printf("Tentativas: %d\n", jogador.tentativas);
	printf("----------------------------------------\n");
	
	return(0);
}

void inicianizartabuleiro(char tabuleiro[TAM][TAM])
{
	int i, j;
	
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			tabuleiro[i][j] = '~';
		}
	}
}

void mostrartabuleiro(char tabuleiro[TAM][TAM])
{
	int i, j;
	
	printf(" ");
	
	for(int j = 0; j < 8; j++)
	{
		printf(" %d", j);
	}
	
	printf("\n");
	
	for(int i = 0; i < 8; i++)
	{
		printf("\n%d", i);
		
		for(int j = 0; j < 8; j++)
		{
			printf(" %c", tabuleiro[i][j]);
		}
	}
	
	printf("\n");
}

void posicionarnavios(char tabuleiro[TAM][TAM])
{
	tabuleiro[5][4] = 'N';
	tabuleiro[2][5] = 'N';
	tabuleiro[0][7] = 'N';
}

void realizaataque(char tabuleiro[TAM][TAM], int *destruidos)
{
	int linha, coluna;
	
	printf("Realize um ataque!\n");
	printf("\nlinha: ");
	scanf("%d", &linha);
	printf("\ncoluna: ");
	scanf("%d", &coluna);
	
	if(tabuleiro[linha][coluna] == 'N')
	{
		printf("Acertou o Navio!\n");
		tabuleiro[linha][coluna] = 'X';
		*destruidos += 1;
	}else if(tabuleiro[linha][coluna] == '~')
	{
		printf("Acertou na agua\n");
		tabuleiro[linha][coluna] = 'O';
	}else if(tabuleiro[linha][coluna] == 'O')
	{
		printf("posicao ja utilizada!\n");
	}else if(tabuleiro[linha][coluna] == 'X')
	{
		printf("posicao ja utilizada!\n");
	}
}

void salvarresultado(Jogador jogador)
{
	FILE *Navios;
	
	Navios = fopen("Navio.txt", "a");
	
	if(Navios == NULL)
	{
		printf("Erro ao abrir!\n");
		return;
	}else
	{
		fprintf(Navios, "%s | %d\n", jogador.nome, jogador.tentativas);
		fclose(Navios);
	}
}