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
#define vii                    vector<int>
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
	string s;
	ll x;
	cin>>s>>x;
    
    ll n = s.length();
	string ans = "";

	for0(i,n){
		ans+='1';
	}

	for0(i,n){
		if(s[i] == '0'){
			if(i-x>=0) ans[i-x] = '0';
			if(i+x<n) ans[i+x] = '0';
			if(i-x<0 && i+x>=n) ans[i] = '0';
		}
	}

	bool ok = true;

	for0(i,n){
		if(s[i] == '1'){
			if(i-x>=0 && ans[i-x]=='0' && i+x<n && ans[i+x]=='0') ok = false;
			else if(i-x>=0 && i+x>=n && ans[i-x] == '0') ok = false;
			else if(i+x<n && i-x<0 && ans[i+x] == '0') ok = false;
			else if(i-x<0 && i+x>=n) ok = false;
		}


	}

	if(ok){
		cout<<ans<<endl;
	}else{
		cout<<-1<<endl;
	}
}


int main(){
	ll t;
	cin>>t;
	for(ll i=1;i<=t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
}