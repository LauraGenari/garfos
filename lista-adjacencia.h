typedef struct GRAFO Grafo;
/*
	id: identificação do vértice
	flag: indica se o vértice já foi visitado ou nao
	nroarestas: quantas arestas o vertice possui
	arestas: ponteiro para os proximos grafos
	arestasflag: indica qual aresta ja foi utilizada
*/


/*cria um vertice com 10 possiveis arestas e o retorna*/
Grafo* criavertice(int nro);

/*mostra o id de todos os vertices criados*/
void ShowAllVertices(Grafo** raiz, int nrovert);

/*faz uma busca sequencial e devolve a posição de um vertice dado seu id*/
int BS(Grafo ** raiz, int id, int nrovert);

/*conecta dois vertices dado seus ~~endereços~~*/
void ConnectVertices(Grafo** a, Grafo** b);

/*desconecta dois vertices dado seus ~~endereços~~*/
void DisconnectVertices(Grafo** a, Grafo** b);

/*caminha recursivamente pelo grafo, selecionando qual será o proximo vertice*/
void Caminha(Grafo** a);

/*
contam de forma recursiva quantos vertices tem um grafo hipotetico que nao é montado na main
atualmente inutil para o nosso codigo, mas o pardo pediu
*/
void ContaVertice(Grafo* first, int* count);
}

/*é chamado recursivamente para printar o caminho, em base das flag. 1 ja passou por la, 0 não passou*/
void ImprimeCaminhoEuleriano(Grafo** raiz, int start);

/*se exite caminho euleriano, o imprime. Caso contrario retorna 1*/
void ExisteCaminhoEuleriano(Grafo** raiz, int nrovert);

void ExisteCaminhoHamiltoniano(Grafo ** raiz);
