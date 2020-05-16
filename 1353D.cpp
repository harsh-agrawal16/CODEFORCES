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

//Constructing the array . A great question to learn about the working of pritority queue stl.

int main(){
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
         
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({n,{-1,n}});

        int count = 1;
        vi ans(n+1,0);

        while(!pq.empty()){
        	int le = pq.top().second.first * (-1);
        	int re = pq.top().second.second;

        	int ind;
        	int len = pq.top().first;
        	ind = (le+re)/2;      	
            pq.pop();
            if(le>re) continue;

            
        	ans[ind] = count;
            
        	if(ind>1) pq.push({ind - le, {-1*le,ind-1}});
        	if(ind<n) pq.push({re - ind,{-1*(ind+1),re}});

        	count++;

        }

        for0(i,n){
        	cout<<ans[i+1]<<" ";
        }
        cout<<endl;
	}
	
}


