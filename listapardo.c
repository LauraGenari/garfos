#include "listapardo.h"

typedef struct no_aresta{
    int v;
    elem peso;
    struct no_aresta * prox;
}no_aresta

typedef struct no_vertice{
    no_aresta * inicio, * fim;
}no_vertice;

struct grafo{
    no_vertices Adj[MAXNUMVERTICES];
    int NumVertices;
};

Grafo * criar_grafo(int * tam, int * erro){
    if( (*tam) > MAXNUMVERTICES){
        *erro = 1;
        return NULL;
    }

    Grafo * g = malloc(sizeof(Grafo));
    if(!g) *erro = 1;
    else {
        *erro = 0;
        g->NumVertices = (*tam);
        for(int i = 0; i < (*tam); i++){
            g->Adj[i].inicio = (no_aresta*)malloc(sizeof(no_aresta));
            g->Adj[i].inicio->peso = 0;
            g->Adj[i].inicio->v = 0;
            g->Adj[i].inicio->prox = NULL;

            g->Adj[i].fim =  g->Adj[i].inicio; 
        }
    }
    return g;
}
//para grafo direcionando
void inserir_aresta(Grafo * g, int * v1, int * v2, int * erro, elem * p){
    if((*v1) >= g->NumVertices) || (*v2) >= g->NumVertices) *erro1;
    else{
        g->Adj[*v1].fim->prox = (no_aresta*) malloc(sizeof(no_aresta));
        if(g->Adj[*v1].fim->prox == NULL){
            *erro = 1;
            return;
        }
        *erro = 0;
        g->Adj[*v1].fim = g->Adj[*v1].fim->prox;
        g->Adj[*v1].fim->v = v2;
        g->Adj[*v1].fim->peso = *p;
        g->Adj[*v1].fim->prox = NULL;
   }
}

void remover_aresta(Grafo *g, int *v1, int *v2, elem *p, int * erro){
    if((*v1) >= g->NumVertices) || (*v2) >= g->NumVertices) *erro = 1;
    else{
        *erro = 0;
        int encontrou = 0;
        no_aresta *ant = g->Adj[*v1].inicio;
        no_aresta *aux = ant->prox;
        while( (aux != NULL) && !encontrou){
            if(aux->v == *v2){
                encontrou = 1;
                *p = aux->peso;
                ant->prox = aux->prox;
            }
            if(g->Adj[*v1].fim == aux) g->Adj[*v1].fim = ant;
            free(aux);
        }
        else{
            ant = aux;
            aux = aux->prox;
        }
    }
}


int conta_arestas(Grafo * g){
    int count = 0;
    no_aresta * p;
    for(int i = 0; i < g->NumVertices; i++){
        p = g->Adj[i].inicio;
        while(p){
            count++;
            p = p->prox;
        }
    }
}

void coloracao(Grafo * g){
    //para 4 cores, função exponencial
    //algoritmo guloso welsh-powell, em 1975
}







