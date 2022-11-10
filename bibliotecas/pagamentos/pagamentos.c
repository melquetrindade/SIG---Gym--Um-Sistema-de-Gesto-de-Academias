#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "../fun_reutilizaveis/fun_reutilizaveis.h"
#include "../menu_principal/menu_principal.h"
#include "pagamentos.h"
#include "../funcionarios/funcionarios.h"

typedef struct salario Salario;

char arq_salario[] = {"arq_salario.dat"};
char arq_funcionario[] = {"arq_funcionario.dat"};

void realizar_pagamentos(void){ // Função de realizar Pagamentos dos Funcionários
    system("clear||cls");
    Salario *salario;
    printf("\t========================================\n");
    printf("\t|      Módulo de Registrar Salário     |\n");
    printf("\t========================================\n");
    char cpf[100];
    printf("\n\tINFORME O CPF: (APENAS NÚMEROS) >>> "); fgets(cpf, 100, stdin); fflush(stdin);
    loop_cpf(cpf);
    salario = busca_salario(arq_salario,cpf);
    if(salario == NULL){
        Funcionario *funcionario;
        funcionario = busca_funcionario(arq_funcionario, cpf);
        if(funcionario == NULL){
            printf("\n\tERRO, NÃO EXISTE NENHUM FUNCIONÁRIO CADASTRADO NO SISTEMA COM ESTE CPF!");
        }
        else{
            Salario *salario1;
            salario1 = preenche_salario(funcionario->cpf,funcionario->nome, funcionario->salaraio);
            printf("\n\tEFETUAMENTO DO PRIMEIRO SALÁRIO!");
            printf("\n\n\tPRESIONE <ENTER> PARA CONFIRMAR O PARAGAMENTO >>> ");
            getchar();
            printf("\n\tSALÁRIO PAGO COM SUCESSO!");
            salvar_no_arq_salario(salario1, arq_salario);
            free(salario1);
        }
        free(salario);
    }
    else{
        int atraso = cal_atraso(salario->data_pg[2], salario->data_pg[1], salario->data_pg[0]);
        if(atraso == 1){
            int dif_mes = 0;
            cal_atraso_etp2(salario->data_pg[2], salario->data_pg[1], salario->data_pg[0], &dif_mes);
            printf("\n\tSALÁRIO EM ATRASO! TOTAL DE MESES EM ATRASO: %d", dif_mes);
            printf("\n\n\tPRESIONE <ENTER> PARA CONFIRMAR O PARAGAMENTO DE: %d/%d/%d >>> ",salario->prox_data[0],salario->prox_data[1], salario->prox_data[2]);
            getchar();
            confirma_salario(arq_salario,salario);
            printf("\n\tMENSALIDADE REALIZADA COM SUCESSO!");
        }
        else{
            printf("\n\tNÃO HÁ SALÁRIOS PENDENTES PARA ESTE FUNCIONÁRIO!");
            printf("\n\tPRÓXIMO PAGAMENTO: %d/%d/%d", salario->prox_data[0],salario->prox_data[1],salario->prox_data[2]);
        }
    }
    free(salario);
    printf("\n\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void listar_pagamentos(void){ // Função de Listar os pagamentos dos funcionários
    system("clear||cls");
    char status = 'v';

    printf("\t=======================================\n");
    printf("\t|     Módulo de Listar Pagamentos     |\n");
    printf("\t=======================================\n");

    ler_arquivo_salario(arq_salario,status);

    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void pesquisar_pagamentos(void){ // Função de Pesquisar por pagamentos
    system("clear||cls");
    Salario *salario;

    printf("\t======================================\n");
    printf("\t|   Módulo de Pesquisar Pagamentos   |\n");
    printf("\t======================================\n");

    char cpf[100];

    printf("\n\tINFORME O CPF: (APENAS NÚMEROS) >>> "); fgets(cpf, 100, stdin); fflush(stdin);
    loop_cpf(cpf);
    salario = pesquisa_salario(arq_salario, cpf);
    if(salario == NULL){
        printf("\n\tNÃO EXISTE NENHUM SALÁRIO CADASTRADO COM ESTE CPF NO SISTEMA!");
    }
    else{
        exibe_salario(salario);
    }
    free(salario);

    printf("\n\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void pagamentos_pendentes(void){ // Função de listar apenas os salários atrasados
    system("clear||cls");
    char status = 'x';

    printf("\t=======================================\n");
    printf("\t|    Módulo de Pagamentos Pendentes   |\n");
    printf("\t=======================================\n");

    ler_arquivo_salario(arq_salario,status);

    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

// Função que verifica se já existe algum salário ativo correspondente ao cpf informado
Salario* busca_salario(char *arquivo, char *cpf_busca){
    FILE *arq;
    int abriu = 1;
    arq = fopen(arquivo, "rb");
    if(arq == NULL){
        abriu = 0;
    }
    if(abriu == 1){
        Salario *salario;
        salario = (Salario*) malloc(sizeof(Salario));
        while(!feof(arq)){
            if(fread(salario, sizeof(Salario), 1, arq)){
                if((strcmp(salario->cpf, cpf_busca) == 0) && (salario->status == 'v')){
                    fclose(arq);
                    return salario;
                }
            }
        }
        fclose(arq);
        return NULL;
    }
    return NULL;
}

// Função que preenche o salário
Salario* preenche_salario(char *cpf, char*nome, char *plano){
    Salario *salario;
    salario = (Salario*) malloc(sizeof(Salario));
    strcpy(salario->cpf,cpf);
    strcpy(salario->nome,nome);
    strcpy(salario->salario,plano);
    pegaData(salario->data_pg);
    cal_prox_pagamento(salario->data_pg[2],salario->data_pg[1], salario->data_pg[0], salario->prox_data);
    salario->status = 'v';
    return salario;
}

// Função que salva em arquivo salário
void salvar_no_arq_salario(const Salario *salario, char *arquivo){
    FILE *arq;
    arq = fopen(arquivo, "ab");
    if (arq == NULL){
        printf("ERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    fwrite(salario, sizeof(Salario), 1, arq);
    fclose(arq);
}

// Função que realiza o pagamento do salário
void confirma_salario(char *arquivo, Salario *salario_novo){
    Salario *salario_teste;
    FILE *arq;
    arq = fopen(arquivo, "r+b");
    if (arq == NULL) {
        printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    salario_teste = (Salario*) malloc(sizeof(Salario));
    int achou = 0;
    while((!feof(arq)) && (achou == 0)){
        fread(salario_teste, sizeof(Salario), 1, arq);
        if((strcmp(salario_teste->cpf, salario_novo->cpf) == 0) && (salario_teste->status != 'x')) {
            achou = 1;
            strcpy(salario_teste->cpf,salario_novo->cpf);
            strcpy(salario_teste->nome,salario_novo->nome);
            strcpy(salario_teste->salario,salario_novo->salario);
            salario_teste->data_pg[0] = salario_novo->prox_data[2];
            salario_teste->data_pg[1] = salario_novo->prox_data[1];
            salario_teste->data_pg[2] = salario_novo->prox_data[0];
            cal_prox_pagamento(salario_teste->data_pg[2],salario_teste->data_pg[1], salario_teste->data_pg[0],salario_teste->prox_data);
            salario_teste->status = 'v';
            fseek(arq, -1*sizeof(Salario), SEEK_CUR);
            fwrite(salario_teste, sizeof(Salario), 1, arq);
        }
    }
    fclose(arq);
    free(salario_teste);
}

// Função que faz a leitura do arquivo de salário
void ler_arquivo_salario(char *arquivo, char statu){
    FILE *arq;
    arq = fopen(arquivo, "rb");
    if (arq == NULL){
        printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    Salario *salario1;
    salario1 = (Salario*) malloc(sizeof(Salario));
    int cont = 0;
    while(!feof(arq)){
        if(fread(salario1, sizeof(Salario),1,arq)){
            if(salario1->status == statu){
                printf("\n\tSALÁRIO %d:\n",cont+1);
                printf("\n\tCPF: %s", salario1->cpf);
                printf("\tNOME: %s", salario1->nome);
                printf("\tPLANO: R$ %s", salario1->salario);
                printf("\n\tÚLTIMO SALÁRIO PAGO: %d/%d/%d", salario1->data_pg[2],salario1->data_pg[1],salario1->data_pg[0]);
                printf("\n\tPRÓXIMO PAGAMENTO: %d/%d/%d", salario1->prox_data[0], salario1->prox_data[1], salario1->prox_data[2]);
                printf("\n\t===================================\n");
                cont+=1;
            }
        }
    }
    if(cont == 0){
        if(statu == 'v'){
            printf("\n\tNÃO EXISTE NENHUM SALÁRIO NO SISTEMA!\n");
        }
        else{
            printf("\n\tNÃO EXISTE NENHUM SALÁRIO ATRASADO NO SISTEMA!\n");
        }
    }
    fclose(arq);
    free(salario1);
}

// Função que pesquisa por um salário específico 
Salario* pesquisa_salario(char *arquivo, char *cpf_busca){
    FILE *arq;
    Salario *salario;
    arq = fopen(arquivo, "rb");
    if(arq == NULL){
        printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    salario = (Salario*) malloc(sizeof(Salario));
    while(!feof(arq)){
        if(fread(salario, sizeof(Salario), 1, arq)){
            if((strcmp(salario->cpf, cpf_busca) == 0) && (salario->status == 'v')){
                fclose(arq);
                return salario;
            }
        }
    }
    fclose(arq);
    return NULL;
}

// Função que exibe o salário
void exibe_salario(const Salario* salario){ // Função exibe o cliente cadastrado
    printf("\n\tCPF: %s", salario->cpf);
    printf("\tNOME: %s", salario->nome);
    printf("\tPLANO: %s", salario->salario);
    printf("\n\tÚLTIMO SALÁRIO PAGO: %d/%d/%d", salario->data_pg[2],salario->data_pg[1],salario->data_pg[0]);
    printf("\n\tPRÓXIMO PAGAMENTO: %d/%d/%d", salario->prox_data[0],salario->prox_data[1],salario->prox_data[2]);
}

// Função que recupe o salário
void recupera_salario(char *arquivo, char *cpf, int*data){
    FILE *arq_salario;
    Salario *salario_busca;
    arq_salario = fopen(arquivo, "r+b");
    if(arq_salario == NULL){
        printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    salario_busca = (Salario*) malloc(sizeof(Salario));
    int achou = 0;
    while((!feof(arq_salario) && (achou == 0))){
        fread(salario_busca, sizeof(Salario), 1, arq_salario);
        if((strcmp(salario_busca->cpf,cpf) == 0) && (salario_busca->status == 'x') && (salario_busca->data_pg[0]=data[0]) && (salario_busca->data_pg[1]=data[1]) && (salario_busca->data_pg[2]=data[2]) && (salario_busca->data_pg[3]=data[3]) && (salario_busca->data_pg[4]=data[4]) && (salario_busca->data_pg[5]=data[5])){
            achou = 1;
            salario_busca->status = 'v';
            fseek(arq_salario, -1*sizeof(Salario), SEEK_CUR);
            fwrite(salario_busca, sizeof(Salario), 1, arq_salario);
        }
    }
    fclose(arq_salario);
    free(salario_busca);
}

// Função que atualiza salário
void atualiza_salario(char *arq_salario, char *func_cpf, char *func_nome, char *func_salario){
    FILE *arq_sal;
    arq_sal = fopen(arq_salario, "r+b");
    if(arq_sal==NULL){
        printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    int achou = 0;
    Salario *salario;
    salario = (Salario*) malloc(sizeof(Salario));
    while(!feof(arq_sal) && (achou == 0)){
        fread(salario, sizeof(Salario), 1, arq_sal);
        if((strcmp(salario->cpf,func_cpf) == 0) && salario->status != 'x'){
            achou = 1;
            strcpy(salario->nome,func_nome);
            strcpy(salario->salario,func_salario);
            fseek(arq_sal, -1*sizeof(Salario), SEEK_CUR);
            fwrite(salario, sizeof(Salario), 1, arq_sal);
        }
    }
    fclose(arq_sal);
    free(salario);
}