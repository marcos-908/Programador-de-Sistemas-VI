#include<stdio.h>
#include<stdlib.h>

void menu();
void criarpersonagem(char nome[], int *vida, int *vidamax, int *ataque, int *defesa, int *nivel, int *experiencia, int *ouro);
void mostrarstatus(char nomeex[], int vida, int vidamax, int ataque, int defesa, int nivel, int experiencia, int ouro);
void explorarmapa(int *vida, int *experiencia, int *ouro);
void subirnivel(int *vida, int *vidamax, int *ataque, int *defesa, int *nivel, int *experiencia, int *ouro);

int main()
{
	int escolha = 0;
	char nome [50];
	int vida = 0;
	int vidamax = 0;
	int ataque = 0;
	int defesa = 0;
	int nivel = 0;
	int experiencia = 0;
	int ouro = 0;
	
	do{
		menu();
		scanf("%d", &escolha);
		switch(escolha)
		{
			case 1:
			criarpersonagem(nome, &vida, &vidamax, &ataque, &defesa, &nivel, &experiencia, &ouro);
			break;
			
			case 2:
			mostrarstatus(nome, vida, vidamax, ataque, defesa, nivel, experiencia, ouro);
			break;
			
			case 3:
			explorarmapa(&vida, &experiencia, &ouro);
			break;
			
			case 0:
			printf("saindo do jogo...\n");
		}
	}while(escolha != 0);
		
	return(0);
}

void menu()
{
	printf("\n");
	printf("=================================\n");
	printf("RPG DE TEXTO - A JORNADA DO HEROI\n");
	printf("=================================\n");
	printf("\n");
	printf("1 - Criar Personagem\n");
	printf("2 - Ver Status\n");
	printf("3 - Explorar Mapa\n");
	printf("4 - Loja\n");
	printf("5 - Inventario\n");
	printf("6 - Descansar\n");
	printf("7 - Enfrentar Chefe Final\n");
	printf("0 - Sair\n");
	printf("\n");
	printf("Escolha:\n");
}

void criarpersonagem(char nome[], int *vida, int *vidamax, int *ataque, int *defesa, int *nivel, int *experiencia, int *ouro)
{
	printf("\nescolha um nome para o personagem\n");
	scanf("%s", nome);
	*vida = 100;
	*vidamax = 100;
	*ataque = 10;
	*defesa = 5;
	*nivel = 1;
	*experiencia = 0;
	*ouro = 50;
	printf("personagem criado com sucesso!\n");
}

void mostrarstatus(char nomeex[], int vida, int vidamax, int ataque, int defesa, int nivel, int experiencia, int ouro)
{
	printf("\nNome: %s\n", nomeex);
	printf("\n");
	printf("Vida: %d/%d\n", vida, vidamax);
	printf("Ataque: %d\n", ataque);
	printf("Defesa: %d\n", defesa);
	printf("\n");
	printf("Nivel: %d\n", nivel);
	printf("Experiencia: %d\n", experiencia);
	printf("\n");
	printf("Ouro: %d\n", ouro);
	
}

void explorarmapa(int *vida, int *experiencia, int *ouro)
{
	int sorteio = 0;
	int sorteioouro = 0;
	int sorteiopocao = 0;
	int sorteiomonstro = 0;
	int vidainimigo = 0;
	int ataqueinimigo = 0;
	
	sorteio = (rand() % 5) + 1;
	
	if(sorteio == 1)
	{
		printf("Voce encontrou um monstro!\n");
		sorteiomonstro = (rand() % 4) + 1;
		if(sorteiomonstro == 1)
		{
			printf("Eita e um Globin!\n");
		}else if (sorteiomonstro == 2)
		{
			printf("E um Esqueleto!!\n");
		}else if(sorteiomonstro == 3)
		{
			printf("Toma cuidado e um Org!!!\n");
		}else if(sorteiomonstro == 4)
		{
			printf("Minha nossa e um Lobisomen!!!!\n");
		}
	}else if(sorteio == 2)
	{
		printf("Parabens voce encontrou um bau do tesouro!\n");
		sorteioouro = (rand() % 50) + 1;
		*ouro = *ouro + sorteioouro;
		printf("Parabens vc ganhou %d de ouro\n", sorteioouro);
	}else if(sorteio == 3)
	{
		printf("Voce encontrou uma pocao!\n");
		sorteiopocao = (rand() % 2) + 8;
		if(sorteiopocao == 1)
		{
			printf("Era uma pocao pequena!\n");
		}else if(sorteiopocao == 2)
		{
			printf("Era uma pocao grande!\n");
		}
	}else if(sorteio == 4)
	{
		printf("Voce caiu em uma armadilha!\n");
		*vida = *vida - 15;
		printf("Voce perdeu 15 pontos de vida\n");
	}else if(sorteio == 5)
	{
		printf("Nada aconteceu...\n");
	}
}