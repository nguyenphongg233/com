#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 2e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

vi adj[MAX];
ll n;
ll dp[MAX];

ll calc(ll u){
	dp[u] = 0;
	for(auto v : adj[u]){
		dp[u] += calc(v) + 1;
	}
	
	return dp[u];
}

signed main(){
	cin>>n;
	
	
	memset(dp,0,sizeof dp);
	for(ll i = 2,x;i <= n;i++){
		cin>>x;
		adj[x].push_back(i);
	}	
	
	calc(1);
	
	for(ll i = 1;i <= n;i++)cout<<dp[i]<<" ";
}