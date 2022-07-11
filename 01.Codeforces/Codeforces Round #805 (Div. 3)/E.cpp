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
		
		ll n;
		vii a(n);
		
		for(auto &x : a)cin>>x.X>>x.Y;
		vector<bool> cnt(n + 1,0),cnt2(n + 1,0);
		
		bool ok = 0;
		
		for(ll i = 1;i <= n;i++){
			
			ll x = a[i - 1].X;
			ll y = a[i - 1].Y;
			
			if((cnt[x] || cnt[y]) && (cnt2[x] || cnt2[y])){
				ok = 1;
				break;
			}else{
				
				if(cnt[x] || cnt[y]){
					
					cnt2[x] = 1;
					cnt2[y] = 1;
					
				}else{
					cnt[x] = 1;
					cnt[y] = 1;
				}
				
			}
			
		}
		
		if(ok)cout<<"NO\n";
		else cout<<"YES\n";
		
	}
	
}