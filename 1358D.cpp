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
vll pref1,pref2,arr;
ll n,x;

ll bsearch(ll low, ll high, ll y){
   ll index = high;	
   while(low<=high){
   	 ll mid = (low+high)/2;

   	 if(y - pref1[mid] < x){
   	 	high = mid - 1;
   	 }
   	 else{
   	 	index = mid;
   	 	low = mid + 1;
   	 }
   }
   return index;
}

ll calculate(ll p){
	return p*(p+1)/2;
}

int main(){
	cin>>n>>x;
	arr.resize(2*n);
	for0(i,n){
		cin>>arr[i];
		arr[i+n] = arr[i];
	}

	pref1 = vll (2*n);
	pref2 = vll (2*n);
	pref1[0] = arr[0];
	pref2[0] = calculate(arr[0]);

	for(int i=1;i<(2*n);i++){
		//prefix sum for the number of hugs.
		pref2[i] = pref2[i-1] + calculate(arr[i]);
		//prefix sum for the number of days
		pref1[i] = pref1[i-1] + arr[i];
	}


    ll ans = 0;
    for(ll i=2*n-1;i>=n;i--){
    	ll index = i;
    	index = bsearch(0,i,pref1[i]);
    	ll temp;
    	temp = pref2[i] - pref2[index];
    	if(pref1[i] - pref1[index] > x){
    		temp-=(calculate((pref1[i] - pref1[index]) - x));
    	}
    	ans = max(ans,temp);
    }
    cout<<ans<<endl;	
}

