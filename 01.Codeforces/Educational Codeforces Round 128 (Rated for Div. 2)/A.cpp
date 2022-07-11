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

signed main(){
	ll t;
	cin>>t;
	
	while(t--){
		ll l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		
		ll x = max(l1,l2);
		
		if(x <= r1 && x <= r2)cout<<x<<'\n';
		else cout<<l1 + l2<<"\n";
	}
}