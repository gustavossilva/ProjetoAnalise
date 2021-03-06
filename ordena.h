#ifndef _ORDENA_H
#define _ORDENA_H

/*
 * Função: ordena_por_bolha
 * ------------------------
 * Ordena em ordem crescente um vetor de inteiros usando o método da bolha
 *
 * A - o vetor de inteiros a ser ordenado.
 * n - o número de elementos de A.
 * 
 * SAÍDA: o vetor A reorganizado em ordem crescente.
 *
 */
void ordena_por_bolha(int *A, int n);


/*
 * Função: ordena_por_shell
 * ------------------------
 * Ordena em ordem crescente um vetor de inteiros usando o método de Shell
 *
 * A - o vetor de inteiros a ser ordenado.
 * n - o número de elementos de A.
 * 
 * SAÍDA: o vetor A reorganizado em ordem crescente.
 *
 */
void ordena_por_shell(int *A, int n);
void insertion(int *v, int tam);
void ordena_intercala(int * v,int p,int r);
void heap(int *a, int n);
void quick(int *vetor, int inicio, int fim);
int pegaMax(int *arr, int n);
void couting_radix(int *A, int tamanho, int exp);
void radixsort(int *arr, int n);
void coutingsort(int *A, int tamanho);
void insertiondouble(double *v, int tam);
void bucketsort(double *A,int tamanho);
#endif
