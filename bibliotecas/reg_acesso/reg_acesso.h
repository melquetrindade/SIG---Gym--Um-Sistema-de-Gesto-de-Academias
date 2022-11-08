typedef struct registro Registro;

struct registro{
    char cpf[100];
    char nome[100];
    int ult_data[6];
    char status;
};

void registrar_frequencia(void);
void listar_frequencia(void);
Registro* busca_frequencia(char *, char *);
Registro* preenche_frequencia(char *, char *);
void salvar_no_arq_registro(const Registro *, char *);
void ler_arquivo_registro(char *);
void confirma_acesso(char *, Registro *);
Registro* pesquisa_frequencia(char *, char *);
void deleta_frequencia(char *, char *);