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

