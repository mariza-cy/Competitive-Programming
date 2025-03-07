# Pre-Contest Review Notes

## Segment tree
```cpp
struct node{
    ll val;
    node *L, *R;

    void build(ll l, ll r){
        ...
    }

    void upd(ll x, ll pos, ll l, ll r){
        ...
    }

    ll query(ll tl, ll tr, ll l, ll r){
        ...
    }
};
```

`init()` function to initialize all nodes:
```cpp
void init(ll l=0, ll r=N){
    if(l==r){
        val=a[l];  // If leaf, assign initial value
    }

    else{
        // Create & initialize children
        L=new node;
        L->init(l,MID);

        R=new node;
        R->init(MID+1,r);

        val=L->val+R->val;  // Assign initial value (Change depending on operation)
    }
}
```

`upd()` function to update values:
```cpp
void upd(ll x, ll pos, ll l, ll r){
    if(l==pos && pos==r){
        val=x;  // If the position is correct, update value
    }

    else if(l<=pos && pos<=r){  // If the position is in the range, update children
        L->upd(x,pos,l,MID);
        R->upd(x,pos,MID+1,r);

        val=L->val+R->val;  // Update value (Change depending on operation)
    }
}
```

`query()` function to answer queries:
```cpp
ll query(ll tl, ll tr, ll l, ll r){
    if(tl<=l && r<=tr){
        return val;  // If the node's range is in the query's range, return value
    }

    else if(r<tl || l>tr){
        return 0;  // If it's all outside, return 0 (Change depending on operation)
    }

    else{
        return L->query(tl,tr,l,MID) + R->query(tl,tr,MID+1,r);
        // If a part is inside, return the sum of its children (Change depending on operation)
    }
}
```

### Range Update Changes
`push()` function to prepare nodes:
```cpp
void push(ll l=0, ll r=N){
    if(l!=r) {
        // Push lazy to children
        L->lazy+=lazy;  
        R->lazy+=lazy;
    }

    val+=RANGE*lazy;  // Update value (Change depending on operation)
    lazy=0;  // Reset lazy ( >> )
}
```

Changes to `init()` & `query()`:
```cpp
void init(ll l=0, ll r=N){
    lazy=0;  // Initialize lazy to 0 (Change depending on operation)

    ...
```

```cpp
ll query(ll tl, ll tr, ll l, ll r){
    push(l, r);  // Update values first

    ...
```

New `upd()`:
```cpp
void upd(ll x, ll tl, ll tr, ll l=0, ll r=N){
    push(l,r);  // Update values first

    if(tl<=l && r<=tr){
        lazy+=x;  // If the node's range is in the query's range, update its value
        push(l,r);
    }

    else if(tr<l || r<tl){
        return;  // If it's all outside, do nothing
    }

    else{  // If a part is inside, update children
        L->upd(x,tl,tr,l,MID);
        R->upd(x,tl,tr,MID+1,r);

        val=L->val+R->val;  // Update value (Change depending on operation)
    }
}
```

### Point query
```cpp
ll query(ll i, ll l=0, ll r=N){
    push(l,r);

    if(l==i && i==r){
        return val;
    }

    else if(i<l || r<i){
        return 0;
    }

    else{
        return L->query(i,l,MID)+R->query(i,MID+1,r);
    }
}
```

## DSU
```cpp
struct dsu{
    vector<ll> p, val;

    void init(ll n){
        for(ll i=0; i<n; i++){
            p.push_back(i);
            val.push_back(0);
        }
    }

    ll find(ll x){
        if(p[x]==x) return x;
        else{
            p[x]=find(p[x]);
            return p[x];
        }
    }

    void merge(ll x, ll y){
        x=find(x);
        y=find(y);

        if(x==y) return;

        val[x]+=val[y];
        p[y]=x;
    }
};
```

## MST
### Prim's algorithm
 - Start from a random node
 - For each node:
   - If it's already visited, ignore it
   - Otherwise add it to the MST
   - Add all edges from that node to a priority queue
   - Select the node with the smallest weight from the queue and continue
  
### Kruskal's algorithm
 - Sort all edges
 - Starting from the edge with the smallest weight:
   - If the node does't create a cycle, add it to the MST (To check for cycles, use a DSU structure)

## Euler tour
```cpp
ll tin[N], tout[N], cnt=0;
void dfs(ll curr) {
    tin[curr]=cnt;
    cnt++;
    for(auto nxt:t[curr]) {
        dfs(nxt);
    }
    tout[curr]=cnt-1;
}
```

### Properties
 - tin[u] <= tin[v] <= tout[u] => v is in u's subtree
 - If we sort the nodes by their tin, all the nodes of u's subtree are in the range [tin[u],tout[u]]

## Topoloigcal sort
## Binary lifting + LCA
## Bellman-Ford
## Hashing
## Trie

## Debugging checklist
 - Input format
 - INF size - invalid options never chosen
 - Edge cases
 - Modulo (correct number?)
 - Div /0 (or %0)
 - Global array sizes + initialization (every time + all elements)
 - Interactive probs: print sth (at least one intsruction etc.)
