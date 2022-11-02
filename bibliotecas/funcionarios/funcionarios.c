#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "../fun_reutilizaveis/fun_reutilizaveis.h"
#include "../menu_principal/menu_principal.h"
#include "funcionarios.h"

typedef struct funcionario Funcionario;
char arquivo_funcionario[] = {"arq_funcionario.dat"};

void cadastrar_funcionario(void){ // Função de cadastrar funcionários
    system("clear||cls");

    printf("\t===================================\n");
    printf("\t|         Módulo de Cadastro      |\n");
    printf("\t===================================\n");

    Funcionario *funcionario;

    funcionario = preenche_funcionario();
    salvar_no_arq_func(funcionario,arquivo_funcionario);
    exibe_funcionario(funcionario);
    free(funcionario);

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

    ler_arquivo_func(arquivo_funcionario);

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

Funcionario* preenche_funcionario(void){
    Funcionario *funcionario;
    funcionario = (Funcionario*) malloc(sizeof(Funcionario));
    printf("\n\tCPF:(APENAS NÚMEROS)>>> "); fgets(funcionario->cpf, 100, stdin); fflush(stdin);
    loop_cpf(funcionario->cpf);
    verifica_pessoa1(arquivo_funcionario, funcionario->cpf);
    printf("\tNOME: "); fgets(funcionario->nome, 100, stdin); fflush(stdin);
    loop_nome(funcionario->nome);
    printf("\tE-MAIL: "); fgets(funcionario->email, 200, stdin); fflush(stdin);
    loop_email(funcionario->email);
    printf("\tTELEFONE:(APENAS NÚMEROS)>>> +55 "); fgets(funcionario->fone, 100, stdin); fflush(stdin);
    loop_fone(funcionario->fone);
    printf("\tDATA DE NASCIMENTO:(dd/mm/aaaa)>>> "); 
    fgets(funcionario->data_nas, 100, stdin); fflush(stdin);
    loop_de_validacao_data(funcionario->data_nas);
    printf("\n\tSALÁRIOS: \n\t1- MEIO SALÁRIO: R$ 606,00\n\t2- UM SALÁRIO: R$ 1.212,00\n\t3- DOIS SALÁRIOS: R$ 2.424,00\n\t4- TRÊS SALÁRIOS: R$ 3.636,00");
    printf("\n\t>>> SELECIONE UM SALÁRIO: ");
    fgets(funcionario->salaraio, 20, stdin); fflush(stdin);
    loop_valor_funcionario(funcionario->salaraio);
    funcionario->status = 'v';
    return funcionario;
}

void salvar_no_arq_func(const Funcionario *funcionario, char *arquivo){
    FILE *arq;
    arq = fopen(arquivo, "ab");
    if (arq == NULL){
        printf("ERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    fwrite(funcionario, sizeof(Funcionario), 1, arq);
    fclose(arq);
}

void ler_arquivo_func(char *arquivo){
    FILE *arq;
    arq = fopen(arquivo, "rb");
    if (arq == NULL){
        printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    Funcionario *funcionario;
    funcionario = (Funcionario*) malloc(sizeof(Funcionario));
    int cont = 0;
    while(!feof(arq)){
        if(fread(funcionario, sizeof(Funcionario),1,arq)){
            printf("\n\tFUNCIONÁRIO %d:\n",cont+1);
            printf("\n\tCPF: %s", funcionario->cpf);
            printf("\tNOME: %s", funcionario->nome);
            printf("\tE-MAIL: %s", funcionario->email);
            printf("\tTELEFONE: +55 %s", funcionario->fone);
            printf("\tDATA DE NASCIMENTO: %s", funcionario->data_nas);
            printf("\tSALÁRIO: R$ %s", funcionario->salaraio);
            printf("\n\t===================================\n");
            cont+=1;
        }
    }
    if(cont == 0){
        printf("\n\tNÃO EXISTE NENHUM FUNCIONÁRIO CADASTRADO NO SISTEMA!\n");
    }
    fclose(arq);
}