/* 
Author : agrwl.harsh (Codeforces)
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


void goodString(){
	string s;
	cin>>s;

	bool same = true;
	for(ll i=1;i<s.length();i++){
		if(s[i] != s[i-1]){
			same = false;
			break;
		}
	}

	if(same){
		cout<<0<<endl;
		return;
	}
    
    ll mx = 0;
    bool fi = false, fj = false;
    ll temp = 0;
	for(ll i=0;i<10;i++){
		for(ll j=0;j<10;j++){
			temp = 0;
			fi = false;
			for(ll k=0;k<s.length();k++){
				if(i==j && s[k] - '0' == i){temp++;continue;}
				if((s[k] - '0') == j && fi){temp++; fi=false;} 
				if((s[k] - '0') == i && !fi){temp++; fi=true;}
			}
			if(i!=j) temp = (temp%2==0)? temp : temp - 1;
			if(temp>=0) mx = max(mx,temp);
		}
	}

	cout<<s.length() - mx<<endl;
}




int main() {

  fastIO;
 // INPUT();

  ll t;
  cin>>t;
// cin >> t;

  fo(i, 0, t - 1)
  {
  	goodString();
  }
  return 0;
}

