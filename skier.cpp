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
	ll t;cin>>t;
	while(t--){
		string s;
		cin>>s;
		ll n = s.length();
		unordered_map<string,bool> HashMap;
		//vector<vector<vector<bool>>> xpath(2*n+1,vector<vector<bool>> (2*n+1, vector<bool> (2*n+1,false)));
		//vector<vector<vector<bool>>> ypath(2*n+1,vector<vector<bool>> (2*n+1, vector<bool> (2*n+1,false)));
		int x = 0; int y = 0;
		ll ans = 0;
		for(int i=0;i<n;i++){
			if(s[i]=='N'){
				string x1 = "x" + to_string(x) + to_string(y) + to_string(y+1) ;
				if(HashMap.find(x1)==HashMap.end()){
					ans+=5;
					HashMap[x1] = true;
					//cout<<x1<<endl;
					x1 = "x" + to_string(x) + to_string(y+1) + to_string(y);
					//cout<<x1<<endl;
					HashMap[x1] = true;	
				}
				else ans+=1;
				y+=1;
				//cout<<x<<" "<<y<<endl;
			}
			else if(s[i]=='S'){
				string x1 = "x" + to_string(x) + to_string(y) + to_string(y-1);
				if(HashMap.find(x1)==HashMap.end()){
					ans+=5;
					HashMap[x1] = true;
					//cout<<x1<<endl;
					x1 = "x" + to_string(x) + to_string(y-1) + to_string(y);
					//cout<<x1<<endl;
					HashMap[x1] = true;	
				}
				else ans+=1;
				y-=1;
			}
			else if(s[i]=='E'){
				string x1 = "y" + to_string(y) + to_string(x) + to_string(x+1);
				if(HashMap.find(x1)==HashMap.end()){
					ans+=5;
					HashMap[x1] = true;
					//cout<<x1<<endl;
					x1 = "y" + to_string(y) + to_string(x+1) + to_string(x);
					//cout<<x1<<endl;
					HashMap[x1] = true;
					
				}
				else ans+=1;
				x+=1;
			}
			else{
				string x1 ="y" + to_string(y) + to_string(x) + to_string(x-1) ;
				if(HashMap.find(x1)==HashMap.end()){
					ans+=5;
					HashMap[x1] = true;
					//cout<<x1<<endl;
					x1 ="y" + to_string(y) + to_string(x-1) + to_string(x);
					//cout<<x1<<endl;
					HashMap[x1] = true;
					
				}
				else ans+=1;
				x-=1;
			}	
		}
		cout<<ans<<endl;
    }
}


