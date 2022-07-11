#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 5e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll n,m,a[MAX],b[MAX];
ll pref[MAX],dp[MAX];

signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	
	for(ll i = 1;i <= n;i++)cin>>a[i];
	for(ll i = 1;i <= m;i++)cin>>b[i];
	
	sort(b + 1,b + 1 + m);
	
	dp[0] = dp[1] = 0;
	pref[1] = b[1];
	
	for(ll i = 1;i <= m;i++){
		
		pref[i] = pref[i - 1] + b[i];
		dp[i] = max(dp[i-1],max(0ll,b[i] - pref[i-1]));
		//cout<<dp[i]<<" ";
	}
	//cout<<"\n";
	
	dp[m + 1] = INF;
	for(ll i = 1;i <= n;i++){
		ll p = lower_bound(dp + 1,dp + 1 + m,a[i]) - dp;
		
		while(dp[p] > a[i] && p >= 1)p--;
		
		cout<<pref[p] + a[i]<<" ";
	}
	
	
}