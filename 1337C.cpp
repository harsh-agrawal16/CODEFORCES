#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+1;
ll i,k,m,n,u,v;
vector<ll> g[N];
ll h[N],*e;

ll dfs(ll r,ll p, ll d){
    ll s=1;
    for(auto v : g[r]){if(v!=p) s+=dfs(v,r,d+1);}
    h[r] = d - s;
    return s;     
}

int main(){
    cin>>n>>k;
    //creating adjacency list.
    e = h+n+1;
    for(i=0;i<n-1;i++){cin>>u>>v;g[u].push_back(v);g[v].push_back(u);}
    dfs(1,-1,1);
    sort(h+1,e);
    //accumulate is use to sum in a given range.
    cout<<accumulate(e-k,e,0ll)<<"\n";
}
