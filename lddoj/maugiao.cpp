#include<bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 20;

using namespace std;

ll n;
ll a[N][N];
ll dp[1 << 20][20];
ll cnt[1 << 20][20];

// dien du n bit va ket thuc tai hang thu i
ll f(ll mask,ll i){
	
	if(mask == 0)return 0;
	
	if(i == 0){
		for(ll j = 0;j < n;j++){
		    if(mask >> j & 1){  
			   dp[mask][i] = a[i][j];
			   cnt[mask][i] = 1;
		    }
	    }
	    
	    return dp[mask][i];
	}
	
	if(dp[mask][i] != -1)return dp[mask][i];
	
	for(ll j = 0;j < n;j++){
		if(mask >> j & 1){
			if(dp[mask][i] < f(mask ^ (1 << j),i - 1) + a[i][j]){
				dp[mask][i] = dp[mask ^ (1 << j)][i - 1] + a[i][j];
				cnt[mask][i] = cnt[mask ^ (1 << j)][i - 1];
			}else if(dp[mask][i] == dp[mask ^ (1 << j)][i - 1] + a[i][j]){
				cnt[mask][i] += cnt[mask ^ (1 << j)][i - 1];
			}
		}
	}
	
	
	return dp[mask][i];
}

signed main(){
	cin>>n;
	for(ll i = 0;i < n;i++){
		for(ll j = 0;j < n;j++){
			cin>>a[i][j];
		}
	}
	memset(cnt,0,sizeof cnt);
	memset(dp,-1,sizeof dp);
	
	cout<<f((1 << n) - 1,n - 1)<<" "<<cnt[(1 << n) - 1][n - 1];
	
	
	
}