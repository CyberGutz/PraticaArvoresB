#include <stdio.h>
#include <stdlib.h>
#include "arvoreb.h"

void pesquisa(registro *x, pointer ap){

  long i = 1;

  if(ap==NULL){
    printf("Esse registro nao esta presente na arvore\n");
    return;
  }

  while(i < ap->n && x->chave > ap->r[i-1].chave)
    i++;

  if(x->chave == ap->r[i-1].chave){
    *x = ap->r[i-1];
    return;
  }

  if(x->chave < ap->r[i-1].chave)
    pesquisa(x, ap->p[i-1]);
  else
    pesquisa(x, ap->p[i]);

}

void ins(registro reg, pointer ap, short *cresceu, registro *regRetorno, pointer *apRetorno){
  long i =1;
  long j;
  pointer apTemp;

  if(ap == NULL){
    *cresceu = true;
    *regRetorno = reg;
    *apRetorno = NULL;
  }

  while(i < ap->n && reg.chave > ap->r[i-1].chave)
    i++;

  if(reg.chave == ap->r[i-1].chave){
    printf("Erro: Registro ja presente\n");
    return;
  }

  if(reg.chave < ap->r[i-1]){
    return;
  }

}
