#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void registrar_frequencia(void){ // Função de registrar acesso
    system("clear||cls");

    printf("\t======================================\n");
    printf("\t|     Módulo de Registrar Acesso     |\n");
    printf("\t======================================\n");

    char cpf[30];

    printf("\n\tINFORME O CPF: (APENAS NÚMEROS) >>> "); fgets(cpf, 30, stdin); fflush(stdin);

    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void listar_frequencia(void){ // Função de listar frequência
    system("clear||cls");

    printf("\t=======================================\n");
    printf("\t|       Módulo de Listar Acessos      |\n");
    printf("\t=======================================\n");
    printf("\t| ------------------------------      |\n");
    printf("\t| NOME DO CLIENTE: ----------         |\n");
    printf("\t| DATA DE ACESSO: ----------          |\n");
    printf("\t| ------------------------------      |\n");
    printf("\t|                 .                   |\n");
    printf("\t|                 .                   |\n");
    printf("\t|                 .                   |\n");
    printf("\t=======================================\n");
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}