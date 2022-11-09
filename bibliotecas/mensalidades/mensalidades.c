#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "../fun_reutilizaveis/fun_reutilizaveis.h"
#include "../menu_principal/menu_principal.h"
#include "mensalidades.h"
#include "../clientes/clientes.h"

typedef struct mensalidade Mensalidade;

char arq_mensalidade[] = {"arq_mensalidade.dat"};
char arq_cliente[] = {"arq_cliente.dat"};

void registrar_mensalidade(void){ // Função de Registrar Mensalidades
    system("clear||cls");
    Mensalidade *mensalidade;

    printf("\t=======================================\n");
    printf("\t|   Módulo de Registrar Mensalidades  |\n");
    printf("\t=======================================\n");

    char cpf[100];

    printf("\n\tINFORME O CPF: (APENAS NÚMEROS) >>> "); fgets(cpf, 100, stdin); fflush(stdin);
    loop_cpf(cpf);
    mensalidade = busca_mensalidade(arq_mensalidade,cpf);
    if(mensalidade == NULL){
        Cliente *cliente;
        cliente = busca_cliente(arq_cliente, cpf);
        if(cliente == NULL){
            printf("\n\tERRO, NÃO EXISTE NENHUM CLIENTE CADASTRADO NO SISTEMA COM ESTE CPF!");
        }
        else{
            Mensalidade *mensalidade1;
            mensalidade1 = preenche_mensalidade(cliente->cpf,cliente->nome, cliente->plano);
            printf("\n\tEFETUAMENTO DA PRIMEIRA MENSALIDADE!");
            printf("\n\n\tPRESIONE <ENTER> PARA CONFIRMAR O PARAGAMENTO >>> ");
            getchar();
            printf("\n\tMENSALIDADE REALIZADA COM SUCESSO!");
            salvar_no_arq_mensalidade(mensalidade1, arq_mensalidade);
            free(mensalidade1);
        }
        free(cliente);
    }
    else{
        int atraso = cal_atraso(mensalidade->data_pg[2], mensalidade->data_pg[1], mensalidade->data_pg[0]);
        if(atraso == 1){
            int dif_mes = 0;
            cal_atraso_etp2(mensalidade->data_pg[2], mensalidade->data_pg[1], mensalidade->data_pg[0], &dif_mes);
            printf("\n\tCLIENTE EM ATRASO! TOTAL DE MESES EM ATRASO: %d", dif_mes);
            printf("\n\n\tPRESIONE <ENTER> PARA CONFIRMAR O PARAGAMENTO DE: %d/%d/%d >>> ",mensalidade->prox_data[0],mensalidade->prox_data[1], mensalidade->prox_data[2]);
            getchar();
            confirma_pagamento(arq_mensalidade,mensalidade);
            printf("\n\tMENSALIDADE REALIZADA COM SUCESSO!");
        }
        else{
            printf("\n\tNÃO HÁ MENSALIDADES PENDENTES PARA ESTE CLIENTE!");
            printf("\n\tPRÓXIMO PAGAMENTO: %d/%d/%d", mensalidade->prox_data[0],mensalidade->prox_data[1],mensalidade->prox_data[2]);
        }
    }
    free(mensalidade);

    printf("\n\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void listar_mensalidade(void){ // Função de listar as mensalidades
    system("clear||cls");
    char status = 'v';

    printf("\t=======================================\n");
    printf("\t|     Módulo de Listar Mensalidades   |\n");
    printf("\t=======================================\n");

    ler_arquivo_mensalidade(arq_mensalidade,status);

    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void pesquisar_mensalidade(void){ // Função de pesquisar mensalidades
    system("clear||cls");
    Mensalidade *mensalidade;

    printf("\t======================================\n");
    printf("\t|  Módulo de Pesquisar Mensalidades  |\n");
    printf("\t======================================\n");

    char cpf[100];

    printf("\n\tINFORME O CPF: (APENAS NÚMEROS) >>> "); fgets(cpf, 100, stdin); fflush(stdin);
    loop_cpf(cpf);
    mensalidade = pesquisa_mensalidade(arq_mensalidade, cpf);
    if(mensalidade == NULL){
        printf("\n\tNÃO EXISTE NENHUMA MENSALIDADE CADASTRADO COM ESTE CPF NO SISTEMA!");
    }
    else{
        exibe_mensalidade(mensalidade);
    }
    free(mensalidade);

    printf("\n\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void deletar_mensalidades(void){ // Função de deletar mensalidades
    system("clear||cls");
    Mensalidade *mensalidade;

    printf("\t======================================\n");
    printf("\t|   Módulo de Deletar Mensalidades   |\n");
    printf("\t======================================\n");

    char cpf[100];

    printf("\n\tINFORME O CPF: (APENAS NÚMEROS) >>> "); fgets(cpf, 100, stdin); fflush(stdin);
    loop_cpf(cpf);
    mensalidade = pesquisa_mensalidade(arq_mensalidade, cpf);
    if(mensalidade == NULL){
        printf("\n\tNÃO EXISTE NENHUMA MENSALIDADE CADASTRADO COM ESTE CPF NO SISTEMA!");
    }
    else{
        deleta_mensalidade(arq_mensalidade, mensalidade);
    }
    free(mensalidade);

    printf("\n\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void mensalidades_pendentes(void){ // Função de listar apenas as mensalidades atrasadas
    system("clear||cls");
    char status = 'x';

    printf("\t=======================================\n");
    printf("\t|   Módulo de Mensalidades Pendentes  |\n");
    printf("\t=======================================\n");

    ler_arquivo_mensalidade(arq_mensalidade,status);

    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

Mensalidade* busca_mensalidade(char *arquivo, char *cpf_busca){
    FILE *arq;
    int abriu = 1;
    arq = fopen(arquivo, "rb");
    if(arq == NULL){
        abriu = 0;
    }
    if(abriu == 1){
        Mensalidade *mensalidade;
        mensalidade = (Mensalidade*) malloc(sizeof(Mensalidade));
        while(!feof(arq)){
            if(fread(mensalidade, sizeof(Mensalidade), 1, arq)){
                if((strcmp(mensalidade->cpf, cpf_busca) == 0) && (mensalidade->status == 'v')){
                    fclose(arq);
                    return mensalidade;
                }
            }
        }
        fclose(arq);
        return NULL;
    }
    return NULL;
}

Mensalidade* preenche_mensalidade(char *cpf, char*nome, char *plano){
    Mensalidade *mensalidade;
    mensalidade = (Mensalidade*) malloc(sizeof(Mensalidade));
    strcpy(mensalidade->cpf,cpf);
    strcpy(mensalidade->nome,nome);
    strcpy(mensalidade->plano,plano);
    pegaData(mensalidade->data_pg);
    cal_prox_pagamento(mensalidade->data_pg[2],mensalidade->data_pg[1], mensalidade->data_pg[0], mensalidade->prox_data);
    mensalidade->status = 'v';
    return mensalidade;
}

void salvar_no_arq_mensalidade(const Mensalidade *mensalidade, char *arquivo){
    FILE *arq;
    arq = fopen(arquivo, "ab");
    if (arq == NULL){
        printf("ERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    fwrite(mensalidade, sizeof(Mensalidade), 1, arq);
    fclose(arq);
}

void confirma_pagamento(char *arquivo, Mensalidade *mensa_novo){
    Mensalidade *mensa_teste;
    FILE *arq;
    arq = fopen(arquivo, "r+b");
    if (arq == NULL) {
        printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    mensa_teste = (Mensalidade*) malloc(sizeof(Mensalidade));
    int achou = 0;
    while((!feof(arq)) && (achou == 0)){
        fread(mensa_teste, sizeof(Mensalidade), 1, arq);
        if((strcmp(mensa_teste->cpf, mensa_novo->cpf) == 0) && (mensa_teste->status != 'x')) {
            achou = 1;
            strcpy(mensa_teste->cpf,mensa_novo->cpf);
            strcpy(mensa_teste->nome,mensa_novo->nome);
            strcpy(mensa_teste->plano,mensa_novo->plano);
            mensa_teste->data_pg[0] = mensa_novo->prox_data[2];
            mensa_teste->data_pg[1] = mensa_novo->prox_data[1];
            mensa_teste->data_pg[2] = mensa_novo->prox_data[0];
            cal_prox_pagamento(mensa_teste->data_pg[2],mensa_teste->data_pg[1], mensa_teste->data_pg[0],mensa_teste->prox_data);
            mensa_teste->status = 'v';
            fseek(arq, -1*sizeof(Mensalidade), SEEK_CUR);
            fwrite(mensa_teste, sizeof(Mensalidade), 1, arq);
        }
    }
    fclose(arq);
    free(mensa_teste);
}

void ler_arquivo_mensalidade(char *arquivo, char statu){
    FILE *arq;
    arq = fopen(arquivo, "rb");
    if (arq == NULL){
        printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    Mensalidade *mensalidade1;
    mensalidade1= (Mensalidade*) malloc(sizeof(Mensalidade));
    int cont = 0;
    while(!feof(arq)){
        if(fread(mensalidade1, sizeof(Mensalidade),1,arq)){
            if(mensalidade1->status == statu){
                printf("\n\tMensalidade %d:\n",cont+1);
                printf("\n\tCPF: %s", mensalidade1->cpf);
                printf("\tNOME: %s", mensalidade1->nome);
                printf("\tPLANO: R$ %s", mensalidade1->plano);
                printf("\n\tÚLTIMO PAGAMENTO: %d/%d/%d", mensalidade1->data_pg[2],mensalidade1->data_pg[1],mensalidade1->data_pg[0]);
                printf("\n\tPRÓXIMO PAGAMENTO: %d/%d/%d", mensalidade1->prox_data[0], mensalidade1->prox_data[1], mensalidade1->prox_data[2]);
                printf("\n\t===================================\n");
                cont+=1;
            }
        }
    }
    if(cont == 0){
        if(statu == 'v'){
            printf("\n\tNÃO EXISTE NENHUMA MENSALIDADE NO SISTEMA!\n");
        }
        else{
            printf("\n\tNÃO EXISTE NENHUMA MENSALIDADE ATRASADA NO SISTEMA!\n");
        }
    }
    fclose(arq);
    free(mensalidade1);
}

Mensalidade* pesquisa_mensalidade(char *arquivo, char *cpf_busca){
    FILE *arq;
    Mensalidade *mensalidade;
    arq = fopen(arquivo, "rb");
    if(arq == NULL){
        printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    mensalidade = (Mensalidade*) malloc(sizeof(Mensalidade));
    while(!feof(arq)){
        if(fread(mensalidade, sizeof(Mensalidade), 1, arq)){
            if((strcmp(mensalidade->cpf, cpf_busca) == 0) && (mensalidade->status == 'v')){
                fclose(arq);
                return mensalidade;
            }
        }
    }
    fclose(arq);
    return NULL;
}

void exibe_mensalidade(const Mensalidade* mensalidade){ // Função exibe o cliente cadastrado
    printf("\n\tCPF: %s", mensalidade->cpf);
    printf("\tNOME: %s", mensalidade->nome);
    printf("\tPLANO: %s", mensalidade->plano);
    printf("\n\tÚLTIMO PAGAMENTO: %d/%d/%d", mensalidade->data_pg[2],mensalidade->data_pg[1],mensalidade->data_pg[0]);
    printf("\n\tPRÓXIMO PAGAMENTO: %d/%d/%d", mensalidade->prox_data[0],mensalidade->prox_data[1],mensalidade->prox_data[2]);
}

void deleta_mensalidade(char *arquivo, Mensalidade *mensalidade){
    Mensalidade *mensa_teste;
    FILE *arq;
    arq = fopen(arquivo, "r+b");
    if (arq == NULL) {
        printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    mensa_teste = (Mensalidade*) malloc(sizeof(Mensalidade));
    int achou = 0;
    while((!feof(arq)) && (achou == 0)) {
        fread(mensa_teste, sizeof(Mensalidade), 1, arq);
        if((strcmp(mensa_teste->cpf, mensalidade->cpf) == 0) && (mensa_teste->status != 'x')) {
            achou = 1;
            int atraso = cal_atraso(mensa_teste->data_pg[2], mensa_teste->data_pg[1], mensa_teste->data_pg[0]);
            if(atraso == 1){
                char op[15];
                int dif_mes = 0;
                cal_atraso_etp2(mensa_teste->data_pg[2], mensa_teste->data_pg[1], mensa_teste->data_pg[0], &dif_mes);
                printf("\n\tA SEGUINTE MENSALIDADE SERÁ EXCLUÍDA:");
                exibe_mensalidade(mensa_teste);
                printf("\n\tOBS: CLIENTE EM ATRASO! TOTAL DE MESES EM ATRASO: %d", dif_mes);
                printf("\n\n\tDESEJA REALMENTE EXCLUIR? 1-(SIM) OU 2-(NÃO) >>> "); fgets(op,15,stdin); fflush(stdin);
                confirma_exclucao_mensa(mensa_teste, op, arq);
            }
            else{
                char op[15];
                printf("\n\tA SEGUINTE MENSALIDADE SERÁ EXCLUÍDA:");
                exibe_mensalidade(mensa_teste);
                printf("\n\tOBS: NÃO HÁ MENSALIDADES PENDENTES PARA ESTE CLIENTE!");
                printf("\n\n\tDESEJA REALMENTE EXCLUIR? 1-(SIM) OU 2-(NÃO) >>> "); fgets(op,15,stdin); fflush(stdin);
                confirma_exclucao_mensa(mensa_teste, op, arq);
            }
        }
    }
    fclose(arq);
    free(mensa_teste);
}

void confirma_exclucao_mensa(Mensalidade *mensalidade, char *op, FILE *arq){
    int op1 = atoi(op);
    while((op1 < 1) || (op1 > 2)){
        system("clear||cls");
        printf("\n\tOPÇÃO INVÁLIDA! TENTE NOVAMENTE:");
        char op_aux[10];
        printf("\n\n\tDESEJA REALMENTE EXCLUIR? 1-(SIM) OU 2-(NÃO) >>> "); fgets(op_aux, 10, stdin); fflush(stdin);
        op1 = atoi(op_aux);
    }
    if(op1 == 1){
        mensalidade->status = 'x';
        fseek(arq, -1*sizeof(Mensalidade), SEEK_CUR);
        fwrite(mensalidade, sizeof(Mensalidade), 1, arq);
        printf("\n\tMENSALIDADE EXCLUÍDA COM SUCESSO!\n");
    }
    else{
        printf("\n\tA EXCLUÇÃO FOI CANCELADA!");
    }
}

void recupera_mensalidade(char *arquivo, char *cpf, int*data){
    FILE *arq_mensalidade;
    Mensalidade *mensa_busca;
    arq_mensalidade = fopen(arquivo, "r+b");
    if(arq_mensalidade == NULL){
        printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    mensa_busca = (Mensalidade*) malloc(sizeof(Mensalidade));
    int achou = 0;
    while((!feof(arq_mensalidade) && (achou == 0))){
        fread(mensa_busca, sizeof(Mensalidade), 1, arq_mensalidade);
        if((strcmp(mensa_busca->cpf,cpf) == 0) && (mensa_busca->status == 'x') && (mensa_busca->data_pg[0]=data[0]) && (mensa_busca->data_pg[1]=data[1]) && (mensa_busca->data_pg[2]=data[2]) && (mensa_busca->data_pg[3]=data[3]) && (mensa_busca->data_pg[4]=data[4]) && (mensa_busca->data_pg[5]=data[5])){
            achou = 1;
            mensa_busca->status = 'v';
            fseek(arq_mensalidade, -1*sizeof(Mensalidade), SEEK_CUR);
            fwrite(mensa_busca, sizeof(Mensalidade), 1, arq_mensalidade);
        }
    }
    fclose(arq_mensalidade);
    free(mensa_busca);
}