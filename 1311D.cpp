#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=1e5+1;
#define forn(i,e) for(ll i=0;i<e;i++)
#define forni(i,x,e) for(ll i=x;i<e;i++)
#define ln "\n"
#define in(a) cin>>a
#define out(a) cout<<a;



//to calculate upper bound
ll upper_bound(ll s,vector<ll> &arr,ll low, ll high){
    ll mid = (high+low)/2;
    ll n = arr.size();
    if(arr[0]>s) return 0;
    if(arr[n-1]<s) return -1;
    if(high<low) return low;
    if(arr[mid]==s) return mid;
    if(arr[mid] < s) return upper_bound(s,arr,mid+1,high); 
    if(arr[mid] > s) return upper_bound(s,arr,low,mid-1);
}


//to calculate lower bound
ll lower_bound(ll s,vector<ll> &arr,ll low, ll high){
    ll mid = (high+low)/2;
    ll n = arr.size();
    if(arr[0]>s) return -1;
    if(arr[n-1]<s) return n-1;
    if(high<low) return high;
    if(arr[mid]==s) return mid;
    if(arr[mid] < s) return lower_bound(s,arr,mid+1,high); 
    if(arr[mid] > s) return lower_bound(s,arr,low,mid-1);
}



int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a,b,c,A,B,C;
        in(a),in(b),in(c);
        
        ll ans = LLONG_MAX;
        for(ll i=1;i<=20000;i++){
            for(ll j=i;j<=20000;j+=i){
                for(ll k=j;k<=20001;k+=j){
                    ll temp = abs(a-i)+abs(b-j)+abs(k-c);
                    if(temp<ans){
                    	ans = temp;
                    	A=i,B=j,C=k;
                    }
                }
            }
        }

        out(ans);
        out(ln);
        cout<<A<<" "<<B<<" "<<C;
        out(ln);
   }
   
}


