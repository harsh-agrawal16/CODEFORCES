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


int main(){
	ll t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
        
        ll n = s.length();
		ll z = 0, on = 0;
		for0(i,s.length()){
			if(s[i]=='0') z++;
			else on++;
		}

		ll ans = min(z,on);
        
        z = 0;
        on = 0;
        ll moves = 0;
		for0(i,n){
			if(s[i]=='0' && on>0){
				z++;
				if(z>=on){
					moves+=on;
					on = 0;
					z = 0;
				}
			}
			else if(s[i] =='1'){
				on++;
			}
		}

		moves+=z;

		ans = min(ans,moves);

		moves = 0;
		z = 0; on = 0;

		for0(i,n){
			if(s[i]=='1' && z>0){
				on++;
				if(on>=z){
					moves+=z;
					z = 0;
					on = 0;
				}
			}
			else if(s[i] =='0'){
				z++;
			}
		}
		moves+=on;

		ans = min(ans,moves);

		cout<<ans<<endl;


	}
}