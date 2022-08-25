#include <stdio.h>
#include <stdlib.h>

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
    printf("===========================================================\n");
    printf("|                                                         |\n");
    printf("|     Universidade Federal do Rio Grande do Norte         |\n");
    printf("|        Centro de Ensino Superior do Seridó              |\n");
    printf("|       Departamento de Computação e Tecnologia           |\n");
    printf("|          Disciplina DCT1106 -- Programação              |\n");
    printf("|          Projeto Sistema de Gestão Escolar              |\n");
    printf("|                                                         |\n");
    printf("===========================================================\n");
    printf("|      > > >  Sistema de Gestão de Academias  < < <       |\n");
    printf("|---------------------------------------------------------|\n");
    printf("|                                                         |\n");
    printf("|  O presente projeto tem como objetivo desenvolver um    |\n");
    printf("|  programa de computador que simule um sistema de gestão |\n");
    printf("|  de academias. O mesmo possui 4 módluos principais:     |\n");
    printf("|  clientes, funcionários, mensalidades e pagamentos.     |\n");
    printf("|                                                         |\n");
    printf("===========================================================\n");
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
    printf("|    Período 1 - 2022.1                                              |\n");
    printf("|                                                                    |\n");
    printf("|  Discentes:                                                        |\n");
    printf("|    Melque Rodrigues da Trindade Santos - 20220039190               |\n");
    printf("|                                                                    |\n");
    printf(" --------------------------------------------------------------------\n");
};

int main(){

    menu_principal();
    tela_sobre_o_tema();
    tela_equipe();

    return 0;
}
