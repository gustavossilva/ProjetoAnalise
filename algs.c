//
// Created by guilherme on 6/11/17.
//
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void insertion(int * v);
void ordena_intercala(int * v,int p,int r);
void intercala(int * v,int p, int q, int r);

int main() {
    int v[10] = {1,2,3,4,7,8,9,5,15,654};
    int p = 0;
    int r = 9;
    ordena_intercala(v,0,r);
//    insertion(v);
    for(int i =0; i<= r; i++)
    {
        printf("%d ",v[i]);
    }
}

void ordena_intercala(int * v,int p,int r)
{
    int q;
    if (p < r) {
        q = floor((p + r) / 2); // retorna o chão dessa operação
        ordena_intercala (v, p, q);
        ordena_intercala(v, q + 1, r);
        intercala(v, p, q, r);
    }
}

void intercala(int * v,int p, int q, int r)
{
    int B[10];
    int i,k,j;
    for (i = p; i<=q; i++)
        B[i] = v[i];
    for (j = (q + 1); j<= r;j++) {
        B[(r + q + 1 - j)] = v[j];
    }
    i = p;
    j = r;
    for(k = p; k<=r; k++) {
            if (B[i] <= B[j]) {
                v[k] = B[i];
                i++;
            } else {
                v[k] = B[j];
                j--;
            }
    }
}

void insertion(int *v)
{
    int chave,i,j;
    for(j=2;j<10;j++)
    {
        chave = v[j];
        i = j - 1;
        while (i > 0 && v[i] > chave)
        {
            v[i+1] = v[i];
            i = i-1;
            v[i+1] = chave;
        }
    }
}
