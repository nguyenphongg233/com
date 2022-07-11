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

string s;
ll n;
bool check(ll k){
	ll cur[] = {0,0};
	
	ll j = 0;
	ll minx = n;
	
	for(ll i = 1;i <= n;i++){
		if(s[i] == '0')cur[0]++;
		else cur[1]++;
		
		while((cur[0] > k || s[j + 1] == '1') && j < i ){
			j++;
			if(s[j] == '0')cur[0]++;
			else cur[1]++;
		}
		
		if(s[i] == '1' && cur[0] == k){
			minx = min(minx,n - k - cur[1]);
			
		}
	}
	
	return minx <= k;
}

signed main(){
    ll t;
    cin>>t;
    
    while(t--){
    	cin>>s;
    	
    	n = s.size();
    	s = " " + s;
    	
    	ll cnt = 0;
    	for(ll i = 1;i <= n;i++)if(s[i] == '0')cnt++;
    	
    	ll l = 1,r = cnt;
    	ll ans;
    	while(l <= r){
    		ll m = l + r >> 1;
    		if(check(m))ans = m,r = m - 1;
    		else l = m + 1;
    	}
    	
    	cout<<ans<<"\n";
    }	
}
