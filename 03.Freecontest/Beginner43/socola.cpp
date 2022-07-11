#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 1e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

ll n,a[MAX];
ll dp[MAX][2];
ll maxx[MAX][2];

signed main(){
	cin>>n;
	
	for(ll i = 1;i <= n;i++)cin>>a[i];
	ll cnt = 0;
	
	dp[n][0] = 0;
	maxx[n][0] = INF;
	
	dp[n][1] = a[n];
	maxx[n][1] = a[n];
	
	for(ll i = n - 1;i >= 1;i--){
		/*maxx[i][1] = max(maxx[i + 1][0],maxx[i + 1][1] - 1);
		maxx[i][1] = min(maxx[i][1],a[n]);
		
		dp[i][1] = max(dp[i + 1][0] + min(maxx[i + 1][0] - 1,a[i]),dp[i + 1][1] + min(maxx[i + 1][1] - 1,a[i]));*/
		
		if(dp[i + 1][0] + max(0ll,min(maxx[i + 1][0] - 1,a[i])) > dp[i + 1][1] + max(0ll,min(maxx[i + 1][1] - 1,a[i]))){
			dp[i][1] = dp[i + 1][0] + max(0ll,min(maxx[i + 1][0] - 1,a[i]));
			maxx[i][1] = max(0ll,min(maxx[i + 1][0] - 1,a[i]));
		}else{
			dp[i][1] = dp[i + 1][1] + max(0ll,min(maxx[i + 1][1] - 1,a[i]));
			maxx[i][1] = max(0ll,min(maxx[i + 1][1] - 1,a[i]));
		}
		
		
		if(dp[i + 1][0] > dp[i + 1][1]){
			dp[i][0] = dp[i + 1][0];
			maxx[i][0] = maxx[i + 1][0];
			
		}else{
			dp[i][0] = dp[i + 1][1];
			maxx[i][0] = maxx[i + 1][1];
		}
		
		cout<<maxx[i][0]<<" "<<dp[i][0]<<" :: "<<maxx[i][1]<<" "<<dp[i][1]<<"\n";
	}
	
	cout<<max(dp[1][0],dp[1][1]);
}