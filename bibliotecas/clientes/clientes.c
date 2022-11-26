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
            recupera_cliente(arquivo_cliente, cliente, arq_registro1, arq_mensalidade1);
        }
    }
    free(cliente);

    printf("\n\n\tPresione <ENTER> para voltar ao menu principal >>> ");
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
    int chave = 0;
    lista_clientes(arquivo_cliente, chave, arq_mensalidade1, arq_registro1);

    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void relatorio_clientes(void){ // Função de listar clientes
    system("clear||cls");

    printf("\t===================================\n");
    printf("\t|         Módulo de Relatório     |\n");
    printf("\t===================================\n");
    int chave = 1;
    lista_clientes(arquivo_cliente, chave, arq_mensalidade1, arq_registro1);

    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

// Função exibe o cliente cadastrado
void exibe_cliente(const Cliente* cliente){
    printf("\n\tCPF: %s", cliente->cpf);
    printf("\tNOME: %s", cliente->nome);
    printf("\tE-MAIL: %s", cliente->email);
    printf("\tTELEFONE: +55 %s", cliente->fone);
    printf("\tDATA DE NASCIMENTO: %s", cliente->data_nas);
    printf("\tPLANO: R$ %s", cliente->plano);
}

// Função que salva no arquivo de clientes
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

// Função que preenche os dados do cliente
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
    cliente->id[0]=0;cliente->id[1]=0;cliente->id[2]=0;cliente->id[3]=0;cliente->id[4]=0;cliente->id[5]=0;
    return cliente;
}

// Função que faz a leitura do arquivo clientes
void ler_arquivo_cliente(char *arquivo){
    system("clear||cls");
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

// Função auxiliar de deleta cliente etapa 1
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
            printf("\n\n\tDESEJA REALMENTE EXCLUIR? 1-(SIM) OU 2-(NÃO) >>> "); fgets(op,15,stdin); fflush(stdin);
            cfrm_exclu_clnt_etp2(mensa_teste->cpf, op, arq_mensa, arq, cliente_teste, arq3, frequencia->cpf);
        }
        else{
            char op[15];
            system("clear||cls");
            exibe_cliente(cliente_teste);
            printf("\n\n\tDESEJA REALMENTE EXCLUIR? 1-(SIM) OU 2-(NÃO) >>> "); fgets(op, 15, stdin); fflush(stdin);
            cfrm_exclu_clnt_etp2(mensa_teste->cpf, op, arq_mensa, arq, cliente_teste, arq3, frequencia->cpf);
        }
    }
    free(mensa_teste);
    free(frequencia);
}

// Função auxiliar de deleta cliente etapa 2
void cfrm_exclu_clnt_etp2(char *mensa_cpf, char *op, char *arq2, FILE *arq, Cliente *cliente_teste, char *arq3, char *freq_cpf){
    int op1 = atoi(op);
    while((op1 < 1) || (op1 > 2)){
        system("clear||cls");
        printf("\n\tOPÇÃO INVÁLIDA! TENTE NOVAMENTE:");
        char op_aux[10];
        printf("\n\n\tDESEJA REALMENTE EXCLUIR? 1-(SIM) OU 2-(NÃO) >>> "); fgets(op_aux, 10, stdin); fflush(stdin);
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
        deleta_frequencia(arq3, freq_cpf,mensa_busca->data_pg);
        cliente_teste->id[0]=mensa_busca->data_pg[0];cliente_teste->id[1]=mensa_busca->data_pg[1];cliente_teste->id[2]=mensa_busca->data_pg[2];cliente_teste->id[3]=mensa_busca->data_pg[3];cliente_teste->id[4]=mensa_busca->data_pg[4];cliente_teste->id[5]=mensa_busca->data_pg[5];
        cliente_teste->status = 'x';
        fseek(arq, -1*sizeof(Cliente), SEEK_CUR);
        fwrite(cliente_teste, sizeof(Cliente), 1, arq);
        printf("\n\tCLIENTE EXCLUÍDO COM SUCESSO!");
        fclose(arq_mensa);
        free(mensa_busca);
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
                        printf("\n\n\t1-(SIM) OU 2-(NÃO) >>> "); fgets(op, 10, stdin); fflush(stdin);
                        int op1 = atoi(op);
                        while((op1 < 1) || (op1 > 2)){
                            system("clear||cls");
                            printf("\n\tOPÇÃO INVÁLIDA! TENTE NOVAMENTE:");
                            printf("\n\tESSE É O CLIENTE QUE VOCÊ DESEJA RECUPERAR?\n");
                            exibe_cliente(cliente);
                            char op_aux[10];
                            printf("\n\n\t1-(SIM) OU 2-(NÃO) >>> "); fgets(op_aux, 10, stdin); fflush(stdin);
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
void recupera_cliente(char *arquivo, Cliente *cliente, char *arq_frenq, char *arq_mensa){
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
                                    if((cliente_teste->id[0]==cliente->id[0]) && (cliente_teste->id[1]==cliente->id[1]) && (cliente_teste->id[2]==cliente->id[2]) && (cliente_teste->id[3]==cliente->id[3]) && (cliente_teste->id[4]==cliente->id[4]) && (cliente_teste->id[5]==cliente->id[5])){
                                        achou = 1;
                                        cliente_teste->status = 'v';
                                        recupera_frequencia(arq_frenq, cliente_teste->cpf, cliente->id);
                                        recupera_mensalidade(arq_mensa, cliente_teste->cpf, cliente->id);
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

//Função que verifica se o cpf já esta sendo utilizado antes de cadastrar algum cliente
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

// Função de atualizar cliente
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
            atualiza_mensalidade(arq_mensalidade1,cliente_teste->cpf,cliente_teste->nome, cliente_teste->plano);
            atualiza_registro(arq_registro1,cliente_teste->cpf,cliente_teste->nome);
            cliente_teste->status = 'v';
            fseek(arq, -1*sizeof(Cliente), SEEK_CUR);
            fwrite(cliente_teste, sizeof(Cliente), 1, arq);
        }
    }
    fclose(arq);
    free(cliente_teste);
}

// Função que seleciona qual o tipo de mensalidade vai ser listado
void lista_plano(char *arquivo, int chave){
    system("clear||cls");
    int op1 = 0;
    do{
        char op[15];
        printf("\n\t##############################");
        printf("\n\t#   1- BÁSICO  ->  R$ 59,99  #");
        printf("\n\t#   2- MÉDIO   ->  R$ 69,99  #");
        printf("\n\t#   3- PREMIUM ->  R$ 79,99  #");
        printf("\n\t##############################");
        printf("\n\n\tSELECIONE O TIPO DE PLANO QUE DESEJA LISTAR >>> "); fgets(op,15,stdin); fflush(stdin);
        op1 = atoi(op);
        if(op1 < 1 || op1 > 3){
            system("clear||cls");
            printf("\n\tOPÇÃO INVÁLIDA, TENTE NOVAMENTE!!");

        }
    }while(op1 < 1 || op1 > 3);
    if(op1 == 1){
        system("clear||cls");
        char basico[] = {"59,99"};
        if(chave == 0){
            ler_por_plano(arquivo,basico);
        }
        else{
            printf("ainda vou fazer");
        }
    }
    else if(op1 == 2){
        system("clear||cls");
        char medio[] = {"69,99"};
        if(chave == 0){
            ler_por_plano(arquivo,medio);
        }
        else{
            printf("ainda vou fazer");
        }
    }
    else{
        system("clear||cls");
        char premium[] = {"79,99"};
        if(chave == 0){
            ler_por_plano(arquivo,premium);
        }
        else{
            printf("ainda vou fazer");
        }
    }
}

// Função que exibe os clientes com base na faixa de mensalidade selecionada
void ler_por_plano(char *arquivo, char* plano){
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
            if((strcmp(cliente->plano,plano) == 0) && (cliente->status != 'x')){
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
        printf("\n\tNÃO EXISTE NENHUM CLIENTE CADASTRADO NO SISTEMA COM ESTE PLANO!\n");
    }
    fclose(arq);
    free(cliente);
}

// Função que seleciona qual tipo de listagem vai ser exibido
void lista_clientes(char *arquivo, int chave, char *arq_mensalidade, char *arq_registro){
    int op1 = 0;
    do{
        char op[15];
        printf("\n\t#####################################");
        printf("\n\t#   1- LISTAR TODOS                 #");
        printf("\n\t#   2- LISTAR POR FAIXA ETÁRIA      #");
        printf("\n\t#   3- LISTAR POR PLANOS            #");
        printf("\n\t#####################################");
        printf("\n\n\tSELECIONE O TIPO DE LISTAGEM QUE DESEJA >>> "); 
        fgets(op,15,stdin); fflush(stdin);
        op1 = atoi(op);
        if(op1 < 1 || op1 > 3){
            system("clear||cls");
            printf("\n\tOPÇÃO INVÁLIDA, TENTE NOVAMENTE!!");

        }
    }while(op1 < 1 || op1 > 3);
    if(op1 == 1){
        if(chave == 0){
            ler_arquivo_cliente(arquivo);
        }
        else{
            relatorio_comple(arquivo, arq_mensalidade, arq_registro);
        }
    }
    else if(op1 == 2){
        int vetor_faixa[2];
        escolhe_idade(vetor_faixa);
        if(chave == 0){
            lista_idade(arquivo, vetor_faixa);
        }
        else{
            printf("ainda vou fazer");
        }
    }
    else{
        lista_plano(arquivo, chave);
    }
}

// Função que exibe os clientes com base na faixa etária selecionada
void lista_idade(char *arquivo, int *idade){
    system("clear||cls");
    FILE *arq;
    arq = fopen(arquivo, "rb");
    if (arq == NULL){
        printf("\n\tERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }
    Cliente *cliente;
    cliente = (Cliente*) malloc(sizeof(Cliente));
    int cont1 = 0;
    int cont2 = 0;
    while(!feof(arq)){
        if(fread(cliente, sizeof(Cliente),1,arq)){
            if(cliente->status == 'v'){
                int idade_cal = calcula_idade(cliente->data_nas);
                if((idade[0] <= idade_cal) && (idade_cal <= idade[1]) && (cliente->status != 'x')){
                    printf("\n\tCLIENTE %d:\n",cont2+1);
                    printf("\n\tCPF: %s", cliente->cpf);
                    printf("\tNOME: %s", cliente->nome);
                    printf("\tE-MAIL: %s", cliente->email);
                    printf("\tTELEFONE: +55 %s", cliente->fone);
                    printf("\tDATA DE NASCIMENTO: %s", cliente->data_nas);
                    printf("\tPLANO: R$ %s", cliente->plano);
                    printf("\n\t===================================\n");
                    cont2 += 1;
                }
                cont1+=1;
            }
        }
    }
    if(cont1 == 0){
        printf("\n\tNÃO EXISTE NENHUM CLIENTE CADASTRADO NO SISTEMA!\n");
    }
    if(cont2 == 0){
        printf("\n\tNÃO EXISTE NENHUM CLIENTE CADASTRADO NO SISTEMA COM ESTA FAIXA ETÁRIA!\n");
    }
    fclose(arq);
    free(cliente);
}

void relatorio_comple(char *arquivo, char *arq_mensa, char *arq_freq){
    system("clear||cls");
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
                int taOK = 0;
                Mensalidade *mensalidade;
                mensalidade = pesquisa_mensalidade(arq_mensa, cliente->cpf);
                if(mensalidade == NULL){
                    taOK = 1;
                }
                Registro *registro;
                registro = pesquisa_frequencia(arq_freq, cliente->cpf);
                if(registro == NULL){
                    taOK = 1;
                }
                if(taOK == 0){
                    exibe_clnt_cplt(cliente, registro->ult_data, mensalidade->data_pg, mensalidade->prox_data, cont);
                    cont += 1;
                }
                free(mensalidade);
                free(registro);
                taOK = 0;
            }
        }
    }
    if(cont == 0){
        printf("\n\tNÃO EXISTE NENHUM CLIENTE CADASTRADO NO SISTEMA!\n");
    }
    fclose(arq);
    free(cliente);
}

void exibe_clnt_cplt(const Cliente *cliente, int *acesso, int *data_pg, int *prox_data, int cont1){
    printf("\n\tCLIENTE %d:\n",cont1+1);
    printf("\n\tCPF: %s", cliente->cpf);
    printf("\tNOME: %s", cliente->nome);
    printf("\tE-MAIL: %s", cliente->email);
    printf("\tTELEFONE: +55 %s", cliente->fone);
    printf("\tDATA DE NASCIMENTO: %s", cliente->data_nas);
    printf("\tPLANO: R$ %s", cliente->plano);
    printf("\n\tÚLTIMO ACESSO À ACADEMIA: %d/%d/%d ás %d:%d:%d", acesso[2],acesso[1],acesso[0],acesso[3],acesso[4],acesso[5]);
    printf("\n\tÚLTIMA MENSALIDADE PAGA: %d/%d/%d", data_pg[2], data_pg[1], data_pg[0]);
    printf("\n\tPRÓXIMA MENSALIDADE: %d/%d/%d", prox_data[0], prox_data[1], prox_data[2]);
    printf("\n\t=====================================================\n");
}