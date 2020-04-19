#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 10000000

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) cin>>arr[i];
        
    vector<vector<ll>> ans(n,vector<ll>(2,1));
    ans[0][0] = 1;
    ans[0][1] = 1;

    for(ll i=1;i<n;i++){
        if(i==1){
            if(arr[i]>arr[i-1]){
                ans[i][0] = 1;
                ans[i][1] = ans[i-1][1]+1;
            }
            continue;
        }

        if(arr[i]>arr[i-1]){
            ans[i][0] = ans[i-1][0]+1;
            ans[i][1] = ans[i-1][1]+1;
        }
        if(arr[i]>arr[i-2] && arr[i]<=arr[i-1] ){
            ans[i][0] = max(ans[i][0], ans[i-2][1]+1);
            ans[i][1] = 1;
            continue;
        }
        if(arr[i]>arr[i-2] && arr[i]>arr[i-1]){
            ans[i][0] = max(ans[i][0], ans[i-2][1]+1);
            ans[i][1] = ans[i-1][1]+1;
        }

    } 

    ll mx = 0;
    for(ll i=0;i<n;i++){
        if(ans[i][0]>mx){
            mx = ans[i][0];
        }
        if(ans[1][1]>mx){
            mx = ans[i][1];
        }
    }

    cout<<mx<<"\n";

}