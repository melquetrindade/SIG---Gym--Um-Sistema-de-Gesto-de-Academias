#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "../menu_principal/menu_principal.h"
#include "informes.h"

void informes(void){ // Função de exibir os informes
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