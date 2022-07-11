#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 2e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

vi adj[MAX];
ll n;
ll dp[MAX];
ll f[MAX];

// f[u] : khong noi canh u 
// dp[u] : noi canh u


void dfs(ll u,ll par){
	dp[u] = f[u] = 0;
	
	for(ll i = 0;i < adj[u].size();i++){
		ll v = adj[u][i];
		
		if(v == par)continue;
		dfs(v,u);
		
		
		f[u] += max(dp[v],f[v]);
		
		
	}
	
	for(ll i = 0;i < adj[u].size();i++){
		ll v = adj[u][i];
		
		if(v == par)continue;
		//dfs(v,u);
		
		
		dp[u] = max(dp[u],f[u] - max(dp[v],f[v]) + f[v] + 1);
		
		
	}
	
	//cout<<u<<" "<<par<<" "<<dp[u]<<" "<<f[u]<<"\n";
	
	
}

signed main(){
	cin>>n;
	
	for(ll i = 1,u,v;i < n;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(1,0);
	cout<<dp[1];
}