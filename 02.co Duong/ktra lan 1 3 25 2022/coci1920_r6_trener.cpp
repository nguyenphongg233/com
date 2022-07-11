#include<bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 1505;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 55;
 
using namespace std;

ll n,k;
string a[N][MAX];
ll dp[N][MAX];
signed main(){
	cin>>n>>k;
	
	for(ll i = 1;i <= n;i++){
		for(ll j = 1;j <= k;j++)cin>>a[i][j];
	}
	
	
	for(ll i = 1;i <= n;i++){
		for(ll j = 1;j <= k;j++){
			if(i == 1){
				dp[i][j] = 1;
				
				continue;
			}
			
			dp[i][j] = 0;
			
			for(ll z = 1;z <= k;z++){
				if(a[i][j].find(a[i - 1][z],0) < a[i][j].size())dp[i][j] += dp[i - 1][z];
			}
			
		}
	}
	
	ll sum = 0;
	for(ll i = 1;i <= k;i++)sum += dp[n][i];
	cout<<sum;
	
	
}