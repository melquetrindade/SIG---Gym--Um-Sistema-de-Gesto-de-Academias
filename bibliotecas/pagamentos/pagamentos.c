#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void realizar_pagamentos(void){ // Função de realizar Pagamentos dos Funcionários
    system("clear||cls");

    printf("\t=======================================\n");
    printf("\t|     Módulo de Realizar Pagamentos   |\n");
    printf("\t=======================================\n");
    printf("\t| INFORME O CPF:                      |\n");
    printf("\t| VALOR DO SALÁRIO:                   |\n");
    printf("\t=======================================\n");
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void listar_pagamentos(void){ // Função de Listar os pagamentos dos funcionários
    system("clear||cls");

    printf("\t=======================================\n");
    printf("\t|     Módulo de Listar Pagamentos     |\n");
    printf("\t=======================================\n");
    printf("\t| SALÁRIO 1:                          |\n");
    printf("\t| NOME DO FUNCIONÁRIO: ----------     |\n");
    printf("\t| ÚLTIMO PAGAMENTO REALIZADO: ------  |\n");
    printf("\t|                                     |\n");
    printf("\t| SALÁRIO 2:                          |\n");
    printf("\t|                 .                   |\n");
    printf("\t|                 .                   |\n");
    printf("\t=======================================\n");
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void pesquisar_pagamentos(void){ // Função de Pesquisar por pagamentos
    system("clear||cls");

    printf("\t======================================\n");
    printf("\t|   Módulo de Pesquisar Pagamentos   |\n");
    printf("\t======================================\n");
    printf("\t| INFORME O CPF: (APENAS NÚMEROS)    |\n");
    printf("\t======================================\n");
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void deletar_pagamentos(void){ // Função de deletar pagamentos 
    system("clear||cls");

    printf("\t======================================\n");
    printf("\t|    Módulo de Deletar Pagamentos    |\n");
    printf("\t======================================\n");
    printf("\t| INFORME O CPF: (APENAS NÚMEROS)    |\n");
    printf("\t======================================\n");
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void pagamentos_pendentes(void){ // Função de listar apenas os salários atrasados
    system("clear||cls");

    printf("\t=======================================\n");
    printf("\t|    Módulo de Pagamentos Pendentes   |\n");
    printf("\t=======================================\n");
    printf("\t| SALÁRIO 1:                          |\n");
    printf("\t| NOME DO CLIENTE: ----------         |\n");
    printf("\t| ÚLTIMO PAGAMENTO REALIZADO: ------  |\n");
    printf("\t|                                     |\n");
    printf("\t| SALÁRIO 2:                          |\n");
    printf("\t|                 .                   |\n");
    printf("\t|                 .                   |\n");
    printf("\t=======================================\n");
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}