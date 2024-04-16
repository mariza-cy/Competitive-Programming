# Dynamic Programming
Dynamic programming, or DP, is a commonly used competitive programming technique that can be used to solve a wide variety of problems. It’s based on a simple idea: using subproblems to solve a bigger one.

## Understanding DP: the Fibonacci sequence
In the Fibonacci sequence, the first numbers are 0 and 1 and every other number is the sum of the 2 numbers before it. The first 10 numbers of the Fibonacci sequence are $0, 1, 1, 2, 3, 5, 8, 13, 21$ and $34$. That can translate into $solve$<sub>$i$</sub> $= solve$<sub>$i-1$</sub> $+ solve$<sub>$i-2$</sub>, where $i$ is the index of the element we want to calculate.

This is the idea of DP: To calculate the answer (here, the element) for a certain value (here, the index of the element), we use the answers for smaller values (here, $i-1$ and $i-2$).

To code this, we can use a recursive function that takes $i$ as an argument and return the $i$<sup>$th$</sup> element:
```cpp
#include <bits/stdc++.h>
using namespace std;

int solve(int i){
    return solve(i-1)+solve(i-2);
}

int main(){
    int x;
    cin>>x;
    cout<<solve(x)<<endl;
}
```

However, this code will run forever, always calling `solve()` with a smaller value. That's why we need to have some *base cases*. Base cases are some subproblems we already know the answer to. In this case, our base cases are $solve$<sub>$0$</sub> $=0$ and $solve$<sub>$1$</sub> $= 1$, as we already know that the first two digits are $0$ and $1$.

The new code will be like this:
```cpp
#include <bits/stdc++.h>
using namespace std;

int solve(int i){
    if(i==0) return 0;
    else if(i==1) return 1;
    else return solve(i-1)+solve(i-2);
}

int main(){
    int x;
    cin>>x;
    cout<<solve(x)<<endl;
}
```

### Memoization
By testing the code, we can see that it works, but it takes a really long time to run for large values of $i$. This is not strange, as `solve()` calls itself 2 times every time it's called, meaning that the calls will double each time, resulting in $O(2$<sup>$i$</sup>$)$ complexity. We need to find a way to optimise our code.

If we add `cout<<i<<endl;` in the first line of `solve` we can see which values are called and how many times. Here is the output for $i=10$:
```
10 9 8 7 6 5 4 3 2 1 0 1 2 1 0 3 2 1 0 1 4 3 2 1 0 1 2 1 0 5 4 3 2 1 0 1 2 1 0 3 2 1 0 1 6 5 4 3 2 1 0 1 2 1 0 3 2 1 0 1 4 3 2 1 0 1 2 1 0 7 6 5 4 3 2 1 0 1 2 1 0 3 2 1 0 1 4 3 2 1 0 1 2 1 0 5 4 3 2 1 0 1 2 1 0 3 2 1 0 1 8 7 6 5 4 3 2 1 0 1 2 1 0 3 2 1 0 1 4 3 2 1 0 1 2 1 0 5 4 3 2 1 0 1 2 1 0 3 2 1 0 1 6 5 4 3 2 1 0 1 2 1 0 3 2 1 0 1 4 3 2 1 0 1 2 1 0
```

As we can see, solve is called many times for the same value. This happens because, in this case, `solve(10)` calls `solve(9)`, which calls `solve(8)`. However, `solve(8)` will also be called by `solve(10)`. As the answer for value $8$ will always be the same, we don't actually need to calculate it again. So how can we avoid unnecessary calls?

This is where *memoization* comes in. Memoization is basically storing the answer for each value after we calculate it, and then using the stored value every time we call `solve()` for that value. To do that, we will use an array `ans`. Beafore calling `solve`, we will set every value of `ans` to -1, and use that as a flag (a sign that we haven't calculated the answer for that value yet). Every time we call `solve`, we will first check if we have already found the answerfor that value, and, if we have, we will return that value instead.

> [!TIP]
> The value we use as a flag could be any value that can't be the actual answer. This means that if the answer can be a negative number, -1 won't work, so a really large or small number, like $1e18$ can be used instead. Alternatively, we can have a second array of booleans, where `true` means we have calculated the answer and `false` means we haven't.

Here is the new code:
```cpp
#include <bits/stdc++.h>
using namespace std;

int ans[1e6];

int solve(int i){
    if(ans[i]!=-1) return ans[i];
    else if(i==0) return 0;
    else if(i==1) return 1;
    else{
        ans[i]=solve(i-1)+solve(i-2);
        return ans[i];
    }
}

int main(){
    for(int i=0; i<1e6; i++){
        ans[i]=-1;
    }

    int x;
    cin>>x;
    cout<<solve(x)<<endl;
}
```

This time, each value needs to be calculated at most once, so the new complexity is $O(i)$.

## Solving a DP problem

### Optimal solutions: The coin problem
Now let's try to solve [Minimizing Coins (CSES)](https://cses.fi/problemset/task/1634). To do that, we will try to approach the problem, step by step.

#### 1. What does `solve()` return?
