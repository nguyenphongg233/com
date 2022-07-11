#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 1e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

signed main(){
	
	ll t;
	cin>>t;
	
	while(t--){
		ll n;
		cin>>n;
		
		ll a[MAX];
		
		for(ll i = 1;i <= n;i++)cin>>a[i];
		
		bool can = 0;
		
		for(ll i = 3;i <= n;i += 2)if((a[i] % 2) != (a[i - 2] % 2)){
			can = 1;
			break;
		}
		for(ll i = 4;i <= n;i += 2)if((a[i] % 2) != (a[i - 2] % 2)){
			can = 1;
			break;
		}
		
		if(!can)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
}