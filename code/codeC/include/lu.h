#ifndef LU_H
#define LU_H

void decompLU(double** A, double** L, double** U, int n) {
    for (int j = 0; j < n; j++) {
        L[j][j] = 1;
        for (int i = 0; i <= j; i++) {
            double s1 = 0;
            for (int k = 0; k < i; k++) {
                s1 += U[k][j] * L[i][k];
            }
            U[i][j] = A[i][j] - s1;
        }
        for (int i = j+1; i < n; i++) {
            double s2 = 0;
            for (int k = 0; k < j; k++) {
                s2 += U[k][j] * L[i][k];
            }
            L[i][j] = (A[i][j] - s2) / U[j][j];
        }
    }
}
#endif