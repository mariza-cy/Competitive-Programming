# Dynamic Programming
Dynamic programming, or DP, is a commonly used competitive programming technique that can be used to solve a wide variety of problems. It’s based on a simple idea: using subproblems, which are called states, to solve a bigger problem.

> [!TIP]
> There are two types of problems where DP can be used: Finding the optimal solution for something (i.e. minimising or maximising the answer) and counting the ways of doing something.

## Understanding DP: the Fibonacci sequence
In the Fibonacci sequence, the first numbers are 0 and 1 and every other number is the sum of the 2 numbers before it. The first 10 numbers of the Fibonacci sequence are $0, 1, 1, 2, 3, 5, 8, 13, 21$ and $34$. That can translate llo $solve(i) = solve(i-1) + solve(i-2), where $i$ is the index of the element we want to calculate.

This is the idea of DP: To calculate the answer (here, the element) for a certain value (here, the index of the element), we use the answers of one or more similar problems with smaller values (here, $i-1$ and $i-2$).

> [!IMPORTANT]
> **States and transitions**
> 
> The subproblems are called *states*, while the recursive calls are called *transitions*.

To code this, we can use a recursive function that takes $i$ as an argument and return the $i$<sup>$th$</sup> element:
```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(ll i){
    return solve(i-1)+solve(i-2);
}

int main(){
    ll x;
    cin>>x;
    cout<<solve(x)<<endl;
}
```

### Base cases
However, this code will run forever, always calling `solve()` with a smaller value. That's why we need to have some *base cases*. Base cases are some subproblems we already know the answer to. In this case, our base cases are $solve(0) = 0$ and $solve(1) = 1$, as we already know that the first two digits are $0$ and $1$.

> [!NOTE]
> In this problem, the base case is a case that does't follow the same rules as the rest of the cases. However, sometimes the base case is't as obvious. Generally, when working with decreasing numbers the base case is 0 (like [below](https://github.com/mariza-cy/Competitive-Programming/blob/main/Guides/Dynamic%20Programming/README.md#2-seperating-cases)), and when working on an array it's either end (with index $0$, $n-1$ or $n$).

The new code will be like this:
```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(ll i){
    if(i==0) return 0;  // Base case #1: The first number is 0
    else if(i==1) return 1;  // Base case #2: The second number is 1
    else return ans[i]=solve(i-1)+solve(i-2);  // If i >= 2, the answer is the sum of solve(i-1) and solve(i-2)
}

int main(){
    ll x;
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

> [!NOTE]
> The value we use as a flag could be any value that can't be the actual answer. This means that if the answer can be a negative number, -1 won't work, so a really large or small number, like $1e18$ can be used instead. Alternatively, we can have a second array of booleans, where `true` means we have calculated the answer and `false` means we haven't.

Here is the new code:
```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ans[1e6];

ll solve(ll i){
    if(ans[i]!=-1) return ans[i];  // If the solution is already saved in ans, return it
    else if(i==0) return 0;  // Base case #1: The first number is 0
    else if(i==1) return 1;  // Base case #2: The second number is 1
    else return ans[i]=solve(i-1)+solve(i-2);  // If i >= 2, the answer is the sum of solve(i-1) and solve(i-2)
}

int main(){
    for(ll i=0; i<1e6; i++){
        ans[i]=-1;  // Before calling the function, make sure to initialize ans
    }

    ll x;
    cin>>x;
    cout<<solve(x)<<endl;
}
```

This time, each value needs to be calculated at most once, so the new complexity is $O(i)$.

## Solving a DP problem - Optimal solutions: The coin problem
Now let's try to solve [Minimizing Coins (CSES)](https://cses.fi/problemset/task/1634). To do that, we will try to approach the problem, step by step.

### 1. Defining the states
**Finding subproblems**: To solve a problem with DP, we must first decide what our subproblems will be. To do that, we have to divide the problem llo "steps". These will basically be the choices we have. In this case, each time we have to choose the next coin we are going to use, so each "step" will be the choise of a coin.

**Finding the parameters**: To do that, we have to find what changes after each step. Here, what changes after we select a coin is the value that we need to collect from now on (For example, if $r=10$ and we have used a coin of value $2$, this value will be $8$). Let's call this value $r$. This is the only info we will need in order to solve the problem.

### 2. Seperating cases
**Working with recursion**: Generally, to find the best option, `solve()` has to choose the minimum/maximum option, depending on the problem. So the next question is: What do we need to know in order to calculate the value of each option? For each option we need to call `solve()`, changing the parameters in the way they will change after the current step. For example, here, if we choose a coin with value $c$<sub>$i$</sub>, then $r$ will reduce by $a$<sub>$i$</sub>, so we must call `solve(r-a[i])`. Next, we must find how this value will be affected during each step. Here, in each step we add one more coin, so the value will be increased by $1$. With these in mind, we can see that to calculate the answer for $r$, we must find the minimum value of `solve(r-a[i])+1` among all $i$, $0 \leq i < n$.

**The base case**: Now, we need to add a base case. The base case must be the simplest subproblem our code will reach. In this case, that's $r=0$, with it's answer being $0$, as we won't need any more coins.

**Other cases**: There's still a problem: sometimes, the subproblem will be unsolvable. For example, if $c={3,4}$ and `solve(2)` is called, it will call `solve(-1)` (since $r-a$<sub>$0$</sub> $=2-3=-1$) and `solve(-2)` (since $r-a$<sub>$1$</sub> $=2-4=-2$), but, obviously, $-1$ and $-2$ are not reachable sums. What's more, the code will run forever, since it will keep reducing $r$ without ever reaching the base case. So when $r<0$ the code must return a value that won't affect the final result. In optimal solution problems, this means it must return a value that will never be the minimum/maximum value, so it will never be chosen, while when counting ways the value must be $0$ so it doesn't affect the sum. Here, since we need the minimum value we can return $10$<sup>$9$</sup>, or any other number larger than $10$<sup>$6$</sup>, so that, no matter what, the other values will be smaller (The worst case is using the minimum value of coins, which is $1$ for the maximum sum, which is $10$<sup>$6$</sup>, meaning $10$<sup>$6$</sup> coins will be used).

> [!TIP]
> It's a good practise to define a constant `INF=1e9` (or `1e18`) so you can use a large value easily while coding. Using it will also make the code more readable, and it's really useful when writing longer code.

### One last fix
The code seems to work perfectly... most of the time. There is one problem. Sometimes, it's impossible to select coins so that their sum is $x$. In that case, the code will return a number greater or equal to the number the function returns when $r<0$. To make sure we never print a large number, we can check if the answer is too large and print `-1` if it is.

### The code
```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF=1e18;
 
ll n, c[1e6];
ll ans[1e6];

ll solve(ll r){
    if(r<0) return INF;  // Special case: If r is too small, return INF
    else if(ans[r]!=-1) return ans[r];  // If the solution is already saved in ans, return it
    else if(r==0) return ans[r]=0;  // Base case: We don't need any coins for a sum of 0
    else{
        ans[r]=INF;  // Initialize ans[r] to INF to find the minimum value
        for(ll i=0; i<n; i++){  // For each coin
            ans[r]=min(ans, solve(r-c[i])+1);  // If we choose this coin next, we'll need this coin, plus the minimum number of coins we need for the rest of the sum
        }
        return ans[r];
    }
}
 
int main(){
    fastio;
 
    ll x;
    cin>>n>>x;
    for(ll i=0; i<n; i++){
        cin>>c[i];
    }
    
    for(ll i=0; i<=x; i++){
        ans[i]=-1;  // Initialize ans
    }
    
    ll y=solve(x);
    if(y>=INF) cout<<-1<<endl;  // If y is too large, it means we can't produce the sum x
    else cout<<y<<endl;
    
    return 0;
}
```
