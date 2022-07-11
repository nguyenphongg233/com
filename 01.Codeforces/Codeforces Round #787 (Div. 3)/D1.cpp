#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

ll visited[MAX];
ll ans = 1;
vi path[MAX];
vi adj[MAX];

void dfs(ll x){
	visited[x] = ans;
	path[ans].push_back(x);
	if(adj[x].empty())ans++;
	
	for(auto v : adj[x]){
		if(!visited[v]){
			dfs(v);
		}
	}
}
ll t;
signed main(){
	cin>>t;
	
	while(t--){

		
		ll n;
		cin>>n;
		
		
		
		ll root;
		memset(visited,0,sizeof visited);
		memset(adj,0,sizeof adj);
		memset(path,0,sizeof path);
		//for(ll i = 1;i <= maxxxx;i++)adj[i].clear(),path[i].clear();
		
		//maxxxx = n;
		ans = 1;
		
		
		
		for(ll i = 1,x;i <= n;i++){
			cin>>x;
			
			if(i == x)root = x;
			else adj[x].push_back(i);
		}
		
		dfs(root);
		
		cout<<ans - 1<<"\n";
		
		for(ll i = 1;i < ans;i++){
			
			//if(path[i].size() == 0)continue;
			cout<<path[i].size()<<'\n';
			for(auto v : path[i])cout<<v<<" ";
			cout<<'\n';
		}
		cout<<'\n';
	}
}