#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 3e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll n;
string s;
ll node = 1;
vector<pair<ll,char>> adj[MAX];
ll f[MAX];
ll dp[MAX];
ll res = 0;
void build(string s,ll last,ll id){
	
	if(id >= s.size()){
		f[last]++;
		return;
	}
	
	bool ok = 0;
	
	for(auto v : adj[last]){
		char c = v.Y;
		ll next = v.X;
		
		if(c == s[id]){
			build(s,next,id + 1);
			ok = 1;
			break;
		}
		
	}
	
	if(!ok){
		adj[last].push_back({++node,s[id]});
		build(s,node,id + 1);
	}
	
}

void dfs(ll u,ll p){
	dp[u] = 0;
	
	for(auto e : adj[u]){
		ll v = e.X;
		if(v == p)continue;
		dfs(v,u);
		
		if(f[v]){
			dp[u] += dp[v];
		}
	}
	
	if(!f[u])dp[u] = 0;
	else dp[u] += f[u];
	
	//cout<<u<<" "<<dp[u]<<"\n";
	res = max(res,dp[u]);
	
	
}

signed main(){
	cin>>n;
	for(ll i = 1;i <= n;i++){
		cin>>s;
		reverse(s.begin(),s.end());
		build(s,1,0);
	}

	dfs(1,0);
	cout<<res;
}