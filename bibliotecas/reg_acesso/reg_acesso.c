#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "../fun_reutilizaveis/fun_reutilizaveis.h"
#include "../menu_principal/menu_principal.h"
#include "reg_acesso.h"
#include "../clientes/clientes.h"

typedef struct registro Registro;
char arq_cliente1[] = {"arq_cliente.dat"};
char arq_registro[] = {"arq_registro.dat"};

void registrar_frequencia(void){ // Função de registrar acesso
    system("clear||cls");
    Registro *frequencia;

    printf("\t======================================\n");
    printf("\t|     Módulo de Registrar Acesso     |\n");
    printf("\t======================================\n");

    char cpf[100];

    printf("\n\tINFORME O CPF: (APENAS NÚMEROS) >>> "); fgets(cpf, 100, stdin); fflush(stdin);
    loop_cpf(cpf);
    frequencia = busca_frequencia(arq_registro, cpf);
    if(frequencia == NULL){
        Cliente *cliente;
        cliente = busca_cliente(arq_cliente1, cpf);
        if(cliente == NULL){
            printf("\n\tACESSO NEGADO!, NÃO EXISTE NENHUM CLIENTE CADASTRADO NO SISTEMA COM ESTE CPF!");
        }
        else{
            Registro *frequencia1;
            frequencia1 = preenche_frequencia(cliente->cpf,cliente->nome);
            printf("\n\tPREENCHIMENTO DA PRIMEIRA FREQUÊNCIA!");
            printf("\n\n\tPRESIONE <ENTER> PARA CONFIRMAR O REGISTRO >>> ");
            getchar();
            printf("\n\tREGISTRO REALIZADO COM SUCESSO!");
            salvar_no_arq_registro(frequencia1, arq_registro);
            free(frequencia1);
        }
        free(cliente);
    }
    else{
        printf("\n\tPRESIONE <ENTER> PARA CONFIRMAR O REGISTRO >>> ");
        getchar();
        confirma_acesso(arq_registro,frequencia);
        printf("\n\tREGISTRO REALIZADO COM SUCESSO!");
    }
    free(frequencia);

    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void listar_frequencia(void){ // Função de listar frequência
    system("clear||cls");

    printf("\t=======================================\n");
    printf("\t|       Módulo de Listar Acessos      |\n");
    printf("\t=======================================\n");

    ler_arquivo_registro(arq_registro);

    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

Registro* busca_frequencia(char *arquivo, char *cpf_busca){
    FILE *arq;
    int abriu = 1;
    arq = fopen(arquivo, "rb");
    if(arq == NULL){
        abriu = 0;
    }
    if(abriu == 1){
        Registro *frequencia;
        frequencia = (Registro*) malloc(sizeof(Registro));
        while(!feof(arq)){
            if(fread(frequencia, sizeof(Registro), 1, arq)){
                if((strcmp(frequencia->cpf, cpf_busca) == 0) && (frequencia->status == 'v')){
                    fclose(arq);
                    return frequencia;
                }
            }
        }
        fclose(arq);
        return NULL;
    }
    return NULL;
}

Registro* preenche_frequencia(char *cpf, char*nome){
    Registro *frequencia;
    frequencia = (Registro*) malloc(sizeof(Registro));
    strcpy(frequencia->cpf,cpf);
    strcpy(frequencia->nome,nome);
    pegaData(frequencia->ult_data);
    frequencia->status = 'v';
    return frequencia;
}

void salvar_no_arq_registro(const Registro *frequencia, char *arquivo){
    FILE *arq;
    arq = fopen(arquivo, "ab");
    if (arq == NULL){
        printf("ERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    fwrite(frequencia, sizeof(Registro), 1, arq);
    fclose(arq);
}

void ler_arquivo_registro(char *arquivo){
    FILE *arq;
    arq = fopen(arquivo, "rb");
    if (arq == NULL){
        printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    Registro *frequencia;
    frequencia = (Registro*) malloc(sizeof(Registro));
    int cont = 0;
    while(!feof(arq)){
        if(fread(frequencia, sizeof(Registro),1,arq)){
            if(frequencia->status == 'v'){
                printf("\n\tFICHA %d:\n",cont+1);
                printf("\n\tNOME: %s", frequencia->nome);
                printf("\tÚLTIMO ACESSO EM: %d/%d/%d às %d:%d:%d", frequencia->ult_data[2],frequencia->ult_data[1],frequencia->ult_data[0],frequencia->ult_data[3],frequencia->ult_data[4],frequencia->ult_data[5]);
                printf("\n\t==========================================\n");
                cont+=1;
            }
        }
    }
    if(cont == 0){
        printf("\n\tNÃO EXISTE NENHUMA FREQUÊNCIA CADASTRADA NO SISTEMA!\n");
    }
    fclose(arq);
    free(frequencia);
}

void confirma_acesso(char *arquivo, Registro *frequencia_novo){
    Registro *frequencia_teste;
    FILE *arq;
    arq = fopen(arquivo, "r+b");
    if (arq == NULL) {
        printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    frequencia_teste = (Registro*) malloc(sizeof(Registro));
    int achou = 0;
    while((!feof(arq)) && (achou == 0)){
        fread(frequencia_teste, sizeof(Registro), 1, arq);
        if((strcmp(frequencia_teste->cpf, frequencia_novo->cpf) == 0) && (frequencia_teste->status != 'x')){
            achou = 1;
            strcpy(frequencia_teste->cpf,frequencia_novo->cpf);
            strcpy(frequencia_teste->nome,frequencia_novo->nome);
            pegaData(frequencia_teste->ult_data);
            frequencia_teste->status = 'v';
            fseek(arq, -1*sizeof(Registro), SEEK_CUR);
            fwrite(frequencia_teste, sizeof(Registro), 1, arq);
        }
    }
    fclose(arq);
    free(frequencia_teste);
}

Registro* pesquisa_frequencia(char *arquivo, char *cpf_busca){
    FILE *arq;
    Registro *frequencia;
    arq = fopen(arquivo, "rb");
    if(arq == NULL){
        printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    frequencia = (Registro*) malloc(sizeof(Registro));
    while(!feof(arq)){
        if(fread(frequencia, sizeof(Registro), 1, arq)){
            if((strcmp(frequencia->cpf, cpf_busca) == 0) && (frequencia->status == 'v')){
                fclose(arq);
                return frequencia;
            }
        }
    }
    fclose(arq);
    return NULL;
}

void deleta_frequencia(char *arquivo, char *cpf){
    FILE *arq_frequencia;
    Registro *frequencia_busca;
    arq_frequencia = fopen(arquivo, "r+b");
    if(arq_frequencia == NULL){
        printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    frequencia_busca = (Registro*) malloc(sizeof(Registro));
    int achou = 0;
    while((!feof(arq_frequencia) && (achou == 0))){
        fread(frequencia_busca, sizeof(Registro), 1, arq_frequencia);
        if((strcmp(frequencia_busca->cpf,cpf) == 0) && (frequencia_busca->status != 'x')) {
            achou = 1;
            frequencia_busca->status = 'x';
            fseek(arq_frequencia, -1*sizeof(Registro), SEEK_CUR);
            fwrite(frequencia_busca, sizeof(Registro), 1, arq_frequencia);
        }
    }
    fclose(arq_frequencia);
    free(frequencia_busca);
}