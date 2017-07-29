#include "grafo.h"

//Node **node;                             

//FILE *fp;

/*int main()
{
    int nv;

    //fp= fopen("./grafos/grafoDenso_NV1024","r");
    //fscanf(fp,"%d",&nv);
    //initial(nv);
    //CriaListAdj();
    //PrintAdjList(nv);

    return 0;
}*/



Node** initial(int nv)
{
    return (Node **)malloc(nv * sizeof(Node *));
}



//CREATE ADJACENCY  LIST - 
Node** CriaListAdj(Node **node, char *arq)
{
    FILE *fp = NULL;
    int nv;
    fp = fopen(arq,"r");
    if(fscanf(fp,"%d",&nv))
        printf("ok!");
    node = initial(nv);
    int v1,v2;
    Node *ptr;
    while(fscanf(fp,"%d %d",&v1,&v2)!=EOF){
        ptr = (Node *)malloc(sizeof(Node));
        ptr->vertex = v2;
        //Se o vertice não foi mapeado ainda
        if (node[v1]==NULL) {
            node[v1] = (Node *)malloc(sizeof(Node));
            node[v1]->vertex = v1;
            node[v1]->next = NULL;
        }
        Node *next = node[v1];
        while (next->next!=NULL)
            next = next->next;

        next->next = ptr;
    }
    //PrintAdjList(node,nv);
    fclose(fp);
   return node;
}

int getTamanho(char *arq){
    FILE *fp = NULL;
    int nv;
    fp = fopen(arq,"r");
    if(fscanf(fp,"%d",&nv));
    return nv;
}

void clearList(Node **node,int tam){
    for(int i=1;i<=tam;i++){
        Node* aux = node[i];
        Node* tmp;
        while(aux!=NULL){
            tmp = aux->next;
            free(aux);
            aux = tmp;
        }
        free(node[i]);
    }
    free(node);
}

//PRINT LIST
void PrintAdjList(Node** node,int nv)
{
    int i;
    Node *ptr;

    for(i=1; i<=nv; i++){
        ptr = node[i]->next;
        printf("    node[%2d]  ",i);
        while(ptr != NULL){
            printf("  -->%2d", ptr->vertex);
            ptr=ptr->next;
        }
        printf("\n");
    }
    printf("\n");
}
