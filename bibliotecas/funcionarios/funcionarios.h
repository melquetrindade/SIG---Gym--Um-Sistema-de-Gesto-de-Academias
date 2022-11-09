typedef struct funcionario Funcionario;

struct funcionario{
    char cpf[100];
    char nome[100];
    char email[200];
    char fone[100];
    char data_nas[100];
    char salaraio[20];
    char status;
    int id[6];
};

void cadastrar_funcionario(void);
void deletar_funcionario(void);
void recuperar_funcionario(void);
void pesquisar_funcionario(void);
void atualizar_funcionario(void);
void listar_funcionario(void);
void exibe_funcionario(const Funcionario*);
Funcionario* preenche_funcionario(void);
void salvar_no_arq_func(const Funcionario *, char *);
void ler_arquivo_func(char *);
Funcionario* busca_funcionario(char *, char *);
void deleta_funcionario(char *, Funcionario *);
Funcionario* busca_func_excluido(char *, char *);
void recupera_funcionario(char *, Funcionario *);
int verifica_2_cpfs_func(char *, Funcionario *);
void verifica_pessoa_func(char *, char *);
void atualiza_funcionario(char *, Funcionario *);
void confir_excl_func(Funcionario*, FILE*, char*);
void cfrm_exclu_func_etp2(char*, char*, char*, FILE*, Funcionario*);