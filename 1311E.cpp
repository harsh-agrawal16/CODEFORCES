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

ll head[5001],ans[5001];

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,d;
        cin>>n>>d;

        for(ll i=1;i<=n;i++){
            ans[i] = i/2;
            d-=(64 - __builtin_clzll(i) -1);
        }

        for(ll i=0,j=1;j<=n;i++,j*=2){
            head[i] = j;
        }

        ll mx = (64 - __builtin_clzll(n) -1);
        for(ll i=n;i && d>0;i--){
            if((i & (i-1)) == 0) continue;
            ++mx;
            head[mx] = i;
            for(ll j= 64 - __builtin_clzll(i) -1; j<mx && d>0 ;j++){
                d--;
                ans[i] = head[j];
            }
        }

        if(d) cout<<"NO"<<ln;
        else{
            cout<<"YES"<<ln;
            for(ll i=2;i<=n;i++) cout<<ans[i]<<" ";
            cout<<ln;   
        }

    }
   
}


