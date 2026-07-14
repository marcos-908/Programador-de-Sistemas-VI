#include<stdio.h>

int main()
{
	int opcao = 0;
	
	printf("O reino de C-Nai esta sendo atacado por monstros das trevas!\n O Rei Jhonson escolheu voce para ajudar o reino!\n VOCE ESTA PREPARADO?\n\n");
	printf("1 - SIM!\n");
	printf("2 - NAO!\n\n");
	do
	{
		scanf("%d", &opcao);
		if(opcao == 2)
		{
			printf("Entendo voce enfrentar as trevas sozinho e perigoso!\n");
		}else if(opcao == 1)
		{
			printf("O jogo vai comecar!\n O OBJETIVO FINAL e acabar com o dragao sombrio");
		}
	}while(opcao != 2);
	
	return(0);
}