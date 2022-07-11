#include<bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 2e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 50;

using namespace std;

ll n;
ll res = 0;

signed main(){
 
    cin>>n;
     for(ll i=1;i<=n;i++){
     	
        for(ll j=1;j<=n/i;j++){
        	
            if((n/i/j)*i*j==n) res++;
            
        }
    }
    cout<<res;
    return 0;
}