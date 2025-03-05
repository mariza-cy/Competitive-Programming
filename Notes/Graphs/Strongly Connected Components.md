# Strongly Connected Components

## Definitions
- **Strongly Connected Graph**: A directed graph where you can reach any node from any other node
- **Strongly Connected Component (SCC)**: A maximal strongly connected subgraph of a directed graph
- **Component Graph**: A DAG graph where each node corresponds to a SCC in a directed graph

## Uses of SCCs
- **Trivial** - Find the SCC each node belongs to
- **Component graph (DP)** - Component graphs are DAGs, so we can use DP on them
- **2-SAT** - With SCCs we can solve the 2-SAT problem (see below)

## Kosaraju's algorithm
An $O(n+e)$ algorithm to find the SCCs of a graph.

[Full implementation](https://github.com/mariza-cy/Competitive-Programming/blob/main/Notes/Graphs/Implementation/Kosaraju's%20algorithm.cpp)\
[Raw implementation](https://github.com/mariza-cy/Competitive-Programming/blob/main/Notes/Graphs/Implementation/Raw%20(No%20comments)/Kosaraju's%20algorithm.cpp)

### 1. Topological sort
Simply run a normal DFS and add each node to a stack/vector at the end of the function (We must run `dfs1()` from every node:
```cpp
vector<ll> s;  // s: The (reversed) topological order of the graph
bool vis1[N]={};

void dfs1(ll curr){
    // Check if visited
    if(vis1[curr]) return;
    vis1[curr]=true;

    // Go to neighbors
    for(auto nxt:g[curr]){
        dfs1(nxt);
    }

    // Add to the vector
    s.push_back(curr);
}
```

### 2. DFS on reversed graph
Starting from the node at the end of `s`, if the node isn't visited, run a DFS on the *reversed* graph starting with that node. 

Since all the nodes that can be reached from it are either part of the current SCC, or a different one, in which case it will already be visited (because of the topological sort). All the nodes that can't be reached from a node on the reversed graph can't reach it on the original one, so they're parts of different SCCs.
```cpp
ll scc[N];  // scc[i]: The SCC of node i
bool vis2[N]={};

void dfs2(ll curr, ll x){  // x: The current SCC
    // Check if visited
    if(vis2[curr]) return;
    vis2[curr]=true;

    // Set current node's SCC to current one
    scc[curr]=x;

    // Go to neighbors
    for(auto nxt:rg[curr]){
        dfs2(nxt,x);
    }
}
```
And inside the `main()` function:
```cpp
ll x=0;  // x: The number of SCCs so far
for(ll i=n-1; i>=0; i--){
    ll curr=s[i];

    // Check if visited
    if(vis2[curr]) continue;

    // Call the DFS function
    dfs2(curr,x);

    // Increase SCC counter
    x++;
}
```

### 3. Creating the component graph
We can just check all the edges of the original graph and add them to the component graph if the vertices they connect belong to different SCCs.

Inside the `main()` function:
```cpp
for(ll u=0; u<n; u++){
    // Change the value of the SCC based on the value of current node (if needed)
    
    for(auto v:g[u]){
        if(scc[u]!=scc[v]){
            dag[scc[u]].push_back(scc[v]);
        }
    }
}
```

## 2-SAT
- **SAT:** The problem of assigning Boolean values to some variables to satisfy a Boolean expression. The expressions are of the form $({a_1}_1 \lor {a_1}_2 \lor \dots \lor {a_1}\_{k_1}) \land ({a_2}_1 \lor {a_2}_2 \lor \dots \lor {a_2}\_{k_2}) \land \dots \land ({a_n}_1 \lor {a_n}_2 \lor \dots \lor {a_n}\_{k_1})$, where each ${a_i}_j$ is either $v$ or $\neg v$ where $v$ is a variable. The SAT problem is NP-complete
- **2-SAT:** A restriction of the SAT problem where each clause has only 2 literals: $({a_1}_1 \lor {a_1}_2) \land ({a_2}_1 \lor {a_2}_2) \land \dots \land ({a_n}_1 \lor {a_n}_2)$. It can be solved in $O(n + m)$ time (where $n$ is the number of variables and $m$ is the number of clauses)

To solve the problem we can create a graph based on the expressions and use it to find a solution, or detect that there isn't one.

### 1. Creating the graph
All the clauses in the expressions must be true, so at least one of the literals of each expression must be true. Therefore, if one of them is false, the other is defenitely true. So if one of the clauses is $(a \lor b)$, then $\neg a \implies b$ and $\neg b \implies a$. Based on these implications, we can create a directed graph where each node represents a value for some variable, so there are nodes $a$ and $\neg a$ for each variable $a$, and an edge from $u$ to $v$ means that $u \implies v$. 

### 2. Checking if the expression is satisfiable
If $a \implies \neg a$ (directly or indirectly), $a$ obviously can't be true, since that would imply it's false. If $a \iff \neg a$, $a$ can't be either $\text{true}$ or $\text{false}$ and there is no way to satisfy the expression. If $a \implies \neg a$, there is a path in the implication graph from $a$ to $\neg a$, and the opposite, so $a \iff \neg a$ if and only if $a$ and $\neg a$ belong in the same SCC.

So it's sufficient to use Kosaraju's algorithm to find the SCCs of the graph, and check that $a$ and $\neg a$ are in different SCCs.
