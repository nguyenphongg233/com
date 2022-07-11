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
const long long  INF = 361700864190383365;
const long long mod = 1e9 + 7;

// Nguyễn Phongg :))
using namespace std;

ll n,m,bit1[MAX],bit2[MAX];

void update(ll bit[] ,ll id ,ll val){
    for(;id<=n;id+=id&-id)bit[id] += val;
}
void updaterange(ll l,ll r,ll val){
    update(bit1,l,val);
    update(bit1,r+1,-val);
    update(bit2,l,(l-1)*val);
    update(bit2,r+1,-r*val);
}
ll sum(ll bit[],ll id){
    ll res = 0;
    for(;id>=1;id-=id&-id)res+= bit[id];
    return res;
}
ll get(ll l,ll r){
    return (sum(bit1,r)*r - sum(bit2,r)) - (sum(bit1,l-1)*(l-1) - sum(bit2,l-1));
}
signed main(){
       faster();
       cin>>n>>m;
       FOR(i,1,n){
           ll x;cin>>x;
           updaterange(i,i,x);
       }
       while(m--){
           ll choose;cin>>choose;
           if(choose&1){
               ll x,y,z;
               cin>>x>>y>>z;
               updaterange(x,y,z);

           }else {
               ll x,y;
               cin>>x>>y;
               cout<<get(x,y)<<'\n';
           }
       }
       return 0;
}