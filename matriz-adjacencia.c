#include "matriz-adjacencia.h"

struct MATRIZ {
  int ** adjacencia;
  int nrovertices;
};

Matriz ** criaMatriz(int nrovertices, int * erro){
  Matriz ** mat = malloc(sizeof(Matriz*)*nrovertices);
  if(!mat){
    (*erro) = -1;
    return NULL;
  }

  (*mat)->nrovertices = nrovertices;
  (*mat)->adjacencia = malloc(sizeof(int*)*nrovertices);
  for (int i = 0; i < nrovertices; i++) {
    (*mat)->adjacencia[i] =  calloc(sizeof(int),nrovertices);
  }
  return mat;
}

void liberarMatriz(Matriz** mat){
  for (int i = 0; i < (*mat)->nrovertices; i++) {
    free((*mat)->adjacencia[i]);
  }
  free((*mat)->adjacencia);
  free(mat);
}

void criaAresta(int linha, int coluna, Matriz**mat, int peso){
  (*mat)->adjacencia[linha][coluna] = peso;
}
