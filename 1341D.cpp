/**
        *AUTHOR:Harsh Agrawal*
        *Birla Institute of Technology,Mesra*    
**/

#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef unsigned long long ull;
const int N=2e5+1;
#define for0(i,e) for(ll i=0;i<e;i++)
#define forx(i,x,e) for(ll i=x;i<e;i++)
#define ln "\n"
#define in(a) cin>>a
#define out(a) cout>>a;
#define vll vector<ll> 
#define vvll vector<vll>
#define qll queue<ll>
#define fastIO  ios_base::sync_with_stdio(0);\
                cin.tie(NULL);\
                cout.tie(NULL)
vvll changes(2001, vll (10,-1));
vector<vvll> dp(2001, vvll(2001, vll(10,-1)));
ll n;
vector<string> s(2001);
string w[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
void store(ll i, ll j){
	string a = s[i];
	string b = w[j];
	ll count = 0;
	for0(k,7){
		if(a[k]!=b[k] && a[k]=='0') count++;
		else if(a[k]!=b[k] && a[k]=='1'){changes[i][j]=-1;return;}
	}
	changes[i][j] = count;
}

ll rec(ll i,ll k){
	if(i==n && k==0) return 1;
	if(i==n && k!=0) return 0;
	if(dp[i][k][0]==-1){
		ll x = 0;
		ll p = 0;
		for(ll j=9;j>=0;j--){
			if(changes[i][j]<=k && changes[i][j]!= -1)   x = rec(i+1,k-changes[i][j]);
			dp[i][k][j] = x;
			if(x==1) p =1;
		}	
		return p;
   }

   for(ll r=9;r>=0;r--){
   	 if(dp[i][k][r]==1) return 1;
   }
   return 0;
}



int main(){
	ll k;
	fastIO;
    cin>>n>>k;

	for0(i,n){cin>>s[i];for0(j,10) store(i,j);}   
	if(!rec(0,k)) {cout<<"-1"<<endl;return 0;}
	string ans = "";
	for0(i,n){
		for(ll j=9;j>=0;j--){
			if(dp[i][k][j]){
				ans+=to_string(j);
				k-=changes[i][j];
				break;
			}	
		}
	}
    //cout<<dp[0][5][9]<<endl;
	cout<<ans<<endl;
}