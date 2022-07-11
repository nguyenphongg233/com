#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 3e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

ll t;
vi adj[MAX];
ll dp[MAX];
vi path[MAX];
ll par[MAX];
bool can[MAX];
bool visited[MAX];

ll cnt = 1;
void dfs(ll u){
	
	
	dp[u] = 0;
	
	
	for(auto v : adj[u]){
		dfs(v);
		
		dp[u] += dp[v];
	}
	
	if(adj[u].size() == 0)dp[u] = 1;
}

bool huh[MAX];
ll maxxxxx = 0;
signed main(){
	
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		
		maxxxxx = max(maxxxxx,n);
		
		ll root;
		memset(dp,0,sizeof dp);
		memset(par,0,sizeof par);
		memset(visited,0,sizeof visited);
		memset(can,0,sizeof can);
		memset(huh,0,sizeof huh);
		for(ll i = 1;i <= maxxxxx;i++)adj[i].clear(),path[i].clear();
		
		maxxxxx = n;
		for(ll i = 1,x;i <= n;i++){
			cin>>x;
			par[i] = x;
			if(x == i)root = i;
			else adj[x].push_back(i);
		}
		
		cnt = 1;
		
		dfs(root);
		
		cout<<dp[root]<<'\n';
		
		deque<ii> h;
		
		h.push_back({root,1});
		visited[root] = 1;
		path[1].push_back(root);
		
		while(!h.empty()){
			
			ll u = h.front().X;
			ll w = h.front().Y;
			
			visited[u] = 1;
			h.pop_front();
			
			for(auto v : adj[u]){
				
				if(visited[v] || v > n)continue;
				visited[v] = 1;
			    if(can[u]){
				    cnt++;
				    path[cnt].push_back(v);
				    h.push_back({v,cnt});
			    }else{
			    	can[u] = 1;
				    path[w].push_back(v);
				    h.push_back({v,w});
			   }
			   
			}
			
		}
		
		
		
		for(ll i = 1;i <= cnt;i++){
			//if(path[i].size() == 0)continue;
			
			//cout<<i<<" hhii ";
			cout<<path[i].size()<<"\n";
			for(auto v : path[i]){
				
			   cout<<v<<" ";
			   
			}
			
			cout<<"\n";
		}
		

		
		cout<<"\n";
		
		
	}
}