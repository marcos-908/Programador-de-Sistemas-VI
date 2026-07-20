#include<stdio.h>
#include<string.h>

struct Aluno
{
	char nome[50];
	int idade;
	float nota;
};

int main()
{
	struct Aluno a1;
	strcpy(a1.nome, "joao");
	scanf("%d", &a1.idade);
	scanf("%lf", &a1.nota);
	printf("Nome %s\n", a1.nome);
	printf("Idade %d\n", &a1.idade);
	printf("Nota %2f\n", &a1.nota);
	
	return(0);
}