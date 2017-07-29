#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "opgrafo.h"
#include <math.h>

void VisitaEmProfundidade(Node** G, int u, int* cor,int *r,int tempo){
	cor[u] = 1;	// 1: CINZA
	tempo = tempo + 1;
	//d[u] = tempo;
	Node* aux = G[u]->next;
	while(aux != NULL){
		if(cor[aux->vertex] == 2){
			r[aux->vertex] = u;
			VisitaEmProfundidade(G,aux->vertex,cor,r,tempo);
		}
		aux = aux->next;
	}
	cor[u] = 0;

}


void BuscaEmProfundidade(Node **G, int u){
	int cor[u];
	int r[u];
	int tempo;
	int i;

	for(i = 1; i<=u ; i++)
		cor[i] = 2; 	//	2: Branco
	
	tempo = 0;
	for(int i=1;i<=u;i++){
		if(cor[i] == 2){
			VisitaEmProfundidade(G,i,cor, r,tempo);
		}
	}
	/*for(int i=1;i<=u;i++){
	    printf("%d, ",cor[i]);
	}*/
}

void BuscaEmLargura(Node** G ,int tam){
    int source = 1;
	int cor[tam],r[tam];
	Fila* f = NULL;
	Node *aux;
	Node *tmp;
	for(int i=1;i<=tam;i++){
		if(i!=source){
			cor[i] = 2;
			//d[i] = infinito
		}
	}
	cor[source] = 1;
	//d[source] = 0;
	r[source] = source;
	//InsereNaFila(&f, G[source]);
	/*while(f != NULL){
		//aux = RemoveDaFila(f);
		tmp = aux;
		while(tmp!=NULL){
			tmp = tmp->next;
			if(cor[tmp->vertex] == 2){
				cor[tmp->vertex] = 1;
				//d[tmp->vertex] = d[aux->vertex] + 1
				r[tmp->vertex] = aux->vertex;
				//InsereNaFila(f,tmp);
			}
		}
		cor[aux->vertex] = 0;
	}*/
}

void InsereNaFila(Fila **fila, Node *a){
	Fila *aux = (Fila*)malloc(sizeof(Fila));
	aux->dado = a;
	aux->next = (*fila);
	(*fila) = aux;
	/*if(!aux->dado){
		fila->dado = a;
		fila->next = NULL;
	}else{
		while(!aux->next){
			aux = aux->next;
		}
		Fila *nova = (Fila*)malloc(sizeof(Fila));
		aux->next = nova;
		nova->dado = a;
		nova->next = NULL;
	}*/
	
}

Node * RemoveDaFila(Fila *fila){
	Node* no;
	if(!fila){
		no = fila->dado;
		fila = fila->next;
		return no;
	}
	else{
		return NULL;
	}
}

