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
#define ln "\n"
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
	ll n;
	cin>>n;
	vll a(n);
	for0(i,n) cin>>a[i];
	unordered_map<ll,ll> HashMap;

	ll ans = 0;
	ll sum;
	ll temp=0;
	for(ll i=0;i<n;i++){
		sum = a[i];
		temp = 0;
		if(sum==0) continue;
		HashMap[sum] = i;
		for(ll j=i+1;j<n;j++){
			sum+=a[j];
			if(sum==0){
				ll x = ((j-1)-i) + 1;
				ans+=x;
				temp = 0;
				break;
			}
			if(HashMap.find(sum) == HashMap.end()){
				HashMap[sum] = i;
				temp = (j-i) + 1;
			}
			else{
				ll x = ((j-1)-i) + 1;
				ans+=x;
				temp = 0;
				break;
			}
		}
		ans+=temp;
		temp = 0;
		HashMap.clear();
	}

	if(a[n-1]!=0) ans+=1;
	cout<<ans<<endl;
}

