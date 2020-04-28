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

vector<vector<bool>> was;
vector<vector<ll>> dist;


ll gcd(ll a, ll b){
    if(a==0) return b;
    else return gcd(b%a,a);
}

ll LCM(ll a, ll b){
    //lcm*hcf =  a*b;
    ll lc = a*b;
    ll gg = gcd(a,b);
    return lc/gg;
}

ll findCount(ll r, ll lcm, ll b){
    ll div  = r/lcm;
    ll cnt = r;
    if(div>=1){
        cnt -= (div-1)*b;
        if(r%lcm < b) cnt-=(r%lcm + 1);
        else cnt-=b;
    }
    return cnt-=min(r,b-1);
}

int main(){
    fastIO;
    ll n,m;cin>>n>>m;
    vll islands(m);
    for0(i,m) cin>>islands[i];
    sort(islands.begin(),islands.end());
    ll g,r;cin>>g>>r;
 
    //01-BFS
    was = vector<vector<bool>> (m,vector<bool>(g+1,false));
    dist = vector<vector<ll>> (m,vector<ll>(g+1,0));
    ll ans = -1;

    deque<pair<ll,ll>> bfs;
    bfs.push_back({0,0});
    while(!bfs.empty()){
        ll v = bfs.front().first;
        ll t = bfs.front().second;
        bfs.pop_front();

        if(t==0){
            ll time = n - islands[v];
            was[v][t] = true;
            if(time <=g){
                ll tempAns = (r+g)*dist[v][t] + time;
                if(ans == -1 || tempAns < ans){
                    ans = tempAns;
                }
            }
        }

        if(t==g){
            dist[v][0] = dist[v][g] + 1;
            was[v][0] = true;
            bfs.push_back({v,0});
            continue;
        }

        if(v){
            ll tTo = t + (islands[v] - islands[v-1]);
            if(was[v-1][tTo] == false && tTo<=g){
                was[v-1][tTo] = true;
                dist[v-1][tTo] = dist[v][t];
                bfs.push_front({v-1,tTo});
            }
        }

        if(v<m-1){
            ll tTo = t + (islands[v+1] - islands[v]);
            if(was[v+1][tTo] == false && tTo<=g){
                was[v+1][tTo] = true;
                dist[v+1][tTo] = dist[v][t];
                bfs.push_front({v+1,tTo});
            }
        }

    }

    cout<<ans<<endl;

}

