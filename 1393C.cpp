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

vll cnt;
vll arr;
ll n;


bool check(ll x){
    
    cnt = vll(100009,0);
    for(ll i=0;i<n;i++){
    	cnt[arr[i]]++;
    }

	set<pair<ll,ll>, greater<pair<ll,ll>>> ss;
    
    for(ll i=0;i<n;i++){
    	ss.insert({cnt[arr[i]], arr[i]});
    }

	vll b;
	for(ll i=0;i<n;i++){

		if(i>=x && cnt[b[i-x]]){
			ss.insert({cnt[b[i-x]], b[i-x]});
		}


		if(ss.empty()) return 0;
		b.push_back(ss.begin()->second);
		cnt[ss.begin()->second]--;
		ss.erase(ss.begin());
	}

	return 1;

}


void solve(){
	cin>>n;
	arr.resize(n);

	for(ll i=0;i<n;i++) cin>>arr[i];

	ll low = 1;
	ll high = n-1;
    ll ans = 0; 
	while(low<=high){
		ll mid = (low + high) / 2;

		if(check(mid)){
			ans = mid;
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}

    if(ans==0) cout<<0<<endl;
	else cout<<ans-1<<endl;

}
    




int main(){
	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}
