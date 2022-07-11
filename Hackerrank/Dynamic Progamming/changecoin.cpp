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

ll n,m;
ll a[MAX];
ll dp[MAX];
signed main(){
	cin>>m>>n;
	for(ll i = 1;i <= n;i++)cin>>a[i];
	
	memset(dp,0,sizeof dp);
	dp[0] = 1;
	
	for(ll j = 1;j <= n;j++){
		for(ll i = 1;i <= m;i++){
			if(i >= a[j])dp[i] += dp[i - a[j]];
		}
	}
	
	cout<<dp[m];
}