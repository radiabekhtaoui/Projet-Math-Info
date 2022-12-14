#include "include/afficher.h"
#include "include/lu.h"
#include "include/lu_tridiagonal.h"
#include "include/resoudre.h"
#include "include/multiplication.h"
#include "include/test.h"

// parametres de discretisation
#define N  5   // nombre de points de discretisation
#define H  1.0/(N+1)   // le pas d'espace uniforme h = 1/(n+1)
// conditions de Dirichlet
#define ALPHA 0  //condition limite u(O)
#define BETA 0  // condition limite u(1)
// fonction à resoudre ici j'ai choisit s(x)= 4π²sin(2πx)
double s(double x) {
    return 4 * M_PI * M_PI * sin(2 * M_PI * x);
}
//fonction maillage 
double *maillage(int n)
{ 
    // Créer un tableau pour stocker les points du maillage
    double *x = malloc(n+2 * sizeof(double));

    for (int i = 0; i <= n+1; i++)
    {
        x[i] =i * H;
    }

    return x;
}
int main(){
    double **a, **l, **u, *b ,*m,*x;
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
    a[i-1][i]=-1/(H*H);
    a[i][i-1]=-1/(H*H);
    a[i-1][i-1]=2/(H*H);
    a[N-1][N-1]=2/(H*H);
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
  
  /*calcul des valeurs de b sur chaque point de discretisation
  m = maillage(N);
  definir b:
  b[0]= s(x[1])+(ALPHA/(H*H));
  b[N-1]= s(x[N-1])+(BETA/(H*H));
  for (int i = 1; i < N-1; i++){
      b[i]=s(x[i]);
  }
  
  printf("b:\n");
  printVect(b,N);*/
  
  for (i=0;i<N;i++){
    b[i]=1;
  }
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