#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 3e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

signed main(){
	ll t;
	
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		
		ll n = s.size();
		
		s = " " + s;
		
		ll l = 1,r = n;
		
		for(ll i = 1;i <= n;i++){
			if(s[i] == '1')l = i;
		}
		
		for(ll i = n;i >= 1;i--){
			if(s[i] == '0')r = i;
		}
		
		cout<<r - l + 1<<"\n";
	}
}