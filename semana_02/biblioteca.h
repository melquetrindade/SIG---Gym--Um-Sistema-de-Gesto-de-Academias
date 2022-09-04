#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Assinatura das funções
int menu_principal(void);
int clientes(void);
int funcionarios(void);
int pagamentos(void);
int mensalidades(void);
int registrar_acesso(void);
int verifica_opcao(int opcao);
void tela_sobre_o_tema(void);
void tela_equipe(void);

int menu_principal(void){ // Tela principal
    setlocale(LC_ALL,"Portuguese");
    char op[3];

    printf("==============================================================\n");
    printf("|                       MENU PRINCIPAL                       |\n");
    printf("==============================================================\n");
    printf("|                        BEM - VINDO                         |\n");
    printf("--------------------------------------------------------------\n");
    printf("|      ------------     ----------------     --------------- |\n");
    printf("|    1-| CLIENTES |   2-| FUNCIONÁRIOS |   3-| MENSALIDADE | |\n");
    printf("|      ------------     ----------------     --------------- |\n");
    printf("|      --------------      --------------------              |\n");
    printf("|    4-| PAGAMENTOS |    5-| REGISTRAR ACESSO |              |\n");
    printf("|      --------------      --------------------              |\n");
    printf("|      ------------------------------------     -----------  |\n");
    printf("|    6-| SOBRE O PROGRAMA/DESENVOLVEDORES |   7-|  SAIR   |  |\n");
    printf("|      ------------------------------------     -----------  |\n");
    printf("==============================================================\n");
    printf("\n");
    printf(">>> ESCOLHA UMA OPÇÃO: "); fgets(op, 3, stdin); fflush(stdin);
    printf("\n");
    int x = atoi(op);
    return x;
}

int clientes(void){ // Tela de Clientes
    setlocale(LC_ALL,"Portuguese");
    char numero[3];
    printf("--------------------------------------------------------\n");
    printf("|                       MENU CLIENTES                  |\n");
    printf("--------------------------------------------------------\n");
    printf("|   -------------      -----------      -------------  |\n");
    printf("| 1-| CADASTRAR |    2-| DELETAR |    3-| RECUPERAR |  |\n");
    printf("|   -------------      -----------      -------------  |\n");
    printf("|   -------------      -------------    -------------  |\n");
    printf("| 4-| PESQUISAR |    5-| ATUALIZAR |  6-|  LISTAR   |  |\n");
    printf("|   ------------       -------------    -------------  |\n");
    printf("|   --------------------------------                   |\n");
    printf("| 7-| VOLTAR PARA O MENU PRINCIPAL |                   |\n");
    printf("|   --------------------------------                   |\n");
    printf("--------------------------------------------------------\n");
    printf("\n");
    printf(">>> ESCOLHA SUA OPÇÃO:"); fgets(numero, 3, stdin); fflush(stdin);
    int x = atoi(numero);
    printf("\n");
    return x;
}

int funcionarios(void){ // Tela do módulo de funcionários
    setlocale(LC_ALL,"Portuguese");
    char op[3];

    printf("--------------------------------------------------------\n");
    printf("|                   MENU FUNCIONÁRIOS                  |\n");
    printf("--------------------------------------------------------\n");
    printf("|   -------------      -----------      -------------  |\n");
    printf("| 1-| CADASTRAR |    2-| DELETAR |    3-| RECUPERAR |  |\n");
    printf("|   -------------      -----------      -------------  |\n");
    printf("|   -------------      -------------    -------------  |\n");
    printf("| 4-| PESQUISAR |    5-| ATUALIZAR |  6-|  LISTAR   |  |\n");
    printf("|   ------------       -------------    -------------  |\n");
    printf("|   --------------------------------                   |\n");
    printf("| 7-| VOLTAR PARA O MENU PRINCIPAL |                   |\n");
    printf("|   --------------------------------                   |\n");
    printf("--------------------------------------------------------\n");
    printf("\n");
    printf(">>> ESCOLHA UMA OPÇÃO: "); fgets(op, 3, stdin); fflush(stdin);
    int x = atoi(op);
    return x;
}

int pagamentos(void){ // Tela do módulo de pagamentos
    setlocale(LC_ALL,"Portuguese");
    char op[3];
    printf("--------------------------------------------------------\n");
    printf("|                    MENU PAGAMENTOS                   |\n");
    printf("--------------------------------------------------------\n");
    printf("|   ----------------------      ---------------------  |\n");
    printf("| 1-| REALIZAR PAGAMENTO |    2-| LISTAR PAGAMENTOS |  |\n");
    printf("|   ----------------------      ---------------------  |\n");
    printf("|   -----------------------     ---------------------  |\n");
    printf("| 3-| PESQUISAR PAGAMENTO |   4-| DELETAR PAGAMENTO |  |\n");
    printf("|   -----------------------     ---------------------  |\n");
    printf("|   --------------------------------                   |\n");
    printf("| 5-| VOLTAR PARA O MENU PRINCIPAL |                   |\n");
    printf("|   --------------------------------                   |\n");
    printf("--------------------------------------------------------\n");
    printf("\n");
    printf(">>> ESCOLHA UMA OPÇÃO: "); fgets(op, 3, stdin); fflush(stdin);
    int x = atoi(op);
    return x;
}

int mensalidades(void){ // Tela do módulo de mensalidades
    setlocale(LC_ALL,"Portuguese");
    char op[3];

    printf("--------------------------------------------------------\n");
    printf("|                  MENU MENSALIDADES                   |\n");
    printf("--------------------------------------------------------\n");
    printf("|   -----------------------     ---------------------  |\n");
    printf("| 1-| REGISTRAR PAGAMENTO |   2-| LISTAR PAGAMENTOS |  |\n");
    printf("|   -----------------------     ---------------------  |\n");
    printf("|   -----------------------     ---------------------  |\n");
    printf("| 3-| PESQUISAR PAGAMENTO |   4-| DELETAR PAGAMENTO |  |\n");
    printf("|   -----------------------     ---------------------  |\n");
    printf("|   --------------------------------                   |\n");
    printf("| 5-| VOLTAR PARA O MENU PRINCIPAL |                   |\n");
    printf("|   --------------------------------                   |\n");
    printf("--------------------------------------------------------\n");
    printf("\n");
    printf(">>> ESCOLHA UMA OPÇÃO: "); fgets(op, 3, stdin); fflush(stdin);
    int x = atoi(op);
    return x;
}