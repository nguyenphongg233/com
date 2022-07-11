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
		ll n;
		cin>>s>>n;
		
		ll sum = 0;
		ll cnt[50];
		for(ll i = 'a';i <= 'z';i++)cnt[i - 'a'] = 0;
		for(auto x : s)sum += x - 'a' + 1,cnt[x - 'a']++;
		
		if(sum <= n){
			cout<<s<<'\n';
			continue;
		}
		
		ll needtodel = sum - n;
		
		
		//cout<<needtodel<<"\n";
		char last = 'a' - 1;
		for(ll i = 'z';i >= 'a';i--){
			
			ll x = i - 'a';
			
			if(cnt[x] * (x + 1) <= needtodel){

				needtodel -= cnt[x] * (x + 1);
				
			}else{
				
				last = i;
				break;
			}
			
		}
		
		//cout<<last<<"\n";
		
		for(auto x : s){
			
			if(x > last)continue;
			else if(x < last)cout<<x;
			else if(x == last){
				
				if(needtodel <= 0)cout<<x;
				else needtodel -= (x - 'a' + 1);
				
			}
		}
		cout<<'\n';
		
		
	}
	
}