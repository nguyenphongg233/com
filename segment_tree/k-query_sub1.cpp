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
const long long  MAX = 50005;
const long long  INF = 10000000070;
const long long mod = 1e9 + 7;

// Nguyễn Phongg :))
using namespace std;

ll n,m,tree[MAX*4],lazy[MAX * 4],a[MAX];

struct query {
	ll k, l, r,cs,ans;
};
void buildtree(ll id, ll l, ll r) {
	if (l == r) {
		tree[id] = 1;
		return;
	}
	ll m = (l + r) / 2;
	buildtree(id * 2, l, m);
	buildtree(id * 2 + 1, m + 1, r);
	tree[id] = tree[id * 2] + tree[id * 2 + 1];
}
ll getval(ll id, ll l, ll r, ll u, ll v) {
	if (u > r || v < l)return 0 ;
	if (u <= l && v >= r)return tree[id];
	ll m = (l + r) / 2;
	return getval(id * 2, l, m, u, v) + getval(id * 2 + 1, m + 1, r, u, v);
}
void update(ll id, ll l, ll r, ll u) {
	if (l == r) {
		if (a[l] <= u)tree[id] = 0;
		else tree[id] = 1;
		return;
	}
	ll m = (l + r) / 2;
	update(id * 2, l, m, u);
	update(id * 2 + 1, m + 1, r, u);
	tree[id] = tree[id * 2] + tree[id * 2 + 1];
}
bool cmp1(query a, query b) {
	return a.k < b.k;
}
bool cmp2(query a, query b) {
	return a.cs < b.cs;
}
signed main() {
	faster();
	cin >> n;
	FOR(i, 1, n)cin >> a[i];
	buildtree(1, 1, n);
	ll m;
	cin >> m;
	vector<query> b(m);
	FOR(i, 0, m - 1)cin >> b[i].l >> b[i].r >> b[i].k,b[i].cs = i;
	sort(b.begin(), b.end(), cmp1);
	FOR(i, 0, m - 1) {
		update(1, 1, n, b[i].k);
		b[i].ans = getval(1, 1, n, b[i].l, b[i].r);
	}
	sort(b.begin(), b.end(), cmp2);
	for (auto e : b)cout << e.ans << "\n";
}