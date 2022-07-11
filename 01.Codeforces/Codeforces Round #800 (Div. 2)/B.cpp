#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 1e5 + 5;
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
		
		
		
		ll cnt = 1;
		
		ll ans = n * (n - 1) / 2 + n;
		
		//cout<<ans<<" ";
		
		for(ll i = 1;i < n;i++){
			if(s[i] == s[i - 1])cnt++;
			else {
				
				
				if(s[i] == '1')ans -= cnt * (cnt - 1),cnt = 1;
			    else  ans -= cnt * (cnt - 1) / 2,cnt = 1;
			
			}
		}
		
		
		if(n > 1 && s[n - 1] != s[n - 2]){
			cout<<ans<<"\n";
			continue;
		}
		
		if(s[n - 1] == '0'){
		    ans -= cnt * (cnt - 1);
		}else {
			ans -= cnt * (cnt - 1) / 2;
		}
		
		cout<<ans<<"\n";
		
	}
	
}