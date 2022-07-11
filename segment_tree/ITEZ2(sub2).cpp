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
const long long  INF = 10000000000070;
const long long mod = 1e9 + 7;

// Nguyễn Phongg :))
using namespace std;

ll n,tree[MAX*2];
void modify(ll p, ll val) {
	// p+=n  -> gan gtri p = p+n la val ;
	// p>>=1 -> truy cap den cac phan tu con ;
	for (tree[p += n] = val; p > 1; p >>= 1) {
		tree[p >> 1] = tree[p] + tree[p ^ 1];
		//p^1 : cay con ben phai ;
	}
}
ll getval(ll l, ll r) {
	ll sum = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1)sum += tree[l++];
		if (r & 1)sum += tree[--r];
	}
	return sum;
}
signed main() {
	cin >> n;
	FOR(i, 0, 2 * n)tree[i] = 0;
	ll t; cin >> t;
	while (t--) {
		ll choose, x, y; cin >> choose >> x >> y;
		if (choose & 1)modify(--x, y);
		else cout << getval(--x,y) << "\n";
	
	}
}