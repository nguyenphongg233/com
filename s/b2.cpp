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

ll n,h;
ll a[MAX];

bool check(ll val){
    ll id = 0;
    for(ll i = 1;i <= n;i++){
        id += a[i] / val + (a[i] % val != 0 ? 1 : 0);
        if(id > h)return false;
    }
    return true;

}

signed main(){
    
    cin>>n>>h;
    for(ll i = 1;i <= n;i++)cin>>a[i];

    ll l = 1,r = 1e15;
    ll ans = 0;

    while(l <= r){
        ll m = l + r >> 1;
        if(check(m))r = m - 1,ans = m;
        else l = m + 1;
    }

    cout<<ans;
    
}