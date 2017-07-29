typedef struct graphnode{                        
    int vertex;
    struct graphnode *next;
}Node;


void VisitaEmProfundidade(Node** G, int u, int* cor,int *r,int tempo){
	cor[u] = 1	// 1: CINZA
	tempo = tempo + 1;
	//d[u] = tempo;
	aux = G[u]->next;
	while(aux != NULL){
		if(cor[aux->vertex] == 2){
			r[v] = u;
			VisitaEmProfundidade(G,aux->vertex,cor,r,tempo);
		}
		aux = aux->next;
	}
	cor[u] = 0;

}


BuscaEmProfundidade(Node **G, int u){
	int *cor;
	int *r;
	int tempo;
	int i;

	cor = (int*) malloc(u+1 * sizeof(int));
	r = (int*) calloc(u+1,sizeof(int));

	for(i = 1; i<=u ; i++)
		cor[i] = 2; 	//	2: Branco
	
	tempo = 0;
	for(int i=1;i<=u;i++){
		if(cor[i] == 2)|{
			VisitaEmProfundidade(G,i,cor, r,tempo);
		}
	}
}
