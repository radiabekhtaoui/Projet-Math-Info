#ifndef AFFICHER_H
#define AFFICHER_H

#include<stdio.h>

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

#endif