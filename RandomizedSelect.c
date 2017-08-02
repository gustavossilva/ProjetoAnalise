#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include<time.h>
#include <stdint.h>
#include<math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "vetor.h"
#include "ordena.h"

#define BILHAO 1000000000L

#define CRONOMETRA(funcao,vetor,p,r,max) {                          \
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &inicio);          \
   funcao(vetor,p,r,max);                                           \
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &fim);             \
   tempo_de_cpu_aux = BILHAO * (fim.tv_sec - inicio.tv_sec) +     \
                  fim.tv_nsec - inicio.tv_nsec;               \
   }


int partition(int a[], int p, int r){
    int x = a[r];
    int i = p-1;
    int aux;
    for(int j = p; j < r; j++){
        if(a[j] <= x){
            i++;
            aux = a[i];
	    a[i] = a[j];
	    a[j] = aux;
        }
    }
    aux = a[i+1];
    a[i+1] = a[r];
    a[r] = aux;
    return i+1;
}


int particao_aleatoria(int a[], int p, int r){
    int i = rand() % r + 1; 
     int aux = a[i];
     a[i] = a[r];
     a[r] = aux;
    return partition(a, p, r);
}

int particao_mediana(int a[], int p, int r){
    int i = rand() % r + 1; 
     int aux = a[i];
     a[i] = a[r];
     a[r] = aux;
    return partition(a, p, r);
}


int selecao_aleatoria(int a[], int p, int r, int i)
{
    if(p==r)
        return a[p];
    int q = particao_aleatoria(a,p,r);
    int k = q-p+1;
    if(i == k)
        return a[q];
    else if(i < k)
        return selecao_aleatoria(a, p, q-1, i);
    else return selecao_aleatoria(a, q+1, r, i-k);
}

int main(){
 int r = 0;
 int * v = NULL;
struct timespec inicio, fim;
uint64_t tempo_de_cpu = 0.0;
uint64_t tempo_de_cpu_aux = 0;
srand(time(NULL));
int tamanho = 0;
int count = 0;
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

for(int n = 0; n <= k; n++)
{
if(h > 10){
        h = 0;
    }
tempo_de_cpu = 0.0;


for(int j = 0; j<3; j++){
	v = leia_vetor_int(arquivos[n],&r);
	tamanho = (int)pow(2,h+4%15);
	int A[tamanho];
	 for(int i =0; i<tamanho; i++)
	 	A[i] = rand()%20000;
	CRONOMETRA(selecao_aleatoria, A,0,tamanho-1,rand()%tamanho + 1);
	tempo_de_cpu += tempo_de_cpu_aux;
	}
	if(count < 11)
		printf("Tempo do vetor aleatorio tamanho %d: %llu\n",tamanho,(long long unsigned int)tempo_de_cpu/(uint64_t) 3);
            else if(count < 22){
        printf("Tempo do vetor Crescente tamanho %d: %llu\n",tamanho,(long long unsigned int)tempo_de_cpu/(uint64_t) 3);
    }
    else if(count < 33){
        printf("Tempo do vetor Crescente P10 tamanho %d: %llu\n",tamanho,(long long unsigned int)tempo_de_cpu/(uint64_t) 3);
    }
    else if(count < 44){
        printf("Tempo do vetor Crescente P20 tamanho %d: %llu\n",tamanho,(long long unsigned int)tempo_de_cpu/(uint64_t) 3);
    }
    else if( count < 55){
        printf("Tempo do vetor Crescente P30 tamanho %d: %llu\n",tamanho,(long long unsigned int)tempo_de_cpu/(uint64_t) 3);
    }
    else if(count < 66){
        printf("Tempo do vetor Crescente P40 tamanho %d: %llu\n",tamanho,(long long unsigned int)tempo_de_cpu/(uint64_t) 3);
    }
    else if(count < 77){
        printf("Tempo do vetor Crescente P50 tamanho %d: %llu\n",tamanho,(long long unsigned int)tempo_de_cpu/(uint64_t) 3);
    }
    else if(count < 88){
        printf("Tempo do vetor Decrescente tamanho %d: %llu\n",tamanho,(long long unsigned int)tempo_de_cpu/(uint64_t) 3);
    }
    else if(count < 99){
        printf("Tempo do vetor Decrescente P10 tamanho %d: %llu\n",tamanho,(long long unsigned int)tempo_de_cpu/(uint64_t) 3);
    }
    else if(count < 110){
        printf("Tempo do vetor Decrescente P20 tamanho %d: %llu\n",tamanho,(long long unsigned int)tempo_de_cpu/(uint64_t) 3);
    }
    else if(count < 121){
        printf("Tempo do vetor Decrescente P30 tamanho %d: %llu\n",tamanho,(long long unsigned int)tempo_de_cpu/(uint64_t) 3);
    }
    else if(count < 132){
        printf("Tempo do vetor Decrescente P40 tamanho %d: %llu\n",tamanho,(long long unsigned int)tempo_de_cpu/(uint64_t) 3);
    }
    else {
        printf("Tempo do vetor Decrescente P50 tamanho %d: %llu\n",tamanho,(long long unsigned int)tempo_de_cpu/(uint64_t) 3);
     }
	h++;
	count++;
}
free(v);

}


