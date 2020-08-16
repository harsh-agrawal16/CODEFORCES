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


void solve(){
	ll n;
	cin>>n;

	string s;
	cin>>s;

	vll pref(n+1,0);
	unordered_map<ll,ll> mp;
	ll ans = 0;

	for(ll i=1;i<=n;i++){
		pref[i] = pref[i-1] + (s[i-1] - '0');
		// if(s[i-1] == '1') ans++;
		mp[pref[i] - i]++;
	}
	mp[0]++;

	for(auto iter = mp.begin(); iter!=mp.end(); iter++){
		ll x = iter->second;
        // cout<<iter->first<<": "<<x<<" ";
	    ans += (x*(x-1))/2;
	}

	cout<<ans<<endl;

}



int main(){
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
}