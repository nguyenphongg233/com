#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 1e4 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll n,m;
vi adj[MAX];
ll tim = 1;
ll num[MAX],low[MAX];
stack<ll> st;
ll tplt = 0;
void dfs(ll u){
	num[u] = low[u] = tim++;
	st.push(u);
	for(ll i = 0;i < adj[u].size();i++){
		ll v = adj[u][i];
		
		if(num[v]){
			low[u] = min(low[u],num[v]);
		}else{
			dfs(v);
			low[u] = min(low[u],low[v]);
		}
	}
	
	if(low[u] == num[u]){
		ll tmp;
		
		do{
			tmp = st.top();
			st.pop();
			
			num[tmp] = low[tmp] = INF;
		}while(tmp != u);
		tplt++;
	}
}

signed main(){
	
	
	cin>>n>>m;
	
	for(ll i = 1,u,v;i <= m;i++){
		cin>>u>>v;
		adj[u].push_back(v);
	}
	
	for(ll i = 1;i <= n;i++)if(!num[i])dfs(i);
	
	cout<<tplt;
	
}