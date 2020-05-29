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
ll n;

ll bsearch(ll low, ll high , ll x){ 
    ll ans = high;
	while(low<=high){
		ll mid = (low+high)/2;

		if(arr[mid] == x) return -1;

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



int main(){
	fastIO;
	ll a,r,m;
	ll sum=0;
	cin>>n>>a>>r>>m;

	if(n==1){cout<<0<<endl;return 0;}

	arr.resize(n);pref.resize(n);
	for0(i,n){cin>>arr[i];sum+=arr[i];}
    m = min(m,a+r);
    sort(arr.begin(),arr.end());
     //calculated prefix sum to aid me in calculating p and q;
    pref[0] = arr[0];
    for(ll i=1;i<n;i++) pref[i] = pref[i-1] + arr[i];
   

	ll p = 0,q=0;
	q = (pref[n-1] - pref[0]) - (n-1)*arr[0];
	ll ans = (q-p)*r + m*p;
    ll temp; 

	for(ll i=1;i<n;i++){
		if(arr[i]==arr[i-1]) continue;
        p = arr[i]*(i+1) - pref[i];
        q = (pref[n-1] - pref[i]) - arr[i]*((n-1)-i) ;

		if(q>=p){
			temp = (q-p)*r + m*p;
		}
		else{
			temp = (p-q)*a + m*q;
		}

		if(ans>temp) ans = temp;
	}
    
	ll breakpoint = sum/n + 1;
	ll index = bsearch(0,n-1,breakpoint); //getting the upper_bound
	if(index!=-1){
		p = breakpoint*(index) - pref[index-1];
		q = (pref[n-1] - pref[index-1]) - breakpoint*(n-index);

		if(q>=p){
			temp = (q-p)*r + m*p;
		}
		else{
			temp = (p-q)*a + m*q;
		}

		if(temp<ans) ans = temp;
	}

	breakpoint = sum / n;
	index = bsearch(0,n-1,breakpoint); 
	if(index!=-1){
		p = breakpoint*(index) - pref[index-1];
		q = (pref[n-1] - pref[index-1]) - breakpoint*(n-index);
		if(q>=p){
			temp = (q-p)*r + m*p;
		}
		else{
			temp = (p-q)*a + m*q;
		}
		if(temp<ans) ans = temp;
	}
	cout<<ans<<endl;
}