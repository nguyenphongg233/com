#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 1e3 + 5;
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
		
		if(n == 1){
			if(s[0] == 'W')cout<<"YES\n";
			else 
			cout<<"NO\n";
			continue;
		}
		
		
		ll last = -1;
		
		s = "W" + s + "W";
		
		bool b = 0,r = 0;
		
		bool can = 0;
		for(ll i = 0;i <= n + 1;i++){
			if(s[i] == 'W'){
				if(last != -1){
					if((b == 0 && r == 0) || (b == 1 && r == 1)){
						b = 0,r = 0;
					}else{
						
						can = 1;
						break;
						
					}
				}
				last = i;
			}
			else if(s[i] == 'R')r = 1;
			else if(s[i] == 'B')b = 1;
			
		}
		
		if(can)cout<<"NO\n";
		else cout<<"YES\n";
	}
}