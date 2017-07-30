#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <float.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "grafo.h"
#include "opgrafo.h"

#define BILHAO 1000000000L

#define CRONOMETRA(funcao,grafo,n) {                          \
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &inicio);          \
   funcao(grafo,n);                                           \
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &fim);             \
   tempo_de_cpu_aux = BILHAO * (fim.tv_sec - inicio.tv_sec) +     \
                  fim.tv_nsec - inicio.tv_nsec;               \
   }

int main(int argc, char *argv[]){
    Node **grafo = NULL;
    int n = 0;
    uint64_t tempo_de_cpu_aux = 0;
    int tamanho = 0,count = 0;
    //clock_t inicio, fim;
    struct timespec inicio, fim;
    uint64_t tempo_de_cpu = 0.0;
    char msg[256];
    char nome_do_arquivo[128];
    char **arquivos;
    int k=0,h = 0;
    arquivos = (char**)malloc(200*sizeof(char*));
    for(int i=0;i<100;i++){
        arquivos[i] = (char*)malloc(128*sizeof(char));
    }
    for(int i=128;i<=1024;i=i*2){
        sprintf(nome_do_arquivo,"grafos/grafoEsparso_NV%d",i);
        strcpy(arquivos[k], nome_do_arquivo);
        k++;
    }
    for(int i=128;i<=1024;i=i*2){
        sprintf(nome_do_arquivo,"grafos/grafoDenso_NV%d",i);
        strcpy(arquivos[k], nome_do_arquivo);
        k++;
    }
  //strcpy(nome_do_arquivo, "vetores/vIntCrescente_131072.dat");
  // Leia o vetor a partir do arquivo
  //v = leia_vetor_int(nome_do_arquivo, &n);
    for(int i=0;i<k;i++){
        tempo_de_cpu = 0.0;
        for(int j=0;j<1;j++){
            tamanho = getTamanho(arquivos[i]);
            grafo = CriaListAdj(grafo,arquivos[i]);
        //inicio = clock();
        //ordena_por_bolha(v,n);
        //insertion(v,tamanho);
        //fim = clock();
	    CRONOMETRA(BuscaEmLargura, grafo,tamanho);
        //tempo_de_cpu += ((double) (fim - inicio)) / CLOCKS_PER_SEC;
	    tempo_de_cpu += tempo_de_cpu_aux;
        }
        //PrintAdjList(grafo,tamanho);
        //clearList(grafo,tamanho);
        printf("Tamanho %d ", tamanho);
        printf("Tempo %ld\n",tempo_de_cpu);
    }
  //imprime_vetor_int(v,16384);
    exit(0);
}

