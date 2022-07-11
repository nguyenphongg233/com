#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 3e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

signed main(){
	ll t;
	cin>>t;
	
	while(t--){
		ll n,m;
		cin>>n>>m;
		
		ll sum = 1;
		for(ll i = 1;i <= n;i++){

		    for(ll j = 2;j <= m;j++){
		    	sum += j;
		    	sum %= mod;
		    }
		    for(ll j = m - 1;j >= 1;j--){
		    	sum += j;
		    	sum %= mod;
		    }
		    sum %= mod;
		}
		
		cout<<sum<<"\n";
		
	}
}