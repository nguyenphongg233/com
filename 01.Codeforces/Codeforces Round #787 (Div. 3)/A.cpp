#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 3e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

signed main(){
	ll t;
	
	cin>>t;
	
	while(t--){
		ll a,b,c,x,y;
		
		cin>>a>>b>>c>>x>>y;
		
		
		ll a_ = x - a;
		ll b_ = y - b;
		
		if(a_ > 0)c-=a_;
		if(b_ > 0)c-=b_;
		
		if(c < 0)cout<<"NO\n";
		else cout<<"YES\n";
	}
}