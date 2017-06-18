#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <float.h>

#include "vetor.h"
#include "ordena.h"

int main(int argc, char *argv[]){
  int * v = NULL;
  int n = 0;
  clock_t inicio, fim;
  double tempo_de_cpu = 0.0;
  char msg[256];
  char nome_do_arquivo[128];
  
  strcpy(nome_do_arquivo, "vetores/vIntCrescente_131072.dat");
  // Leia o vetor a partir do arquivo
  v = leia_vetor_int(nome_do_arquivo, &n);
  
  // Cronometrando o método de ordenação da bolha
  inicio = clock();
  ordena_por_bolha(v,n); 
  fim = clock();
  tempo_de_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

  strcpy(msg, "");
  if (esta_ordenado_int(CRESCENTE,v,n))
     sprintf(msg,
             "bolha: %s ordenado com tempo %.*f s.\n", 
             nome_do_arquivo, DBL_DECIMAL_DIG, tempo_de_cpu);
  else
     sprintf(msg, "bolha: falha na ordenação de %s.\n", nome_do_arquivo);     
  printf("%s\n", msg);
  
  // Não se esqueça de liberar a memória.
  free(v);
  
  // Leia o vetor a partir do arquivo
  v = leia_vetor_int(nome_do_arquivo, &n);
  
  // Cronometrando o método de ordenação de Shell
  inicio = clock();
  ordena_por_shell(v,n); 
  fim = clock();
  tempo_de_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
  
  strcpy(msg, "");
  if (esta_ordenado_int(CRESCENTE,v,n))
     sprintf(msg,
             "Shell: %s ordenado com tempo %.*f s.\n", 
             nome_do_arquivo, DBL_DECIMAL_DIG, tempo_de_cpu);
  else
     sprintf(msg, "Shell: falha na ordenação de %s.\n", nome_do_arquivo);
     
  printf("%s\n", msg);
  
  /* Se você não prestou atenção na primeira vez: não se esqueça de 
     liberar a memória. */
  free(v);
  
  exit(0);
}

