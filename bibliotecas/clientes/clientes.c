#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "../fun_reutilizaveis/fun_reutilizaveis.h"
#include "../menu_principal/menu_principal.h"
#include "clientes.h"

typedef struct cliente Cliente;

void cadastrar_clientes(void){ // Função de cadastrar clientes
    system("clear||cls");

    printf("\t===================================\n");
    printf("\t|         Módulo de Cadastro      |\n");
    printf("\t===================================\n");

    Cliente cliente;

    printf("\n\tCPF:(APENAS NÚMEROS)>>> "); fgets(cliente.cpf, 100, stdin); fflush(stdin);
    loop_cpf(cliente.cpf);
    printf("\tNOME: "); fgets(cliente.nome, 100, stdin); fflush(stdin);
    loop_nome(cliente.nome);
    printf("\tE-MAIL: "); fgets(cliente.email, 200, stdin); fflush(stdin);
    loop_email(cliente.email);
    printf("\tTELEFONE:(APENAS NÚMEROS)>>> +55 "); fgets(cliente.fone, 100, stdin); fflush(stdin);
    loop_fone(cliente.fone);
    printf("\tDATA DE NASCIMENTO:(dd/mm/aaaa)>>> "); fgets(cliente.data_nas, 100, stdin); fflush(stdin);
    loop_de_validacao_data(cliente.data_nas);
    printf("\n\tPLANOS: \n\t1- BÁSICO: R$ 59,99\n\t2- MÉDIO: R$ 69,99\n\t3- PREMIUM: 79,99");
    printf("\n\t>>> SELECIONE UM PLANO: ");
    fgets(cliente.plano, 20, stdin); fflush(stdin);
    loop_valor_cliente(cliente.plano);

    exibe_cliente(&cliente);

    printf("\n\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void deletar_clientes(void){  // Função de deletar clientes
    system("clear||cls");

    printf("\t===================================\n");
    printf("\t|         Módulo de Exclusão      |\n");
    printf("\t===================================\n");

    char cpf[100];

    printf("\tINFORME O CPF: (APENAS NÚMEROS) >>> "); fgets(cpf, 100, stdin); fflush(stdin);
    loop_cpf(cpf);

    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");    
}

void recuperar_clientes(void){ // Função de recuperar Clientes
    system("clear||cls");

    printf("\t===================================\n");
    printf("\t|         Módulo de Recuperar     |\n");
    printf("\t===================================\n");

    char cpf[100];

    printf("\tINFORME O CPF: (APENAS NÚMEROS) >>> "); fgets(cpf, 100, stdin); fflush(stdin);
    loop_cpf(cpf);

    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void pesquisar_clientes(void){ // Função de pesquisar clientes
    system("clear||cls");

    printf("\t===================================\n");
    printf("\t|         Módulo de Pesquisar     |\n");
    printf("\t===================================\n");

    char cpf[100];

    printf("\tINFORME O CPF: (APENAS NÚMEROS) >>> "); fgets(cpf, 100, stdin); fflush(stdin);
    loop_cpf(cpf);

    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void atualizar_clientes(void){ // Função de atualizar clientes
    system("clear||cls");

    printf("\t===================================\n");
    printf("\t|       Módulo de Atualização     |\n");
    printf("\t===================================\n");

    char cpf[100];

    printf("\tINFORME O CPF: (APENAS NÚMEROS) >>> "); fgets(cpf, 100, stdin); fflush(stdin);
    loop_cpf(cpf);

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

void exibe_cliente(const Cliente* cliente){ // Função exibe o cliente cadastrado
    system("clear||cls");

    printf("\tCLIENTE CADASTRADO COM SUCESSO!\n");
    printf("\n\tCPF: %s", cliente->cpf);
    printf("\tNOME: %s", cliente->nome);
    printf("\tE-MAIL: %s", cliente->email);
    printf("\tTELEFONE: +55 %s", cliente->fone);
    printf("\tDATA DE NASCIMENTO: %s", cliente->data_nas);
    printf("\tPLANO: R$ %s", cliente->plano);
}