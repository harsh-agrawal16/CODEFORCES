
/**
        *AUTHOR:Harsh Agrawal*
        *Birla Institute of Technology,Mesra*    
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=2e5+1;
#define forn(i,e) for(ll i=0;i<e;i++)
#define forni(i,x,e) for(ll i=x;i<e;i++)
#define ln "\n"
#define in(a) cin>>a
#define out(a) cout>>a;

vector<vector<ll>> adList(N);

bool dfs(ll u, ll prev, vector<bool> q, ll count){
    if(q[u])count--;
    if(count==0) return true;

    ll temp = count;
    bool te = false;
    for(auto v: adList[u]){
        if(adList[u].size()>=2){for(auto x: adList[u]) if(x!=prev && x!=v) if(q[x]) count--;}
        if(count == 0 ) return true;
        if(v!=prev){
            te = te || dfs(v,u,q,count);
        } 
        if(te) return true;
        count = temp;
    }

    return false;
}

int main(){
    ll n,m;cin>>n>>m;
    
    for(ll i=0;i<n-1;i++){
        ll x,y;cin>>x;cin>>y;
        adList[x].push_back(y);
        adList[y].push_back(x);
    }

    //vector<bool> q(m+1,false);
    for(ll i=0;i<m;i++){
        vector<bool> q(n+1,false);
        ll k;
        cin>>k;
        ll count =0;
        forn(i,k){
            ll x;cin>>x;
            q[x] = true;
            count++; //since all are different.
        }
        
        if(q[1]) count--;
        if(count==0){cout<<"YES"<<ln; continue;}
        if(dfs(1,-1,q,count)) cout<<"YES"<<ln; 
        else cout<<"NO"<<ln;
    }

    
}

 