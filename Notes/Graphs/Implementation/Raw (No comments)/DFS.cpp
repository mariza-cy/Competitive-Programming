#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=2e5;

vector<ll> g[N];

bool vis[N]={};
void dfs(ll curr){
    if(vis[curr]) return;
    vis[curr]=1;

    for(auto nxt:g[curr]){
        dfs(nxt);
    }
}

int main(){
    ll n, m;
    cin>>n>>m;
    for(ll i=0; i<m; i++){
        ll u, v;
        cin>>u>>v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0);

    return 0;
}
