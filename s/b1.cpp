#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;


ll power(ll a,ll b){
    if(b == 1)return a % mod;
    if(b == 0)return 1;

    ll s = power(a,b/2);
    s = ((s % mod) * (s % mod))%mod;

    if(b & 1) s = (s * a) % mod;
    return s;
}

signed main(){
    
    ll n;
    cin>>n;

    
    cout<<power(2,n);
    
}