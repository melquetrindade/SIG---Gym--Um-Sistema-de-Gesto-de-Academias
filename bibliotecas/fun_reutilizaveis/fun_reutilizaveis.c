#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include "fun_reutilizaveis.h"

void loop_cpf(char *cpf_teste){ // Função de loop de validação de telefone

    char copia_cpf[30];
    strcpy(copia_cpf,cpf_teste);

    cpf_inteiro(copia_cpf);
    int verifica = valida_cpf(copia_cpf);
    if(verifica == 0){
        char cpf_novo[40];
        printf("\tCPF INVÁLIDO, DIGITE UM NOVO CPF: (APENAS NÚMEROS)>>> "); 
        fgets(cpf_novo, 40, stdin); fflush(stdin);
        strcpy(copia_cpf, cpf_novo);
        loop_cpf(copia_cpf);
    }
    strcpy(cpf_teste, copia_cpf);
}

int valida_cpf(char *cpf_teste){ // Função que válida CPF

    char cpf[30];
    strcpy(cpf, cpf_teste);

    int tam = strlen(cpf);
    int soma = 0;
    int cpf_novo[11];
    int d1 = 0;
    int d2 = 0;

    if((tam - 1) != 11){
        return 0;
    }
    for(int i = 0; i < (tam-1); i++){
        if(cpf[i] <'0' && cpf[i] > '9'){
            return 0;
        }
    }
    for(int i = 0; i < 11; i++){
        cpf_novo[i] = (cpf[i] -48);
    }
    for(int i = 0; i < 9; i++){
        soma+= (cpf_novo[i] * (10-i));
    }
    d1 = 11 - (soma % 11);
    if(d1 == 10 || d1 == 11){
        d1 = 0;
    }
    if(d1 != cpf_novo[9]){
        return 0;
    }
    soma = 0;

    for(int i = 0; i < 10; i++){
        soma += (cpf_novo[i] * (11 - i));
    }
    d2 = 11 - (soma % 11);
    if(d2 == 10 || d2 == 11){
        d2 = 0;
    }
    if(d2 != cpf_novo[10]){
        return 0;
    }
    return 1;
}

void loop_de_validacao_data(char *data_teste){ // Função que fica no loop até o usuário digitar uma data válida

    char data_aux[40];
    int vetor_data[3]; 
    strcpy(data_aux, data_teste);
    int formatacao = valida_format_data(data_aux);

    if(formatacao == 0){
        while(formatacao == 0){
            printf("\tERRO DE FORMATACAO, TENTE NOVAMENTE!\n");
            char data_aux2[40];
            printf("\tDIGITE UMA NOVA DATA: (dd/mm/aaaa) >>> "); fgets(data_aux2, 40, stdin); fflush(stdin);
            strcpy(data_aux, data_aux2);
            formatacao = valida_format_data(data_aux2);
        }
    }
    divide_data_inteiro(data_aux, vetor_data);
    int confirma_data = dataValida(vetor_data[0], vetor_data[1], vetor_data[2]);
    if(confirma_data == 0){
        printf("\tA DATA INFORMADA E INVALIDA, TENTE NOVAMENTE!\n");
        char data_aux3[40];
        printf("\tINFORME UMA DATA VALIDA: (dd/mm/aaaa) >>> "); fgets(data_aux3, 40, stdin); fflush(stdin);
        strcpy(data_aux, data_aux3);
        loop_de_validacao_data(data_aux3);
    }
    else{
        strcpy(data_teste, data_aux);
    }
    strcpy(data_teste, data_aux);
}

int bissexto(int aa){ // Função que calcula se o ano é bissexto. Créditos: Flavius Gorgônio da Luz
    if((aa % 4 == 0) && (aa % 100 != 0)){
        return 1;
    }else if(aa % 400 == 0){
        return 1;
    }else{
        return 0;
    }
}

int dataValida(int dd, int mm, int aa){ // Função que valida datas. Créditos: Flavius Gorgônio da Luz
    int maiorDia;
    if(aa < 0 || mm < 1 || mm > 12 || dd < 1) {
        return 0;
    }
    if(mm == 2){
        if(bissexto(aa)) {
            maiorDia = 29;
        }else{
            maiorDia = 28;
        }
    }else if(mm == 4 || mm == 6 || mm == 9 || mm == 11){
        maiorDia = 30;
    }else{
        maiorDia = 31;
    }
    if(dd > maiorDia){
        return 0;
    }
    return 1;
}

int valida_format_data(char *data){ // Função que valida a formatação da data
    int tam = strlen(data);
    int cont = 0;
    if(data[0] == '/' || data[tam-2] == '/'){
        return 0;
    }
    for(int i = 0; i < (tam-1); i++){
        if(data[i] >= '0' && data[i] <= '9'){
            continue;
        }
        else if(data[i] == '/' && data[i+1] == '/'){
            return 0;
        }
        else if(data[i] == '/'){
            cont += 1;
            continue;
        }
        else{
            return 0;
        }
    }
    if(cont != 2){
        return 0;
    }
    return 1;
}

void divide_data_inteiro(char *data_teste, int *vetorData){ // Função que quebra a data string em data inteiro
    char copia_data[40];
    char *pt;
    char dia[10];
    char mes[10];
    char ano[20];
    strcpy(copia_data, data_teste);
    pt = strtok(data_teste, "/");
    int cont = 1;
    while(pt){
        if(cont == 1){
            strcpy(dia, pt);
        }
        else if(cont == 2){
            strcpy(mes, pt);
        }
        else{
            strcpy(ano, pt);
        }
        pt = strtok(NULL, "/");
        cont += 1;
    }
    vetorData[0] = atoi(dia);
    vetorData[1] = atoi(mes);
    vetorData[2] = atoi(ano);
    strcpy(data_teste, copia_data);
}

void pegaData(int *vetor){ // Função que pega a data do computador
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    vetor[0] = tm.tm_year + 1900;
    vetor[1] = tm.tm_mon + 1;
    vetor[2] =tm.tm_mday;
    vetor[3] = tm.tm_hour;
    vetor[4] = tm.tm_min;
    vetor[5] = tm.tm_sec;
}

void cal_prox_pagamento(int dia, int mes, int ano, int *vetor_data){ // Função que calcula quando será a próxima mensalidade/pagamento
    int dia_t = dia;
    int mes_t = mes;
    int ano_t = ano;
    int meses[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(bissexto(ano_t)){
        meses[1] = 29;
    }
    for(int i = 1; i <= meses[mes_t-1]; i++){
        dia_t += 1;
        if(dia_t > meses[mes_t-1]){
            mes_t += 1;
            dia_t = 1;
            if(mes_t == 13){
                mes_t = 1;
                ano_t += 1;
            }
        }
    }
    vetor_data[0] = dia_t;
    vetor_data[1] = mes_t;
    vetor_data[2] = ano_t;
}

void cal_atraso_etp2(int dia, int mes, int ano, int *diferenca){ // Função que calcula quantas mensalidades/salários estão em atraso

    int vetor[6];
    pegaData(vetor);

    if((vetor[0] - ano) > 1){
        int ano_aux = ano + 1;
        int diferenca_mes1 = 0;
        while(ano_aux != vetor[0]){
            diferenca_mes1 += 12;
            ano_aux += 1;
        }
        int diferenca_mes2 = 12 - mes;
        int total_mes = diferenca_mes1 + diferenca_mes2 + vetor[1];
        *diferenca = total_mes;
    }
    else if((vetor[0] - ano) == 1){
        int diferenca_mes2 = 12 - mes;
        int total_mes = diferenca_mes2 + vetor[1];
        *diferenca = total_mes;
    }
    else{
        int diferenca_mes3 = vetor[1] - mes;
        *diferenca = diferenca_mes3;
    }
}

int cal_atraso(int dia, int mes, int ano){ // Função que calcula se houve atraso na mensalidade 
    int meses[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(bissexto(ano)){
        meses[1] = 29;
    }
    int vetor[6];
    pegaData(vetor);
    if(ano != vetor[0] && mes != vetor[0]){
        if(mes < 12 || vetor[1] > 1 || (vetor[0] - ano > 1)){
            return 1;
        }else{
            int diferenca = 31 - dia;
            int soma1 = diferenca + vetor[1];
            if(soma1 > meses[mes-1]){
                return 1;
            }else{
                return 0;
            }
        }
    }else if(ano != vetor[0] && vetor[1] == mes){
        return 1;
    }else if(ano == vetor[0] && mes != vetor[1]){
        int soma = 0;
        int dif_mes = vetor[1] - mes;
        for(int i = 0; i < dif_mes; i++){
            soma+= meses[(mes-1)+i];
        }
        soma = soma - dia;
        soma = soma + vetor[2];
        if(soma > meses[mes-1]){
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}

void cpf_inteiro(char *fone_teste){ // Função que retira caracteres diferentes de números
    char cpf[30] = {""};
    char *pt;
    pt = strtok(fone_teste, " .-");
    while(pt){
        strcat(cpf, pt);
        pt = strtok(NULL, " .-");
    }
    strcpy(fone_teste,cpf); 
}

void loop_fone(char *fone_teste){ // Função de loop de validação de telefone

    int tam1 = strlen(fone_teste);
    char *copia_fone;
    copia_fone = (char*)(malloc(tam1+1));
    strcpy(copia_fone,fone_teste);

    fone_inteiro(copia_fone);
    printf("%s", copia_fone);
    int verifica = fone_valida_etp2(copia_fone);
    if(verifica == 0){
        char fone_novo[40];
        printf("NÚMERO INVÁLIDO, DIGITE UM NOVO NÚMERO: (APENAS NÚMEROS)>>> "); 
        fgets(fone_novo, 40, stdin); fflush(stdin);
        strcpy(copia_fone, fone_novo);
        loop_fone(copia_fone);
    }
    int ok_dd = valida_dd(copia_fone);
    if(ok_dd == 0){
        char fone_novo2[40];
        printf("NÚMERO INVÁLIDO, DIGITE UM NOVO NÚMERO: (APENAS NÚMEROS)>>> "); 
        fgets(fone_novo2, 40, stdin); fflush(stdin);
        strcpy(copia_fone, fone_novo2);
        loop_fone(copia_fone);
    }
    strcpy(fone_teste, copia_fone);
}

void fone_inteiro(char *fone_teste){ // Função que retira caracteres diferentes de números
    int tam = strlen(fone_teste);
    char *fone;
    char *pt;
    fone = (char*)(malloc(tam+1));
    pt = strtok(fone_teste, ")( .-");
    while(pt){
        strcat(fone, pt);
        pt = strtok(NULL, ")( .-");
    }
    strcpy(fone_teste,fone);  
}

int valida_dd(char *fone_teste){ // Função que verifica se o DD é válido
    int dds[67] = {61,62,64,65,66,67,82,71,73,74,75,77,85,88,98,99,83,81,87,86,89,84,79,68,96,92,97,91,93,94,69,95,63,27,28,31,32,33,34,35,37,38,21,22,24,11,12,13,14,15,16,17,18,19,41,42,43,44,45,46,51,53,54,55,47,48,49};
    int tam = strlen(fone_teste);
    char *dd1;
    char resto2[10];
    dd1 = (char*)(malloc(tam+1));
    strncpy(dd1, fone_teste, 2);
    for(int i = 0; i < tam; i++){
        if(i > 1){
            resto2[i-2] = fone_teste[i];
        }
    }
    int dd_int = atoi(dd1);
    int tam_resto = strlen(resto2);
    if(tam_resto != 10){
        return 0;
    }
    for(int i = 0; i <= 67; i++){
        if(dd_int == dds[i]){
            return 1;
        }
        else{
            continue;
        }
    }
    return 0;
}

int fone_valida_etp2(char *fone_teste){ //Função Verifica se a quantidade de carcacter está certo
    int tam = strlen(fone_teste);
    if(tam != 12){
        return 0;
    }
    for(int i = 0; i < tam-1; i++){
        if((fone_teste[i] >= '0' && fone_teste[i] <= '9') || fone_teste[i] == ' '){
            continue;
        }
        else{
            return 0;
        }
    }
    return 1;
}