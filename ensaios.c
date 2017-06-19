#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <float.h>
#include <math.h>

#include "vetor.h"
#include "ordena.h"

int main(int argc, char *argv[]){
  int * v = NULL;
  int n = 0;
  int tamanho = 0,count = 0;
  clock_t inicio, fim;
  double tempo_de_cpu = 0.0;
  char msg[256];
  char nome_do_arquivo[128];
  char **arquivos;
  int k=0,h = 0;
  arquivos = (char**)malloc(200*sizeof(char*));
  for(int i=0;i<200;i++){
    arquivos[i] = (char*)malloc(128*sizeof(char));
  }
  
  for(int i=0;i<11;i++){
    sprintf(nome_do_arquivo,"vetores/vIntAleatorio_%d.dat",(int)pow(2,i+4%15));
    strcpy(arquivos[k], nome_do_arquivo);
    k++;
  }
  for(int i=0;i<11;i++){
    sprintf(nome_do_arquivo,"vetores/vIntCrescente_%d.dat",(int)pow(2,i+4%15));
    strcpy(arquivos[k], nome_do_arquivo);
    k++;
    
  }
  for(int i=0;i<11;i++){
    sprintf(nome_do_arquivo,"vetores/vIntCrescente_%d_P10.dat",(int)pow(2,i+4%15));
    strcpy(arquivos[k], nome_do_arquivo);
    k++; 
  }
  for(int i=0;i<11;i++){
    sprintf(nome_do_arquivo,"vetores/vIntCrescente_%d_P20.dat",(int)pow(2,i+4%15));
    strcpy(arquivos[k], nome_do_arquivo);
    k++;
  }
  for(int i=0;i<11;i++){
    sprintf(nome_do_arquivo,"vetores/vIntCrescente_%d_P30.dat",(int)pow(2,i+4%15));
    strcpy(arquivos[k], nome_do_arquivo);
    k++;
  }
  for(int i=0;i<11;i++){
    sprintf(nome_do_arquivo,"vetores/vIntCrescente_%d_P40.dat",(int)pow(2,i+4%15));
    strcpy(arquivos[k], nome_do_arquivo);
    k++;
  }
  for(int i=0;i<11;i++){
    sprintf(nome_do_arquivo,"vetores/vIntCrescente_%d_P50.dat",(int)pow(2,i+4%15));
    strcpy(arquivos[k], nome_do_arquivo);
    k++;
  }
  for(int i=0;i<11;i++){
    sprintf(nome_do_arquivo,"vetores/vIntDecrescente_%d.dat",(int)pow(2,i+4%15));
    strcpy(arquivos[k], nome_do_arquivo);
    k++;
  }
  for(int i=0;i<11;i++){
    sprintf(nome_do_arquivo,"vetores/vIntDecrescente_%d_P10.dat",(int)pow(2,i+4%15));
    strcpy(arquivos[k], nome_do_arquivo);
    k++;
  }
  for(int i=0;i<11;i++){
    sprintf(nome_do_arquivo,"vetores/vIntDecrescente_%d_P20.dat",(int)pow(2,i+4%15));
    strcpy(arquivos[k], nome_do_arquivo);
    k++;
  }

  for(int i=0;i<11;i++){
      sprintf(nome_do_arquivo,"vetores/vIntDecrescente_%d_P30.dat",(int)pow(2,i+4%15)); 
    strcpy(arquivos[k], nome_do_arquivo);
    k++;
  }
  for(int i=0;i<11;i++){
    sprintf(nome_do_arquivo,"vetores/vIntDecrescente_%d_P40.dat",(int)pow(2,i+4%15));
    strcpy(arquivos[k], nome_do_arquivo);
    k++;
  }
  for(int i=0;i<11;i++){
    sprintf(nome_do_arquivo,"vetores/vIntDecrescente_%d_P50.dat",(int)pow(2,i+4%15));
    strcpy(arquivos[k], nome_do_arquivo);
    k++;
  }
    printf("%d\n",k);
  //strcpy(nome_do_arquivo, "vetores/vIntCrescente_131072.dat");
  // Leia o vetor a partir do arquivo
  //v = leia_vetor_int(nome_do_arquivo, &n);
  printf("%s\n",arquivos[11]);
  for(int i=0;i<k;i++){
    tempo_de_cpu = 0.0;
    if(h > 10){
        h = 0;
    }
    for(int j=0;j<3;j++){
        v = leia_vetor_int(arquivos[i],&n);
        tamanho = (int)pow(2,h+4%15);
        inicio = clock();
        //ordena_por_bolha(v,n);
        quick(v,0,tamanho);
        fim = clock();
        tempo_de_cpu += ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    }
    if(esta_ordenado_int(CRESCENTE,v,n) && count < 11){
        printf("Tempo do vetor aleatorio tamanho %d: %lf\n",tamanho,tempo_de_cpu/3);
    }
    else if(esta_ordenado_int(CRESCENTE,v,n) && count < 22){
        printf("Tempo do vetor Crescente tamanho %d: %lf\n",tamanho,tempo_de_cpu/3);
    }
    else if(esta_ordenado_int(CRESCENTE,v,n) && count < 33){
        printf("Tempo do vetor Crescente P10 tamanho %d: %lf\n",tamanho,tempo_de_cpu/3);
    }
    else if(esta_ordenado_int(CRESCENTE,v,n) && count < 44){
        printf("Tempo do vetor Crescente P20 tamanho %d: %lf\n",tamanho,tempo_de_cpu/3);
    }
    else if(esta_ordenado_int(CRESCENTE,v,n) && count < 55){
        printf("Tempo do vetor Crescente P30 tamanho %d: %lf\n",tamanho,tempo_de_cpu/3);
    }
    else if(esta_ordenado_int(CRESCENTE,v,n) && count < 66){
        printf("Tempo do vetor Crescente P40 tamanho %d: %lf\n",tamanho,tempo_de_cpu/3);
    }
    else if(esta_ordenado_int(CRESCENTE,v,n) && count < 77){
        printf("Tempo do vetor Crescente P50 tamanho %d: %lf\n",tamanho,tempo_de_cpu/3);
    }
    else if(esta_ordenado_int(CRESCENTE,v,n) && count < 88){
        printf("Tempo do vetor Decrescente tamanho %d: %lf\n",tamanho,tempo_de_cpu/3);
    }
    else if(esta_ordenado_int(CRESCENTE,v,n) && count < 99){
        printf("Tempo do vetor Decrescente P10 tamanho %d: %lf\n",tamanho,tempo_de_cpu/3);
    }
    else if(esta_ordenado_int(CRESCENTE,v,n) && count < 110){
        printf("Tempo do vetor Decrescente P20 tamanho %d: %lf\n",tamanho,tempo_de_cpu/3);
    }
    else if(esta_ordenado_int(CRESCENTE,v,n) && count < 121){
        printf("Tempo do vetor Decrescente P30 tamanho %d: %lf\n",tamanho,tempo_de_cpu/3);
    }
    else if(esta_ordenado_int(CRESCENTE,v,n) && count < 132){
        printf("Tempo do vetor Decrescente P40 tamanho %d: %lf\n",tamanho,tempo_de_cpu/3);
    }
    else if(esta_ordenado_int(CRESCENTE,v,n) && count < 143){
        printf("Tempo do vetor Decrescente P50 tamanho %d: %lf\n",tamanho,tempo_de_cpu/3);
    }
    else{
        printf("Erro em ordenção do vetor %d, arquivo %s",i,arquivos[i]);
    }
    h++;
    count++;
  }
  
  free(v);
  exit(0);
}

