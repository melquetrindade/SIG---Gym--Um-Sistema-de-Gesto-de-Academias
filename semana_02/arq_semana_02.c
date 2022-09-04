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
///                                Semana 02                                ///
///////////////////////////////////////////////////////////////////////////////

// variáveis
int entrada;
int op_menu_principal;
int op_menu_clientes;
int op_menu_funcionarios;
int op_menu_mensalidade;
int op_menu_pagamentos;
int op_menu_reg_acesso;

int main(void){

	setlocale(LC_ALL,"Portuguese");
    #define true 1
    #define false 0
    entrada = true;

    while(entrada != false){
        op_menu_principal = menu_principal();
        if(op_menu_principal == 1){
            system("clear||cls");
			op_menu_clientes = clientes();
			op_menu_clientes = verifica_opcao(op_menu_clientes);
            if(op_menu_clientes == 1){
                printf("Módulo de Cadastro!\n");
            }
            else if(op_menu_clientes == 2){
                printf("Módulo de Deletar!\n");
            }
            else if(op_menu_clientes == 3){
                printf("Módulo de Recuperar!\n");
            }
            else if(op_menu_clientes == 4){
                printf("Módulo de Pesquisa!\n");
            }
            else if(op_menu_clientes == 5){
                printf("Módulo de Atualização!\n");
            }
            else if(op_menu_clientes == 6){
                printf("Módulo de Relatório!\n");
            }
            else if(op_menu_clientes == 7){
				system("clear");
                printf("Voltando para o menu principal...\n");
            }
			else if(op_menu_clientes == 0){
				printf("opção inválida\n");
				printf("\n");
			}
		}
		else if(op_menu_principal == 2){
			system("clear||cls");	
		}
		else if(op_menu_principal == 3){
			system("clear||cls");
		}
		else if(op_menu_principal == 4){
			system("clear||cls");
		}
		else if(op_menu_principal == 5){
			system("clear||cls");
		}
		else if(op_menu_principal == 6){
			system("clear||cls");
		}
		else if(op_menu_principal == 7){
			system("clear||cls");
		}
		else{
			system("clear||cls");
			printf("Entrada inválida, tente novamente:\n");
		}
    }
    printf("SISTEMA ENCERRADO!\n");
    

    return 0;
}
