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

#include "vetor.h"
#include "final.h"

#define BILHAO 1000000000L

#define CRONOMETRA(funcao,vetor,vetor2,n) {                          \
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &inicio);          \
   funcao(vetor,vetor2,n);                                           \
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &fim);             \
   tempo_de_cpu_aux = BILHAO * (fim.tv_sec - inicio.tv_sec) +     \
                  fim.tv_nsec - inicio.tv_nsec;               \
   }

int main(int argc, char *argv[]){
  int * v = NULL;
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
  int s[16],f[16];
  int s1[32],f1[32];
  int s2[64],f2[64];
  int s3[128],f3[128];
  int s4[256],f4[256];
  int s5[512],f5[512];
  int s6[1024],f6[1024];
  int s7[2048],f7[2048];
  int s8[4096],f8[4096];
  int s9[8192],f9[8192];
  int s10[16384],f10[16384];
  srand(time(NULL));
  for(int i=0;i<16;i++){
  if(i == 0){
	s[0] = 0;
        f[0] = rand();}
  else{
      s[i] = f[i-1] + 1;
      f[i] = rand();}
}
  for(int i=0;i<32;i++){
  if(i == 0){
	s1[0] = 0;
        f1[0] = rand();}
  else{
      s1[i] = f1[i-1] + 1;
      f1[i] = rand();}
}
  for(int i=0;i<64;i++){
  if(i == 0){
	s2[0] = 0;
        f2[0] = rand();}
  else{
      s2[i] = f2[i-1] + 1;
      f2[i] = rand();}
}
  for(int i=0;i<128;i++){
  if(i == 0){
	s3[0] = 0;
        f3[0] = rand();}
  else{
      s3[i] = f3[i-1] + 1;
      f3[i] = rand();}
}
  for(int i=0;i<256;i++){
  if(i == 0){
	s4[0] = 0;
        f4[0] = rand();}
  else{
      s4[i] = f4[i-1] + 1;
      f4[i] = rand();}
}
  for(int i=0;i<512;i++){
  if(i == 0){
	s5[0] = 0;
        f5[0] = rand();}
  else{
      s5[i] = f5[i-1] + 1;
      f5[i] = rand();}
}
  for(int i=0;i<1024;i++){
  if(i == 0){
	s6[0] = 0;
        f6[0] = rand();}
  else{
      s6[i] = f6[i-1] + 1;
      f6[i] = rand();}
}
  for(int i=0;i<2048;i++){
  if(i == 0){
	s7[0] = 0;
        f7[0] = rand();}
  else{
      s7[i] = f7[i-1] + 1;
      f7[i] = rand();}
}
  for(int i=0;i<4096;i++){
  if(i == 0){
	s8[0] = 0;
        f8[0] = rand();}
  else{
      s8[i] = f8[i-1] + 1;
      f8[i] = rand();}
}
    tempo_de_cpu = 0.0;
    if(h > 10){
        h = 0;
    }
  for(int i=0;i<8192;i++){
  if(i == 0){
	s9[0] = 0;
        f9[0] = rand();}
  else{
      s9[i] = f9[i-1] + 1;
      f9[i] = rand();}
}
    tempo_de_cpu = 0.0;
    if(h > 10){
        h = 0;
    }
  for(int i=0;i<16384;i++){
  if(i == 0){
	s10[0] = 0;
        f10[0] = rand();}
  else{
      s10[i] = f10[i-1] + 1;
      f10[i] = rand();}
}
    tempo_de_cpu = 0.0;
    if(h > 10){
        h = 0;
    }
  int *g[15] = {s,s1,s2,s3,s4,s5,s6,s7,s8};
  int *l[15] = {f,f1,f2,f3,f4,f5,f6,f7,f8};
    for(int j=0;j<3;j++){
        tamanho = 16384;
        /*inicio = clock();
        //ordena_por_bolha(v,n);
        insertion(v,tamanho);
        fim = clock();*/
	CRONOMETRA(seletorgulosoativades, s10,f10,tamanho);
        //tempo_de_cpu += ((double) (fim - inicio)) / CLOCKS_PER_SEC;
	tempo_de_cpu += tempo_de_cpu_aux;

        printf("Tempo do vetor Crescente tamanho %d: %llu\n",tamanho,(long long unsigned int)tempo_de_cpu/(uint64_t) 3);

    }
    h++;
    count++;
  //imprime_vetor_int(v,16384);
  free(v);
  exit(0);
}

