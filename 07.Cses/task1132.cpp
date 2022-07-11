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

ll n;
vi adj[MAX];
ll dp[MAX][2];
ll ans[MAX];

void dfs(ll u,ll p){
	vi icpc;
	dp[u][0] = dp[u][1] = -1;
	
	for(auto v : adj[u]){
		if(v == p)continue;
		
		dfs(v,u);
		if(dp[v][0] != -1)
		icpc.push_back(dp[v][0]);
	}
	
	sort(icpc.rbegin(),icpc.rend());
	
	if(icpc.size() > 1)dp[u][0] = icpc[0] + 1,dp[u][1] = icpc[1] + 1;
	else if(icpc.size() == 1)dp[u][0] = icpc[0] + 1;
	else dp[u][0] = dp[u][1] = 0;
	
	
}

void calc(ll u,ll p){
	
	
	
	for(auto v : adj[u]){
		if(v == u)continue;
		
		calc(v,u);
		
	}
}
signed main(){
	cin>>n;
	
	ll o = !(n % 2);
	cout<<o;
	/*for(ll i = 1,u,v;i < n;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(1,0);
	//calc(1,0);
	
	for(ll i = 1;i <= n;i++){
		cout<<i<<" : ";
		cout<<dp[i][0]<<" "<<dp[i][1]<<"\n";
	}*/
}