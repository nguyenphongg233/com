#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 2e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll n,k;
deque<ll> h;
ll a[MAX];
ll dp[MAX][MAX];

ll pref[MAX];
   
signed main(){
	
	cin>>n>>k;
	
	pref[0] = 0;
	for(ll i = 1;i <= n;i++)cin>>a[i],pref[i] = pref[i-1] + a[i];
	
	for(ll i = 1;i <= n;i++){
		
		for(ll j = 1;j <= k;j++){
			if(i - j  + 1< 1)dp[i][j] = pref[i];
			else dp[i][j] = max(dp[i][j],minx[k - j])
		}
		
	}
	
	cout<<dp[n];







}