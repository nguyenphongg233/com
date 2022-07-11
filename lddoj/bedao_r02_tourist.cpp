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

vi adj[MAX];
ll h[MAX];
ll fleg[MAX];
ll up[MAX][20];
ll a,b,n;

void dfs1(ll u,ll p){
	fleg[u] = 0;
	for(auto v : adj[u]){
		if(v == p)continue;
		
		h[v] = h[u] + 1;
		up[v][0] = u;
		
		for(ll i = 1;i < 18;i++){
			up[v][i] = up[up[v][i - 1]][i - 1];
		}
		
		dfs1(v,u);
		
		fleg[u] = max(fleg[u],fleg[v] + 1);
		
	}
}

ll lca(ll u,ll v){
	if(h[u] != h[v]){
		if(h[u] < h[v])swap(u,v);
		
		ll k = h[u] - h[v];
		
		for(ll i = 0;(1 << i) <= k;i++){
			if(k >> i & 1)u = up[u][i];
		}
	}
	
	if(u == v)return u;
	
	ll k = log2(h[u]);
	
	for(ll i = k;i >= 0;i--){
		if(up[u][i] != up[v][i]){
			u = up[u][i];
			v = up[v][i];
		}
	}
	
	return up[u][0];
}

signed main(){
	cin>>n;
	for(ll i = 1,u,v;i < n;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs1(1,0);
	
	cin>>a>>b;
	
	ll p = lca(a,b);
	
	if(h[a] < h[b])swap(a,b);
	
	ll res = 0;
	
	// ca 2 cung di den lca
	if(h[a] == h[b])res = max(res,h[p] - h[a]);
	
	ll lb = h[b] - h[p];
	ll la = h[a] - h[p];
	
	//cout<<a<<" "<<b<<" "<<p<<" "<<la<<" "<<lb<<"\n";
	
	// duong dai nhat di den gan lca 
	
	if(a != p)
	res = max(res,min(la,h[b] + 1));
	//cout<<min(la,h[b] + 1)<<"\n";
	
	// b -> goc ,a -> con dai nhat
	if(a != p)
	res = max(res,min(h[b] + 1,fleg[a] + 1));
	//cout<<min(h[b] + 1,fleg[a] + 1)<<"\n";
	
	// a -> goc , b - > con dai nhat
	if(b != p)
	res = max(res,min(h[a] + 1,fleg[b] + 1));
	//cout<<min(h[a] + 1,fleg[b] + 1)<<"\n";
	
	// ca 2 cx di den con
	
	if(a != p && b != p)
	res = max(res,min(fleg[a] + 1,fleg[b] + 1));
	
	
	cout<<res;
}
