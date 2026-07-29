#include<stdio.h>
#define TAM 5
#define TESOUROS 3

typedef struct
{
	char nome[20];
	int tentativas;
}Jogador;

void inicianizarmapa(char mapa[TAM][TAM]);
void mostrarmapa(char mapa[TAM][TAM]);
void posicionartesouros(char mapa[TAM][TAM]);
int procurartesouros(char mapa[TAM][TAM], int *encontrados);
void salvarresultado(Jogador jogador);

int main()
{
	char mapa[TAM][TAM];
	Jogador jogador;
	int encontrados = 0;
	jogador.tentativas = 0;
	
	
	printf("------Bem Vindo Ao Game------\n");
	printf("Insira o seu nome:\n");
	scanf(" %s", jogador.nome);
	
	inicianizarmapa(mapa);
	posicionartesouros(mapa);
	while(encontrados < 3)
	{
		mostrarmapa(mapa);
		procurartesouros(mapa, &encontrados);
		jogador.tentativas += 1;
		
	}
	
	mostrarmapa(mapa);
	
	salvarresultado(jogador);
	printf("\n\nParabens voce achou todos os tesouros!\n");
	printf("--------------------------------------\n");
	printf("Nome: %s\n", jogador.nome);
	printf("Tentativas: %d\n", jogador.tentativas);
	printf("--------------------------------------\n");
	
	
	return(0);
}

void inicianizarmapa(char mapa[TAM][TAM])
{
	int i, j;
	
	for(int i = 0; i < TAM; i++)
	{
		for(int j = 0; j < TAM; j++)
		{
			mapa[i][j] = '#';
		}
	}
}

void mostrarmapa(char mapa[TAM][TAM])
{
	int i, j;
	
	printf("\n");
	printf(" ");
	for(int j = 0; j < TAM; j++)
	{
		printf(" %d", j);
	}
	
	printf("\n");
	
	for(int i = 0; i < TAM; i++)
	{
		printf("\n%d ", i);
		
		for(int j = 0; j < TAM; j++)
		{
			printf("%c ", mapa[i][j]);	
		}
	}
}

void posicionartesouros(char mapa[TAM][TAM])
{
	mapa[3][1] = 'T';
	mapa[4][0] = 'T';
	mapa[3][2] = 'T';
}

int procurartesouros(char mapa[TAM][TAM], int *encontrados)
{
	int linha = 0;
	int coluna = 0;
	
	printf("\nlinha: ");
	scanf("%d", &linha);
	printf("\ncoluna: ");
	scanf("%d", &coluna);
	
	if(mapa[linha][coluna] == 'T')
	{
		printf("\n\nTesouro encontrado!\n\a");
		mapa[linha][coluna] = 'X';
		*encontrados += 1;
		return(1);
	}
	
	printf("\nNada encontrado\n");
	mapa[linha][coluna] = 'O';
	
	return(1);
}

void salvarresultado(Jogador jogador)
{
	FILE *arquivo;
	
	arquivo = fopen("historico.txt", "a");
	
	if(arquivo == NULL)
	{
		printf("Erro ao abrir!\n");
		return;
	}else
	{
		fprintf(arquivo, "%s | %d\n", jogador.nome, jogador.tentativas);
		fclose(arquivo);
	}
}