#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 2015 + 5;
const long long mod = 20152015;
const long long INF = 1e9;
const long long N = 111;

using namespace std;

ll v[N],c[N];
vi adj[MAX];
ll n,m;
ll dp[N][MAX];

void dfs(ll u,ll p){
	

	for(ll i = 0;i <= m;i++){
		dp[u][i] = dp[p][i];
	}
	
	//cout<<u<<" "<<p<<"\n";
	for(auto v : adj[u]){
		if(v == p)continue;
		
		dfs(v,u);
		
	}
	
	for(ll i = 0;i + c[u] <= m;i++){
		if(dp[u][i] != -1){
			dp[p][i + c[u]] = max(dp[p][i + c[u]],dp[u][i] + v[u]);
		}
	}
	
}
signed main(){
	
	cin>>n>>m;
	
	memset(dp,-1,sizeof dp);
	
	for(ll i = 2;i <= n;i++)cin>>v[i];
	for(ll i = 2;i <= n;i++)cin>>c[i];
	
	for(ll i = 1,u,v;i < n;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dp[0][0] = 0;
	dfs(1,0);
	
	ll ans = -INF;
	
	for(ll i = 1;i <= m;i++){
		ans = max(ans,dp[1][i]); 
	}
	
	cout<<ans;
}