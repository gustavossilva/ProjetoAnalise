#include <stdio.h>

#include "vetor.h"

static void inline troca(int *A, int i, int j){
  int temp;
  temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}

void ordena_por_bolha(int *A, int n){
  int i,j;

  if (n<2) return;
  
  for(i=0; i<n; i++)
    for(j=0; j<n-1; j++)
      if (A[j] > A[j+1])
        troca(A,j,j+1);
}


void ordena_por_shell(int *A, int n){
  // Sequência de lacunas de Marcin Ciura
  // Ref: https://en.wikipedia.org/wiki/Shellsort
  int lacunas[] = {701, 301, 132, 57, 23, 10, 4, 1};
  int *lacuna;
  int i, j, temp;
  
  for(lacuna=lacunas; *lacuna > 0; lacuna++){
    for(i=*lacuna; i < n; i++){
      // adicione A[i] aos elementos que foram ordenados
      // guarde A[i] em temp e crie um espaço na posição i
      temp = A[i];
      // Desloque os elementos previamente ordenados até 
      // que a posição correta para A[i] seja encontrada
      for(j=i; j >= *lacuna && A[j - *lacuna] > temp; j -= *lacuna){
         A[j] = A[j - *lacuna];
      }
      // Coloque temp (o A[i] original) em sua posição correta
      A[j] = temp;
    }
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
    int B[10];
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

