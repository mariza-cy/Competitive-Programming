# SQRT tricks

## Mo's algorithm

### Applications
Mo's algorithm can be used in problems with offline range queries, where we can efficiently calculate the answer after adding or removing an element from the current range. It can calculate the answers to $q$ on an array of size $n$ in $O(q\sqrt{n} + n\sqrt{n})$

### The algorithm

#### 1. Splitting into blocks
Read all the queries and split them in "blocks" of size $\sqrt n$ (or a fixed value close to $\sqrt{n}$) based on their left bound (say $l_i$). In other words, in each block $b_j$, there are all the ranges with $j\sqrt{n} \leq l_i < (j+1)\sqrt{n}$:

<p align="center"><img src="https://github.com/mariza-cy/Competitive-Programming/blob/main/Others/Images/Mo's%20Algorithm%20Queries%201.png" width="540"></p>

Each block will be represented by a vector `b[i]`, where each element is a pair of a pair, the left and right bound of the range, and an integer, the number of the current query. To find the block of range $(l,r)$, we'll use $j\sqrt{n} \leq l_i < (j+1)\sqrt{n}  \implies  j \leq \frac{l_i}{\sqrt{n}} < j+1  \implies  j = \left \lfloor{\frac{l_i}{\sqrt{n}}}\right \rfloor$

```cpp
ll x=500;  // x: a fixed value close to the square root of the maximum value of n
vector<pair<pair<ll,ll>,ll>> b[x];  // b[i]: the ranges included in block i

for(ll i=0; i<q; i++){
    ll l, r;
    cin>>l>>r;
    b[l/x].push_back({{l,r},i});  // Add the range to its block
}
```
