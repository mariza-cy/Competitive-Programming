#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> graph;
const ll N=1e6;

graph g[N], rg[N], dag[N];  // g: the original graph, rg: the reversed graph, dag: the component graph

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

int main(){
    // Input
    ll n, m;
    cin>>n>>m;
    for(ll i=0; i<m; i++){
        ll u, v;
        cin>>u>>v; u--; v--;
        g[u].push_back(v);
        rg[v].push_back(u);
    }

    dfs1(0);

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

    for(ll u=0; u<n; u++){
        // Change the value of the SCC based on the value of current node (if needed)
        
        for(auto v:g[u]){
            if(scc[u]!=scc[v]){
                dag[scc[u]].push_back(scc[v]);
            }
        }
    }
}
