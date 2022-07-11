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

string s;
ll n;

struct Node {
	ll optimal, open, close;
};
Node tree[MAX * 4];
Node operator + (const Node& a, const Node& b) {
	Node ans;
	ll tmp = min(a.open, b.close);
	ans.optimal = a.optimal + b.optimal + tmp;
	ans.open = a.open + b.open - tmp;
	ans.close = a.close + b.close - tmp;
	return ans;
}
void buildtree(ll id, ll l, ll r) {
	if (l == r) {
		if (s[l] == '(')tree[id] = { 0,1,0 };
		else tree[id] = { 0,0,1 };
		return;
	}
	ll m = (l + r) / 2;
	buildtree(id * 2, l, m);
	buildtree(id * 2 + 1, m + 1, r);
	tree[id] = tree[id * 2] + tree[id * 2 + 1];
}
Node getvalue(ll id, ll l, ll r, ll u, ll v) {
	if (u > r || v < l)return { 0,0,0 };
	if (u<=l&&v>=r)return tree[id];
	ll m = (l + r) / 2;
	return getvalue(id * 2, l, m, u, v) + getvalue(id * 2 + 1, m + 1, r, u, v);
}
signed main() {
	string s;
	cin >> s;
	n = s.size();
	s = " " + s;
	buildtree(1, 1, n);
	ll m;
	cin >> m;
	while (m--) {
		ll x, y;
		cin >> x >> y;
		Node qwe = getvalue(1, 1, n, x, y);
		cout << min(qwe.open,qwe.close) << "\n";
	}
}