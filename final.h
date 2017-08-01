#ifndef _FINAL_H
#define _FINAL_H


int min(int A[],int n);
int * min_max(int *A, int n);
int getMax(int first, int second);
int corte_haste(int  *p,int n);
int corte_haste_memorizado(int *p, int n);
int corte_haste_memorizado_aux(int *p,int n, int r[]);
int corte_haste_bottom_up(int *p, int n);

//op em matrizes
int parentizacao_recursiva(int p[], int i, int j);
int parentizacao_bottomup(int p[], int n);
int scm_recursiva( char *X, char *Y, int m, int n );
int scm( char *X, char *Y, int m, int n );

//Gulosos
void seletorgulosoativades(int s[], int f[], int n);
int SeletorRecursivoAtividades(int s[],int f[],int k,int n);
#endif
