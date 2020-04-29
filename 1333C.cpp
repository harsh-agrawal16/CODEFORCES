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

//Eugene and array
//A beautiful solution which demonstrates the use of prefix sums.
//O(n*logn)                

int main(){
	ll n;
	cin>>n;
	vll prefix(n+1,0);
	for(ll i=1;i<=n;i++){
		ll x;
		cin>>x;
		prefix[i] = prefix[i-1] + x;
	}
	set<ll> s = {0};
	ll begin = 0, end =  0;
	ll ans = 0;
	while(begin < n){
		while(end < n && !s.count(prefix[end+1])){
			s.insert(prefix[end+1]);
			++end;
		}
		ans+=(end-begin);
		s.erase(prefix[begin]);
		++begin;
	}
	cout<<ans<<endl;	
}

