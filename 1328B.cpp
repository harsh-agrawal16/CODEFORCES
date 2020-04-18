#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=1e5+1;
#define forn(i,e) for(ll i=0;i<e;i++)
#define forni(i,x,e) for(ll i=x;i<e;i++)
#define ln "\n"
#define LLONG_MAX LL_MAX
#define LLONG_MIN LL_MIN
#define ULLONG_MAX ULL_MAX
 


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

void solve(ll n, ll k){
    ll x = ceil((sqrt(1 + 8*k) - 1)/2);
    //cout<<x<<ln;
    vector<char> ans(n,'a');

    ans[n-1-x] = 'b';
    x = x-1;
    ll prev = (x+1)*(x)/2;
    //cout<<prev<<ln;
    ans[n-(k-prev)] = 'b';

    forn(i,n) cout<<ans[i];
    cout<<ln;

}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k; cin>>n>>k;
        solve(n,k);
    }
}


