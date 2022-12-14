def produitmat_mat(A : list[list[float]], B : list[list[float]],n : int)-> list[list[int]] :
    C = [[0 for k in range(n)]for k in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                C[i][j] += A[i][k]*B[k][j]
    return C

def produitmat_vect(A : list[list[float]], u : list[float],n : int) -> list[float]:
        b = [0 for i in range(n)]
        for i in range(n):
            for j in range(n):
                b[i] += A[i][j]*u [j] 
        return b     