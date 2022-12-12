#ifndef RESOUDRE_H
#define RESOUDRE_H


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
        x[i]=(y[i]-u[i][i+1]*x[i+1])/u[i][i];
    }

    return x; 
}

#endif