#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void while_cpf(char *cpf_teste){ // Função que fica no loop até o usuário digitar uma data válida

    char cpf_aux[30];
    strcpy(cpf_aux, cpf_teste);
    int teste = valida_cpf(cpf_aux);
    if(teste == 0){
        while(teste == 0){
            printf("CPF INVÁLIDO, TENTE NOVAMENTE!\n");
            char cpf_aux2[40];
            printf("DIGITE UM NOVO CPF: (APENAS NÚMEROS) >>> "); 
            fgets(cpf_aux2, 40, stdin); fflush(stdin);
            strcpy(cpf_aux, cpf_aux2);
            teste = valida_cpf(cpf_aux2);
        }
    }
    strcpy(cpf_teste, cpf_aux);
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

void while_de_validacao_data(char *data_teste){ // Função que fica no loop até o usuário digitar uma data válida

    char data_aux[40];
    int vetor_data[3]; 
    strcpy(data_aux, data_teste);
    int formatacao = valida_format_data(data_aux);

    if(formatacao == 0){
        while(formatacao == 0){
            printf("ERRO DE FORMATACAO, TENTE NOVAMENTE!\n");
            char data_aux2[40];
            printf("DIGITE UMA NOVA DATA: (dd/mm/aaaa) >>> "); fgets(data_aux2, 40, stdin); fflush(stdin);
            strcpy(data_aux, data_aux2);
            formatacao = valida_format_data(data_aux2);
        }
    }
    divide_data_inteiro(data_aux, vetor_data);
    int dia = vetor_data[0];
    int mes = vetor_data[1];
    int ano = vetor_data[2];
    int confirma_data = dataValida(dia, mes, ano);
    if(confirma_data == 0){
        printf("A DATA INFORMADA E INVALIDA, TENTE NOVAMENTE!\n");
        char data_aux3[40];
        printf("INFORME UMA DATA VALIDA: (dd/mm/aaaa) >>> "); fgets(data_aux3, 40, stdin); fflush(stdin);
        strcpy(data_aux, data_aux3);
        while_de_validacao_data(data_aux3);
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

    if(tam != 11){
        return 0;
    }
    for(int i = 0; i < 10; i++){
        if(data[i] >= '0' && data[i] <= '9'){
            continue;
        }
        else if(data[i] == '/'){
            continue;
        }
        else{
            return 0;
        }
    }
    if(data[2] != '/' || data[5] != '/'){
        return 0;
    }
    return 1;
}

void divide_data_inteiro(char *data_teste, int *vetorData){ // Função que quebra a data string em data inteiro
    char copia_data[40];
    char *pt;
    char dia[10];
    char mes[10];
    char ano[10];
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

