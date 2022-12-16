def Decomposition(A : list[list[float]], n : int, h : int ) :
    L = [[0 for i in range(n)] for j in range(n)]
    U = [[0 for i in range(n)] for j in range(n)]
    
    U[0][0] = A[0][0]
    for i in range(1,n):
        L[i][i-1]= A[i][i-1] / U[i-1] [i-1]
        U[i][i] = A[i][i] - L[i][i-1] * A[i-1][i]
    
    for i in range(n):
        L[i][i] = 1
    
    for i in range(1,n):
        U[i-1][i] = A[i-1][i]
    
    return L,U

def afficher_Mat(a):
    for i in a:
        print(i) 
