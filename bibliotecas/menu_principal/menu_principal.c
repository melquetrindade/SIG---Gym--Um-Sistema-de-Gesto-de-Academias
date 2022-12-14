#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "../menu_principal/menu_principal.h"

int menu_principal(void){ // Tela principal
    setlocale(LC_ALL,"Portuguese");
    char op[20];

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
    printf("|    6-| SOBRE O PROGRAMA/DESENVOLVEDORES |   9-|  SAIR   |  |\n");
    printf("|      ------------------------------------     -----------  |\n");
    printf("==============================================================\n");
    printf("\n");
    printf(">>> ESCOLHA UMA OPÇÃO: "); fgets(op, 20, stdin); fflush(stdin);
    printf("\n");
    int x = atoi(op);
    return x;
}

int clientes(void){ // Tela do módulo de Clientes
    setlocale(LC_ALL,"Portuguese");
    char numero[20];
    printf("-----------------------------------------------------------------\n");
    printf("|                            MENU CLIENTES                      |\n");
    printf("----------------------------------------------------------------- \n");
    printf("|   -------------         -------------       -------------     |\n");
    printf("| 1-| CADASTRAR |       2-|  DELETAR  |     3-| RECUPERAR |     |\n");
    printf("|   -------------         -------------       -------------     |\n");
    printf("|   -------------         -------------       -------------     |\n");
    printf("| 4-| PESQUISAR |       5-| ATUALIZAR |     6-|  LISTAR   |     |\n");
    printf("|   ------------          -------------       -------------     |\n");
    printf("|   ----------------------     -------------------------------- |\n");
    printf("| 7-| RELATÓRIO CLIENTES |   9-| VOLTAR PARA O MENU PRINCIPAL | |\n");
    printf("|   ----------------------     -------------------------------- |\n");
    printf("-----------------------------------------------------------------\n");
    printf("\n");
    printf(">>> ESCOLHA SUA OPÇÃO: "); fgets(numero, 20, stdin); fflush(stdin);
    int x = atoi(numero);
    printf("\n");
    return x;
}

int funcionarios(void){ // Tela do módulo de funcionários
    setlocale(LC_ALL,"Portuguese");
    char op[20];

    printf("---------------------------------------------------------------------\n");
    printf("|                           MENU FUNCIONÁRIOS                       |\n");
    printf("---------------------------------------------------------------------\n");
    printf("|   -------------          -------------         -------------      |\n");
    printf("| 1-| CADASTRAR |        2-|  DELETAR  |       3-| RECUPERAR |      |\n");
    printf("|   -------------          -------------         -------------      |\n");
    printf("|   -------------          -------------         -------------      |\n");
    printf("| 4-| PESQUISAR |        5-| ATUALIZAR |       6-|  LISTAR   |      |\n");
    printf("|   ------------           -------------         -------------      |\n");
    printf("|   --------------------------     -------------------------------- |\n");
    printf("| 7-| RELATÓRIO FUNCIONÁRIOS |   9-| VOLTAR PARA O MENU PRINCIPAL | |\n");
    printf("|   --------------------------     -------------------------------- |\n");
    printf("---------------------------------------------------------------------\n");
    printf("\n");
    printf(">>> ESCOLHA UMA OPÇÃO: "); fgets(op, 20, stdin); fflush(stdin);
    int x = atoi(op);
    return x;
}

int pagamentos(void){ // Tela do módulo de pagamentos
    setlocale(LC_ALL,"Portuguese");
    char op[20];
    printf("----------------------------------------------------------------------\n");
    printf("|                            MENU PAGAMENTOS                         |\n");
    printf("----------------------------------------------------------------------\n");
    printf("|   ----------------------       ------------------------------      |\n");
    printf("| 1-| REALIZAR PAGAMENTO |     2-| LISTAR TODOS OS PAGAMENTOS |      |\n");
    printf("|   ----------------------       ------------------------------      |\n");
    printf("|   -----------------------      -------------------------------     |\n");
    printf("| 3-| PESQUISAR PAGAMENTO |    4-| LISTAR PAGAMENTOS PENDENTES |     |\n");
    printf("|   -----------------------      -------------------------------     |\n");
    printf("|   --------------------------------                                 |\n");
    printf("| 9-| VOLTAR PARA O MENU PRINCIPAL |                                 |\n");
    printf("|   --------------------------------                                 |\n");
    printf("----------------------------------------------------------------------\n");
    printf("\n");
    printf(">>> ESCOLHA UMA OPÇÃO: "); fgets(op, 20, stdin); fflush(stdin);
    int x = atoi(op);
    return x;
}

int mensalidades(void){ // Tela do módulo de mensalidades
    setlocale(LC_ALL,"Portuguese");
    char op[20];

    printf("----------------------------------------------------------------------\n");
    printf("|                           MENU MENSALIDADES                        |\n");
    printf("----------------------------------------------------------------------\n");
    printf("|   -------------------------     --------------------------------   |\n");
    printf("| 1-| REGISTRAR MENSALIDADE |   2-| LISTAR TODAS AS MENSALIDADES |   |\n");
    printf("|   -------------------------     --------------------------------   |\n");
    printf("|   -------------------------     ---------------------------------  |\n");
    printf("| 3-| PESQUISAR MENSALIDADE |   4-| LISTAR MENSALIDADES PENDENTES |  |\n");
    printf("|   -------------------------     ---------------------------------  |\n");
    printf("|   --------------------------------                                 |\n");
    printf("| 9-| VOLTAR PARA O MENU PRINCIPAL |                                 |\n");
    printf("|   --------------------------------                                 |\n");
    printf("----------------------------------------------------------------------\n");
    printf("\n");
    printf(">>> ESCOLHA UMA OPÇÃO: "); fgets(op, 20, stdin); fflush(stdin);
    int x = atoi(op);
    return x;
}

int registrar_acesso(void){ // Tela do módulo de registrar acesso
    setlocale(LC_ALL,"Portuguese");
    char op[20];

    printf("--------------------------------------------------------\n");
    printf("|                 MENU REGISTRAR ACESSO                |\n");
    printf("--------------------------------------------------------\n");
    printf("|   ----------------------       --------------------  |\n");
    printf("| 1-|  REGISTRAR ACESSO  |     2-|  LISTAR ACESSOS  |  |\n");
    printf("|   ----------------------       --------------------  |\n");
    printf("|   --------------------------------                   |\n");
    printf("| 9-| VOLTAR PARA O MENU PRINCIPAL |                   |\n");
    printf("|   --------------------------------                   |\n");
    printf("--------------------------------------------------------\n");
    printf("\n");
    printf(">>> ESCOLHA UMA OPÇÃO: "); fgets(op, 20, stdin); fflush(stdin);
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
    int opcoes[8] = {1,2,3,4,5,6,7,9};   // para os módulos 1 e 2
    for(int i = 0; i<=7; i++){
        if(opcao == opcoes[i]){
            return opcao;
        }
    }
    system("clear||cls");
    return 0;
}

int verifica_opcao_2(int opcao){     // Verifica se a opção escolhida é válida
    int opcoes[5] = {1,2,3,4,9};    // para os módulos 3 e 4
    for(int i = 0; i<=4; i++){
        if(opcao == opcoes[i]){
            return opcao;
        }
    }
    system("clear||cls");
    return 0;
}

int verifica_opcao_3(int opcao){     // Verifica se a opção escolhida é válida
    int opcoes[3] = {1,2,9};        // para o módulo 5
    for(int i = 0; i<=2; i++){
        if(opcao == opcoes[i]){
            return opcao;
        }
    }
    system("clear||cls");
    return 0;
}