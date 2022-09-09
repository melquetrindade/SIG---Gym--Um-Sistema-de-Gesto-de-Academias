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
int verifica_opcao_1(int opcao);
int verifica_opcao_2(int opcao);
void tela_sobre_o_tema(void);
void tela_equipe(void);
void cadastrar_clientes(void);
void deletar_clientes(void);
void recuperar_clientes(void);
void pesquisar_clientes(void);
void atualizar_clientes(void);
void listar_clientes(void);

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
    printf(">>> ESCOLHA SUA OPÇÃO: "); fgets(numero, 3, stdin); fflush(stdin);
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

int registrar_acesso(void){ // Tela do módulo de registrar acesso
    setlocale(LC_ALL,"Portuguese");
    char op[3];

    printf("--------------------------------------------------------\n");
    printf("|                 MENU REGISTRAR ACESSO                |\n");
    printf("--------------------------------------------------------\n");
    printf("|   ----------------------       --------------------  |\n");
    printf("| 1-|  REGISTRAR ACESSO  |     2-|  LISTAR ACESSOS  |  |\n");
    printf("|   ----------------------       --------------------  |\n");
    printf("|   ----------------------      ---------------------  |\n");
    printf("| 3-|  PESQUISAR ACESSO  |    4-|  DELETAR ACESSOS  |  |\n");
    printf("|   ----------------------      ---------------------  |\n");
    printf("|   --------------------------------                   |\n");
    printf("| 5-| VOLTAR PARA O MENU PRINCIPAL |                   |\n");
    printf("|   --------------------------------                   |\n");
    printf("--------------------------------------------------------\n");
    printf("\n");
    printf(">>> ESCOLHA UMA OPÇÃO: "); fgets(op, 3, stdin); fflush(stdin);
    int x = atoi(op);
    return x;
}

void tela_sobre_o_tema(void){ //Tela sobre o tema
    setlocale(LC_ALL,"Portuguese");

    printf("=============================================================\n");
    printf("|                                                           |\n");
    printf("|     Universidade Federal do Rio Grande do Norte           |\n");
    printf("|        Centro de Ensino Superior do Seridó                |\n");
    printf("|       Departamento de Computação  e Tecnologia            |\n");
    printf("|          Disciplina DCT1106 -- Programação                |\n");
    printf("|          Projeto Sistema de Gestão de Academias           |\n");
    printf("|                                                           |\n");
    printf("=============================================================\n");
    printf("|      > > >  Sistema de Gestão de Academias  < < <         |\n");
    printf("|-----------------------------------------------------------|\n");
    printf("|                                                           |\n");
    printf("|  As academias utilizam sistemas de gestão para controlar  |\n");
    printf("|  dados e informações sobre seus clientes, funcionários,   |\n");
    printf("|  equipe de instrutores e gestão financeira. O presente    |\n");
    printf("|  projeto tem como objetivo propor um programa de          |\n");
    printf("|  computador que implementa funcionalidades básicas        |\n");
    printf("|  relacionadas à gestão de pessoas de uma academia,        |\n");
    printf("|  incluindo dados dos clientes, de horários de acesso,     |\n");
    printf("|  pagamento dos suas mensalidades, controle de pagamentos  |\n");
    printf("|  dos funcionários e demais receitas e despesas.           |\n");
    printf("=============================================================\n");
}

void tela_equipe(void){ // Tela sobre o desenvolvedor
    setlocale(LC_ALL,"Portuguese");

    printf(" --------------------------------------------------------------------\n");
    printf("|                                                                    |\n");
    printf("|  UFRN CERES - CAICÓ                                                |\n");
    printf("|  Projeto da Disciplica - Programação                               |\n");
    printf("|  Docente: Flavius da Luz e Gorgônio                                |\n");
    printf("|                                                                    |\n");
    printf("|  SIG-Gym: Um Sistema de Gestão de Academias                        |\n");
    printf("|                                                                    |\n");
    printf("|  Curso:                                                            |\n");
    printf("|    Bacharelado em Sistemas de Informação                           |\n");
    printf("|    Período 2 - 2022.2                                              |\n");
    printf("|                                                                    |\n");
    printf("|  Discentes:                                                        |\n");
    printf("|    Melque Rodrigues da Trindade Santos - 20220039190               |\n");
    printf("|                                                                    |\n");
    printf(" --------------------------------------------------------------------\n");
}

int verifica_opcao_1(int opcao){         // Verifica se a opção escolhida é válida
    int opcoes[7] = {1,2,3,4,5,6,7};    // para os módulos 1 e 2
    for(int i = 0; i<=6; i++){
        if(opcao == opcoes[i]){
            return opcao;
        }
    }
    system("clear||cls");
    return 0;
}

int verifica_opcao_2(int opcao){     // Verifica se a opção escolhida é válida
    int opcoes[7] = {1,2,3,4,5};    // para os módulos 3, 4 e 5
    for(int i = 0; i<=6; i++){
        if(opcao == opcoes[i]){
            return opcao;
        }
    }
    system("clear||cls");
    return 0;
}

void cadastrar_clientes(void){
    system("clear||cls");

    printf("\t===================================\n");
    printf("\t|         Módulo de Cadastro      |\n");
    printf("\t===================================\n");

    char cpf[30];
    char nome[100];
    char email[100];
    char fone[30];
    char data_nas[30];

    printf("\n\tCPF:(APENAS NÚMEROS)>>> "); fgets(cpf, 30, stdin); fflush(stdin);
    printf("\tNOME: "); fgets(nome, 100, stdin); fflush(stdin);
    printf("\tE-MAIL: "); fgets(email, 100, stdin); fflush(stdin);
    printf("\tTELEFONE:(APENAS NÚMEROS)>>> "); fgets(fone, 30, stdin); fflush(stdin);
    printf("\tDATA DE NASCIMENTO:(dd/mm/aaaa)>>> "); fgets(data_nas, 30, stdin); fflush(stdin);

    system("clear||cls");

    printf("\tCLIENTE CADASTRADO COM SUCESSO!\n");
    printf("\n\tCPF: %s", cpf);
    printf("\tNOME: %s", nome);
    printf("\tE-MAIL: %s", email);
    printf("\tTELEFONE: %s", fone);
    printf("\tDATA DE NASCIMENTO: %s", data_nas);
    
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void deletar_clientes(void){
    system("clear||cls");

    printf("\t===================================\n");
    printf("\t|         Módulo de Exclusão      |\n");
    printf("\t===================================\n");
    printf("\t| INFORME O CPF: (APENAS NÚMEROS) |\n");
    printf("\t===================================\n");
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");    
}

void recuperar_clientes(void){
    system("clear||cls");

    printf("\t===================================\n");
    printf("\t|         Módulo de Recuperar     |\n");
    printf("\t===================================\n");
    printf("\t| INFORME O CPF: (APENAS NÚMEROS) |\n");
    printf("\t===================================\n");
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void pesquisar_clientes(void){
    system("clear||cls");

    printf("\t===================================\n");
    printf("\t|         Módulo de Pesquisar     |\n");
    printf("\t===================================\n");
    printf("\t| INFORME O CPF: (APENAS NÚMEROS) |\n");
    printf("\t===================================\n");
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void atualizar_clientes(void){
    system("clear||cls");

    printf("\t===================================\n");
    printf("\t|       Módulo de Atualização     |\n");
    printf("\t===================================\n");
    printf("\t| INFORME O CPF: (APENAS NÚMEROS) |\n");
    printf("\t===================================\n");
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void listar_clientes(void){
    system("clear||cls");

    printf("\t===================================\n");
    printf("\t|         Módulo de Listagem      |\n");
    printf("\t===================================\n");
    printf("\t| CLIENTE 1:                      |\n");
    printf("\t| CPF: -------                    |\n");
    printf("\t| NOME COMPLETO: --------         |\n");
    printf("\t| E-MAIL: ---------               |\n");
    printf("\t| TELEFONE:--------               |\n");
    printf("\t| DATA DE NASCIMENTO: --------    |\n");
    printf("\t|                                 |\n");
    printf("\t| CLIENTE 2:                      |\n");
    printf("\t|              .                  |\n");
    printf("\t|              .                  |\n");
    printf("\t|              .                  |\n");
    printf("\t===================================\n");
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}