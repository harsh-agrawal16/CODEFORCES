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

void solve(){
	ll n;
	cin>>n;
	vll arr(n);
	for0(i,n) cin>>arr[i];

	ll g,s,b;
	ll count = 0;

	if(n<10){cout<<0<<" "<<0<<" "<<0<<endl;return;}

	for(ll j=0;j<n;j++){
		if(arr[j] == arr[n/2-1]) count++;
	}

	ll i=0;
    g = 1;
    for(i=1;i<n;i++){
    	if(arr[i]==arr[i-1]) g++;
    	else break;
    	if(g>=n/2){
    		cout<<0<<" "<<0<<" "<<0<<endl;
    		return;
    	} 
    }


    
    s = 1;
    i+=1;
    for(;i<n;i++){
    	if(s<=g) s++;
    	else if(arr[i]==arr[i-1]) s++;
    	else if(arr[i]!=arr[i-1]) break; 
    }
	
	if(g+s>=n/2){cout<<0<<" "<<0<<" "<<0<<endl;return;}
	
	b=1;
	i+=1;
    for(;i<n;i++){
    	if(b<=g || i<n/2) b++;
    	else if(arr[i]==arr[i-1]) b++;
    	else break;
    }
    
    if(arr[n/2] == arr[n/2-1]) b-=count;
    if(b<=g || (b+s+g)>n/2 ){cout<<0<<" "<<0<<" "<<0<<endl;return;}

    cout<<g<<" "<<s<<" "<<b<<endl;
    return;    
}


int main(){
	fastIO;
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
}
	