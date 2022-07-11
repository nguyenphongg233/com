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

ll n,a[MAX];

ll cacl(ll l,ll r){
    if(l==r)return 1;
    else if((l-r+1)&1)return ( (l-r+2)/2 + 1);
    else return  (l-r+1)/2 + 1;
}
signed main(){
    faster();
    vi s;
    cin>>n;
    FOR(i,1,n)cin>>a[i];
    sort(a+1,a+1+n);
    FOR(i,1,n)FOR(j,1,i-1){
        s.push_back(a[cacl(i,j)]);
    }
    for(auto e: s)cout<<e<<" ";
    return 0;
}