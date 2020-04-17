#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+1;
#define forn(i,e) for(ll i=0;i<e;i++)
ll i;
ll ans;
ll l,u;


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


void solve(vector<ll> &R,vector<ll> &G,vector<ll> &B,ll i){
    ll r = R.size();
    ll g = G.size();
    ll b = B.size();
    l = lower_bound(R[i],G,0,g-1); u = upper_bound(R[i],B,0,b-1);
    if(l!=-1 && u!=-1) ans = min(ans, (ll) (pow(R[i]-G[l],2) + pow(R[i]-B[u],2) + pow(B[u]-G[l],2)));
}

int main(){
    ll t;cin>>t;
    while(t--){
        ll r,g,b;
        cin>>r>>g>>b; 
        vector<ll> R(r),G(g),B(b); 
        for(i=0;i<r;i++) cin>>R[i];
        for(i=0;i<g;i++) cin>>G[i];
        for(i=0;i<b;i++) cin>>B[i];
        sort(R.begin(),R.end()),sort(G.begin(),G.end()),sort(B.begin(),B.end());
        
        ans = 1ll<<62;
        forn(i,r){solve(R,G,B,i);solve(R,B,G,i);}
        forn(i,g){solve(G,R,B,i);solve(G,B,R,i);}
        forn(i,b){solve(B,R,G,i);solve(B,G,R,i);}
        cout<<ans<<"\n";
    }

}
