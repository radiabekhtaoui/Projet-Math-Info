#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

double **multMat(double **a, double **b,int n){
   
    double **c;
    c = (double**)malloc(n*sizeof(double*));
        for(int i=0;i<n;i++) {
            c[i] = (double*)malloc(n*sizeof(double));
        }

    for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
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
        for(int j=0;j<n;j++) {
            c[i] += a[i][j]*v[j];
        }
    }
    return c;
}
#endif