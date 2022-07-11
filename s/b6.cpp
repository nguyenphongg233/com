#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 1e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll n,m;
ll a[MAX];
ll down[MAX];
ll prime[MAX];
bool d[MAX];
signed main(){
    
    cin>>n>>m;


    for(ll i = 1,l,r;i <= n;i++){
        cin>>l>>r;
        a[l] = i;
        down[r + 1] = min(-i,down[r + 1]);
        
    }
    
    
    
    memset(d,0,sizeof d);
    memset(prime,0,sizeof prime);

    for(ll i = 1;i <= 5 * 1e5;i++){
        if(prime[i - 1] == -down[i])prime[i] = 0,prime[i] = max({a[i],prime[i]});
        else prime[i] = max({prime[i - 1],a[i]});
        d[prime[i]] = 1;
        //if(prime[i] != 0 )cout<<i<<" "<<prime[i]<<" "<<a[i]<<"\n";
    }

    ll sum = 0;
    for(ll i = 1;i <= 5 * 1e5;i ++){
        sum += d[i];
        //if(d[i] == 1)cout<<i<<" ";
    }

    cout<<sum;

    


    
    
}