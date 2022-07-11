#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 20;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;


ll a[MAX][MAX];
ll n;
ll dp[(1 << 17)][17];

ll calc(ll mask,ll end){
	if(mask == 0)return 0;
	
	if(dp[mask][end] != 0)return dp[mask][end];
	
	
	ll &res = dp[mask][end] = INF;
	for(ll i = 0;i < n;i++){
		if(mask >> i & 1){
			res = min(res,calc(mask & ~(1 << i),i) + a[end][i]);
		}
	}
	
	return res;
}

signed main(){
	
	cin>>n;
	
	for(ll i = 0;i < n;i++){
		for(ll j = 0;j < n;j++){
			cin>>a[i][j];
		}
	}
	
	ll res = INF;
	
	for(ll i = 0;i < n;i++){
		res = min(res,calc((1 << n) - 1,i));
	}
	
	cout<<res;
	
	
}