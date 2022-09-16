#ifndef ARVOREB_H
#define ARVOREB_H
#define TRUE 1
#define FALSE 0
#define m 2                     //mínimo de registros
#define mm 2*m                  //máximo de registros (mm+1 é o máximo de ponteiros)

typedef struct registro{
  int chave;
}registro;

typedef struct pagina *pointer;

typedef struct pagina{
  short n;
  registro r[mm];
  pointer p[mm];
}pagina;

void cria(pointer *dic);
registro pesquisa(registro x, pointer ap);
void ins(registro reg, pointer ap, short *cresceu, registro *regRetorno, pointer *apRetorno);
void insere(registro reg, pointer *ap);
void insereNaPag(pointer ap, registro reg, pointer apDir);
void imprime(pagina *p);

#endif
