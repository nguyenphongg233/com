#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 1e5 + 5;
const long long mod = 666013;
const long long INF = 1e9;

using namespace std;

ll n;
ll a[MAX];
vii adj[MAX];
ll in[MAX],out[MAX];

void dfs1(ll u,ll p){
	for(auto e : adj[u]){
		ll v = e.X;
		ll w = e.Y;
		
		if(v == p)continue;
		dfs1(v,u);
		
		in[u] = max(in[u],in[v] + w);
	}
}

void dfs2(ll u,ll p){
	ll mx1 = -1,mx2 = -1;
	
	for(auto e : adj[u]){
		ll v = e.X;
		ll w = e.Y;
		
		if(v == p)continue;
		
		if(in[v] + w >= mx1){
			mx2 = mx1;
			mx1 = in[v] + w;
		}else if(in[v] + w > mx2){
			mx2 = in[v] + w;
		}
	}
	
	
	for(auto e : adj[u]){
		ll v = e.X;
		ll w = e.Y;
		
		if(v == p)continue;
		
		ll longest = mx1;
		
		if(mx1 == in[v] + w)longest = mx2;
		
		out[v] = w + max(out[u],longest);
		dfs2(v,u);
	}
	
	//cout<<u<<" "<<mx1<<" "<<mx2<<"\n";
	if(mx1 != -1)out[u] = max(out[u],mx1 + out[u]);
	if(mx2 != -1 && mx1 != -1)out[u] = max(out[u],mx1 + mx2);
	//if(mx1 != -1)out[u] = max(out[u],mx1 + out[u]);
}
signed main(){
	cin>>n;
	
	for(ll i = 1,u,v,w;i < n;i++){
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	
	dfs1(1,0);
	dfs2(1,0);
	
	for(ll i = 1;i <= n;i++)cout<<max(out[i],in[i])<<"\n";
}