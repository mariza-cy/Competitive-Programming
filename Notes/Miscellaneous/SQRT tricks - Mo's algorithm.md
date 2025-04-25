# SQRT tricks

## Mo's algorithm

### Applications
Mo's algorithm can be used in problems with offline range queries, where we can efficiently calculate the answer after adding or removing an element from the current range. It can calculate the answers to $q$ on an array of size $n$ in $O(q\sqrt{n} + n\sqrt{n})$

### The algorithm

#### 1. Splitting into blocks
Read all the queries and split them in "blocks" of size $\sqrt n$ (or a fixed value close to $\sqrt{n}$) based on their left bound (say $l_i$). In other words, in each block $b_j$, there are all the ranges with $l_i \in [j\sqrt{n}, (j+1)\sqrt{n})$. For example, these might be the queries of block 1 might be:
<p align="center"><img src="https://github.com/mariza-cy/Competitive-Programming/blob/main/Others/Images/Mo's%20Algorithm%20Queries%201.png" width="540"></p>

Each block will be represented by a vector `b[i]`, where each element is a pair of a pair, the left and right bound of the range, and an integer, the number of the current query. To find the block of range $(l,r)$, we'll use $j\sqrt{n} \leq l_i < (j+1)\sqrt{n}  \implies  j \leq \frac{l_i}{\sqrt{n}} < j+1  \implies  j = \left \lfloor{\frac{l_i}{\sqrt{n}}}\right \rfloor$

```cpp
ll SQRT=500;  // SQRT: a fixed value close to the square root of the maximum value of n
vector<pair<pair<ll,ll>,ll>> b[SQRT];  // b[i]: the ranges included in block i

for(ll i=0; i<q; i++){
    ll l, r;
    cin>>l>>r;

    // Add the range to its block
    b[l/SQRT].push_back({{l,r},i});  
}
```

#### 2. Processing the queries
Now process each block, starting by sorting the queries of that block in non-decreasing order of the left bound. In the previous example:
<p align="center"><img src="https://github.com/mariza-cy/Competitive-Programming/blob/main/Others/Images/Mo's%20Algorithm%20Queries%202.png" width="540"></p>

Then initialize a left ($l$) and right ($r$) pointer to positions $j\sqrt{n}$ (the first position of the block) and $j\sqrt{n} - 1$ (the position before the beginning of the block), respectively. These will represent the current range. Also initialize a variable with the answer for the current range, and any other variables you might need to calculate this answer.

Now process the queries, one by one. If the current query is on range $[l_c,r_c]$ we need to move from range $[l,r]$ to range $[l_c,r_c]$ (note that $l \leq l_c$, since the queries are sorted), so we must:
- Add elements to the end of the current range until $r = r_c$
- (If $l_c < l$) Add elements to the beginning of the current range until $l = l_c$
- (If $l < l_c$) Remove elements from the beginning of the current range until $l = l_c$

After moving to the next range, save the answer in an array on the position tha corresponds to that query.

```cpp
ll ansq[q];  // ansq[i]: the answer to the i-th query
for(ll i=0; i<SQRT; i++){
    sort

###
