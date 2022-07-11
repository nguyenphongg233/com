#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 1e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 32;

using namespace std;

ll n,q;
ll a[MAX];
vi powr;
ll dp[MAX][N];
ll pref[MAX][N];

signed main(){
	cin>>n>>q;
	
	for(ll i = 1;i <= n;i++)cin>>a[i];
	
	powr.push_back(1);
	
	while(1){
		if(powr.back() * q > INF)break;
		else powr.push_back(powr.back() * q);
	}
	
	memset(dp,0,sizeof dp);
	
	for(ll i = 1;i <= n;i++)dp[a[i]][1] = 1;
	
	
	for(ll i = 2;i <= n;i++){
		if(i >= powr.size() - 1){
			cout<<0<<"\n";
			continue;
		}
		
		ll sum = 0;
		
		for(ll j = 1;j <= n;j++){
			if(a[j] % q != 0)dp[a[j]][i] = 0;
			else dp[a[j]][i] += dp[a[j] / q][i - 1];
			
			sum += dp[a[j]][i];
		}
		
		
		cout<<sum;
	}
	
	
	
}