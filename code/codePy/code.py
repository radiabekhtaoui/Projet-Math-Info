n=8

def Decomposition_LU(A : list[list[float]], L : list[list[float]], U : list[list[float]], n : int ) :
   
    U[0][0] = A[0][0]
    for i in range(1,n):
        L[i][i-1]= A[i][i-1] / U[i-1] [i-1]
        U[i][i] = A[i][i] - L[i][i-1] * A[i-1][i]
    
    for i in range(n):
        L[i][i] = 1
    
    for i in range(1,n):
        U[i-1][i] = A[i-1][i]


def Sol_y(L : list[list[float]] , b : list[float], n:int) -> list[float] :
    
    y = [0 for i in range (n)]
    y[0] = b[0]/L[0][0]
    
    for i in range (1,n):
        y[i] = (b[i] - L[i][i-1] * y[i-1])/L[i][i]
    return y


def Sol_u(U : list[list[float]] , y : list[float] , n : int) -> list[float]:
    
    u = [0 for i in range(n)]
    u[n-1] = y[n-1] / U[n-1][n-1] 
    
    for i in range(n-2,-1,-1):
        u[i] = (y[i] - U[i][i+1] * u[i+1]) / U[i][i]
    return u

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

b = [1 for i in range(n)]
y = Sol_y(L,b,n)
u = Sol_u(U,y,n)
print("La solution du système est u:")
print(u)
