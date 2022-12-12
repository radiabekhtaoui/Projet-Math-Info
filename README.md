# Documentation 

## Factorisation LU d'une matrice tri-diagonale

Soit la matrice A sous la forme tri-diagonale suivante:

$$
\left(\begin{array}{cc} 
b_{1} & c_{1} & 0 & \cdots &0\\ 
a_{2} & b_{2} & c_{2}& \ddots & \vdots \\ 
\vdots  & \ddots  & \ddots  & \ddots & \vdots   \\
0 & 0 & a_{n-1} & b_{n-1}& c_{n-1} \\ 
0 & 0 & 0 & a_{n} & b_{n}\\ 
\end{array}\right)
$$ 

On peut écrire cette matrice comme produit des deux matrices suivante :

$$
\left(\begin{array}{cc} 
1 & 0 & \cdots & \cdots &0\\ 
l_{2} & 1 & \ddots & \ddots & \vdots \\ 
\vdots  & \ddots  & \ddots  & \ddots & \vdots   \\
\vdots & \ddots & l_{n-1} & 1& 0 \\ 
0 & \cdots & 0 & l_{n} & 1\\ 
\end{array}\right)
\left(\begin{array}{cc} 
v_{1} & c_{1} & 0 & \cdots &0\\ 
0 & v_{2} & c_{2}& \ddots & \vdots \\ 
\vdots  & \ddots  & \ddots  & \ddots & \vdots   \\
\vdots & \ddots & \ddots & v_{n-1}& c_{n-1} \\ 
0 & \cdots & \cdots & 0 & v_{n}\\ 
\end{array}\right)
$$ 
##### On va par la suite suivre la methode de la correspondance terme à terme pour faire la decomposition LU :
