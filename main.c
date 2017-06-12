//compile gcc -o my_app main.c gerador.c
#include "main.h"

/*gerarVetor(vetor,k,flag) Gera um vetor V alocado dinamicamento tamanho 2^k e com a ordenação baseado na flag
    flag 0 = vetor totalmente aleatorio
    flag 1 = vetor ordenado de forma crescente
    flag 2 = vetor ordenado de forma decrescnte
    flag 3 = vetor 90% ordenado de forma crescente
    flag 4 = vetor 90% ordenado de forma decrescente
    flag 5 = vetor 50% ordenado de forma crescente
*/
int main() {
    int* v;
    v = gerarVetor(v,4,1);

    
    return 0;
}