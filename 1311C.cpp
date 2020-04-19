#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=1e5+1;
#define forn(i,e) for(ll i=0;i<e;i++)
#define forni(i,x,e) for(ll i=x;i<e;i++)
#define ln "\n"
#define in(a) cin>>a
#define out(a) cout>>a;



//to calculate upper bound
ll upper_bound(ll s,vector<ll> &arr,ll low, ll high){
    ll mid = (high+low)/2;
    ll n = arr.size();
    if(arr[0]>s) return 0;
    if(arr[n-1]<s) return -1;
    if(high<low) return low;
    if(arr[mid]==s) return mid;
    if(arr[mid] < s) return upper_bound(s,arr,mid+1,high); 
    if(arr[mid] > s) return upper_bound(s,arr,low,mid-1);
}


//to calculate lower bound
ll lower_bound(ll s,vector<ll> &arr,ll low, ll high){
    ll mid = (high+low)/2;
    ll n = arr.size();
    if(arr[0]>s) return -1;
    if(arr[n-1]<s) return n-1;
    if(high<low) return high;
    if(arr[mid]==s) return mid;
    if(arr[mid] < s) return lower_bound(s,arr,mid+1,high); 
    if(arr[mid] > s) return lower_bound(s,arr,low,mid-1);
}



int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;in(n),in(m);
        string a;
        in(a);

        vector<ll> p(m);
        vector<ll> ans(26,0);
        forn(i,m) in(p[i]);

        vector<vector<ll>> dp(n, vector<ll>(26,0));

        forn(i,n){
            if(i==0){dp[i][a[i] - 'a']++;continue;}
            forn(j,26){
            	dp[i][j] = dp[i-1][j];
            }
            dp[i][a[i] - 'a']++;
        }

        forn(j,m){
            forn(i,26){
                ans[i]+=dp[p[j]- 1][i];
            }
        }

        forn(i,26){
                ans[i]+=dp[n-1][i];
        }

        forn(i,26) cout<<ans[i]<<" ";
        cout<<ln;
   }
   
}


