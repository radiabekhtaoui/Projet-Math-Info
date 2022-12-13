#include "include/lu.h"
#include "include/lu_tridiagonal.h"

#include <time.h>
#include<stdio.h>

#define N 1000 //taille de la matrice

int main()
{
   
    double **a, **l, **u;
    
    // pour stocker le temps d'exécution des fonctions
    double tempsExe_lu,tempsExe_lu_tridia;
     
    int i;

    a = (double**)malloc(N*sizeof(double*));
    l = (double**)malloc(N*sizeof(double*));
    u = (double**)malloc(N*sizeof(double*));
        for(i=0;i<N;i++) {
            a[i] = (double*)malloc(N*sizeof(double));
            l[i] = (double*)malloc(N*sizeof(double));
            u[i] = (double*)malloc(N*sizeof(double));
        }
    
   
    //definir A 
    for(i=1;i<N;i++) {
        a[i-1][i]=-1;
        a[i][i-1]=-1;
        a[i-1][i-1]=2;
        a[N-1][N-1]=2;
    }
   
    clock_t debut1 = clock();
    decompLU(a,l,u,N);
    clock_t fin1 = clock();
 
    // calcule le temps écoulé en trouvant la différence (fin - debut) et divisant la différence par CLOCKS_PER_SEC pour convertir en secondes
    tempsExe_lu = (double)(fin1 - debut1) / CLOCKS_PER_SEC;
 
    //printf("le temps d'execution de LU est : %f seconds\n", tempsExe_lu);
    //de meme pour lu tridiagonale
    clock_t debut2 = clock();
    decompLU_Tridiag(a,l,u,N);
    clock_t fin2 = clock();
    
    tempsExe_lu_tridia = (double)(fin2 - debut2) / CLOCKS_PER_SEC;
 
    //printf("le temps d'execution de LU tridiagonale est : %f seconds\n", tempsExe_lu_tridia);
    if (tempsExe_lu<tempsExe_lu_tridia) printf("LU est plus efficace que LU tridiagonale\n");
    else if (tempsExe_lu>tempsExe_lu_tridia) printf("LU tridiagonale est plus efficace que LU\n");
    else printf("LU et LU tridiagonale revient au meme\n");
 
    return 0;
}