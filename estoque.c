#include<stdio.h>
#include<stdlib.h>
#include<libpq-fe.h>

void menu();
void select(PGconn *conn);
void update(PGconn *conn);
void insert(PGconn *conn);
void delete(PGconn *conn);

int main()
{
	int escolha = 0;
	
	const char *conninfo = "host=localhost port=5432 dbname=Estoque user=postgres password=admin";
	
	PGconn *conn = PQconnectdb(conninfo);
	
	if (PQstatus(conn) != CONNECTION_OK)
	{
		fprintf(stderr, "Erro de conexao: %s\n", PQerrorMessage(conn));
		PQfinish(conn);
		return(1);
	}
	
	printf("Conectado ao banco com sucesso!\n");
	
	do{
		menu();
		scanf("%d", &escolha);
		switch(escolha)
		{
			case 1:
			system("cls");
			select(conn);
			break;
			
			case 2:
			system("cls");
			select(conn);
			update(conn);
			break;
			
			case 3:
			system("cls");
			select(conn);
			insert(conn);
			break;
			
			case 4:
			system("cls");
			select(conn);
			delete(conn);
			break;
			
			case 0:
			system("cls");
			printf("Sistema Finalizado\n");
			break;
			
			default:
			system("cls");
			printf("\nATENCAO: Escolha uma das opcoes disponiveis no menu!\n\n");
		}
	}while(escolha != 0);
	
	PQfinish(conn);
	
	return(0);
}

void menu()
{
    printf("\n");
    printf("+--------------------------------------+\n");
    printf("|           SISTEMA DE ESTOQUE         |\n");
    printf("+--------------------------------------+\n");
    printf("|                                      |\n");
    printf("|   1 - Consultar produtos             |\n");
    printf("|   2 - Alterar produto                |\n");
    printf("|   3 - Cadastrar produto              |\n");
    printf("|   4 - Excluir produto                |\n");
    printf("|   0 - Sair                           |\n");
    printf("|                                      |\n");
    printf("+--------------------------------------+\n");
}

void select(PGconn *conn)
{
	PGresult *res = PQexec(conn, "select * from estoque;");
	
	  if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        fprintf(stderr, "Erro na consulta: %s\n", PQerrorMessage(conn));
        PQclear(res);
        return;
    }
	
	int linhas = PQntuples(res);
    int colunas = PQnfields(res);
	
	printf("Total de linhas: %d\n", linhas);
    printf("Total de colunas: %d\n\n", colunas);
	
	for (int j = 0; j < colunas; j++) {
        printf("%-20s", PQfname(res, j));
    }
	
	printf("\n---------------------------------------------------------------------------\n");
	
	for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%-20s", PQgetvalue(res, i, j));
        }
        printf("\n");
    }
	
	PQclear(res);
}

void update(PGconn *conn)
{
	int id;
    char nome[50];
    int quantidade;
    double preco;
    char sql[300];
	
	printf("\nID do produto: ");
    scanf("%d", &id);
	
	printf("Novo produto: ");
    scanf("%49s", nome);
	
	printf("Nova quantidade: ");
    scanf("%d", &quantidade);
	
	printf("Novo preco: ");
    scanf("%lf", &preco);
	
	sprintf(sql, "UPDATE estoque SET nome = '%s', quantidade = %d, preco = %.2lf WHERE id = %d;", nome, quantidade, preco, id);
	
	PGresult *res = PQexec(conn, sql);
	
	if (PQresultStatus(res) != PGRES_COMMAND_OK)
    {
        fprintf(stderr, "Erro no UPDATE: %s\n", PQerrorMessage(conn));
        PQclear(res);
        return;
    }
	
	printf("Produto atualizado com sucesso!\n");
	
	PQclear(res);
}

void insert(PGconn *conn)
{
	char nome[50];
    int quantidade;
    double preco;
    char sql[300];
	
	printf("\nNome do produto: ");
    scanf("%49s", nome);

    printf("Quantidade: ");
    scanf("%d", &quantidade);

    printf("Preco: ");
    scanf("%lf", &preco);
	
	sprintf(sql, "INSERT INTO estoque (nome, quantidade, preco) VALUES ('%s', %d, %.2lf);", nome, quantidade, preco);
	
	PGresult *res = PQexec(conn, sql);
	
	if (PQresultStatus(res) != PGRES_COMMAND_OK)
    {
        fprintf(stderr, "Erro no INSERT: %s\n", PQerrorMessage(conn));
        PQclear(res);
        return;
    }
	
	printf("Produto cadastrado com sucesso!\n");
	
	PQclear(res);
}

void delete(PGconn *conn)
{
	int id;
	char sql[300];
	
	printf("ID do produto:  ");
	scanf("%d", &id);
	
	sprintf(sql, "\nDELETE FROM estoque WHERE id = %d;", id);
	
	PGresult *res = PQexec(conn, sql);
	
	if (PQresultStatus(res) != PGRES_COMMAND_OK)
    {
        fprintf(stderr, "Erro no DELETE: %s\n", PQerrorMessage(conn));
        PQclear(res);
        return;
    }
	
	printf("Produto excluido com sucesso!\n");
	
	PQclear(res);
}