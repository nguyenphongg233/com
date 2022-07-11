#include<bits/stdc++.h>

#define ll int
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 5e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

signed main(){
	ll t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		
			ll suml = s[0] + s[1] + s[2];
			ll n = s.size() - 1;
			ll sumr = s[n] + s[n - 1] + s[n - 2];
			
		if(suml == sumr)cout<<"YES\n";
		else cout<<"NO\n";
	}
}