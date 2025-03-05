#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> graph;
const ll N=1e6;

// _______________Actual algorithm begins here_______________

graph g[N], rg[N], dag[N];

vector<ll> s;
bool vis1[N]={};

void dfs1(ll curr){
    if(vis1[curr]) return;
    vis1[curr]=true;

    for(auto nxt:g[curr]){
        dfs1(nxt);
    }

    s.push_back(curr);
}

ll scc[N];
bool vis2[N]={};

void dfs2(ll curr, ll x){
    if(vis2[curr]) return;
    vis2[curr]=true;

    scc[curr]=x;

    for(auto nxt:rg[curr]){
        dfs2(nxt,x);
    }
}

// _____________________main() function______________________

int main(){
    ll n, m;
    cin>>n>>m;
    for(ll i=0; i<m; i++){
        ll u, v;
        cin>>u>>v; u--; v--;
        g[u].push_back(v);
        rg[v].push_back(u);
    }

    dfs1(0);

    ll x=0;
    for(ll i=n-1; i>=0; i--){
        ll curr=s[i];

        if(vis2[curr]) continue;

        dfs2(curr,x);

        x++;
    }

    for(ll u=0; u<n; u++){
        for(auto v:g[u]){
            if(scc[u]!=scc[v]){
                dag[scc[u]].push_back(scc[v]);
            }
        }
    }
}
