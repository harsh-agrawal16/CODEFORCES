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
#define for1(i,e) for(ll i=1;i<n;i++)
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
	string s;
	cin>>s;

	ll n = s.length();

	bool ok = true;


    s = "w"+s+"2";
    for(ll i=1;i<s.length()-1;i++){
    	if(s[i] == '?'){
    		if(s[i-1]!='a' && s[i+1]!='a') s[i] = 'a';
    		if(s[i-1]!='b' && s[i+1]!='b') s[i] = 'b';
    		if(s[i-1]!='c' && s[i+1]!='c') s[i] = 'c';
    	}

    	if(s[i] == s[i-1]){ok = false;break;}	
    }

    if(!ok) cout<<-1<<endl;
    else cout<<s.substr(1,n)<<endl;
}


int main(){
	fastIO;
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
}
	