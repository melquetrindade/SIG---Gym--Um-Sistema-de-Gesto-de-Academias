#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "biblioteca.h"

///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///                  Projeto Sistema de Gestão Escolar                      ///
///////////////////////////////////////////////////////////////////////////////
///                                Semana 02                                ///
///////////////////////////////////////////////////////////////////////////////

int entrada;
int op_menu_principal;

int main(void){
    
    setlocale(LC_ALL,"");
    #define true 1
    #define false 0
    entrada = true;
    
    while(entrada != false){
        op_menu_principal = menu_principal();
        if(op_menu_principal == 1){
        	clientes();
		}
		else if(op_menu_principal == 2){
			funcionarios();
		}
		else if(op_menu_principal == 3){
			mensalidades();
		}
		else if(op_menu_principal == 4){
			pagamentos();
		}
		else if(op_menu_principal == 5){
			registrar_acesso();
		}
		else if(op_menu_principal == 0){
			printf("Módulo de Encerramento!");
			entrada = false;
		}
		else{
			printf("Entrada inválida, tente novamente:\n");
		}
    }
    printf("\nSISTEMA ENCERRADO!");

    return 0;
}
