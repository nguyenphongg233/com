#include<bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 2e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 165;
 
using namespace std;


ll dp[MAX];
signed main(){
	ll t;
	cin>>t;
	
	dp[0] = 0;
	for(ll i = 1;i < MAX;i++){
		dp[i] = INF;
	}
	for(ll i = 1;i < MAX;i++){
		if(i - 2 >= 0)dp[i] = min(dp[i],dp[i - 2] + 1);
		if(i - 1 >= 0)dp[i] = min(dp[i],dp[i - 1] + 1);
		if(i - 5 >= 0)dp[i] = min(dp[i],dp[i - 5] + 1);
	}
	
	
	
	while(t--){
		ll minx = INF;
		
		ll n;
		cin>>n;
		vi a(n);
		for(auto &x : a)cin>>x,minx = min(minx,x);
		
		for(auto &x : a)x -= minx;
		
		ll cnt = 0;
		for(auto x : a)cnt += dp[x];
		cout<<cnt<<"\n";
	}
}