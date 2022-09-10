#include <stdio.h>
#include <stdlib.h>
#include "arvoreb.h"

int main(){
    int option, container;
    pointer *p;
    registro in;

    do
    {
        printf("*~~~~~~~~~~~~~~~~~ARVORES B*~~~~~~~~~~~~~~~~~*\n");
        printf("*                                            *\n");
        printf("*                 MENU:                      *\n");
        printf("*            1-Criar Arvore                  *\n");
        printf("*            2-Inserir elemento              *\n");
        printf("*            3-Pesquisar elemento            *\n");
        printf("*            4-Imprimir Arvore               *\n");
        printf("*            0-Sair do Programa              *\n");
        printf("*                                            *\n");
        printf("*//ALTERNATIVA ESCOLHIDA -> ");
        scanf("%d*c",&option);

        switch (option)
        {
        case 0:
            printf("*~~~~~~~~~~~~~SAINDO DO PROGRAMA~~~~~~~~~~~~~*\n");
        break;

        case 1:
            cria(p);
        break;

        case 2:
            printf("*\n//ELEMENTO A SER INSERIDO -> ");
            printf("%d*c",&in);
            insere(in, p);
        break;

        case 3:
            printf("\n*//ELELMENTO A SER PESQUISADO -> ");
            scanf("%d*c",&container);
            pesquisa(container, p);
        break;

        case 4:

        break;
        
        default:
            printf("*~~~~~~~~~~~~ALTERNATIVA INVALIDA~~~~~~~~~~~~*\n");
        break;
        }
    
    } while (option != 0);
    

    exit(0);
}