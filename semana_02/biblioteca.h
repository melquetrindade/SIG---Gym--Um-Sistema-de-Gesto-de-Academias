#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int menu_principal(){
    setlocale(LC_ALL,"");

    int op;

    printf("================================================\n");
    printf("|                MENU PRINCIPAL                |\n");
    printf("================================================\n");
    printf("|                 BEM - VINDO                  |\n");
    printf("------------------------------------------------\n");
    printf("|      ------------        ----------------    |\n");
    printf("|    1-| CLIENTES |      2-| FUNCIONÁRIOS |    |\n");
    printf("|      ------------        ----------------    |\n");
    printf("|      ----------------      --------------    |\n");
    printf("|    3-| MENSALIDADES |    4-| PAGAMENTOS |    |\n");
    printf("|      ----------------      --------------    |\n");
    printf("|      --------------------     -----------    |\n");
    printf("|    5-| REGISTRAR ACESSO |   0-|  SAIR   |    |\n");
    printf("|      --------------------     -----------    |\n");
    printf("================================================\n");
    printf("\n");
    printf(">>> ESCOLHA UMA OPÇÃO: "); scanf("%d", &op); fflush(stdin);

    return op;
};

void clientes(){
    setlocale(LC_ALL,"");

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
    printf("| 0-| VOLTAR PARA O MENU PRINCIPAL |                   |\n");
    printf("|   --------------------------------                   |\n");
    printf("--------------------------------------------------------\n");

};

void funcionarios(){
    setlocale(LC_ALL,"");

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
    printf("| 0-| VOLTAR PARA O MENU PRINCIPAL |                   |\n");
    printf("|   --------------------------------                   |\n");
    printf("--------------------------------------------------------\n");
};

void pagamentos(){
    setlocale(LC_ALL,"");

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
    printf("| 0-| VOLTAR PARA O MENU PRINCIPAL |                   |\n");
    printf("|   --------------------------------                   |\n");
    printf("--------------------------------------------------------\n");
};

void mensalidades(){
    setlocale(LC_ALL,"");

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
    printf("| 0-| VOLTAR PARA O MENU PRINCIPAL |                   |\n");
    printf("|   --------------------------------                   |\n");
    printf("--------------------------------------------------------\n");
};

void registrar_acesso(){
    setlocale(LC_ALL,"");

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
    printf("| 0-| VOLTAR PARA O MENU PRINCIPAL |                   |\n");
    printf("|   --------------------------------                   |\n");
    printf("--------------------------------------------------------\n");
};

void tela_sobre_o_tema(){
    setlocale(LC_ALL,"");

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
    printf("|  dados e informções sobre seus clientes, funcionários,    |\n");
    printf("|  equipe de instrutores e gestão financeira. O presente    |\n");
    printf("|  projeto tem como objetivo propor um programa de          |\n");
    printf("|  computador que implementa funcionalidades básicas        |\n");
    printf("|  relacionadas à gestão de pessoas de uma acdemias, 	|\n");
    printf("|  incluindo dados dos clientes, de horários de acesso,     |\n");
    printf("|  pagamento dos suas mensalidades, controle de pagamentos  |\n");
    printf("|  dos funcionários e demais receitas e despesas.           |\n");
    printf("=============================================================\n");
};

void tela_equipe(){
    setlocale(LC_ALL,"");

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
};
