#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

int main() {
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

    // Executa uma consulta simples
    PGresult *res = PQexec(conn, "SELECT * FROM estoque;");

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        fprintf(stderr, "Erro na consulta: %s\n", PQerrorMessage(conn));
        PQclear(res);
        PQfinish(conn);
        return 1;
    }

    // Obtém o número de linhas e colunas
    int linhas = PQntuples(res);
    int colunas = PQnfields(res);

    printf("Total de linhas: %d\n", linhas);
    printf("Total de colunas: %d\n\n", colunas);

    // Imprime o nome das colunas
    for (int j = 0; j < colunas; j++) {
        printf("%-20s", PQfname(res, j));
    }
    printf("\n------------------------------------------------------------\n");

    // Percorre dinamicamente todas as linhas e colunas
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%-20s", PQgetvalue(res, i, j));
        }
        printf("\n");
    }

    // Libera os resultados e encerra
    PQclear(res);
    PQfinish(conn);
    return 0;
}