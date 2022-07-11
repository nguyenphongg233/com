#include<bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 50;

using namespace std;

ll n,a,b;
vi adj[MAX];
ll forwa[MAX];
ll h[MAX];
ll fleg[MAX];
ll ma[MAX];
ll dp[MAX];

void dfs1(ll u,ll p){
	
	
	fleg[u] = 0;
	for(auto v : adj[u]){
		if(v == p)continue;
		
		h[v] = h[u] + 1;
		dfs1(v,u);
		
		fleg[u] = max(fleg[u],fleg[v] + 1);
		
	}
	
	
	
}
ll ans = 0;


signed main(){
	cin>>n;
	for(ll i = 1,u,v;i < n;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(h,0,sizeof h);
	deque<ll> he;
	
	cin>>a>>b;
	
	forwa[a] = -1;
	he.push_back(a);
	
	while(!he.empty()){
		ll u = he.front();
		he.pop_front();
		
		for(auto v : adj[u]){
			if(v == forwa[u])continue;
			forwa[v] = u;
			he.push_back(v);
		}
	}
	
	vi udon;
	
	ll x = b;
	
	while(x != a){
		udon.push_back(x);
		x = forwa[x];
	}
	
	udon.push_back(a);
	reverse(udon.begin(),udon.end());
	

	
	// xay dung duong di tu a - > b
	
	
	dfs1(a,-1);
	
	//for(ll i = 1;i <= n;i++)cout<<h[i]<<"\n";
	
	for(ll i = udon.size() - 1;i >= 0;i--){
		
		//cout<<udon[i]<<" ";
		
		ll u = udon[i];
		for(auto v : adj[u]){
			if(v == udon[i + 1])continue;
			if(v == udon[i - 1])continue;
			ma[u] = max(ma[u],fleg[v] + 1);
		}
		//cout<<u<<" "<<ma[u]<<"\n";
	}
	
	
	for(ll i = udon.size() - 1;i >= 0;i--){
		
		ll u = udon[i];
		if(u == b)dp[u] = fleg[u] + 1;
		else dp[u] = max(dp[u + 1],h[b] - h[u] + ma[u - 1] + 1);

		ans = max(ans,min(dp[u],h[u] + ma[u + 1] + 1));
		
		//cout<<u<<" ";
		//cout<<h[u] + ma[u + 1] + 1<<" "<<h[b] - h[u] + ma[u + 1] + 1<<"\n";
		
	}

	cout<<ans<<"\n";
}