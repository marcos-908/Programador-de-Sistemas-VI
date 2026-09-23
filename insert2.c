#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

int main() {
	// Variáveis
    char produto[15];
    int quantidade = 0;
    double preco = 0.0;
	int tamanho = 0;
	PGresult *res = NULL;
	
    // String de conexão — ajuste os dados conforme seu banco
    const char *conninfo = "host=localhost port=5432 dbname=Estoque user=postgres password=admin";

    // Conecta ao banco
    PGconn *conn = PQconnectdb(conninfo);

    // Verifica se a conexão deu certo
    if (PQstatus(conn) != CONNECTION_OK) {
        fprintf(stderr, "Erro de conexão: %s\n", PQerrorMessage(conn));
        PQfinish(conn);
        return 1;
    }

    printf("Conectado ao banco com sucesso!\n");
	
	printf("informe o nome: ");
	scanf("%s",produto);
	printf("informe a quantidade: ");
	scanf("%d",&quantidade);
	printf("informe o valor: ");
	scanf("%lf",&preco);
	
	tamanho = snprintf(NULL, 0,"INSERT INTO estoque (produto, quantidade, preco_unitario) VALUES ('%s', %d, %.2lf);",produto, quantidade, preco);
	tamanho = (tamanho + 1); // +1 para o '\0'
	
	// Comando INSERT
    char *sql = malloc(tamanho * sizeof(char));
	
	sprintf(sql,"INSERT INTO estoque (produto, quantidade, preco_unitario) VALUES ('%s', %d, %2.lf);", produto, quantidade, preco); 
    res = PQexec(conn, sql);

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        fprintf(stderr, "Erro no INSERT: %s\n", PQerrorMessage(conn));
        PQclear(res);
        PQfinish(conn);
        return 1;
    }

    printf("Insercao realizada com sucesso!\n");
	free(sql);
    PQclear(res);
    PQfinish(conn);
    return 0;
}