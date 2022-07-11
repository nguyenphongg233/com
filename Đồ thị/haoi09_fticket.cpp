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
const long long  MAX = 300003;
const long long  INF = 1316134982;
const long long mod = 1e9 + 7;

// Nguyễn Phongg :))
using namespace std;

ll n, m, u, v, t;
vii a[MAX];
ll trace[5003][2];
// 2 trạng thái : +0 dùng vé free
//                +1 không dùng 
signed main() {
	faster();
	cin >> n >> m;
	FOR(i, 1, m) {
		cin >> u >> v >> t;
		a[u].push_back({ v,t });
		a[v].push_back({ u,t });
	}
	memset(trace, INF, sizeof(trace));
	priority_queue < pair<ll, ii>, vector<pair<ll, ii>>, greater<pair<ll, ii>>> h;
	h.push({ 0,{1,0} });
	trace[1][0] = 0;
	while (!h.empty()) {
		pair<ll, ii> o = h.top();
		h.pop();
		ll u = o.Y.X;
		ll nt = o.Y.Y;
		ll var = o.X;
		if (trace[u][nt] != var)continue;
		for (auto e : a[u]) {
			if (trace[e.X][nt] > trace[u][nt] + e.Y) {
				trace[e.X][nt] = var + e.Y;
				h.push({ trace[e.X][nt],{e.X,nt} });
			}
			if (!nt && trace[e.X][nt+1] > trace[u][nt]) {
				trace[e.X][nt+1] = var;
				h.push({ trace[e.X][nt+1],{e.X,nt + 1} });
			}
		}

	}
	cout << min(trace[n][0],trace[n][1]);
	//time();
}