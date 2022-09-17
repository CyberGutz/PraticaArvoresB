#include <stdio.h>
#include <stdlib.h>
#include "arvoreb.h"

void cria(pointer *dic){
  *dic = NULL;
  printf("*                                            *\n");
  printf("*~~~~~~~~PAGINA CRIADA COM SUCESSO!!!~~~~~~~~*\n");
  printf("*                                            *\n");
}

registro pesquisa(registro x, pointer ap){
  long i = 1;

  if(ap==NULL){
    printf("Esse registro nao esta presente na arvore\n");
    return x;
  }

  while(i < ap->n && x.chave > ap->r[i-1].chave)
    i++;

  if(x.chave == ap->r[i-1].chave){
    printf("O registro foi encontrado!!!\n");
    return x;
  }

  if(x.chave < ap->r[i-1].chave)
    pesquisa(x, ap->p[i-1]);
  else
    pesquisa(x, ap->p[i]);
}

void insereNaPag(pointer ap, registro reg, pointer apDir){
  short posNF;
  int k;
 
  k = ap->n;

  posNF = (k>0);

  while(posNF){
    if(reg.chave >= ap->r[k-1].chave){
      posNF = FALSE;
      break;
    }

    ap->r[k] = ap->r[k-1];
    ap->p[k+1] = ap->p[k];
    k--;

    if(k < 1)
      posNF = FALSE;
    else
      posNF = TRUE;
  }

  ap->r[k] = reg;
  ap->p[k] = apDir;
  ap->p[k+1] = apDir;
  ap->n++;
}

void ins(registro reg, pointer ap, short *cresceu, registro *regRetorno, pointer *apRetorno){
  int i,j;
  pointer apTemp;
  
  if(ap == NULL){
    (*cresceu) = TRUE;
    (*regRetorno) = reg;
    (*apRetorno) = NULL;
    return;
  }
  
  while(i < ap->n && reg.chave > ap->r[i-1].chave){
    i++;
  }

 
  if(reg.chave == ap->r[i-1].chave)
    printf("Erro: Registro ja presente\n");
  

  if(reg.chave < ap->r[i-1].chave)
    i--;

  ins(reg, ap->p[i], cresceu, regRetorno, apRetorno);

  if(!*cresceu)
    return;

  if(ap->n < mm){
    insereNaPag(ap, *regRetorno, *apRetorno);
    *cresceu = FALSE;
    return;
  }
  
  else{
    apTemp = (pointer)malloc(sizeof(pagina));
    apTemp->n = 0;
    apTemp->p[0] = NULL;

    if(i<m+1){
      insereNaPag(apTemp, ap->r[mm-1], ap->p[mm]);
      ap->n--;
      insereNaPag(ap, *regRetorno, *apRetorno);
    }

    else 
      insereNaPag(apTemp, *regRetorno, *apRetorno);
    
    for(j=m+2;j<=mm;j++){
      insereNaPag(apTemp, ap->r[j-1], ap->p[j]);
    }

    ap->n = m;
    apTemp->p[0] = ap->p[m+1];
    *regRetorno = ap->r[m];
    *apRetorno = apTemp;apTemp = (pointer)malloc(sizeof(pagina));
    apTemp->n = 0;
    apTemp->p[0] = NULL;

    if(i<mm){                       //adia o split e mantém o 1/3
      insereNaPag(apTemp, ap->r[mm-1], ap->p[mm]);
      ap->n--;
      insereNaPag(ap, *regRetorno, *apRetorno);
    }

    else 
      insereNaPag(apTemp, *regRetorno, *apRetorno);
    
    for(j=m+2;j<=mm;j++){
      insereNaPag(apTemp, ap->r[j-1], ap->p[j]);
    }

    ap->n = m;
    apTemp->p[0] = ap->p[m+1];
    *regRetorno = ap->r[m];
    *apRetorno = apTemp;
    }

  }

  void insere(registro reg, pointer *ap){
    short cresceu;
    registro regRetorno;
    pagina *apRetorno, *apTemp;
    
    ins(reg, *ap, &cresceu, &regRetorno, &apRetorno);
    
    if(cresceu){
      apTemp = (pagina *)malloc(sizeof(pagina));
      apTemp->n = 1;
      apTemp->r[0] = regRetorno;
      apTemp->p[1] = apRetorno;
      apTemp->p[0] = *ap;
      *ap = apTemp;
  }
}

void imprime(pagina *p){
  int i;

  printf("%d\n\n\n", p->n);

  if(p!=NULL){
    for(i=0; i < p->n;i++){

      printf("[%d]",p->r[i].chave);

    }

    printf("\n");

    for(i=0; i <= p->n; i++){
      imprime(p->p[i]);
    }
  }
}
