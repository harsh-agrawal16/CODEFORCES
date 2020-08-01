/* 
Author : agrwl.harsh (COdeforces)
         Harshagrawal16 (Codechef)
*/


#include <bits/stdc++.h>
#define ll                      long long
#define ld                      long double
#define ull                     unsigned long long
#define fastIO                  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl                    "\n"
#define for0(i,n)               for(ll i=0;i<n;i++)
#define fo(i,a,b)               for(int i = a; i<=b ; i++)
#define rfo(i,a,b)              for(int i = a; i>=b ; i--)
#define vii                     vector<int>
#define vll                     vector<ll>
#define pq                      priority_queue
#define uom                     unordered_map
#define all(v)                  v.begin(),v.end()
#define mp                      make_pair
#define pb                      push_back
#define pob                     pop_back
#define ff                      first
#define ss                      second
#define pii                     pair<int,int>
#define pll                     pair<long,long>
#define mll                     map<ll,ll>
#define mii                     map<int,int>
#define vvii                    vector<vii>
#define vvll                    vector<vll>
#define mod                     1000000007
#define MIN                     -1e9
#define pi                      3.1415926535897932384626433832795

using namespace std;

void INPUT()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}


ll power(ll n, ll p){
	ll res = 1LL;

	while(p){
		if(p&1) res*=n;
		res%=mod;

		n*=n;
		n%=mod;

		p>>=1LL;
	}

	return res;
}


vll uv;
vvll adj;
vll p,h,g;
string ans;

ll modi(ll n){
	if(n<0) return n*(-1);
	return n;
}


ll dfs(ll u, ll prev){
	ll sum = 0;
	uv[u] = p[u];

	for(auto v : adj[u]){
		if(v==prev) continue;
		uv[u]+=dfs(v, u);
		sum+=g[v];
	}

	if((h[u] + uv[u])%2!=0){ans="NO";}
   	g[u] = (h[u] + uv[u])/2;

   	if(g[u] > uv[u]){ans="NO";}
   	if(g[u] < 0){ans="NO";}

   	if(sum>g[u]){ans="NO";}

	return uv[u];
}

void solve(){
	ll n,m;
	cin>>n>>m;

	p = vll (n+1); h = vll (n+1);
	uv = vll (n+1,0);
	g = vll (n+1,0);

	for0(i,n) {cin>>p[i+1];}
	for0(i,n) cin>>h[i+1];
    

	adj = vvll(n+1);

	for0(i,n-1){
		ll x,y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
    
   ans = "YES";
   
   dfs(1,-1);
    
   

   cout<<ans<<endl;
}


int main() {

  fastIO;
 // INPUT();

  ll t;
  cin>>t;
// cin >> t;

  fo(i, 0, t - 1)
  {
  	solve();
  }
  return 0;
}

