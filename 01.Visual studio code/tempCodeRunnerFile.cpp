#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 5e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll n,m;

signed main(){
	while(cin>>n>>m){
		ll a[MAX];
		vi adj[MAX];
		for(ll i = 1;i <= n;i++)cin>>a[i];
		for(ll i = 1,u,v;i <= m;i++){
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		bool visited[MAX];
		memset(visited,0,sizeof visited);
		bool can = 0;
		
		for(ll i = 1;i <= n;i++){
			
		}
	}
}