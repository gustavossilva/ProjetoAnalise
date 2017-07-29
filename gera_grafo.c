#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "grafo.h"

#define POT2(n) (1 << (n))





void gera_e_salva_graf(int n, Tipo t){
//  int * v = NULL;
  char nome_do_arquivo[64];
  char sufixo[10];

  switch (t){
    case ESPARSO: 
      sprintf(nome_do_arquivo, "grafoEsparso_NV%d", n);
      break;
    case DENSO:
      sprintf(nome_do_arquivo, "grafoDenso_NV%d", n);
      break;
    default: break; //CONFIRME(false, 
                      //"gera_e_salva_graf: Ordenação desconhecida");
  }
  escreve_grafo(n,t,nome_do_arquivo);
}

void escreve_grafo(int n, Tipo t, char* arq){
    int i,j;
    FILE* fd = NULL;
    
    fd = fopen(arq,"w");
    
    fprintf(fd, "%d\n", n);
    switch(t){
        case ESPARSO:
            for(i=1;i<n;i++){
                fprintf(fd,"%d %d\n", i, i+1);
            }
            fprintf(fd,"%d",n);
            break;
        case DENSO:
            for(i=1;i<n;i++){
                for(j=1;j<=n;j++){
                    if(i!=j){
                        fprintf(fd,"%d %d\n",i, j);
                    }
                }
            }
            fprintf(fd,"%d",n);        
            break;
        default: 
            break; 
    }
}


int main(int argc, char *argv[]){
  int n = 0;
  int p = 0;
  char diretorio[256];
  
  struct stat st = {0};

  
  if (argc == 2)
    strcpy(diretorio, argv[1]);
  else
    strcpy(diretorio, "./grafos");

  if (stat(diretorio, &st) == -1) { // se o diretorio não existir,
    mkdir(diretorio, 0700);         // crie um
  }

  CONFIRME(chdir(diretorio) == 0, "Erro ao mudar de diretório");
  
  for(int i = 128; i<=1024;i=(i*2)){
    gera_e_salva_graf(i, ESPARSO);
    gera_e_salva_graf(i, DENSO);
  
  }
  
  //CONFIRME(chdir("..") == 0, "Erro ao mudar de diretório");
  
  exit(0);
}

