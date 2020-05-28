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
	fastIO;
	ll k;
	cin>>k;
	while(k--){
		double h,c,t;
		cin>>h>>c>>t;

		double mid = (h+c)/2;
		double ans = 0;
		if(t<=mid){
			cout<<2<<endl;
			continue;
		}
		if(t==h){
			cout<<1<<endl;
			continue;
		}

		ans = ceil((t-h)/((h+c)-2*t)) ;
		double x = (ans*(h+c) + h)/(2*ans + 1) - t;
		double y = (ans*(h+c) -c)/(2*ans - 1) - t;

		//cout<<x<<" "<<y<<endl;	

		if(fabs(x)<fabs(y)){
			cout<<2*ans+1<<endl;
		}	
		else{
			cout<<2*ans-1<<endl;
		}

	}
		
}

