n=8
import LU
import Resolution
import Multiplication

L = [[0 for i in range(n)] for j in range(n)]
U = [[0 for i in range(n)] for j in range(n)]
A = [[0 for i in range(n)] for j in range(n)]
for i in range(1,n):
        A[i-1][i] = -1
        A[i-1][i-1] = 2
        A[i][i-1] = -1
        A[n-1][n-1] = 2

LU.Decomposition(A, L, U, n)
print("Matrice A:")
LU.afficher_Mat(A)
print("Matrice L:")
LU.afficher_Mat(L)
print("Matrice U:")
LU.afficher_Mat(U)

b = [1 for i in range(n)]
y = Resolution.Sol_y(L,b,n)
u = Resolution.Sol_u(U,y,n)
print("La solution du système est u:")
print(u)


assert A==Multiplication.produitmat_mat(L, U, 8)
ax = Multiplication.produitmat_vect(A,u,8)