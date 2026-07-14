#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu();
void criarpersonagem(char nome[], int *vida, int *vidamax, int *ataque, int *defesa, int *nivel, int *experiencia, int *ouro);
void mostrarstatus(char nomeex[], int vida, int vidamax, int ataque, int defesa, int nivel, int experiencia, int ouro);
void explorarmapa(int *vida, int ataque, int defesa, int *experiencia, int *ouro);
void subirnivel(int *vida, int *vidamax, int *ataque, int *defesa, int *nivel, int *experiencia);
void macaco(int *experiencia);
void combate(int *vida, int ataque, int defesa, int *vidainimigo, int ataqueinimigo, int *experiencia, int *ouro, int *venceu);
void loja(int *ouro);

int main()
{
	int opcao = 0;
	int escolha = 0;
	char nome [50];
	int vida = 0;
	int vidamax = 0;
	int ataque = 0;
	int defesa = 0;
	int nivel = 0;
	int experiencia = 0;
	int ouro = 0;
	
	srand(time(NULL));
	
	printf(" O reino de C-Nai esta sendo atacado por monstros das trevas!\n O Rei Jhonson escolheu voce para ajudar o reino!\n         VOCE ESTA PREPARADO?\n\n");
	printf("1 - SIM!\n");
	printf("2 - NAO!\n\n");
	scanf("%d", &opcao);
	
	if(opcao == 2)
	{
		printf("\nEntendo voce enfrentar as trevas sozinho e perigoso!\n");
	}else if(opcao == 1)
	{
		printf("\nO jogo vai comecar!\n O OBJETIVO FINAL e acabar com o dragao sombrio");
		
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
			explorarmapa(&vida, ataque, defesa, &experiencia, &ouro);
			break;
			
			case 4:
			
			
			case 67:
			macaco(&experiencia);
			subirnivel(&vida, &vidamax, &ataque, &defesa, &nivel, &experiencia);
			break;
			
			case 0:
			printf("saindo do jogo...\n");
		}
	}while(escolha != 0);
	}
		
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

void explorarmapa(int *vida, int ataque, int defesa, int *experiencia, int *ouro)
{
	int vidainimigo = 0;
	int ataqueinimigo = 0;
	int sorteio = 0;
	int sorteioouro = 0;
	int sorteiopocao = 0;
	int sorteiomonstro = 0;
	int venceu = 0;
	
	sorteio = (rand() % 5) + 1;
	
	if(sorteio == 1)
	{
		printf("Voce encontrou um monstro!\n");
		sorteiomonstro = (rand() % 4) + 1;
		if(sorteiomonstro == 1)
		{
			printf("Eita e um Globin!\n");
			vidainimigo = 30;
			ataqueinimigo = 5;
			combate(vida, ataque, defesa, &vidainimigo, ataqueinimigo, experiencia, ouro, &venceu);
			if(venceu == 1 && *vida >= 0)
			{
				*ouro += 10;
				*experiencia += 5;
				printf("+10 ouro\n");
				printf("+5 XP\n");
			}
		}else if (sorteiomonstro == 2)
		{
			printf("E um Esqueleto!!\n");
			vidainimigo = 50;
			ataqueinimigo = 8;
			combate(vida, ataque, defesa, &vidainimigo, ataqueinimigo, experiencia, ouro, &venceu);
			if(venceu == 1 && *vida >= 0)
			{
				*ouro += 15;
				*experiencia += 10;
				
				printf("+15 ouro\n");
				printf("+10 XP\n");
			}
		}else if(sorteiomonstro == 3)
		{
			printf("Toma cuidado e um Orc!!!\n");
			vidainimigo = 80;
			ataqueinimigo = 12;
			combate(vida, ataque, defesa, &vidainimigo, ataqueinimigo, experiencia, ouro, &venceu);
			if(venceu == 1 && *vida >= 0)
			{
				*ouro += 25;
				*experiencia += 20;
				printf("+25 ouro\n");
				printf("+20 XP\n");
			}
		}else if(sorteiomonstro == 4)
		{
			printf("Minha nossa e um Lobisomem!!!!\n");
			vidainimigo = 120;
			ataqueinimigo = 15;
			combate(vida, ataque, defesa, &vidainimigo, ataqueinimigo, experiencia, ouro, &venceu);
			if(venceu == 1 && *vida >= 0)
			{
				*ouro += 50;
				*experiencia += 40;
				printf("+50 ouro\n");
				printf("+40 XP\n");
			}
		}
	}else if(sorteio == 2)
	{
		printf("Parabens voce encontrou um bau do tesouro!\n");
		sorteioouro = (rand() % 50) + 1;
		*ouro = *ouro + sorteioouro;
		printf("Parabens vc ganhou %d moeda de ouro\n", sorteioouro);
	}else if(sorteio == 3)
	{
		printf("Voce encontrou uma pocao!\n");
		sorteiopocao = (rand() % 2) + 1;
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
		if(*vida <= 0)
		{
			printf("==============\n");
			printf("  GAME OVER!\n");
			printf("==============\n");
			printf("Voce morreu!\n");
			exit(0);
		}else
		{
			printf("Voce perdeu 15 pontos de vida\n");
		}
	}else if(sorteio == 5)
	{
		printf("Nada aconteceu...\n");
	}
}

void subirnivel(int *vida, int *vidamax, int *ataque, int *defesa, int *nivel, int *experiencia)
{
	if(*experiencia >= 100)
	{
		*nivel += 1;
		*vidamax = *vidamax + 20;
		*vida = *vidamax;
		*ataque = *ataque + 5;
		*defesa = *defesa + 3;
		*experiencia = 0;
		
		printf("Parabens vc conseguiu subir de nivel!");
	}
}

void macaco(int *experiencia)
{
	*experiencia += 10;
}

void combate(int *vida, int ataque, int defesa, int *vidainimigo, int ataqueinimigo, int *experiencia, int *ouro, int *venceu)
{
	int opcao_2 = 0;
	int dano = 0;
	int danorecebido = 0;
	int fugir = 0;
	
	while(*vida > 0 && *vidainimigo > 0)
	{
		printf("====================\n");
		printf("    COMBATE\n");
		printf("vida = %d\n", *vida);
		printf("vida do inimigo = %d\n", *vidainimigo);
		printf("====================\n");
		printf("\n\n1 - Atacar!\n");
		printf("2 - Defeder\n");
		printf("3 - Fugir\n");
		scanf("%d", &opcao_2);
			
		switch(opcao_2)
		{
			case 1:
			dano = ataque;
			*vidainimigo -= dano;
			if(*vidainimigo <= 0)
			{
				printf("Voce matou o inimigo!\n");
				*venceu = 1;
			}else
			{
				printf("Voce causou %d de dano no inimigo\n", dano);
				danorecebido = ataqueinimigo;
				*vida -= danorecebido;
				if(*vida <= 0)
				{
					printf("==============\n");
					printf("  GAME OVER!\n");
					printf("==============\n");
					printf("Voce morreu!\n");
					exit(0);
				}else
				{
					printf("Voce recebeu %d de dano\n", danorecebido);
				}
			}
			break;
			
			case 2:
			danorecebido =  ataqueinimigo / 2;
			*vida -= danorecebido;
			if(*vida <= 0)
				{
					printf("==============\n");
					printf("  GAME OVER!\n");
					printf("==============\n");
					printf("Voce morreu!\n");
					exit(0);
				}else
				{
					printf("Voce recebeu %d de dano\n", danorecebido);
				}
			break;
			
			case 3:
			fugir = (rand() % 2) + 1;
			if(fugir == 1)
			{
				printf("Falhou em tentar fugir!\n");
				danorecebido = ataqueinimigo;
				*vida -= danorecebido;
				if(*vida <= 0)
				{
					printf("==============\n");
					printf("  GAME OVER!\n");
					printf("==============\n");
					printf("Voce morreu!\n");
					exit(0);
				}else
				{
					printf("Voce recebeu %d de dano\n", danorecebido);
				}
			}else if(fugir == 2)
			{
				printf("Voce conseguiu fugir!\n");
				*vidainimigo = 0;
				*venceu = 0;
				break;
				
				default:
				printf("Voce nao escolheu nenhuma opcao\n");
				danorecebido = ataqueinimigo;
				*vida -= danorecebido;
				printf("Voce recebeu %d de dano\n", danorecebido);
				break;
			}
		}
	}
}

void loja(int *ouro)
{
	
}