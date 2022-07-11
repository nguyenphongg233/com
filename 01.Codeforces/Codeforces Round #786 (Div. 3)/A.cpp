#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 3e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

signed main(){
	ll t;
	cin>>t;
	
	while(t--){
		ll x,y;
		
		cin>>x>>y;
		
		ll q = y/x;
		
		ll a = 0,b = 0;
		
		if(y % x != 0){
			cout<<0<<" "<<0<<"\n";
			continue;
		}
		
		if(q == 1){
			cout<<1<<" "<<1<<"\n";
			continue;
		}
		
		for(ll i = 2;i <= q;i++){
			if(q % i == 0){
				ll l = i;
				
				ll cnt = 1;
				while(l < q)l *= i,cnt++;
				
				if(l == q){
					a = cnt;
					b = i;
					break;
				}
			}
		}
		
		cout<<a<<" "<<b<<"\n";
		
	}
}