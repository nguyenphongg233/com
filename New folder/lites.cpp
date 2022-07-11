#include<bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 165;
 
using namespace std;

ll n,m;
ll st[MAX << 2];
ll lazy[MAX << 2];

void lazyupdate(ll id,ll l,ll r){
	if(lazy[id] > 0){
		st[id] = r - l + 1 - st[id];
		lazy[id << 1] ^= lazy[id];
		lazy[id << 1 | 1] ^= lazy[id];
		
		lazy[id] = 0;
	}
}

void update(ll id,ll l,ll r,ll u,ll v){
	lazyupdate(id,l,r);
	
	if(u > r || v < l)return;
	if(u <= l && v >= r){
		st[id] = r - l + 1 - st[id];
		lazy[id << 1] ^= 1;
		lazy[id << 1 | 1] ^= 1;
		return;
	}
	
	ll m = l + r >> 1;
	
	update(id << 1,l,m,u,v);
	update(id << 1 | 1,m + 1,r,u,v);
	
	st[id] = st[id << 1] + st[id << 1 | 1];
}


ll get(ll id,ll l,ll r,ll u,ll v){
	lazyupdate(id,l,r);
	
	if(u > r || v < l)return 0;
	
	if(u <= l && r <= v)return st[id];
	
	ll m = l + r >> 1;
	
	return get(id << 1,l,m,u,v) + get(id << 1 | 1,m + 1,r,u,v);
	
	
}




signed main(){
	cin>>n>>m;
	while(m--){
		ll choose;
		cin>>choose;
		ll u,v;
		cin>>u>>v;
		if(choose == 0){
			update(1,1,n,u,v);
		}else{
			cout<<get(1,1,n,u,v)<<"\n";
		}
	}
}