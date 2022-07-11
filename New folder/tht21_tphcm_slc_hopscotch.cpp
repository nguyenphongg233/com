#include<bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 20;
 
using namespace std;

ll n,root;
vi adj[MAX];
ll cand[MAX];
ll dp[MAX];
// nhay den cac con cua u va quay ve u 
void dfs(ll u,ll p){
	
	priority_queue<ii> q;
	for(auto v : adj[u]){
		if(v == p)continue;
		dfs(v,u);
		q.push({dp[v],cand[v]});
	}
	ll res = 0;
	ll sum = 0;
	while(!q.empty() && ((u == root && cand[u] > 0)||cand[u] > 1)){
		
		ll v = q.top().X;
		ll val = q.top().Y;
		
		//cout<<v<<" "<<val<<"\n";
		q.pop();
		
		res += v + 2;
		cand[u]--;
		if(val > 1)sum += val - 1;
		
	}
	
	
	if(u == root){
		res += 2 * min(sum,cand[u]);
		cand[u] -= min(sum,cand[u]);
	}else {
		res += 2 * min(sum,cand[u] - 1);
		cand[u] -= min(sum,cand[u] - 1);
	}
	dp[u] = res;
	
	//cout<<"dp["<<u<<"] = "<<dp[u]<<" "<<cand[u]<<"\n";
}


signed main(){
	cin>>n;
	
	for(ll i = 1;i <= n;i++)cin>>cand[i];
	for(ll i = 2,u,v;i <= n;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	cin>>root;
	
	
	dfs(root,-1);
	
	cout<<dp[root];
}
