#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 1e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;


ll step[MAX][MAX];
ll n,m;
char adj[MAX][MAX];

signed main(){
	
	cin>>n>>m;
	
	for(ll i = 1;i <= n;i++){
		for(ll j = 1;j <= n;j++){
			adj[i][j] = '.';
		}
	}
	
	
	for(ll i = 1,u,v;i <= m;i++){
		char c;
		cin>>u>>v>>c;
		adj[u][v] = c;
		adj[v][u] = c;
		
	}
	
	
	step[1][2] = 0;
	
	deque<ii> h;
	
	h.push_back({1,2});
	
	while(!h.empty()){
		ll str = h.front().X;
		ll ed = h.front().Y;
		
		
		//cout<<str<<" "<<ed<<" "<<step[str][ed]<<"\n";
		h.pop_front();
		
		if(adj[str][ed] != '.')return cout<<step[str][ed] * 2 + 1,0;
		
		for(ll i = 1;i <= n;i++){
			if(adj[str][i] == '.')continue;
			for(ll j = 1;j <= n;j++){
				if(adj[ed][j] == '.')continue;
				if(adj[ed][j] != adj[str][i])continue;
				
				if(i == j)return cout<<step[str][ed] * 2 + 2 ,0;
				
				step[i][j] = step[str][ed] + 1;
				h.push_back({i,j});
				
			}
		}
		
		
		
	}
	
	cout<<-1;
	
}