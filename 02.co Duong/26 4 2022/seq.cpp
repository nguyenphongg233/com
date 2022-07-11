#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 1e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;


ll n,k,a[MAX],b[MAX],c[MAX],st[MAX << 2];


void buildtree(ll id,ll l,ll r){
	if(l == r){
		st[id] = c[l];
		return;
	}
	ll m = l + r >> 1;
	
	buildtree(id << 1,l,m);
	buildtree(id << 1 | 1,m + 1,r);
	
	st[id] = __gcd(st[id << 1],st[id << 1 | 1]);
}

ll get(ll id,ll l,ll r,ll u,ll v){
	if(u > r || v < l)return 0;
	if(u <= l && r <= v)return st[id];
	
	ll m = l + r >> 1;
	
	return __gcd(get(id << 1,l,m,u,v),get(id << 1 | 1,m + 1,r,u,v));
	
}

signed main(){
	
	cin>>n>>k;
	
	for(ll i = 1;i <= n;i++)cin>>a[i];
	for(ll i = 1;i <= n;i++)cin>>b[i];
	
	for(ll i = 1;i <= n;i++)c[i] = abs(a[i] - b[i]);
	   
	
	buildtree(1,1,n);
	for(ll i = 1,u,v;i <= k;i++){
		cin>>u>>v;
		
		cout<<get(1,1,n,u,v)<<"\n";
	}
}