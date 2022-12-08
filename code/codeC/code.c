#include<stdlib.h>
#include<stdio.h>

#define N 6

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
        printf("%lf \t",x[i]);
    }
    printf("\n");
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

int main(){
    double **a, **l, **u, *b ,*x;
    int i;

    a = (double**)malloc(N*sizeof(double*));
        for(i=0;i<N;i++) {
            a[i] = (double*)malloc(N*sizeof(double));
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

  for(i=1;i<N;i++) {
    a[i-1][i]=-1;
    a[i][i-1]=-1;
    a[i-1][i-1]=2;
    a[N-1][N-1]=2;
  }

  for (i=0;i<N;i++){
    b[i]=1;
  }

  printf("Matrice A :\n");
  printMat(a,N);
  decompLU(a,l,u,N);
  printf("Matrice L :\n");
  printMat(l,N);
  printf("Matrice U :\n");
  printMat(u,N);
  x=resoudres(l,u,b,N);
  printf("solution x:\n");
  printVect(x,N);

  return 0;
}