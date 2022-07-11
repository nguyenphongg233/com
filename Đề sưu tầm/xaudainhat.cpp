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
const long long  MAX = 205;
const long long  INF = 10000000000070;
const long long mod = 1e9 + 7;

// Nguyễn Phongg :))
using namespace std;

string a, b,c;
ll f[MAX][MAX];
ll x = 1, y = 1, z = 0;

signed main() {
	/*duahau
      bunbo*/
	faster();
	cin >> a >> b;
	f[0][0] = 0;
	ll n = a.size(), m = b.size();
	a = " " + a;
	b = " " + b;
	FOR(i, 1, n)FOR(j, 1, m)if (a[i] == b[j])f[i][j] = f[i - 1][j - 1] + 1;
	else f[i][j] = max(f[i - 1][j],f[i][j-1]);
	ll i = n, j = m;
	while (f[n][m] != 0) {
		if (a[n] == b[m])c = a[n] + c, n--, m--;
		else if (f[n][m] == f[n - 1][m])n--;
		else m--;
	}
	//cout << c;
	n = i, m = j;
	while (x <= n && y <= m) {
		while (a[x] == c[z] && b[y] == c[z] && x <= n && y <= m && z < c.size()) {
			cout << c[z];
			x++, y++, z++;
		}
		while (a[x] != c[z]&&x<=n)cout << a[x], x++;
		while (b[y] != c[z] && y <= m)cout << b[y], y++;
	}
	time();
}