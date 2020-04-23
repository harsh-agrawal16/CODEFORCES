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
#define ln "\n"
#define in(a) cin>>a
#define out(a) cout>>a;
#define vll vector<ll> 
#define vvll vector<vll>
#define qll queue<ll>
#define fastIO  ios_base::sync_with_stdio(0);\
                cin.tie(NULL);\
                cout.tie(NULL)

ll n,m,a,b,c;

vll dijkstra(ll u, vvll &adList){
	vll spaths(n+1,LLONG_MAX);
	vector<bool> visited(n+1, false);
	spaths[u] = 0;
	qll q;
	q.push(u);
	while(!q.empty()){
		ll temp = q.front();
		q.pop();
		visited[temp] = true;
		for(auto v:adList[temp]){
			if(!visited[v]){
				spaths[v] = min(spaths[v],spaths[temp]+1);
				q.push(v);
			}
		}
	}
	return spaths;
}
ll dfs_b(ll u,vector<bool> &v,vvll &adList,ll d){
	//if(u==a) d=0;
	if(u==b) return d;
	v[u] = true;
	ll mn = LLONG_MAX;
	for(auto x:adList[u]){
		if(!v[x]) mn  = min(mn, dfs_b(x,v,adList,d+1));
	}
	return mn;
 }


ll dfs_c(ll u,vector<bool> &v,vvll &adList,ll d){
	if(u==a) d=0;
	if(u==c) return d;
	v[u] = true;
	ll mn = LLONG_MAX;
	for(auto x:adList[u]){
		if(!v[x]) mn  = min(mn, dfs_c(x,v,adList,d+1));
	}
	return mn;
}

int main(){
	fastIO;
	ll t;cin>>t;
	while(t--){
		cin>>n>>m>>a>>b>>c;
		vll p(m);for0(i,m) cin>>p[i];
		sort(p.begin(),p.end());
		for(ll i=1;i<m;i++){
			p[i]+=p[i-1];
			//cout<<p[i]<<" ";
		}
	
		vvll adList(n+1);
		for0(i,m){
			ll u,v;cin>>u>>v;
			adList[u].push_back(v);
			adList[v].push_back(u);
		}
        vector<bool> v(n+1,false);
        
        if(a==b && b==c) {cout<<0<<ln;continue;} 
        vll ax = dijkstra(a,adList);
        vll bx = dijkstra(b,adList);
        vll cx = dijkstra(c,adList);
        
        ll ans = LLONG_MAX;
        ll sum,x;
        for(ll i=1;i<=n;i++){
        	x = ax[i] + bx[i] + cx[i];
        	sum = 0;
        	
        	if(x>m) continue;

        	if(bx[i]>0) sum = p[bx[i]-1];

            ans = min(ans, sum+p[x-1]);

        }
        cout<<ans<<ln;

	}
    
}