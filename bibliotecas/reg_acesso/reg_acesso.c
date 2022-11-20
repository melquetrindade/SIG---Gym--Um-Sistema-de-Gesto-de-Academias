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
    printf("\n\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void listar_frequencia(void){ // Função de listar frequência
    system("clear||cls");

    printf("\t=======================================\n");
    printf("\t|       Módulo de Listar Acessos      |\n");
    printf("\t=======================================\n");

    lista_tempo(arq_registro);

    printf("\n\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

// Função que verifica se já existe uma ficha de frequência com o cpf informado
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

// Função que preenche a ficha de clientes
Registro* preenche_frequencia(char *cpf, char*nome){
    Registro *frequencia;
    frequencia = (Registro*) malloc(sizeof(Registro));
    strcpy(frequencia->cpf,cpf);
    strcpy(frequencia->nome,nome);
    pegaData(frequencia->ult_data);
    frequencia->status = 'v';
    frequencia->id[0]=0;frequencia->id[1]=0;frequencia->id[2]=0;frequencia->id[3]=0;frequencia->id[4]=0;frequencia->id[5]=0;
    return frequencia;
}

// Função que salva no arquivo de registro
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

// Função que faz a leitura do arquivo de registro
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

// Função que realiza a confirmação do acesso do cliente a academia 
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

// Função que pesquisa por uma ficha em específica
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

// Função que deleta a ficha de frequência
void deleta_frequencia(char *arquivo, char *cpf, int*data){
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
            frequencia_busca->id[0]=data[0];frequencia_busca->id[1]=data[1];frequencia_busca->id[2]=data[2];frequencia_busca->id[3]=data[3];frequencia_busca->id[4]=data[4];frequencia_busca->id[5]=data[5];
            fseek(arq_frequencia, -1*sizeof(Registro), SEEK_CUR);
            fwrite(frequencia_busca, sizeof(Registro), 1, arq_frequencia);
        }
    }
    fclose(arq_frequencia);
    free(frequencia_busca);
}

// Função que recupera a ficha de frequência
void recupera_frequencia(char *arquivo, char *cpf, int*data){
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
        if((strcmp(frequencia_busca->cpf,cpf) == 0) && (frequencia_busca->status == 'x')){
            if((frequencia_busca->id[0]=data[0]) && (frequencia_busca->id[1]=data[1]) && (frequencia_busca->id[2]=data[2]) && (frequencia_busca->id[3]=data[3]) && (frequencia_busca->id[4]=data[4]) && (frequencia_busca->id[5]=data[5])){
                achou = 1;
                frequencia_busca->status = 'v';
                fseek(arq_frequencia, -1*sizeof(Registro), SEEK_CUR);
                fwrite(frequencia_busca, sizeof(Registro), 1, arq_frequencia);
            }
        }
    }
    fclose(arq_frequencia);
    free(frequencia_busca);
}

// Função que calcula há quanto tempo o cliente não visita a academia
int cal_tempo(int *data){
    int meses[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int vetor[6];
    pegaData(vetor);
    if(bissexto(vetor[0])){
        meses[1] = 29;
    }
    int dia = data[2];
    int mes = data[1];
    int ano = data[0];
    int tempo = 0;
    int dif_ano = vetor[0] - ano;

    if(dif_ano == 0){
        int dif_mes = vetor[1] - mes;
        if(dif_mes == 1){
            int soma_dia = vetor[2] + (meses[mes-1] - dia);
            if(soma_dia < 32){
                tempo = soma_dia;
            }
            else{
                tempo = 32;;
            }
        }
        else if(dif_mes > 1){
            tempo = 32;
        }
        else{
            int dif_dia = vetor[2] - dia;
            tempo = dif_dia;
        }
    }
    else{
        if(vetor[1] == 1 && mes == 12){
            int soma_dia = vetor[2] + (meses[mes-1] - dia);
            if(soma_dia < 32){
                tempo = soma_dia;
            }
            else{
                tempo = 32;;
            }
        }
        else{
            tempo = 32;
        }
    }
    return tempo;
}

// Função que exibe as opções de listagem das frequência
void lista_tempo(char *arquivo){
    system("clear||cls");
    int op1 = 0;
    do{
        char op[15];
        printf("\n\t########################################");
        printf("\n\t#   1- ACESSADO HOJE                   #");
        printf("\n\t#   2- ACESSADO NOS ÚLTIMOS 7 DIAS     #");
        printf("\n\t#   3- ACESSADO NAS ÚLTIMAS 2 SEMANAS  #");
        printf("\n\t#   4- ACESSADO ESTE MÊS               #");
        printf("\n\t#   5- NÃO ACESSA HÁ MAIS DE 1 MÊS     #");
        printf("\n\t#   6- LISTAR TODOS OS ACESSOS         #");
        printf("\n\t########################################");
        printf("\n\n\tSELECIONE O PERÍODO QUE DESEJA LISTAR >>> "); fgets(op,15,stdin); fflush(stdin);
        op1 = atoi(op);
        if(op1 < 1 || op1 > 6){
            system("clear||cls");
            printf("\n\tOPÇÃO INVÁLIDA, TENTE NOVAMENTE!!");
        }
    }while(op1 < 1 || op1 > 6);
    if(op1 == 1){
        system("clear||cls");
        int hoje = 0;
        ler_por_tempo(arquivo,hoje);
    }
    else if(op1 == 2){
        system("clear||cls");
        int semana = 7;
        ler_por_tempo(arquivo,semana);
    }
    else if(op1 == 3){
        system("clear||cls");
        int duas_semana = 14;
        ler_por_tempo(arquivo,duas_semana);
    }
    else if(op1 == 4){
        system("clear||cls");
        int mes = 31;
        ler_por_tempo(arquivo,mes);
    }
    else if(op1 == 5){
        system("clear||cls");
        int duas_mes = 31;
        ler_por_tempo2(arquivo,duas_mes);
    }
    else{
        system("clear||cls");
        ler_arquivo_registro(arquivo);
    }
}

// Função que exibe os clientes com base na faixa de período selecionado
void ler_por_tempo(char *arquivo, int tempo){
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
            int tempo_rec = cal_tempo(frequencia->ult_data);
            if((tempo_rec <= tempo) && (frequencia->status != 'x')){
                printf("\n\tFICHA %d:\n",cont+1);
                printf("\n\tNOME: %s", frequencia->nome);
                printf("\tÚLTIMO ACESSO EM: %d/%d/%d às %d:%d:%d", frequencia->ult_data[2],frequencia->ult_data[1],frequencia->ult_data[0],frequencia->ult_data[3],frequencia->ult_data[4],frequencia->ult_data[5]);
                printf("\n\t==========================================\n");
                cont += 1;
            }
        }
    }
    if(cont == 0){
        printf("\n\tNÃO EXISTE NENHUMA FICHA DE FREQUÊNCIA NO SISTEMA NESTE PERÍODO!\n");
    }
    fclose(arq);
    free(frequencia);
}

// Função que exibe os clientes com base na faixa de período de mais de 2 meses sem visita
void ler_por_tempo2(char *arquivo, int tempo){
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
            int tempo_rec = cal_tempo(frequencia->ult_data);
            if((tempo_rec > tempo) && (frequencia->status != 'x')){
                printf("\n\tFICHA %d:\n",cont+1);
                printf("\n\tNOME: %s", frequencia->nome);
                printf("\tÚLTIMO ACESSO EM: %d/%d/%d às %d:%d:%d", frequencia->ult_data[2],frequencia->ult_data[1],frequencia->ult_data[0],frequencia->ult_data[3],frequencia->ult_data[4],frequencia->ult_data[5]);
                printf("\n\t==========================================\n");
                cont += 1;
            }
        }
    }
    if(cont == 0){
        printf("\n\tNÃO EXISTE NENHUM CLIENTE CADASTRADO NO SISTEMA COM ESTE PERÍODO!\n");
    }
    fclose(arq);
    free(frequencia);
}

// Função que atualiza a ficha de frequência
void atualiza_registro(char *arq_registro, char *cliente_cpf, char *cliente_nome){
    FILE *arq_registro1;
    arq_registro1 = fopen(arq_registro, "r+b");
    if(arq_registro1 == NULL){
        printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    int achou = 0;
    Registro *frequencia_teste;
    frequencia_teste = (Registro*) malloc(sizeof(Registro));
    while(!feof(arq_registro1) && (achou == 0)){
        fread(frequencia_teste, sizeof(Registro), 1, arq_registro1);
        if((strcmp(frequencia_teste->cpf,cliente_cpf) == 0) && frequencia_teste->status != 'x'){
            achou = 1;
            strcpy(frequencia_teste->nome,cliente_nome);
            fseek(arq_registro1, -1*sizeof(Registro), SEEK_CUR);
            fwrite(frequencia_teste, sizeof(Registro), 1, arq_registro1);
        }
    }
    fclose(arq_registro1);
    free(frequencia_teste);
}