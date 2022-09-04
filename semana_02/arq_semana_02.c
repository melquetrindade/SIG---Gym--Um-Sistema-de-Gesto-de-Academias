#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "biblioteca.h"

// Variáveis
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
        if(op_menu_principal == 1){
            system("clear||cls");
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
            printf("Módulo de Encerramento!\n");
            entrada = false;
        }
        else{
            system("clear||cls");
            printf("Entrda inválida, tente novamente:\n");
        }
    }
    printf("SISTEMA ENCERRADO!\n");

    return 0;
}