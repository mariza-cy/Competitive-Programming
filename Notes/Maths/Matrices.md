# Matrices

## Definitions
- **Matrix**: A table of numbers, the mathematics equivalent to a 2D array in programming. For example, this is a matrix of size $2 \times 3$:
```math
A = \begin{bmatrix}
35 & 12 & 7\\
8 & 4 & 20
\end{bmatrix}
```
- **Vector**: A matrix with only one column, for example:
```math
A = \begin{bmatrix}
35\\
12\\
7\\
8
\end{bmatrix}
```
- **Square matrix**: A matrix with the same number of rows and columns, for example:
```math
A = \begin{bmatrix}
35 & 12\\
7 & 8
\end{bmatrix}
```

## Basic operations

### Sum
The sum $A + B$ of matrices $A$ and $B$ is defined if they have the same size. Each element of the result is equal to the sum of the corresponding elements in  $A$ and $B$. Formally:
```math
(A + B)[i, j] = A[i, j] + B[i, j]
```
For example:
```math
\begin{bmatrix}
35 & 12 & 7\\
8 & 4 & 20
\end{bmatrix}
+
\begin{bmatrix}
13 & 14 & 6\\
3 & 1 & 10
\end{bmatrix}
=
\begin{bmatrix}
35+13 & 12+14 & 7+6\\
8+3 & 4+1 & 20+10
\end{bmatrix}
=
\begin{bmatrix}
48 & 26 & 13\\
11 & 5 & 30
\end{bmatrix}
```

### Multiplication by a value
The product $A \cdot x$ of a matrix $A$ and a value $x$ is a matrix where each element is the corresponding element of $A$ multiplied by $x$. Formally:
```math
(x \cdot A)[i, j] = x \cdot A[i, j]
```
For example:
```math
2 \cdot
\begin{bmatrix}
35 & 12 & 7\\
8 & 4 & 20
\end{bmatrix}
=
\begin{bmatrix}
2\cdot35 & 2\cdot12 & 2\cdot7\\
2\cdot8 & 2\cdot4 & 2\cdot20
\end{bmatrix}
=
\begin{bmatrix}
70 & 24 & 14\\
16 & 8 & 40
\end{bmatrix}
