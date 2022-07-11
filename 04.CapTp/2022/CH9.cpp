#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 20 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

signed main(){
	ll t;
	cin>>t;
	
	while(t--){
		string s;
		cin>>s;
		
		ll sum = 0;
		for(ll i = 0 ;i < s.size();i++)sum += s[i] - '0';
		bool can = 0;
		for(ll i = 0;i < s.size();i++){
			for(ll j = '0';j < s[i];j++){
				ll x = s[i] - '0';
				ll y = j - '0';
				ll sum_ = sum - x + y;
				
				if(sum_ % 9 == 0){
					s[i] = j;
					can = 1;
					break; 
				}
			}
			if(can)break;
		}
		
		if(!can){
			for(ll i = s.size() - 1;i >= 0;i--){
			    for(ll j = s[i];j <= '9';j++){
				    ll x = s[i] - '0';
				    ll y = j - '0';
				
				    ll sum_ = sum - x + y;
				
				    if(sum_ % 9 == 0){
					    s[i] = j;
					    can = 1;
					    break;
				    }
			    }
			    if(can)break;
			}
		}
		
		cout<<s<<"\n";
	}
}