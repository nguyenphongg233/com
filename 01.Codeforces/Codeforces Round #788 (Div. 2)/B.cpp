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
		ll n;
		string s;
		
		cin>>n>>s;
		
		bool a[500];
		
		ll m;
		cin>>m;
		
		memset(a,0,sizeof a);
		for(ll i = 1;i <= m;i++){
			char x;
			cin>>x;
			a[x] = 1;
		}
		
		s = " " + s;
		
		ll l = 1;
		ll res = 0;
		for(ll i = 1;i <= n;i++){
			if(a[s[i]]){
				res = max(res,i - l);
				l = i;
			}
		}
		
		cout<<res<<'\n';
	}
}