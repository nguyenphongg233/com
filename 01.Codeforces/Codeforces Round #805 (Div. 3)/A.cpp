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

ll po10[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

signed main(){
	
	ll t;
	cin>>t;
	
	while(t--){
		ll x;
		cin>>x;
		
		ll ans = 0;
		for(ll i = 0;i <= 9;i++){
			if(x >= po10[i])ans = x - po10[i];
		}
		cout<<ans<<"\n";
	}
	
}