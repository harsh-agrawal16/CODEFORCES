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
vll c;
vll dp;


ll rec(ll x){
	if(dp[x]!=-1) return dp[x];

	if(x==2) {dp[x] = max(x*c[x], (x-1)*c[x-1]); return dp[x];}
	if(x==1) {dp[x] = x*c[x];return dp[x];}

	dp[x] = max(x*c[x] + rec(x-2) , (x-1)*c[x-1] + rec(x-3));
	return dp[x];
}


int main(){
	ll n;
	cin>>n;
    
    vll arr(n);
    c = vll (100001,0);
    dp = vll (100001,-1);
    dp[0] = 0;
    for0(i,n) {cin>>arr[i]; c[arr[i]]++;}
    sort(arr.begin(),arr.end());
    ll mx = arr[n-1];

    cout<<rec(mx)<<endl;

} 
