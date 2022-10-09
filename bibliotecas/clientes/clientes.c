#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void cadastrar_clientes(void){ // Função de cadastrar clientes
    system("clear||cls");

    printf("\t===================================\n");
    printf("\t|         Módulo de Cadastro      |\n");
    printf("\t===================================\n");

    char cpf[30], nome[100], email[100], fone[30], data_nas[30];

    printf("\n\tCPF:(APENAS NÚMEROS)>>> "); fgets(cpf, 30, stdin); fflush(stdin);
    printf("\tNOME: "); fgets(nome, 100, stdin); fflush(stdin);
    printf("\tE-MAIL: "); fgets(email, 100, stdin); fflush(stdin);
    printf("\tTELEFONE:(APENAS NÚMEROS)>>> "); fgets(fone, 30, stdin); fflush(stdin);
    printf("\tDATA DE NASCIMENTO:(dd/mm/aaaa)>>> "); fgets(data_nas, 30, stdin); fflush(stdin);

    system("clear||cls");

    printf("\tCLIENTE CADASTRADO COM SUCESSO!\n");
    printf("\n\tCPF: %s", cpf);
    printf("\tNOME: %s", nome);
    printf("\tE-MAIL: %s", email);
    printf("\tTELEFONE: %s", fone);
    printf("\tDATA DE NASCIMENTO: %s", data_nas);
    
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void deletar_clientes(void){  // Função de deletar clientes
    system("clear||cls");

    printf("\t===================================\n");
    printf("\t|         Módulo de Exclusão      |\n");
    printf("\t===================================\n");

    char cpf[30];

    printf("\tINFORME O CPF: (APENAS NÚMEROS) >>> "); fgets(cpf, 30, stdin); fflush(stdin);

    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");    
}

void recuperar_clientes(void){ // Função de recuperar Clientes
    system("clear||cls");

    printf("\t===================================\n");
    printf("\t|         Módulo de Recuperar     |\n");
    printf("\t===================================\n");

    char cpf[30];

    printf("\tINFORME O CPF: (APENAS NÚMEROS) >>> "); fgets(cpf, 30, stdin); fflush(stdin);

    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void pesquisar_clientes(void){ // Função de pesquisar clientes
    system("clear||cls");

    printf("\t===================================\n");
    printf("\t|         Módulo de Pesquisar     |\n");
    printf("\t===================================\n");

    char cpf[30];

    printf("\tINFORME O CPF: (APENAS NÚMEROS) >>> "); fgets(cpf, 30, stdin); fflush(stdin);

    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void atualizar_clientes(void){ // Função de atualizar clientes
    system("clear||cls");

    printf("\t===================================\n");
    printf("\t|       Módulo de Atualização     |\n");
    printf("\t===================================\n");

    char cpf[30];

    printf("\tINFORME O CPF: (APENAS NÚMEROS) >>> "); fgets(cpf, 30, stdin); fflush(stdin);

    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void listar_clientes(void){ // Função de listar clientes
    system("clear||cls");

    printf("\t===================================\n");
    printf("\t|         Módulo de Listagem      |\n");
    printf("\t===================================\n");
    printf("\t| CLIENTE 1:                      |\n");
    printf("\t| CPF: -------                    |\n");
    printf("\t| NOME COMPLETO: --------         |\n");
    printf("\t| E-MAIL: ---------               |\n");
    printf("\t| TELEFONE:--------               |\n");
    printf("\t| DATA DE NASCIMENTO: --------    |\n");
    printf("\t|                                 |\n");
    printf("\t| CLIENTE 2:                      |\n");
    printf("\t|              .                  |\n");
    printf("\t|              .                  |\n");
    printf("\t|              .                  |\n");
    printf("\t===================================\n");
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}