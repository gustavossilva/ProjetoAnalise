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
