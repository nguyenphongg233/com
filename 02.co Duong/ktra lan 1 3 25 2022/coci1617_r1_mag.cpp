#include<bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 1e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 165;
 
using namespace std;

ll coin[MAX];
vi l[MAX],r[MAX];
vi adj[MAX];
ll posl[MAX],posr[MAX];
ll dpin[MAX],dpout[MAX];
ll n;
ii ans = {1e9,1};
bool ss(const ii &a,const ii &b){
	return a.X * b.Y < a.Y * b.X;
}

void dfsin(ll u,ll p){
	l[u].push_back(0);
	for(auto v : adj[u]){
		if(v == p)continue;
		dfsin(v,u);
		posl[v] = l[u].size() - 1;
		l[u].push_back(max(l[u].back(),coin[v] == 1 ? dpin[v] + 1 : 0));
	}
	
	r[u].push_back(0);
	for(ll i = adj[u].size() - 1;i >= 0;i--){
		ll v = adj[u][i];
		
		if(v == p)continue;
		
		posr[v] = r[u].size() - 1;
		r[u].push_back(max(r[u].back(),coin[v] == 1 ? dpin[v] + 1 : 0));
	}
	
	dpin[u] = l[u].back();
}

void dfsout(ll u,ll p){
	if(u != 1){
		dpout[u] = (coin[p] == 1 ? (1 + max(dpout[p],max(l[p][posl[u]],r[p][posr[u]]))) : 0);
	}
	
	ii tmp = {coin[u],1};
	
	if(ss(tmp,ans)){
		ans = tmp;
	}
	
	ll maxx = dpout[u];
	
	for(auto v : adj[u]){
		if(v == p)continue;
		
		ll val = (coin[v] == 1 ? dpin[v] + 1 : 0);
		ii tm = {coin[u],1 + maxx + val};
		
		if(ss(tm,ans))ans = tm;
		
		maxx = max(maxx,val);
		dfsout(v,u);
	}
	
}

signed main(){
	cin>>n;
	
	for(ll i = 1,u,v;i < n;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for(ll i = 1;i <= n;i++)cin>>coin[i];
	
	dfsin(1,0);
	dfsout(1,0);
	
	ll t = __gcd(ans.X,ans.Y);
	
	cout<<ans.X/t <<"/"<<ans.Y/t;
	
}