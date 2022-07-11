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

ll n;
ll dp[MAX];

signed main(){
	cin>>n;
	
	for(ll i = 1;i <= n;i++){
		for(ll j = 1;j <= 6;j++){
			if(i < j)break;
			if(i == j)dp[i] += 1;
			else dp[i] += dp[i - j];
			dp[i] %= mod;
		}
	}
	cout<<dp[n];
}