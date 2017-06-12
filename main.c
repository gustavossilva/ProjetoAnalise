//gcc -o my_app main.c gerador.c -lm
#include "main.h"

/*gerarVetor(vetor,k,flag) Gera um vetor V alocado dinamicamento tamanho 2^k e com a ordenação baseado na flag
    flag 0 = vetor totalmente aleatorio
    flag 1 = Vetores ordenados em ordem crescente
    flag 2 = Vetores ordenados em ordem decrescente
    flag 3 = vetor 90% ordenado de forma crescente
    flag 4 = vetor 90% ordenado de forma decrescente
    flag 5 = vetor 50% ordenado de forma crescente
*/
int main() {
    //FILE *f = fopen("file.txt", "w");

    int i;
    int *v1,*v2,*v3,*v4,*v5,*v6,*v7,*v8,*v9,*v10,*v11,*v12;
    int *teste;
    //Vetores Aleatorios
    v1 = gerarVetor(v1,3,0);
    v2 = gerarVetor(v2,4,0);
    v3 = gerarVetor(v3,5,0);
    v4 = gerarVetor(v4,6,0);
    v5 = gerarVetor(v5,7,0);
    v6 = gerarVetor(v6,8,0);
    v7 = gerarVetor(v7,9,0);
    v8 = gerarVetor(v8,10,0);
    v9 = gerarVetor(v9,11,0);
    v10 = gerarVetor(v10,12,0);
    v11 = gerarVetor(v11,13,0);
    v12 = gerarVetor(v12,14,0);
    teste = gerarVetor(teste,5,3);

/*    for(i =1;i<pow(2,14);i++){
        fprintf(f,"%d %d %f %f %f\n",1,i,log2(i),i*log2(i),pow(i,2));
    }*/


    //Vetores ordenados em ordem crescente

    return 0;
}

