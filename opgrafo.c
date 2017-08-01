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
	tempo = tempo+1;
    //f[u] = tempo;
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
    Node* fila[1024];
    int front = 0;
    int rear = -1;
    int itemCount = 0;

    int source = 1;
	int cor[tam],r[tam];
	//Fila* Q = (Fila*)malloc(sizeof(Fila));
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
	InsereNaFila(fila,G[source],&itemCount,&rear);
	while(isEmpty(itemCount) != 1){
		aux = RemoveDaFila(fila,&itemCount,&front);
		tmp = aux;
		while(tmp!=NULL){
			if(cor[tmp->vertex] == 2){
				cor[tmp->vertex] = 1;
				//d[tmp->vertex] = d[aux->vertex] + 1
				r[tmp->vertex] = aux->vertex;
				InsereNaFila(fila,G[tmp->vertex],&itemCount,&rear);
			}
			tmp = tmp->next;
		}
		cor[aux->vertex] = 0;
	}
}

Node* topoDaFila(Node**fila,int front){
    return fila[front];
}

int isFull(int itemCount){
    if(itemCount == 1024)
        return 1;
    else
        return 0;
}

int isEmpty(int itemCount){
    if(itemCount == 0)
        return 1;
    else
        return 0;
}

void InsereNaFila(Node** fila,Node* no,int* itemCount,int* rear){
    if(!isFull(*itemCount)){
        if(*rear == 1024-1){
            *rear = -1;
        }
        fila[++(*rear)] = no;
        (*itemCount)++;
    }
    //printf("Elemento inserido %d \n", no->vertex);
}

Node* RemoveDaFila(Node** fila,int *itemCount,int *front) {
   Node* data = fila[(*front)++];
	
   if((*front) == 1024) {
      (*front) = 0;
   }
   (*itemCount)--;
   return data;  
}


void VisitaEmProfundidadeTop(Node** G, int u, int* cor,int *r,int tempo,int *d, int *f,Node **fila, int* rear, int *itemCount){
	cor[u] = 1;	// 1: CINZA
	tempo = tempo + 1;
	d[u] = tempo;
	Node* aux = G[u]->next;
	while(aux != NULL){
		if(cor[aux->vertex] == 2){
			r[aux->vertex] = u;
			VisitaEmProfundidadeTop(G,aux->vertex,cor,r,tempo,d,f,fila,rear,itemCount);
		}
		aux = aux->next;
	}
	cor[u] = 0;
	tempo = tempo+1;
    f[u] = tempo; 
    //printf("Aresta %d tempo %d",u,f[u]);
    InsereNaFila(fila,G[u],itemCount,rear);
}


void OrdenaTopologico(Node **G, int u){
    Node* fila[1025];
    int front = 0;
    int rear = -1;
    int itemCount = 0;
	int cor[u];
	int r[u];
	int d[u];
	int f[u];
	int tempo;
	int i;

	for(i = 1; i<=u ; i++)
		cor[i] = 2; 	//	2: Branco
	tempo = 0;
	for(int i=1;i<=u;i++){
		if(cor[i] == 2){
			VisitaEmProfundidadeTop(G,i,cor, r,tempo,d,f, fila, &rear,&itemCount);
		}
	}
	//for(int i=(u-1);i>0;i--){
	//    printf("%d, ",fila[i]->vertex);
	//}
}
