#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=2e5+1;
#define forn(i,e) for(ll i=0;i<e;i++)
#define forni(i,x,e) for(ll i=x;i<e;i++)
#define ln "\n"
#define in(a) cin>>a
#define out(a) cout>>a;
#define fastIO  ios_base::sync_with_stdio(0);\
                cin.tie(NULL);\
                cout.tie(NULL)

//a very good question. learned about the prefix trick.                

int main(){
  fastIO;
  ll t;cin>>t;
  while(t--){
    ll n,k;cin>>n>>k;

    vector<ll>arr(n);
    forn(i,n) cin>>arr[i];

    vector<ll> cnt1(2*k + 2, 0);
    vector<ll> pref(2*k+2,0);

    forn(i,n/2){
        cnt1[arr[i] + arr[n-i-1]]++;
    }

    forn(i,n/2){
        ll l = min(arr[i],arr[n-i-1]) + 1; ll r = max(arr[i],arr[n-i-1])+ k;

        pref[l]++;
        pref[r+1]--;
    }

    for(ll i=1;i<=2*k+1;i++){
        pref[i]+=pref[i-1];
    }

    ll ans = LLONG_MAX;
    for(ll i=2;i<=2*k+1;i++){
        ans = min(ans , pref[i] - cnt1[i] +  (n/2 - pref[i])*2);
    }
    cout<<ans<<ln;


  }

}
    


