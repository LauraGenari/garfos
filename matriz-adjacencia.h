#include <stdlib.h>

typedef struct MATRIZ Matriz;

Matriz ** criaMatriz(int nrovertices);
void liberarMatriz(Matriz** mat);
void criaAresta(int linha, int coluna, Matriz**mat, int peso);
