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

#define pi = 3.1415926535
const long long  MAX = 10005;
const long long  INF = 10000000070;
const long long mod = 1e9 + 7;

// Nguyễn Phongg :))
using namespace std;

ll n,a[MAX];
vi tree[MAX * 4];

void buildtree(ll id, ll l, ll r) {
    if (l == r) {
        tree[id].push_back(a[l]);
        return;
    }
    ll m = (l + r) / 2;
    buildtree(id * 2, l, m);
    buildtree(id * 2 + 1, m + 1, r);
    tree[id].resize(tree[id * 2].size() + tree[id * 2 + 1].size());
    merge(tree[id * 2].begin(), tree[id * 2].end(), tree[id * 2 + 1].begin(), tree[id * 2 + 1].end(), tree[id].begin());
}
void update(ll id, ll l, ll r,ll i,ll v) {
    if (l == r) {
        if (l == i)tree[id][0] = v;
        return;
    }
    ll m = (l + r) / 2;
    update(id * 2, l, m, i, v);
    update(id * 2 + 1, m + 1, r, i, v);
    tree[id].resize(tree[id * 2].size() + tree[id * 2 + 1].size());
    merge(tree[id * 2].begin(), tree[id * 2].end(), tree[id * 2 + 1].begin(), tree[id * 2 + 1].end(), tree[id].begin());
}
ll getvalue(ll id, ll l, ll r, ll u, ll v,ll k) {
    if (u > r || v < l)return 0;
    if (u <= l && v >= r)return tree[id].size() - (upper_bound(tree[id].begin(), tree[id].end(), k) - tree[id].begin());
    ll m = (l + r) / 2;
    return getvalue(id * 2, l, m, u, v, k) + getvalue(id * 2 + 1, m + 1, r, u, v, k);
}
signed main() {
    faster();
    cin >> n;
    FOR(i, 1, n)cin >> a[i];
    buildtree(1, 1, n);
    ll t; cin >> t;
    while (t--) {
        ll choose; cin >> choose;
        if (choose) {
            ll x, y, z;
            cin >> x >> y >> z;
            cout << getvalue(1, 1, n, x, y, z) << "\n";
        }
        else {
            ll x, y;
            cin >> x >> y;
            update(1, 1, n, x, y);
        }
    }
}