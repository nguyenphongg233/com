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
const long long  INF = 10000000000000070;
const long long mod = 1e9 + 7;

// Nguyễn Phongg :))
using namespace std;

ll n, m, a[MAX*4], tree[MAX * 4];

void update(ll id, ll l, ll r, ll x, ll y) {
	if (x > r || x < l)return;
	if (l == r) {
		if (l == x)tree[id] -= y;
		return;
	}
	ll m = (l + r) / 2;
	update(id * 2, l, m, x, y);
	update(id * 2 + 1, m + 1, r, x, y);
	tree[id] = tree[id * 2] + tree[id * 2 + 1];
}
ll getvalue(ll id, ll l, ll r, ll u, ll v) {
	if (u > r || v < l)return 0;
	if (u <= l && v >= r)return tree[id];
	ll m = (l + r) / 2;
	return getvalue(id * 2, l, m, u, v) + getvalue(id * 2 + 1, m + 1, r, u, v);
}
signed main() {
	faster();
	cin >> n >> m;
	FOR(i, 1, 4 * n)tree[i] = 0, a[i] = 0;
	while (m--) {
		ll c, x, y;
		cin >> c >> x >> y;
		if (c == 1) {
			ll q = a[x] - y;
			a[x] = y;
			update(1, 1, n, x, q);
		}
		else cout << getvalue(1, 1, n, x, y) << " ";
	}
}