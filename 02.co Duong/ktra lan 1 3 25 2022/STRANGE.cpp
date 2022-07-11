#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 2e5 + 5;
const long long mod = 1000007;
const long long INF = 1e9;

using namespace std;

ll dp[MAX];
vi adj[MAX];
ll node[MAX];
ll n,k;
ll h[MAX];
ll f[MAX];
void dfs(ll u,ll p){
	if(node[u])dp[u] += 1;
	for(auto v : adj[u]){
		if(v == p)continue;
		h[v] = h[u] + 1;
		dfs(v,u);
		dp[u] += dp[v];
		
	}
}
void calc(ll u,ll p){
	for(auto v : adj[u]){
		if(v == p)continue;
		if(dp[v] == 0)continue;
		calc(v,u);
		f[u] += f[v] + (h[v] - h[u]) * 2;
	}
	//cout<<u<<" "<<dp[u]<<"\n";
}
signed main(){
	
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	if(ifstream("strange.inp")){
		freopen("strange.inp","r",stdin);
		freopen("strange.out","w",stdout);
	}
	
	cin>>n>>k;
	
	memset(dp,0,sizeof dp);
	memset(node,0,sizeof node);
	
	for(ll i = 1,x;i <= k;i++){
		cin>>x;
		node[x] = 1;
	}
	
	for(ll i = 1,u,v;i < n;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1,0);
	calc(1,0);
	ll res = INF;
	
	//cout<<f[1]<<"\n";
	for(ll i = 1;i <= n;i++){
		if(node[i])res = min(res,f[1] - h[i]);
		//cout<<f[1] - h[i]<<"\n";
	}
	cout<<res;
}