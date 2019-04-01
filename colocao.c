#include <stdio.h>
#include <stdlib.h>

typedef struct MATRIZ Matriz;
struct MATRIZ {
  int ** adjacencia;
  int nrovertices;
  int ** flag;
};

typedef struct VETOR Vetor;
struct VETOR{
  int no;
  int grau;
  int cor;
};

Matriz * criaMatriz(int nrovertices){
  Matriz * mat = malloc(sizeof(Matriz));
  if(!mat){
    return NULL;
  }

  (mat)->nrovertices = nrovertices;
  (mat)->adjacencia = malloc(sizeof(int*)*nrovertices);
  for (int i = 0; i < nrovertices; i++) {
    (mat)->adjacencia[i] =  calloc(sizeof(int),nrovertices);
  }
  (mat)->flag = malloc(sizeof(int*)*nrovertices);
  for (int i = 0; i < nrovertices; i++) {
    (mat)->flag[i] =  calloc(sizeof(int),nrovertices);
  }

  return mat;
}

void cria_vetor(Matriz * m, Vetor * v){
   v = malloc((m->nrovertices*sizeof(Vetor)));
  int aux = 0;
  for (int i = 0; i < m->nrovertices; i++) {
    for (int j = 0; j < m->nrovertices; j++) {
      //printf("m[%d][%d] = %d\n", i, j, m->adjacencia[i][j]);
      if(m->adjacencia[i][j] > 0){
        aux++;
        //printf("aux = %d\n", aux);
      }
    }
    v[i].no = i;
    v[i].grau = aux;
    v[i].cor = 0;
    aux = 0;
    //printf("v[%d] = %d\n", i, v[i]);
  }
}

void insertionSort(Vetor * v, int n)
{
    int i, keyno, keygrau, j;
    for (i = 1; i < n; i++) {
        keyno = v[i].no;
        keygrau = v[i].grau;
        j = i - 1;

        while (j >= 0 && v[j].grau > keygrau) {
            v[j + 1].grau = v[j].grau;
            v[j + 1].no = v[j].no;
            j = j - 1;
        }
        v[j + 1].grau = keygrau;
        v[j + 1].no = keyno;
    }
}

void colore_grafo(Matriz * m, Vetor * v){
  int cor = 1;

  for (int i = m->nrovertices - 1; i >= 0; i--) {
    if(v[i].cor == 0){
      for (int j = 0; j < m->nrovertices; j++) {
        if(m->adjacencia[i][j] == 0 && v[j].cor == 0){
          v[j].cor = cor;
        }
      }
      cor++;
    }
  }
}
