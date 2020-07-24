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
	ll ans = -1;
    ll n;
    cin>>n;
	vll arr(n);
	vector<bool> _map(1025,false);	
	for(ll i=0;i<n;i++){
		cin>>arr[i];
		_map[arr[i]] = true;
	}


	if(n%2!=0){
		cout<<-1<<endl;
		return;
	}
    
    ll j;
	for(ll i=1;i<=1024;i++){
		for(j=0;j<n;j++){
			if(!_map[arr[j]^i]) break;
		}
		if(j==n) {ans = i;break;}
	}

	cout<<ans<<endl;

	
}

int main(){
	fastIO;
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
}                