#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "bibliotecas/menu_principal/menu_principal.h"
#include "bibliotecas/clientes/clientes.h"
#include "bibliotecas/funcionarios/funcionarios.h"
#include "bibliotecas/informes/informes.h"
#include "bibliotecas/mensalidades/mensalidades.h"
#include "bibliotecas/pagamentos/pagamentos.h"
#include "bibliotecas/reg_acesso/reg_acesso.h"
#include "./bibliotecas/fun_reutilizaveis/fun_reutilizaveis.h"

//  Variáveis
int entrada;
int op_menu_principal;
int op_menu_clientes;
int op_menu_funcionarios;
int op_menu_mensalidades;
int op_menu_pagamentos;
int op_menu_reg_acesso;

int main(){
    setlocale(LC_ALL,"Portuguese");
    #define true 1
    #define false 0
    entrada = true;

    while(entrada != false){
        op_menu_principal = menu_principal();
        if(op_menu_principal == 1){ // Entra no módulo de clientes
            system("clear||cls");
            op_menu_clientes = clientes();
            op_menu_clientes = verifica_opcao_1(op_menu_clientes);
            if(op_menu_clientes == 1){
                cadastrar_clientes();
            }
            else if(op_menu_clientes == 2){
                deletar_clientes();
            }
            else if(op_menu_clientes == 3){
                recuperar_clientes();
            }
            else if(op_menu_clientes == 4){
                pesquisar_clientes();
            }
            else if(op_menu_clientes == 5){
                atualizar_clientes();
            }
            else if(op_menu_clientes == 6){
                listar_clientes();
            }
            else if(op_menu_clientes == 7){
                relatorio_clientes();
            }
            else if(op_menu_clientes == 9){
                system("clear||cls");
                printf("Voltando para o menu principal...\n");
            }
            else if(op_menu_clientes == 0){
                printf("Opção Inválida, Tente Novamente:\n");
                printf("\n");
            }
        }
        else if(op_menu_principal == 2){ // Entra no módulo de funcionários
            system("clear||cls");
            op_menu_funcionarios = funcionarios();
            op_menu_funcionarios = verifica_opcao_1(op_menu_funcionarios);
            if(op_menu_funcionarios == 1){
                cadastrar_funcionario();
            }
            else if(op_menu_funcionarios == 2){
                deletar_funcionario();
            }
            else if(op_menu_funcionarios == 3){
                recuperar_funcionario();
            }
            else if(op_menu_funcionarios == 4){
                pesquisar_funcionario();
            }
            else if(op_menu_funcionarios == 5){
                atualizar_funcionario();
            }
            else if(op_menu_funcionarios == 6){
                listar_funcionario();
            }
            else if(op_menu_clientes == 7){
                relatorio_funcionarios();
            }
            else if(op_menu_funcionarios == 9){
                system("clear||cls");
                printf("Voltando para o menu principal...\n");
            }
            else if(op_menu_funcionarios == 0){
                printf("Opção Inválida, Tente Novamente:\n");
                printf("\n");
            }
        }
        else if(op_menu_principal == 3){ // Entra no módulo de mensalidades
            system("clear||cls");
            op_menu_mensalidades = mensalidades();
            op_menu_mensalidades = verifica_opcao_2(op_menu_mensalidades);
            if(op_menu_mensalidades == 1){
                registrar_mensalidade();
            }
            else if(op_menu_mensalidades == 2){
                listar_mensalidade();
            }
            else if(op_menu_mensalidades == 3){
                pesquisar_mensalidade();
            }
            else if(op_menu_mensalidades == 4){
                mensalidades_pendentes();
            }
            else if(op_menu_mensalidades == 9){
                system("clear||cls");
                printf("Voltando para o menu principal...\n");
            }
            else if(op_menu_mensalidades == 0){
                system("clear||cls");
                printf("Opção Inválida, Tente Novamente:\n");
            }
        }
        else if(op_menu_principal == 4){ // Entra no módulo de salários
            system("clear||cls");
            op_menu_pagamentos = pagamentos();
            op_menu_pagamentos = verifica_opcao_2(op_menu_pagamentos);
            if(op_menu_pagamentos == 1){
                realizar_pagamentos();
            }
            else if(op_menu_pagamentos == 2){
                listar_pagamentos();
            }
            else if(op_menu_pagamentos == 3){
                pesquisar_pagamentos();
            }
            else if(op_menu_pagamentos == 4){
                pagamentos_pendentes();
            }
            else if(op_menu_pagamentos == 9){
                system("clear||cls");
                printf("Voltando para o menu principal...\n");
            }
            else if(op_menu_pagamentos == 0){
                system("clear||cls");
                printf("Opção Inválida, Tente Novamente:\n");
            }

        }
        else if(op_menu_principal == 5){ // Entra no módulo de registrar acesso
            system("clear||cls");
            op_menu_reg_acesso = registrar_acesso();
            op_menu_reg_acesso = verifica_opcao_3(op_menu_reg_acesso);
            if(op_menu_reg_acesso == 1){
                registrar_frequencia();
            }
            else if(op_menu_reg_acesso == 2){
                listar_frequencia();
            }
            else if(op_menu_reg_acesso == 9){
                system("clear||cls");
                printf("Voltando para o menu principal...\n");
            }
            else if(op_menu_reg_acesso == 0){
                system("clear||cls");
                printf("Opção Inválida, Tente Novamente:\n");
            }

        }
        else if(op_menu_principal == 6){ // Entra no módulo de informes
            informes();
        }
        else if(op_menu_principal == 9){ // Encerra o sistema
            system("clear||cls");
            printf("Módulo de Encerramento!\n");
            entrada = false;
        }
        else{
            system("clear||cls");
            printf("Entrada inválida, tente novamente:\n");
        }
    }
    system("clear||cls");
    printf("SISTEMA ENCERRADO!\n");

    return 0;
}