/**
        *AUTHOR:Harsh Agrawal*
        *Birla Institute of Technology,Mesra*    
**/

#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef unsigned long long ull;
const int N=2e5+1;
#define for0(i,e) for(int i=0;i<e;i++)
#define forx(i,x,e) for(int i=x;i<e;i++)
#define ln "\n"
#define in(a) cin>>a
#define out(a) cout>>a;
#define pb push_back
#define vll vector<ll> 
#define vvll vector<vll>
#define vi vector<int>
#define vvi vector<vi>
#define qll queue<ll>
#define fastIO  ios_base::sync_with_stdio(0);\
                cin.tie(NULL);\
                cout.tie(NULL)
vi pa;
vvi adj;
vi d;
vi tin,tout;
int T;

void dfs(int u, int prev, int dep){
    d[u] = dep;
    pa[u] = prev;
    tin[u] = T++; //entry time.
    for(auto edge : adj[u]){
        if(edge != prev) dfs(edge,u,dep+1);
    }
    tout[u] = T++; //exit time.
}

bool isAncestor(int u, int v){
    if(tin[u]<=tin[v] && tout[u]>=tout[v]) return true;
    return false;
}

int main(){
    fastIO;
    int n,m;
    cin>>n>>m;
    adj = vvi(n+1);
    T=0;
    tin = vi(n+1); tout = vi(n+1);
    pa = vi(n+1); d = vi(n+1);
    for0(i,n-1){
        int x,y;cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1,-1,0);
    while(m--){
        int k;cin>>k;
        vi q(k); for0(i,k) cin>>q[i];
        int u = q[0];
        forx(i,1,k) if(d[u]<d[q[i]]) u = q[i];
        for0(i,k){
            if(q[i]!=u && pa[q[i]]!=-1) q[i] = pa[q[i]];
        }
        bool done = true;
        for0(i,k){
            if(q[i]!=u && q[i]!=1) done&=isAncestor(q[i],u);
        }
        if(done) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    
}