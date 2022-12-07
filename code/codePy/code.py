n=8

def Decomposition_LU(A : list[list[int]], L : list[list[int]], U : list[list[int]], n : int ) :
   
    U[0][0] = A[0][0]
    for i in range(1,n):
        L[i][i-1]= A[i][i-1] / U[i-1] [i-1]
        U[i][i] = A[i][i] - L[i][i-1] * A[i-1][i]
    
    for i in range(n):
        L[i][i] = 1
    
    for i in range(1,n):
        U[i-1][i] = A[i-1][i]

def afficher_Mat(a):
    for i in a:
        print(i) 

L = [[0 for i in range(n)] for j in range(n)]
U = [[0 for i in range(n)] for j in range(n)]
A = [[0 for i in range(n)] for j in range(n)]
for i in range(n):
        A[i-1][i] = -1
        A[i][i] = 2
        A[i][i-1] = -1

Decomposition_LU(A, L, U, n)
print("Matrice A:")
afficher_Mat(A)
print("Matrice L:")
afficher_Mat(L)
print("Matrice U:")
afficher_Mat(U)


