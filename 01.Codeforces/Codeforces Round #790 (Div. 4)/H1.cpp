#include<bits/stdc++.h>

#define ll int
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 3e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

bool check(ll l,ll r,ll u,ll v){
	if(l <= u && r >= v)return true;
	return false;
}

signed main(){
	ll t;
	cin>>t;
	
	while(t--){
		ll n;
		cin>>n;
		vii a;
		for(ll i = 1;i <= n;i++){
			ll x;
			cin>>x;
			ii ds;
			ds.X = i;
			ds.Y = x;
			a.push_back(ds);
			
		}
		sort(a.begin(),a.end());
		ll cnt = 0;
		
		ll ns = a.size();
		
		for(ll i = 0;i < ns;i++){
			for(ll j = i + 1;j < ns;j++){
				ll xl = a[i].X;
				ll yl = a[i].Y;
				ll xr = a[j].X;
				ll yr = a[j].Y;
				
				if(check(xl,yl,xr,yr))cnt++;
				else if(check(xr,yr,xl,yl))cnt++;
			}
		}
		cout<<cnt<<'\n';
	}
}