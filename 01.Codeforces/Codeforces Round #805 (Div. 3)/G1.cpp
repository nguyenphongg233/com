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

ll n;
vi adj[MAX];
ll dd[MAX];
ll dp[MAX];
ll h[MAX];
void dfs(ll u,ll p){
	for(auto v : adj[u]){
		if(v == p)continue;
		h[v] = h[u] + 1;
		dfs(v,u);
	}
}

void dfs1(ll u,ll p){
	
	dp[u] = dd[u];
	for(auto v : adj[u]){
		if(v == p)continue;
		
		dfs(v,u);
		
		dp[u] += dp[v];
		
	}
	
}

bool dfs2(ll u,ll p){
	
	
	vi up;
	for(auto v : adj[u]){
		
		if(v == p)continue;
		
		if(dp[v] > 0)up.push_back(dp[v]);
		
	}
	
	
	if(p != -1){
		
		if(dp[u] != dp[p] && up.size() > 1)return false;
		
		
	}else if(p == -1){
		
		if(up.size() > 2)return false;
		
		
		bool ok = 1;
		for(auto v : adj[u]){
		
			if(v == p)continue;
			
			if(dp[v] > 0)ok &= dfs2(v,u);
		
	    }
	    return ok;
		
	}
	
	
	
	
	for(auto v : adj[u]){
		
		if(v == p)continue;
		
		if(dp[v] > 0)return dfs2(v,u);
		
	}
	
	
}
signed main(){
	
	cin>>n;
	
	for(ll i = 1,u,v;i < n;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(1,0);
	
	
	ll q;
	cin>>q;
	
	while(q--){
		
		ll m;
		cin>>m;
		
		vii rt(m);
		memset(dd,0,sizeof dd);
		for(auto &x : rt)cin>>x.Y,dd[x.Y] = 1,x.X = h[x.Y];
		memset(dp,0,sizeof dp);
		dfs1(1,0);
		
		sort(rt.begin(),rt.end());
		
		bool po = dfs2(1,-1);
		
		if(po)cout<<"YES\n";
		else cout<<"NO\n";
	
	}
	
}