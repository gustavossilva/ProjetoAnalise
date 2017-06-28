#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"
#include <math.h>
void intercala(int * v,int p, int q, int r);
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
    int *B = calloc((r+1),sizeof(int));
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
	free(B);
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

void coutingsort(int *A, int tamanho){
    int k = 10;
    int aux;
    int *C = (int*)calloc(k+1,sizeof(int));
    int *B = (int*)malloc(tamanho*sizeof(int));
    
    for(int j = 0;j<tamanho;j++){
        C[A[j]]++;
    }
    for(int i=1;i<=k;i++){
        C[i] = C[i] + C[i-1];
    }
    for(int j=0;j<tamanho;j++){
        B[C[A[j]]-1] = A[j];
        C[A[j]]--;
    }
    for(int i=0;i<tamanho;i++){
        A[i] = B[i];
    }
}

int pegaMax(int *arr, int n) //pegar o maior valor no array;
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void couting_radix(int *A, int tamanho, int exp){ //couting adaptado para ir de digito a digito
    int k = tamanho;
    int aux;
    int *C = (int*)calloc(k+1,sizeof(int));
    int *B = (int*)malloc(tamanho*sizeof(int));
    
    for(int j = 0;j<tamanho;j++){
        C[(A[j]/exp)%10]++;
    }
    for(int i=1;i<=k;i++){
        C[i] = C[i] + C[i-1];
    }
    for(int j=tamanho-1;j>=0;j--){
        B[C[ (A[j]/exp)%10]-1] = A[j];
        C[(A[j]/exp)%10]--;
    }
    for(int i=0;i<tamanho;i++){
        A[i] = B[i];
    }
}

void radixsort(int *arr, int n)
{
    // Encontrar o nro máximo nos valores
    int m = pegaMax(arr, n);
    //For do radix ir digito a digito
    for (int exp = 1; m/exp > 0; exp *= 10)
        couting_radix(arr, n, exp);
}

void insertiondouble(double *v, int tam)
{
    int i,j;
    double chave;
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

void bucketsort(double *A,int tamanho){
    bucket *C = (bucket*)malloc(10*sizeof(bucket));
    int j,i;
    for(int i=0;i<10;i++){ //Inicialização dos topos dos baldes
        C[i].topo = 0.0;
        C[i].balde = (double*)malloc((int)(tamanho)*sizeof(double));
    }
    for(i = 0;i<tamanho;i++){ //Verifica em que balde o elem deve ficar
        j = 10-1;
        while(1){
            if(j<0){
                break;
            }
            if(A[i]>=j*10){
                C[j].balde[C[j].topo] = A[i];
                (C[j].topo)++;
                break;
            }
            j--;
        }
    }    
    for(i=0;i<10;i++){ //ordena os baldes
        if(C[i].topo){
            insertiondouble(C[i].balde,C[i].topo);
        }
    }
    i=0;
    for(j=0;j<10;j++){ //coloca os elementos dos baldes de volta no vetor
        for(int k=0;k<C[j].topo;k++){
            A[i]=C[j].balde[k];
            i++;
        }
    }
    for(i=0;i<10;i++){
        free(C[i].balde);
    }
    free(C);
}
