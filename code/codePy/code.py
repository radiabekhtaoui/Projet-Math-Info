import LU_t
import Resolution
import Multiplication
import test
import  math
from math import *

n = 8       #nombre de points de dicretisation
h = 1/n+1    #le pas d'espace uniforme

#fonction à resoudre s(x) = 4πsin(2πx)
def s(x : float) -> float :
    return 4 * pi * pi * sin(2*π*x)

#fonction maillage
def maillage(x : list[float] , n : int) :
    for i in range(n+2):
         x[i] = i * h


#fonction qui retourne le vecteur b
def createB(B : list[float], x : list[float], ALPHA : float , BETA : float) :
        B [0] = (s(x[0]) + (ALPHA /h**2))
        B[N-1] = (s(x[n-1]) + (BETA /h**2 ))
        for i in range(1,n-1):
                B[i] = s(x[i])

A = [[0 for i in range(n)] for j in range(n)]
for i in range(1,n):
        A[i-1][i] = 1 / h**2
        A[i-1][i-1] = -2 / h**2
        A[i][i-1] = 1 / h**2
        A[n-1][n-1] = -2 / h**2

L , U = LU_t.Decomposition(A, n , h)
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



    

        


