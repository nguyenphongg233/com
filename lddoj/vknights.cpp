#include<bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 2e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 20;

using namespace std;

ll n;
ll m,l;
ll k[MAX];
ll dp[MAX][1 << 3];
ll cnt[MAX][1 << 3];

signed main(){
	
	cin>>n;
	for(ll i = 0;i < n;i++){
		cin>>k[i];
	}
	// hang 0 
	for(ll mask = 0;mask < 1 << 3;mask++){
		
		ll x = __builtin_popcount(mask)
		
		if(x > k[0])continue;
		
		
		cnt[0][mask] = 1;
		dp[0][mask] = x;
		
	} 
	// hang 1
	for(ll mask = 0;mask < 1 << 3;mask++){
		ll x = __builtin_popcount(mask);
		
		if(x > k[1])continue;
		
		for(ll premask = 0;premask < 1 << 3;premask++){
			ll x_ = __builtin_popcount(premask);
			
			if(x_ > k[0])continue;
			
			if(mask & 1 && (premask >> 2 & 1))continue;
			if((mask >> 2 & 1) && premask & 1)continue;
			
			/*
			
			  * . .
			  . . *
			  
			  . . *
			  * . .
			
			*/
			
			
			if(dp[1][mask] < dp[0][premask] + x){
				dp[1][mask] = dp[0][premask] + x;
				cnt[1][mask] = cnt[0][premask];
			}else if(dp[1][mask] == dp[0][premask] + x){
				cnt[1][mask] += cnt[0][premask];
			}
			
		}
		
	}
	
	// hang >= 2
	
	for(ll i = 2;i < n;i++){
		for(ll mask = 0;mask < 1 << 3;mask++){
			ll x = __builtin_popcount(mask);
			
			if(x > k[i])continue;
			
			
			
		}
	}
	
	
	
	
	
	
	
	
}