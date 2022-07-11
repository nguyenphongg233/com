#include <bits/stdc++.h>

#define ll long long
#define ld long double

#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define gettime() cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
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

ll bit[MAX], n,a[MAX];

void update(ll id, ll val) {
	for (; id <= n; id += (id & (-id)))bit[id] += val;
	// id&(id+1) 
}
ll sum(ll id) {
	ll sum = 0;
	for (; id >= 1; id -= id & -id)sum += bit[id];
	// id | id+1
	return sum;
}
ll get(ll &l, ll &r) {
	return sum(r) - sum(l - 1);
}
signed main() {
	faster();
	cin >> n;
	ll t; cin >> t;
	FOR(i, 1, n)a[i] = 0;
	while (t--) {
		ll choose, x, y; cin >> choose >> x >> y;
		if (choose & 1) {
			update(x, y - a[x]);
			a[x] = y;
		}
		else cout << get(x,y) << "\n";
	}
	//gettime();
	return 0;
}