#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "../fun_reutilizaveis/fun_reutilizaveis.h"
#include "../menu_principal/menu_principal.h"
#include "funcionarios.h"

typedef struct funcionario Funcionario;

void cadastrar_funcionario(void){ // Função de cadastrar funcionários
    system("clear||cls");

    printf("\t===================================\n");
    printf("\t|         Módulo de Cadastro      |\n");
    printf("\t===================================\n");

    //char cpf[100], nome[100], email[200], fone[100], data_nas[100], salario[20];
    Funcionario funcionario;

    printf("\n\tCPF:(APENAS NÚMEROS)>>> "); fgets(funcionario.cpf, 100, stdin); fflush(stdin);
    loop_cpf(funcionario.cpf);
    printf("\tNOME: "); fgets(funcionario.nome, 100, stdin); fflush(stdin);
    loop_nome(funcionario.nome);
    printf("\tE-MAIL: "); fgets(funcionario.email, 200, stdin); fflush(stdin);
    loop_email(funcionario.email);
    printf("\tTELEFONE:(APENAS NÚMEROS)>>> +55 "); fgets(funcionario.fone, 100, stdin); fflush(stdin);
    loop_fone(funcionario.fone);
    printf("\tDATA DE NASCIMENTO:(dd/mm/aaaa)>>> "); 
    fgets(funcionario.data_nas, 100, stdin); fflush(stdin);
    loop_de_validacao_data(funcionario.data_nas);
    printf("\n\tSALÁRIOS: \n\t1- MEIO SALÁRIO: R$ 606,00\n\t2- UM SALÁRIO: R$ 1.212,00\n\t3- DOIS SALÁRIOS: R$ 2.424,00\n\t4- TRÊS SALÁRIOS: R$ 3.636,00");
    printf("\n\t>>> SELECIONE UM SALÁRIO: ");
    fgets(funcionario.salaraio, 20, stdin); fflush(stdin);
    loop_valor_funcionario(funcionario.salaraio);
    
    exibe_funcionario(&funcionario);

    printf("\n\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void deletar_funcionario(void){ // Função de deletar funcionários
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

void recuperar_funcionario(void){ // Função de recuperar funcionários
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

void pesquisar_funcionario(void){ // Função de pesquisar funcionários
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

void atualizar_funcionario(void){ // Função de atualizar funcionários
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

void listar_funcionario(void){ // Função de listar funcionários
    system("clear||cls");

    printf("\t===================================\n");
    printf("\t|         Módulo de Listagem      |\n");
    printf("\t===================================\n");
    printf("\t| FUNCIONÁRIO 1:                  |\n");
    printf("\t| CPF: -------                    |\n");
    printf("\t| NOME COMPLETO: --------         |\n");
    printf("\t| E-MAIL: ---------               |\n");
    printf("\t| TELEFONE:--------               |\n");
    printf("\t| DATA DE NASCIMENTO: --------    |\n");
    printf("\t|                                 |\n");
    printf("\t| FUNCIONÁRIO 2:                  |\n");
    printf("\t|              .                  |\n");
    printf("\t|              .                  |\n");
    printf("\t|              .                  |\n");
    printf("\t===================================\n");
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void exibe_funcionario(const Funcionario* funcionario){// Função exibe o funcionário cadastrado
    system("clear||cls");

    printf("\tFUNCIONÁRIO CADASTRADO COM SUCESSO!\n");
    printf("\n\tCPF: %s", funcionario->cpf);
    printf("\tNOME: %s", funcionario->nome);
    printf("\tE-MAIL: %s", funcionario->email);
    printf("\tTELEFONE: +55 %s", funcionario->fone);
    printf("\tDATA DE NASCIMENTO: %s", funcionario->data_nas);
    printf("\tSALÁRIO: R$ %s", funcionario->salaraio);
}