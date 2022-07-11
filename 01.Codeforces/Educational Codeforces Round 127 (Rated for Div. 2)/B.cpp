#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;


ll n,a[MAX];
ll dx[] = {-1,0,1};
signed main(){
	
	ll t;
	cin>>t;
	
	while(t--){
		cin>>n;
		
		memset(a,0,sizeof a);
		
		for(ll i = 1;i <= n;i++)cin>>a[i];
		
		bool can = 0;
		
		
		bool vc = 0;
		
		ll x = a[1] - 1;
		
		for(ll j = x;j <= x + n - 1;j ++){
			if(abs(a[j - x + 1] - j) > 1){
				vc = 1;
				break;
			}
		}
		if(!vc){
			can = 1;	
		}
		x = a[1];
		vc = 0;
		
		for(ll j = x;j <= x + n - 1;j ++){
			if(abs(a[j - x + 1] - j) > 1){
				vc = 1;
				break;
			}
		}
			
		if(!vc){
			can = 1;	
		}
		x = a[1] + 1;
		vc = 0;
		
		for(ll j = x;j <= x + n - 1;j ++){
			if(abs(a[j - x + 1] - j) > 1){
				vc = 1;
				break;
			}
		}
			
		if(!vc){
			can = 1;	
		}
		
		
		cout<<((can) ? "YES" : "NO")<<"\n";
	}
}