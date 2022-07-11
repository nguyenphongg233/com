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

ll st[MAX << 2];
ll a[MAX];
ll n,q;

void buildtree(ll id,ll l,ll r){
	if(l == r){
		st[id] = a[l];
		return;
	}
	ll m = l + r >> 1;
	buildtree(id << 1,l,m);
	buildtree(id << 1 | 1,m + 1,r);
	
	st[id] = st[id << 1] + st[id << 1 | 1];
}
void update(ll id,ll l,ll r,ll u,ll v){
	if(u > r || u < l)return;
	if(l == r){
		if(u == l)st[id] = v;
		return;
	}
	ll m = l + r >> 1;
	update(id << 1,l,m,u,v);
	update(id << 1 | 1,m + 1,r,u,v);
	
	st[id] = st[id << 1] + st[id << 1 | 1];
}
ll get(ll id,ll l,ll r,ll u,ll v){
	if(u > r || v < l)return 0;
	if(u <= l && r <= v)return st[id];
	
	ll m = l + r >> 1;
	return get(id << 1,l,m,u,v) + get(id << 1 | 1,m + 1,r,u,v);
}

ll cs ;
ll xort = 0;
ll xort2 = 0;
signed main(){
	cin>>n>>q;
	cs = n + 1;
	for(ll i = 1;i <= n;i++)cin>>a[i];
	buildtree(1,1,MAX - 1);
	
	for(ll i = 1,c,v;i <= q;i++){
		cin>>c>>v;
		
		//cout<<i<<":\n";
		//cout<<get(1,1,MAX - 1,1,MAX - 1)<<",";
		if(c == 1){
			a[cs] = v;
			update(1,1,MAX - 1,cs++,v);
			//for(ll i = 1;i <= cs;i++)cout<<a[i]<<" ";
			//cout<<"\n";
		}else if(c == 2){
			a[v] = 0;
			update(1,1,MAX - 1,v,0);
		}else 
		if(c == 3){
			//ll sum = 0;
			xort = v;
			xort2 = v;
			for(ll i = 1;i < cs;i++){
				//cout<<(a[i]^xort)<<" = ";
				
				//sum += a[i] ^ xort;
				update(1,1,MAX - 1,i,a[i] ^ xort);
				a[i] ^= xort;
			}
			//cout<<sum<<"\n";
			//continue;
		}
		
		//for(ll i = 1;i < cs;i++)cout<<a[i]<<" ";
		//cout<<"\n";
		cout<<(get(1,1,MAX - 1,1,MAX - 1))<<"\n";
		
	}
}