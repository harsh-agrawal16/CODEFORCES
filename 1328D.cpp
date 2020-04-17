#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+1;
#define forn(i,e) for(ll i=0;i<e;i++)
#define forni(i,x,e) for(ll i=x;i<e;i++)
#define ln "\n"
ll i;
ll ans;
ll l,u;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll q;cin>>q;
    while(q--){
        ll n;cin>>n;
        vector<ll> t(n);
        forn(i,n) cin>>t[i];
        
        ll x=1;
        ll count;
        if(n%2==0){
            x=1;
            count = 1;
            forni(i,1,n){
                if(t[i]!=t[i-1]) count = 2;
            }
            cout<<count<<ln;
            x=1;
            if(count==1) forn(i,n) cout<<x<<" ";
            else{
                forn(i,n){
                    cout<<x<<" ";
                    x = (x==1)? 2:1;
                }
            }
            cout<<ln;
        }
        else{
            x=1;
            bool isPair=false;
            bool isDiff=false;
            if(t[0]==t[n-1]) isPair=true;
            forni(i,1,n){
                if(t[i]==t[i-1]){isPair=true;}
                else isDiff= true;
            }
            if(!isDiff){cout<<1<<ln; forn(i,n) cout<<x<<" ";cout<<ln;}
            else if(!isPair)
            {
            	x=1;
            	cout<<3<<ln;
            	forn(i,n-1){
            		cout<<x<<" ";
            		x = (x==1)? 2 : 1;
            	}
            	cout<<3<<ln;
            }
            else if(isPair){
            	vector<ll> ans(n);
            	cout<<2<<ln;
            	//cout<<1<<" ";
            	//ans[0]=1;
            	forn(i,n){
            		if(t[i]==t[(i+1)%n]){
            			x=1;
            			for(ll j=(i+1)%n;j<n;j++){
            				ans[j]=x;
            				x=(x==1)? 2:1;
            			}
            			
            			x=1;
            			for(ll j=i;j>=0;j--){
            				ans[j] = x;
            				x= (x==1)? 2:1;
            			}
            			
            			forn(i,n) cout<<ans[i]<<" ";
            			cout<<ln;
                        break;
            		}
            		
            	}
            	
            }
            

        }


    }  

}
