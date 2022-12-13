import math
def Test_matrice(a:list[list[float]],b: list[list[float]],n:int):
    for i in range(n):
        for j in range(n):
            if(math.floor(a[i][j] - b[i][j])==0):
                return True
            else:
                return False

def Test_vect(a : list[float],b : list[float],n:int):
    for i in range(n):
       if( math.floor(abs(a[i] - b[i]))== 0):
          return True
       else:
           return False