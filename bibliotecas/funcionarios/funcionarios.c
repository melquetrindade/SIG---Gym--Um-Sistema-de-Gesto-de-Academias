#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "../fun_reutilizaveis/fun_reutilizaveis.h"
#include "../menu_principal/menu_principal.h"
#include "funcionarios.h"
#include "../pagamentos/pagamentos.h"

typedef struct funcionario Funcionario;

char arquivo_funcionario[] = {"arq_funcionario.dat"};
char arq_salario1[] = {"arq_salario.dat"};

void cadastrar_funcionario(void){ // Função de cadastrar funcionários
    system("clear||cls");

    printf("\t===================================\n");
    printf("\t|         Módulo de Cadastro      |\n");
    printf("\t===================================\n");

    Funcionario *funcionario;

    funcionario = preenche_funcionario();
    salvar_no_arq_func(funcionario,arquivo_funcionario);
    system("clear||cls");
    printf("\tFUNCIONÁRIO CADASTRADO COM SUCESSO!\n");
    exibe_funcionario(funcionario);
    free(funcionario);

    printf("\n\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void deletar_funcionario(void){ // Função de deletar funcionários
    system("clear||cls");
    Funcionario *funcionario;

    printf("\t===================================\n");
    printf("\t|         Módulo de Exclusão      |\n");
    printf("\t===================================\n");

    char cpf[100];

    printf("\tINFORME O CPF: (APENAS NÚMEROS) >>> "); fgets(cpf, 100, stdin); fflush(stdin);
    loop_cpf(cpf);
    funcionario = busca_funcionario(arquivo_funcionario, cpf);
    if(funcionario == NULL){
        printf("\n\tNÃO EXISTE NENHUM FUNCIONAŔIO CADASTRADO COM ESTE CPF NO SISTEMA!");
    }
    else{
        deleta_funcionario(arquivo_funcionario, funcionario);
    }
    free(funcionario);

    printf("\n\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls"); 
}

void recuperar_funcionario(void){ // Função de recuperar funcionários
    system("clear||cls");
    Funcionario *funcionario;

    printf("\t===================================\n");
    printf("\t|         Módulo de Recuperar     |\n");
    printf("\t===================================\n");

    char cpf[100];

    printf("\tINFORME O CPF: (APENAS NÚMEROS) >>> "); fgets(cpf, 100, stdin); fflush(stdin);
    loop_cpf(cpf);
    funcionario = busca_func_excluido(arquivo_funcionario, cpf);
    if(funcionario == NULL){
        printf("\n\tNÃO EXISTE NENHUM FUNCIONÁRIO NA LIXEIRA DO SISTEMA COM ESTE CPF!");
    }
    else{
        int recebe = verifica_2_cpfs_func(arquivo_funcionario, funcionario);
        if(recebe == 0){
            printf("\n\tJÁ EXISTE UM FUNCIONAŔIO CADASTRADO COM ESTE CPF NO SISTEMA!");
        }
        else{
            exibe_funcionario(funcionario);
            recupera_funcionario(arquivo_funcionario, funcionario);
        }
    }
    free(funcionario);

    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void pesquisar_funcionario(void){ // Função de pesquisar funcionários
    system("clear||cls");
    Funcionario *funcionario;

    printf("\t===================================\n");
    printf("\t|         Módulo de Pesquisar     |\n");
    printf("\t===================================\n");

    char cpf[100];

    printf("\tINFORME O CPF: (APENAS NÚMEROS) >>> "); fgets(cpf, 100, stdin); fflush(stdin);
    loop_cpf(cpf);
    funcionario = busca_funcionario(arquivo_funcionario, cpf);
    if(funcionario == NULL){
        printf("\n\tNÃO EXISTE NENHUM CLIENTE CADASTRADO COM ESTE CPF NO SISTEMA!");
    }
    else{
        exibe_funcionario(funcionario);
    }
    free(funcionario);

    printf("\n\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void atualizar_funcionario(void){ // Função de atualizar funcionários
    system("clear||cls");
    Funcionario *funcionario;

    printf("\t===================================\n");
    printf("\t|       Módulo de Atualização     |\n");
    printf("\t===================================\n");

    char cpf[100];

    printf("\tINFORME O CPF: (APENAS NÚMEROS) >>> "); fgets(cpf, 100, stdin); fflush(stdin);
    loop_cpf(cpf);
    funcionario = busca_funcionario(arquivo_funcionario, cpf);
    if(funcionario == NULL){
        printf("\n\tNÃO EXISTE NENHUM FUNCIONÁRIO CADASTRADO COM ESTE CPF NO SISTEMA!");
    }
    else{
        atualiza_funcionario(arquivo_funcionario, funcionario);
        funcionario = busca_funcionario(arquivo_funcionario, cpf);
        if(funcionario == NULL){
            printf("\n\tNÃO EXISTE NENHUM FUNCIONÁRIO CADASTRADO COM ESTE CPF NO SISTEMA!");
        }
        else{
            system("clear||cls");
            printf("\n\n\tFUNCIONÁRIO ATUALIZADO COM SUCESSO!\n");
            exibe_funcionario(funcionario);
        }
    }
    free(funcionario);

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
    verifica_pessoa_func(arquivo_funcionario, funcionario->cpf);
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
            if(funcionario->status == 'v'){
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
    }
    if(cont == 0){
        printf("\n\tNÃO EXISTE NENHUM FUNCIONÁRIO CADASTRADO NO SISTEMA!\n");
    }
    fclose(arq);
    free(funcionario);
}

// Função que busca cliente
Funcionario* busca_funcionario(char *arquivo, char *cpf_busca){
    FILE *arq;
    Funcionario *funcionario;
    arq = fopen(arquivo, "rb");
    if(arq == NULL){
        printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    funcionario = (Funcionario*) malloc(sizeof(Funcionario));
    while(!feof(arq)){
        if(fread(funcionario, sizeof(Funcionario), 1, arq)){
            if((strcmp(funcionario->cpf, cpf_busca) == 0) && (funcionario->status == 'v')){
                fclose(arq);
                return funcionario;
            }
        }
    }
    fclose(arq);
    return NULL;
}

// Função que deleta cliente
// void deleta_funcionario(char *arquivo, Funcionario *funcionario){
//     Funcionario *funcionario_teste;
//     FILE *arq;
//     arq = fopen(arquivo, "r+b");
//     if (arq == NULL) {
//         printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
//         exit(1);
//     }
//     funcionario_teste = (Funcionario*) malloc(sizeof(Funcionario));
//     int achou = 0;
//     while((!feof(arq)) && (achou == 0)) {
//         fread(funcionario_teste, sizeof(Funcionario), 1, arq);
//         if((strcmp(funcionario_teste->cpf, funcionario->cpf) == 0) && (funcionario_teste->status != 'x')) {
//             achou = 1;
//             funcionario->status = 'x';
//             fseek(arq, -1*sizeof(Funcionario), SEEK_CUR);
//             fwrite(funcionario_teste, sizeof(Funcionario), 1, arq);
//             printf("\n\tFUNCIONÁRIO EXCLUÍDO COM SUCESSO!\n");
//         }
//     }
//     fclose(arq);
//     free(funcionario_teste);
    
// }

// Função que deleta cliente
void deleta_funcionario(char *arquivo, Funcionario *funcionario){
    Funcionario *func_teste;
    FILE *arq;
    arq = fopen(arquivo, "r+b");
    if (arq == NULL) {
        printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    func_teste = (Funcionario*) malloc(sizeof(Funcionario));
    int achou = 0;
    while((!feof(arq)) && (achou == 0)) {
        fread(func_teste, sizeof(Funcionario), 1, arq);
        if((strcmp(func_teste->cpf, funcionario->cpf) == 0) && (func_teste->status != 'x')) {
            achou = 1;
            confir_excl_func(func_teste, arq, arq_salario1);
        }
    }
    fclose(arq);
    free(func_teste);
    
}

void confir_excl_func(Funcionario *func_teste, FILE *arq, char *arq_salario1){
    Salario *salario_teste;
    salario_teste = pesquisa_salario(arq_salario1, func_teste->cpf);
    if(salario_teste == NULL){
        printf("\n\tERRO, NÃO FOI POSSÍVEL CONTINUAR COM A OPERAÇÃO!");
        printf("\n\tO FUNCIONÁRIO PRECISA TER UMA CONTA SALARIAL");
    }
    else{
        int atraso = cal_atraso(salario_teste->data_pg[2], salario_teste->data_pg[1], salario_teste->data_pg[0]);
        if(atraso == 1){
            char op[15];
            int dif_mes = 0;
            cal_atraso_etp2(salario_teste->data_pg[2], salario_teste->data_pg[1], salario_teste->data_pg[0], &dif_mes);
            system("clear||cls");
            exibe_funcionario(func_teste);
            printf("\n\tOBS: FUNCIONÁRIO ESTÁ COM SALÁRIO EM ATRASO! TOTAL DE SALÁRIOS EM ATRASO: %d", dif_mes);
            printf("\n\n\tDESEJA REALMENTE EXCLUIR? 1-(SIM) OU 0-(NÃO) >>> "); fgets(op,15,stdin); fflush(stdin);
            cfrm_exclu_func_etp2(salario_teste->cpf, op, arq_salario1, arq, func_teste);
        }
        else{
            char op[15];
            system("clear||cls");
            exibe_funcionario(func_teste);
            printf("\n\n\tDESEJA REALMENTE EXCLUIR? 1-(SIM) OU 0-(NÃO) >>> "); fgets(op, 15, stdin); fflush(stdin);
            cfrm_exclu_func_etp2(salario_teste->cpf, op, arq_salario1, arq, func_teste);
        }
    }
    free(salario_teste);
}

void cfrm_exclu_func_etp2(char *salario_cpf, char *op, char *arq2, FILE *arq, Funcionario *func_teste){
    int op1 = atoi(op);
    while((op1 < 0) || (op1 > 1)){
        system("clear||cls");
        printf("\n\tOPÇÃO INVÁLIDA! TENTE NOVAMENTE:");
        char op_aux[10];
        printf("\n\n\tDESEJA REALMENTE EXCLUIR? 1-(SIM) OU 0-(NÃO) >>> "); fgets(op_aux, 10, stdin); fflush(stdin);
        op1 = atoi(op_aux);
    }
    if(op1 == 1){
        FILE *arq_salari;
        Salario *salario_busca;
        arq_salari = fopen(arq2, "r+b");
        if(arq_salari == NULL){
            printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
            exit(1);
        }
        salario_busca = (Salario*) malloc(sizeof(Salario));
        int achou = 0;
        while((!feof(arq_salari)) && (achou == 0)) {
            fread(salario_busca, sizeof(Salario), 1, arq_salari);
            if((strcmp(salario_busca->cpf, salario_cpf) == 0) && (salario_busca->status != 'x')) {
                achou = 1;
                salario_busca->status = 'x';
                fseek(arq_salari, -1*sizeof(Salario), SEEK_CUR);
                fwrite(salario_busca, sizeof(Salario), 1, arq_salari);
            }
        }
        fclose(arq_salari);
        free(salario_busca);
        func_teste->status = 'x';
        fseek(arq, -1*sizeof(Funcionario), SEEK_CUR);
        fwrite(func_teste, sizeof(Funcionario), 1, arq);
        printf("\n\tFUNCIONÁRIO EXCLUÍDO COM SUCESSO!");
    }
    else{
        printf("\n\tA EXCLUÇÃO FOI CANCELADA!");
    }
}

// Função que procura por algum cliente excluído e garante que ele não está ativo antes de fazer a recuperação
Funcionario* busca_func_excluido(char *arquivo, char *cpf_busca){
    FILE *arq;
    Funcionario *funcionario;
    arq = fopen(arquivo, "rb");
    if(arq == NULL){
        printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    funcionario = (Funcionario*) malloc(sizeof(Funcionario));
    while(!feof(arq)){
        if(fread(funcionario, sizeof(Funcionario), 1, arq)){
            if(strcmp(funcionario->cpf, cpf_busca) == 0){
                if(funcionario->status == 'v'){
                    fclose(arq);
                    return funcionario;
                }else{
                    int recebe = verifica_2_cpfs_func(arquivo,funcionario);
                    if(recebe == 0){
                        fclose(arq);
                        return funcionario;
                    }else{
                        char op[10];
                        printf("\n\tESSE É O FUNCIONÁRIO QUE VOCÊ DESEJA RECUPERAR?");
                        system("clear||cls");
                        exibe_funcionario(funcionario);
                        printf("\n\t1-(SIM) OU 0-(NÃO) >>> "); fgets(op, 10, stdin); fflush(stdin);
                        int op1 = atoi(op);
                        printf("%d", op1);
                        while((op1 < 0) || (op1 > 1)){
                            system("clear||cls");
                            printf("\n\tOPÇÃO INVÁLIDA! TENTE NOVAMENTE:");
                            printf("\n\tESSE É O FUNCIONÁRIO QUE VOCÊ DESEJA RECUPERAR?\n");
                            exibe_funcionario(funcionario);
                            char op_aux[10];
                            printf("\n\n\t1-(SIM) OU 0-(NÃO) >>> "); fgets(op_aux, 10, stdin); fflush(stdin);
                            op1 = atoi(op_aux);
                        }if(op1 == 1){
                            funcionario->status = 'v';
                            fclose(arq);
                            return funcionario;
                        }
                    }
                }
            }
        }
    }
    fclose(arq);
    return NULL;
}

// Verifica se todos os dados de um determinado cliente são compatíves com o cliente que quero recuperar
void recupera_funcionario(char *arquivo, Funcionario *funcionario){
    Funcionario *funcionario_teste;
    FILE *arq;
    arq = fopen(arquivo, "r+b");
    if(arq == NULL){
        printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    funcionario_teste = (Funcionario*) malloc(sizeof(Funcionario));
    int achou = 0;
    while((!feof(arq)) && (achou == 0)) {
        fread(funcionario_teste, sizeof(Funcionario), 1, arq);
        if((strcmp(funcionario_teste->cpf, funcionario->cpf) == 0)){
            if(strcmp(funcionario_teste->data_nas, funcionario->data_nas) == 0){
                if(strcmp(funcionario_teste->email, funcionario->email) == 0){
                    if(strcmp(funcionario_teste->fone, funcionario->fone) == 0){
                        if(strcmp(funcionario_teste->nome, funcionario->nome) == 0){
                            if(strcmp(funcionario_teste->salaraio, funcionario->salaraio) == 0){
                                if(funcionario_teste->status == 'x' && funcionario->status == 'v'){
                                    achou = 1;
                                    funcionario_teste->status = 'v';
                                    fseek(arq, -1*sizeof(Funcionario), SEEK_CUR);
                                    fwrite(funcionario_teste, sizeof(Funcionario), 1, arq);
                                    printf("\n\tFUNCIONÁRIO RECUPERADO COM SUCESSO!\n");
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    fclose(arq);
    free(funcionario_teste);
}

// Verifica se um determinado CPF já está sendo usado por alguma pessoa
int verifica_2_cpfs_func(char *arquivo, Funcionario *funcionario){
    FILE *arq;
    arq = fopen(arquivo, "rb");
    if(arq == NULL){
        printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    Funcionario *funcionario_teste;
    funcionario_teste = (Funcionario*) malloc(sizeof(Funcionario));
    while((!feof(arq))){
        if(fread(funcionario_teste, sizeof(Funcionario), 1, arq)){
            if((strcmp(funcionario_teste->cpf, funcionario->cpf) == 0) && (funcionario_teste->status == 'v')){
                fclose(arq);
                free(funcionario);
                return 0;
            }
        }
    }
    fclose(arq);
    free(funcionario);
    return 1;
}

// Função que verifica se o cpf já esta sendo utilizado antes que cadastrar algum cliente
void verifica_pessoa_func(char *arquivo, char *cpf){
    int taOk = 1;
    FILE *arq;
    arq = fopen(arquivo, "rb");
    if(arq == NULL){
        taOk = 3;
    }
    if(taOk != 3){
        Funcionario *funcionario_teste;
        funcionario_teste = (Funcionario*) malloc(sizeof(Funcionario));
        while(!feof(arq)){
            if(fread(funcionario_teste, sizeof(Funcionario),1,arq)){
                if(((strcmp(funcionario_teste->cpf,cpf)) == 0) && funcionario_teste->status != 'x'){
                    taOk = 0;
                }
            }
        }
        fclose(arq);
        free(funcionario_teste);
        if(taOk == 0){
            printf("\n\tJÁ EXISTE UMA PESSOA CADASTRADA COM ESTE CPF!\n");
            char cpf_novo[100];
            printf("\tDIGITE UM NOVO CPF: (APENAS NÚMEROS)>>> ");
            fgets(cpf_novo, 100, stdin); fflush(stdin);
            strcpy(cpf, cpf_novo);
            loop_cpf(cpf);
            verifica_pessoa_func(arquivo, cpf);
        }
    }
}

void atualiza_funcionario(char *arquivo, Funcionario *func_novo){
    Funcionario *func_teste;
    FILE *arq;
    arq = fopen(arquivo, "r+b");
    if (arq == NULL) {
        printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    func_teste = (Funcionario*) malloc(sizeof(Funcionario));
    int achou = 0;
    while((!feof(arq)) && (achou == 0)) {
        fread(func_teste, sizeof(Funcionario), 1, arq);
        if((strcmp(func_teste->cpf, func_novo->cpf) == 0) && (func_teste->status != 'x')) {
            achou = 1;
            printf("\n\t>>>  PREENCHA OS NOVOS DADOS  <<<");
            printf("\n\tNOME: "); fgets(func_teste->nome, 100, stdin); fflush(stdin);
            loop_nome(func_teste->nome);
            printf("\tE-MAIL: "); fgets(func_teste->email, 200, stdin); fflush(stdin);
            loop_email(func_teste->email);
            printf("\tTELEFONE:(APENAS NÚMEROS)>>> +55 "); fgets(func_teste->fone, 100, stdin); fflush(stdin);
            loop_fone(func_teste->fone);
            printf("\tDATA DE NASCIMENTO:(dd/mm/aaaa)>>> "); 
            fgets(func_teste->data_nas, 100, stdin); fflush(stdin);
            loop_de_validacao_data(func_teste->data_nas);
            printf("\n\tSALÁRIOS: \n\t1- MEIO SALÁRIO: R$ 606,00\n\t2- UM SALÁRIO: R$ 1.212,00\n\t3- DOIS SALÁRIOS: R$ 2.424,00\n\t4- TRÊS SALÁRIOS: R$ 3.636,00");
            printf("\n\t>>> SELECIONE UM SALÁRIO: ");
            fgets(func_teste->salaraio, 20, stdin); fflush(stdin);
            loop_valor_funcionario(func_teste->salaraio);
            func_teste->status = 'v';
            fseek(arq, -1*sizeof(Funcionario), SEEK_CUR);
            fwrite(func_teste, sizeof(Funcionario), 1, arq);
        }
    }
    fclose(arq);
    free(func_teste);
}