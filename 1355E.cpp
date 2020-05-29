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

long double pi = 3.141592653589793238;
vll arr;
vll pref;
ll n,a,r,m;
ll sum=0;

ll bsearch(ll low, ll high , ll x){ 
    ll ans = high;
	while(low<=high){
		ll mid = (low+high)/2;

		if(arr[mid]>x){
			ans = mid;
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}
	return ans;
}

ll fun(ll height){
	ll index = bsearch(0,n-1,height);
	ll p = height*(index) - pref[index-1];
	ll q = (pref[n-1] - pref[index-1])  - (n-index)*height;

	if(p>=q){
		return (p-q)*a + m*q;
	} 
	else{
		return (q-p)*r + m*p;
	}
}


ll ternary_search(ll l, ll r){

	while(r-l>3){
		ll m1 = l + (r-l)/3;
		ll m2 = r - (r-l)/3;

		if(fun(m2) > fun(m1)) r = m2;
		else l = m1;
	}
    
    ll ans = fun(l);
	for(ll i=l;i<=r;i++){
		ans = min(ans,fun(i));
	}

	return ans;
}


int main(){
	fastIO;
	cin>>n>>a>>r>>m;

	if(n==1){cout<<0<<endl;return 0;}

	arr.resize(n);pref.resize(n);
	for0(i,n){cin>>arr[i];sum+=arr[i];}
    m = min(m,a+r);
    sort(arr.begin(),arr.end());
     //calculated prefix sum to aid me in calculating p and q;
    pref[0] = arr[0];
    for(ll i=1;i<n;i++) pref[i] = pref[i-1] + arr[i];
    cout<<ternary_search(arr[0],arr[n-1]);   
}