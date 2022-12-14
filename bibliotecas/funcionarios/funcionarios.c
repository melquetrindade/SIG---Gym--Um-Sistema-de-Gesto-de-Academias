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
    funcionario = busca_clnt_excluido1(arquivo_funcionario, cpf);
    if(funcionario == NULL){
        printf("\n\tNÃO EXISTE NENHUM FUNCIONÁRIO NA LIXEIRA DO SISTEMA COM ESTE CPF!");
    }
    else{
        int recebe = verifica_2_cpfs_func(arquivo_funcionario, funcionario);
        if(recebe == 0){
            printf("\n\tJÁ EXISTE UM FUNCIONAŔIO CADASTRADO COM ESTE CPF NO SISTEMA!");
        }
        else{
            system("clear||cls");
            recupera_funcionario(arquivo_funcionario, funcionario, arq_salario1);
        }
    }
    free(funcionario);

    printf("\n\n\tPresione <ENTER> para voltar ao menu principal >>> ");
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

    printf("\n\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void listar_funcionario(void){ // Função de listar funcionários
    system("clear||cls");

    printf("\t===================================\n");
    printf("\t|         Módulo de Listagem      |\n");
    printf("\t===================================\n");
    int chave = 0;
    lista_funcionario(arquivo_funcionario, chave, arq_salario1);

    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void relatorio_funcionarios(void){ // Função de listar clientes
    system("clear||cls");

    printf("\t===================================\n");
    printf("\t|         Módulo de Relatório     |\n");
    printf("\t===================================\n");
    int chave = 1;
    lista_funcionario(arquivo_funcionario, chave, arq_salario1);

    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

// Função exibe o funcionário cadastrado
void exibe_funcionario(const Funcionario* funcionario){
    printf("\n\tCPF: %s", funcionario->cpf);
    printf("\tNOME: %s", funcionario->nome);
    printf("\tE-MAIL: %s", funcionario->email);
    printf("\tTELEFONE: +55 %s", funcionario->fone);
    printf("\tDATA DE NASCIMENTO: %s", funcionario->data_nas);
    printf("\tSALÁRIO: R$ %s", funcionario->salaraio);
}

// Função que preenche o funcionário
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
    funcionario->id[0]=0;funcionario->id[1]=0;funcionario->id[2]=0;funcionario->id[3]=0;funcionario->id[4]=0;funcionario->id[5]=0;
    funcionario->prox = NULL;
    return funcionario;
}

// Função que salva no arquivo funcionário
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

// Função que faz a leitura do arquivo funcionário
void ler_arquivo_func(char *arquivo){
    system("clear||cls");
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

// Função que busca funcionário
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

// Função que deleta funcionário
void deleta_funcionario(char *arquivo, Funcionario *funcionario){
    Funcionario *func_teste;
    FILE *arq;
    arq = fopen(arquivo, "r+b");
    if (arq == NULL) {
        printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    func_teste= (Funcionario*) malloc(sizeof(Funcionario));
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

// Função auxiliar de deleta funcionário etapa 1
void confir_excl_func(Funcionario *func_teste, FILE *arq, char *arq_salario){
    Salario *salario_teste;
    salario_teste = pesquisa_salario(arq_salario, func_teste->cpf);
    if(salario_teste == NULL){
        printf("\n\tERRO, NÃO FOI POSSÍVEL CONTINUAR COM A OPERAÇÃO!");
        printf("\n\tO CLIENTE PRECISA TER UMA CONTA E UMA FICHA DE FREQUÊNCIA");
    }
    else{
        int atraso = cal_atraso(salario_teste->data_pg[2],salario_teste->data_pg[1],salario_teste->data_pg[0]);
        if(atraso == 1){
            char op[15];
            int dif_mes = 0;
            cal_atraso_etp2(salario_teste->data_pg[2],salario_teste->data_pg[1],salario_teste->data_pg[0], &dif_mes);
            system("clear||cls");
            exibe_funcionario(func_teste);
            printf("\n\tOBS: CLIENTE EM ATRASO! TOTAL DE MESES EM ATRASO: %d", dif_mes);
            printf("\n\n\tDESEJA REALMENTE EXCLUIR? 1-(SIM) OU 2-(NÃO) >>> "); fgets(op,15,stdin); fflush(stdin);
            cfrm_exclu_func_etp2(salario_teste->cpf, op, arq_salario, arq,func_teste);
        }
        else{
            char op[15];
            system("clear||cls");
            exibe_funcionario(func_teste);
            printf("\n\n\tDESEJA REALMENTE EXCLUIR? 1-(SIM) OU 2-(NÃO) >>> "); fgets(op, 15, stdin); fflush(stdin);
            cfrm_exclu_func_etp2(salario_teste->cpf, op, arq_salario, arq,func_teste);
        }
    }
    free(salario_teste);
}

// Função auxiliar de deleta funcionário etapa 2
void cfrm_exclu_func_etp2(char *salario_cpf, char *op, char *arq_s, FILE *arq, Funcionario *func_teste){
    int op1 = atoi(op);
    while((op1 < 1) || (op1 > 2)){
        system("clear||cls");
        printf("\n\tOPÇÃO INVÁLIDA! TENTE NOVAMENTE:");
        char op_aux[10];
        printf("\n\n\tDESEJA REALMENTE EXCLUIR? 1-(SIM) OU 2-(NÃO) >>> "); fgets(op_aux, 10, stdin); fflush(stdin);
        op1 = atoi(op_aux);
    }
    if(op1 == 1){
        FILE *arq_salario;
        Salario *salario_busca;
        arq_salario = fopen(arq_s, "r+b");
        if(arq_salario == NULL){
            printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
            exit(1);
        }
        salario_busca = (Salario*) malloc(sizeof(Salario));
        int achou = 0;
        while((!feof(arq_salario)) && (achou == 0)) {
            fread(salario_busca, sizeof(Salario), 1, arq_salario);
            if((strcmp(salario_busca->cpf, salario_cpf) == 0) && (salario_busca->status != 'x')){
                achou = 1;
                func_teste->id[0]=salario_busca->data_pg[0];func_teste->id[1]=salario_busca->data_pg[1];func_teste->id[2]=salario_busca->data_pg[2];func_teste->id[3]=salario_busca->data_pg[3];func_teste->id[4]=salario_busca->data_pg[4];func_teste->id[5]=salario_busca->data_pg[5];
                func_teste->status = 'x';
                salario_busca->status = 'x';
                fseek(arq_salario, -1*sizeof(Salario), SEEK_CUR);
                fwrite(salario_busca, sizeof(Salario), 1, arq_salario);
            }
        }
        fseek(arq, -1*sizeof(Funcionario), SEEK_CUR);
        fwrite(func_teste, sizeof(Funcionario), 1, arq);
        printf("\n\tCLIENTE EXCLUÍDO COM SUCESSO!");
        fclose(arq_salario);
        free(salario_busca);
    }
    else{
        printf("\n\tA EXCLUÇÃO FOI CANCELADA!");
    }
}

// Função que procura por algum funcionário excluído e garante que ele não está ativo antes de fazer a recuperação
Funcionario* busca_clnt_excluido1(char *arquivo, char *cpf_busca){
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
                    // exibe_funcionario(funcionario);
                    fclose(arq);
                    return funcionario;
                }
                else{
                    int recebe = verifica_2_cpfs_func(arquivo,funcionario);
                    if(recebe == 0){
                        fclose(arq);
                        return funcionario;
                    }else{
                        system("clear||cls");
                        printf("\n\tESSE É O CLIENTE QUE VOCÊ DESEJA RECUPERAR?\n");
                        exibe_funcionario(funcionario);
                        char op[10];
                        printf("\n\n\t1-(SIM) OU 2-(NÃO) >>> "); fgets(op, 10, stdin); fflush(stdin);
                        int op1 = atoi(op);
                        while((op1 < 1) || (op1 > 2)){
                            system("clear||cls");
                            printf("\n\tOPÇÃO INVÁLIDA! TENTE NOVAMENTE:");
                            printf("\n\tESSE É O CLIENTE QUE VOCÊ DESEJA RECUPERAR?\n");
                            exibe_funcionario(funcionario);
                            char op_aux[10];
                            printf("\n\n\t1-(SIM) OU 2-(NÃO) >>> "); fgets(op_aux, 10, stdin); fflush(stdin);
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

// Verifica se todos os dados de um determinado funcionário são compatíves com o funcionário que quero recuperar
void recupera_funcionario(char *arquivo, Funcionario *funcionario, char *arq_salaraio){
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
                                    recupera_salario(arq_salaraio, funcionario_teste->cpf, funcionario_teste->id);
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
                free(funcionario_teste);
                return 0;
            }
        }
    }
    fclose(arq);
    free(funcionario_teste);
    return 1;
}

// Função que verifica se o cpf já esta sendo utilizado antes que cadastrar algum funcionário
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

// Função que atualiza funcionário
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
            atualiza_salario(arq_salario1,func_teste->cpf,func_teste->nome,func_teste->salaraio);
            func_teste->status = 'v';
            fseek(arq, -1*sizeof(Funcionario), SEEK_CUR);
            fwrite(func_teste, sizeof(Funcionario), 1, arq);
        }
    }
    fclose(arq);
    free(func_teste);
}

// Função que seleciona qual o tipo de salário vai ser listado
void lista_salario(char *arquivo, int chave, char *arq_salario){
    system("clear||cls");
    int op1 = 0;
    do{
        char op[15];
        printf("\n\t#######################################");
        printf("\n\t#   1- MEIO SALÁRIO  ->  R$ 606,00    #");
        printf("\n\t#   2- UM SALÁRIO    ->  R$ 1.212,00  #");
        printf("\n\t#   3- DOIS SALÁRIOS ->  R$ 2.424,00  #");
        printf("\n\t#   4- TRÊS SALÁRIOS ->  R$ 3.636,00  #");
        printf("\n\t#######################################");
        printf("\n\n\tSELECIONE O TIPO DE PLANO QUE DESEJA LISTAR >>> "); fgets(op,15,stdin); fflush(stdin);
        op1 = atoi(op);
        if(op1 < 1 || op1 > 4){
            system("clear||cls");
            printf("\n\tOPÇÃO INVÁLIDA, TENTE NOVAMENTE!!");
        }
    }while(op1 < 1 || op1 > 4);
    if(op1 == 1){
        system("clear||cls");
        char meio[] = {"606,00"};
        if(chave == 0){
            ler_por_salario(arquivo,meio);
        }
        else{
            int op = 2;
            lista_dinamica_direta(chave, op, meio);
        }
    }
    else if(op1 == 2){
        system("clear||cls");
        char um[] = {"1.212,00"};
        if(chave == 0){
            ler_por_salario(arquivo,um);
        }
        else{
            int op = 2;
            lista_dinamica_direta(chave, op,um);
        }
    }
    else if(op1 == 3){
        system("clear||cls");
        char dois[] = {"2.424,00"};
        if(chave == 0){
            ler_por_salario(arquivo,dois);
        }
        else{
            int op = 2;
            lista_dinamica_direta(chave, op, dois);
        }
    }
    else{
        system("clear||cls");
        char tres[] = {"3.636,00"};
        if(chave == 0){
            ler_por_salario(arquivo,tres);
        }
        else{
            int op = 3;
            lista_dinamica_direta(chave, op, tres);
        }
    }
}

// Função que exibe os funcionários com base na faixa de salários selecionada
void ler_por_salario(char *arquivo, char* salario){
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
            if((strcmp(funcionario->salaraio,salario) == 0) && (funcionario->status != 'x')){
                printf("\n\tCLIENTE %d:\n",cont+1);
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
        printf("\n\tNÃO EXISTE NENHUM FUNCIONÁRIO CADASTRADO NO SISTEMA COM ESTE SALÁRIO!\n");
    }
    fclose(arq);
    free(funcionario);
}

// Função que seleciona qual tipo de listagem vai ser exibido
void lista_funcionario(char *arquivo, int chave, char *salario){
    int op1 = 0;
    do{
        char op[15];
        printf("\n\t#####################################");
        printf("\n\t#   1- LISTAR TODOS                 #");
        printf("\n\t#   2- LISTAR POR FAIXA ETÁRIA      #");
        printf("\n\t#   3- LISTAR POR SALÁRIOS          #");
        printf("\n\t#   4- LISTAR POR ORDEM ALFABÉTICA  #");
        printf("\n\t#####################################");
        printf("\n\n\tSELECIONE O TIPO DE LISTAGEM QUE DESEJA >>> "); 
        fgets(op,15,stdin); fflush(stdin);
        op1 = atoi(op);
        if(op1 < 1 || op1 > 4){
            system("clear||cls");
            printf("\n\tOPÇÃO INVÁLIDA, TENTE NOVAMENTE!!");

        }
    }while(op1 < 1 || op1 > 4);
    if(op1 == 1){
        if(chave == 0){
            ler_arquivo_func(arquivo);
        }
        else{
            int op = 1;
            char vazio[] = {""};
            lista_dinamica_direta(chave, op, vazio);
        }
    }
    else if(op1 == 2){
        int vetor_faixa[2];
        escolhe_idade(vetor_faixa);
        if(chave == 0){
            lista_idade_func(arquivo, vetor_faixa);
        }
        else{
            lista_dinamica_direta2(vetor_faixa);
        }
    }
    else if(op1 == 3){
        lista_salario(arquivo, chave, salario);
    }
    else{
        lista_dinamica(chave);
    }
}

// Função que exibe os funcionários com base na faixa etária selecionada
void lista_idade_func(char *arquivo, int *idade){
    system("clear||cls");
    FILE *arq;
    arq = fopen(arquivo, "rb");
    if (arq == NULL){
        printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    Funcionario *funcionario;
    funcionario = (Funcionario*) malloc(sizeof(Funcionario));
    int cont1 = 0;
    int cont2 = 0;
    while(!feof(arq)){
        if(fread(funcionario, sizeof(Funcionario),1,arq)){
            if(funcionario->status == 'v'){
                int idade_cal = calcula_idade(funcionario->data_nas);
                if((idade[0] <= idade_cal) && (idade_cal <= idade[1]) && (funcionario->status != 'x')){
                    printf("\n\tCLIENTE %d:\n",cont2+1);
                    printf("\n\tCPF: %s", funcionario->cpf);
                    printf("\tNOME: %s", funcionario->nome);
                    printf("\tE-MAIL: %s", funcionario->email);
                    printf("\tTELEFONE: +55 %s", funcionario->fone);
                    printf("\tDATA DE NASCIMENTO: %s", funcionario->data_nas);
                    printf("\tSALÁRIO: R$ %s", funcionario->salaraio);
                    printf("\n\t===================================\n");
                    cont2 += 1;
                }
                cont1+=1;
            }
        }
    }
    if(cont1 == 0){
        printf("\n\tNÃO EXISTE NENHUM FUNCIONÁRIO CADASTRADO NO SISTEMA!\n");
    }
    if(cont2 == 0){
        printf("\n\tNÃO EXISTE NENHUM FUNCIONÁRIO CADASTRADO NO SISTEMA COM ESTA FAIXA ETÁRIA!\n");
    }
    fclose(arq);
    free(funcionario);
}

// Função que exibe o relatório combinatório de funcionário
void exibe_func_cplt(const Funcionario *funcionario, int *data_pg, int *prox_data, int cont1){
    printf("\n\tFUNCIONÁRIO %d:\n",cont1+1);
    printf("\n\tCPF: %s", funcionario->cpf);
    printf("\tNOME: %s", funcionario->nome);
    printf("\tE-MAIL: %s", funcionario->email);
    printf("\tTELEFONE: +55 %s", funcionario->fone);
    printf("\tDATA DE NASCIMENTO: %s", funcionario->data_nas);
    printf("\tSALÁRIO: R$ %s", funcionario->salaraio);
    printf("\n\tÚLTIMO SALÁRIO PAGO: %d/%d/%d", data_pg[2], data_pg[1], data_pg[0]);
    printf("\n\tPRÓXIMO PAGAMENTO: %d/%d/%d", prox_data[0], prox_data[1], prox_data[2]);
    printf("\n\t=====================================================\n");
}

// Função que faz a junção dos arquivos refentes ao funcionário.
void processo_relatorio_func(Funcionario *funcionario, char *arq_salario, int *cont, int cont2){
    int taOK = 0;
    Salario *salario;
    salario = pesquisa_salario(arq_salario, funcionario->cpf);
    if(salario == NULL){
        taOK = 1;
    }
    if(taOK == 0){
        exibe_func_cplt(funcionario, salario->data_pg, salario->prox_data, cont2);
        *cont += 1;
    }
    free(salario);
    taOK = 0;
}

// Função que organiza a lista dinâmica em ordem alfabética
void lista_dinamica(int chave){
    system("clear||cls");
    FILE *arq;
	Funcionario* novoFunc;
	Funcionario* lista;

	arq = fopen("arq_funcionario.dat","rb");
	if(arq == NULL){
		printf("Erro na abertura do arquivo\n!");
		exit(1);
	}
    int cont1 = 0;
	lista = NULL;
	while(!feof(arq)){
        novoFunc = (Funcionario*) malloc(sizeof(Funcionario));
        if(fread(novoFunc, sizeof(Funcionario),1,arq)){
            if(novoFunc->status != 'x'){
                if (lista == NULL){
                lista = novoFunc;
                novoFunc->prox = NULL;
                }
                else if(strcmp(novoFunc->nome,lista->nome) < 0){
                    novoFunc->prox = lista;
                    lista = novoFunc;
                }
                else{
                    Funcionario* anter = lista;
                    Funcionario* atual = lista->prox;
                    while((atual != NULL) && strcmp(atual->nome,novoFunc->nome) < 0){
                        anter = atual;
                        atual = atual->prox;
                    }
                    anter->prox = novoFunc;
                    novoFunc->prox = atual;
                }
            }
            cont1 += 1;
        }
	}
	fclose(arq);
    processo_lista_dmc(chave, cont1, novoFunc, lista);
}

// Função que exibe e limpa as listas dinâmicas referente a listagem de ordem alfabética
void processo_lista_dmc(int chave, int cont1, Funcionario *novoFunc, Funcionario *lista){
    if(chave == 1){
        if(cont1 != 0){
            novoFunc = lista;
            int i = 0;
            while(novoFunc != NULL){
                processo_relatorio_func(novoFunc, arq_salario1, &i, i);
                novoFunc = novoFunc->prox;
            }
            novoFunc = lista;
            while(lista != NULL){
                lista = lista->prox;
                free(novoFunc);
                novoFunc = lista;
            }
        }
        else{
            printf("\n\tNÃO EXISTE NENHUM FUNCIONÁRIO CADASTRADO NO SISTEMA!\n");
        }
    }
    else{
        if(cont1 != 0){
            novoFunc = lista;
            int i = 0;
            while(novoFunc != NULL){
                printf("\n\tFUNCIONÁRIO %d:\n",i+1);
                exibe_funcionario(novoFunc);
                printf("\n\t========================================\n");
                novoFunc = novoFunc->prox;
                i += 1;
            }
            novoFunc = lista;
            while(lista != NULL){
                lista = lista->prox;
                free(novoFunc);
                novoFunc = lista;
            }
        }
        else{
            printf("\n\tNÃO EXISTE NENHUM FUNCIONÁRIO CADASTRADO NO SISTEMA!\n");
        }
    }
}

// Função que cria as listas dinâmicas para os retórios de listar todos e listar por salários
void lista_dinamica_direta(int chave, int op, char *salario){
    system("clear||cls");
    FILE *arq;
	Funcionario* novoFunc;
	Funcionario* lista;
	Funcionario* ultimo;

	arq = fopen("arq_funcionario.dat","rt");
	if (arq == NULL){
		printf("Erro na abertura do arquivo\n!");
		exit(1);
	}

	lista = NULL;
    int cont1 = 0;
    while(!feof(arq)){
        novoFunc = (Funcionario*) malloc(sizeof(Funcionario));
        if(fread(novoFunc, sizeof(Funcionario),1,arq)){
            if(novoFunc->status != 'x'){
                novoFunc->prox = NULL;
                if(lista == NULL){
                    lista = novoFunc;
                }
                else{
                    ultimo->prox = novoFunc;
                }
                ultimo = novoFunc;
            }
            cont1 += 1;
        }
	}
	fclose(arq);
    if(op == 1){
        processo_lista_dmc(chave, cont1, novoFunc, lista);
    }
    else{
        lista_dmc_salario(cont1, novoFunc, lista, salario);
    }
}

// Função que exibe os funcionários com base na faixa etária selecionada etapa1.
void lista_dinamica_direta2(int *vetor_data1){
    system("clear||cls");
    FILE *arq;
	Funcionario* novoFunc;
	Funcionario* lista;
	Funcionario* ultimo;

	arq = fopen("arq_funcionario.dat","rt");
	if (arq == NULL){
		printf("Erro na abertura do arquivo\n!");
		exit(1);
	}

	lista = NULL;
    int cont1 = 0;
    while(!feof(arq)){
        novoFunc = (Funcionario*) malloc(sizeof(Funcionario));
        if(fread(novoFunc, sizeof(Funcionario),1,arq)){
            if(novoFunc->status != 'x'){
                novoFunc->prox = NULL;
                if(lista == NULL){
                    lista = novoFunc;
                }
                else{
                    ultimo->prox = novoFunc;
                }
                ultimo = novoFunc;
            }
            cont1 += 1;
        }
	}
	fclose(arq);
    lista_dmc_idade(cont1, novoFunc, lista, vetor_data1);
}

// Função que exibe os funcionários com base na faixa etária selecionada etapa2.
void lista_dmc_idade(int cont1, Funcionario *novoFunc, Funcionario *lista, int *idade){
    if(cont1 != 0){
        novoFunc = lista;
        int i = 0;
        while(novoFunc != NULL){
            int idade_cal = calcula_idade(novoFunc->data_nas);
            if((idade[0] <= idade_cal) && (idade_cal <= idade[1]) && (novoFunc->status != 'x')){
                int taOK = 0;
                Salario *salario;
                salario = pesquisa_salario(arq_salario1, novoFunc->cpf);
                if(salario == NULL){
                    taOK = 1;
                }
                if(taOK == 0){
                    exibe_func_cplt(novoFunc, salario->data_pg, salario->prox_data, i);
                    i += 1;
                }
                free(salario);
                taOK = 0;
            }
            novoFunc = novoFunc->prox;
        }
        novoFunc = lista;
        while(lista != NULL){
            lista = lista->prox;
            free(novoFunc);
            novoFunc = lista;
        }
        if(i == 0){
            printf("\n\tNÃO EXISTE NENHUM FUNCIONÁRIO CADASTRADO NO SISTEMA COM ESTA FAIXA ETÁRIA!\n");
        }
    }
    else{
        printf("\n\tNÃO EXISTE NENHUM FUNCIONÁRIO CADASTRADO NO SISTEMA!\n");
    }
}

// Função que exibe os funcionários com base na faixa de salário selecionada.
void lista_dmc_salario(int cont1, Funcionario *novoFunc, Funcionario *lista, char *salario){
    if(cont1 != 0){
        novoFunc = lista;
        int i = 0;
        while(novoFunc != NULL){
            if((strcmp(novoFunc->salaraio,salario) == 0) && (novoFunc->status != 'x')){
                int taOK = 0;
                Salario *salario;
                salario = pesquisa_salario(arq_salario1, novoFunc->cpf);
                if(salario == NULL){
                    taOK = 1;
                }
                if(taOK == 0){
                    exibe_func_cplt(novoFunc, salario->data_pg, salario->prox_data, i);
                    i += 1;
                }
                free(salario);
                taOK = 0;
            }
            novoFunc = novoFunc->prox;
        }
        novoFunc = lista;
        while(lista != NULL){
            lista = lista->prox;
            free(novoFunc);
            novoFunc = lista;
        }
        if(i == 0){
            printf("\n\tNÃO EXISTE NENHUM FUNCIONÁRIO CADASTRADO NO SISTEMA COM ESTE SALÁRIO!\n");
        }
    }
    else{
        printf("\n\tNÃO EXISTE NENHUM FUNCIONÁRIO CADASTRADO NO SISTEMA!\n");
    }
}