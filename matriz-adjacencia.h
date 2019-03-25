#include <stdlib.h>
#include <stdio.h>

typedef struct MATRIZ Matriz;

Matriz ** criaMatriz(int nrovertices);

void liberarMatriz(Matriz** mat);

void inserirAresta(int linha, int coluna, Matriz**mat, int peso);

int removerAresta(int linha, int coluna, Matriz**mat);

Matriz ** matrizTransposta( Matriz*mat);

int ListaAdjvazia(Grafo *g, int *v, int * erro);
int PrimeiroListaAdj(Grafo * g, int *v, int *erro);

void ProxAdj(Grafo *g, int *v, int *Adj, int*p, int * prox, int * fimlistaadj, int * erro);

int* Grau(Grafo* g;

void ciclo_euleriano(Grafo * g);

int eh_grafo_euleriano(Grafo*g);

int grau(Grafo*g, int *v);

int proximo_vertice(Grafo ** g, int *v);
