#include <stdlib.h>
#include <stdio.h>

#define MAXNUMVERTICES 100

typedef int elem;
typedef struct grafo Grafo;

Grafo * criar_grafo(int * tam, int * erro);
void inserir_aresta(Grafo * g, int * v1, int * v2, int * erro, elem * p);
