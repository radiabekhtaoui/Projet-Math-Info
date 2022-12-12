#ifndef LU_H
#define LU_H

#include<stdlib.h>


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
#endif