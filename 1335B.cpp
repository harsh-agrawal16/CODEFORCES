#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 10000000

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
        ll n,a,b;
        cin>>n>>a>>b;

        vector<ll> a1(26,-1),a2(26,-1);
        char x = 'a';
        string ans = "";
        for(ll i=0;i<b;i++){
            ans+=x;
            a1[x-'a']=1;
            x++;
        }
        
        x--;
        while(b<a){
            ans+=x;
            a1[x-'a']++;
            b++;
        }
        a2 = a1;
        
        ll k=0;
        a2[ans[k]-'a']--;
        for(ll j=a;j<n;j++){
            for(ll i=0;i<26;i++){
                if(a1[i]==-1) continue;
                if(a2[i]<a1[i]){
                    ans+=ans[k];
                    k++;
                    a2[i]=a1[i];
                    break;
                }
            }
            a2[ans[k]-'a']--;
        }

        cout<<ans<<"\n";
        
    }

}