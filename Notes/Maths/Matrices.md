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
```

### Multiplication of two matrices
The product $AB$ of matrices $A$ and $B$ is defined if the width of $A$ equals the height of $B$. The element in the $i$-th row and $j$-th column of $AB$ is equal to the sum of the products of each element in the $i$-th row of $A$ and the corresponding element of the $j$-th column of $B$:
```math
AB[i, j] = A[i, 1] \cdot B[1, j] + A[i, 2] \cdot B[2, j] + \dots + A[i, n] \cdot B[n, j] = \sum_{k=1}^{n} A[i, k] \cdot B[k, j]
```
<p align="center"><img src="https://github.com/mariza-cy/Competitive-Programming/blob/main/Others/Images/Matrix%20Multiplication.png" width="200"></p>

For example:
```math
\begin{bmatrix}
12 & 7\\
4 & 20\\
3 & 2
\end{bmatrix}
\cdot
\begin{bmatrix}
1 & 6\\
2 & 9
\end{bmatrix}
=
\begin{bmatrix}
12\cdot1+7\cdot2 & 12\cdot6+7\cdot9\\
4\cdot1+20\cdot2 & 4\cdot6+20\cdot9\\
3\cdot1+2\cdot2 & 3\cdot6+2\cdot9
\end{bmatrix}
=
\begin{bmatrix}
26 & 135\\
44 & 204\\
7 & 36
\end{bmatrix}
```

$A(BC) = (AB)C$ holds, but $AB$ isn't always equal to $BA$.

#### Calculating with code
To multiply two matrices in a program, we can just use a straightforward $O(n^3)$ algorithm:
```cpp
vector<vector<ll>> multiply(vector<vector<ll>> a, vector<vector<ll>> b){  // a: matrix A, b: matrix B
    // x: the height of A (and the result), n: the width of A and height of B, y: the width of B (and the result)
    ll x=a.size(), n=b.size(), y=b[0].size();

    vector<vector<ll>> ans;  // ans: the product AB
    for(ll i=0; i<x; i++){
        ans.push_back(vector<ll>());  // Insert a new row (an empty vector) to the result

        for(ll j=0; j<y; j++){
            ans[i].push_back(0);  // Insert a new element, initially set to 0

            // For each element of the result:
            for(ll k=0; k<n; k++){
                ans[i][j]+=a[i][k]*b[k][j];  // AB[i, j] = sum(A[i, k] * B[k, j])
            }
        }
    }
    return ans;
}
```
