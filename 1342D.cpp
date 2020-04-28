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
	fastIO;
    int n,k;cin>>n>>k;
    vi limits(k+1);
    vi count(k+1,-1);
    vi arr(n);
    for0(i,n) cin>>arr[i];
    for0(i,k) cin>>limits[i+1];

    sort(arr.begin(),arr.end());
    count[1] = n;
    int prev = 1; 
    for0(i,n){
    	if(arr[i]!=prev){
    		count[arr[i]] = n - i;
    		prev = arr[i];
    	}
    }

    prev = 0;
    int ans = 0;
    for(int i=k;i>0;i--){
    	if(count[i]==-1){
    		count[i] = prev;
    	}
    	else{
    		prev = count[i];
    		ll te = ceil((double) count[i] / limits[i]);
    		if(te>ans) ans = te;
    	}
    }

    vvi testcases(ans);
    int j = 0;
    for0(i,n){
    	testcases[j].pb(arr[i]);
    	j = (j+1)%ans;
    }

    cout<<ans<<endl;
    for0(i,ans){
    	cout<<testcases[i].size()<<" ";
    	for0(j,testcases[i].size()){
    		cout<<testcases[i][j]<<" ";
    	}
    	cout<<endl;
    }


 
}

