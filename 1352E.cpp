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


int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vi arr(n);
		vi cnt(n+1,0);
		for(ll i=0;i<n;i++){
			cin>>arr[i];
			cnt[arr[i]]++;
		}
        
        if(n==1){
        	cout<<0<<endl;
        	continue;
        }

        ll ans = 0;

        for(ll i=0;i<n-1;i++)
        {
        	ll sum = arr[i];
        	for(ll j=i+1;j<n;j++){
        		sum+=arr[j];
        		if(sum<=n)
        		{
        		    ans+=cnt[sum];
        		    cnt[sum] = 0;
        		}
        	}
        }


		cout<<ans<<endl;
	}
}


