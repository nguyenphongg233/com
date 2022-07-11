#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 1e5 + 5;
const long long mod = 666013;
const long long INF = 1e9;

using namespace std;

signed main(){
	ll t;
	cin>>t;
	
	while(t--){
		ll a,b,c;
		cin>>a>>b>>c;
		
		ll z = c;
		ll x = a + b + c;
		ll y = b + c;
		
		cout<<x<<" "<<y<<" "<<z<<"\n";
		//cout<<x % y<<" "<<y % z<<" "<<z % x<<"\n";
		//cout<<"\n";
	}
}