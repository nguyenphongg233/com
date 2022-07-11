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
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll t;
	cin>>t;
	
	while(t--){
		
		ll n,k;
		cin>>n>>k;
		vi a(n + 1);
		for(ll i = 1;i <= n;i++)cin>>a[i];
		unordered_map<ll,ii> mp;
		
		
		for(ll i = 1;i <= n;i++){
			
			if(mp.count(a[i])){
				
				mp[a[i]].X = min(mp[a[i]].X,i);
				mp[a[i]].Y = max(mp[a[i]].Y,i);
				
			}else{
				
				mp[a[i]] = {i,i};
				
			}
			
		}
		
		while(k--){
			
			ll x,y;
			cin>>x>>y;
			if(!mp.count(x) || !mp.count(y))cout<<"NO\n";
			else if(x == y)cout<<"YES\n";
			else if(mp[x].X < mp[y].Y)cout<<"YES\n";
			else cout<<"NO\n";
			
			//cout<<mp[x].X<<" "<<mp[x].Y<<" "<<mp[y].X<<" "<<mp[y].Y<<"\n";
			
			
			
		}
		
	}
}