#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 1e6 + 5;
const long long mod = 1e9 ;
const long long INF = 1e9;

using namespace std;

ll dp[MAX],pref[MAX];
ll n,k;

signed main(){
	cin>>n>>k;
	dp[0] = pref[0] = 1;
	for(ll i = 1;i <= k;i++){
		dp[i] = dp[i - 1] * 2;
		dp[i] %= mod;
		pref[i] = pref[i - 1] + dp[i];
	    pref[i] %= mod;
	}	
	
	for(ll i = k + 1;i <= n;i++){
		dp[i] = (pref[i - 1] - pref[i - k - 1] + mod) % mod;
		pref[i] = (pref[i - 1] + dp[i]) % mod;
	}
	
	cout<<dp[n];
}g fs