#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n, m;
    cin>>n>>m;
    vector<ll> g[n];
    for(ll i=0; i<m; i++){
        ll u, v;
        cin>>u>>v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bool vis[n]={};
    queue<ll> q; q.push(0);
    while(!q.empty()){
        ll curr=q.front(); q.pop();

        if(vis[curr]) continue;
        vis[curr]=1;

        for(auto nxt:g[curr]){
            q.push(nxt);
        }
    }

    return 0;
}
