#include "afficher.h"
#include "LU.h"
#include "resoudre.h"
#include "multiplication.h"
#include "test.h"

#define N 4

void decompLU(double **a,double **l,double **u,int n){
   
    u[0][0]=a[0][0];

    //remplir la sous diagonale de L et la diagonale de U

    for(int i=1;i<n;i++){
        
        l[i][i-1]=a[i][i-1]/u[i-1][i-1];

        u[i][i]=a[i][i] - l[i][i-1]*a[i-1][i];
    }

    //remplir la diagonale de L

    for(int i=0;i<n;i++){

        l[i][i]= 1;
    }

    //remplir la sur diagonale de U
    for(int i=1;i<n;i++){

        u[i-1][i]=a[i-1][i];
    }
}

double  *resoudres(double **l,double **u,double *b,int n) {
    double *y,*x;
    
    x=(double*)malloc(sizeof(double)*n);
    y=(double*)malloc(sizeof(double)*n);

    y[0]=b[0];
    for(int i=1;i<n;i++) {
        y[i]=b[i]-l[i][i-1]*y[i-1];
    }
    x[n-1]=y[n-1]/u[n-1][n-1];
    for(int i=n-2;i>=0;i--) {
        x[i]=y[i]-u[i][i+1]*x[i+1]/u[i][i];
    }

    return x;
}
double **multMat(double **a, double **b,int n){
   
    double **c;
    c = (double**)malloc(n*sizeof(double*));
        for(int i=0;i<n;i++) {
            c[i] = (double*)malloc(n*sizeof(double));
        }

    for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                c[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }           
    }
    return c;
}
double *multMatVect(double **a, double *v,int n){
    double *c;
    c = (double*)malloc(n*sizeof(double));

    for(int i=0;i<n;i++) {
        c[i] = 0;
        for(int j=0;j<n;j++) {
            c[i] += a[i][j]*v[j];
        }
    }
    return c;
}
int EgaliteTestMat(double **a, double **b,int n){
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j]!= b[i][j]) return 0;//a!=b
        }
    }
    return 1;//a==b
}
int EgaliteTestvect(double *a, double *b,int n){
    for (int i = 0; i < n; i++) {
        if(a[i]!= b[i]) return 0;//a!=b
    }
    return 1;//a==b
}
//afficher une matrice
void printMat(double **a,int n) {
  int i,j;

  for(i=0;i<n;i++) {
    for(j=0;j<n;j++) {
        printf("%0.2lf \t",a[i][j]);
    };
    printf("\n");
  }
}
void printVect(double *x,int n){
    for(int i=0;i<n;i++) {
        printf("%0.2lf \t",x[i]);
    }
    printf("\n");
}


int main(){
    double **a, **l, **u, *b ,*x;
    int i;

    a = (double**)malloc(N*sizeof(double*));
        for(i=0;i<N;i++) {
            a[i] = (double*)malloc(N*sizeof(double));
        }
    
  for(i=1;i<N;i++) {
    a[i-1][i]=-1;
    a[i][i-1]=-1;
    a[i-1][i-1]=2;
    a[N-1][N-1]=2;
  }

    l = (double**)malloc(N*sizeof(double*));
        for(i=0;i<N;i++) {
            l[i] = (double*)malloc(N*sizeof(double));
        }  

    u = (double**)malloc(N*sizeof(double*));
        for(i=0;i<N;i++) {
            u[i] = (double*)malloc(N*sizeof(double));
        }
    b= (double*)malloc(sizeof(double)*N);
  
  printf("Matrice A :\n");
  printMat(a,N);
  
  //LU TRIDIAGGONALE
  decompLU(a,l,u,N);
  
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
    b[i]=1*i;
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
  
  printf("solution x:\n");
  printVect(x,N);
  
  return 0;
}