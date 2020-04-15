#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 10000000

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        
        vector<pair<ll,ll>> m(n);
        ll mi=10000000000000;
        ll k = 0;
        for(ll i=0;i<n;i++){
            cin>>m[i].first>>m[i].second;
            mi = min(mi, min(m[i].first,m[i].second));
        }
        
        for(ll i=0;i<n;i++){
        	if(m[i].second < m[(i+1)%n].first) k+=(m[(i+1)%n].first - m[i].second);
        }

        cout<<k+mi<<endl;


    }


}