#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <float.h>
#include <math.h>

#include "vetor.h"
#include "ordena.h"

int main(int argc, char *argv[]){
  printf("teste");
  int * v = NULL;
  int n = 0;
  clock_t inicio, fim;
  double tempo_de_cpu = 0.0;
  char msg[256];
  char nome_do_arquivo[128];
  char **arquivos;
  int k=0;
  printf("teste");
  arquivos = (char**)malloc(200*sizeof(char*));
  for(int i=0;i<200;i++){
    arquivos[i] = (char*)malloc(128*sizeof(char));
  }
  
  for(int i=0;i<12;i++){
    sprintf(nome_do_arquivo,"vetores/vIntAleatorio_%d.dat",(int)pow(2,i+3%15));
    strcpy(arquivos[k], nome_do_arquivo);
    k++;
  }
  for(int i=0;i<12;i++){
    sprintf(nome_do_arquivo,"vetores/vIntCrescente_%d.dat",(int)pow(2,i+3%15));
    strcpy(arquivos[k], nome_do_arquivo);
    k++;
    
  }
  for(int i=0;i<12;i++){
    sprintf(nome_do_arquivo,"vetores/vIntCrescente_%d_P10.dat",(int)pow(2,i+3%15));
    strcpy(arquivos[k], nome_do_arquivo);
    k++; 
  }
  for(int i=0;i<12;i++){
    sprintf(nome_do_arquivo,"vetores/vIntCrescente_%d_P20.dat",(int)pow(2,i+3%15));
    strcpy(arquivos[k], nome_do_arquivo);
    k++;
  }
  for(int i=0;i<12;i++){
    sprintf(nome_do_arquivo,"vetores/vIntCrescente_%d_P30.dat",(int)pow(2,i+3%15));
    strcpy(arquivos[k], nome_do_arquivo);
    k++;
  }
  for(int i=0;i<12;i++){
    sprintf(nome_do_arquivo,"vetores/vIntCrescente_%d_P40.dat",(int)pow(2,i+3%15));
    strcpy(arquivos[k], nome_do_arquivo);
    k++;
  }
  for(int i=0;i<12;i++){
    sprintf(nome_do_arquivo,"vetores/vIntCrescente_%d_P50.dat",(int)pow(2,i+3%15));
    strcpy(arquivos[k], nome_do_arquivo);
    k++;
  }
  for(int i=0;i<12;i++){
    sprintf(nome_do_arquivo,"vetores/vIntDecrescente_%d.dat",(int)pow(2,i+3%15));
    strcpy(arquivos[k], nome_do_arquivo);
    k++;
  }
  for(int i=0;i<12;i++){
    sprintf(nome_do_arquivo,"vetores/vIntDecrescente_%d_P10.dat",(int)pow(2,i+3%15));
    strcpy(arquivos[k], nome_do_arquivo);
    k++;
  }
  for(int i=0;i<12;i++){
    sprintf(nome_do_arquivo,"vetores/vIntDecrescente_%d_P20.dat",(int)pow(2,i+3%15));
    strcpy(arquivos[k], nome_do_arquivo);
    k++;
  }

  for(int i=0;i<12;i++){
      sprintf(nome_do_arquivo,"vetores/vIntDecrescente_%d_P30.dat",(int)pow(2,i+3%15)); 
    strcpy(arquivos[k], nome_do_arquivo);
    k++;
  }
  for(int i=0;i<12;i++){
    sprintf(nome_do_arquivo,"vetores/vIntDecrescente_%d_P40.dat",(int)pow(2,i+3%15));
    strcpy(arquivos[k], nome_do_arquivo);
    k++;
  }
  for(int i=0;i<12;i++){
    sprintf(nome_do_arquivo,"vetores/vIntDecrescente_%d_P50.dat",(int)pow(2,i+3%15));
    strcpy(arquivos[k], nome_do_arquivo);
    k++;
  }
    printf("%d\n",k);
  //strcpy(nome_do_arquivo, "vetores/vIntCrescente_131072.dat");
  // Leia o vetor a partir do arquivo
  //v = leia_vetor_int(nome_do_arquivo, &n);
  printf("%s",arquivos[11]);
  v = leia_vetor_int(arquivos[11],&n);
  
  // Cronometrando o método de ordenação da bolha
  inicio = clock();
  ordena_por_bolha(v,n); 
  fim = clock();
  tempo_de_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

  strcpy(msg, "");
  if (esta_ordenado_int(CRESCENTE,v,n))
     sprintf(msg,
             "bolha: %s ordenado com tempo %.*f s.\n", 
             arquivos[11], DBL_DECIMAL_DIG, tempo_de_cpu);
  else
     sprintf(msg, "bolha: falha na ordenação de %s.\n", arquivos[11]);     
  printf("%s\n", msg);
  
  // Não se esqueça de liberar a memória.
  free(v);
  
  // Leia o vetor a partir do arquivo
  v = leia_vetor_int(arquivos[11], &n);
  
  // Cronometrando o método de ordenação de Shell
  inicio = clock();
  ordena_por_shell(v,n); 
  fim = clock();
  tempo_de_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
  
  strcpy(msg, "");
  if (esta_ordenado_int(CRESCENTE,v,n))
     sprintf(msg,
             "Shell: %s ordenado com tempo %.*f s.\n", 
             arquivos[11], DBL_DECIMAL_DIG, tempo_de_cpu);
  else
     sprintf(msg, "Shell: falha na ordenação de %s.\n", arquivos[11]);
     
  printf("%s\n", msg);
  
  /* Se você não prestou atenção na primeira vez: não se esqueça de 
     liberar a memória. */
  free(v);
  
  exit(0);
}

