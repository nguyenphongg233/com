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

ll n, m, a[MAX], tree[MAX*4];
ii cnt[MAX];

void buildtree(ll id, ll l, ll r) {
	if (l == r) {
		tree[id] = a[l];
		return;
	}
	ll m = (l + r) / 2;
	buildtree(id * 2, l, m);
	buildtree(id * 2 + 1, m + 1, r);
	tree[id] = max(tree[id * 2], tree[id * 2 + 1]);
}
void update(ll id, ll l, ll r, ll x, ll y) {
	if (x > r || x < l)return;
	if (l == r) {
		tree[id] = y;
		return;
	}
	ll m = (l + r) / 2;
	update(id * 2, l, m, x, y);
	update(id * 2 + 1, m + 1, r, x, y);
	tree[id] = max(tree[id * 2], tree[id * 2 + 1]);
}
ll getval(ll id, ll l, ll r, ll u, ll v) {
	if (u > r || v < l)return -INF;
	if (u <= l && v >= r)return tree[id];
	ll m = (l + r) / 2;
	return max(getval(id * 2, l, m, u, v), getval(id * 2 + 1, m + 1, r, u, v));
}
signed main() {
	ll n;
	cin >> n;
	FOR(i, 1, n)cin >> a[i], cnt[i].X = a[i], cnt[i].Y = i;
	buildtree(1, 1, n);
	sort(cnt + 1, cnt + 1 + n);
	ll t; cin >> t;
	while (t--) {
		ll choose, x, y; cin >> choose >> x >> y;
		if (choose & 1)update(1, 1, n, x, y);
		else cout << getval(1, 1, n, x, y) << "\n";
	}
}
