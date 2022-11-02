#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "../fun_reutilizaveis/fun_reutilizaveis.h"
#include "../menu_principal/menu_principal.h"
#include "clientes.h"

typedef struct cliente Cliente;
char arquivo_cliente[] = {"arq_cliente.dat"};

void cadastrar_clientes(void){ // Função de cadastrar clientes
    system("clear||cls");

    printf("\t===================================\n");
    printf("\t|         Módulo de Cadastro      |\n");
    printf("\t===================================\n");

    Cliente *cliente;

    cliente = preenche_cliente();

    salvar_no_arq_cliente(cliente, arquivo_cliente);
    exibe_cliente(cliente);
    free(cliente);

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

    ler_arquivo_cliente(arquivo_cliente);

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

void salvar_no_arq_cliente(const Cliente *cliente, char *arquivo){
    FILE *arq;
    arq = fopen(arquivo, "ab");
    if (arq == NULL){
        printf("ERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    fwrite(cliente, sizeof(Cliente), 1, arq);
    fclose(arq);
}

Cliente* preenche_cliente(void){
    Cliente *cliente;
    cliente = (Cliente*) malloc(sizeof(Cliente));
    printf("\n\tCPF:(APENAS NÚMEROS)>>> "); fgets(cliente->cpf, 100, stdin); fflush(stdin);
    loop_cpf(cliente->cpf);
    verifica_pessoa1(arquivo_cliente, cliente->cpf);
    printf("\tNOME: "); fgets(cliente->nome, 100, stdin); fflush(stdin);
    loop_nome(cliente->nome);
    printf("\tE-MAIL: "); fgets(cliente->email, 200, stdin); fflush(stdin);
    loop_email(cliente->email);
    printf("\tTELEFONE:(APENAS NÚMEROS)>>> +55 "); fgets(cliente->fone, 100, stdin); fflush(stdin);
    loop_fone(cliente->fone);
    printf("\tDATA DE NASCIMENTO:(dd/mm/aaaa)>>> "); fgets(cliente->data_nas, 100, stdin); fflush(stdin);
    loop_de_validacao_data(cliente->data_nas);
    printf("\n\tPLANOS: \n\t1- BÁSICO: R$ 59,99\n\t2- MÉDIO: R$ 69,99\n\t3- PREMIUM: 79,99");
    printf("\n\t>>> SELECIONE UM PLANO: ");
    fgets(cliente->plano, 20, stdin); fflush(stdin);
    loop_valor_cliente(cliente->plano);
    cliente->status = 'v';
    return cliente;
}

void ler_arquivo_cliente(char *arquivo){
    FILE *arq;
    arq = fopen(arquivo, "rb");
    if (arq == NULL){
        printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    Cliente *cliente;
    cliente = (Cliente*) malloc(sizeof(Cliente));
    int cont = 0;
    while(!feof(arq)){
        if(fread(cliente, sizeof(Cliente),1,arq)){
            printf("\n\tCLIENTE %d:\n",cont+1);
            printf("\n\tCPF: %s", cliente->cpf);
            printf("\tNOME: %s", cliente->nome);
            printf("\tE-MAIL: %s", cliente->email);
            printf("\tTELEFONE: +55 %s", cliente->fone);
            printf("\tDATA DE NASCIMENTO: %s", cliente->data_nas);
            printf("\tPLANO: R$ %s", cliente->plano);
            printf("\n\t===================================\n");
            cont+=1;
        }
    }
    if(cont == 0){
        printf("\n\tNÃO EXISTE NENHUM CLIENTE CADASTRADO NO SISTEMA!\n");
    }
    fclose(arq);
}