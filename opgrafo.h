#ifndef _OPGRAFO_H
#define _OPGRAFO_H

/*typedef struct fila{
	Node *dado;
	struct fila *next;
}Fila;*/

void BuscaEmProfundidade(Node **G, int u);
void VisitaEmProfundidade(Node** G, int u, int* cor,int *r,int tempo);
void InsereNaFila(Node **,Node* ,int*,int*);
Node * RemoveDaFila(Node**,int*,int*);
int isEmpty(int);
int isFull(int);
void BuscaEmLargura(Node** G ,int tam);
void VisitaEmProfundidadeTop(Node** G, int u, int* cor,int *r,int tempo,int *d, int *f,Node **fila, int* rear, int *itemCount);
void OrdenaTopologico(Node **G, int u);
#endif
