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
ll cost = 0;
ll n;
vvll adj;
vll arr,b,c;

pair<ll, ll> dfs(ll u, ll prev, ll cs){
	pair<ll,ll> a = {0,0};

	if(b[u]!=c[u]){
		if(b[u]==0) a.first++;
		else a.second++;
	}

	for(auto &i : adj[u]){
		if(i==prev) continue;
		pair<ll,ll> temp = dfs(i,u,min(arr[u],cs));
		a.first+=temp.first;
		a.second+=temp.second;
	}

	if(arr[u]<cs){
		ll temp = min(a.first, a.second);
		a.first-=temp;
		a.second-=temp;
		temp = 2*temp*arr[u];
		cost+=temp;
	}

	return a;
}


void solve(){
	cin>>n;
	adj = vvll (n+1);
	arr = vll (n+1);
	b = vll (n+1);
	c = vll (n+1);

	for0(i,n){
		cin>>arr[i+1]>>b[i+1]>>c[i+1];
	}

	for0(i,n-1){
		ll u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	pair<ll , ll > ans = dfs(1,0,LLONG_MAX);

	if(ans.first!=0 || ans.second!=0){
		cout<<-1<<endl;
	}
	else{
		cout<<cost<<endl;
	}
	
}


int main(){
	fastIO;
	ll t;
	t=1;
	while(t--){
		solve();
	}
}
	