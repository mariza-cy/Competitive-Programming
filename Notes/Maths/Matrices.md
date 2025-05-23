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

### Exponentiation
The power $A^x$ of a matrix $A$ is defined if $A$ is a square matrix. Like with numbers, $A^x$ is $A$ multiplied with itself $x$ times:
```math
A^x = \underbrace{A \cdot A \cdot \dots \cdot A}_{\textit{x times}}
```
$A^0$ is an identity matrix, meaning each element is $1$ if the number of its row is equal to the number of its column and $0$ otherwise:
```math
A^0[i, j] = \begin{cases}
    1, & i = j\\
    0, & \text{otherwise}
\end{cases}
```
For example:
```math
\begin{bmatrix}
    1 & 6\\
    2 & 9
\end{bmatrix}^3
=
\begin{bmatrix}
    1 & 6\\
    2 & 9
\end{bmatrix}
\cdot
\begin{bmatrix}
    1 & 6\\
    2 & 9
\end{bmatrix}
\cdot
\begin{bmatrix}
    1 & 6\\
    2 & 9
\end{bmatrix}
=
\begin{bmatrix}
    133 & 618\\
    290 & 1335
\end{bmatrix}
```
```math
\begin{bmatrix}
    1 & 6\\
    2 & 9
\end{bmatrix}^0
=
\begin{bmatrix}
    1 & 0\\
    0 & 1
\end{bmatrix}
```

#### Calculating with code
We can efficiently calculate $A^x$ in $O(n^3 \log x)$, where $n$ is the size of $A$ using the same recursive algorithm we use in modular exponentiation:
```math
A^x = \begin{cases}
    \text{identity matrix} & x = 0\\
    (A \cdot A)^{\frac{x}{2}} & x \text{ is even}\\
    A \cdot (A \cdot A)^{\lfloor \frac{x}{2} \rfloor} & x \text{ is odd}\\
\end{cases}
```

We can use the multiplication value from before to implement it with code:
```cpp
vector<vector<ll>> identity(ll n){  // Returns an identity matrix of size n
    vector<vector<ll>> ans;
    for(ll i=0; i<n; i++){
        ans.push_back(vector<ll>());  // Insert a new row (an empty vector) to the result
        for(ll j=0; j<n; j++){
            // Insert a new element
            if(i==j) ans[i].push_back(1);
            else ans[i].push_back(0);
        }
    }
    return ans;
}

vector<vector<ll>> mpow(vector<vector<ll>> a, ll x){
    if(x==0) return identity(a.size());  // Identity matrix
    else if(x%2==0) return mpow(multiply(a,a), x/2);  // (a*a)^(x/2)
    else return multiply(a, mpow(multiply(a,a), x/2));  // a*((a*a)^(x/2))
}
```

**Complexity proof**: Since `x` is divided by 2 in each call, there are about $\log x$ calls in total. Sometimes the function will also call `identity` with complexity $O(n^2)$ or `multiply()` with complexity $O(n^3)$. Total: $O(n^3 \log x)$.

## Linear recurrences
**Definition**: A function $f(n)$ with initial values $f(0), f(1), \dots, f(k-1)$, where the next values are calculated using the formula:
```math
f(n) = c_1f(n-1) + c_2f(n-2) + \dots + c_kf(n-k)
```
where $c_1, c_2, \dots, c_k$ are constant coefficients.

Although DP can be used to calculate $f(n)$ in $O(nk)$, we can use matrix exponentiation to calculate it in $O(k^3 \log n)$.

### Creating a starting vector
We'll start with a vector $F_0$ of size $k \times 1$ where $F_0[i, 1] = f(i)$. Since $f(i)$ is fixed for every $i$ up to $k-1$, we already know all the values of this matrix.

### Creating a "transformation matrix"
Let's try to find a vector $X$ such that: 
```math
X \cdot F_0 = X \cdot
\begin{bmatrix}
    f(1)\\
    f(2)\\
    \vdots\\
    f(k)
\end{bmatrix}
=
\begin{bmatrix}
    f(2)\\
    f(3)\\
    \vdots\\
    f(k+1)
\end{bmatrix}
= F_1
```

#### First $k-1$ rows
Because of the matrix multiplication formula:
```math
F_1[i, 1] = X[i, 1] \cdot F_0[1, 1] + X[i, 2] \cdot F_0[2, 1] + \dots + X[i, k] \cdot F_0[k, 1] = X[i, 1] \cdot f(1) + X[i, 2] \cdot f(2) + \dots + X[i, k] \cdot f(k)
```

For the first $k-1$ rows, $F_1[i, 1] = f(i+1)$, so:
```math
F_1[i, 1] = X[i, 1] \cdot f(1) + X[i, 2] \cdot f(2) + \dots + X[i, k] \cdot f(k) = f(i+1)
```

Because of this, $X[i, i+1]$ must be equal to $1$ and all other $X[i, j]$ must be equal to $0$:
```math
F_1[i, 1] = 0 f(1) + 0 f(2) + \dots + 1 f(i+1) + \dots + 0 f(k) = 0 + 0 + \dots + f(i+1) + \dots + 0 = f(i+1)
```

#### Last row
The formula of the recurrence is:
```math
f(k+1) = c_k f((k+1)-k) + c_{k-1} f((k+1)-(k-1)) + \dots + c_1 f((k+1)-1) = c_k f(1) + c_{k-1} f(2) + \dots + c_1 f(k)
```

Additionally,
```math
F_1[k, 1] = X[k, 1] \cdot f(1) + X[k, 2] \cdot f(2) + \dots + X[k, k] \cdot f(k)
```

Therefore, if $X[k, i] = c_{k-i+1}$:
```math
F_1[k, 1] = X[k, 1] \cdot f(1) + X[k, 2] \cdot f(2) + \dots + X[k, k] \cdot f(k) = c_k f(1) + c_{k-1} f(2) + \dots + c_1 f(k) = f(k+1)
```

So the matrix $X$ will be:
```math
X =
\begin{bmatrix}
    0 & 1 & 0 & 0 & \dots & 0\\
    0 & 0 & 1 & 0 & \dots & 0\\
    0 & 0 & 0 & 1 & \dots & 0\\
    \vdots & \vdots & \vdots & \vdots & \ddots & \vdots\\
    0 & 0 & 0 & 0 & \dots & 1\\\
    c_k & c_{k-1} & c_{k-2} & c_{k-3} & \dots & c_1
\end{bmatrix}
```

### Finding bigger values
If we assume that the new starting vector if $F_1$, $X \cdot F_1 = F_2$, where:
```math
F_2 =
\begin{bmatrix}
    f(3)\\
    f(4)\\
    \vdots\\
    f(k+2)
\end{bmatrix}
```

By multiplying $n$ times, we get $F_n$:
```math
F_n =
\begin{bmatrix}
    f(n+1)\\
    f(n+2)\\
    \vdots\\
    f(n+k-1)
\end{bmatrix}
```

So we can find $f(n)$ by calculating
```math
F_{n-1} =
\begin{bmatrix}
    f(n)\\
    f(n+1)\\
    \vdots\\
    f(n+k-1)
\end{bmatrix}
= X^{n-1} =
\begin{bmatrix}
    f(1)\\
    f(2)\\
    \vdots\\
    f(k)
\end{bmatrix}
```

The complexity is $O(k^3 \log n)$ because of the matrix exponentiation.
