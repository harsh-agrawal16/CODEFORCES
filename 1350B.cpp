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

vll arr;
vll dp;
ll n;

ll func(ll ind){
	if(ind>n) return 0;
	if(dp[ind]!=-1) return dp[ind];

	ll count = 0;

	for(ll i=2*ind;i<=n;i+=ind){
		if(arr[i]>arr[ind]){
			count = max(count, 1 + func(i));
		}
	}

	dp[ind] = count;
	return dp[ind];
}

int main(){
	ll t;
	cin>>t;
	while(t--){
		cin>>n;
		arr = vll (n+1);
		dp = vll (n+1,-1);
		for(ll i=1;i<=n;i++){
			cin>>arr[i];
		} 
		
		ll maxi = 1;
		for(ll i=1;i<=n;i++){
			maxi = max(maxi, 1 + func(i));
		}

		cout<<maxi<<endl;
	}
}


