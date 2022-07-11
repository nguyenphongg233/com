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
const long long  MAX = 1000005;
const long long  INF = 10000000070;
const long long mod = 1e9 + 7;

// Nguyễn Phongg :))
using namespace std;

ll n, a[MAX], tree[MAX * 4],m,lazy[MAX*4];

void lazyupdate(ll k, ll l, ll r) {
	if (lazy[k] > 0) {
		tree[k] += lazy[k];
		if (l < r) {
			lazy[k * 2] += lazy[k];
			lazy[k * 2 + 1] += lazy[k];
		}
		lazy[k] = 0ll;
	}
}
void update(ll id, ll l, ll r, ll u, ll v, ll val) {
	lazyupdate(id, l, r);
	if (u > r || v < l)return;
	if (u<=l&&v>=r) {
		tree[id] += val;
		if (l < r) {
			lazy[id * 2] += val;
			lazy[id * 2 + 1] += val;
		}
		return;
	}
	ll m = (l + r) / 2;
	update(id * 2, l, m, u, v, val);
	update(id * 2 + 1, m + 1, r, u, v, val);
	tree[id] = max(tree[id * 2], tree[id * 2 + 1]);
}
ll getval(ll id, ll l, ll r, ll u, ll v) {
	lazyupdate(id, l, r);
	if (u > r || v < l)return 0;
	if (u <= l && v >= r)return tree[id];
	ll m = (l + r) / 2;
	return max(getval(id * 2, l, m, u, v), getval(id * 2 + 1, m + 1, r, u, v));
}
signed main() {
	faster();
	cin >> n >> m;
	FOR(i, 1, 4 * n)tree[i] = 0;
	while (m--) {
			ll x, y, z;
			cin >> x >> y >> z;
			update(1, 1, n, x, y, z);
	}
	ll q; cin >> q;
	while (q--) {
		ll x, y;
		cin >> x >> y;
		cout << getval(1, 1, n, x, y)<<"\n";
	}
}