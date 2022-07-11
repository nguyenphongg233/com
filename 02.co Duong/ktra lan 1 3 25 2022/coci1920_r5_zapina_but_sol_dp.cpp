#include<bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 355;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 55;
 
using namespace std;

ll dp[MAX][MAX][2];
ll c[MAX][MAX];

ll n;
ll calc(ll a,ll b,bool ok){
	if(b == n + 1){
		if(a != 0)return 0;
		else return ok;
	}
	
	if(a == 0)return ok;
	if(dp[a][b][ok] != -1)return dp[a][b][ok];
	
	ll &res = dp[a][b][ok] = 0;
	
	for(ll i = 0;i <= a;i++)
		res = (res + (c[a][i] % mod * calc(a - i,b + 1,ok | (b == i)) % mod) % mod) % mod;
	
	return res;
	
	
}

signed main(){
	cin>>n;
	memset(dp,-1,sizeof dp);
	
	c[0][0] = 1;
	
	for(ll i = 1;i < MAX;i++){
		for(ll j = 0;j <= i;j++){
			c[i][j] = c[i - 1][j];
			if(j)c[i][j] += c[i - 1][j - 1];
			c[i][j] %= mod;
		}
	}
	
	cout<<calc(n,1,0)<<"\n";
	
}