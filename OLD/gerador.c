//
// Created by gustavovm on 11/06/17.
//
//

#include "gerador.h"

Vetor gerarVetor(Vetor vetor,int k, int flag){

    int tam = pow(2,k);
    vetor.size = tam;
    //printf("%d\n",tam);
    vetor.v = malloc(tam*sizeof(int));

    switch(flag){
        case 0: //vetor totalmente aleatorio
            geraAleatorio(vetor.v,tam);
            break;

        case 1: //Vetores ordenados em ordem crescente
            geraAleatorio(vetor.v,tam);
            qsort(vetor.v,tam,sizeof(vetor.v[0]),crescente);
            break;

        case 2: //Vetores ordenados em ordem decrescente
            geraAleatorio(vetor.v,tam);
            qsort(vetor.v,tam,sizeof(vetor.v[0]),decrescente);
            break;

        case 3: //vetor 90% ordenado de forma crescente
            geraAleatorio(vetor.v,tam);
            qsort(vetor.v,tam,sizeof(vetor.v[0]),crescente);
            //exibeVetor(vetor,tam);
            desordenaVetor(vetor.v,tam,0.1,0);
            break;

        case 4: //vetor 90% ordenado de forma decrescente
            geraAleatorio(vetor.v,tam);
            qsort(vetor.v,tam,sizeof(vetor.v[0]),decrescente);
            //exibeVetor(vetor,tam);
            desordenaVetor(vetor.v,tam,0.1,1);
            break;
        case 5: //vetor 80% ordenado de forma crescente
            geraAleatorio(vetor.v,tam);
            qsort(vetor.v,tam,sizeof(vetor.v[0]),crescente);
            //exibeVetor(vetor,tam);
            desordenaVetor(vetor.v,tam,0.2,0);
            break;

        case 6: //vetor 80% ordenado de forma decrescente
            geraAleatorio(vetor.v,tam);
            qsort(vetor.v,tam,sizeof(vetor.v[0]),decrescente);
            //exibeVetor(vetor,tam);
            desordenaVetor(vetor.v,tam,0.2,1);
            break;
        case 7: //vetor 70% ordenado de forma crescente
            geraAleatorio(vetor.v,tam);
            qsort(vetor.v,tam,sizeof(vetor.v[0]),crescente);
            //exibeVetor(vetor,tam);
            desordenaVetor(vetor.v,tam,0.3,0);
            break;
        case 8: //vetor 70% ordenado de forma decrescente
            geraAleatorio(vetor.v,tam);
            qsort(vetor.v,tam,sizeof(vetor.v[0]),decrescente);
            //exibeVetor(vetor,tam);
            desordenaVetor(vetor.v,tam,0.3,1);
            break;
        case 9: //vetor 60% ordenado de forma crescente
            geraAleatorio(vetor.v,tam);
            qsort(vetor.v,tam,sizeof(vetor.v[0]),crescente);
            //exibeVetor(vetor,tam);
            desordenaVetor(vetor.v,tam,0.4,0);
            break;
        case 10: //vetor 60% ordenado de forma decrescente
            geraAleatorio(vetor.v,tam);
            qsort(vetor.v,tam,sizeof(vetor.v[0]),decrescente);
            //exibeVetor(vetor,tam);
            desordenaVetor(vetor.v,tam,0.4,1);
            break;
        case 11:  //vetor 50% ordenado de forma crescente
            geraAleatorio(vetor.v,tam);
            qsort(vetor.v,tam,sizeof(vetor.v[0]),crescente);
            //exibeVetor(vetor,tam);
            desordenaVetor(vetor.v,tam,0.5,0);
            break;
        case 12: //vetor 50% ordenado de forma decrescente
            geraAleatorio(vetor.v,tam);
            qsort(vetor.v,tam,sizeof(vetor.v[0]),decrescente);
            //exibeVetor(vetor,tam);
            desordenaVetor(vetor.v,tam,0.5,1);
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

void desordenaVetor(int *vetor,int tam,float qtd,int flag){ //flag 1 = descrescente flag 0 = crescente
    float tamanho = round(qtd*tam);
    int aux;
    int mover,sorteio1 = 0,sorteio2=0;
    srand(clock());
    if((int)tamanho%2 !=0){
        for(mover =0;mover <tamanho;mover++){
            srand(clock());
            sorteio1 = rand()%(tam-1);
            if(flag == 0){
                vetor[sorteio1] = vetor[sorteio1-1] - 1;
            }else{
                vetor[sorteio1] = vetor[sorteio1-1] + 1;
            }
            sorteio1 = 0;
        }
    }
    else{
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
    }
    //exibeVetor(vetor,tam);
}

void exibeVetor(int *vetor,int tam){
    int i;
    printf("Vetor: ");
    for(i=0;i<tam;i++){
        printf("%d, ",vetor[i]);
    }
    printf("\n");
}

/*
int getSize(int *v){
    int i=0;
    while(v[i] != NULL){
        i++;
    }
    return i;
}*/
