#ifndef _OPGRAFO_H
#define _OPGRAFO_H

typedef struct fila{
	Node *dado;
	struct fila *next;
}Fila;

void BuscaEmProfundidade(Node **G, int u);
void VisitaEmProfundidade(Node** G, int u, int* cor,int *r,int tempo);
void InsereNaFila(Fila **fila, Node *a);
Node * RemoveDaFila(Fila *fila);
void BuscaEmLargura(Node** G ,int tam);
#endif
