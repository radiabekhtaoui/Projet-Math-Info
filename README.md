# Documentation 

### Factorisation LU d'une matrice tri-diagonale (la methode utilisée pour implémenter le module LU)

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

$$b_{1}=v_{1} \Rightarrow v_{1} = b_{1} $$

$$a_{k}= l_{k} v_{k−1} \Rightarrow l_{k} = a_{k}/v_{k−1}$$

$$b_{k} = l_{k} c_{k−1} + v_{k} \Rightarrow v_{k} = b_{k} − l_{k} c_{k−1}, \hspace{10pt} k = 2,\cdots, n $$

Le module LU est implémenté suivant cet algorithme.

### Resolution du system Ax = b (la methode utilisée pour implémenter le module resoudre):
##### On commence par resoudre Ly = b:
Methode de descente:
$$y_{1} = b_{1}$$

$$l_{k} y_{k−1} + y_{k} = b_{k} \Rightarrow  y_{k} = b_{k} − l_{k} y_{k−1}, \hspace{10pt} k = 2, \cdots, n$$

##### Par la suite on fait la resolution de Ux = y:
Methode de remontée:
$$v_{n}x_{n} = yn \Rightarrow x_{n} = y_{n} / v_{n} $$

$$v_{k}x_{k} + c_{k}x_{k+1} = y_{k} \Rightarrow x_{k} = (y_{k} − c_{k}x_{k+1})/v_{k}, \hspace{10pt} k = n − 1,\cdots , 1$$
