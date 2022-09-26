// Assinatura das funções

// Funções das telas dos módulos principais
int menu_principal(void);
int clientes(void);
int funcionarios(void);
int pagamentos(void);
int mensalidades(void);
int registrar_acesso(void);
int verifica_opcao_1(int opcao);
int verifica_opcao_2(int opcao);
int verifica_opcao_3(int opcao);
void tela_sobre_o_tema(void);
void tela_equipe(void);

// Funções do Módulo de Clientes
void cadastrar_clientes(void);
void deletar_clientes(void);
void recuperar_clientes(void);
void pesquisar_clientes(void);
void atualizar_clientes(void);
void listar_clientes(void);

// Funções do Módulo de Funcionários
void cadastrar_funcionario(void);
void deletar_funcionario(void);
void recuperar_funcionario(void);
void pesquisar_funcionario(void);
void atualizar_funcionario(void);
void listar_funcionario(void);

// Funções do Módulo de Mensalidades dos clientes
void registrar_mensalidade(void);
void listar_mensalidade(void);
void pesquisar_mensalidade(void);
void deletar_mensalidades(void);
void mensalidades_pendentes(void);

// Funções do Módulo de Pagamentos dos funcinários
void realizar_pagamentos(void);
void listar_pagamentos(void);
void pesquisar_pagamentos(void);
void deletar_pagamentos(void);
void pagamentos_pendentes(void);

// Funções do Módulo de Acesso a academia
void registrar_frequencia(void);
void listar_frequencia(void);

// Função do Módulo sobre o programa e desenvolvedores
void informes(void);