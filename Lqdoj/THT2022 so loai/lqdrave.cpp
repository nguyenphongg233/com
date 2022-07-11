#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll n,k;
vii adj[MAX];
ll ans = INF;
ll dp[MAX];
ll spec[MAX];

void dfs(ll u,ll p){
	
	
	spec[u] = 0;
	dp[u] = 1;
	
	for(auto e : adj[u]){
		ll v = e.X;
		ll w = e.Y;
		
		if(v == p)continue;
		
		dfs(v,u);
		
		if(dp[v] > dp[u])spec[u] = v;
		
		dp[u] += dp[v];
		
		
	}
	
	//cout<<u<<" "<<dp[u]<<"\n";
	
	
	
}

signed main(){
	
	cin>>n>>k;
	
	for(ll i = 1,u,v,l;i < n;i++){
		cin>>u>>v>>l;
		u++,v++;
		adj[u].push_back({v,l});
		adj[v].push_back({u,l});
	}
	
	dfs(1,0);
	
	
	for(ll i = 1;i <= n;i++)cout<<i<<" "<<dp[i]<<'\n';
	//cout<<((ans == INF) ? -1 : ans);
}