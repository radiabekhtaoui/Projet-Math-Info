n = 8
import LU_t
import Resolution
import Multiplication
import test
import  math

A = [[0 for i in range(n)] for j in range(n)]
for i in range(1,n):
        A[i-1][i] = -1
        A[i-1][i-1] = 2
        A[i][i-1] = -1
        A[n-1][n-1] = 2

L , U = LU_t.Decomposition(A, n)
print("Matrice A:")
LU_t.afficher_Mat(A)
print("Matrice L:")
LU_t.afficher_Mat(L)
print("Matrice U:")
LU_t.afficher_Mat(U)

b = [1 for i in range(n)]
y = Resolution.Sol_y(L,b,n)
u = Resolution.Sol_u(U,y,n)
print("La solution du système est u:")
print(u)

B = Multiplication.produitmat_mat(L,U,8)
assert test.Test_matrice(A,B,8) == True

ax = Multiplication.produitmat_vect(A,u,8)
assert test.Test_vect(ax,b,8) == True



    

        


