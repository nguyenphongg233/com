#include <bits/stdc++.h>

#define ll long long
#define ld long double

#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define time() cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<pair<ll, ll>>

#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FOD(i, a, b) for (ll i = a; i >= b; i--)

const double pi = 1.00 * acos(-1.00);
const long long  MAX = 100005;
const long long  INF = 10000000000070;
const long long mod = 1e9 + 7;

// Nguyễn Phongg :))
using namespace std;

ll n, m, a[MAX];
vi tree[MAX * 4];
ll pre[MAX];
void buildtree(ll id, ll l, ll r) {
	if (l == r) {
		tree[id].push_back(pre[l]);
		return;
	}
	ll m = (l + r) / 2;
	buildtree(id * 2, l, m);
	buildtree(id * 2 + 1, m + 1, r);
	tree[id].resize(tree[id * 2].size() + tree[id * 2 + 1].size());
	merge(tree[id * 2].begin(), tree[id * 2].end(), tree[id * 2 + 1].begin(), tree[id * 2 + 1].end(), tree[id].begin());
}
ll getval(ll id, ll l, ll r, ll u, ll v, ll k) {
	if (u > r || v < l)return 0;
	if (u <= l && v >= r) return lower_bound(tree[id].begin(), tree[id].end(), k) - tree[id].begin();
	ll m = (l + r) / 2;
	return getval(id * 2, l, m, u, v, k) + getval(id * 2 + 1, m + 1, r, u, v, k);
}
signed main() {
	faster();
	cin >> n;
	map<ll, ll> mp;
	FOR(i, 1, n) {
	     cin >> a[i];
		 pre[i] = mp[a[i]];
		 mp[a[i]] = i;
	}
	buildtree(1, 1, n);
	cin >> m;
	while (m--) {
		ll x, y;
		cin >> x >> y ;
		cout << getval(1, 1, n, x, y,x) << "\n";
	}
	//time();
}