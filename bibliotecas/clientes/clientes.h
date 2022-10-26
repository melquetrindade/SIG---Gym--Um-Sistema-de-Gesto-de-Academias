typedef struct cliente Cliente;

struct cliente{
    char cpf[100];
    char nome[100];
    char email[200];
    char fone[100];
    char data_nas[100];
    char plano[20];
};

void cadastrar_clientes(void);
void deletar_clientes(void);
void recuperar_clientes(void);
void pesquisar_clientes(void);
void atualizar_clientes(void);
void listar_clientes(void);
void exibe_cliente(const Cliente*);