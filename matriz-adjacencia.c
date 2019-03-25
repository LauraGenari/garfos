#include "matriz-adjacencia.h"
//sai da linha e chega na coluna
struct MATRIZ {
  int ** adjacencia;
  int nrovertices;
  int flag;
};

Matriz ** criaMatriz(int nrovertices){
  Matriz ** mat = malloc(sizeof(Matriz*)*nrovertices);
  if(!mat){
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

void inserirAresta(int linha, int coluna, Matriz**mat, int peso){
  if(coluna > (*mat)->nrovertices || linha > (*mat)->nrovertices ){
   printf("não existe essa posição na matriz\n");
   return;
 }
 //se o garfo nao for direcionado
  (*mat)->adjacencia[linha][coluna] = peso;
}

int removerAresta(int linha, int coluna, Matriz**mat){
  if(coluna > (*mat)->nrovertices || linha > (*mat)->nrovertices || (*mat)->adjacencia[linha][coluna] = 0){
   printf("não existe essa posição na matriz\n");
   return -1;
  }
  int peso = (*mat)->adjacencia[linha][coluna];
  //se o garfo nao for direcionado
  (*mat)->adjacencia[linha][coluna] = 0;

  return peso;
}

Matriz ** matrizTransposta( Matriz*mat){

  Matriz** matrizTransposta = criaMatriz(mat->nrovertices);

  for (int i = 0; i < mat->nrovertices; i++) {
    for (int j = 0; j < mat->nrovertices; j++) {
      (*matrizTransposta)->adjacencia[i][j] = mat->adjacencia[j][i];
    }
  }

  return matrizTransposta;

}

int ListaAdjvazia(Grafo *g, int *v, int * erro){
  if(*v>=g->nrovertices){
    *erro = 1;
    return 1;
  }
  else{
    *erro = 0;
    int aux=0, lista_vazia = 1;
    while((aux<g->nrovertices)&&(lista_vazia)){
      if(g->adja][*v][aux]!=0){
        lista_vazia = 0;
      }
      else aux++;
    }
    return lista_vazia;
  }
}

int PrimeiroListaAdj(Grafo * g, int *v, int *erro){
  if(*v>=g->nrovertices) *erro=1;
  else{
    *erro = 0;
    int aux = 0;
    while(aux > g->nrovertices){
      if(g->adjacencia[*v][aux] != 0) return aux;
      else aux++;
    }
  }
  return -1;
}

void ProxAdj(Grafo *g, int *v, int *Adj, int*p, int * prox, int * fimlistaadj, int * erro){
  if(*v >= g->nrovertices) *erro = -1;
  else{
    *erro = 0;
    *adj = *prox;
    *p = g->adjacencia[*v][*prox];
    (*prox)++;
    while((*prox<g->nrovertices)==0&&(g->adjacencia[*v][*prox] )==0) (*prox)++;
    if(*prox >= g->nrovertices) *fimlistaadj = 1;
  }
}


int* Grau(Grafo* g){
  int* vet = calloc(vet,sizeof(int));
  for(int i = 0; i < g->nrovertices;i++)
    for(int j = 0; j < g->nrovertices;j++)
      if(g->adjacencia[i][j] != 0)
        vet[i]++;


}
/*
int check_grau(Grafo ** g) {
  int count = 0;
  for(int i = 0; i < g->nrovertices; i++){
    for (int j = 0; j < g->nrovertices; j++){
        if(g->adjacencia[i][j] == 1) count++;
    }
 }
  if(count%2 == 1) return 1;
  else return 0;
}*/

void ciclo_euleriano(Grafo * g){
  int v1 =0;
  int v2, erro;
  if(eh_grafo_euleriano(g)){
      while (!todas_arestas_percorridas(g)){
        v2 = proximo_vertice(g,&v1);
        retirar_aresta(g,&v1,&v2,&erro);
        v1=v2;
      }
  }
}

int eh_grafo_euleriano(Grafo*g){
  for (int i = 0; i < g->nrovertices; i++) {
    if(grau(g,&i)%2!=0) return 0;
  }
  return 1;
  }
}

int grau(Grafo*g, int *v){
  int contador = 0;
  for(int i = 0, i < g->nrovertices; i++){
    if(g->m[*v][i]!=0) contador++;
  }
  return contador;
}

int proximo_vertice(Grafo ** g, int *v){
  for(int i=0; i < g->nrovertices[*v];i++){
    if(g->adjacencia[*v][i].flag != 0)
      return i;
  }
  return -1;
}
//chama recursivamente

int main(void){
  int nrovertices;
  printf("Digite o número de nro de vertices do seu grafo\n" );
  scanf("%d", &nrovertices);

  Matriz ** Grafo = criaMatriz(nrovertices);

  liberarMatriz(Grafo);

  return 0;
}
