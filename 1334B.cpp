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
        ll n,x;
        cin>>n>>x;

        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);

        ll ans=0;
        ll sum=0;
        for(ll i=n-1;i>=0;i--){
            sum+=arr[i];
            if((sum/(n-i)>=x)) ans++;
        }

        cout<<ans<<"\n";

    }

}