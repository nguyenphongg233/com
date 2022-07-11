#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll v1,v2,n,m;
ll a[MAX];
ii dp[MAX];

signed main(){
	cin>>v1>>v2>>n;
	
	for(ll i = 1;i <= n;i++)cin>>a[i];
	
	sort(a + 1,a + 1 + n);
	
	ll ml = v1 - v2;
	
	vi ans;
	
	memset(dp,-1,sizeof dp);
	
	
	dp[0] = {0,0};
	
	for(ll i = 1;i <= n;i++){
		for(ll j = ml;j >= a[i];j--){
			
			if(dp[j - a[i]].Y == -1)continue;
			
			if(dp[j - a[i]].Y + 1 < dp[j].Y || dp[j].Y == -1){
				dp[j].Y = dp[j - a[i]].Y + 1;
				dp[j].X = a[i];
			}
			
		}
		
		
	}
	
	
	if(dp[ml].Y == -1)return cout<<-1,0;
	
	
	ll io = ml;
	
	
	while(io != 0){
		
		ans.push_back(dp[io].X);
		
		io -= dp[io].X;
		
	}
	
	sort(ans.begin(),ans.end());
	
	for(auto v : ans)cout<<v<<" ";
	
}