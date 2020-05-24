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

vi a,k;


int count_lesser(int x){
	int cnt = 0;
	for(auto y:a){
		if(y<=x) cnt++;
	}
	for(auto y:k){
		if(y>0 && y<=x) cnt++;
		if(y<0 && abs(y)<=cnt) cnt--;
	}
	return cnt;
}

int main(){
	fastIO;
	int n,q;
	cin>>n>>q;
	a.resize(n);
	k.resize(q);

	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<q;i++) cin>>k[i];

	if(count_lesser(int(1e7)) == 0){
		puts("0");
		return 0;
	}	

	int l = 0;
	int r = int(1e6)+1;

	while((r-l)>1){
		int mid = (r+l)/2;

		if(count_lesser(mid) > 0) r = mid;
		else l = mid;
	}


	cout<<r<<endl;
    return 0;

}
