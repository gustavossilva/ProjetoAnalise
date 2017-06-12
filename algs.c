//
// Created by guilherme on 6/11/17.
//
#include <stdio.h>
#include <math.h>


int main() {
    int v[10] = {1,7,5,654,12,3,48,7,5,6};
    int p = 10/2;
    int r = 10;
    ordena_intercala(v,p,r);
}

void ordena_intercala(int * v,int p,int r)
{
    if (p < r) {
        int q = floor((p + r) / 2); // retorna o chão dessa operação
        ordena_intercala (v, p, q);
        ordena_intercala(v, q + 1, r);
        intercala(v, p, q, r);
    }
}
void intercala(int * v,int p, int q, int r)
{
    int B[10];
    int n = 10;
    int i,k,j;
    q = n/2;
    r = n;
    p = 0;
    for (i = p; i<q; i++)
        B[i] = v[i];
    for (j = (q + 1); j< r;j++)
        B[(r + q + 1 - j)] = v[j];
    i = p;
    j = r;
    for(k = p; k<r; k++) {
        if (B[i] <= B[j])
        {
            v[k] = B[i];
            i = (i+1);
        }
        else
        {
            v[k] = B[j];
            j = (j-1);
        }

    }

    for(i = 0; i<10;i++)
    {
        printf("%d ",v[i]);
    }
}

void insertion()
{
    int v[10] = {1,7,5,654,12,3,48,7,5,6};
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
    for(i = 0; i<10;i++)
    {
        printf("%d ",v[i]);
    }
}
