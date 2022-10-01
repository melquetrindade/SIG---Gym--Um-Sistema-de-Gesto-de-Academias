#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void registrar_mensalidade(void){ // Função de Registrar Mensalidades
    system("clear||cls");

    printf("\t=======================================\n");
    printf("\t|   Módulo de Registrar Mensalidades  |\n");
    printf("\t=======================================\n");
    printf("\t| INFORME O CPF:                      |\n");
    printf("\t| VALOR DA MENSALIDADE:               |\n");
    printf("\t=======================================\n");
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void listar_mensalidade(void){ // Função de listar as mensalidades
    system("clear||cls");

    printf("\t=======================================\n");
    printf("\t|     Módulo de Listar Mensalidades   |\n");
    printf("\t=======================================\n");
    printf("\t| MENSALIDADE 1:                      |\n");
    printf("\t| NOME DO CLIENTE: ----------         |\n");
    printf("\t| ÚLTIMO PAGAMENTO REALIZADO: ------  |\n");
    printf("\t|                                     |\n");
    printf("\t| MESALIDADE 2:                       |\n");
    printf("\t|                 .                   |\n");
    printf("\t|                 .                   |\n");
    printf("\t=======================================\n");
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void pesquisar_mensalidade(void){ // Função de pesquisar mensalidades
    system("clear||cls");

    printf("\t======================================\n");
    printf("\t|  Módulo de Pesquisar Mensalidades  |\n");
    printf("\t======================================\n");
    printf("\t| INFORME O CPF: (APENAS NÚMEROS)    |\n");
    printf("\t======================================\n");
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void deletar_mensalidades(void){ // Função de deletar mensalidades
    system("clear||cls");

    printf("\t======================================\n");
    printf("\t|   Módulo de Deletar Mensalidades   |\n");
    printf("\t======================================\n");
    printf("\t| INFORME O CPF: (APENAS NÚMEROS)    |\n");
    printf("\t======================================\n");
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void mensalidades_pendentes(void){ // Função de listar apenas as mensalidades atrasadas
    system("clear||cls");

    printf("\t=======================================\n");
    printf("\t|   Módulo de Mensalidades Pendentes  |\n");
    printf("\t=======================================\n");
    printf("\t| MENSALIDADE 1:                      |\n");
    printf("\t| NOME DO CLIENTE: ----------         |\n");
    printf("\t| ÚLTIMO PAGAMENTO REALIZADO: ------  |\n");
    printf("\t|                                     |\n");
    printf("\t| MESALIDADE 2:                       |\n");
    printf("\t|                 .                   |\n");
    printf("\t|                 .                   |\n");
    printf("\t=======================================\n");
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}