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
#define for1(i,e) for(ll i=1;i<e;i++)
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
ll n,j,k;
string a,b;
vll ans;
              
 
void decrement(){
	for(ll i=j-1;i>=0;i--){
		if(a[i] == b[i]){
			j--;
		}
		else{
			break;
		}
	}

	k = j-1;
}


void change(){
	ll i=0,x=k;
	// cout<<i<<" "<<k<<endl;
	
	while(i<=x){
		a[i] = (a[i] == '0')? '1' : '0';
		if(i==x) break;
		a[x] = (a[x] == '0')? '1' : '0';
		swap(a[i],a[x]);
		i++;
		x--;
	}
	//cout<<a<<endl;
}

void solve(){
	cin>>n;
	cin>>a>>b;
    
    j = n;
    k = j - 1;
    ans = vll();
    
    decrement();

    while(k>=0){
    	if(a[0] != b[k]){
    		ans.pb(j--);
    		change();
    		k--;
    		decrement();
    	}
    	else{
    		ans.pb(1);
    		a[0] = (a[0] == '0')? '1' : '0';
    	}
    	//cout<<a<<endl;
    }

    cout<<ans.size()<<" ";
    for(ll i=0;i<ans.size();i++){
    	cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(){
	ll t;
	cin>>t;
	for(ll i=1;i<=t;i++){
		solve();
	}
}