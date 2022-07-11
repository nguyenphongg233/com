#include<bits/stdc++.h>

#define ll long long 
#define vi vector<ll>
#define ii pair<ll,ll> 

#define X first
#define Y second

const long long MAX = 1e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll n;
ll dp[MAX][MAX];
char a[MAX][MAX];
signed main(){
	dp[1][1] = 1;
	
	cin>>n;
	
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	
	for(ll i = 1;i <= n;i++){
		for(ll j = 1;j <= n;j++){
			//char x;
			cin>>a[i][j];
			
			/*if(i == 1 && j == 1)dp[i][j] = 1;
			else if(x != '.')dp[i][j] = 0;
			else dp[i][j] = dp[i-1][j] + dp[i][j-1];

			dp[i][j] %= mod;*/
			
			//cout<<a[i][j]<<" ";
		}
		//cout<<"\n";
	}
	
	for(ll i = 1;i <= n;i++){
		for(ll j = 1;j <= n;j++){
			//char x;
			char x = a[i][j];
			
			if(i == 1 && j == 1)dp[i][j] = 1;
			else if(x != '.')dp[i][j] = 0;
			else dp[i][j] = dp[i-1][j] + dp[i][j-1];

			dp[i][j] %= mod;
			
			//cout<<a[i][j]<<" ";
		}
		//cout<<"\n";
	}
	
	
	if(a[1][1] == '*')return cout<<0,0;
	cout<<dp[n][n];
	
	
}