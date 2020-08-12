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

void solve(){
	ll n;

	vll dp(1000001,-1);
    
    ll good, bad;

    dp[3] = 2;
    bad = 4;
    ll prev = 6;

    for(ll i=4;i<=1000000;i++){
    	dp[i] = ((dp[i-1]*(i))%mod + (bad*(i-2))%mod)%mod;

    	bad = ((prev*i)%mod - dp[i])%mod;
    	prev = (prev*i)%mod;
    	if(bad<0) bad+=mod;
    }
    
    cin>>n;
    cout<<dp[n]<<endl;

}
int main() {
  
 fastIO;
 ll t;
 t=1;
 while(t--){
 	solve();
 }
 
}

