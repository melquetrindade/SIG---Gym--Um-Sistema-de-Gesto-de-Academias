#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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
    printf("---------------------------------------------------------------------\n");
    printf("|                           MENU PAGAMENTOS                         |\n");
    printf("---------------------------------------------------------------------\n");
    printf("|   ----------------------         ---------------------            |\n");
    printf("| 1-| REALIZAR PAGAMENTO |       2-| LISTAR PAGAMENTOS |            |\n");
    printf("|   ----------------------         ---------------------            |\n");
    printf("|   -----------------------        ---------------------            |\n");
    printf("| 3-| PESQUISAR PAGAMENTO |      4-| DELETAR PAGAMENTO |            |\n");
    printf("|   -----------------------        ---------------------            |\n");
    printf("|   --------------------------     -------------------------------- |\n");
    printf("| 5-|  PAGAMENTOS PENDENTES  |   6-| VOLTAR PARA O MENU PRINCIPAL | |\n");
    printf("|   --------------------------     -------------------------------- |\n");
    printf("---------------------------------------------------------------------\n");
    printf("\n");
    printf(">>> ESCOLHA UMA OPÇÃO: "); fgets(op, 3, stdin); fflush(stdin);
    int x = atoi(op);
    return x;
}

int mensalidades(void){ // Tela do módulo de mensalidades
    setlocale(LC_ALL,"Portuguese");
    char op[3];

    printf("----------------------------------------------------------------------\n");
    printf("|                  MENU MENSALIDADES                                 |\n");
    printf("----------------------------------------------------------------------\n");
    printf("|   -----------------------       ---------------------              |\n");
    printf("| 1-| REGISTRAR PAGAMENTO |     2-| LISTAR PAGAMENTOS |              |\n");
    printf("|   -----------------------       ---------------------              |\n");
    printf("|   -----------------------       ---------------------              |\n");
    printf("| 3-| PESQUISAR PAGAMENTO |     4-| DELETAR PAGAMENTO |              |\n");
    printf("|   -----------------------       ---------------------              |\n");
    printf("|   --------------------------      -------------------------------- |\n");
    printf("| 5-| MENSALIDADES PENDENTES |    6-| VOLTAR PARA O MENU PRINCIPAL | |\n");
    printf("|   --------------------------      -------------------------------- |\n");
    printf("----------------------------------------------------------------------\n");
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
    printf("|   --------------------------------                   |\n");
    printf("| 3-| VOLTAR PARA O MENU PRINCIPAL |                   |\n");
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
    int opcoes[6] = {1,2,3,4,5,6};    // para os módulos 3 e 4
    for(int i = 0; i<=5; i++){
        if(opcao == opcoes[i]){
            return opcao;
        }
    }
    system("clear||cls");
    return 0;
}

int verifica_opcao_3(int opcao){     // Verifica se a opção escolhida é válida
    int opcoes[3] = {1,2,3};        // para o módulo 5
    for(int i = 0; i<=2; i++){
        if(opcao == opcoes[i]){
            return opcao;
        }
    }
    system("clear||cls");
    return 0;
}

// ========================= FUNÇÕES DO MÓDULO DE CLIENTES ==================

void cadastrar_clientes(void){ // Função de cadastrar clientes
    system("clear||cls");

    printf("\t===================================\n");
    printf("\t|         Módulo de Cadastro      |\n");
    printf("\t===================================\n");

    char cpf[30], nome[100], email[100], fone[30], data_nas[30];

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

void deletar_clientes(void){  // Função de deletar clientes
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

void recuperar_clientes(void){ // Função de recuperar Clientes
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

void pesquisar_clientes(void){ // Função de pesquisar clientes
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

void atualizar_clientes(void){ // Função de atualizar clientes
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

void listar_clientes(void){ // Função de listar clientes
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

// ========================= FUNÇÕES DO MÓDULO DE FUNCIONÁRIOS ==================

void cadastrar_funcionario(void){ // Função de cadastrar funcionários
    system("clear||cls");

    printf("\t===================================\n");
    printf("\t|         Módulo de Cadastro      |\n");
    printf("\t===================================\n");
    printf("\t| CPF:(APENAS NÚMEROS)            |\n");
    printf("\t| NOME COMPLETO:                  |\n");
    printf("\t| E-MAIL:                         |\n");
    printf("\t| TELEFONE:(APENAS NÚMEROS)       |\n");
    printf("\t| DATA DE NASCIMENTO:(dd/mm/aaaa) |\n");
    printf("\t===================================\n");

    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void deletar_funcionario(void){ // Função de deletar funcionários
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

void recuperar_funcionario(void){ // Função de recuperar funcionários
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

void pesquisar_funcionario(void){ // Função de pesquisar funcionários
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

void atualizar_funcionario(void){ // Função de atualizar funcionários
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

void listar_funcionario(void){ // Função de listar funcionários
    system("clear||cls");

    printf("\t===================================\n");
    printf("\t|         Módulo de Listagem      |\n");
    printf("\t===================================\n");
    printf("\t| FUNCIONÁRIO 1:                  |\n");
    printf("\t| CPF: -------                    |\n");
    printf("\t| NOME COMPLETO: --------         |\n");
    printf("\t| E-MAIL: ---------               |\n");
    printf("\t| TELEFONE:--------               |\n");
    printf("\t| DATA DE NASCIMENTO: --------    |\n");
    printf("\t|                                 |\n");
    printf("\t| FUNCIONÁRIO 2:                  |\n");
    printf("\t|              .                  |\n");
    printf("\t|              .                  |\n");
    printf("\t|              .                  |\n");
    printf("\t===================================\n");
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

// =================== FUNÇÕES DO MÓDULO DE MENSALIDADES DOS CLIENTES ==================

void registrar_mensalidade(void){ // Função de Registrar Mensalidades
    system("clear||cls");

    printf("\t=======================================\n");
    printf("\t|   Módulo de Registrar Mensalidades  |\n");
    printf("\t=======================================\n");
    printf("\t| INFORME O CPF:                      |\n");
    printf("\t| VALOR DA MENSALIDADE:               |\n");
    printf("\t=======================================\n");
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void listar_mensalidade(void){ // Função de listar as mensalidades
    system("clear||cls");

    printf("\t=======================================\n");
    printf("\t|     Módulo de Listar Mensalidades   |\n");
    printf("\t=======================================\n");
    printf("\t| MENSALIDADE 1:                      |\n");
    printf("\t| NOME DO CLIENTE: ----------         |\n");
    printf("\t| ÚLTIMO PAGAMENTO REALIZADO: ------  |\n");
    printf("\t|                                     |\n");
    printf("\t| MESALIDADE 2:                       |\n");
    printf("\t|                 .                   |\n");
    printf("\t|                 .                   |\n");
    printf("\t=======================================\n");
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void pesquisar_mensalidade(void){ // Função de pesquisar mensalidades
    system("clear||cls");

    printf("\t======================================\n");
    printf("\t|  Módulo de Pesquisar Mensalidades  |\n");
    printf("\t======================================\n");
    printf("\t| INFORME O CPF: (APENAS NÚMEROS)    |\n");
    printf("\t======================================\n");
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void deletar_mensalidades(void){ // Função de deletar mensalidades
    system("clear||cls");

    printf("\t======================================\n");
    printf("\t|   Módulo de Deletar Mensalidades   |\n");
    printf("\t======================================\n");
    printf("\t| INFORME O CPF: (APENAS NÚMEROS)    |\n");
    printf("\t======================================\n");
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void mensalidades_pendentes(void){ // Função de listar apenas as mensalidades atrasadas
    system("clear||cls");

    printf("\t=======================================\n");
    printf("\t|   Módulo de Mensalidades Pendentes  |\n");
    printf("\t=======================================\n");
    printf("\t| MENSALIDADE 1:                      |\n");
    printf("\t| NOME DO CLIENTE: ----------         |\n");
    printf("\t| ÚLTIMO PAGAMENTO REALIZADO: ------  |\n");
    printf("\t|                                     |\n");
    printf("\t| MESALIDADE 2:                       |\n");
    printf("\t|                 .                   |\n");
    printf("\t|                 .                   |\n");
    printf("\t=======================================\n");
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

// ================== FUNÇÕES DO MÓDULO DE PAGAMENTOS DOS FUNCIONÁRIOS ==================

void realizar_pagamentos(void){ // Função de realizar Pagamentos dos Funcionários
    system("clear||cls");

    printf("\t=======================================\n");
    printf("\t|     Módulo de Realizar Pagamentos   |\n");
    printf("\t=======================================\n");
    printf("\t| INFORME O CPF:                      |\n");
    printf("\t| VALOR DO SALÁRIO:                   |\n");
    printf("\t=======================================\n");
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void listar_pagamentos(void){ // Função de Listar os pagamentos dos funcionários
    system("clear||cls");

    printf("\t=======================================\n");
    printf("\t|     Módulo de Listar Pagamentos     |\n");
    printf("\t=======================================\n");
    printf("\t| SALÁRIO 1:                          |\n");
    printf("\t| NOME DO FUNCIONÁRIO: ----------     |\n");
    printf("\t| ÚLTIMO PAGAMENTO REALIZADO: ------  |\n");
    printf("\t|                                     |\n");
    printf("\t| SALÁRIO 2:                          |\n");
    printf("\t|                 .                   |\n");
    printf("\t|                 .                   |\n");
    printf("\t=======================================\n");
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void pesquisar_pagamentos(void){ // Função de Pesquisar por pagamentos
    system("clear||cls");

    printf("\t======================================\n");
    printf("\t|   Módulo de Pesquisar Pagamentos   |\n");
    printf("\t======================================\n");
    printf("\t| INFORME O CPF: (APENAS NÚMEROS)    |\n");
    printf("\t======================================\n");
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void deletar_pagamentos(void){ // Função de deletar pagamentos 
    system("clear||cls");

    printf("\t======================================\n");
    printf("\t|    Módulo de Deletar Pagamentos    |\n");
    printf("\t======================================\n");
    printf("\t| INFORME O CPF: (APENAS NÚMEROS)    |\n");
    printf("\t======================================\n");
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void pagamentos_pendentes(void){ // Função de listar apenas os salários atrasados
    system("clear||cls");

    printf("\t=======================================\n");
    printf("\t|    Módulo de Pagamentos Pendentes   |\n");
    printf("\t=======================================\n");
    printf("\t| SALÁRIO 1:                          |\n");
    printf("\t| NOME DO CLIENTE: ----------         |\n");
    printf("\t| ÚLTIMO PAGAMENTO REALIZADO: ------  |\n");
    printf("\t|                                     |\n");
    printf("\t| SALÁRIO 2:                          |\n");
    printf("\t|                 .                   |\n");
    printf("\t|                 .                   |\n");
    printf("\t=======================================\n");
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

// ======================= FUNÇÕES DO MÓDULO DE REGISTRAR ACESSO ==================

void registrar_frequencia(void){ // Função de registrar acesso
    system("clear||cls");

    printf("\t======================================\n");
    printf("\t|     Módulo de Registrar Acesso     |\n");
    printf("\t======================================\n");
    printf("\t| INFORME O CPF: (APENAS NÚMEROS)    |\n");
    printf("\t======================================\n");
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

void listar_frequencia(void){ // Função de listar frequência
    system("clear||cls");

    printf("\t=======================================\n");
    printf("\t|       Módulo de Listar Acessos      |\n");
    printf("\t=======================================\n");
    printf("\t| ------------------------------      |\n");
    printf("\t| NOME DO CLIENTE: ----------         |\n");
    printf("\t| DATA DE ACESSO: ----------          |\n");
    printf("\t| ------------------------------      |\n");
    printf("\t|                 .                   |\n");
    printf("\t|                 .                   |\n");
    printf("\t|                 .                   |\n");
    printf("\t=======================================\n");
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}

// ============= FUNÇÃO DO MÓDULO SOBRE O PROGRAMA E DESENVOLVEDORES ==================

void informes(void){
    system("clear||cls");
    tela_sobre_o_tema();
    printf("\n\tPresione <ENTER> para continuar >>> ");
    getchar();
    system("clear||cls");
    tela_equipe();
    printf("\n\tPresione <ENTER> para voltar ao menu principal >>> ");
    getchar();
    system("clear||cls");
}