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


    // Exibe o resultado da consulta
	for(int i = 0; i < 2;i++)
	{
		for(int y = 0; y < 4;y++)
		{
			printf("DADOS: %s\n", PQgetvalue(res, i, y));
		}
	}
	
    // Libera os resultados e encerra
    PQclear(res);
    PQfinish(conn);
    return 0;
}