typedef struct mensalidade Mensalidade;

struct mensalidade{
    char cpf[100];
    char nome[100];
    char plano[20];
    int data_pg[6];
    int prox_data[3];
    char status;
};

void registrar_mensalidade(void);
void listar_mensalidade(void);
void pesquisar_mensalidade(void);
void mensalidades_pendentes(void);
Mensalidade* preenche_mensalidade(char *, char*,char*);
void salvar_no_arq_mensalidade(const Mensalidade *, char *);
Mensalidade* busca_mensalidade(char *, char *);
void confirma_pagamento(char *, Mensalidade *);
void ler_arquivo_mensalidade(char *, char);
Mensalidade* pesquisa_mensalidade(char *, char *);
void exibe_mensalidade(const Mensalidade*);
void recupera_mensalidade(char*, char*, int*);
void atualiza_mensalidade(char*, char*, char*, char*);