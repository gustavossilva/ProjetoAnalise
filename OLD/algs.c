//
// Created by guilherme on 6/11/17.
//


#include "algs.h"



int main() {
    int v[12] = {735,5,11,10000,9,8,9,100,5,15,654,736};
    int p = 0;
    int r = 11;
    ordena_intercala(v,p,r);
//    insertion(v);
    for(int i =0; i<= r; i++)
    {
        printf("%d ",v[i]);
    }
}



void ordena_intercala(int * v,int p,int r)
{
    int q;
    if (p < r) {
        q = floor ((p + r) / 2); // retorna o chão dessa operação
        ordena_intercala (v, p, q);
        ordena_intercala(v, q + 1, r);
        intercala(v, p, q, r);
    }
}

void intercala(int * v,int p, int q, int r)
{
    int B[12];
    int i,k,j;
    for (i = p; i<=q; i++)
        B[i] = v[i];
    for (j = (q + 1); j<= r;j++) {
        B[(r + q + 1 - j)] = v[j];
    }
    i = p;
    j = r;
    for(k = p; k<=r; k++) {
            if (B[i] <= B[j]) {
                v[k] = B[i];
                i++;
            } else {
                v[k] = B[j];
                j--;
            }
    }
}

void insertion(int *v, int tam)
{
    int chave,i,j;
    for(j=1;j<tam;j++)
    {
        chave = v[j];
        i = j - 1;
        while (i >= 0 && v[i] > chave)
        {
            v[i+1] = v[i];
            i = i-1;   
        }
	v[i+1] = chave;
    }
}

void heap(int *a, int n) {
    int i = n / 2, pai, filho, t;
    for (;;) {
        if (i > 0) {
            i--;
            t = a[i];
        } else {
            n--;
            if (n == 0) return;
            t = a[n];
            a[n] = a[0];
        }
        pai = i;
        filho = i * 2 + 1;
        while (filho < n) {
            if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
                filho++;
            if (a[filho] > t) {
                a[pai] = a[filho];
                pai = filho;
                filho = pai * 2 + 1;
            } else {
                break;
            }
        }
        a[pai] = t;
    }
}

void quick(int *vetor, int inicio, int fim){

    int pivo, aux, i, j, meio;

    i = inicio;
    j = fim;

    meio = (int) ((i + j) / 2);
    pivo = vetor[meio];

    do{
        while (vetor[i] < pivo) i = i + 1;
        while (vetor[j] > pivo) j = j - 1;

        if(i <= j){
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    }while(j > i);

    if(inicio < j) quick(vetor, inicio, j);
    if(i < fim) quick(vetor, i, fim);
}

void radix(int *vetor, int tamanho){
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b = (int *)calloc(tamanho, sizeof(int));

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
            maior = vetor[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };
        for (i = 0; i < tamanho; i++)
            bucket[(vetor[i] / exp) % 10]++;
        for (i = 1; i < 10; i++)
            bucket[i] += bucket[i - 1];
        for (i = tamanho - 1; i >= 0; i--)
            b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
        for (i = 0; i < tamanho; i++)
            vetor[i] = b[i];
        exp *= 10;
    }
    free(b);
}

/*
void count(char *arr, int tam)
{
    // The output character array that will have sorted arr
    char output[strlen(arr)];

    // Create a count array to store count of inidividul
    // characters and initialize count array as 0
    int count[tam + 1], i;
    memset(count, 0, sizeof(count));

    // Store count of each character
    for(i = 0; arr[i]; ++i)
        ++count[arr[i]];

    // Change count[i] so that count[i] now contains actual
    // position of this character in output array
    for (i = 1; i <= tam; ++i)
        count[i] += count[i-1];

    // Build the output character array
    for (i = 0; arr[i]; ++i)
    {
        output[count[arr[i]]-1] = arr[i];
        --count[arr[i]];
    }

    // Copy the output array to arr, so that arr now
    // contains sorted characters
    for (i = 0; arr[i]; ++i)
        arr[i] = output[i];
}

void bucket(int *array, int n)
{
    int i, j;
    int count[n];
    for (i = 0; i < n; i++)
        count[i] = 0;

    for (i = 0; i < n; i++)
        (count[array[i]])++;

    for (i = 0, j = 0; i < n; i++)
        for(; count[i] > 0; (count[i])--)
            array[j++] = i;
}*/
