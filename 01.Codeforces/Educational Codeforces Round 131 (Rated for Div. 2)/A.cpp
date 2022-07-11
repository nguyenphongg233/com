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
		
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		
		if(a + b + c + d == 4)cout<<2<<"\n";
		else if(a + b + c + d >= 1)cout<<1<<'\n';
		else cout<<"0\n";
		
	}
}