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

void solve(){
	ll n;
	cin>>n;
	vll arr(n);
	map<ll,ll> c;
	for0(i,n) {cin>>arr[i];c[arr[i]] = i;}
	vll ans(n+1,0);
    
  
	ll i = 1;
	ll mn = c[i];
	ll mx = c[i];
	ans[1] = 1;
	i++;

	while(i<=n){
		mn = min(c[i],mn);
		mx = max(c[i],mx);

		if((mx-mn)+1 == i) ans[i] = 1;
		i++;
	}


    for0(i,n) cout<<ans[i+1];
    cout<<endl;


	


}


int main(){
	fastIO;
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
}
	