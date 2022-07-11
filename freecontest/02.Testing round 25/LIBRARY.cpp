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

ll n,m,a[MAX];
vi adj[MAX];
bool visited[MAX];

ll solve(ll i){
    queue<ll> h;
    ll minx = a[i];
    visited[i] = 1;
    h.push(i);
    while(!h.empty()){
        ll o = h.front();
         h.pop();
        for(auto e : adj[o])if(!visited[e]){
              visited[e] = 1;
              h.push(e);
              minx = min(minx,a[e]);
        }
    }
    return minx;
}
signed main(){
    faster();
    cin>>n>>m;
    FOR(i,1,n)cin>>a[i];
    FOR(i,1,m){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll res = 0;
    FOR(i,1,n)if(!visited[i])res += solve(i);
    cout<<res;
    return 0;
}