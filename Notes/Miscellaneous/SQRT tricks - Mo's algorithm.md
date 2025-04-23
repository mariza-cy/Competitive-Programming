# SQRT tricks

## Mo's algorithm

### Applications
Mo's algorithm can be used in problems with offline range queries, where we can efficiently calculate the answer after adding or removing an element from the current range. It can calculate the answers to $q$ on an array of size $n$ in $O(q\sqrt{n} + n\sqrt{n})$

### The algorithm
The idea is to proccess the queries in a specific order so that we can efficiently transform each range to the next one. To do that, firstly read all the queries and split them in "blocks" of size $\sqrt n$ (or a fixed value close to $\sqrt{n}$) based on their left bound (say $l_i$). In other words, in each block $b_j$, there are all the ranges with $j\sqrt{n} \leq l_i < (j+1)\sqrt{n}$:

<p align="center"><img src="https://github.com/mariza-cy/Competitive-Programming/blob/main/Others/Images/Mo's%20Algorithm%20Queries%201.png" width="540"></p>
