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


signed main(){
    
    ll t;
    cin>>t;

    while(t--){
        ll n,m;
        cin>>n>>m;
        if(n > m)swap(n,m);

        if(n == 1 && m == 1){
            cout<<0<<"\n";
            continue;
        }

        if(n == 1 && m > 2){
            cout<<-1<<"\n";
            continue;
        }
        
        ll res = 2 * n - 2;

        if(m != n){
           res++;
           ll p = m - n - 1;
           ll r = p % 3;
           ll c = p / 3;

        }

        cout<<res<<"\n";
    }
    
    
}