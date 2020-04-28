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

int n,k;

vi countSort(vi arr, vi count_for_sort){
    vi a(n);
    forx(i,1,k+1){
        count_for_sort[i]+=count_for_sort[i-1];
    }

    for0(i,n){
        a[count_for_sort[arr[i]] - 1] = arr[i];
        count_for_sort[arr[i]]--; 
    }
    return a;
}

int main(){
	fastIO;
    cin>>n>>k;
    vi limits(k+1);
    vi count_for_sort(k+1,0);
    vi count(k+1,-1);
    vi arr(n);
    for0(i,n) {cin>>arr[i];count_for_sort[arr[i]]++;}
    for0(i,k) cin>>limits[i+1];

    arr = countSort(arr,count_for_sort); //Now you have a array sorted in o(n) using count sort.
    
    count[1] = n;
    int prev=1;
    for0(i,n){
        if(arr[i]!=prev){
            count[arr[i]] = n - i;
            prev = arr[i];
        }
    }
    prev = 0;
    for(int j=k;j>0;j--){
        if(count[j] == -1){
            count[j] = prev;
        }
        else prev = count[j];
    }   
    
    int ans = 0;
    for0(i,n){
        int x = ceil(((double) count[arr[i]]) / limits[arr[i]]);
        if(x>ans) ans = x;
    }

    vvi testcases(ans);
    int j = 0;
    for0(i,n){
        testcases[j].pb(arr[i]);
        j = (j+1)%ans;
    }
     
    //printing the result
    cout<<ans<<endl;
    for0(i,ans){
        cout<<testcases[i].size()<<" ";
        for(auto j : testcases[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }



   

 
}

