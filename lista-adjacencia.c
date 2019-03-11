#include "lista-adjacencia.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct GRAFO Grafo;
/*
	id: identificação do vértice
	flag: indica se o vértice já foi visitado ou nao
	nroarestas: quantas arestas o vertice possui
	arestas: ponteiro para os proximos grafos
	arestasflag: indica qual aresta ja foi utilizada
*/
struct GRAFO{
	int id;
	int flag;
	int nroarestas;
	int* arestaflag;
	Grafo** arestas;
};

/*cria um vertice com 10 possiveis arestas e o retorna*/
Grafo* criavertice(int nro){
	Grafo* abc =  malloc(sizeof(Grafo));

	abc->id = nro;
	abc->flag = 0;
	abc->nroarestas = 0;
	abc->arestas = malloc(sizeof(Grafo*) * 10);
	abc->arestaflag = calloc(sizeof(int),10);

	return abc;
}

void apagavertice(Grafo** raiz, int id, int nrovert){
		int a = BS(raiz, id, raiz, nrovert);
		if (a != -1) free(raiz);
		else printf("O id %d nao existe\n", id);
}

/*mostra o id de todos os vertices criados*/
void ShowAllVertices(Grafo** raiz, int nrovert){
	for (int i = 0; i < nrovert; ++i){
			printf("vertice: %d \t  id: %d\n",i , raiz[i]->id);
		}
	}

/*faz uma busca sequencial e devolve a posição de um vertice dado seu id*/
int BS(Grafo ** raiz, int id, int nrovert){
	for (int i = 0; i <  nrovert; i++) {
		if(raiz[i]->id == id) return i;
	}
	return -1;
}

/*conecta dois vertices dado seus ~~endereços~~*/
void ConnectVertices(Grafo** a, Grafo** b){
	(*a)->arestas[(*a)->nroarestas] = (*b);
	(*a)->arestaflag[(*a)->nroarestas] = 1;
	(*a)->nroarestas++;

	(*b)->arestas[(*b)->nroarestas] = (*a);
	(*b)->arestaflag[(*b)->nroarestas] = 1;
	(*b)->nroarestas++;
}

/*desconecta dois vertices dado seus ~~endereços~~*/
void DisconnectVertices(Grafo** a, Grafo** b){
	for( int i = 0; i < (*a)->nroarestas; i++){
		if((*a)->arestas[i] == (*b)){
			(*a)->arestas[i] = NULL;
			(*a)->nroarestas--;
		}
		if((*b)->arestas[i] == (*a)){
			(*b)->arestas[i] = NULL;
			(*b)->nroarestas--;
		}
	}
}

/*caminha recursivamente pelo grafo, selecionando qual será o proximo vertice*/
void Caminha(Grafo** a){
	int nro;
	printf("voce esta no %d\n", (*a)->id);
	printf("Para onde vc quer ir?\n");
	printf("opções:\n");

	for(int i =0; i < (*a)->nroarestas; i++){
		Grafo * b =  (*a)->arestas[i];
		printf("vertice %d\n", b->id);
	}

//essa parte de chamar recursivamente ta dando seg fault. Me ajudem
	scanf("%d", &nro);
	int b =  BS( (*a)->arestas, nro, (*a)->nroarestas);

	if( b == -1){
		return;
	}
	else{
		Caminha(&((*a)->arestas[b]));
	}
}

/*
contam de forma recursiva quantos vertices tem um grafo hipotetico que nao é montado na main
atualmente inutil para o nosso codigo, mas o pardo pediu
*/
void ContaVertice(Grafo* first, int* count){
	for (int i = 0; i < first->nroarestas; ++i){
		if(first->flag == 0){
			*count++;
			first->flag = 1;
			ContaVertice(first->arestas[i],count);
		}
	}
}
int ContaVerticeAux(Grafo* first){
	int* conta= malloc(sizeof(int));
	int aux;
	*conta = 0;
	ContaVertice(first, conta);
	aux = *conta;
	free(conta);
	return aux;
}

/*é chamado recursivamente para printar o caminho, em base das flag. 1 ja passou por la, 0 não passou*/
void ImprimeCaminhoEuleriano(Grafo** raiz, int start){
		if (raiz[start]->flag != 1){
			printf("vertice: %d \n",raiz[start]->id);
			raiz[start]->flag = 1;
			for (int i = 0; i < raiz[start]->nroarestas; i++) {
				ImprimeCaminhoEuleriano(&(raiz[start]->arestas[i]), i);
			}
		}
		else{
			return;
		}
}

/*se exite caminho euleriano, o imprime. Caso contrario retorna 1*/
void ExisteCaminhoEuleriano(Grafo** raiz, int nrovert){
	int nroimpares = 0, totalarestas = 0, impar = 0;
	for (int i = 0; i < nrovert; ++i){
		if( raiz[i]->nroarestas % 2 == 1){
			nroimpares++;
			impar = i;
		}
	}
	//se o numero de vertices impares for 2 ou 0, existe caminho euleriano entao o imprime, senao, nao exsite
	if(nroimpares == 2 || nroimpares == 0){
		ImprimeCaminhoEuleriano(raiz,impar);
	}
	else{
		printf("Não existe caminho euleriano\n");
	}
}

void ExisteCaminhoHamiltoniano(Grafo ** raiz){


}

int main(){
	Grafo** raiz;
	int controle, nrovert=0;

	raiz = malloc(sizeof(Grafo*) * 50);

	printf("digite um numero:\n  0 encerra\n  1 cria vertice\n  2 mostra todos os vertices\n  3 junta vertices\n  4 separa vertices\n  5 caminha\n  6 procura caminho euleriano\n  7 procura caminho hamiltoniano\n");
	scanf("%d", &controle);

	while(controle != 0){
		if(controle == 1){
			int nro;
			printf("digite o id do vertice(de 0 a 50)\n");
			scanf("%d", &nro);
			raiz[nrovert] = criavertice(nro);
			nrovert++;
		}
		else if(controle == 2){
			ShowAllVertices(raiz, nrovert);
		}
		else if(controle == 3){
			int a, b,x,y;

			printf("Digite o id de dois vertices para criar uma conexao entre eles\n");
			scanf("%d %d", &a, &b);

			x = BS(raiz, a, nrovert);
			if(x == -1){
				printf("vertice %d nao existe\n", a);
			}

			y = BS(raiz, b, nrovert);
			if(y == -1){
				printf("vertice %d nao existe\n", b);
			}

			else ConnectVertices(&raiz[x], &raiz[y]);

		}
		else if(controle == 4){
			int a, b,x,y;
			printf("Digite o id de dois vertices para desfazer uma conexao entre eles\n");
			scanf("%d %d", &a, &b);

			x = BS(raiz, a, nrovert);
			if(x == -1){
				printf("vertice %d nao existe\n", a);
			}

			y = BS(raiz, b, nrovert);
			if(y == -1){
				printf("vertice %d nao existe\n", b);
			}

			else DisconnectVertices(&raiz[x], &raiz[y]);
		}

		else if(controle == 5){
			int a;
			printf("selecione um id para comecar\n");
			scanf("%d", &a);
			int	x = BS(raiz, a, nrovert);
			Caminha(&raiz[x]);
		}

		else if(controle == 6){
			 ExisteCaminhoEuleriano(raiz, nrovert);
		}

		else if(controle == 7){
			 ExisteCaminhoHamiltoniano(raiz);
		}

		printf("digite um numero:\n  0 encerra\n  1 cria vertice\n  2 mostra todos os vertices\n  3 junta vertices\n  4 separa vertices\n  5 caminha\n  6 procura caminho euleriano\n  7 procura caminho hamiltoniano\n");
		scanf("%d", &controle);
	}

	for (int i = 0; i < 50; ++i){
		if(raiz[i] != NULL){
			free(raiz[i]);
		}
	}
	free(raiz);
}
