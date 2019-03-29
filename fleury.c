#include <stdio.h>
#include <stdlib.h>

typedef struct MATRIZ Matriz;
struct MATRIZ {
  int ** adjacencia;
  int nrovertices;
  int flag;
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
  return mat;
}

int * verifica_fleury( Matriz * m, int * grau, int * maior, int * count){
  (*count) = 0;
  (*maior) = 0;
  grau = calloc(m->nrovertices, sizeof(int));
  int aux = 0;
  for (int i = 0; i < m->nrovertices; i++) {
    for (int j = 0; j < m->nrovertices; j++) {
      //printf("m[%d][%d] = %d\n", i, j, m->adjacencia[i][j]);
      if(m->adjacencia[i][j] > 0){
        (*count)++;
        aux++;
        //printf("count = %d\n", *count);
      }
    }
    if(aux % 2 == 1) {
      printf("Nao tem ciclo euleriano\n");
      return 0;
    }
    else if(aux > (*maior)) (*maior) = aux;
    grau[i] = aux;
    aux = 0;
    //printf("grau[%d] = %d\n", i, grau[i]);
  }
  return grau;
}

void DFS(Matriz * g,int v1,int* graus, int* cont){
  int v2;
  //printf("%d\n", (*cont));
  if((*cont) == 0){
    printf("%d\n", v1);
  }
  for(v2 = 0; v2 < g->nrovertices; v2++){
    if(g->adjacencia[v1][v2] == 1 && graus[v1] > 1){
      printf("%d, ",v1);
      g->adjacencia[v1][v2] = 0;
      g->adjacencia[v2][v1] = 0;
      graus[v1]--;
      (*cont)--;
      DFS(g,v2,graus,cont);
      return;
    }
    else if(graus[v1] == 1){
      if(g->adjacencia[v1][v2] == 1){
        printf("%d, ",v1);
        g->adjacencia[v1][v2] = 0;
        g->adjacencia[v2][v1] = 0;
        graus[v1]--;
        (*cont)--;
        DFS(g,v2,graus,cont);
        return;
      }
    }
  }
}


int main(int argc, char const *argv[]) {
  Matriz * m = criaMatriz(7);

  (m)->adjacencia[0][1] = 1;
  (m)->adjacencia[0][2] = 1;
  (m)->adjacencia[1][0] = 1;
  (m)->adjacencia[1][5] = 1;
  (m)->adjacencia[2][0] = 1;
  (m)->adjacencia[2][3] = 1;
  (m)->adjacencia[2][4] = 1;
  (m)->adjacencia[2][5] = 1;
  (m)->adjacencia[3][2] = 1;
  (m)->adjacencia[3][4] = 1;
  (m)->adjacencia[4][2] = 1;
  (m)->adjacencia[4][3] = 1;
  (m)->adjacencia[4][5] = 1;
  (m)->adjacencia[4][6] = 1;
  (m)->adjacencia[5][1] = 1;
  (m)->adjacencia[5][2] = 1;
  (m)->adjacencia[5][4] = 1;
  (m)->adjacencia[5][6] = 1;
  (m)->adjacencia[6][4] = 1;
  (m)->adjacencia[6][5] = 1;

  int * grau, maior, count;
  grau = verifica_fleury(m, grau, &maior, &count);
  printf("count = %d\t maior = %d\n", count, maior);

  if(grau != 0){
    for (int i = 0; i < 7; i++) {
      printf("grau[%d] = %d\n", i, grau[i]);
    }
  }
  count /= 2;
  DFS(m, maior, grau, &count);

  return 0;
}
