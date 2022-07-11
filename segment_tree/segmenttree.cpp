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
const long long  MAX = 200005;
const long long  INF = 10000000070;
const long long mod = 1e9+7;

// Nguyễn Phongg :))
using namespace std;

ll n, a[MAX], tree[MAX * 4];

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
void update(ll id, ll l, ll r, ll u, ll v, ll val) {
	if (u > r || v < l)return;
	if (l == r) {
		tree[id] += val;
		return;
	}
	ll mid = (l + r) / 2;
	update(id * 2, l, mid, u, v, val);
	update(id * 2 + 1, mid + 1, r, u, v, val);
	tree[id] = max(tree[id * 2], tree[id * 2 + 1]);
}
ll getval(ll id, ll l, ll r, ll u, ll v) {
	if (u<l || v>r)return INF;
	if (l == r)return tree[id];
	ll m = (l + r) / 2;
	return max(getval(id * 2, l, m, u, v), getval(id * 2 + 1, m + 1, r, u, v));

}
signed main() {
	cin >> n;
	FOR(i, 1, n)cin >> a[i];
	buildtree(1, 1, n);
	FOR(i, 1, n * 4)cout << tree[i] << " ";
	ll t; cin >> t;
	while (t--) {
		char s;
		cin >> s;
		if (s == 'x') {
			ll x, y, v;
			cin >> x >> y >> v;
			update(1, 1,n, x, y, v);
		}
		else {
			ll x, y;
			cin >> x >> y;
			cout<<getval(1, 1, n, x, y);
		}
	}
}