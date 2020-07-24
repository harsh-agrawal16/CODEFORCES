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
#define for1(i,e) for(ll i=1;i<e;i++)
#define forx(i,x,e) for(ll i=x;i<e;i++)
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


void solve(){
	ll n;
	string a, b;
	cin>>n>>a>>b;

	vll ans;

	// if(a == b){
	// 	cout<<0<<endl;
	// 	return;
	// }
    char x = a[0];
	for(ll i=0;i<n-1;i++){
		if(a[i] == x && a[i+1]!=x){
			ans.pb(i+1);
			x = a[i+1];
		}
	}

	if(a[n-1] != x){
		ans.pb(n);
		x = a[n-1];
	}

	// cout<<a<<endl;
    
	for(ll i=n-1;i>=0;i--){
		if(b[i] != x){
			ans.pb(i+1);
			x = b[i];
		}
	}

	cout<<ans.size()<<" ";

	for(ll i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	// cout<<a<<endl<<b<<endl;
}

int main(){
	fastIO;
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
}                