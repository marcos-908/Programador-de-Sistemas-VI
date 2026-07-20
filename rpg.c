#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu();
void criarpersonagem(char nome[], int *vida, int *vidamax, int *ataque, int *defesa, int *nivel, int *experiencia, int *ouro);
void mostrarstatus(char nomeex[], int vida, int vidamax, int ataque, int defesa, int nivel, int experiencia, int ouro);
void explorarmapa(int *vida, int ataque, int defesa, int *experiencia, int *ouro, int *pocao_pequena, int *pocao_grande);
void subirnivel(int *vida, int *vidamax, int *ataque, int *defesa, int *nivel, int *experiencia);
void combate(int *vida, int ataque, int defesa, int *vidainimigo, int ataqueinimigo, int *experiencia, int *ouro, int *venceu);
void loja(int *ouro, int *pocao_pequena, int *pocao_grande, int *espada, int *armadura, int *escudo);
void inventario(int *vida, int *vidamax, int *ataque, int *defesa, int *pocao_pequena, int *pocao_grande, int *espada, int *armadura, int *escudo);
void descansar(int *vida, int *vidamax);
void chefefinal(int *vida, int *vidamax, int *ataque, int *defesa, int *experiencia, int *ouro, int *nivel);

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
	int pocao_pequena = 0;
	int pocao_grande = 0;
	int espada = 0;
	int armadura = 0;
	int escudo = 0;
	
	srand(time(NULL));
	
	printf(" O ceu sobre o reino de C-Nai escureceu de vez. Monstros de sombrios invadiram as muralhas do sul e avancam sem piedade.\n No salao do trono, o Rei Jhonson - desarmado e desesperado - implora diretamente pela sua ajuda:Nossos portoes cairam e nao nos resta mais nada. Por favor, voce e a nossa ultima esperanca!\n         VOCE ESTA PREPARADO?\n\n");
	printf("1 - SIM!\n");
	printf("2 - NAO!\n\n");
	scanf("%d", &opcao);
	
	if(opcao == 2)
	{
		printf("\n Voce da as costas ao desespero do Rei. Sem a sua ajuda, as sombras engolem o trono e o reino de C-Nai cai em ruinas para sempre.\n Voce escolheu a covardia.\n==============\n  GAME OVER!\n==============\n");
	}else if(opcao == 1)
	{
		printf("\n O Rei Jhonson recupera o folego e aponta para as portas que tremem: Que os deuses o guiem! Sua missao final e destruir o Dragao Sombrio, a origem de todo este mal!\n Voce saca sua arma e se prepara para o pior. A batalha comeca agora!");
		
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
			explorarmapa(&vida, ataque, defesa, &experiencia, &ouro, &pocao_pequena, &pocao_grande);
			subirnivel(&vida, &vidamax, &ataque, &defesa, &nivel, &experiencia);
			break;
			
			case 4:
			loja(&ouro, &pocao_pequena, &pocao_grande, &espada, &armadura, &escudo);
			break;
			
			case 5:
			inventario(&vida, &vidamax, &ataque, &defesa, &pocao_pequena, &pocao_grande, &espada, &armadura, &escudo);
			break;
			
			case 6:
			descansar(&vida, &vidamax);
			break;
			
			case 7:
			chefefinal(&vida, &vidamax, &ataque, &defesa, &experiencia, &ouro, &nivel);
			break;
			
			case 0:
			printf("saindo do jogo...\n");
			break;
			
			default:
			printf("Voce nao escolheu nada");
		}
	}while(escolha != 0);
	}
	system("pause");
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

void explorarmapa(int *vida, int ataque, int defesa, int *experiencia, int *ouro, int *pocao_pequena, int *pocao_grande)
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
			*pocao_pequena += 1;
		}else if(sorteiopocao == 2)
		{
			printf("Era uma pocao grande!\n");
			*pocao_grande += 1;
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
			system("pause");
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
	while(*experiencia >= 100)
	{
		*nivel += 1;
		*vidamax = *vidamax + 20;
		*vida = *vidamax;
		*ataque = *ataque + 5;
		*defesa = *defesa + 3;
		*experiencia -= 100;
		
		printf("Parabens vc conseguiu subir de nivel!");
	}
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
					system("pause");
					exit(0);
				}else
				{
					printf("Voce recebeu %d de dano\n", danorecebido);
				}
			}
			break;
			
			case 2:
			danorecebido =  ataqueinimigo - defesa;
			if(danorecebido < 0)
			{
				danorecebido = 0;
			}
			*vida -= danorecebido;
			if(*vida <= 0)
				{
					printf("==============\n");
					printf("  GAME OVER!\n");
					printf("==============\n");
					printf("Voce morreu!\n");
					system("pause");
					exit(0);
				}else
				{
					printf("Voce defendeu o ataque!");
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
					system("pause");
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

void loja(int *ouro, int *pocao_pequena, int *pocao_grande, int *espada, int *armadura, int *escudo)
{
	int opcao = 0;
	int preco_pocao_pequena = 50;
	int preco_pocao_grande = 100;
	int preco_espada = 500;
	int preco_armadura = 650;
	int preco_escudo = 300;
	
	do{
		
		printf("         _\\/_          \n");
		printf("       .-\"   \"-.        \n");
		printf("      / .---. \\        \n");
		printf("     | /     \\ |       \n");
		printf("     | | o o | |\n");
		printf("     \\ \\  -  / /       \n");
		printf("      \\ `---' /        \n");
		printf("      /`-----'\\        \n");
		printf("     / |  $  | \\       \n");
		printf("    /  |_____|  \\      \n");
		printf("   /_____________\\     \n");
		printf("   |             |     \n");
		printf("   |=== BALCAO ==|     \n");
		printf("   |_____________|     \n");
		printf("VENDEDOR: \"Bem-vindo, viajante! O que vai querer?\"\n");
		printf("\n\n=====================\n");
		printf("       LOJA          \n");
		printf("=====================\n");
		printf("1 - Pocao Pequena | 50\n");
		printf("2 - Pocao Grande  | 100\n");
		printf("3 - Espada        | 500\n");
		printf("4 - Armadura      | 650\n");
		printf("5 - Escudo        | 300\n");
		printf("0 - Voltar\n");
		printf("Sua Escolha:\n");
	
		scanf("%d", &opcao);
		
		switch(opcao)
		{
			case 1:
			if(*ouro >= preco_pocao_pequena)
			{
				printf("Voce comprou uma pocao pequena!\n");
				*ouro -= preco_pocao_pequena;
				*pocao_pequena += 1;
				printf("Ouro restante = %d\n", *ouro);
			}else
			{
				printf("Voce nao tem moedas de ouro sufciente!\n");
			}
			break;
			
			case 2:
			if(*ouro >= preco_pocao_grande)
			{
				printf("Voce comprou uma pocao grande\n");
				*ouro -= preco_pocao_grande;
				*pocao_grande += 1;
				printf("Ouro restante = %d\n", *ouro);
			}else
			{
				printf("Voce nao tem moedas de ouro sufciente!\n");
			}
			break;
			
			case 3:
			if(*espada == 0)
			{
				if(*ouro >= preco_espada)
				{
					printf("Voce comprou uma espada!\n");
					*ouro -= preco_espada;
					*espada = 1;
					printf("Ouro restante = %d\n", *ouro);
				}else
				{
					printf("Voce nao tem moedas de ouro sufciente!\n");
				}
			}else
			{
				printf("Voce ja tem uma espada!\n");
			}
			break;
			
			case 4:
			if(*armadura == 0)
			{
				if(*ouro >= preco_armadura)
				{
					printf("Voce comprou uma armadura\n");
					*ouro -= preco_armadura;
					*armadura = 1;
					printf("Ouro restante = %d\n\n", *ouro);
				}else
				{
					printf("Voce nao tem moedas de ouro sufciente!\n");
				}
			}else
			{
				printf("Voce ja tem uma armadura!\n");
			}
			break;
			
			case 5:
			if(*escudo == 0)
			{
				if(*ouro >= preco_escudo)
				{
					printf("Voce comprou um escudo\n");
					*ouro -= preco_escudo;
					*escudo = 1;
					printf("Ouro restante = %d\n", *ouro);
				}else
				{
					printf("Voce nao tem moedas de ouro sufciente!\n");
				}
			}else
			{
				printf("Voce ja tem um escudo!\n");
			}
			break;
			
			case 0:
			printf("Voce saiu da loja\n");
			break;
			
			default:
			printf("Voce nao escolheu nenhuma opcao disponivel\n");
			break;
		}
	}while(opcao != 0);
}

void inventario(int *vida, int *vidamax, int *ataque, int *defesa, int *pocao_pequena, int *pocao_grande, int *espada, int *armadura, int *escudo)
{
	int opcao = 0;
	int opcao_2 = 0;
	
	do
	{
		printf("\n\n===================\n");
		printf("    INVENTARIO\n");
		printf("===================\n");
		printf("\n1 - Vizualizar Itens\n");
		printf("2 - Usar Item\n");
		printf("3 - Descatar Item\n");
		printf("0 - Voltar\n");
		printf("Sua Escolha:\n");
		
		scanf("%d", &opcao);
		
		switch(opcao)
		{
			case 1:
			do{
				if(*pocao_pequena >= 1)
				{
					printf("1 - Pocao Pequena | %d\n", *pocao_pequena);
				}else
				{
					printf("1 - Pocao Pequena | Nao tem!\n");
				}
				if(*pocao_grande >= 1)
				{
					printf("2 - Pocao Grande  | %d\n", *pocao_grande);
				}else
				{
					printf("2 - Pocao Grande  | Nao tem!\n");
				}
				if(*espada == 1)
				{
					printf("3 - Espada        | Nao equipada\n");
				}else if(*espada == 2)
				{
					printf("3 - Espada        | Equipada\n");
				}else
				{
					printf("3 - Espada        | Nao tem!\n");
				}
				if(*armadura == 1)
				{
					printf("4 - Armadura      | Nao equipada\n");
				}else if(*armadura == 2)
				{
					printf("4 - Armadura      | Equipada\n");
				}else
				{
					printf("4 - Armadura      | Nap tem!\n");
				}
				if(*escudo == 1)
				{
					printf("5 - Escudo        | Nao equipada\n");
				}else if(*escudo == 2)
				{
					printf("5 - Escudo        | Equipada\n");
				}else
				{
					printf("5 - Escudo        | Nao tem\n");
				}
				printf("0 - Voltar\n");
				scanf("%d", &opcao_2);
			}while(opcao_2 != 0);
			break;
			
			case 2:
			do{
				if(*pocao_pequena >= 1)
				{
					printf("1 - Pocao Pequena | %d\n", *pocao_pequena);
				}else
				{
					printf("1 - Pocao Pequena | Nao tem!\n");
				}
				if(*pocao_grande >= 1)
				{
					printf("2 - Pocao Grande  | %d\n", *pocao_grande);
				}else
				{
					printf("2 - Pocao Grande  | Nao tem!\n");
				}
				if(*espada == 1)
				{
					printf("3 - Espada        | Nao equipada\n");
				}else if(*espada == 2)
				{
					printf("3 - Espada        | Equipada\n");
				}else
				{
					printf("3 - Espada        | Nao tem!\n");
				}
				if(*armadura == 1)
				{
					printf("4 - Armadura      | Nao equipada\n");
				}else if(*armadura == 2)
				{
					printf("4 - Armadura      | Equipada\n");
				}else
				{
					printf("4 - Armadura      | Nap tem!\n");
				}
				if(*escudo == 1)
				{
					printf("5 - Escudo        | Nao equipada\n");
				}else if(*escudo == 2)
				{
					printf("5 - Escudo        | Equipada\n");
				}else
				{
					printf("5 - Escudo        | Nao tem\n");
				}
				printf("0 - Voltar\n");
				printf("Sua Escolha:\n");
				scanf("%d", &opcao_2);
				
				switch(opcao_2)
				{
					case 1:
					if(*pocao_pequena >= 1)
					{
						*vida += 20;
						
						if(*vida >= *vidamax)
						{
							*vida = *vidamax;
						}
						
						printf("Voce recuperou vida!\n");
						*pocao_pequena -= 1;
					}else
					{
						printf("Voce nao tem pocao pequena!\n");
					}
					break;
					
					case 2:
					if(*pocao_grande >= 1)
					{
						*vida += 50;
						
						if(*vida >= *vidamax)
						{
							*vida = *vidamax;
						}
						
						printf("Voce recuperou vida!\n");
						*pocao_grande -= 1;
					}else
					{
						printf("Voce nao tem pocao grande!\n");
					}
					break;
					
					case 3:
					if(*espada == 1)
					{
						*ataque += 5;
						*espada = 2;
					}else if(*espada == 2)
					{
						printf("A espada ja esta equipada\n");
					}else
					{
						printf("Voce nao possui a espada!\n");
					}
					break;
					
					case 4:
					if(*armadura == 1)
					{
						*defesa += 5;
						*armadura = 2;
					}else if(*armadura == 2)
					{
						printf("A armadura ja esta equipada\n");
					}else
					{
						printf("Voce nao possui a armadura!\n");
					}
					break;
					
					case 5:
					if(*escudo == 1)
					{
						*defesa += 3;
						*escudo = 2;
					}else if(*escudo == 2)
					{
						printf("O escudo ja esta esquipado\n");
					}else
					{
						printf("Voce nao possui o escudo!\n");
					}
					break;
				}
				
			}while(opcao_2 != 0);
			break;
			
			case 3:
			do
			{
				if(*pocao_pequena >= 1)
				{
					printf("1 - Pocao Pequena | %d\n", *pocao_pequena);
				}else
				{
					printf("1 - Pocao Pequena | Nao tem!\n");
				}
				if(*pocao_grande >= 1)
				{
					printf("2 - Pocao Grande  | %d\n", *pocao_grande);
				}else
				{
					printf("2 - Pocao Grande  | Nao tem!\n");
				}
				if(*espada == 1)
				{
					printf("3 - Espada        | Nao equipada\n");
				}else if(*espada == 2)
				{
					printf("3 - Espada        | Equipada\n");
				}else
				{
					printf("3 - Espada        | Nao tem!\n");
				}
				if(*armadura == 1)
				{
					printf("4 - Armadura      | Nao equipada\n");
				}else if(*armadura == 2)
				{
					printf("4 - Armadura      | Equipada\n");
				}else
				{
					printf("4 - Armadura      | Nap tem!\n");
				}
				if(*escudo == 1)
				{
					printf("5 - Escudo        | Nao equipada\n");
				}else if(*escudo == 2)
				{
					printf("5 - Escudo        | Equipada\n");
				}else
				{
					printf("5 - Escudo        | Nao tem\n");
				}
				printf("0 - Voltar\n");
				printf("Sua escolha:\n");
				scanf("%d", &opcao_2);
				
				switch(opcao_2)
				{
					case 1:
					if(*pocao_pequena >= 1)
					{
						*pocao_pequena -= 1;
						printf("Voce descartou uma pocao pequena!\n");
					}else
					{
						printf("Nao tem pocao pequena para descartar!\n");
					}
					break;
					
					case 2:
					if(*pocao_grande >= 1)
					{
						*pocao_grande -= 1;
					}else
					{
						printf("Nao tem pocao grande para descartar!\n");
					}
					break;
					
					case 3:
					if(*espada == 0)
					{
						printf("Sem espada para descartar!\n");
					}else if(*espada == 1)
					{
						*espada = 0;
						printf("Voce descartou a espada!\n");
					}else if(*espada == 2)
					{
						*ataque -= 5;
						*espada = 0;
						printf("Voce descartou a espada!\n");
					}
					break;
					
					case 4:
					if(*armadura == 0)
					{
						printf("Sem armadura para descartar!\n");
					}else if(*armadura == 1)
					{
						*armadura = 0;
						printf("Voce descartou a armadura!\n");
					}else if(*armadura == 2)
					{
						*defesa -= 5;
						*armadura = 0;
						printf("Voce descartou a armadura!\n");
					}
					break;
					
					case 5:
					if(*escudo == 0)
					{
						printf("Sem escudo para descartar!\n");
					}else if(*escudo == 1)
					{
						*escudo = 0;
						printf("Voce descartou o escudo!\n");
					}else if(*escudo ==2)
					{
						*defesa -= 3;
						*escudo = 0;
						printf("Voce descartou o escudo!\n");
					}
					break;
				}
			}while (opcao_2 != 0);
		}
	}while(opcao != 0);
}

void descansar(int *vida, int *vidamax)
{
	*vida += 30;
	if(*vida >= *vidamax)
	{
		*vida = *vidamax;
		printf("Voce recuperou vida!\n");
	}else
	{
		printf("Voce recuperou vida!\n");
	}
}

void chefefinal(int *vida, int *vidamax, int *ataque, int *defesa, int *experiencia, int *ouro, int *nivel)
{
	int vidainimigo = 300;
	int ataqueinimigo = 25;
	int venceu = 0;
	
	if(*nivel <= 5)
	{
		printf("Voce ainda nao esta preparado!\n");
	}else if(*nivel >= 5)
	{
		printf("Voce decide enfrentar o dragao!\n");
		combate(vida, *ataque, *defesa, &vidainimigo, ataqueinimigo, experiencia, ouro, &venceu);
		if(venceu == 1 && *vida >= 0)
		{
			*ouro += 1000000;
			*experiencia += 1000000;
			printf("+1000000 de ouro!\n");
			printf("+1000000 de XP!\n");
			printf("PARABENS VOCE GANHOU O JOGO!\n");
			system("pause");
			exit(0);
		}
	}
}