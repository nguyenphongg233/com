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
const long long  MAX = 1003;
const long long  INF = 361700864190383365;
const long long mod = 1e9 + 7;

// Nguyễn Phongg :))
using namespace std;

ll n, m, a[MAX][MAX];
ii str, ed;
ll trace[MAX][MAX];
ii truyvet[MAX][MAX];
unordered_map<ll, vii>mp;
bool d[MAX][MAX];
ll dx[] = { 0,0,-1,1 };
ll dy[] = { 1,-1,0,0 };
signed main() {
	faster();
	cin >> n >> m >> str.X >> str.Y >> ed.X >> ed.Y;
	FOR(i, 1, n)FOR(j, 1, m) {
		cin >> a[i][j];
		if (a[i][j])
			mp[a[i][j]].push_back({ i,j });
	}
	priority_queue<ii, vii, greater<ii>> h;
	memset(trace, INF, sizeof(trace));
	memset(d, 0, sizeof(d));
	h.push({ str.X,str.Y });
	trace[str.X][str.Y] = 0;
	truyvet[str.X][str.Y] = { str.X,str.Y };
	while (!h.empty()) {
		ii o = h.top();
		h.pop();
		if (a[o.X][o.Y] == 0)continue;
		d[o.X][o.Y] = 1;
		//if (o == ed)break;
		FOR(i, 0, 3) {
			ll x = o.X + dx[i];
			ll y = o.Y + dy[i];
			if (x > n || y > m || x < 1 || y < 1 || a[x][y] == 0)continue;
			d[x][y] = 1;
			if (trace[x][y] > trace[o.X][o.Y] + 1) {
				trace[x][y] = trace[o.X][o.Y] + 1;
				truyvet[x][y] = { o.X,o.Y };
				h.push({ x,y });
			}
		}
		for (auto e : mp[a[o.X][o.Y]]) {
			if (e == o||d[e.X][e.Y])continue;
			ll x = e.X, y = e.Y;
			d[x][y] = 1;
			if (trace[x][y] > trace[o.X][o.Y] + 1) {
				trace[x][y] = trace[o.X][o.Y] + 1;
				truyvet[x][y] = { o.X,o.Y };
				h.push({ x,y });
			}
		}
		if (o == ed)break;
	}
	/*ll x = ed.X, y = ed.Y;
	while (truyvet[x][y] != str) {
		cout << x << " " << y << "\n";
		ii o = truyvet[x][y];
		x = o.X, y = o.Y;
	}*/
	/*FOR(i, 1, n) {
		FOR(j, 1, m)if (trace[i][j] == 361700864190383365)cout << "-1 ";
		else cout << trace[i][j] << " ";
		cout << "\n";
	}*/
	cout << trace[ed.X][ed.Y];
	//time();
}