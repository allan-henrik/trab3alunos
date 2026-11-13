#include <stdio.h>
#include <sqlite3.h>

int main() {

    sqlite3 *db;
    char *erro = NULL;

    sqlite3_open("banco.db", &db);

    char *sql =
        "CREATE TABLE IF NOT EXISTS alunosMatricula ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "primeironome TEXT NOT NULL,"
        "segundonome TEXT NOT NULL,"
        "sexo TEXT NOT NULL,"
        "telefone INTEGER NOT NULL,"
        "endereco TEXT NOT NULL"
        ");";

    int resultado = sqlite3_exec(
        db,
        sql,
        NULL,
        NULL,
        &erro
    );

    if (resultado != SQLITE_OK) {
        printf("Erro: %s\n", erro);
        sqlite3_free(erro);
    } else {
        printf("Tabela criada com sucesso!\n");
    }

    sqlite3_close(db);

    return 0;
}
