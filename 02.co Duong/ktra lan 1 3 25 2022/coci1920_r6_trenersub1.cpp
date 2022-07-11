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
map<string,ll> mp;
signed main(){
	cin>>n>>k;
	
	for(ll i = 1;i <= n;i++){
		for(ll j = 1;j <= k;j++)cin>>a[i][j];
	}
	
	for(ll i = 1;i <= n;i++){
		for(ll j = 1;j <= k;j++){
			if(i == 1){
				dp[i][j] = 1;
				mp[a[i][j]] += dp[i][j];
				//cout<<dp[i][j]<<" ";
				continue;
			}
			
			dp[i][j] = 0;
			//cout<<i<<" "<<j<<"\n";
			/*for(ll z = 0;z < i;z++){
				for(ll z_ = 1;z_ + z <= i;z_ ++){
					string uip = a[i][j].substr(z,z_);
					//cout<<z<<" "<<z_<<" "<<uip<<"\n";
					dp[i][j] += mp[uip];
				}
			}*/
			
			string uip = a[i][j].substr(0,i - 1);
			dp[i][j] += mp[uip];
			string op = a[i][j].substr(1,i - 1);
			if(op != uip)dp[i][j] += mp[op];
			
			//cout<<dp[i][j]<<" ";
			mp[a[i][j]] += dp[i][j];
			mp[a[i][j]] %= mod;
			dp[i][j] %= mod;
		}
		//cout<<"\n";
	}
	
	ll sum = 0;
	for(ll i = 1;i <= k;i++)sum += dp[n][i] % mod;
	cout<<sum % mod;;
}
