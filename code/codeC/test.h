#ifndef TEST_H
#define TEST_H

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
        if(abs(a[i]-b[i])!=0) return 0;//a!=b
    }
    return 1;//a==b
}
  
#endif