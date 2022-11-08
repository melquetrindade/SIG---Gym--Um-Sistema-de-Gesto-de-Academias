#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include "fun_reutilizaveis.h"
#include "../clientes/clientes.h"
#include "../menu_principal/menu_principal.h"
#include "../funcionarios/funcionarios.h"

// Função de loop de validação de cpf
void loop_cpf(char *cpf_teste){

    cpf_inteiro(cpf_teste);
    int verifica = valida_cpf(cpf_teste);
    if(verifica == 0){
        char cpf_novo[100];
        printf("\tCPF INVÁLIDO, DIGITE UM NOVO CPF: (APENAS NÚMEROS)>>> "); 
        fgets(cpf_novo, 100, stdin); fflush(stdin);
        strcpy(cpf_teste, cpf_novo);
        loop_cpf(cpf_teste);
    }
}

// Função que válida CPF
int valida_cpf(char *cpf_teste){ 

    char cpf[100];
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

// Função que fica no loop até o usuário digitar uma data válida
void loop_de_validacao_data(char *data_teste){ 

    char data_aux[100];
    int vetor_data[3]; 
    strcpy(data_aux, data_teste);
    int formatacao = valida_format_data(data_aux);

    if(formatacao == 0){
        while(formatacao == 0){
            printf("\tERRO DE FORMATACAO, TENTE NOVAMENTE!\n");
            char data_aux2[100];
            printf("\tDIGITE UMA NOVA DATA: (dd/mm/aaaa) >>> "); 
            fgets(data_aux2, 100, stdin); fflush(stdin);
            strcpy(data_aux, data_aux2);
            formatacao = valida_format_data(data_aux);
        }
    }
    divide_data_inteiro(data_aux, vetor_data);
    int confirma_data = dataValida(vetor_data[0], vetor_data[1], vetor_data[2]);
    if(confirma_data == 0){
        printf("\tA DATA INFORMADA E INVALIDA, TENTE NOVAMENTE!\n");
        char data_aux3[100];
        printf("\tINFORME UMA DATA VALIDA: (dd/mm/aaaa) >>> "); 
        fgets(data_aux3, 100, stdin); fflush(stdin);
        strcpy(data_aux, data_aux3);
        loop_de_validacao_data(data_aux);
    }
    strcpy(data_teste, data_aux);
}

// Função que calcula se o ano é bissexto. Créditos: Flavius Gorgônio da Luz
int bissexto(int aa){ 
    if((aa % 4 == 0) && (aa % 100 != 0)){
        return 1;
    }else if(aa % 400 == 0){
        return 1;
    }else{
        return 0;
    }
}

// Função que valida datas. Créditos: Flavius Gorgônio da Luz
int dataValida(int dd, int mm, int aa){ 
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

// Função que valida a formatação da data
int valida_format_data(char *data){
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

// Função que quebra a data string em data inteiro
void divide_data_inteiro(char *data_teste, int *vetorData){
    char copia_data[40];
    char *pt;
    char dia[30] = {""};
    char mes[30] = {""};
    char ano[30] = {""};
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

// Função que pega a data do computador
void pegaData(int *vetor){ 
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    vetor[0] = tm.tm_year + 1900;
    vetor[1] = tm.tm_mon + 1;
    vetor[2] =tm.tm_mday;
    vetor[3] = tm.tm_hour;
    vetor[4] = tm.tm_min;
    vetor[5] = tm.tm_sec;
}

// Função que calcula quando será a próxima mensalidade/pagamento
void cal_prox_pagamento(int dia, int mes, int ano, int *vetor_data){
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

// Função que calcula quantas mensalidades/salários estão em atraso
void cal_atraso_etp2(int dia, int mes, int ano, int *diferenca){

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

// Função que calcula se houve atraso na mensalidade 
int cal_atraso(int dia, int mes, int ano){
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

// Função que retira caracteres diferentes de números
void cpf_inteiro(char *fone_teste){ 
    char cpf[30] = {""};
    char *pt;
    pt = strtok(fone_teste, " .-");
    while(pt){
        strcat(cpf, pt);
        pt = strtok(NULL, " .-");
    }
    strcpy(fone_teste,cpf); 
}

// Função de loop de validação de telefone
void loop_fone(char *fone_teste){ 
    fone_inteiro(fone_teste);
    int verifica = fone_valida_etp2(fone_teste);
    if(verifica == 0){
        char fone_novo[100] = {""};
        printf("\tNÚMERO INVÁLIDO, DIGITE UM NOVO NÚMERO: (APENAS NÚMEROS)>>> "); 
        fgets(fone_novo,100, stdin); fflush(stdin);
        strcpy(fone_teste, fone_novo);
        loop_fone(fone_teste);
    }
    int ok_dd = valida_dd(fone_teste);
    if(ok_dd == 0){
        char fone_novo2[100] = {""};
        printf("\tNÚMERO INVÁLIDO, DIGITE UM NOVO NÚMERO: (APENAS NÚMEROS)>>> "); 
        fgets(fone_novo2, 100, stdin); fflush(stdin);
        strcpy(fone_teste, fone_novo2);
        loop_fone(fone_teste);
    }
}

// Função que retira caracteres diferentes de números
void fone_inteiro(char *fone_teste){ 
    char fone[100] = {""};
    char *pt;
    pt = strtok(fone_teste, ")( .-");
    while(pt){
        strcat(fone, pt);
        pt = strtok(NULL, ")( .-");
    }
    strcpy(fone_teste,fone);  
}

// Função que verifica se o DD é válido
int valida_dd(char *fone_teste){
    int dds[67] = {61,62,64,65,66,67,82,71,73,74,75,77,85,88,98,99,83,81,87,86,89,84,79,68,96,92,97,91,93,94,69,95,63,27,28,31,32,33,34,35,37,38,21,22,24,11,12,13,14,15,16,17,18,19,41,42,43,44,45,46,51,53,54,55,47,48,49};
    int tam = strlen(fone_teste);
    char dd1[3];
    char resto2[10];
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

//Função Verifica se a quantidade de carcacter está certo
int fone_valida_etp2(char *fone_teste){
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
// Função que quebra o email em duas partes;
void quebra_email(char *email_teste, char *prt_local, char *prt_dominio){
    char copia_email[200] = {""};
    strcpy(copia_email, email_teste);
    char local[100] = {""};
    char dominio[100] = {""};
    char *pt;
    pt = strtok(copia_email, "@");
    int cont = 1;
    while(pt){
        if(cont == 1){
            strcat(local, pt);
        }
        else{
            strcat(dominio, pt);
        }
        cont += 1;
        pt = strtok(NULL, "@");
    }
    strcpy(prt_local,local);
    strcpy(prt_dominio, dominio); 

}

// Função que verifica se tem o @ no email
int verifica_arroba(char *email_teste){
    int tam = strlen(email_teste);
    int cont = 0;
    for(int i = 0; i < (tam-1); i++){
        if(email_teste[i] == '@'){
            cont += 1;
        }
        else{
            continue;
        }
    }
    if(cont != 1){
        return 0;
    }
    return 1;
}

// Função que recebe o retorno da função local e domínio
int valida_local_dominio(char *local, char *dominio){
    int recebe_local = verifica_local(local);
    int recebe_dominio = verifica_dominio(dominio);
    if(recebe_local == 1 && recebe_dominio == 1){
        return 1;
    }
    return 0;
}

// Função que valida a parte local do email
int verifica_local(char *local){ // # ! % $ ‘ & + * – / = ? ^ _`. { | } ~
    int caracteres[20] = {35,33,37,36,39,38,43,42,95,47,61,63,94,45,96,46,123,124,125,126};
    int tam = strlen(local);
    if(tam > 65){
        return 0;
    }if(local[0] == '.'){
        return 0;
    }for(int i = 0; i < (tam); i++){
        if(local[i] >= 'a' && local[i] <= 'z'){
            continue;
        }else if(local[i] >= 'A' && local[i] <= 'Z'){
            continue;
        }else if(local[i] == '.' && local[i+1] == '.'){
            return 0;
        }else if(local[i] >= '0' && local[i] <= '9'){
            continue;
        }else{
            int con3 = 0;
            for(int y = 0; y < 20; y++){
                if(local[i] == caracteres[y]){
                    continue;
                }else{
                    con3 += 1;
                }
            }if(con3 == 20){
                return 0;
            }
        }
    }
    return 1;
}

// Função que valida a parte domínio do email
int verifica_dominio(char *dominio){
    int tam = strlen(dominio);
    int cont = 0;
    int cont2 = 0;
    if(tam > 65){
        return 0;
    }
    if((dominio[tam-2] == '.') || (dominio[0] == '-' && dominio[tam-2] == '-')){
        return 0;
    }
    for(int i = 0; i < (tam - 2); i++){
        if((dominio[i] >= 'a' && dominio[i] <= 'z') || (dominio[i] >= 'A' && dominio[i] <= 'Z')){
            continue;
        }
        else if(dominio[i] >= '0' && dominio[i] <= '9'){
            cont += 1;
            continue;
        }
        else if(dominio[i] == '.' && dominio[i+1] == '.'){
            return 0;
        }
        else if(dominio[i] == '.'){
            cont2 += 1;
            continue;
        }
        else if(dominio[i] == '-'){
            continue;
        }
        else{
            return 0;
        }
    }
    if(cont == tam){
        return 0;
    }
    if(cont2 < 1){
        return 0;
    }
    return 1;
}

// Função do loop do email
void loop_email(char *email_teste){ 
    int taOk = verifica_arroba(email_teste);

    if(taOk == 1){
        char local[100] = {""};
        char dominio[100] = {""};
        quebra_email(email_teste, local, dominio);
        int confirma = valida_local_dominio(local, dominio);
        if(confirma == 0){
            char email_novo[200] = {""};
            printf("\tE-MAIL INVÁLIDO, DIGITE UM NOVO E-MAIL: "); 
            fgets(email_novo,200, stdin); fflush(stdin);
            strcpy(email_teste, email_novo);
            loop_email(email_teste);
        }
    }
    else{
        char email_novo[200] = {""};
        printf("\tE-MAIL INVÁLIDO, DIGITE UM NOVO E-MAIL: "); 
        fgets(email_novo,200, stdin); fflush(stdin);
        strcpy(email_teste, email_novo);
        loop_email(email_teste);
    }
}

// Função verica se existe outro que não seja letras
int verifica_caracter(char *nome){
    int tam = strlen(nome);
    for(int i = 0; i < (tam-1); i++){
        if((nome[i] >= 33 && nome[i] <= 64) || (nome[i] >= 91 && nome[i] <= 96)){
            return 0;
        }
        else if(nome[i] >= 123 && nome[i] <= 126){
            return 0;
        }
        else{
            continue;
        }
    }
    if(tam == 2){
        if(nome[0] == 10){
            return 0;
        }
    }
    return 1;
}

// Função de loop de nome
void loop_nome(char *nome_teste){

    formata_nome(nome_teste);
    verifica_caracter(nome_teste);
    int verifica = verifica_caracter(nome_teste);
    if(verifica == 0){
        char nome_novo[100] = {""};
        printf("\tNOME INVÁLIDO, DIGITE UM NOVO NOME: "); 
        fgets(nome_novo, 100, stdin); fflush(stdin);
        strcpy(nome_teste, nome_novo);
        loop_nome(nome_teste);
    }
}

// Função retira todos os caracteres de espaçamento
void formata_nome(char *nome_teste){
    char *pt;
    char nome[100] = {""};
    pt = strtok(nome_teste, " ");
    while(pt){
        strcat(nome, pt);
        strcat(nome, " ");
        pt = strtok(NULL, " ");
    }
    strcpy(nome_teste,nome);
}

// Função que verifica se a opção do plano é válida
int valida_caracter_valor_cliente(char *valor){
    int tam = strlen(valor);
    if(tam != 2){
        return 0;
    }
    int planos[4] = {49,50,51,10};
    for(int i = 0; i < 4; i++){
        if(valor[0] == planos[i]){
            return 1;
        }
    }
    return 0;
}

// Função retira todos os caracteres de espaçamento
void valor_inteiro(char *plano_teste){
    char plano[20] = {""};
    char *pt;
    pt = strtok(plano_teste, " ");
    while(pt){
        strcat(plano, pt);
        pt = strtok(NULL, " ");
    }
    strcpy(plano_teste,plano);  
}

// Função de lopp de plano para clientes
void loop_valor_cliente(char *valor_teste){

    valor_inteiro(valor_teste);
    int verifica = valida_caracter_valor_cliente(valor_teste);
    if(verifica == 0){
        char valor_novo[20];
        printf("\tPLANO INVÁLIDO, DIGITE UM NOVO PLANO: "); 
        fgets(valor_novo, 20, stdin); fflush(stdin);
        strcpy(valor_teste, valor_novo);
        loop_valor_cliente(valor_teste);
    }
    else{
        if(valor_teste[0] == 49){
            strcpy(valor_teste, "59,99");
        }
        else if(valor_teste[0] == 50){
            strcpy(valor_teste, "69,99");
        }
        else{
            strcpy(valor_teste, "79,99");
        }
    }
}

// Função de loop de salário para funcionários
void loop_valor_funcionario(char *valor_teste){

    valor_inteiro(valor_teste);
    int verifica = valida_caracter_valor_funcionario(valor_teste);
    if(verifica == 0){
        char valor_novo[20];
        printf("\tPLANO INVÁLIDO, DIGITE UM NOVO PLANO: "); 
        fgets(valor_novo, 20, stdin); fflush(stdin);
        strcpy(valor_teste, valor_novo);
        loop_valor_funcionario(valor_teste);
    }
    else{
        if(valor_teste[0] == 49){
            strcpy(valor_teste, "606,00");
        }
        else if(valor_teste[0] == 50){
            strcpy(valor_teste, "1.212,00");
        }
        else if(valor_teste[0] == 51){
            strcpy(valor_teste, "2.424,00");
        }
        else{
            strcpy(valor_teste, "3.636,00");
        }
    }
}

// Função que verifica se a opção de salário é válida
int valida_caracter_valor_funcionario(char *valor){
    int tam = strlen(valor);
    if(tam != 2){
        return 0;
    }
    int planos[5] = {49,50,51,52,10};
    for(int i = 0; i < 5; i++){
        if(valor[0] == planos[i]){
            return 1;
        }
    }
    return 0;
}