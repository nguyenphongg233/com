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

ll n, k, a[MAX],dp[MAX];
deque<ll> h;

signed main() {
	cin >> n >> k;
	FOR(i, 1, n)cin >> a[i];
	dp[n] = a[n];
	h.push_back(n);
	ll maxx = 0;
	FOD(i, n - 1, 1) {
		while (!h.empty()&&h.front() - k > i)h.pop_front();
		dp[i] = max(dp[h.front()], a[1] - a[1]) + a[i];
		//cout << dp[i] << " ";
		maxx = max(maxx, dp[i]);
		while (!h.empty() && dp[h.back()] <= dp[i])h.pop_back();
		h.push_back(i);
	}
	cout <<maxx;
}