typedef struct salario Salario;

struct salario{
    char cpf[100];
    char nome[100];
    char salario[20];
    int data_pg[6];
    int prox_data[3];
    char status;
};

void realizar_pagamentos(void);
void listar_pagamentos(void);
void pesquisar_pagamentos(void);
void pagamentos_pendentes(void);
Salario* busca_salario(char*, char*);
Salario* preenche_salario(char*, char*, char*);
void salvar_no_arq_salario(const Salario*, char*);
void confirma_salario(char*, Salario*);
void ler_arquivo_salario(char*, char);
Salario* pesquisa_salario(char*, char*);
void exibe_salario(const Salario*);
void recupera_salario(char*, char*, int*);
void atualiza_salario(char*, char*, char*, char*);