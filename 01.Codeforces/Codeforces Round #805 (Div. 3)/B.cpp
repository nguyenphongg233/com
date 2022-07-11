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
		
		string s;
		cin>>s;
		vector<char> cnt;
		ll step = 0;
		for(ll i = 0;i < s.size();i++){
			
			if(cnt.size() == 0){
				
				cnt.push_back(s[i]);
				
			}else if(cnt.size() < 3){
				
				bool ok = 0;
				for(auto v : cnt)if(v == s[i])ok = 1;
				
				if(!ok)cnt.push_back(s[i]);
				
				
			}else if(cnt.size() == 3){
				
				bool ok = 0;
				for(auto v : cnt)if(v == s[i])ok = 1;
				
				if(!ok){
					cnt.clear();
					step++;
					cnt.push_back(s[i]);
					
				}
				
			}
			
			
			
		}
		if(cnt.size() > 0)step++;
		cout<<step<<"\n";
	}
}