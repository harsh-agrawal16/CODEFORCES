#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 10000000

int main(){

    ll t;
    cin>>t;
    while(t--){
    	ll n;
    	cin>>n;
    	string x;
    	cin>>x;
    	
    	string a="1" , b="1";
    	string big = "0";

    	for(ll i=1;i<n;i++){
    		if(x[i] == '0'){
    			a+='0';
    			b+='0';
    		}
    		if(x[i]=='2'){
    			if(big=="0"){
    				a+='1';
    				b+='1';
    			}
    			else{
    				if(big=="a"){
	    				a+='0';
	    				b+='2';
    				}
	    			else if(big=="b"){
	    				b+='0';
	    				a+='2';
	    			}

    			}
    		}

    		if(x[i]=='1'){
    			if(big=="a"){
    				a+='0';
    				b+='1';
    			}
    			else if(big=="b"){
    				b+='0';
    				a+='1';
    			}
    			else{
    				a+='1';
    				b+='0';
    				big = "a";
    			}
    		}
    	}

    	cout<<a<<endl;
    	cout<<b<<endl;

    }


}