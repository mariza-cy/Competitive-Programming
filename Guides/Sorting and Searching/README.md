# Sorting and Searching

## A. Sorting

In competitive programming, knowing how to sort an array is essential in many problems. Although sorting the output is rarely neccesary, you might need to sort an array in order for your solution to work - we'll see a few of its main uses later.

### The `sort()` function

> ### Problem: [Ταξινόμηση αριθμών](https://www.hackerrank.com/contests/bubbles-bubbles/challenges/1-10)
> Source: COI exercises on Hackerrank - Bubble sort

Fortunally, C++ has a ready, built-in function that's both efficient and flexible, so as long as you know how to use it you don't need to know how to implement any sorting algorithms.

Its syntax is pretty simple: `sort(first, last)`

And this is how you can use it to sort an array and a vector:
```cpp
sort(a,a+n);  // to sort array a[n]
sort(b.begin(),b.end());  // to sort vector b
```

The parameter `first` is an iterator (basically a variable that points to an element inside a data structure, e.g. an array) that points to the first element in our array or vector, and the parameter `last` is an iterator that points to the position **right after** its end.

An array `a[n]`'s first position is `a` and the position after its end is `a+n`. In a vector, we use the `.begin()` and `.end()` methods.

So here's the full code to sort an array:
```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin>>n;
    long double a[n];
    for(ll i=0; i<n; i++){
        cin>>a[i];
    }

    sort(a,a+n);

    for(ll i=0; i<n; i++){
        cout<<a[i];
    }
}
```

### More practice
Try to solve as many of these problems as possible:

- [ ] [Ταξινόμηση με άθροισμα ψηφίων](https://www.hackerrank.com/contests/bubbles-bubbles/challenges/10-3) | Source: COI exercises on Hackerrank - Bubble sort | :star:	- 1/10
- [ ] [Χριστουγεννιάτικος χορός](https://www.hackerrank.com/contests/bubbles-bubbles/challenges/challenge-307) | Source: COI exercises on Hackerrank - Bubble sort | :star: :star: - 2/10
- [ ] [Alice and Books](https://codeforces.com/problemset/problem/1978/A) | Source: Codeforces | :star: :star: - 2/10
- [ ] [Choosing Cubes](https://codeforces.com/contest/1980/problem/B) | Source: Codeforces | :star: :star: :star: - 3/10
