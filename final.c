#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"
#include <math.h>
#include<limits.h>
#include "final.h"

int min(int A[],int n){
	int min = A[0];
	for(int i = 1; i < n; i++)
	{
		if(min > A[i])
			min = A[i];
	}
	return min;
}

int * min_max(int A[], int n){
	int min = A[0];
	int max = A[0];
	int *resultado = (int*) malloc(2*sizeof(int));
	int i;
	for(i=1; i<n; i++){
		if (min > A[i])
			min = A[i];
		if (max < A[i])
			max = A[i];
	}
	resultado[0] = min;
	resultado[1] = max;
	return resultado;
}

 int getMax(int first, int second)
{
    return first > second ? first : second;
}

int corte_haste(int  *p,int n){
	int i;
	if (n <= 0)
		return 0;
	int q = INT_MIN;
	for (i=0;i<n;i++)
		{
			q = getMax(q,p[i] + corte_haste(p,n-i-1));
		}
	return q;
}

int corte_haste_memorizado(int *p, int n){
	int r[n+1];
	for(int i=0;i<n;i++)
		r[i] = INT_MIN;
	int i;
	return corte_haste_memorizado_aux(p,n,r);
}

int corte_haste_memorizado_aux(int *p,int n, int r[]){
	int q,i;	
	if(r[n] > 0)
		return r[n];
	if (n== 0)
		q=0;
	else {
		q = INT_MIN;
		for(i = 0; i<n; i++)
			q = getMax(q,p[i] + corte_haste_memorizado_aux(p,n-i-1,r));
	}
	r[n] = q;
	return q;
}


int corte_haste_bottom_up(int *p, int n){
	int val[n+1];
   val[0] = 0;
   int i, j;
 
   for (i = 1; i<=n; i++)
   {
       int max_val = INT_MIN;
       for (j = 0; j < i; j++)
        		 max_val = getMax(max_val, p[j] + val[i-j-1]);
       val[i] = max_val;
   }
 
   return val[n];
}

int parentizacao_recursiva(int p[], int i, int j)
{
    if(i == j)
        return 0;
    int k;
    int min = INT_MAX;
    int count;
 
    for (k = i; k <j; k++)
    {
        count = parentizacao_recursiva(p, i, k) +
                parentizacao_recursiva(p, k+1, j) +
                p[i-1]*p[k]*p[j];
 
        if (count < min)
            min = count;
    }
 
    return min;
}

int parentizacao_bottomup(int p[], int n)
{
    int m[n][n];
 
    int i, j, k, L, q;
 

    for (i=1; i<n; i++)
        m[i][i] = 0;
 
    for (L=2; L<n; L++)
    {
        for (i=1; i<n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;
            for (k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    return m[1][n-1];
}
int scm_recursiva( char *X, char *Y, int m, int n )
{
   if (m == 0 || n == 0)
     return 0;
   if (X[m-1] == Y[n-1])
     return 1 + scm_recursiva(X, Y, m-1, n-1);
   else
     return getMax(scm_recursiva(X, Y, m, n-1), scm_recursiva(X, Y, m-1, n));
}

int scm( char *X, char *Y, int m, int n )
{
   int L[m+1][n+1];
   int i, j;
  
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
  
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = getMax(L[i-1][j], L[i][j-1]);
     }
   }
    
   return L[m][n];
}

void seletorgulosoativades(int s[], int f[], int n) //Iterativo
{
    int i, j;
    i = 0;
    //A primeira é selecionada
    for (j = 1; j < n; j++)
    {
      if (s[j] >= f[i])
      {
          //selecionou a atividade j
          i = j;
      }
    }
}
int SeletorRecursivoAtividades(int s[],int f[],int k,int n) //Recursivo
{
int m = k + 1;
while (m <= n && s[m] < f[k]) // Encontre a primeira atividade em Sk a terminar
	m = m + 1;
if (m <= n)
	return SeletorRecursivoAtividades(s, f, m, n); // teria que gerar um conjunto, porém farei retornar 0 é śo para rodar o código;
else 
	return 0;
}

void mochila(int quantidades[], int valores[],int n){
	int P = 50;
	int N = n;
	float valores_unitarios[N];
	int itensId[N];
	float porcentagemAdicionada[N];
	int peso = 0;
	float valorMochila = 0;
	int i;
	for(i = 0; i < N; i++){
		itensId[i] = i;
		porcentagemAdicionada[i] = 0.0;
		valores_unitarios[i] = valores[i] / quantidades[i];
	}
	// ordenar por valor unitario
	int key, keyId, j;
   	for (i = 1; i < N; i++){
        key = valores_unitarios[i];
        keyId = itensId[i];
        j = i-1;
 
        while (j >= 0 && valores_unitarios[j] > key){
            valores_unitarios[j+1] = valores_unitarios[j];
            itensId[j+1] = itensId[j];
            j = j-1;
        }
    	valores_unitarios[j+1] = key;
        itensId[j+1] = keyId;
   	}

	i = N-1;
	peso = 0;
	valorMochila = 0;
	int cabe;
	float porcentagem;
	while(peso <= P && i >= 0){
		if(peso + quantidades[itensId[i]] > P){
			cabe = P - peso;
			porcentagem = (float)cabe / (float)quantidades[itensId[i]];
			//printf("Porcentagem : %lf\n", porcentagem);
			porcentagemAdicionada[itensId[i]] = porcentagem;
			peso += cabe;
			valorMochila += valores[itensId[i]] * cabe;
			//printf("Adicionado item %d com quantidade %d\n", itensId[i], cabe);		
		}
		else{
			porcentagemAdicionada[itensId[i]] = 1;
			peso += quantidades[itensId[i]];
			valorMochila += valores[itensId[i]];
			//printf("Adicionado item %d com quantidade %d\n", itensId[i], quantidades[itensId[i]]);	
		}
		i--;	
	}
}


