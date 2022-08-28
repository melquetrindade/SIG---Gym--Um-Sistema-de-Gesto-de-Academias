#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///                  Projeto Sistema de Gestão Escolar                      ///
///////////////////////////////////////////////////////////////////////////////
///                                Semana 1                                 ///
///////////////////////////////////////////////////////////////////////////////

void menu_principal(void);
void tela_sobre_o_tema(void);
void tela_equipe(void);

void menu_principal(){
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
};

void tela_sobre_o_tema(){
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

int main(void){

    setlocale(LC_ALL,"");

    menu_principal();
    tela_sobre_o_tema();
    tela_equipe();

    return 0;
}
