typedef struct cliente Cliente;

struct cliente{
    char cpf[100];
    char nome[100];
    char email[200];
    char fone[100];
    char data_nas[100];
    char plano[20];
    char status;
    int id[6];
    Cliente *prox;
};

// Assinaturas
void cadastrar_clientes(void);
void deletar_clientes(void);
void recuperar_clientes(void);
void pesquisar_clientes(void);
void atualizar_clientes(void);
void listar_clientes(void);
void relatorio_clientes(void);
void exibe_cliente(const Cliente*);
void salvar_no_arq_cliente(const Cliente *, char *);
Cliente* preenche_cliente(char *);
void ler_arquivo_cliente(char *);
Cliente* busca_cliente(char *, char *);
void deleta_cliente(char *, Cliente *);
Cliente* busca_clnt_excluido(char *, char *);
void recupera_cliente(char *, Cliente *, char*, char*);
int verifica_2_cpfs(char *, Cliente *);
void verifica_pessoa_cliente(char * ,char *);
void atualiza_cliente(char *, Cliente *);
void confir_excl_cliente(Cliente *, FILE *, char *, char*);
void cfrm_exclu_clnt_etp2(char*, char *, char *, FILE *, Cliente *, char *, char*);
void ler_por_plano(char *, char* );
void lista_plano(char *, int, char*, char*);
void lista_clientes(char *, int, char*, char*);
void lista_idade(char *, int*);
void exibe_clnt_cplt(const Cliente*, int*, int*, int*, int);
void processo_relatorio(Cliente*, char*, char*, int*, int);
void lista_dnmc_direta_clnt(int, int, char*);
void processo_lista_dmc_clt(int, int, Cliente*, Cliente*);
void lista_dmc_plano_clt(int, Cliente*, Cliente*, char*);
void lista_dinamica_clnt(int);
void lista_dnmc_direta2_clnt(int*);
void lista_dmc_idade_clnt(int, Cliente*, Cliente*, int*);