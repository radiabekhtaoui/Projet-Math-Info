#include "include/afficher.h"
#include "include/lu.h"
#include "include/lu_tridiagonal.h"
#include "include/resoudre.h"
#include "include/multiplication.h"
#include "include/test.h"

#define N 3

int main(){
    double **a, **l, **u, *b ,*x, *m;
    int i;

    a = (double**)malloc(N*sizeof(double*));
    l = (double**)malloc(N*sizeof(double*));
    u = (double**)malloc(N*sizeof(double*));
        for(i=0;i<N;i++) {
            a[i] = (double*)malloc(N*sizeof(double));
            l[i] = (double*)malloc(N*sizeof(double));
            u[i] = (double*)malloc(N*sizeof(double));
        }
    b= (double*)malloc(sizeof(double)*N);
  //definir A 
  for(i=1;i<N;i++) {
    a[i-1][i]=-1;
    a[i][i-1]=-1;
    a[i-1][i-1]=2;
    a[N-1][N-1]=2;
  }
  
  printf("Matrice A :\n");
  printMat(a,N);

  //LU 
  //decompLU(a,l,u,N);
  
  //LU TRIDIAGGONALE
  decompLU_Tridiag(a,l,u,N);
  
  //test unitaire de la decomposition LU
  if(!EgaliteTestMat(multMat(l,u,N),a,N)){
    printf("Erreur lors de la decomposition LU : A != L*U\n");
    return EXIT_FAILURE;
  }

  printf("Matrice L :\n");
  printMat(l,N);
  printf("Matrice U :\n");
  printMat(u,N);
  
  //definir b:
  for (i=0;i<N;i++){
    b[i]=1;
  }
  printf("b:\n");
  printVect(b,N);
  
  //resoudre le systeme:
  x=resoudres(l,u,b,N);
  
  //test unitaire de la solution :
  if(!EgaliteTestvect(multMatVect(a,x,N),b,N)){
    printf("Erreur de solution : AX!= B\n");
    return EXIT_FAILURE;
  }
  printf("solution X:\n");
  printVect(x,N);

  return 0;
}