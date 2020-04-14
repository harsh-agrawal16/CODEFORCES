#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> arr(n);
		for(ll i=0;i<n;i++) cin>>arr[i];

		sort(arr.begin(),arr.end());
		ll k = (n-1)/2;

		for(ll i=0;i<n;i++){
			if(i&1){
				cout<<arr[k+(i+1)/2]<<" ";
			}
			else{
				cout<<arr[k-i/2]<<" ";
			}
		}

		cout<<"\n";

	}
}