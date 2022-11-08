#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "../fun_reutilizaveis/fun_reutilizaveis.h"
#include "../menu_principal/menu_principal.h"
#include "clientes.h"
#include "../mensalidades/mensalidades.h"
#include "../reg_acesso/reg_acesso.h"

typedef struct cliente Cliente;

char arquivo_cliente[] = {"arq_cliente.dat"};
char arq_mensalidade1[] = {"arq_mensalidade.dat"};
char arq_registro1[] = {"arq_registro.dat"};

void cadastrar_clientes(void){ // Função de cadastrar clientes
    system("clear||cls");

    printf("\t===================================\n");
    printf("\t|         Módulo de Cadastro      |\n");
    printf("\t===================================\n");

    Cliente *cliente;

    cliente = preenche_cliente(arquivo_cliente);

    salvar_no_arq_cliente(cliente, arquivo_cliente);
    system("clear||cls");
    printf("\tCLIENTE CADASTRADO COM SUCESSO!\n");
    exibe_cliente(cliente);
    free(cliente);

    printf("\n\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void deletar_clientes(void){  // Função de deletar clientes
    system("clear||cls");
    Cliente *cliente;

    printf("\t===================================\n");
    printf("\t|         Módulo de Exclusão      |\n");
    printf("\t===================================\n");

    char cpf[100];

    printf("\tINFORME O CPF: (APENAS NÚMEROS) >>> "); fgets(cpf, 100, stdin); fflush(stdin);
    loop_cpf(cpf);
    cliente = busca_cliente(arquivo_cliente, cpf);
    if(cliente == NULL){
        printf("\n\tNÃO EXISTE NENHUM CLIENTE CADASTRADO COM ESTE CPF NO SISTEMA!");
    }
    else{
        deleta_cliente(arquivo_cliente, cliente);
    }
    free(cliente);

    printf("\n\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");   
}

void recuperar_clientes(void){ // Função de recuperar Clientes
    system("clear||cls");
    Cliente *cliente;

    printf("\t===================================\n");
    printf("\t|         Módulo de Recuperar     |\n");
    printf("\t===================================\n");

    char cpf[100];

    printf("\tINFORME O CPF: (APENAS NÚMEROS) >>> "); fgets(cpf, 100, stdin); fflush(stdin);
    loop_cpf(cpf);
    cliente = busca_clnt_excluido(arquivo_cliente, cpf);
    if(cliente == NULL){
        printf("\n\tO CPF QUE DESEJA RECUPERAR NÃO EXISTE NA LIXEIRA DO SISTEMA!");
    }
    else{
        int recebe = verifica_2_cpfs(arquivo_cliente, cliente);
        if(recebe == 0){
            printf("\n\tJÁ EXISTE UM CLIENTE CADASTRADO COM ESTE CPF NO SISTEMA!\n");
        }
        else{
            system("clear||cls");
            recupera_cliente(arquivo_cliente, cliente);
        }
    }
    free(cliente);

    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void pesquisar_clientes(void){ // Função de pesquisar clientes
    system("clear||cls");
    Cliente *cliente;

    printf("\t===================================\n");
    printf("\t|         Módulo de Pesquisar     |\n");
    printf("\t===================================\n");

    char cpf[100];

    printf("\tINFORME O CPF: (APENAS NÚMEROS) >>> "); fgets(cpf, 100, stdin); fflush(stdin);
    loop_cpf(cpf);
    cliente = busca_cliente(arquivo_cliente, cpf);
    if(cliente == NULL){
        printf("\n\tNÃO EXISTE NENHUM CLIENTE CADASTRADO COM ESTE CPF NO SISTEMA!");
    }
    else{
        exibe_cliente(cliente);
    }
    free(cliente);

    printf("\n\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void atualizar_clientes(void){ // Função de atualizar clientes
    system("clear||cls");
    Cliente *cliente;

    printf("\t===================================\n");
    printf("\t|       Módulo de Atualização     |\n");
    printf("\t===================================\n");

    char cpf[100];

    printf("\tINFORME O CPF: (APENAS NÚMEROS) >>> "); fgets(cpf, 100, stdin); fflush(stdin);
    loop_cpf(cpf);
    cliente = busca_cliente(arquivo_cliente, cpf);
    if(cliente == NULL){
        printf("\n\tNÃO EXISTE NENHUM CLIENTE CADASTRADO COM ESTE CPF NO SISTEMA!");
    }
    else{
        atualiza_cliente(arquivo_cliente, cliente);
        cliente = busca_cliente(arquivo_cliente, cpf);
        if(cliente == NULL){
            printf("\n\tNÃO EXISTE NENHUM CLIENTE CADASTRADO COM ESTE CPF NO SISTEMA!");
        }
        else{
            system("clear||cls");
            printf("\n\tCLIENTE ATUALIZADO COM SUCESSO!\n");
            exibe_cliente(cliente);
        }
    }
    free(cliente);

    printf("\n\n\tPresione <ENTER> para voltar ao menu principal >>> ");
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

Cliente* preenche_cliente(char *arquivo){
    Cliente *cliente;
    cliente = (Cliente*) malloc(sizeof(Cliente));
    printf("\n\tCPF:(APENAS NÚMEROS)>>> "); fgets(cliente->cpf, 100, stdin); fflush(stdin);
    loop_cpf(cliente->cpf);
    verifica_pessoa_cliente(arquivo, cliente->cpf);
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
            if(cliente->status == 'v'){
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
    }
    if(cont == 0){
        printf("\n\tNÃO EXISTE NENHUM CLIENTE CADASTRADO NO SISTEMA!\n");
    }
    fclose(arq);
    free(cliente);
}

// Função que busca cliente
Cliente* busca_cliente(char *arquivo, char *cpf_busca){
    FILE *arq;
    Cliente *cliente;
    arq = fopen(arquivo, "rb");
    if(arq == NULL){
        printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    cliente = (Cliente*) malloc(sizeof(Cliente));
    while(!feof(arq)){
        if(fread(cliente, sizeof(Cliente), 1, arq)){
            if((strcmp(cliente->cpf, cpf_busca) == 0) && (cliente->status == 'v')){
                fclose(arq);
                return cliente;
            }
        }
    }
    fclose(arq);
    return NULL;
}

// Função que deleta cliente
void deleta_cliente(char *arquivo, Cliente *cliente){
    Cliente *cliente_teste;
    FILE *arq;
    arq = fopen(arquivo, "r+b");
    if (arq == NULL) {
        printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    cliente_teste = (Cliente*) malloc(sizeof(Cliente));
    int achou = 0;
    while((!feof(arq)) && (achou == 0)) {
        fread(cliente_teste, sizeof(Cliente), 1, arq);
        if((strcmp(cliente_teste->cpf, cliente->cpf) == 0) && (cliente_teste->status != 'x')) {
            achou = 1;
            confir_excl_cliente(cliente_teste, arq, arq_mensalidade1, arq_registro1);
        }
    }
    fclose(arq);
    free(cliente_teste);
    
}

void confir_excl_cliente(Cliente *cliente_teste, FILE *arq, char *arq_mensa, char *arq3){
    Mensalidade *mensa_teste;
    mensa_teste = pesquisa_mensalidade(arq_mensa, cliente_teste->cpf);
    Registro *frequencia;
    frequencia = pesquisa_frequencia(arq_registro1, cliente_teste->cpf);
    if(mensa_teste == NULL || frequencia == NULL){
        printf("\n\tERRO, NÃO FOI POSSÍVEL CONTINUAR COM A OPERAÇÃO!");
        printf("\n\tO CLIENTE PRECISA TER UMA CONTA E UMA FICHA DE FREQUÊNCIA");
    }
    else{
        int atraso = cal_atraso(mensa_teste->data_pg[2], mensa_teste->data_pg[1], mensa_teste->data_pg[0]);
        if(atraso == 1){
            char op[15];
            int dif_mes = 0;
            cal_atraso_etp2(mensa_teste->data_pg[2], mensa_teste->data_pg[1], mensa_teste->data_pg[0], &dif_mes);
            system("clear||cls");
            exibe_cliente(cliente_teste);
            printf("\n\tOBS: CLIENTE EM ATRASO! TOTAL DE MESES EM ATRASO: %d", dif_mes);
            printf("\n\n\tDESEJA REALMENTE EXCLUIR? 1-(SIM) OU 0-(NÃO) >>> "); fgets(op,15,stdin); fflush(stdin);
            cfrm_exclu_clnt_etp2(mensa_teste->cpf, op, arq_mensa, arq, cliente_teste, arq3, frequencia->cpf);
        }
        else{
            char op[15];
            system("clear||cls");
            exibe_cliente(cliente_teste);
            printf("\n\n\tDESEJA REALMENTE EXCLUIR? 1-(SIM) OU 0-(NÃO) >>> "); fgets(op, 15, stdin); fflush(stdin);
            cfrm_exclu_clnt_etp2(mensa_teste->cpf, op, arq_mensa, arq, cliente_teste, arq3, frequencia->cpf);
        }
    }
    free(mensa_teste);
    free(frequencia);
}

void cfrm_exclu_clnt_etp2(char *mensa_cpf, char *op, char *arq2, FILE *arq, Cliente *cliente_teste, char *arq3, char *freq_cpf){
    int op1 = atoi(op);
    while((op1 < 0) || (op1 > 1)){
        system("clear||cls");
        printf("\n\tOPÇÃO INVÁLIDA! TENTE NOVAMENTE:");
        char op_aux[10];
        printf("\n\n\tDESEJA REALMENTE EXCLUIR? 1-(SIM) OU 0-(NÃO) >>> "); fgets(op_aux, 10, stdin); fflush(stdin);
        op1 = atoi(op_aux);
    }
    if(op1 == 1){
        FILE *arq_mensa;
        Mensalidade *mensa_busca;
        arq_mensa = fopen(arq2, "r+b");
        if(arq_mensa == NULL){
            printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
            exit(1);
        }
        mensa_busca = (Mensalidade*) malloc(sizeof(Mensalidade));
        int achou = 0;
        while((!feof(arq_mensa)) && (achou == 0)) {
            fread(mensa_busca, sizeof(Mensalidade), 1, arq_mensa);
            if((strcmp(mensa_busca->cpf, mensa_cpf) == 0) && (mensa_busca->status != 'x')) {
                achou = 1;
                mensa_busca->status = 'x';
                fseek(arq_mensa, -1*sizeof(Mensalidade), SEEK_CUR);
                fwrite(mensa_busca, sizeof(Mensalidade), 1, arq_mensa);
            }
        }
        fclose(arq_mensa);
        free(mensa_busca);
        deleta_frequencia(arq3, freq_cpf);
        cliente_teste->status = 'x';
        fseek(arq, -1*sizeof(Cliente), SEEK_CUR);
        fwrite(cliente_teste, sizeof(Cliente), 1, arq);
        printf("\n\tCLIENTE EXCLUÍDO COM SUCESSO!");
    }
    else{
        printf("\n\tA EXCLUÇÃO FOI CANCELADA!");
    }
}

// Função que procura por algum cliente excluído e garante que ele não está ativo antes de fazer a recuperação
Cliente* busca_clnt_excluido(char *arquivo, char *cpf_busca){
    FILE *arq;
    Cliente *cliente;
    arq = fopen(arquivo, "rb");
    if(arq == NULL){
        printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    cliente = (Cliente*) malloc(sizeof(Cliente));
    while(!feof(arq)){
        if(fread(cliente, sizeof(Cliente), 1, arq)){
            if(strcmp(cliente->cpf, cpf_busca) == 0){
                if(cliente->status == 'v'){
                    fclose(arq);
                    return cliente;
                }else{
                    int recebe = verifica_2_cpfs(arquivo,cliente);
                    if(recebe == 0){
                        fclose(arq);
                        return cliente;
                    }else{
                        char op[10];
                        system("clear||cls");
                        printf("\n\tESSE É O CLIENTE QUE VOCÊ DESEJA RECUPERAR?\n");
                        exibe_cliente(cliente);
                        printf("\n\n\t1-(SIM) OU 0-(NÃO) >>> "); fgets(op, 10, stdin); fflush(stdin);
                        int op1 = atoi(op);
                        while((op1 < 0) || (op1 > 1)){
                            system("clear||cls");
                            printf("\n\tOPÇÃO INVÁLIDA! TENTE NOVAMENTE:");
                            printf("\n\tESSE É O CLIENTE QUE VOCÊ DESEJA RECUPERAR?\n");
                            exibe_cliente(cliente);
                            char op_aux[10];
                            printf("\n\n\t1-(SIM) OU 0-(NÃO) >>> "); fgets(op_aux, 10, stdin); fflush(stdin);
                            op1 = atoi(op_aux);
                        }if(op1 == 1){
                            cliente->status = 'v';
                            fclose(arq);
                            return cliente;
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
void recupera_cliente(char *arquivo, Cliente *cliente){
    Cliente *cliente_teste;
    FILE *arq;
    arq = fopen(arquivo, "r+b");
    if(arq == NULL){
        printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    cliente_teste = (Cliente*) malloc(sizeof(Cliente));
    int achou = 0;
    while((!feof(arq)) && (achou == 0)) {
        fread(cliente_teste, sizeof(Cliente), 1, arq);
        if((strcmp(cliente_teste->cpf, cliente->cpf) == 0)){
            if(strcmp(cliente_teste->data_nas, cliente->data_nas) == 0){
                if(strcmp(cliente_teste->email, cliente->email) == 0){
                    if(strcmp(cliente_teste->fone, cliente->fone) == 0){
                        if(strcmp(cliente_teste->nome, cliente->nome) == 0){
                            if(strcmp(cliente_teste->plano, cliente->plano) == 0){
                                if(cliente_teste->status == 'x' && cliente->status == 'v'){
                                    achou = 1;
                                    cliente_teste->status = 'v';
                                    fseek(arq, -1*sizeof(Cliente), SEEK_CUR);
                                    fwrite(cliente_teste, sizeof(Cliente), 1, arq);
                                    printf("\n\tCLIENTE RECUPERADO COM SUCESSO!\n");
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    fclose(arq);
    free(cliente_teste);
}

// Verifica se um determinado CPF já está sendo usado por alguma pessoa
int verifica_2_cpfs(char *arquivo, Cliente *cliente){
    FILE *arq;
    arq = fopen(arquivo, "rb");
    if(arq == NULL){
        printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    Cliente *cliente_teste;
    cliente_teste = (Cliente*) malloc(sizeof(Cliente));
    while((!feof(arq))){
        if(fread(cliente_teste, sizeof(Cliente), 1, arq)){
            if((strcmp(cliente_teste->cpf, cliente->cpf) == 0) && (cliente_teste->status == 'v')){
                return 0;
                fclose(arq);
                free(cliente);
            }
        }
    }
    return 1;
    fclose(arq);
    free(cliente);
}

//Função que verifica se o cpf já esta sendo utilizado antes que cadastrar algum cliente
void verifica_pessoa_cliente(char *arquivo, char *cpf){
    int taOk = 1;
    FILE *arq;
    arq = fopen(arquivo, "rb");
    if(arq == NULL){
        taOk = 3;
    }
    if(taOk != 3){
        Cliente *cliente_teste;
        cliente_teste = (Cliente*) malloc(sizeof(Cliente));
        while(!feof(arq)){
            if(fread(cliente_teste, sizeof(Cliente),1,arq)){
                if(((strcmp(cliente_teste->cpf,cpf)) == 0) && cliente_teste->status != 'x'){
                    taOk = 0;
                }
            }
        }
        fclose(arq);
        free(cliente_teste);
        if(taOk == 0){
            printf("\n\tJÁ EXISTE UMA PESSOA CADASTRADA COM ESTE CPF!\n");
            char cpf_novo[100];
            printf("\tDIGITE UM NOVO CPF: (APENAS NÚMEROS)>>> ");
            fgets(cpf_novo, 100, stdin); fflush(stdin);
            strcpy(cpf, cpf_novo);
            loop_cpf(cpf);
            verifica_pessoa_cliente(arquivo, cpf);
        }
    }
}

void atualiza_cliente(char *arquivo, Cliente *cliente_novo){
    Cliente *cliente_teste;
    FILE *arq;
    arq = fopen(arquivo, "r+b");
    if (arq == NULL) {
        printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    cliente_teste = (Cliente*) malloc(sizeof(Cliente));
    int achou = 0;
    while((!feof(arq)) && (achou == 0)) {
        fread(cliente_teste, sizeof(Cliente), 1, arq);
        if((strcmp(cliente_teste->cpf, cliente_novo->cpf) == 0) && (cliente_teste->status != 'x')) {
            achou = 1;
            printf("\n\t>>>  PREENCHA OS NOVOS DADOS  <<<");
            printf("\n\tNOME: "); fgets(cliente_teste->nome, 100, stdin); fflush(stdin);
            loop_nome(cliente_teste->nome);
            printf("\tE-MAIL: "); fgets(cliente_teste->email, 200, stdin); fflush(stdin);
            loop_email(cliente_teste->email);
            printf("\tTELEFONE:(APENAS NÚMEROS)>>> +55 "); fgets(cliente_teste->fone, 100, stdin); fflush(stdin);
            loop_fone(cliente_teste->fone);
            printf("\tDATA DE NASCIMENTO:(dd/mm/aaaa)>>> "); fgets(cliente_teste->data_nas, 100, stdin); fflush(stdin);
            loop_de_validacao_data(cliente_teste->data_nas);
            printf("\n\tPLANOS: \n\t1- BÁSICO: R$ 59,99\n\t2- MÉDIO: R$ 69,99\n\t3- PREMIUM: 79,99");
            printf("\n\t>>> SELECIONE UM PLANO: ");
            fgets(cliente_teste->plano, 20, stdin); fflush(stdin);
            loop_valor_cliente(cliente_teste->plano);
            cliente_teste->status = 'v';
            fseek(arq, -1*sizeof(Cliente), SEEK_CUR);
            fwrite(cliente_teste, sizeof(Cliente), 1, arq);
        }
    }
    fclose(arq);
    free(cliente_teste);
}