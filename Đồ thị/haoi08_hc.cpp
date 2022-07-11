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

ll n, m, a[MAX][MAX];
ii trace[MAX][MAX];
ll dx[] = { 1,-1,0,0 };
ll dy[] = { 0,0,-1,1 };

signed main() {
	faster();
	cin >> n >> m;
	vector<vi> p(n + 1, vi(m + 1,INF));
	queue <ii> h;
	FOR(i, 1, n) {
		FOR(j, 1, m) {
			cin >> a[i][j];
			if (j == 1) {
				h.push({ i,j });
				trace[i][j] = { 0,0 };
				p[i][j] = a[i][j];
			}
		}
	}
	pair<ll, ii> no;
	no.X = INF;
	while (!h.empty()) {
		ii res = h.front();
		if (res.Y==m&&no.X > p[res.X][res.Y]) {
			no.X = p[res.X][res.Y];
			no.Y.X = res.X;
			no.Y.Y = res.Y;
		}
		h.pop();
		FOR(i, 0, 3) {
			ll x = res.X + dx[i];
			ll y = res.Y + dy[i];
			if (x > n || y > m || x < 1 || y < 1)continue;
			if (p[res.X][res.Y] + a[x][y] < p[x][y]) {
				p[x][y] = p[res.X][res.Y] + a[x][y];
				trace[x][y] = { res.X,res.Y };
				h.push({ x,y });
			}
		}
	}
	//while (no.Y.X != 0 && no.Y.Y != 0) {
	//	cout << no.X << " ";
	//	no = { p[no.Y.X][no.Y.Y],trace[no.Y.X][no.Y.Y] };
	//}
	cout << no.X;
	//time();
}