#include<bits/stdc++.h>

#define ll long long 
#define vi vector<ll>
#define ii pair<ll,ll> 

#define X first
#define Y second

const long long MAX = 1e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll n,c[MAX],dp[MAX];
ll x;

signed main(){
	cin>>n>>x;
	for(ll i = 1;i <= n;i++)cin>>c[i];
	
	sort(c + 1,c + 1 + n);
	
	dp[0] = 1;
	
	for(ll i = 1;i <= x;i++){

		for(ll j = 1;j <= n;j++){
			ll xr = c[j];
			
			if(xr > i)break;
			dp[i] += dp[i - xr];
			dp[i] %= mod;
		}
	}
	cout<<dp[x];
}