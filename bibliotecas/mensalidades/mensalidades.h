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
void deletar_mensalidades(void);
void mensalidades_pendentes(void);
Mensalidade* busca_mensalidade(char *, char *);
Mensalidade* preenche_mensalidade(char *, char*, char *);
void salvar_no_arq_mensalidade(const Mensalidade *, char *);
void confirma_pagamento(char *, Mensalidade *);
void ler_arquivo_mensalidade(char *, char;
Mensalidade* pesquisa_mensalidade(char *, char *);
void exibe_mensalidade(const Mensalidade*);
void deleta_mensalidade(char *, Mensalidade *);
void confirma_exclucao_mensa(Mensalidade *, char *, FILE *);