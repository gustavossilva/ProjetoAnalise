//
// Created by gustavovm on 11/06/17.
//


#ifndef PROJETOANALISE_GERADOR_H
#define PROJETOANALISE_GERADOR_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct Vetor{
    int* v;
    int size;
}Vetor;

Vetor gerarVetor(Vetor,int, int);
int geraAleatorio(int*, int);
void exibeVetor(int*, int);
int crescente (const void * , const void * );
int decrescente (const void * , const void * );
void desordenaVetor(int *, int, float, int);
int getSize(int *);


#endif //PROJETOANALISE_GERADOR_H

