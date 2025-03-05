# Strongly Connected Components

## Definitions
- **Strongly Connected Graph**: A directed graph where you can reach any node from any other node
- **Strongly Connected Component (SCC)**: A maximal strongly connected subgraph of a directed graph
- **Component Graph**: A DAG graph where each node corresponds to a SCC in a directed graph

## Kosaraju's algorithm
An $O(n+e)$ algorithm to find the SCCs of a graph.

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
