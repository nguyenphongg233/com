#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 5e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

vii adj[MAX];
ll n,m;
ll step[MAX];
bool visited[MAX];
ll step2[MAX];
ll dp[MAX];
bool out[MAX];
ll par[MAX];


bool thereisonewayton(){
	deque<ll> h;
	h.push_back(n);
	ll cnt = 0;
	memset(par,0,sizeof par);
	memset(out,0,sizeof out);
	
	out[n] = 1;
	while(!h.empty()){
		
		//cout<<h.front()<<"\n";
		ll u = h.front();
		h.pop_front();
		
		for(auto e : adj[u]){
			ll v = e.X;
			if(u == par[v])continue;
			if(out[u] == 1)return false;
			out[u] = 1;
			h.push_back(u);
			par[u] = v;
		}
		
		
	}
	
	return true;
}
signed main(){
	
	cin>>n>>m;
	
	for(ll i = 1,u,v;i <= m;i++){
		cin>>u>>v;
		adj[u].push_back({v,0});
		adj[v].push_back({u,1});
	}
	
	
	deque<ll> h;
	h.push_back(n);
	memset(step,-1,sizeof step);
	step[n] = 1;
	
	while(!h.empty()){
		ll u = h.front();
		h.pop_front();
		for(auto e : adj[u]){
			ll v = e.X;
			
			if(!visited[v]){
				visited[v] = 1;
				step[v] = step[u] + 1;
				h.push_back(v);
			}
		}
	}
	
	
	if(!visited[1])return cout<<-1,0;
	
	h.push_back(1);
	ll ans = INF;
	
	memset(step2,-1,sizeof step2);
	step2[1] = 0;
	while(!h.empty()){
		ll u = h.front();
		h.pop_front();
		
		for(auto e : adj[u]){
			ll v = e.X;
			ll tt = e.Y;
			if(step2[v] == -1){
				if(tt == 1)ans = min(ans,step[v]);
				else{
					step2[v] = 0;
					h.push_back(v);
				}
			}
		}
		
		
	}
	
	
	//cout<<ans;
	
	priority_queue<ii,vii,greater<ii>>h1;
	
	h1.push({0,1});
	for(ll i = 1;i <= n;i++)step[i] = INF;
	
	step[1] = 0;
	
	
	while(!h1.empty()){
		ll u = h1.top().Y;
		ll val = h1.top().X;
		
		//cout<<u<<" "<<step[u]<<" :\n";
		
		h1.pop();
		
		for(ll i = 0;i < adj[u].size();i++){
			ll v = adj[u][i].X;
			ll lue = adj[u][i].Y;
			
			//cout<<v<<" ";
			
			if(step[v] > step[u] + lue){
				step[v] = step[u] + lue;
				h1.push({step[v],v});
			}
			
		}
		
		//cout<<"\n";
	}
	
	if(step[n] == INF)return cout<<-1,0;
	//cout<<step[n]<<" "<<ans<<"\n";
	if(!thereisonewayton())cout<<step[n]<<"\n";
	else cout<<ans;
	
	
}