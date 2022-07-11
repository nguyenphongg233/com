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

map<pair<char,char>,ll> mp;

signed main(){
	ll t;
	cin>>t;
	
	ll cnt = 1;
	
	for(ll i = 'a';i <= 'z';i++){
		for(ll j = 'a' ;j <= 'z';j++){
			if(i != j){
				char a = char(i);
				char b = char(j);
				
				mp[{a,b}] = cnt++;
				
			}
		}
	}
	
	
	while(t--){
		char a,b;
		cin>>a>>b;
		
		cout<<mp[{a,b}]<<"\n";
		
		
	}
}