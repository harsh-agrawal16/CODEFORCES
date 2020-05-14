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


int main(){
	ll n;
	cin>>n;
	vll arr(n);
	for(ll i=0;i<n;i++){
		cin>>arr[i];
	}

	vll suffix_gcd(n);
	suffix_gcd[n-1] = arr[n-1];
	for(ll i=n-2;i>=0;i--){
		suffix_gcd[i] = __gcd(suffix_gcd[i+1],arr[i]);
	}

	ll g1 = (arr[0]*suffix_gcd[1])/(__gcd(arr[0],suffix_gcd[1]));
	ll ans = g1;
	ll g2;
	for(ll i=1;i<n-1;i++){
		g2 = (arr[i]*suffix_gcd[i+1])/(__gcd(arr[i],suffix_gcd[i+1]));
		ans = __gcd(g1,g2);
		g1 = ans;
	}

	cout<<ans<<endl;
	
}


