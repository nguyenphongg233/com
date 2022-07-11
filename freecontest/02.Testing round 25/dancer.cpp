#include<bits/stdc++.h>

#define ll long long
#define ld long double

#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<pair<ll, ll>>

#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FOD(i, a, b) for (ll i = a; i >= b; i--)

const double pi = 1.00 * acos(-1.00);
const long long  MAX = 100005;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

// a.k.a 1 Dam Wrong Answer

using namespace std;

ll n,k;

signed main(){
    faster();
    cin>>n>>k;
    vi a,b;
    FOR(i,1,n){
        ll x;cin>>x;
        if(x<=0)a.push_back(-x);
        else b.push_back(x);
    }
    sort(b.begin(),b.end());
    sort(a.begin(),a.end());
    ll res = 0;
    for(auto e : a){
        //cout<<"?";
        ll y = lower_bound(b.begin(),b.end(),e) - b.begin();
        while(b[y] - e <= k && y < b.size()) res++,y++;
    }
    cout<<res;
    return 0;
}