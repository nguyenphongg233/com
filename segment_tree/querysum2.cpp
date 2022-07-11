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

vi bit1,bit2;
ll n,a[MAX],q,diff[MAX];

void update(vi &bit,ll id,ll val){
    for(;id<=n;id+=id&-id)bit[id] += val;
}
void updateranger(ll l,ll r,ll v){
    update(bit1,l,(l-1)*v);
    update(bit1,r+1,-r*v);
    update(bit2,l,v);
    update(bit2,r+1,-v);
}
ll get(vi &bit,ll id){
    ll result = 0;
    for(;id>=1;id-=id&-id)result+=bit[id];
    return result;
}
ll pref(ll u){
    return get(bit2,u)*u - get(bit1,u);
}
ll getrange(ll u,ll v){
    return pref(v) - pref(u-1);
}
signed main(){
       faster();
       cin>>n>>q;
       bit1.resize(n+1);
       bit2.resize(n+1);
       FOR(i,1,n)cin>>a[i],updateranger(i,i,a[i]);
       while(q--){
           ll x,y,z;cin>>x>>y>>z;
           if(x==1){
               ll v;
               cin>>v;
               updateranger(y,z,v);
           }else {
                cout<<getrange(y,z)<<"\n";
                   
            }
       }
       return 0;
}