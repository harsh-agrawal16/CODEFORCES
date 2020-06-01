/**
        *AUTHOR:Harsh Agrawal*
        *Birla Institute of Technology,Mesra*    
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=2e5+1;
#define for0(i,e) for(ll i=0;i<e;i++)
#define forx(i,x,e) for(ll i=x;i<e;i++)
#define endl "\n"
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
vvll adj;
ll n,x;


ll dfs(ll y,ll prev,ll count){
	count++;
	for(auto i : adj[y]){
		if(i!=prev) count = dfs(i,y,count);
	}
	return count;
}


void solve(){
	cin>>n>>x;
	adj = vvll (n+1);

	for0(i,n-1){
		ll u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
    
    //cout<<adj[x].size()<<endl;
	if(adj[x].size()==1){
		cout<<"Ayush"<<endl;
	}
    
    else if(n%2!=0){
    	cout<<"Ashish"<<endl;
    }

    else if(n%2==0){
    	cout<<"Ayush"<<endl;
    }
}


int main(){
	fastIO;
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
}
	