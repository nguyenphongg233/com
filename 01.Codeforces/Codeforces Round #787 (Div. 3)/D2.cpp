#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

vi adj[MAX];
ll n,high[MAX],cnt = 0;
ii p[MAX];
bool check[MAX];
vi res[MAX];
queue<ll> q;
 
void dfs(int u) {
	check[u] = true;
	res[cnt].push_back(u);
	for (auto x : adj[u]) {
		if (!check[x]) {
			dfs(x);
			break;
		}
	}
}
 
void bfs(ll u) {
	q.push(u);
	memset(high , -1 , sizeof(high));
	high[u] = 0;
	while(!q.empty()) {
		ll u = q.front();
		q.pop();
		for (auto x : adj[u]) {
			if (high[x] == -1) {
				high[x] = high[u] + 1;
				q.push(x);
			}
		}
	}
}
 

 
signed main() {
    ll t;
	cin >> t;
	while(t--) {
		cin >> n;
		cnt = 0;
		for (ll i = 1;i <= n;i++) {
			adj[i].clear();
		}
		ll root = 1;
		for (ll i = 1;i<=n;i++) {
			ll u;
			cin >> u;
			adj[u].push_back(i);
			if (u == i) root = u;
		}
		bfs(root);
		for (ll i = 1;i<=n;i++)p[i].X = high[i],p[i].Y = i;
		
		sort(p + 1,p + n + 1);
		
		memset(check,0,sizeof check);
		for (ll i = 1;i<=n;i++) 
			if (!check[p[i].Y]) dfs(p[i].Y),cnt++;
		
		cout << cnt << "\n";
		for (ll i = 0; i < cnt;i++) {
			cout << res[i].size() << "\n";
			for (auto v : res[i]) cout << v << " ";
			cout << "\n";
		}
		cout << "\n";
		for (ll i = 0;i<cnt;i++) {
			res[i].clear();
		}
	}
	return 0;
}