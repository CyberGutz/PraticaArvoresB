#ifndef ARVOREB_H
#define ARVOREB_H
#define true 1
#define false 0
#define m 2                     //mínimo de registros
#define mm 2*m                  //máximo de registros (mm+1 é o máximo de ponteiros)


typedef struct registro{
  long chave;
}registro;
typedef struct pagina *pointer;
typedef struct pagina{
  short n;
  registro r[mm];
  pointer p[mm];
};

void pesquisa(int *x, pointer ap);
void ins(registro reg, pointer ap, short *cresceu, int *regRetorno, pointer *apRetorno);
void insere(registro reg, pointer *ap);
void insereNaPag(pointer ap, int reg, pointer apDir);

#endif
