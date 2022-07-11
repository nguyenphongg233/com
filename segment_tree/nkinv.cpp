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

ll n, a[MAX], bit[MAX];

void update(ll id) {
	for (; id < MAX; id += id & -id)bit[id] ++;
}
ll get(ll id) {
	ll result = 0;
	for (; id >= 1; id -= id & -id) result += bit[id];
	return result;
}
signed main() {
	faster();
	cin >> n;
	ll sum = 0;
	FOR(i, 1, n)cin >> a[i];
	FOD(i, n, 1) {
		update(a[i]);
		sum += get(a[i] - 1);
	}
	cout << sum;
	//time();
}