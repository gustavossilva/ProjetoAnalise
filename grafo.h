#include <stdio.h>
#include <stdlib.h>
#define maxV 128                   

#define CONFIRME(teste,msg) (                   \
    {if (!(teste)){                             \
      fprintf(stderr, (msg));                   \
      exit(-1);}})
                  
typedef struct graphnode{                        
    int vertex;
    struct graphnode *next;
}Node;

typedef enum tipo {ESPARSO, DENSO} Tipo;

Node** initial(int nv);                                                 
void PrintAdjList(Node **node,int nv);
Node** CriaListAdj(Node **node, char *arq);
void clearList(Node **node,int tam);
int getTamanho(char* arq);
