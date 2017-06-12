//
// Created by gustavovm on 11/06/17.
//
//

#include "gerador.h"

int* gerarVetor(int* vetor,int k, int flag){

    int tam = pow(2,k);
    printf("%d\n",tam);
    vetor = malloc(tam*sizeof(int));

    switch(flag){
        case 0: //vetor totalmente aleatorio
            geraAleatorio(vetor,tam);
            break;

        case 1: //Vetores ordenados em ordem crescente
            geraAleatorio(vetor,tam);
            qsort(vetor,tam,sizeof(vetor[0]),crescente);
            break;

        case 2: //Vetores ordenados em ordem decrescente
            geraAleatorio(vetor,tam);
            qsort(vetor,tam,sizeof(vetor[0]),decrescente);
            break;

        case 3: //vetor 90% ordenado de forma crescente
            geraAleatorio(vetor,tam);
            qsort(vetor,tam,sizeof(vetor[0]),crescente);
            exibeVetor(vetor,tam);
            desordenaVetor(vetor,tam,0.1);
            break;

        case 4: //vetor 90% ordenado de forma decrescente
            geraAleatorio(vetor,tam);
            qsort(vetor,tam,sizeof(vetor[0]),decrescente);
            exibeVetor(vetor,tam);
            desordenaVetor(vetor,tam,0.1);
            break;
        case 5:  //vetor 75% ordenado de forma crescente
            geraAleatorio(vetor,tam);
            qsort(vetor,tam,sizeof(vetor[0]),crescente);
            exibeVetor(vetor,tam);
            desordenaVetor(vetor,tam,0.25);
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
    srand(clock());
    for(i=0;i<tam;i++){
        vetor[i] = rand()%5000;
    }
    return 0;
}

void desordenaVetor(int *vetor,int tam,float qtd){
    float tamanho = round(qtd*tam);
    int aux;
    int mover,sorteio1 = 0,sorteio2=0;
    srand(clock());
    for(mover=0;mover<tamanho;mover+=2){
        while(sorteio1 == sorteio2){
            sorteio1 = rand()%(tam-1);
            srand(clock());
            sorteio2 = rand()%(tam-1);
        }
        aux = vetor[sorteio1];
        vetor[sorteio1] = vetor[sorteio2];
        vetor[sorteio2] = aux;
        sorteio1 = 0;
        sorteio2 = 0;
    }
    exibeVetor(vetor,tam);
}

void exibeVetor(int *vetor,int tam){
    int i;
    printf("Vetor: ");
    for(i=0;i<tam;i++){
        printf("%d, ",vetor[i]);
    }
    printf("\n");
}
