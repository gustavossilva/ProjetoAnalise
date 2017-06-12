//
// Created by gustavovm on 11/06/17.
//
//gcc -o my_app main.c gerador.c -lm

#include "gerador.h"

int* gerarVetor(int* vetor,int k, int flag){

    int tam = pow(2,k);
    printf("%d\n",tam);
    vetor = malloc(tam*sizeof(int));

    switch(flag){
        case 0: //vetor totalmente aleatorio
            geraAleatorio(vetor,tam);
            exibeVetor(vetor,tam);
            break;

        case 1: //vetor ordenado de forma crescente
            geraAleatorio(vetor,tam);
            qsort(vetor,tam,sizeof(vetor[0]),crescente);
            exibeVetor(vetor,tam);
            break;

        case 2: //vetor ordenado de forma decrescnte
            geraAleatorio(vetor,tam);
            qsort(vetor,tam,sizeof(vetor[0]),decrescente);
            exibeVetor(vetor,tam);
            break;

        case 3: //vetor 90% ordenado de forma crescente
            break;

        case 4: //vetor 90% ordenado de forma decrescente
            break;

        case 5:  //vetor 50% ordenado de forma crescente
            break;

        default:
            printf("Flag incorreta");
            break;
    }
    return vetor;
}

int crescente (const void * elem1, const void * elem2)
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}
int decrescente (const void * elem1, const void * elem2)
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return -1;
    if (f < s) return 1;
    return 0;
}

int geraAleatorio(int* vetor,int tam){
    int i;
    for(i=0;i<tam;i++){
        vetor[i] = rand()%5000;
    }
    return 0;
}

void exibeVetor(int *vetor,int tam){
    int i;
    printf("Vetor: ");
    for(i=0;i<tam;i++){
        printf("%d, ",vetor[i]);
    }
    printf("\n");
}
