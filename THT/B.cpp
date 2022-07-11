#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 5e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll base;
map<ll,ll> mp;
ll whoasked = 0;
ii a[MAX];
ll col[MAX];
ll p[MAX];

signed main(){
	ll n;
	cin>>n;
	mp[0] = 1;
	p[0] = 1;
	base = 2 * n;
	
	for(ll i = 1;i <= 2 * n;i++)p[i] = (p[i - 1] * base ) % mod;
	
	vi r;
	for(ll i = 1,u,v;i <= n;i++){
		cin>>u>>v;
		a[i] = {u,v};
		r.push_back(u);
		r.push_back(v);
	}
	ll res = 0;
	sort(r.begin(),r.end());
	r.erase(unique(r.begin(),r.end()),r.end());
	
	for(ll i = 1;i <= n;i++){
		ll u = a[i].X;
		ll v = a[i].Y;
		
		u = lower_bound(r.begin(),r.end(),u) - r.begin() + 1;
		v = lower_bound(r.begin(),r.end(),v) - r.begin() + 1;
		
		//cout<<u<<" "<<v<<" ";
		
		if(col[u] == 0){
			whoasked -= p[u];
			if(whoasked < 0)whoasked += mod * mod;
			whoasked %= mod;
			col[u] = 1;
		}else{
			whoasked += p[u];
			whoasked %= mod;
			col[u] = 0;
		}
		
		
		
		if(col[v] == 0){
			whoasked -= p[v];
			if(whoasked < mod)whoasked += mod * mod;
			whoasked %= mod;
			col[v] = 1;
		}else{
			whoasked += p[v];
			whoasked %= mod;
			col[v] = 0;
		}
		
		res += mp[whoasked];
		//cout<<mp[whoasked]<<" ";
		mp[whoasked]++;
		
		//cout<<whoasked<<"\n";
		
	}
	
	cout<<res;
	
}
