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

vll arr;
vll dp;
ll n;


//A very good greedy problem , taught me how to approach greedy probelems.
//make your own test cases, solve, repeat mode, solve for 15-20 minutes for tougher problems, look for a pattern and yahoo answer!!!!

int main(){
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		string ans = "";
		cin>>n>>k;
		vll arr(n);
		bool isKThere = false;
		for0(i,n){
			cin>>arr[i];
			if(i>0 && arr[i]>=k && arr[i-1]>=k){
				ans = "yes";
			}
			if(i>1 && arr[i]>=k && arr[i-2]>=k){
				ans = "yes";
			}
			if(arr[i]==k) isKThere = true;
		}

		//if k is not there the answer will always be no.
		if(!isKThere){
			cout<<"no"<<endl;
			continue;
		}

		if(n==1 && isKThere) ans ="yes";

        //if any two adjacent values are equal to k , the answer will always be yes.
		if(ans=="yes"){
			cout<<ans<<endl;
			continue;
		}

		cout<<"no"<<endl;
		continue;
	}
}


