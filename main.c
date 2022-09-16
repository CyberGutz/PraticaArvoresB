#include <stdio.h>
#include <stdlib.h>
#include "arvoreb.h"

int main(){
    int option, container;
    pointer *point;
    registro search, retorno;
    registro in;
    pagina *p;

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
            cria(point);
        break;

        case 2:
            printf("*\n//ELEMENTO A SER INSERIDO -> ");
            scanf("%d*c",&container);
            in.chave = container;
            insere(in, point);
        break;

        case 3:
            printf("\n*//ELELMENTO A SER PESQUISADO -> ");
            scanf("%d*c",&container);
            search.chave = container;
            retorno = pesquisa(search, *point);
        break;

        case 4:
            imprime(p);
        break;
        
        default:
            printf("*~~~~~~~~~~~~ALTERNATIVA INVALIDA~~~~~~~~~~~~*\n");
        break;
        }
    
    } while (option != 0);
    

    exit(0);
}