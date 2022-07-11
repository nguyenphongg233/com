#include <bits/stdc++.h>

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
const long long  INF = 10000000070;
const long long mod = 1e9 + 7;

// Nguyễn Phongg :))
using namespace std;

ll n, m, a[MAX];
vi tree[MAX * 4];

void build(ll id, ll l, ll r) {
	if (l == r) {
		tree[id].push_back(a[l]);
		return;
	}
	ll m = (l + r) / 2;
	build(id * 2, l, m);
	build(id * 2 + 1, m + 1, r);
	tree[id].resize(tree[id * 2].size() + tree[id * 2 + 1].size());
	merge(tree[id * 2].begin(), tree[id * 2].end(), tree[id * 2 + 1].begin(), tree[id * 2 + 1].end(), tree[id].begin());
}
void update(ll id, ll l, ll r,ll u,ll v,ll q) {
	if (u > r || u < l)return;
	if (l == r) {
		if (l == u)tree[id][0] = v;
		return;
	}
	ll m = (l + r) / 2;
	update(id * 2, l, m, u, v,q);
	update(id * 2 + 1, m + 1, r, u, v,q);
	ll j = binary_search(tree[id].begin(), tree[id].end(), q);
	if (j)tree[id][j] = 0;
	tree[id].resize(tree[id * 2].size() + tree[id * 2 + 1].size());
	merge(tree[id * 2].begin(), tree[id * 2].end(), tree[id * 2 + 1].begin(), tree[id * 2 + 1].end(), tree[id].begin());
}
ll getval(ll id, ll l, ll r, ll u, ll v, ll k) {
	if (u > r || v < l)return INF;
	if (u <= l && v >= r) {
		ll q = lower_bound(tree[id].begin(), tree[id].end(), k) - tree[id].begin();
		if (q >= 0 && q <= tree[id].size() - 1)return tree[id][q];
		else return INF;
	}
	ll m = (l + r) / 2;
	return min(getval(id * 2, l, m, u, v, k), getval(id * 2 + 1, m + 1, r, u, v, k));
}
signed main() {
	faster();
	cin >> n >> m;
	FOR(i, 1, n)cin >> a[i];
	build(1, 1, n);
	while (m--) {
		ll choose; cin >> choose;
		if (choose == 2) {
			ll x, y, z;
			cin >> x >> y >> z;
			ll q = getval(1, 1, n, x, y, z);
			if (q == INF)cout << "-1";
			else cout << q;
			cout << "\n";
		}
		else {
			//qq = 0;
			ll x, y;
			cin >> x >> y;
			update(1, 1, n, x, y,a[x]);
			a[x] = y;
		}
	}
}