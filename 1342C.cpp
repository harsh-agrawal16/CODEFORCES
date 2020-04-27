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


ll gcd(ll a, ll b){
	if(a==0) return b;
	else return gcd(b%a,a);
}

ll LCM(ll a, ll b){
	//lcm*hcf =  a*b;
	ll lc = a*b;
	ll gg = gcd(a,b);
	return lc/gg;
}

ll findCount(ll r, ll lcm, ll b){
	ll div  = r/lcm;
	ll cnt = r;
	if(div>=1){
		cnt -= (div-1)*b;
		if(r%lcm < b) cnt-=(r%lcm + 1);
		else cnt-=b;
	}
	return cnt-=min(r,b-1);
}

int main(){
	fastIO;

	ll t;cin>>t;
	while(t--){
		ll a,b,q;cin>>a>>b>>q;
		if(a>b) swap(a,b);
		ll lcm = LCM(a,b);
		while(q--){
			ll l,r,count,ans;cin>>l>>r;		

			if(lcm==b || r<b){
				cout<<"0"<<" ";
				continue;
			}
			
			count = findCount(r,lcm,b);
			if(l>1) count -= findCount(l-1,lcm,b);
			cout<<count<<" ";
		}
		cout<<endl;
	}
	
}

