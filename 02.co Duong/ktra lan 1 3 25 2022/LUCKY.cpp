#include<bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 3e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 165;
 
using namespace std;

signed main(){
	
	if(ifstream("lucky.inp")){
		freopen("lucky.inp","r",stdin);
		freopen("lucky.out","w",stdout);
	}
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll t;
	cin>>t;
	
	while(t--){
		ll x,y;
		cin>>x>>y;
		
		string s;
		cin>>s;
		ll cnt = 0;
		for(ll i = 0;i < s.size();i++){
			if(s[i] - '0' == x || s[i] - '0' == y)cnt++;
		}
		
		if(cnt == x || cnt == y)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	
}