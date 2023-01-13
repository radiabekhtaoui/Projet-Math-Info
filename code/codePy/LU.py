#fonction pour faire la decomposition LU

def LU_decomposition(A:list[list[float]],n : int, h : int):
    L = [[0 for i in range(n)]for j in range(n)]
    U = [[0 for i in range(n)]for j in range(n)]
    for j in range(n):
        L[j][j] = 1
        for i in range(j+1):
            s1 = sum(U[k][j] * L[i][k] for k in range(i))
            U[i][j] = A[i][j] - s1
        for i in range(j, n):
            s2 = sum(U[k][j] * L[i][k] for k in range(j))
            L[i][j] = (A[i][j] - s2) / U[j][j]

    return L, U

n = 8
h = 1

A = [[0 for i in range(n)] for j in range(n)]
for i in range(1,n):
        A[i-1][i] = 1// h**2
        A[i-1][i-1] = -2// h**2
        A[i][i-1] = 1//h**2
        A[n-1][n-1] = -2//h**2

L,U = LU_decomposition(A,n,h)
print("La matrice L")
print(L)
print("La matrice U")
print(U)